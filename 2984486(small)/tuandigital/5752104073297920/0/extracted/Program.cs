using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProperShuffle
{
    class Program
    {
        static void Main(string[] args)
        {
            int test = int.Parse(Console.ReadLine());
            string[] ret = new string[test];
            int goodCount = 0;
            int badCount = 0;
            for (int t = 1; t <= test; t++)
            {
                int n = int.Parse(Console.ReadLine());
                int[] permut = new int[n];
                string[] line = Console.ReadLine().Split();
                for (int i = 0; i < n; i++)
                {
                    permut[i] = int.Parse(line[i]);
                }
                int numberOfLowerIndices = 0;
                int numberOfUpperIndices = 0;
                for (int i = 0; i < n; i++)
                {
                    if (permut[i] < i)
                        numberOfLowerIndices++;
                    else if (permut[i] > i)
                        numberOfUpperIndices++;
                }
                int numberOfNotMoveIndices = n - numberOfUpperIndices - numberOfLowerIndices;
                if (numberOfUpperIndices + numberOfNotMoveIndices > numberOfLowerIndices)
                {
                    ret[t - 1] = "BAD";
                    badCount++;
                }
                else
                {
                    ret[t - 1] = "GOOD";
                    goodCount++;
                }
                Console.WriteLine("Case #{0}: {1}", t, ret[t - 1]);
            }
        }
    }
}
