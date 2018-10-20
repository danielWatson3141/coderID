using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem_A
{
    class Program
    {
        static TextReader input = Console.In;
        static TextWriter output = Console.Out;
        static void Main(string[] args)
        {
            if (args.Any())
            {
                var path = args[0];
                if (File.Exists(path))
                {
                    input = File.OpenText(path);
                }
                path = path.Remove(path.LastIndexOf('.'));
                path += ".out";
                output = File.CreateText(path);
            }

            int totalCases = int.Parse(input.ReadLine());
            for (int currentCase = 1; currentCase <= totalCases; currentCase++)
            {
                string caseOutput = HandleCase(input);
                output.WriteLine(string.Format("Case #{0}: {1}", currentCase, caseOutput));
            }
            output.Flush();
        }

        private static string HandleCase(TextReader input)
        {
            string line = input.ReadLine();
            int outletNumber = int.Parse(line.Split(' ')[0]);
            int switchNumber = int.Parse(line.Split(' ')[1]);

            List<int> currentOutlets = input.ReadLine().Split(' ').Select(outlet => Convert.ToInt32(outlet, 2)).ToList();
            List<int> desiredOutlets = input.ReadLine().Split(' ').Select(outlet => Convert.ToInt32(outlet, 2)).ToList();

            // breadth first search for least amount of toggles
            // only toggle > current switch to not do double cases.
            int minSwitch = DoSwitchEnumerate(new switchcase(currentOutlets, desiredOutlets, 0, 0), switchNumber);
            return minSwitch == -1 ? "NOT POSSIBLE" : minSwitch.ToString();
        }

        private static int DoSwitchEnumerate(switchcase @case, int totalSwitches)
        {
            if (@case.valid())
                return 0;

            Queue<switchcase> tests = new Queue<switchcase>();
            for (int @switch = @case.startSwitch; @switch < totalSwitches; @switch++)
            {
                tests.Enqueue(new switchcase(@case.current, @case.desired, @case.currentSwitches ^ (1 << @switch), @switch + 1));
            }
            while (tests.Count > 0)
            {
                var test = tests.Dequeue();
                if (test.valid())
                {
                    return Convert.ToString(test.currentSwitches, 2).Where(ch => ch == '1').Count();
                }
                else
                {
                    for (int @switch = test.startSwitch; @switch < totalSwitches; @switch++)
                    {
                        tests.Enqueue(new switchcase(@case.current, @case.desired, test.currentSwitches ^ (1 << @switch), @switch + 1));
                    }
                }
            }
            return -1;
        }

        public class switchcase
        {
            public List<int> current;
            public List<int> desired;
            public int currentSwitches;
            public int startSwitch;

            public switchcase(List<int> current, List<int> desired, int currentSwitches, int startSwitch)
            {
                this.current = current.ToList();
                this.desired = desired.ToList();
                this.currentSwitches = currentSwitches;
                this.startSwitch = startSwitch;
            }

            public bool valid()
            {
                // flip switches
                for (int i = 0; i < current.Count; i++)
                {
                    current[i] ^= currentSwitches;
                }
                return !current.Except(desired).Any();
            }
        }
    }
}
