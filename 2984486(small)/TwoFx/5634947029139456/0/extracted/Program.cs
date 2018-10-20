using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;

namespace R1AA
{
    class Program
    {
        private const bool DEBUG = false;
        static void debug()
        {
            int[][] t = new[] { new[] { 0, 1 }, new[] { 1, 0 } };
            flip(t, 1);
            Console.WriteLine();
        }

        static string solveCase()
        {
            int[] nl = readMany<int>();
            int n = nl[0];
            int l = nl[1];
            int[][] initial = readMany().Select(x => x.Select(y => int.Parse(new string(new char[] {y}))).ToArray()).ToArray();
            int[][] req = readMany().Select(x => x.Select(y => int.Parse(new string(new char[] {y}))).ToArray()).ToArray();
            List<Tuple<int[][], int>> workingOn = new List<Tuple<int[][], int>>() { new Tuple<int[][], int>(clo(initial), 0) };
            List<Tuple<int[][], int>> newWorking = new List<Tuple<int[][], int>>();
            for (int cl = 0; cl < l; cl++)
            {
                newWorking.Clear();
                foreach (Tuple<int[][], int> cfg in workingOn)
                {
                    int c = getc(cfg.Item1, cl);
                    int rc = getc(req, cl);
                    //if (c == n - c) Console.WriteLine("shit.");
                    if (rc == c)
                    {
                        newWorking.Add(cfg);
                    }
                    
                    if (n - c == rc)
                    {
                        newWorking.Add(new Tuple<int[][], int>(flip(cfg.Item1, cl), cfg.Item2 + 1));
                    }
                }
                if (newWorking.Count == 0)
                {
                    return "NOT POSSIBLE";
                }
                workingOn = newWorking.Select(x => new Tuple<int[][], int>(clo(x.Item1), x.Item2)).ToList();
                //else return "NOT POSSIBLE";
            }
            foreach (var cur in workingOn.OrderBy(x => x.Item2))
            {
                string[] init = cur.Item1.Select(i => i.Aggregate<int, string>("", (old, q) => old + q.ToString())).OrderBy(x => x).ToArray();
                string[] requ = req.Select(i => i.Aggregate<int, string>("", (old, q) => old + q.ToString())).OrderBy(x => x).ToArray();
                if (init.SequenceEqual(requ))
                {
                    return cur.Item2.ToString();
                }
            }
            return "NOT POSSIBLE";
        }

        static int[][] clo(int[][] inp)
        {
            return inp.Select(x => (int[])x.Clone()).ToArray();
        }

        static int getc(int[][] thing, int p)
        {
            return thing.Count(t => t[p] == 1);
        }

        static int[][] flip(int[][] thing, int p)
        {
            int[][] th = clo(thing);
            foreach (int[] t in th)
            {
                t[p] = 1 - t[p];
            }
            return th;
        }

        static void Main(string[] args)
        {
            if (DEBUG)
            {
                debug();
            }
            else
            {
                Initialize();
                SolveAll(solveCase);
            }
            Console.ReadKey();
        }

        private static StreamReader inf;
        private static StreamWriter outf;

        private delegate void o(string format, params object[] args);
        private static o Output;

        private static T read<T>()
        {
            return (T)Convert.ChangeType(inf.ReadLine(), typeof(T));
        }

        private static string read()
        {
            return inf.ReadLine();
        }

        private static T[] readMany<T>()
        {
            return readMany<T>(' ');
        }

        private static _[] readMany<_>(params char[] ___)
        {
            return read().Split(___).Select(__ => (_)Convert.ChangeType(__, typeof(_))).ToArray();
        }

        private static string[] readMany()
        {
            return readMany<string>();
        }

        private static T[][] readField<T>(int height, Func<char, T> map)
        {
            T[][] res = new T[height][];
            for (int _ = 0; _ < height; _++)
            {
                res[_] = read().Select(c => map(c)).ToArray();
            }
            return res;
        }

        private static char[][] readField(int height)
        {
            return readField(height, c => c);
        }

        private static T[][] readField<T>(int height, Dictionary<char, T> dic)
        {
            return readField(height, c => dic[c]);
        }

        public static void Initialize()
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Input file: ");
            inf = new StreamReader(Console.ReadLine());
            Console.Write("Output file: ");
            outf = new StreamWriter(Console.ReadLine());
            Console.ForegroundColor = ConsoleColor.White;
            Output = highlightedPrint;
            Output += outf.WriteLine;
        }

        private static void highlightedPrint(string format, params object[] args)
        {
            ConsoleColor prev = Console.ForegroundColor;
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine(format, args);
            Console.ForegroundColor = prev;
        }

        public static void SolveAll(Func<string> calc)
        {
            int cases = int.Parse(inf.ReadLine());
            for (int _ = 1; _ <= cases; _++)
            {
                Output("Case #{0}: {1}", _, calc());
            }
            inf.Close();
            outf.Close();
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("Eureka!");
        }
    }
}