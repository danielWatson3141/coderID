using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    public class ProblemA
    {
        static String _fileDirectory = @"C:\Users\SAMSUNG\Desktop\codejam\ProblemA\";

        static void Main(string[] args)
        {
            //_fileDirectory = AppDomain.CurrentDomain.BaseDirectory;

            InputFile input = new InputFile(_fileDirectory + "a.in");
            OutputFile output = new OutputFile(_fileDirectory + "a.out");

            Int32 caseCount = input.ReadIntLine();

            for (int i = 0; i < caseCount; i++)
            {
                Int32[] arr = input.ReadIntArray();

                Int32 N = arr[0];
                Int32 L = arr[1];

                String[] flows = input.ReadStringArray();
                String[] required = input.ReadStringArray();

                Int32 flipRequired = 0;

                if (flows.Where(p => !required.Contains(p)).Count() != 0)
                {
                    Boolean isCompleted = false;
                    flipRequired = GenerateNew(flows, required, L, 0, out isCompleted);

                    if (isCompleted)
                    {
                        output.WriteCase(i + 1, flipRequired.ToString());
                    }
                    else
                    {
                        output.WriteCase(i + 1, "NOT POSSIBLE");
                    }
                }
                else
                {
                    output.WriteCase(i + 1, flipRequired.ToString());
                }
            }

            output.Close();
        }

        static Int32 GenerateNew(String[] flows, String[] required, Int32 length, Int32 currentIndex, out Boolean isCompleted)
        {
            Int32 minCount = Int32.MaxValue;
            isCompleted = false;

            if (currentIndex == length)
            {
                isCompleted = false;
                return 0;
            }

            for (int i = currentIndex; i < length; i++)
            {
                Int32 requiredFlips = 0;

                String[] newFlows = Replacer(flows, i);
                requiredFlips += 1;

                if (newFlows.Where(p => !required.Contains(p)).Count() == 0 && newFlows.Distinct().Count() == newFlows.Length)
                {
                    isCompleted = true;

                    if (minCount > requiredFlips)
                    {
                        minCount = requiredFlips;
                    }
                }
                else
                {
                    requiredFlips += GenerateNew(newFlows, required, length, i + 1, out isCompleted);

                    if (isCompleted)
                    {
                        if (minCount > requiredFlips)
                        {
                            minCount = requiredFlips;
                        }
                    }
                }
            }

            isCompleted = minCount != Int32.MaxValue;

            return minCount;
        }

        static String[] Replacer(String[] arr, Int32 index)
        {
            String[] newArr = new String[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                newArr[i] = arr[i].Substring(0, index) + (arr[i].Substring(index, 1) == "0" ? "1" : "0") + arr[i].Substring(index + 1);
            }
            return newArr;
        }

    }
}
