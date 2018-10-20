using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2014
{
    internal static class Program
    {
        private static readonly Func<string> read = Console.ReadLine;
        private static readonly Action<string> print = Console.WriteLine;
        private static readonly Action<string> put = Console.Write;

        private static void Main()
        {
            var T = int.Parse(read());
            var n = T;
            while(n-->0)
            {
                var s = read().Split(' ');
                var N = int.Parse(s[0]);
                var L = int.Parse(s[1]);
                var outlet_ = read().Split(' ').Select(_ => Convert.ToInt64(_, 2)).ToArray();
                var device = read().Split(' ').Select(_ => Convert.ToInt64(_, 2)).OrderBy(_ => _).ToArray();
                var outlet = new long[N];

                long bitmax = (long)Math.Pow(2, L);
                long bitcount = long.MaxValue;
                for (long swbit = 0; swbit < bitmax; swbit++)
                {
                    for (int outletnum = 0; outletnum < N; outletnum++)
                    {
                        outlet[outletnum] = outlet_[outletnum] ^ swbit;
                    }
                    Array.Sort(outlet);
                    if (outlet.SequenceEqual(device))
                    {
                        int bitcount_ = 0;
                        for (int i = 0; i < 64; i++)
                        {
                            if ((swbit & (1L<<i)) != 0)
                                bitcount_++;
                        }
                        bitcount = Math.Min(bitcount, bitcount_);
                    }
                }

                print(string.Format("Case #{0}: {1}", T - n, bitcount != long.MaxValue ? bitcount.ToString() : "NOT POSSIBLE"));
            }
        }
    }
}
