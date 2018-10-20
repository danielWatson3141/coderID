using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstProblem
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    inputStream.ReadLine();
                    var flows = inputStream.ReadLine().Split().Select(s => Convert.ToInt64(s, 2)).ToArray();
                    var devices = new HashSet<long>(inputStream.ReadLine().Split().Select(s => Convert.ToInt64(s, 2)));

                    var minimumChanges = int.MaxValue;

                    foreach (var flow in flows)
                    {
                        foreach (var device in devices)
                        {
                            var changes = flow ^ device;
                            var changesCount = 0;

                            var tempChanges = changes;
                            for (var i = 0; i < 64; i++)
                            {
                                if ((tempChanges & 1) != 0)
                                    changesCount++;
                                tempChanges >>= 1;
                            }

                            if (changesCount < minimumChanges)
                            {
                                var newFlows = new HashSet<long>(flows.Select(f => f ^ changes));

                                newFlows.IntersectWith(devices);

                                if (newFlows.Count == flows.Length)
                                    minimumChanges = changesCount;
                            }
                        }
                    }

                    if (minimumChanges != int.MaxValue)
                        outputStream.WriteLine("Case #{0}: {1}", caseNumber, minimumChanges);
                    else
                        outputStream.WriteLine("Case #{0}: NOT POSSIBLE", caseNumber);
                }
            }
        }
    }
}
