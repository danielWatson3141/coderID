using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014_PreRound
{
    class A
    {
        public A()
        {
            using (StreamWriter sw = new StreamWriter(@"D:\data\A\output.txt"))
            {
                foreach (var r in GetCases().AsParallel().Select(t => Tuple.Create(t.Item1, Solve(t))).OrderBy(t => t.Item1))
                //foreach (var r in GetCases().Select(t => Tuple.Create(t.Item1, Solve(t))).OrderBy(t => t.Item1))
                {
                    sw.WriteLine("Case #" + r.Item1 + ": " + r.Item2);
                    Console.WriteLine("Case #" + r.Item1 + ": " + r.Item2);
                }
            }
        }

        IEnumerable<Tuple<int, int, int, string[], string[]>> GetCases()
        {
            //using (StreamReader sr = new StreamReader(@"C:\Users\MarvinMiao\Downloads\B-small-attempt0.in"))
            //using (StreamReader sr = new StreamReader(@"C:\Users\MarvinMiao\Downloads\B-large.in"))
            using (StreamReader sr = new StreamReader(@"C:\Users\MarvinMiao\Downloads\A-small-attempt1.in"))
            //using (StreamReader sr = new StreamReader(@"input_A.txt"))
            {
                int caseCount = int.Parse(sr.ReadLine());

                for (int i = 1; i <= caseCount; i++)
                {
                    var ln = sr.ReadLine().Split(' ');
                    var parts = sr.ReadLine().Split(' ');
                    var parts2 = sr.ReadLine().Split(' ');

                    yield return Tuple.Create(i, int.Parse(ln[0]), int.Parse(ln[1]), parts, parts2);
                }
            }
        }

        public string Solve(Tuple<int, int, int, string[], string[]> input)
        {
            var goal = new HashSet<long>();
            var current = new HashSet<long>();

            foreach (string s in input.Item4)
            {
                long value = 0;
                for (int i = 0; i < input.Item3; i++)
                {
                    value = value | ((s[i] == '1' ? 1L : 0) << i);
                }

                current.Add(value);
            }

            foreach (string s in input.Item5)
            {
                long value = 0;
                for (int i = 0; i < input.Item3; i++)
                {
                    value = value | ((s[i] == '1' ? 1L : 0) << i);
                }

                goal.Add(value);
            }

            var r = SolveSub(current, goal, input.Item3, input.Item2, 0, 0);
            if (r == int.MaxValue)
            {
                Console.WriteLine("NOT POSSIBLE");
                return "NOT POSSIBLE";
            }
            else
            {
                Console.WriteLine(r);
                return r.ToString();
            }

        }

        public int SolveSub(HashSet<long> current, HashSet<long> goal, int L, int N, int lc, int step)
        {
            int r = goal.Intersect(current).Count();

            if (r == N)
            {
                return step;
            }

            if (lc == L)
            {
                return int.MaxValue;
            }

            {
                var currentT = new HashSet<long>();

                foreach (var value in current)
                {
                    currentT.Add(value ^ (1L << lc));
                }

                return Math.Min(SolveSub(current, goal, L, N, lc + 1, step),
                    SolveSub(currentT, goal, L, N, lc + 1, step + 1));
            }
        }

    }
}
