using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    public static class Program
    {
        public static void Main()
        {
            CodeJamHelper.Execute<C>();

            Console.WriteLine();
            Console.Write("Press any key to continue...");
            Console.ReadKey(true);
        }
    }

    public static class CodeJamHelper
    {
        public static void Execute<TExec>() where TExec : CodeJamBase, new()
        {
            // Opens input and output files
            FileStream inputFile = null;
            FileStream outputFile = null;
            StreamReader input = null;
            StreamWriter output = null;

            var sw = new Stopwatch();
            try
            {
                inputFile = new FileStream("input.in", FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
                input = new StreamReader(inputFile);
                inputFile = null;
                outputFile = new FileStream("output.txt", FileMode.Create, FileAccess.Write);
                output = new StreamWriter(outputFile);
                outputFile = null;

                var T = input.ReadNumber();

                var cases = new CodeJamBase[T];

                var taskScheduler = new LimitedConcurrencyLevelTaskScheduler(8);

                sw.Start();

                for (var caseNumber = 0; caseNumber < T; caseNumber++)
                {
                    // Change Class
                    CodeJamBase processor = cases[caseNumber] = new TExec();

                    processor.LoadInput(input);
                    if (processor.ExecuteAsynchronus)
                    {
                        processor.Task = Task.Factory.StartNew<string>(processor.Process, CancellationToken.None,
                                                                       TaskCreationOptions.PreferFairness, taskScheduler);
                    }
                }

                if (cases.First().ExecuteAsynchronus)
                {
                    for (var caseNumber = 0; caseNumber < T; caseNumber++)
                    {
                        var task = cases[caseNumber].Task;
                        task.Wait();
                        WriteOutput(output, caseNumber, task.Result);
                        cases[caseNumber] = null;
                    }
                }
                else
                {
                    for (int caseNumber = 0; caseNumber < T; caseNumber++)
                    {
                        WriteOutput(output, caseNumber, cases[caseNumber].Process());
                        cases[caseNumber] = null;
                    }
                }

                sw.Stop();
            }
            finally
            {
                if (inputFile != null) inputFile.Dispose();

                if (outputFile != null) outputFile.Dispose();

                if (input != null) input.Dispose();

                if (output != null) output.Dispose();
            }
            Console.WriteLine(sw.Elapsed);
        }

        #region Helper methods

        private static void WriteOutput(StreamWriter output, int caseNumber, string result)
        {
            var outStr = String.Format("Case #{0}: {1}", caseNumber + 1, result);
            output.WriteLine(outStr);
            Console.WriteLine(outStr);
        }

        public static int ReadNumber(this StreamReader input)
        {
            return Convert.ToInt32(input.ReadLine());
        }

        public static string[] ReadList(this StreamReader input)
        {
            return input.ReadLine().Split();
        }

        public static int[] ReadNumberList(this StreamReader input)
        {
            return input.ReadList().Select(str => Convert.ToInt32(str)).ToArray();
        }

        public static long ReadLong(this StreamReader input)
        {
            return Convert.ToInt64(input.ReadLine());
        }

        public static long[] ReadLongList(this StreamReader input)
        {
            return input.ReadList().Select(s => Convert.ToInt64(s)).ToArray();
        }

        public static decimal ReadReal(this StreamReader input)
        {
            return Convert.ToDecimal(input.ReadLine());
        }

        public static decimal[] ReadRealList(this StreamReader input)
        {
            return input.ReadList().Select(Convert.ToDecimal).ToArray();
        }


        #endregion
    }

    public abstract class CodeJamBase
    {
        public Task<string> Task;

        public abstract bool ExecuteAsynchronus { get; }

        public abstract void LoadInput(StreamReader input);

        public abstract string Process();
    }


    //http://msdn.microsoft.com/en-IN/library/ee789351.aspx

    /// <summary>
    ///     Provides a task scheduler that ensures a maximum concurrency level while
    ///     running on top of the ThreadPool.
    /// </summary>
    public class LimitedConcurrencyLevelTaskScheduler : TaskScheduler
    {
        /// <summary>Whether the current thread is processing work items.</summary>
        [ThreadStatic] private static bool _currentThreadIsProcessingItems;

        /// <summary>The maximum concurrency level allowed by this scheduler.</summary>
        private readonly int _maxDegreeOfParallelism;

        /// <summary>The list of tasks to be executed.</summary>
        private readonly LinkedList<Task> _tasks = new LinkedList<Task>(); // protected by lock(_tasks) 

        /// <summary>Whether the scheduler is currently processing work items.</summary>
        private int _delegatesQueuedOrRunning; // protected by lock(_tasks) 

        /// <summary>
        ///     Initializes an instance of the LimitedConcurrencyLevelTaskScheduler class with the
        ///     specified degree of parallelism.
        /// </summary>
        /// <param name="maxDegreeOfParallelism">The maximum degree of parallelism provided by this scheduler.</param>
        public LimitedConcurrencyLevelTaskScheduler(int maxDegreeOfParallelism)
        {
            if (maxDegreeOfParallelism < 1) throw new ArgumentOutOfRangeException("maxDegreeOfParallelism");
            _maxDegreeOfParallelism = maxDegreeOfParallelism;
        }

        /// <summary>Gets the maximum concurrency level supported by this scheduler.</summary>
        public override sealed int MaximumConcurrencyLevel
        {
            get { return _maxDegreeOfParallelism; }
        }

        /// <summary>Queues a task to the scheduler.</summary>
        /// <param name="task">The task to be queued.</param>
        protected override sealed void QueueTask(Task task)
        {
            // Add the task to the list of tasks to be processed.  If there aren't enough 
            // delegates currently queued or running to process tasks, schedule another. 
            lock (_tasks)
            {
                _tasks.AddLast(task);
                if (_delegatesQueuedOrRunning < _maxDegreeOfParallelism)
                {
                    ++_delegatesQueuedOrRunning;
                    NotifyThreadPoolOfPendingWork();
                }
            }
        }

        /// <summary>
        ///     Informs the ThreadPool that there's work to be executed for this scheduler.
        /// </summary>
        private void NotifyThreadPoolOfPendingWork()
        {
            ThreadPool.UnsafeQueueUserWorkItem(_ =>
                {
                    // Note that the current thread is now processing work items. 
                    // This is necessary to enable inlining of tasks into this thread.
                    _currentThreadIsProcessingItems = true;
                    try
                    {
                        // Process all available items in the queue. 
                        while (true)
                        {
                            Task item;
                            lock (_tasks)
                            {
                                // When there are no more items to be processed, 
                                // note that we're done processing, and get out. 
                                if (_tasks.Count == 0)
                                {
                                    --_delegatesQueuedOrRunning;
                                    break;
                                }

                                // Get the next item from the queue
                                item = _tasks.First.Value;
                                _tasks.RemoveFirst();
                            }

                            // Execute the task we pulled out of the queue 
                            TryExecuteTask(item);
                        }
                    }
                        // We're done processing items on the current thread 
                    finally
                    {
                        _currentThreadIsProcessingItems = false;
                    }
                }, null);
        }

        /// <summary>Attempts to execute the specified task on the current thread.</summary>
        /// <param name="task">The task to be executed.</param>
        /// <param name="taskWasPreviouslyQueued"></param>
        /// <returns>Whether the task could be executed on the current thread.</returns>
        protected override sealed bool TryExecuteTaskInline(Task task, bool taskWasPreviouslyQueued)
        {
            // If this thread isn't already processing a task, we don't support inlining 
            if (!_currentThreadIsProcessingItems) return false;

            // If the task was previously queued, remove it from the queue 
            if (taskWasPreviouslyQueued) TryDequeue(task);

            // Try to run the task. 
            return TryExecuteTask(task);
        }

        /// <summary>Attempts to remove a previously scheduled task from the scheduler.</summary>
        /// <param name="task">The task to be removed.</param>
        /// <returns>Whether the task could be found and removed.</returns>
        protected override sealed bool TryDequeue(Task task)
        {
            lock (_tasks) return _tasks.Remove(task);
        }

        /// <summary>Gets an enumerable of the tasks currently scheduled on this scheduler.</summary>
        /// <returns>An enumerable of the tasks currently scheduled.</returns>
        protected override sealed IEnumerable<Task> GetScheduledTasks()
        {
            bool lockTaken = false;
            try
            {
                Monitor.TryEnter(_tasks, ref lockTaken);
                if (lockTaken) return _tasks.ToArray();
                else throw new NotSupportedException();
            }
            finally
            {
                if (lockTaken) Monitor.Exit(_tasks);
            }
        }
    }
}