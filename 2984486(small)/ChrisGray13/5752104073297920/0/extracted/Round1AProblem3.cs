using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Round1AProblem3
    {
        const string _responseFormat = "Case #{0}: {1}";
        const string _googleCheated = "Google cheated!";
        const string _good = "GOOD";
        const string _bad = "BAD";

        static void Main(string[] args)
        {
            int numOfTests = 0;
            string currentInputLine;
            int[] permutations;
            int permLength, higherValues, lowerValues;


            using (StreamWriter sw = new StreamWriter("Output.txt", false))
            {
                if ((args.Length == 1) && File.Exists(args[0]))
                {
                    using (StreamReader sr = new StreamReader(args[0]))
                    {
                        currentInputLine = sr.ReadLine();
                        if (currentInputLine == null)
                        {
                            sw.WriteLine(_googleCheated);
                        }
                        else
                        {
                            numOfTests = Convert.ToInt32(currentInputLine);
                            for (int i = 1; i <= numOfTests; i++)
                            {
                                currentInputLine = sr.ReadLine();
                                if (currentInputLine == null)
                                {
                                    sw.WriteLine(_googleCheated);
                                }
                                else
                                {
                                    permLength = Convert.ToInt32(currentInputLine);

                                    currentInputLine = sr.ReadLine();
                                    if (currentInputLine == null)
                                    {
                                        sw.WriteLine(_googleCheated);
                                    }
                                    else
                                    {
                                        permutations = Array.ConvertAll<string, int>(currentInputLine.Split(' '), v => Convert.ToInt32(v));
                                        higherValues = lowerValues = 0;

                                        for (int j = 0, k = permutations.Length - 1, length = (permutations.Length / 2); j <= length; j++, k--)
                                        {
                                            if (permutations[j] > permutations[j + 1])
                                            {
                                                higherValues++;
                                            }

                                            if (permutations[k] < permutations[k - 1])
                                            {
                                                lowerValues++;
                                            }
                                        }

                                        sw.WriteLine(String.Format(_responseFormat, i, ((higherValues + lowerValues) > (permutations.Length / 2)) ? _good : _bad));
                                    }
                                }
                            }
                        }
                    }
                }

                sw.Flush();
            }
        }
    }
}
