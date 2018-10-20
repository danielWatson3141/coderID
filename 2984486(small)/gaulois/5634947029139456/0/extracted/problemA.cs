
#define TRACE

using System;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Problem
    {
        public List<UInt64> devices = new List<UInt64>();
        public List<UInt64> slots = new List<UInt64>();
        public int nBits;
    }

    class MainClass
    {
        static int HowManyMatches(Problem p)
        {
            HashSet<UInt64> hs = new HashSet<ulong>();
            foreach(var ui in p.slots)
            {
                hs.Add(ui);
            }

            int m = 0;

            foreach(var ui in p.devices)
            {
                if(hs.Contains(ui))
                {
                    m += 1;
                }
            }

            return m;
        }

        static void Flip(Problem p, UInt64 flip)
        { 
            for(int i = 0; i < p.devices.Count; ++i)
            {
                p.devices[i] = p.devices[i] ^ flip;
            }
        }

        static int Count(UInt64 flip)
        {
            int n = 0;
            for (int i = 63; i != -1; --i)
            {
                UInt64 msk = (UInt64)1 << i;

                if ((flip & msk) >> i == 1)
                {
                    n += 1;
                }
            }

            return n;
        }

        static int Solve(Problem m)
        {
            int minFlip = int.MaxValue;

            UInt64 maxFlip = (UInt64)1 << m.nBits;
            for (UInt64 i = 0; i < maxFlip; ++i)
            {
                Flip(m, i);

                int currMatch = HowManyMatches(m);

                if (currMatch == m.devices.Count)
                {
                    int nF = Count(i);

                    if(nF < minFlip)
                    {
                        minFlip = nF;
                    }
                }

                Flip(m, i);

                //System.Console.WriteLine( UI64ToStr(i) );
            }

            return minFlip == int.MaxValue? -1 : minFlip;
        }

        static UInt64 StrTo64(string s)
        {
            UInt64 t = 0;
            UInt64 m = 1;

            for (int i = s.Length - 1; i >= 0; --i)
            {
                if (s[i] == '1')
                {
                    t += m;
                }

                m = m * 2;
            }

            return t;
        }

        static string UI64ToStr(UInt64 int64)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 63; i != -1; --i)
            {
                UInt64 msk = (UInt64)1 << i;

                if ((int64 & msk) >> i == 1)
                {
                    sb.Append("1");
                }
                else
                {
                    sb.Append("0");
                }
            }

            return sb.ToString();
        }

        static List<Problem> ReadProblems(string file)
        {
            List<Problem> problems = new List<Problem>();

            string[] lines = System.IO.File.ReadAllLines(file);

            int nProbs = int.Parse(lines[0]);
            for (int i = 1; i < lines.Length; ++i)
            {
                Problem problem = new Problem();

                string[] sViews = lines[i].Split(' ');
                problem.nBits = int.Parse(sViews[1]);
                
                ++i;
                

                sViews = lines[i].Split(' ');
                foreach (string sView in sViews)
                {
                    problem.slots.Add(StrTo64(sView));
                }

                ++i;

                sViews = lines[i].Split(' ');
                foreach (string sView in sViews)
                {
                    problem.devices.Add(StrTo64(sView));
                }

                problems.Add(problem);
            }

            // Trace.Assert (nProbs == problems.Count);

            return problems;
        }

        public static void Main(string[] args)
        {
            Trace.Listeners.Add(new ConsoleTraceListener());

            string filename = "../../A-small-attempt2.in";
            //string filename = "../../A-small-attempt0.in";
            //string filename = "../../C-small-practice.in";
            //string filename = "../../C-large-practice.in";

            List<Problem> problems = ReadProblems(filename);

            int i = 0;
            StringBuilder sb = new StringBuilder();
            foreach (var problem in problems)
            {
                int res = Solve(problem);

                //List<string> sRes = new List<string>();

                //foreach (var e in res)
                //{
                //    sRes.Add(UI64ToStr(e));
                //}

                string s = string.Format("Case #{0}: {1}", i + 1, res == -1 ? "NOT POSSIBLE" : res.ToString());

                Console.WriteLine(s);
                sb.Append(s);
                sb.Append("\n");

                System.IO.File.WriteAllText(filename.Replace(".in", ".temp"), sb.ToString());

                ++i;
            }

            System.IO.File.WriteAllText(filename.Replace(".in", ".out"), sb.ToString());
        }
    }
}
