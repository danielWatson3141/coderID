using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA.ChargingChaos
{
    class Program
    {
        class Case
        {
            public int CaseNumber { get; set; }
            public int N { get; set; }
            public int L { get; set; }
            public IEnumerable<string> Initial { get; set; }
            public IEnumerable<string> Expected { get; set; }
        }

        static void Main(string[] args)
	    {
            const string fileName = "A-small-attempt0";

            var input = File.ReadAllLines("../../" + fileName + ".in");
            var cases = new List<Case>();

            // read input
            int testCasesCount = int.Parse(input[0]);

            for (int i = 0; i < testCasesCount; ++i)
            {
                var c = new Case();
                c.CaseNumber = i+1;
                string[] line = input[1 + i * 3].Split();
                c.N = int.Parse(line[0]);
                c.L = int.Parse(line[1]);

                c.Initial = input[2 + i * 3].Split().ToList();
                c.Expected = input[3 + i * 3].Split().ToList();
                cases.Add(c);
            }

            // process cases

            var output = new List<string>();

            foreach (var c in cases)
            {
                int maxSwitches = (int)Math.Pow(2, c.Initial.FirstOrDefault().Length);

                int minSwitches = c.Initial.FirstOrDefault().Length + 1;

                for (int i = 0; i < maxSwitches; ++i)
                {
                    var temp = c.Initial.ToList();

                    // get switch indexes
                    string bin = Convert.ToString(i, 2); //Convert to binary in a string
                    int[] bits = bin.PadLeft(c.L, '0') // Add 0's from left
                                 .Select(x => int.Parse(x.ToString())) // convert each char to int
                                 .ToArray(); // Convert IEnumerable from select to Array

                    // switch
                    for (var x=0; x < temp.Count; ++x )
                    {
                        for (int j = 0; j < c.L; ++j)
                        {
                            if (bits[j] == 1)
                            {
                                var sb = new StringBuilder(temp[x]);
                                sb[j] = temp[x][j].CompareTo('0') == 0 ? '1' : '0';
                                temp[x] = sb.ToString();
                            }
                        }
                    }

                    // check if all fits
                    var success = true;
                    foreach (var s in c.Expected)
                    {
                        var result = temp.Remove(s);
                        if (result == false)
                        {
                            success = false;
                            break;
                        }
                    }

                    if (success == true)
                    {
                        var currentSwitches = bits.Where(x => x == 1).Count();
                        minSwitches = currentSwitches < minSwitches ? currentSwitches : minSwitches;
                    }
                }

                if (minSwitches <= c.Initial.FirstOrDefault().Length)
                {
                    output.Add("Case #" + c.CaseNumber + ": " + minSwitches);
                }
                else
                {
                    output.Add("Case #" + c.CaseNumber + ": NOT POSSIBLE");
                }
            }

            File.WriteAllLines("../../" + fileName + ".out", output);
	    }
    }

}
