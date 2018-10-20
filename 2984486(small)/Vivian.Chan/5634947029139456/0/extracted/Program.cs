using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace QuestionA
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("A-small-attempt2.in");
            StreamWriter sw = new StreamWriter("1.txt");
            int numberOfCases = int.Parse(sr.ReadLine());

            for (int caseNo = 1; caseNo <= numberOfCases; caseNo++)
            {
                string[] line1 = sr.ReadLine().Split(' ');
                int N = int.Parse(line1[0]);
                int L = int.Parse(line1[1]);

                string[] line2 = sr.ReadLine().Split(' ');

                var oris = new bool[N, L];
                for (int i = 0; i < line2.Length; i++)
                {
                    var ori = line2[i].Select(chr => chr.Equals('1')).ToArray();
                    for (int j = 0; j < ori.Length; j++)
                    {
                        oris[i, j] = ori[j];
                    }
                }


                string[] line3 = sr.ReadLine().Split(' ');
                var tgts = new bool[N, L];
                for (int i = 0; i < line3.Length; i++)
                {
                    var tgt = line3[i].Select(chr => chr.Equals('1')).ToArray();
                    for (int j = 0; j < tgt.Length; j++)
                    {
                        tgts[i, j] = tgt[j];
                    }
                }

                sw.WriteLine(string.Format("Case #{0}: {1}", caseNo, minF(N, L, oris, tgts)));
            }
            sw.Close();
            sr.Close();
        }

        public static string minF(int N, int L, bool[,] ori, bool[,] tgt)
        {
            var flips = new Flip[N, N];

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    bool[] o = new bool[L];
                    bool[] t = new bool[L];

                    for (int k = 0; k < L; k++)
                    {
                        o[k] = ori[i, k];
                        t[k] = tgt[j, k];
                    }
                    flips[i, j] = new Flip(o, t);
                }
            }

            var minFlip = int.MaxValue;
            string minFlips = string.Empty;
            bool[] ops  = new bool[L];
            for (int f = 0; f < N; f++)
            {
                var result = new Dictionary<int, int>();
                var flip = flips[0, f];
                result.Add(0, f);
                for (int r = 1; r < N; r++)
                {
                    for (int c = 0; c < N; c++)
                    {
                        if (flips[r, c].Equals(flip))
                        {
                            if (!result.ContainsKey(r))
                            {
                                result.Add(r, c);
                            }
                        }
                    }
                }

                if (result.Keys.Sum() == (N * (N - 1) / 2) && result.Values.Distinct().Sum() == (N * (N - 1) / 2))
                {
                    if (flip.nOp < minFlip) {
                        minFlips = flip.ToString();
                        ops = flip.Op;
                        minFlip = flip.nOp;
                    }
                        
                }
            }

            if (minFlip == int.MaxValue) return "NOT POSSIBLE";
            return minFlip.ToString();

        }

        public static bool Exact(bool[] ori, bool[] tgt)
        {
            for (int i = 0; i < tgt.Length; i++)
            {
                if (ori[i] != tgt[i]) return false;
            }
            return true;
        }

        public class Flip
        {
            public int nOp { get; set; }
            public bool[] T { get; set; }
            public bool[] O { get; set; }
            public bool[] Op { get; set; }
            public Flip(bool[] o, bool[] t)
            {
                T = t;
                O = o;
                Op = new bool[T.Length];
                DoFlip();
            }

            public void DoFlip()
            {
                for (int i = 0; i < T.Length; i++)
                {
                    if (T[i] != O[i])
                    {
                        nOp++;
                        Op[i] = true;
                    }
                    else
                    {
                        Op[i] = false;
                    }
                }
            }

            public bool Equals(Flip f)
            {
                if (f == null) return false;

                for (int i = 0; i < Op.Length; i++)
                {
                    if (f.Op[i] != this.Op[i]) return false;
                }
                return true;
            }

            public override string ToString()
            {
                string s = string.Empty;
                for (int i = 0; i < Op.Length; i++)
                {
                    if (Op[i])
                    {
                        s = s + "1";
                    }
                    else {
                        s = s + '0';    
                    }
                }
                return s;
            }
        }
    }
}
