using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ChargingChaos
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"D:\Google Code Jam\ChargingChaos\A-small-attempt1.in");
            int testCases = Int32.Parse(lines[0]);

            using (StreamWriter sw = new StreamWriter(@"D:\Google Code Jam\ChargingChaos\output.txt"))
            {
                for (int tIndex = 0; tIndex < testCases; tIndex++)
                {
                    string[] nl = lines[1 + tIndex * 3].Split(' ');
                    int n = Int32.Parse(nl[0]);
                    int l = Int32.Parse(nl[1]);
                    Int64[] initial = lines[2 + tIndex * 3].Split(' ').Select(i => Convert.ToInt64(i, 2)).ToArray();
                    Int64[] final = lines[3 + tIndex * 3].Split(' ').Select(i => Convert.ToInt64(i, 2)).ToArray();

                    Int64[] current = initial;

                    long bitEq = 0;
                    long limit = (1 << l) - 1;
                    int y = 0;
                    bool hasMatch = false;

                    while (!hasMatch)
                    {
                        for (int i = 0; i < l + 1; i++)
                        {
                            hasMatch = true;
                            for (int j = 0; j < n; j++)
                            {
                                if (!final.Contains(current[j]))
                                {
                                    hasMatch = false;
                                    break;
                                }
                            }

                            // flip the switch
                            if (!hasMatch)
                            {
                                bitEq++;
                                Int64[] newCurrent = new Int64[n];
                                for (int j = 0; j < n; j++)
                                {
                                    long switchBits = initial[j] & bitEq;
                                    long revSwitchBits = (~switchBits) & bitEq;
                                    long constBits = initial[j] & (~bitEq);
                                    newCurrent[j] = revSwitchBits | constBits;
                                }
                                current = newCurrent;
                                y++;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (bitEq > limit) break;
                    }

                    sw.WriteLine("Case #{0}: {1}", tIndex + 1, hasMatch ? Convert.ToString(bitEq, 2).Where(c => c == '1').Count().ToString() : "NOT POSSIBLE");
                }

                sw.Close();
            }
        }
    }
}
