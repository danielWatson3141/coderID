using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj
{
    class Program
    {
        static int BitCount(Int64 n)
        {
            int c = 0;
            while (n != 0)
            {
                n = n & (n - 1);
                c++;
            }
            return c;
        }
        static void Main(string[] args)
        {
            var T = Int64.Parse(Console.ReadLine());
            for (Int64 i = 0; i < T; ++i)
            {
                var s = Console.ReadLine().Split(' ');
                Int64 N = Int64.Parse(s[0]); // how many numbers
                Int64 L = Int64.Parse(s[1]); // how many bits/number

                List<Int64> goals = new List<Int64>();
                List<Int64> original = new List<Int64>();
                s = Console.ReadLine().Split(' ');
                foreach (var s1 in s)
                {
                    Int64 num = 0;
                    for (int j = 0; j < s1.Length; ++j)
                    {
                        num = num * 2 + ((s1[j] == '1') ? 1 : 0);
                    }
                    original.Add(num);
                }
                s = Console.ReadLine().Split(' ');
                foreach (var s1 in s)
                {
                    Int64 num = 0;
                    for (int j = 0; j < s1.Length; ++j)
                    {
                        num = num * 2 + ((s1[j] == '1') ? 1 : 0);
                    }
                    goals.Add(num);
                }

                int best = int.MaxValue;
                for (int j = 0; j < goals.Count; ++j)
                {
                    Int64 mask = goals[j] ^ original[0];
                    bool win = true;
                    for (int k = 0; k < goals.Count; ++k)
                    {
                        if (!goals.Contains(original[k] ^ mask))
                        {
                            win = false;
                            break;
                        }
                    }
                    if (win)
                    {
                        if (BitCount(mask) < best)
                        {
                            best = BitCount(mask);
                        }
                    }
                }

                if (best < int.MaxValue)
                {
                    // write out the answer...
                    System.Console.WriteLine("Case #{0}: {1}", 1 + i, best);
                }
                else 
                {
                    System.Console.WriteLine("Case #{0}: {1}", 1 + i, "NOT POSSIBLE");
                }
            }
        }
    }
}
