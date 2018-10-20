using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChargingChaos
{
    class Program
    {
        const string filename = "A-small-attempt1.in";
        const int linesPerCase = 3;
        const int linesForCaseNumber = 1;

        const string notPossible = "NOT POSSIBLE";

        static void Main(string[] args)
        {
            var allLines = File.ReadAllLines(filename);
            int T_cases = int.Parse(allLines.First());

            Debug.Assert(T_cases >= 1, "Input cases not correct");

            for (int currentCase = 1; currentCase <= T_cases; currentCase++)
            {
                string resultForCase = SolveChargingChaosProblemForLines(allLines.Skip(linesForCaseNumber + ((currentCase - 1) * linesPerCase)).Take(linesPerCase).ToArray());

                Console.WriteLine("Case #{0}: {1}", currentCase, resultForCase);
            }
        }

        private static string SolveChargingChaosProblemForLines(string[] problemLines)
        {
            string[] splitProblemFirstLine = problemLines[0].Split(' ');
            int N_devices = int.Parse(splitProblemFirstLine[0]);
            int L_switches = int.Parse(splitProblemFirstLine[1]);

            string[] splitInitialFlow = problemLines[1].Split(' ');
            string[] splitRequiredFlow = problemLines[2].Split(' ');

            Debug.Assert(splitRequiredFlow.Length == N_devices);
            Debug.Assert(splitInitialFlow.Length == N_devices);
            Debug.Assert(splitRequiredFlow.Distinct().Count() == splitRequiredFlow.Length);
            Debug.Assert(splitInitialFlow.Distinct().Count() == splitInitialFlow.Length);

            var initialFlow = splitInitialFlow.Select(eachFlow => new BinaryNumber(eachFlow)).ToList();
            var requiredFlow = splitRequiredFlow.Select(eachFlow => new BinaryNumber(eachFlow)).OrderBy(eachFlow => eachFlow.NumFlow).ToList();

            var allPossibleSolutions = FindMatchingCombination(initialFlow, requiredFlow, L_switches);

            if (allPossibleSolutions.Any())
            {
                long bestSolution = ChooseBestSolution(allPossibleSolutions);
                return string.Format("{0}", bestSolution);
            }

            return notPossible;
        }

        private static long ChooseBestSolution(List<int> allPossibleSolutions)
        {
            return allPossibleSolutions.Select(eachSolution => new { sol = eachSolution, bitsOne = BitCount(eachSolution) }).OrderBy(eachItem => eachItem.bitsOne).First().bitsOne;
        }

        private static long BitCount(long x)
        {
            x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
            x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
            x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
            x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
            x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));

            return x;
        }

        private static List<int> FindMatchingCombination(List<BinaryNumber> initialFlow, List<BinaryNumber> requiredFlow, int L_switches)
        {
            int possibleCombinations = (int)Math.Pow(2, L_switches);
            List<int> possibleSolutions = new List<int>();

            for (int i = 0; i < possibleCombinations; i++)
            {
                List<BinaryNumber> temporaryCopy = initialFlow.Select(eachFlow => eachFlow.FlipSwitches(i)).OrderBy(eachFlow => eachFlow.NumFlow).ToList();

                if (Enumerable.SequenceEqual(temporaryCopy, requiredFlow))
                {
                    possibleSolutions.Add(i);
                }
            }

            return possibleSolutions;
        }

        class BinaryNumber
        {
            private string strFlow;

            public BinaryNumber(string strFlow)
            {
                this.strFlow = strFlow;
                this.NumFlow = Convert.ToInt32(strFlow, 2);
            }

            public BinaryNumber(int numFlow)
            {
                this.NumFlow = numFlow;
            }

            public int NumFlow { get; private set; }

            public override int GetHashCode()
            {
                return NumFlow;
            }

            public override bool Equals(object obj)
            {
                return (obj is BinaryNumber)
                    && (obj as BinaryNumber).NumFlow == this.NumFlow;
            }

            internal BinaryNumber FlipSwitches(int i)
            {
                return new BinaryNumber(this.NumFlow ^ i);
            }
        }
    }
}
