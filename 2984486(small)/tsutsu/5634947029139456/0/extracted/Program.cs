using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChargingChaos
{
    class Program
    {
        private static readonly int TCount = 100;

        private static int sloveCount = 0;

        private static void SloveAll(System.IO.StreamReader sr, List<string>[] result, int tid)
        {
            var T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                var line1 = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                var bits1 = sr.ReadLine().Split(' ');
                var bits2 = sr.ReadLine().Split(' ');
                if (i % Program.TCount != tid) { continue; }
                var N = line1[0]; var L = line1[1];
                var output = new List<string>();
                var ret = Program.Slove(N, L, bits1, bits2);
                var ans = (ret == -1) ? "NOT POSSIBLE" : ret.ToString();
                output.Add(string.Format("Case #{0}: {1}", i + 1, ans));

                lock (result)
                {
                    result[i] = output;
                    Console.WriteLine("*** Count {0} ***", ++Program.sloveCount);
                    output.ForEach(x => Console.WriteLine(x));
                }
            }
        }

        private static int Slove(int N, int L, string[] bits1, string[] bits2)
        {
            if (Program.IsOK(bits1, bits2)) { return 0; }

            for (int i = 1; i < L + 1; i++)
            {
                var posComb = Program.Combinations(Enumerable.Range(0, L).ToList(), i);
                foreach (var posList in posComb)
                {
                    var bits1_ = Program.Flip(posList, bits1);
                    if (Program.IsOK(bits1_, bits2)) { return i; }
                }
            }

            return -1;
        }

        private static string[] Flip(IEnumerable<int> posList, string[] bits1)
        {
            var result = new string[bits1.Length];
            var count = 0;
            foreach (var bit in bits1)
            {
                var ary = bit.ToCharArray();
                foreach (var pos in posList)
	            {
                    if (ary[pos] == '0') { ary[pos] = '1'; }
                    else { ary[pos] = '0'; }
	            }
                result[count] = new string(ary);
                count++;
            }
            return result;
        }

        private static bool IsOK(string[] bits1, string[] bits2)
        {
            foreach (var item1 in bits1)
            {
                var found = false;
                foreach (var item2 in bits2)
                {
                    if (item1 == item2) { found = true; break; }
                }
                if (!found) { return false; }
            }
            return true;
        }

        private static IEnumerable<List<TSrc>> Combinations<TSrc>(List<TSrc> src, int n)
        {
            return Enumerable.Range(0, n - 1)
                .Aggregate(
                    Enumerable.Range(0, src.Count() - n + 1)
                        .Select(num => new List<int>() { num }),
                    (list, _) => list.SelectMany(c =>
                        Enumerable.Range(c.Max() + 1, src.Count() - c.Max() - 1)
                            .Select(num => new List<int>(c) { num })
                        )
                    )
                .Select(c => c
                    .Select(num => src[num])
                    .ToList()
                    );
        }

        static void Main(string[] args)
        {
            var inFilename = (args.Length == 1) ? args[0] : "A-small-attempt0.in";
            if (!System.IO.File.Exists(inFilename)) { return; }

            var T = int.Parse(System.IO.File.ReadLines(inFilename).Take(1).ToArray()[0]);
            var result = new List<string>[T];

            Parallel.For(0, Program.TCount, tid =>
            {
                using (var sr = new System.IO.StreamReader(inFilename))
                {
                    Program.SloveAll(sr, result, tid);
                }
            });

            Console.WriteLine("\n/* ------------------------------------------ */\n");

            var outFilename = System.IO.Path.ChangeExtension(inFilename, ".out");
            using (var sw = new System.IO.StreamWriter(outFilename, false))
            {
                foreach (var item in result)
                {
                    item.ForEach(x =>
                    {
                        Console.WriteLine(x);
                        sw.WriteLine(x);
                    });
                }
            }
        }
    }
}
