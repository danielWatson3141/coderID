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
        private static Dictionary<int, List<int>> table;
        private static void Solve(int T)
        {
            for ( int test = 1; test <= T; test++)
            {
                int n = ReadInt();
                table = new Dictionary<int, List<int>>();
                for (int i = 0; i < n-1; i++)
                {
                    int x, y;
                    Read(out x, out y);
                    x--;
                    y--;
                    if(!table.ContainsKey(x))
                        table.Add(x, new List<int>());

                    if (!table.ContainsKey(y))
                        table.Add(y, new List<int>());

                    table[x].Add(y);
                    table[y].Add(x);
                }
                var mask = (1 << (n));
                var res = int.MaxValue;
                for (int usedMask = 1; usedMask < mask; usedMask++)
                {
                    var isGood = false;
                    for (int root = 0; root < n; root++)
                    {
                        var bite = 1 << root;
                        if((usedMask & bite) != bite)
                            continue;

                        var used = new bool[n];
                        used[root] = true;
                        if (CheckNode(root, usedMask, -1, used))
                        {
                            isGood = true;
                            for (int i = 0; i < n; i++)
                            {
                                if (!used[i])
                                {
                                    bite = 1 << i;
                                    if ((usedMask & bite) == bite)
                                    {
                                        isGood = false;
                                        break;
                                    }
                                }
                            }
                            
                            break;
                        }
                    }
                    if (isGood)
                        res = Math.Min(res, n - GetCountOnes(usedMask));
                }
                
                Console.WriteLine(OuputStringFormat, test, res);
            }
        }

        private static int GetCountOnes(int mask)
        {
            var res = 0;
            var pow = 1;
            while (pow <= mask)
            {
                if ((mask & pow) == pow)
                    res++;

                pow *= 2;
            }
            return res;
        }

        private static bool CheckNode(int node, int mask, int root, bool[] used)
        {
            if (!table.ContainsKey(node))
                throw new ArgumentNullException("node");

            var count = 0;
            foreach (var child in table[node])
            {
                if(child == root)
                    continue;

                used[child] = true;
                var bite = 1 << child;
                if((mask & bite) != bite)
                    continue;

                var isGood = CheckNode(child, mask, node, used);
                if(!isGood)
                    return false;

                count++;
            }

            return count == 2 || count == 0;
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
