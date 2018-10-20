using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace waterfood.CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputs = File.ReadAllLines(@"../../A-large.in");
            var outputs = new StringBuilder();

            int T = int.Parse(inputs[0]);
            for (int x = 0; x < T; x++)
            {
                var setting = inputs[x * 3 + 1].Split(' ');
                int N = int.Parse(setting[0]);
                int L = int.Parse(setting[1]);
                var source = ReadLineRadix2(inputs[x * 3 + 2]);
                var target = ReadLineRadix2(inputs[x * 3 + 3]);

                // get possible action mapping from each row in source to all rows in target
                var mappings = source.Select(srcRow => target.Select(tgtRow => tgtRow ^ srcRow).ToList()).ToList();
                // get candidates
                IEnumerable<UInt64> intersaction = mappings[0];
                for (int i = 1; i < mappings.Count; i++)
                {
                    intersaction = intersaction.Intersect(mappings[i]);
                }
                var candidates = intersaction.ToList();

                // test each candidate
                var solution = new LinkedList<UInt64>();
                foreach (var c in candidates)
                {
                    var positions = mappings.Select(mapping => mapping.IndexOf(c));
                    if (positions.Distinct().Count() == N)
                    {
                        solution.AddLast(c);
                    }
                }

                // find best
                string answer = "NOT POSSIBLE";
                if (solution.Count > 0)
                {
                    int best = solution.Select(CountOnes).Min();
                    answer = best.ToString();
                }

                outputs.AppendLine(string.Format("Case #{0}: {1}", x + 1, answer));
            }

            File.WriteAllText(@"../../A-large.out", outputs.ToString());
        }

        private static List<UInt64> ReadLineRadix2(string line)
        {
            string[] numbers = line.Split(' ');
            return numbers.Select(n => Convert.ToUInt64(n, 2)).ToList();
        }

        private static int CountOnes(UInt64 n)
        {
            int i = 0;
            while (n != 0)
            {
                n = n & (n - 1);
                i++;
            }
            return i;
        }
    }
}
