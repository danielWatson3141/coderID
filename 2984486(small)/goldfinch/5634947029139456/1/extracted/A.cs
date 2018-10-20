using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14
{
    using System.Globalization;

    public class A
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];
            for (int i = 0; i < cases; i++)
            {
                var zline = lines[i * 3 + 1].Split(' ').Select(s => int.Parse(s)).ToList();
                int n = zline[0];
                int l = zline[1];
                var firstLine = lines[i * 3 + 2].Split(' ').Select(s => this.Convert(s)).ToArray();

                var secondLine = lines[i * 3 + 3].Split(' ').Select(s => this.Convert(s)).ToArray();



                int a = this.Calc(n, l, firstLine, secondLine);
                if (a == int.MaxValue)
                {
                    res[i] = string.Format("Case #{0}: NOT POSSIBLE", i + 1);
                }
                else
                {
                    res[i] = string.Format("Case #{0}: {1}", i + 1, a);
                }

            }
            return res;
        }

        private int Calc(int n, int l, long[] switches, long[] devices)
        {
            int res = int.MaxValue;
            Array.Sort(devices);
            for (int i = 0; i < n; i++)
            {
                long s1 = switches[0];
                for (int j = 0; j < devices.Length; j++)
                {
                    long dif = devices[j] ^ s1;

                    for (int q = 0; q < n; q++)
                        switches[q] ^= dif;
                    Array.Sort(switches);
                    bool f = false;
                    for (int q = 0; q < n; q++)
                        if (switches[q] != devices[q])
                            f = true;
                    if (!f)
                    {
                        long t = dif;
                        int c = 0;
                        while (t > 0)
                        {
                            if (t % 2 == 1)
                                c++;
                            t /= 2;
                        }
                        res = Math.Min(res, c);
                    }
                    for (int q = 0; q < n; q++)
                        switches[q] ^= dif;
                }
            }
            return res;
        }

        private long Convert(string s)
        {
            long res = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] != '0')
                    res += 1;
                res *= 2;
            }
            return res;
        }
    }
}
