using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeWarrior5
{
    class AChargingChaos
    {
        public static void Main()
        {
            Solve();
        }
        public static void Solve()
        {
            string filename = @"C:\CodeTest\A-small-attempt0";
            InputFile input = new InputFile(filename);
            OutputFile output = new OutputFile(filename);

            int noTestCases = input.readNextLineInt();
            for (int tcCount = 0; tcCount < noTestCases; tcCount++)
            {
                int[] firstLine = input.readNextLineIntArr();
                int N = firstLine[0];
                int L = firstLine[1];
                string[] switchArray = input.readNextLineStringArr();
                string[] devArray = input.readNextLineStringArr();

                Array.Sort(devArray);

                int count;
                string minFlipString = null;
                int minFlipCount = L + 1;
                bool flipCheck = false;

                for (count = 0; count < switchArray.Length; count++)
                {
                    string flipString = Xor(devArray[count], switchArray[0]);
                    int flipCount = countFlip(devArray[count], switchArray[0]);
                    if(flipCount < minFlipCount)
                    {
                        flipCheck = FlipAndCheck(Xor(devArray[count], switchArray[0]), (string[]) switchArray.Clone(), devArray);
                        if (flipCheck)
                        {
                            minFlipString = flipString;
                            minFlipCount = flipCount;
                        }
                    }
                }
                if (minFlipCount == (L + 1))
                {
                    output.WriteNextTestResult("NOT POSSIBLE");
                }
                else
                {
                    output.WriteNextTestResult("" + minFlipCount);
                }

            }

            input.Close();
            output.Close();
        }

        private static bool FlipAndCheck(string flip, string[] switchArr, string[] devArr)
        {
            for (int i = 0; i < switchArr.Length; i++)
            {
                switchArr[i] = Xor(flip, switchArr[i]);
            }
            Array.Sort(switchArr);
            
            int count;
            for(count =0; count < switchArr.Length; count++)
            {
                if(devArr[count] != switchArr[count])
                    break;
            }
            if(count == switchArr.Length)
                return true;
            return false;
        }

        private static int countFlip(string x, string y)
        {
            int count = 0;
            for (int i = 0; i < x.Length; i++)
            {
                if (x[i] != y[i])
                {
                    count++;
                }
            }
            return count;
        }

        private static string Xor(string x, string y)
        {
            char[] output = new char[x.Length];
            for (int i = 0; i < x.Length; i++)
            {
                if (x[i] == y[i])
                {
                    output[i] = '1';
                }
                else
                {
                    output[i] = '0';
                }
            }
            return new string(output);
        }
    }
}
