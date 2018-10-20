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
            //Round1A.Perform("A_test.txt", "A_out_test.txt");
            Round1A.Perform("A-small-attempt0.in", "A_out_s0.txt");
            //Round1A.Perform("A-large.in", "A_out_large.txt");
        }
    }

    public class Round1A
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

        private static UInt64 CountBits(UInt64 n)
        {
            UInt64 c;
            for (c = 0; n != 0; c++)
                n &= n - 1;
            return c;
        }

        private static void Solve1Case(int caseNum, StreamReader r, StreamWriter w)
        {
            string[] nos = r.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            int N = Int32.Parse(nos[0]);
            int L = Int32.Parse(nos[1]);

            string[] nos2 = r.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            List<UInt64> outlets = new List<UInt64>();
            foreach (string item in nos2)
            {
                outlets.Add(Convert.ToUInt64(item, 2));
            }

            string[] nos3 = r.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            List<UInt64> devices = new List<UInt64>();
            foreach (string item in nos3)
            {
                devices.Add(Convert.ToUInt64(item, 2));
            }

            outlets.Sort();
            devices.Sort();
            double max = Math.Pow(2, L);
            UInt64 switchflipped = 0;
            bool possible = false;
            for (UInt64 i = 0; i < max; i++)
            {
                List<UInt64> copyoutlets = new List<UInt64>();
                foreach (UInt64 outl in outlets)
                {
                    UInt64 t = outl ^ i;
                    copyoutlets.Add(t);
                }
                if (copyoutlets.Intersect(devices).Count() == outlets.Count)
                {
                    possible = true;
                    switchflipped = CountBits(i);
                    break;
                }
            }
            if (possible)
            {
                w.WriteLine("Case #" + caseNum.ToString() + ": " + switchflipped);
            }
            else
            {
                w.WriteLine("Case #" + caseNum.ToString() + ": " + "NOT POSSIBLE");
            }
        }
    }
}
