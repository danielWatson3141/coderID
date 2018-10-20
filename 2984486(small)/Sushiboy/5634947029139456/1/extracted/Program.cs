using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace gcj1aal
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
                long[] a = rarray2(s[++n]);
                long[] b = rarray2(s[++n]);

                int N = len[0], L = len[1];
                int l = 1;

                Array.Sort(b);

                int[] x = new int[L];
                int[] y = new int[L];
                int k = 0;

                for (int i = 0; i < N; i++)
                {
                    k = 0;
                    while (a[i] != 0)
                    {
                        x[k] += (int)a[i] % 2;
                        a[i] /= 2;
                        k++;
                    }
                    k = 0;
                    while (b[i] != 0)
                    {
                        y[k] += (int)b[i] % 2;
                        b[i] /= 2;
                        k++;
                    }
                }

                int ans = 0;
                for (int i = 0; i < L; i++)
                {
                    if (x[i] == y[i])
                    {
                    }
                    else if (x[i] == (N - y[i]))
                    {
                        ans++;
                    }
                    else
                    {
                        ans = -100;
                        break;
                    }
                }

                if (ans<0)
                {
                    w.WriteLine("Case #{0}: NOT POSSIBLE", j + 1);
                }
                else
                {
                    w.WriteLine("Case #{0}: {1}", j + 1, ans);
                }

            }
            w.Close();
        }

        static int[] rarray(string a)
        {
            return (from s in a.Split(' ') select int.Parse(s)).ToArray();
        }

        static long[] rarray2(string a)
        {
            return (from s in a.Split(' ') select Convert.ToInt64(s, 2)).ToArray();
        }

        static double[] drarray(string a)
        {
            return (from s in a.Split(' ') select double.Parse(s)).ToArray();
        }

    }
}
