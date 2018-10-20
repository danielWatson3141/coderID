using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;


namespace Round1A2014Prob1
{
    class Round1AProb1
    {

        public const string cInputFile = "C:\\Dev\\2014\\Round1A\\Prob1\\A-small-attempt0.in";
        public const string cOutputFile = "C:\\Dev\\2014\\Round1A\\Prob1\\out.txt";
        public const string cExampleAnswerFile = "C:\\Dev\\2014\\Round1A\\Prob1\\ea.txt";

        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter(cOutputFile))
            {
                using (StreamReader reader = new StreamReader(cInputFile))
                {
                    int numberOfTestCases = int.Parse(reader.ReadLine());

                    for (int testCaseNum = 0; testCaseNum < numberOfTestCases; testCaseNum++)
                    {
                        int[] parms1 = reader.ReadLine().Split(' ').Select(o => int.Parse(o)).ToArray();
                        string[] flow = reader.ReadLine().Split(' ');
                        string[] needed = reader.ReadLine().Split(' ');

                        int flips = GetMinNumOfFlips(parms1[0], parms1[1], flow, needed);

                        string val = "";
                        if (flips != -1)
                        {
                            val = flips.ToString();
                        }
                        else
                        {
                            val = "NOT POSSIBLE";
                        }

                        //Output testcase 
                        string outputLine = "Case #" + (testCaseNum + 1).ToString() + ": " + val;

                        Console.WriteLine(outputLine);
                        writer.WriteLine(outputLine);
                    }
                }
            }
            ///CompareResultWithExample();
        }

        public static int GetMinNumOfFlips(int pNumOutlets, int pSwitchSize, string[] pFlow, string[] pNeeded)
        {
            int flips = -1;

            ulong[] flowAsBase10 = pFlow.Select(o => Convert.ToUInt64(o, 2)).ToArray();
            ulong[] neededAsBase10 = pNeeded.Select(o => Convert.ToUInt64(o, 2)).ToArray();

            //Sort pNeeded
            Array.Sort(pNeeded);
            Array.Sort(neededAsBase10);

            bool equals = flowAsBase10.OrderBy(a => a).SequenceEqual(neededAsBase10.OrderBy(a => a));

            if (equals)
            {
                flips = 0;
            }
            else
            {
                List<ulong> possibleX0rs = new List<ulong>();
                foreach (ulong a in neededAsBase10)
                {
                    possibleX0rs.Add(a ^ flowAsBase10[0]);
                }
                possibleX0rs = possibleX0rs.Distinct().ToList();

                int curMin = -1;
                foreach (ulong a in possibleX0rs)
                {
                    int h = CountBits(a);

                    if (curMin == -1 || h < curMin)
                    {
                        //Check if flipping the bits gives us valid sequence
                        ulong[] flippedFlow = new ulong[pNumOutlets];
                        Array.Copy(flowAsBase10, flippedFlow, pNumOutlets);

                        for (int i = 0; i < pNumOutlets; i++)
                        {
                            flippedFlow[i] = a ^ flippedFlow[i];
                        }

                        Array.Sort(flippedFlow);
                        Array.Sort(neededAsBase10);
                        equals = flippedFlow.OrderBy(o => o).SequenceEqual(neededAsBase10.OrderBy(o => o));
                        if (equals && (curMin == -1 || h < curMin))
                        {
                            curMin = h;
                        }
                    }
                }

                if (curMin != -1)
                {
                    flips = curMin;
                }

                
            }

            return flips;
        }

        public static int CountBits(ulong pValue)
        {
            int count = 0;
            while (pValue != 0)
            {
                count++;
                pValue &= pValue - 1;
            }
            return count;
        }
    }
}
