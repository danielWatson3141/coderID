using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;
using System.Numerics;

namespace A
{
    class Program
    {
        static int numBits(int x)
        {
            int count = 0;
            while (x != 0)
            {
                x = x & (x - 1);
                count++;
            }
            return count;
        }

        static string Solve(int N, int L, string[] outlets, string[] devices)
        {
            char[][] os = new char[N][];
            for (int i = 0; i < N; i++)
                os[i] = outlets[i].ToCharArray();


            int B = 1 << L;
            var all = Enumerable.Range(0, B).OrderBy(x => numBits(x)).ToArray();

            foreach (var x in all)
            {
                for (int i = 0; i < L; i++)
                    if (((1 << i) & x) != 0)
                    {
                        for (int j = 0; j < N; j++)
                            os[j][i] = os[j][i] == '0' ? '1' : '0';
                    }

                bool[] matched = new bool[N];
                for (int i = 0; i < N; i++)
                {
                    string s = new string(os[i]);
                    for (int j = 0; j < N; j++)
                        if (s == devices[j])
                        {
                            matched[j] = true;
                            break;
                        }
                }

                if (matched.All(m => m))
                    return numBits(x).ToString();

                for (int i = 0; i < L; i++)
                    if (((1 << i) & x) != 0)
                    {
                        for (int j = 0; j < N; j++)
                            os[j][i] = os[j][i] == '0' ? '1' : '0';
                    }
            }

            return "NOT POSSIBLE";
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                int N = int.Parse(line[0]);
                int L = int.Parse(line[1]);

                string[] outlets = Console.ReadLine().Split();
                string[] devices = Console.ReadLine().Split();

                if (outlets.Any(x => x.Length != L) || devices.Any(x => x.Length != L))
                    throw new Exception();

                Console.WriteLine("Case #{0}: {1}", t, Solve(N, L, outlets, devices));
            }
        }
    }
}
