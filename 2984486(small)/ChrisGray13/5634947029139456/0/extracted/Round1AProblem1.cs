using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Round1AProblem1
    {
        const string _responseFormat = "Case #{0}: {1}";
        const string _googleCheated = "Google cheated!";
        const string _notPossible = "NOT POSSIBLE";

        static void Main(string[] args)
        {
            int numOfTests = 0;
            string currentInputLine;
            int numOfOutlets, lengthOfOutlet;
            string[] values;
            int[] outletValues, deviceValues;
            int[] newOutletValues;
            int perm, minPermValue;

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
                                    values = currentInputLine.Split(' ');
                                    numOfOutlets = Convert.ToInt32(values[0]);
                                    lengthOfOutlet = Convert.ToInt32(values[1]);

                                    currentInputLine = sr.ReadLine();
                                    if (currentInputLine == null)
                                    {
                                        sw.WriteLine(_googleCheated);
                                    }
                                    else
                                    {
                                        outletValues = Array.ConvertAll<string, int>(currentInputLine.Split(' '), v => Convert.ToInt32(v, 2));

                                        currentInputLine = sr.ReadLine();
                                        if (currentInputLine == null)
                                        {
                                            sw.WriteLine(_googleCheated);
                                        }
                                        else
                                        {
                                            deviceValues = Array.ConvertAll<string, int>(currentInputLine.Split(' '), v => Convert.ToInt32(v, 2));
                                            Array.Sort<int>(deviceValues);

                                            newOutletValues = new int[outletValues.Length];
                                            minPermValue = lengthOfOutlet + 1;

                                            for (int j = 0, perms = (int)Math.Pow(2, lengthOfOutlet); j < perms; j++)
                                            {
                                                perm = j;

                                                for (int k = 0; k < outletValues.Length; k++)
                                                {
                                                    newOutletValues[k] = outletValues[k] ^ j;
                                                }

                                                Array.Sort<int>(newOutletValues);

                                                for (int l = 0; l < outletValues.Length; l++)
                                                {
                                                    if (newOutletValues[l] != deviceValues[l])
                                                    {
                                                        perm = -1;
                                                        break;
                                                    }
                                                }

                                                if (perm == j)
                                                {
                                                    if (Convert.ToString(perm, 2).Count<char>(c => c == '1') < minPermValue)
                                                    {
                                                        minPermValue = Convert.ToString(perm, 2).Count<char>(c => c == '1');
                                                    }
                                                }
                                            }

                                            sw.WriteLine(String.Format(_responseFormat, i, (minPermValue == lengthOfOutlet + 1) ? _notPossible : minPermValue.ToString()));
                                        }
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
