using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class A
    {
        static void Main(string[] args)
        {
            using(var sr = new StreamReader(@"D:\Jam\A\input.txt"))
            {
                using (var sw = new StreamWriter(@"D:\Jam\A\output.txt"))
                {
                    long T = long.Parse(sr.ReadLine());
                    for (int i = 1; i <= T; i++)
                    {
                        var splitted = sr.ReadLine().Split(' ').ToArray();
                        long N = long.Parse(splitted[0]);
                        long L = long.Parse(splitted[1]);

                        var outlets = sr.ReadLine().Split(' ').Select(str => ConvertToNumber(str));
                        var devices = sr.ReadLine().Split(' ').Select(str => ConvertToNumber(str));

                        long ans = long.MaxValue;
                        long upperBound = (1L << (int)L);
                        for (long switches = 0; switches < upperBound; switches++)
                        {
                            var newOutletsSet = new HashSet<long>(outlets.Select(outlet => outlet ^ switches));

                            if(devices.All(d => newOutletsSet.Contains(d)))
                            {
                                ans = Math.Min(ans, GetOnesCount(switches));
                            }
                        }

                        if (ans == long.MaxValue)
                        {
                            sw.WriteLine("Case #{0}: {1}", i.ToString(), "NOT POSSIBLE");
                        }
                        else
                        {
                            sw.WriteLine("Case #{0}: {1}", i.ToString(), ans);
                        }
                    }
                }
            }
        }

        private static long GetOnesCount(long switches)
        {
            int res = 0;
            while (switches != 0)
            {
                res += (int)(switches % 2L);
                switches = switches >> 1;
            }
            return (long)res;
        }

        private static long ConvertToNumber(string str)
        {
            long res = 0;
            foreach (var c in str)
            {
                res = res << 1;
                res = res + (c == '1' ? 1l : 0l);
            }
            return res;
        }
    }
}
