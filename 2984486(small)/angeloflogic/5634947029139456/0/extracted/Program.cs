using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                var NL = Console.ReadLine().Split(' ');
                var N = Convert.ToInt32(NL[0]);
                var L = Convert.ToInt32(NL[1]);
                var outlets = Console.ReadLine().Split(' ').Select(token => Convert.ToUInt32(token, 2)).ToArray();
                var devices = Console.ReadLine().Split(' ').Select(token => Convert.ToUInt32(token, 2)).ToArray();
                var hash = devices.ToDictionary(d => d, d => false);
                var minS = Int32.MaxValue;
                for (uint s = 0; s < (1 << L); ++s)
                {
                    bool conflict = false;
                    foreach (var outlet in outlets)
                    {
                        if (!hash.ContainsKey(outlet ^ s))
                            conflict = true;
                        else if (hash[outlet ^ s])
                            conflict = true;
                        else
                            hash[outlet ^ s] = true;
                    }
                    foreach (var key in devices)
                        hash[key] = false;
                    if (!conflict)
                        minS = Math.Min(minS, NumberOfSetBits(s));
                }
                if (minS < Int32.MaxValue)
                    Console.WriteLine("Case #{0}: {1}", t, minS);
                else
                    Console.WriteLine("Case #{0}: NOT POSSIBLE", t);
            }
        }

        static int NumberOfSetBits(uint i)
        {
            i = i - ((i >> 1) & 0x55555555);
            i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
            return (int)((((i + (i >> 4)) & 0x0F0F0F0Fu) * 0x01010101u) >> 24);
        }
    }
}
