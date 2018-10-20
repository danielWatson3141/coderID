using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    public class Switches
    {
        public static IEnumerable<string> Combinations;
        public static void Start()
        {
            var input = new Input("SwitchTestSmall");


            int startIndexOfCases = 0;
            int linesPerCase = 3;

            int cases = int.Parse(input.Lines[startIndexOfCases]);
            int currentLine = startIndexOfCases;
            var testCases = new List<TestCase>();

            List<string> outputLines = new List<string>();
            for (int caseCount = 1; caseCount <= cases; caseCount++)
            {
                TestCase testCase = new TestCase()
                {
                    Layout = input.Lines[currentLine + 1].Split(' ').ToList(),
                    InitialOutlet = input.Lines[currentLine + 2].Split(' ').ToList(),
                    RequiredOutlet = input.Lines[currentLine + 3].Split(' ').ToList(),
                };

                GetAllCombinations(int.Parse(testCase.Layout[1]));
                var house = new House(testCase);

                string output = string.Format("Case #{0}: {1}", caseCount, house.Output);
                Console.WriteLine(output);
                outputLines.Add(output);

                currentLine += linesPerCase;
            }

            File.WriteAllLines(@"C:\TestFolder\Output.txt", outputLines);
            Console.ReadLine();

        }

        private static void GetAllCombinations(int length)
        {
            List<string> list = new List<string>();
            for (int x = 0; x <= length; x++)
            {
                foreach (var s in BinStrings(length, x))
                {
                    list.Add(s);
                }
            }

            Switches.Combinations = list;
        }

        private static IEnumerable<string> BinStrings(int length, int bits)
        {
            if (length == 1)
            {
                yield return bits.ToString();
            }
            else
            {
                if (length > bits)
                {
                    foreach (string s in BinStrings(length - 1, bits))
                    {
                        yield return "0" + s;
                    }
                }
                if (bits > 0)
                {
                    foreach (string s in BinStrings(length - 1, bits - 1))
                    {
                        yield return "1" + s;
                    }
                }
            }
        }

        public class TestCase
        {
            public List<string> Layout { get; set; }
            public List<string> InitialOutlet { get; set; }
            public List<string> RequiredOutlet { get; set; }
        }

        public class House
        {
            public string Output { get; set; }
            public House(TestCase testCase)
            {
                int devices = int.Parse(testCase.Layout[0]);
                int length = int.Parse(testCase.Layout[1]);

                this.VerifyOutlets(testCase, length);

                if (!string.IsNullOrEmpty(Output))
                {
                    return;
                }

                int flipCount = 0;

                IList<string> initialOutlet = testCase.InitialOutlet;
                bool matched = false;

                matched = this.Match(initialOutlet, testCase.RequiredOutlet);
                if (matched)
                {
                    Output = flipCount.ToString();
                    return;
                }

                while(length!=flipCount)
                {
                    IEnumerable<string> combinations = this.GetSpecificCombination(flipCount);

                    foreach(var combination in combinations)
                    {
                        var testOutlet = this.FlipAll(flipCount, initialOutlet, combination);

                        matched = this.Match(testOutlet, testCase.RequiredOutlet);
                        if (matched)
                        {
                            Output = flipCount.ToString();
                            return;
                        }
                    }

                    flipCount++;
                }

                this.Output = "NOT POSSIBLE";
            }

            private void VerifyOutlets(TestCase testCase, int length)
            {
                foreach (var outlet in testCase.InitialOutlet)
                {
                    if (length != outlet.Length)
                    {
                        this.Output = "NOT POSSIBLE";
                    }
                }

                foreach (var outlet in testCase.RequiredOutlet)
                {
                    if (length != outlet.Length)
                    {
                        this.Output = "NOT POSSIBLE";
                    }
                }
            }

            private bool Match(IList<string> initialOutlets, IList<string> requiredOutlets)
            {
                int requiredMatches = initialOutlets.Count;
                foreach(var initial in initialOutlets)
                {
                    foreach(var required in requiredOutlets)
                    {
                        if (initial == required)
                        {
                            requiredMatches--;
                        }
                    }
                }

                if (requiredMatches == 0)
                {
                    return true;
                }

                return false;
            }
                       

            private IEnumerable<string> GetSpecificCombination(int flips)
            {
                var list = new List<string>();
                foreach(string combination in Switches.Combinations)
                {
                    if(flips == combination.Count(x => x == '1'))
                    {
                        list.Add(combination);
                    }
                }

                return list;
            }

            private IList<string> FlipAll(int flipCount, IList<string> initialOutlets, string combination)
            {
                List<string> list = new List<string>();
                list.AddRange(initialOutlets);
                for(int x = 0; x <= combination.Length -1; x++)
                {
                    if (combination[x] == '1')
                    {
                        this.Flip(x, ref list);
                    }
                }

                return list;
            }

            private void Flip(int position, ref List<string> initialOutlets)
            {
                for (int x = 0; x < initialOutlets.Count; x++)
                {
                    string initial = initialOutlets[x];

                    StringBuilder sb = new StringBuilder(initial);

                    char newChar;
                    if (sb[position] == '0')
                    {
                        newChar = '1';
                    }
                    else
                    {
                        newChar = '0';
                    }
                    sb[position] = newChar;
                    initialOutlets[x] = sb.ToString();
                }
            }

        }
    }
}
