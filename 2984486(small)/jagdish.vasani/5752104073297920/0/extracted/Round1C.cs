using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace QualificationRound
{
    public class BaseClass
    {
        [STAThread]
        public static void Main(string[] args)
        {
            //Round1C.Perform("C_test.txt", "C_test_out.txt");
            Round1C.Perform("C-small-attempt0.in", "C_out_s0.txt");
            //Round1C.Perform("C-large.in", "C_out_large.txt");
        }
    }

    public class Round1C
    {
        internal static void Perform(string ipFile, string opFile)
        {
            StreamReader r = new StreamReader(ipFile);
            StreamWriter w = new StreamWriter(opFile);
            int cases = Int32.Parse(r.ReadLine().Trim());
            for (int i = 1; i <= cases; i++)
            {
                Solve1Case(i, r, w);
            }

            r.Close();
            w.Close();
        }

        private static void Solve1Case(int caseNum, StreamReader r, StreamWriter w)
        {
            int total = Int32.Parse(r.ReadLine());
            string[] nos = r.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            bool good = true;
            for (int i = 0; i < nos.Length; i++)
            {
                if (Int32.Parse(nos[i]) == i)
                {
                    good = false;
                    break;
                }
            }


            if (good)
            {
                w.WriteLine("Case #" + caseNum.ToString() + ": " + "GOOD");
            }
            else
            {
                w.WriteLine("Case #" + caseNum.ToString() + ": " + "BAD");
            }
        }
    }
}
