using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Net.NetworkInformation;
using System.Runtime.InteropServices;
using System.Text;

namespace GoogleJam
{
    class Program
    {
        private const string Problem = "problem";

        private static int l;
        private static void Solve(int T)
        {
            for ( int test = 1; test <= T; test++)
            {
                int n;
                Read(out n, out l);
                var outlets = ReadArray();
                var devices = ReadArray();
                var diffs = new HashSet<long>();
                var costs = new long[n + 1, n + 1];
                for (int i = 0; i < n; i++)
                {
                    var device = devices[i];
                    for (int j = 0; j < n; j++)
                    {
                        var outlet = outlets[j];
                        var cost = GetCost(device, outlet);
                        diffs.Add(cost);
                        costs[i, j] = cost;
                    }
                }

                var res = int.MaxValue;
                foreach (var diff in diffs)
                {
                    var isGood = true;
                    for (int i = 0; i < n; i++)
                    {
                        var isDevContains = false;
                        for (int j = 0; j < n; j++)
                        {
                            if (costs[i, j] == diff)
                            {
                                isDevContains = true;
                                break;
                            }
                        }
                        if (!isDevContains)
                        {
                            isGood = false;
                            break;
                        }
                    }
                    if (isGood)
                    {
                        res = Math.Min(res, GetCountChanges(diff));
                    }
                }
                if(res == int.MaxValue)
                    Console.WriteLine(OuputStringFormat, test, "NOT POSSIBLE");
                else
                    Console.WriteLine(OuputStringFormat, test, res);
            }
        }

        private static long GetCost(string device, string outlet)
        {
            var res = 0L;
            for (int i = 0; i < l; i++)
            {
                if(device[i] != outlet[i])
                    res += (long)Math.Pow(2, l - 1 - i);
            }
            return res;
        }

        private static int GetCountChanges(long n)
        {
            var res = 0;
            for (int i = 0; i < l; i++)
            {
                long bite = 1 << i;
                if ((n & bite) == bite)
                    res++;
            }
            return res;
        }

        static void Main()
        {
            Console.SetIn(new StreamReader(String.Format(@"..\..\{0}.in", Problem)));
            if (!Debugger.IsAttached)
                Console.SetOut(new StreamWriter(String.Format(@"..\..\{0}.out", Problem)));

            var T = ReadInt();

            Solve(T);

            Console.In.Close();
            Console.Out.Flush();
            Console.Out.Close();
         
            if (Debugger.IsAttached)
            {
                Console.SetIn(new StreamReader(Console.OpenStandardInput()));
                Console.ReadLine();
            }
        }

        const string OuputStringFormat = "Case #{0}: {1}";

        #region Reader

        private static string Read()
        {
            return Console.ReadLine();
        }

        private static void Read<T>(out T a1, out T a2)
        {
            var input = ReadArray();
            a1 = (T)Convert.ChangeType(input[0], typeof(T));
            a2 = (T)Convert.ChangeType(input[1], typeof(T));
        }

        private static void Read<T>(out T a1, out T a2, out T a3)
        {
            var input = ReadArray();
            a1 = (T)Convert.ChangeType(input[0], typeof(T));
            a2 = (T)Convert.ChangeType(input[1], typeof(T));
            a3 = (T)Convert.ChangeType(input[2], typeof(T));
        }

        private static void Read<T>(out T a1, out T a2, out T a3, out T a4)
        {
            var input = ReadArray();
            a1 = (T)Convert.ChangeType(input[0], typeof(T));
            a2 = (T)Convert.ChangeType(input[1], typeof(T));
            a3 = (T)Convert.ChangeType(input[2], typeof(T));
            a4 = (T)Convert.ChangeType(input[3], typeof(T));
        }

        private static int ReadInt()
        {
            return Int32.Parse(Read());
        }

        private static long ReadLong()
        {
            return long.Parse(Read());
        }

        private static double ReadDouble()
        {
            return double.Parse(Read(), CultureInfo.InvariantCulture);
        }

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(Read(), typeof(T));
        }

        private static string[] ReadArray()
        {
            var readLine = Console.ReadLine();
            if (readLine != null)
                return readLine.Split(' ');

            throw new ArgumentException();
        }

        private static List<int> ReadIntArray()
        {
            return ReadArray().Select(Int32.Parse).ToList();
        }

        private static List<long> ReadLongArray()
        {
            return ReadArray().Select(long.Parse).ToList();
        }

        private static List<double> ReadDoubleArray()
        {
            return ReadArray().Select(d => double.Parse(d, CultureInfo.InvariantCulture)).ToList();
        }

        private static List<T> ReadArray<T>()
        {
            return ReadArray().Select(x => (T)Convert.ChangeType(x, typeof(T))).ToList();
        }

        private static void WriteLine(double value)
        {
            Console.WriteLine(value.ToString(CultureInfo.InvariantCulture));
        }

        private static void WriteLine(double value, string stringFormat)
        {
            Console.WriteLine(value.ToString(stringFormat, CultureInfo.InvariantCulture));
        }

        private static void WriteLine<T>(T value)
        {
            Console.WriteLine(value);
        }

        private static void Write(double value)
        {
            Console.Write(value.ToString(CultureInfo.InvariantCulture));
        }

        private static void Write(double value, string stringFormat)
        {
            Console.Write(value.ToString(stringFormat, CultureInfo.InvariantCulture));
        }

        private static void Write<T>(T value)
        {
            Console.Write(value);
        }

        #endregion
    }
}
