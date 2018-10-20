using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
namespace GCJ
{
    class Program
    {
        const long mod = 1000002013;
        class Solver
        {
            int cmp(KeyValuePair<long, long> a, KeyValuePair<long, long> b)
            {
                return a.Key.CompareTo(b.Key);
            }

            int cmp(KeyValuePair<int, string> x, KeyValuePair<int, string> y)
            {
                return -x.Key.CompareTo(y.Key);
            }
            
            Dictionary<int, int> ppp = new Dictionary<int, int>();
            const int cnt = 30000;
            public void init()
            {
                int NN = 1000;
                if (ppp.Count == 0)
                {
                    Random r = new Random();
                    for (int i = 0; i < NN; i++) for (int j = 0; j < NN; j++) ppp.Add(1000 * i + j, 0);
                    for (int i = 0; i < cnt; i++)
                    {
                        Console.WriteLine(i);
                        int[] p = new int[NN];
                        for (int j = 0; j < NN; j++) p[j] = j;
                        for (int j = 0; j < NN; j++)
                        {
                            int k = r.Next(NN);
                            int x = p[k];
                            p[k] = p[j];
                            p[j] = x;
                        }
                        for (int j = 0; j < NN; j++) for (int k = j + 1; k < NN; k++)
                            {
                                ppp[p[j] * 1000 + p[k]]++;
                            }
                    }
                }
            }


            public string Solve(MyIO io)
            {
                int N = io.NextInt;
                int NN = N;


                List<int> l = new List<int>();
                for (int i = 0; i < N; i++) l.Add(io.NextInt);
                double R1 = 0, R2 = 0;
                for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++)
                    {
                        R1 += Math.Log(0.5);
                        R2 += Math.Log(ppp[l[i] * 1000 + l[j]] / (double)cnt);
                    }
                if (R1 < R2) return "BAD";
                else return "GOOD";


                return "";
            }
        }
        static void Main(string[] args)
        {
            Solver solve = new Solver();
            solve.init();
            MyIO io = new MyIO(new StreamReader(@"C:\Users\zaq1xsw2tk\Documents\Visual Studio 2012\Projects\codejam\codejam\in.txt"));
            int caseCount = io.NextInt;
            for (int i = 0; i < caseCount; i++)
            {
                string res = solve.Solve(io);
                io.WriteLine("Case #{0}: {1}", i + 1, res);
                Console.WriteLine("Case #{0}: {1}", i + 1, res);
            }
            io.Flush();
        }
        class MyIO
        {
            TextReader reader;
            TextWriter writer = new StreamWriter("out.txt");
            string[] tokens;
            int pointer;
            public MyIO(TextReader rd)
            {
                reader = rd;
            }
            public string NextLine()
            {
                try
                {
                    return reader.ReadLine();
                }
                catch (IOException)
                {
                    return null;
                }
            }
            public string NextString
            {
                get
                {
                    try
                    {
                        while (tokens == null || pointer >= tokens.Length)
                        {
                            tokens = NextLine().Split(new char[] { ' ' }, System.StringSplitOptions.RemoveEmptyEntries);
                            pointer = 0;
                        }
                        return tokens[pointer++];
                    }
                    catch (IOException)
                    {
                        return null;
                    }
                }
            }
            public int NextInt
            {
                get { return int.Parse(NextString); }
            }
            public long NextLong
            {
                get { return long.Parse(NextString); }
            }
            public double NextDouble
            {
                get { return double.Parse(NextString); }
            }
            public bool Write(string format, params object[] args)
            {
                writer.Write(format, args);
                return true;
            }
            public void WriteLine(string format, params object[] args)
            {
                writer.WriteLine(format, args);
            }
            public void WriteLine(object obj)
            {
                writer.WriteLine("{0}", obj);
            }
            public void WriteLine()
            {
                writer.WriteLine();
            }
            public void Write(object obj)
            {
                writer.Write("{0}", obj);
            }
            public void Flush()
            {
                writer.Flush();
            }
        }
    }
}
