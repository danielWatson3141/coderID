using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace MainApp
{
    public static class CodeJamExtensions
    {
        public static IEnumerable<string> ReadDataLines(this StreamReader reader)
        {
            int lineCount = reader.ReadLine().ToInt32();
            return reader.ReadLines(lineCount);

        }

        public static IEnumerable<string> ReadLines(this StreamReader reader, int lineCount)
        {
            for (int i = 0; i < lineCount; i++)
            {
                yield return reader.ReadLine();
            }
        }

        public static int ToInt32(this string str)
        {
            return int.Parse(str);
        }

        public static long ToInt64(this string str)
        {
            return long.Parse(str);
        }

        public static double ToDouble(this string str)
        {
            return double.Parse(str);
        }

        public static List<string> Split(this string str)
        {
            return str.Split(' ').ToList();
        }

        public static List<int> SplitAsInt32(this string str)
        {
            return str.Split(' ').Select(s => s.ToInt32()).ToList();
        }

        public static List<long> SplitAsInt64(this string str)
        {
            return str.Split(' ').Select(s => s.ToInt64()).ToList();
        }

        public static List<double> SplitAsDouble(this string str)
        {
            return str.Split(' ').Select(s => s.ToDouble()).ToList();
        }

        private static int caseIndex = 0;

        public static void WriteCaseOutput(this StreamWriter writer, params object[] values)
        {
            writer.Write("Case #{0}:", caseIndex + 1);
            foreach (var val in values)
            {
                writer.Write(" ");
                writer.Write(val);                
            }
            writer.WriteLine();
            caseIndex++;
        }

    }

    class Program
    {
        static string ToOutputFileName(string fileName)
        {
            return Path.GetFileNameWithoutExtension(fileName) + ".out";
        }

        static int C(List<Int64> outlets, List<Int64> dev, long f, int l, int switched)
        {
            long finalff = (long)1 << l;
            if (f == finalff) return switched;
            // last bit count
            int n = outlets.Count;
            int c = outlets.Select(o => o & f).Count(o => o > 0);
            int d = dev.Select(o => o & f).Count(o => o > 0);
            int result = int.MinValue;
            long f2 = (f << 1) - 1;
            var ds = dev.Select(o => o & f2);
            if (d == c)
            {
                var cs = new HashSet<long>(outlets.Select(o => o & f2));   
                if (cs.SetEquals(ds))
                {
                    result = switched + C(outlets, dev, f << 1, l, switched);
                }
            }
            if (result < 0 && d == n - c)
            {
                var cs = new HashSet<long>(outlets.Select(o => (o ^ f) & f2));
                if (cs.SetEquals(ds))
                {
                    var newoutlets = new List<long>(outlets);
                    for (int j = 0; j < newoutlets.Count; j++)
                    {
                        newoutlets[j] ^= f;
                    }
                    result = switched + 1 + C(newoutlets, dev, f << 1, l, switched);
                }
            }
            return result;
        }

        static int Calculate(List<Int64> outlets, List<Int64> dev, int l)
        {
            return C(outlets, dev, 1, l, 0);

            int switched = 0;
            int n = outlets.Count;
            for (int i = 0, f = 1; i < l; i++)
            {
                // last bit count
                int c = outlets.Select(o => o & f).Count(o => o > 0);
                int d = dev.Select(o => o & f).Count(o => o > 0);
                if (d == c || d == n - c)
                {
                    bool su = false;
                    // try flag check
                    if (d == c)
                    {
                        int f2 = (f << 1) - 1;
                        var cs = new HashSet<long>(outlets.Select(o => o & f2));
                        var ds = dev.Select(o => o & f2);
                        if (cs.SetEquals(ds)) su = true;
                    }
                    if (!su && d == n - c)
                    {
                        int f2 = (f << 1) - 1;
                        var cs = new HashSet<long>(outlets.Select(o => (o ^ f) & f2));
                        var ds = dev.Select(o => o & f2);
                        if (cs.SetEquals(ds))
                        {
                            for (int j = 0; j < outlets.Count; j++)
                            {
                                outlets[j] ^= f;
                            }
                            su = true;
                            switched++;
                        }
                    }
                    if (!su) return -1;
                }
                else return -1;
                f <<= 1;
            }
            return switched;
        }



        static void Main(string[] args)
        {
            string inputFileName = args[0];
            var reader = new StreamReader(inputFileName);
            int caseCount = reader.ReadLine().ToInt32();
            var writer = new StreamWriter(ToOutputFileName(inputFileName));
            for (int i = 0; i < caseCount; i++)
            {
                var nl = reader.ReadLine().SplitAsInt32();
                var n = nl[0];
                var l = nl[1];
                var outlets = reader.ReadLine().Split().Select(o => Convert.ToInt64(o, 2)).ToList();
                var devs = reader.ReadLine().Split().Select(o => Convert.ToInt64(o, 2)).ToList();
                int r = Calculate(outlets, devs, l);
                string result = r >= 0 ? r.ToString() : "NOT POSSIBLE";
                writer.WriteCaseOutput(result);
            }
            reader.Close();
            writer.Close();

            // show explorer to access output file
            Process.Start("Explorer", Environment.CurrentDirectory);
        }
    }
}
