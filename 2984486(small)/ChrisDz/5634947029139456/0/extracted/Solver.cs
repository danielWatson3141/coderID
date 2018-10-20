using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Google.CodeJam
{
    internal class Solver
    {
        private static int CountBits(long i)
        {
            int count = 0;
            while (i > 0)
            {
                if ((i & 1) == 1)
                    count++;

                i >>= 1;
            }
            return count;
        }

        private static void Solve(int id, TextReader reader, TextWriter writer)
        {
            var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int n = line[0], l = line[1];

            var initialFlow = reader.ReadLine().Split(' ').Select(s => Convert.ToInt64(s, 2)).ToArray();
            var requiredFlow = reader.ReadLine().Split(' ').Select(s => Convert.ToInt64(s, 2)).ToArray();

            var solutions = new List<long>();
            for (long bitsToFlip = 0; bitsToFlip <= 0x3FF; bitsToFlip++)
            {
                var flow = initialFlow.Select(outlet => outlet ^ bitsToFlip);
                if (requiredFlow.All(flow.Contains))
                    solutions.Add(bitsToFlip);
            }

            if (solutions.Count == 0)
            {
                writer.WriteLine("Case #{0}: {1}", id, "NOT POSSIBLE");
                return;
            }

            int minBits = solutions.Select(CountBits).Min();
            writer.WriteLine("Case #{0}: {1}", id, minBits);
        }

        private static void Main(string[] args)
        {
            try
            {
                var inputPath = args[0];
                var outputPath = args[1];

                using (var reader = new StreamReader(inputPath))
                using (var writer = new StreamWriter(outputPath))
                {
                    int count = int.Parse(reader.ReadLine());
                    for (int i = 0; i < count; i++)
                        Solve(i + 1, reader, writer);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
