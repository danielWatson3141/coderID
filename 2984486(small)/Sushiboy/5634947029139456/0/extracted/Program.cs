using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace gcj1aa
{
    class Program
    {
        static void Main(string[] args)
        {

            string textFile = "D:\\gcj.txt";
            System.Text.Encoding enc = Encoding.GetEncoding("shift_jis");
            string[] s = File.ReadAllLines(textFile, enc);

            int n = 0;
            int[] Tm = rarray(s[0]);
            int T = Tm[0];

            string fname = @"D:\Test.txt";
            Encoding sjis = Encoding.GetEncoding("Shift-JIS");
            StreamWriter w = new StreamWriter(fname, false, sjis);

            for (int j = 0; j < T; j++)
            {
                int[] len = rarray(s[++n]);
                int[] a = rarray2(s[++n]);
                int[] b = rarray2(s[++n]);

                int N=len[0],L = len[1];
                int l = 1;

                Array.Sort(b);
                int times = 9999999;

                for (int i = 0; i < L; i++)
                {
                    l *= 2;
                }

                for (int i = 0; i < l; i++)
                {
                    int[] c = (int[])a.Clone();
                    for (int k = 0; k < N; k++)
                    {
                        c[k]^= i;
                    }
                    Array.Sort(c);

                    if(c.SequenceEqual(b))
                    {
                        int p=i,ct=0;
                        while (p != 0)
                        {
                            ct += p % 2;
                            p /= 2;
                        }
                        times = Math.Min(times, ct);
                    }
                }
                if (times > L)
                {
                    w.WriteLine("Case #{0}: NOT POSSIBLE", j + 1);
                }
                else
                {
                    w.WriteLine("Case #{0}: {1}", j + 1, times);
                }
                
            }
            w.Close();
        }

        static int[] rarray(string a)
        {
            return (from s in a.Split(' ') select int.Parse(s)).ToArray();
        }

        static int[] rarray2(string a)
        {
            return (from s in a.Split(' ') select Convert.ToInt32(s,2)).ToArray();
        }

        static double[] drarray(string a)
        {
            return (from s in a.Split(' ') select double.Parse(s)).ToArray();
        }

    }
}
