using GoogleCodeJam;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam_Round1A_A
{
    class ProgramA
    {
        static void Main(string[] args)
        {
            using (CodeJamProblem problem = new CodeJamProblem('A', ProblemType.Small, 1))
            {
                int T = problem.ReadInt32();
                for (int cur = 0; cur < T; cur++)
                {
                    int linesPerCase = 3;
                    dynamic caseInputs = problem.ReadStringArrays(linesPerCase);

                    problem.OutputCase(RunCase(caseInputs).ToString());
                }
            }
        }

        private static object RunCase(string[][] caseInputs)
        {
            int N = int.Parse(caseInputs[0][0]);
            int L = int.Parse(caseInputs[0][1]);

            char[] bitmask = new char[L];
            for (int l = 0; l < L; l++)
            {
                int onesIn = 0;
                int onesOut = 0;
                for (int n = 0; n < N; n++)
                {
                    if (caseInputs[1][n][l] == '1')
                        onesIn++;
                    if (caseInputs[2][n][l] == '1')
                        onesOut++;
                }

                if (onesIn != onesOut && onesIn != N - onesOut)
                    return "NOT POSSIBLE";
                else if (onesIn == onesOut && onesIn == N - onesOut)
                    bitmask[l] = '2';
                else if (onesIn == onesOut)
                    bitmask[l] = '0';
                else if (onesIn == N - onesOut)
                    bitmask[l] = '1';
                else
                {
                }
            }

            List<string> possiblilities = new List<string>() {""};
            for (int l = 0; l < L; l++)
            {
                List<string> add = new List<string>();
                for (int p = 0; p < possiblilities.Count; p++)
                {
                    if (bitmask[l] != '2')
                        possiblilities[p] += bitmask[l];
                    else
                    {
                        string s = possiblilities[p] + "1";
                        possiblilities[p] += "0";
                        add.Add(s);
                    }
                }

                possiblilities.AddRange(add);
            }

            int c = int.MaxValue;
            for (int p = 0; p < possiblilities.Count; p++)
            {
                bool containsAll = true;
                for (int n = 0; n < N; n++)
                {
                    string flow = "";
                    for (int l = 0; l < L; l++)
                    {
                        if (possiblilities[p][l] == '0')
                            flow += caseInputs[2][n][l];
                        else
                            flow += (caseInputs[2][n][l] == '1') ? '0' : '1';
                    }

                    if (!caseInputs[1].Contains(flow))
                    {
                        containsAll = false;
                        break;
                    }
                }

                if (containsAll)
                {
                    int d = possiblilities[p].Count((char x) => (x == '1'));
                    if (d < c)
                        c = d;
                }
            }

            if (c == int.MaxValue)
                return "NOT POSSIBLE";

            return c;
        }
    }
}
