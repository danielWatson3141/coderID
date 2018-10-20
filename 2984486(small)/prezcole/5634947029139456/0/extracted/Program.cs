using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;

namespace Switches
{
    class Program
    {
        private const string PATH_INPUT_REAL = @"D:\data\Downloads\A-small-attempt1.in";
        private const string PATH_INPUT_TEST = @"D:\data\Downloads\test.txt";
        private const string PATH_OUTPUT = @"D:\data\Downloads\output.txt";

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(PATH_INPUT_REAL);
            var output = new List<string>();

            int counter = 1;
            for (int i = 1; i < lines.Length; i += 3, counter++)
            {
                output.Add("Case #" + (counter) + ": " + Solve(lines[i], lines[i + 1], lines[i + 2]));
            }


            File.WriteAllLines(PATH_OUTPUT, output);
        }

        private static string Solve(string p1, string p2, string p3)
        {
            int N = Int32.Parse(p1.Split()[0]);
            int l = Int32.Parse(p1.Split()[1]);
            List<int> input = p2.Split().Select(n => ConvertBinaryString(n)).ToList();
            List<int> output = p3.Split().Select(n => ConvertBinaryString(n)).ToList();

            int bestChanges = Int32.MaxValue;
            for (int i = 0; i < N; i++)
            {
                int xorVal = input[0] ^ output[i];
                IEnumerable<int> xorVals = input.Select(n => n ^ xorVal);
                if (xorVals.Union(output).Count() == output.Count)
                {
                    int numChanges = 0;
                    int currentNum = xorVal;
                    while (currentNum > 0)
                    {
                        if (currentNum % 2 == 1)
                        {
                            numChanges++;
                        }
                        currentNum /= 2;
                    }
                    if (numChanges < bestChanges)
                    {
                        bestChanges = numChanges;
                    }
                }
            }

            return bestChanges < Int32.MaxValue ? bestChanges.ToString() : "NOT POSSIBLE";
        }

        private static int ConvertBinaryString(string x)
        {
            int output = 0;
            for (int i = x.Length - 1, j = 0; i >= 0; i--, j++)
            {
                output += (int)Math.Pow(2, j) * Int32.Parse(x[i].ToString());
            }
            return output;
        }
    }
}
