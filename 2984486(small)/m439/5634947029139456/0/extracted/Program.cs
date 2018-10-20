using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D
{
    class Program
    {
        static void Main(string[] args)
        {
            //            string fileName = "test";
            //string fileName = "input";
                string fileName = "A-small-attempt1";
            // string fileName = "A-large";

            string line;

            System.IO.StreamReader inFile =
               new System.IO.StreamReader(fileName + ".in");
            System.IO.StreamWriter outFile =
                new System.IO.StreamWriter(fileName + ".out");

            line = inFile.ReadLine();

            int testcases;
            bool success = int.TryParse(line, out testcases);

            for (int i = 0; i < testcases; i++)
            {
                solveSingleTestcase(inFile, outFile, i + 1);
            }

            inFile.Close();
            outFile.Close();

            Console.ReadLine();
        }

        private static void solveSingleTestcase(System.IO.StreamReader inFile, System.IO.StreamWriter outFile, int testcaseNumber)
        {
            string line = inFile.ReadLine();
            string[] tokensNL = line.Split();

            int N, L;
            int.TryParse(tokensNL[0], out N);
            int.TryParse(tokensNL[1], out L);

            char[,] outlets = new char[N, L];
            char[,] devices = new char[N, L];

            line = inFile.ReadLine();
            string[] tokensO = line.Split();

            line = inFile.ReadLine();
            string[] tokensD = line.Split();


            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < L; j++)
                {
                    outlets[i, j] = tokensO[i].ToCharArray(j, 1)[0];
                    devices[i, j] = tokensD[i].ToCharArray(j, 1)[0];
                }
            }

            Console.Write("Case #" + testcaseNumber + ": ");
            outFile.Write("Case #" + testcaseNumber + ": ");

/*            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < L; j++)
                {
                    Console.Write(outlets[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < L; j++)
                {
                    Console.Write(devices[i, j]);
                }
                Console.WriteLine();
            }
            */

            char[] switchState = new char[L];
            bool success = true;
            for (int j = 0; j < L; j++)
            {
                // count outlet 1s and device 1s
                int outlet1s = 0, device1s = 0;
                for (int i = 0; i < N; i++)
                {
                    if (outlets[i, j] == '1')
                    {
                        outlet1s++;
                    }
                    if (devices[i, j] == '1')
                    {
                        device1s++;
                    }
                }

                if (device1s == N - device1s)
                {
                    switchState[j] = 'b'; // both possible
                    continue; 
                }

                if (outlet1s == device1s)
                {
                    switchState[j] = 'n'; // don't switch
                    continue;
                }

                if (outlet1s == N - device1s)
                {
                    switchState[j] = 's'; // switch
                    continue;
                }

                success = false;
                break;
            }

            if (!success)
            {
                Console.WriteLine("NOT POSSIBLE");
                outFile.WriteLine("NOT POSSIBLE");
                return;
            }

            int switchFlips = 0;
            for (int j = 0; j < L; j++)
            {
                if (switchState[j] == 's')
                {
                    flipBit(outlets, j);
                    switchFlips++;
                }
            }
            
            Array.Sort(tokensD);

            int switchFlips2 = trySwitching(outlets, tokensD, switchState, 0, 0);

            if (switchFlips2 == -1)
            {
                Console.WriteLine("NOT POSSIBLE");
                outFile.WriteLine("NOT POSSIBLE");
                return;
            }
            else
            {
                Console.WriteLine(switchFlips + switchFlips2);
                outFile.WriteLine(switchFlips + switchFlips2);
            }
        }

        private static int trySwitching(char[,] outlets, string[] tokensD, char[] switchState, int bitPos, int switchCount)
        {
            int N = outlets.GetLength(0);
            int L = outlets.GetLength(1);

            if (bitPos == L)
            {
                // check result
                string[] outletStrings = new string[N];
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < L; j++)
                    {
                        outletStrings[i] += outlets[i, j];
                    }
                }

                Array.Sort(outletStrings);

                for (int i = 0; i < N; i++)
                {
                    if (outletStrings[i] != tokensD[i])
                    {
                        return -1;
                    }
                }

                return switchCount;
            }

            if (switchState[bitPos] == 'n' || switchState[bitPos] == 's')
            {
                return trySwitching(outlets, tokensD, switchState, bitPos + 1, switchCount);
            }
            else // if(switchState[bitPos] == 'b') 
            {
                int noSwitch = trySwitching(outlets, tokensD, switchState, bitPos + 1, switchCount); // don't switch

                char[,] outletClone = (char[,]) outlets.Clone();
                flipBit(outletClone, bitPos);
                int yesSwitch = trySwitching(outletClone, tokensD, switchState, bitPos + 1, switchCount + 1); // switch

                if (yesSwitch == -1)
                {
                    return noSwitch;
                }
                else if (noSwitch == -1)
                {
                    return yesSwitch;
                }
                else if (noSwitch < yesSwitch)
                {
                    return noSwitch;
                }
                else // if (yesSwitch <= noSwitch)
                {
                    return yesSwitch;
                }
            }
        }

        private static void flipBit(char[,] outlets, int j)
        {
            for (int i = 0; i < outlets.GetLength(0); i++)
            {
                if (outlets[i, j] == '0')
                {
                    outlets[i, j] = '1';
                }
                else
                {
                    outlets[i, j] = '0';
                }
            }
        }
    }
}