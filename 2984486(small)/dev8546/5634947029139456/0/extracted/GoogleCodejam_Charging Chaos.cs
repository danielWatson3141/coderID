using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SPOJSolutions
{
    class GoogleCodejam_Charging_Chaos
    {
        static int totalGChange = Int32.MaxValue;
        static void DP(string[] strN, string[] strL, int counter , int totalChange , bool[] flipped)
        {
            if (counter == strL[0].Length)
            {
                bool result = isOK(strL, strN, flipped, strL[0].Length);
                if (result)
                    totalGChange = Math.Min(totalGChange, totalChange);
                return;
            }
            //do not change the bit and compare 
            flipped[counter] = false;
            DP(strN, strL, counter + 1, totalChange,flipped);
            flipped[counter] = true;
            DP(strN, strL, counter + 1, totalChange + 1, flipped);
            
        }

        static bool isOK(string[] strN, string[] strL, bool[] flippedBits , int L)
        {
            int totalMatch = 0;
            for (int i = 0; i < strN.Length; i++)
            {
                bool matched = false;
                for (int j = 0; j < strL.Length; j++)
                {
                    bool complete = true;
                    for (int k = 0; k < L; k++)
                    {
                        char bit = flippedBits[k] ? strL[j][k] == '1' ? '0' : '1' : strL[j][k];
                        if (strN[i][k] != bit)
                        {
                            complete = false;
                            break;
                        }
                    }
                    if (complete)
                    {
                        matched = true;
                        break;
                    }
                }
                if (matched)
                    totalMatch++;
                else
                    break;
            }
            if (totalMatch != strN.Length)
                return false;
            return true;
        }
        static void Main()
        {

            using (StreamReader reader = new StreamReader("input.txt"))
            {

                int t = int.Parse(reader.ReadLine());
                int testCaseNumber = 1;
                using (StreamWriter sw = new StreamWriter("output.txt"))
                {
                    while (t > 0)
                    {
                        string[] str = reader.ReadLine().Split();
                        int N = int.Parse(str[0]);
                        int L = int.Parse(str[1]);
                        string[] strN = reader.ReadLine().Trim().Split();
                        string[] strL = reader.ReadLine().Trim().Split();
                        StringBuilder sb = new StringBuilder();
                        sb.AppendFormat("Case #{0}:", testCaseNumber);
                        bool[] flipped = new bool[L];
                        totalGChange = Int32.MaxValue;
                        DP(strN, strL, 0, 0, flipped);
                        if (totalGChange != Int32.MaxValue)
                            sb.AppendFormat(" {0}", string.Format("{0}", totalGChange));
                        else
                            sb.AppendFormat(" {0}", "NOT POSSIBLE");
                        sw.WriteLine(sb.ToString());
                        t--;
                        testCaseNumber++;
                    }
                }

            }
        }
    }
}
