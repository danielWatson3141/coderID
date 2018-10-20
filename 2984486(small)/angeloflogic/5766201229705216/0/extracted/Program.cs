using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                var N = Convert.ToInt32(Console.ReadLine());
                var C = new int[N];
                var X = new int[N - 1];
                var Y = new int[N - 1];
                var EMap = new uint[N];
                var NMap = new uint[N];
                for (int n = 0; n < N - 1; ++n)
                {
                    var XY = Console.ReadLine().Split(' ').Select(token => Convert.ToInt32(token)).ToArray();
                    X[n] = XY[0] - 1;
                    Y[n] = XY[1] - 1;
                    EMap[X[n]] |= (1u << n);
                    EMap[Y[n]] |= (1u << n);
                    NMap[X[n]] |= (1u << Y[n]);
                    NMap[Y[n]] |= (1u << X[n]);
                }
                var minC = Int32.MaxValue;
                for (uint c = 0; c < (1 << N); ++c)
                {
                    uint csh = 0;
                    for (int n = 0; n < N; ++n)
                        if ((c & (1u << n)) != 0)
                            csh |= EMap[n];
                    var csh2 = csh;
                    for (int b = 0; b < N; ++b)
                        C[b] = 0;
                    for (int b = 0; b < N - 1; ++b)
                    {
                        if ((csh & 1) == 0)
                        {
                            ++C[X[b]];
                            ++C[Y[b]];
                        }
                        csh >>= 1;
                    }
                    int count0 = 0;
                    int count1 = 0;
                    int count2 = 0;
                    int count3 = 0;
                    int root = -1;
                    for (int b = 0; b < N; ++b)
                    {
                        if (C[b] == 0)
                            ++count0;
                        else if (C[b] == 1)
                            ++count1;
                        else if (C[b] == 2)
                        {
                            ++count2;
                            root = b;
                        }
                        else if (C[b] == 3)
                            ++count3;
                    }
                    if (count0 + count1 + count2 + count3 == N && count2 == 1 || count0 == N)
                    {
                        uint cov = (1u << root);
                        for (int i = 0; i < N; ++i)
                            for (int b = 0; b < N - 1; ++b)
                                if ((csh2 & (1 << b)) == 0)
                                {
                                    if ((cov & (1 << X[b])) != 0)
                                        cov |= (1u << Y[b]);
                                    if ((cov & (1 << Y[b])) != 0)
                                        cov |= (1u << X[b]);
                                }
                        if (NumberOfSetBits(cov) == N - NumberOfSetBits(c))
                            minC = Math.Min(minC, NumberOfSetBits(c));
                    }
                }
                Console.WriteLine("Case #{0}: {1}", t, minC);
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
