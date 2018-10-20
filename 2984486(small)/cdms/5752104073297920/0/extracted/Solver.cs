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
    
        string solveCase(int[][] input)
        {
            var numbers = input[1];
            int res = 0;
            for (int i = 1; i < numbers.Length; i++)
            {
                var n = numbers[i];
                var before = numbers.Take(i);
                int greater = before.Where(n1 => n1 > n).Count();
                res += greater;
                res -= before.Count() - greater;
            }
            return res>0?"GOOD":"BAD";
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
                int[] linePartsint = lineParts.Select(p => Convert.ToInt32(p)).ToArray();

                int caseLines = 1;
                int[][] caseInput = new int[caseLines + 1][];
                caseInput[0] = linePartsint;

                for (var caseLine = 0; caseLine < caseLines; caseLine++)
                {
                    iLine++;
                    lineParts = lines[iLine].Split(' ');
                    linePartsint = lineParts.Select(p => Convert.ToInt32(p)).ToArray();
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

