using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;

namespace google_code_jam
{

    class MinesweeperMaster
    {
        int R, C, M;
        int[,] g, h;

        int N;

        bool Z(int r, int c)
        {
            if (r >= 0 && c >= 0 && r < R && c < C)
            {
                return true;
            }
            return false;
        }

        int Y(int r, int c)
        {
            int n = 0;
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (Z(r + i, c + j))
                    {
                        if (g[r + i, c + j] == -1)
                        {
                            n++;
                        }
                    }
                }
            }
            return n;
        }

        void Remove(int r, int c)
        {
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (Z(r + i, c + j))
                    {
                        if (g[r + i, c + j] == -1)
                        {
                            g[r + i, c + j] = 0;
                        }
                    }
                }
            }
        }

        void X()
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (g[i, j] != -1)
                    {
                        g[i, j] = Y(i, j);
                    }
                }
            }
        }

        void U(ref int r, ref int c, int m)
        {
            int min = int.MaxValue;

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (g[i, j] == m)
                    {
                        r = i;
                        c = j;
                        return;
                    }
                    if (g[i, j] > 0 && g[i, j] < min)
                    {
                        min = g[i, j];
                        r = i;
                        c = j;
                    }
                }
            }
            return;
        }

        public string MinesweeperMaster2(string[] args)
        {
            var A = args[0].Split(' ');

            R = int.Parse(A[0]);
            C = int.Parse(A[1]);
            M = int.Parse(A[2]);

            string s = "\r\nImpossible";
            g = new int[R, C];

            int N = R * C - 1;

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    g[i, j] = -1;
                }
            }

            g[0, 0] = 0;

            while (true)
            {
                X();

                if (N == M)
                {
                    break;
                }

                if (N < M)
                {
                    return s;
                }

                int r = 0;
                int c = 0;

                U(ref r, ref c, N - M);
                N -= g[r, c];
                Remove(r, c);
            }

            s = "";

            for (int i = 0; i < R; i++)
            {
                s += "\r\n";
                for (int j = 0; j < C; j++)
                {
                    if (i == 0 && j == 0)
                    {
                        s += "c";
                    }
                    else if (g[i, j] >= 0)
                    {
                        s += ".";
                    }
                    else
                    {
                        s += "*";
                    }
                }
            }

            return s;
        }
    }

    class ChargingChaos
    {
        public string solve(string[] arg)
        {
            string[] X = arg[1].Split(' ');
            string[] Y = arg[2].Split(' ');

            int N = X.Length;
            int L = X[0].Length;

            long[] x = new long[N];
            long[] y = new long[N];

            for (int i = 0; i < N; i++)
            {
                x[i] = Convert.ToInt64(X[i], 2);
                y[i] = Convert.ToInt64(Y[i], 2);
            }

            int min = int.MaxValue;

            for (int i = 0; i < N; i++)
            {
                long z = x[0] ^ y[i];
                int[] g = new int[N];

                g[i] = 1;

                for (int j = 1; j < N; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        if (g[k] == 1)
                        {
                            continue;
                        }

                        if ((z ^ x[j]) == y[k])
                        {
                            g[k] = 1;
                            break;
                        }
                    }
                }

                if (g.Sum() == N)
                {
                    int n = 0;
                    for (int j = 0; j < 50; j++)
                    {
                        long t = ((long)1) << j;
                        if ((t & z) > 0)
                        {
                            n++;
                        }
                    }
                    min = Math.Min(min, n);
                }
            }

            if (min == int.MaxValue)
            {
                return "NOT POSSIBLE";
            }

            return min.ToString();
        }
    }

    class Program
    {
        delegate string SOLVE(string[] x);

        static void Main(string[] args)
        {
            string folder = @"D:\TMP\";
            string input = "input";

            int n = 3;

            StreamReader reader = new StreamReader(folder + input + ".in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"D:\TMP\out.txt");
            string s = reader.ReadLine();

            int m = int.Parse(s);

            for (int i = 0; i < m; i++)
            {
                string[] x = new string[n];

                for (int j = 0; j < n; j++)
                {
                    x[j] = reader.ReadLine();
                }

                string r = "Case #" + (i + 1).ToString() + ":" + " " + new ChargingChaos().solve(x);
                writer.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }
    }
}
