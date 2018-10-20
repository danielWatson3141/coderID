using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> inputs = ReadFile("A-small-attempt0.in");

            int numOfTests = Int32.Parse(inputs[0]);
            int i = 1;
            int testNo = 1;
            List<string> outputs = new List<string>();
            while (i < inputs.Count-1)
            { 
                string[] NL = inputs[i++].Split(' ');
                testcase tc = new testcase()
                {
                    N = Int32.Parse(NL[0]),
                    L = Int32.Parse(NL[1]),
                    inputs = inputs[i++].Split(' '),
                    targets = inputs[i++].Split(' '),
                };
                int result = MagicFunction(tc);
                switch (result)
                { 
                    case -1:
                        outputs.Add(String.Format("Case #{0}: NOT POSSIBLE", testNo));
                        break;
                    default:
                        outputs.Add(String.Format("Case #{0}: {1}", testNo, result));
                        break;
                }
                testNo++;
            }            

            WriteToFile(outputs);
        }

        static int MagicFunction(testcase tc)
        {
            int result = Int32.MaxValue;

            Array.Sort(tc.inputs);
            Array.Sort(tc.targets);

            if (isMatch(tc.inputs, tc.targets))
            {
                return 0;
            }

            int flips = (int)Math.Pow(2, tc.L);
            for (int i = 0; i < flips; i++)
            {
                int f = Flip(i, tc.inputs, tc.targets);
                if (f >= 0)
                {
                    result = Math.Min(result, f);
                }
            }

            return result != Int32.MaxValue ? result : -1;
        }

        static int Flip(int num, string[] A, string[] B)
        {
            string[] AA = (string[])A.Clone();
            int p = 0;
            int count = 0;
            while (num >= 0)
            {
                if (num % 2 == 1)
                { 
                    for(int i=0; i<AA.Length; i++)
                    {
                        char c = AA[i][p] == '0' ? '1' : '0';
                        char[] c_arr = AA[i].ToCharArray();
                        c_arr[p] = c;
                        AA[i] = new string(c_arr);
                    }
                    count++;
                }
                if (num == 0)
                {
                    break;
                }
                num /= 2;
                p++;
            }
            Array.Sort(AA);
            if (isMatch(AA, B))
            {
                return count;
            }
            else
            {
                return -1;
            }
        }

        static bool isMatch(string[] A, string[] B)
        {
            for (int i = 0; i < A.Length; i++)
            {
                if (!String.Equals(A[i], B[i]))
                {
                    return false;
                }
            }
            return true;
        }

        static List<string> ReadFile(string path)
        {
            return File.ReadAllLines(path).ToList();
        }

        static void WriteToFile(List<string> lines)
        {
            string path = "output.txt";
            File.WriteAllLines(path, lines);
        }
    }

    internal class testcase
    {
        public int N;
        public int L;
        public string[] inputs;
        public string[] targets;
    }
}
