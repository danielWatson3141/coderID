using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CodeJam
{

    class Solver
    {
        string solveCase(long[][] input)
        {
            long N = input[0][0];
            long[] outlets = input[1];
            long[] devices = input[2];

            long[] matches = new long[N];
            for (int i = 0; i < outlets.Length; i++)
            {
                long[] outletmatches = new long[N];
                long outlet = outlets[i];
                for (int j = 0; j < devices.Length; j++)
                {
                    long device = devices[j];
                    outletmatches[j] = outlet ^ device;
                }
                if (i == 0)
                    matches = outletmatches;
                else
                {
                    matches = matches.Intersect(outletmatches).ToArray();
                }
            }
            if (matches.Length == 0)
                return "NOT POSSIBLE";
            else
                return Convert.ToString(matches.Min(), 2).ToCharArray().Where(c => c == '1').Count() + "";

        }


        public string Solve(string input)
        {
            string[] lines = input.Trim().Split('\n').Select(l => l.TrimEnd('\r')).ToArray();

            StringBuilder sb = new StringBuilder();
            int nbCases = Convert.ToInt32(lines[0]);
            int iLine = 1;
            for (int i = 0; i < nbCases; i++)
            {
                //Console.WriteLine("Case: " + i);

                string[] lineParts = lines[iLine].Split(' ');
                long[] linePartsint = lineParts.Select(p => Convert.ToInt64(p)).ToArray();

                int caseLines = 2;//linePartsint[0];
                long[][] caseInput = new long[caseLines + 1][];
                caseInput[0] = linePartsint;

                for (var caseLine = 0; caseLine < caseLines; caseLine++)
                {
                    iLine++;
                    lineParts = lines[iLine].Split(' ');
                    linePartsint = lineParts.Select(p => Convert.ToInt64(p+"",2)).ToArray();
                    caseInput[caseLine + 1] = linePartsint;
                }
                string result = solveCase(caseInput);
                sb.AppendLine("Case #" + (i + 1) + ": " + result);
                iLine++;
            }
            return sb.ToString();
        }
    }

}

