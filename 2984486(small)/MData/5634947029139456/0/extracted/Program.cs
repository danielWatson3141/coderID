using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJamRound1AQuestionA
{
    class Program
    {
        static void Main(string[] args)
        {
            List<FarmHouse> farmhouseList = new List<FarmHouse>();

            List<string> inputLines = File.ReadAllLines("input.txt").ToList();
            int currentLine = 2;

            int caseCount = 1;

            List<string> output = new List<string>();

            while (true)
            {
                FarmHouse house = new FarmHouse();
                house.currentOutputs = inputLines[currentLine].Split(' ').Select(x => x.ToString()).ToList();
                currentLine++;
                house.requiredOutputs = inputLines[currentLine].Split(' ').Select(x => x.ToString()).ToList();
                farmhouseList.Add(house);

                int? solvedAnswer = house.Solve();
                string answer = string.Format("Case #{0}: {1}", caseCount, solvedAnswer.HasValue ? solvedAnswer.Value.ToString() : "NOT POSSIBLE");
                Console.WriteLine(answer);
                caseCount++;

                output.Add(answer);

                currentLine += 2;
                if (currentLine > inputLines.Count)
                    break;
            }

            File.WriteAllLines("output.txt", output);
        }

        class FarmHouse
        {
            public List<string> currentOutputs { get; set; }
            public List<string> requiredOutputs { get; set; }

            public int? Solve()
            {
                List<RecursiveResult> results = new List<RecursiveResult>();
                List<string> inputItems = new List<string>();
                currentOutputs.ForEach(x => inputItems.Add(""));

                flipAll(results, currentOutputs, inputItems, 0);

                int lowestValue = int.MaxValue;

                foreach (RecursiveResult result in results)
                {
                    if (IsSolved(result.items, requiredOutputs))
                    {
                        if (result.flipCount < lowestValue)
                        {
                            lowestValue = result.flipCount;
                        }
                    }
                        
                }
                if (lowestValue != int.MaxValue)
                    return lowestValue;
                else
                    return null;
            }

            private bool IsSolved(List<string> current, List<string> required)
            {
                foreach (string currentItem in current)
                {
                    if (required.Contains(currentItem) == false)
                        return false;
                }
                return true;
            }

            private void flipAll(List<RecursiveResult> returnItems, List<string> startItems , List<string> currentItems, int flipCount)
            {
                if(currentItems[0].Length == startItems[0].Length)
                {
                    RecursiveResult result = new RecursiveResult();
                    result.items = currentItems;
                    result.flipCount = flipCount;
                    returnItems.Add(result);
                    return;
                }

                

                //First does not flip at all. 
                int currentPosition = currentItems[0].Length;
                List<string> freshList = currentItems.ToList();
                for (int i = 0; i < currentItems.Count; i++)
                {
                    freshList[i] += startItems[i][currentPosition];
                }
                flipAll(returnItems, startItems, freshList, flipCount);

                List<string> freshList2 = currentItems.ToList();
                for (int i = 0; i < currentItems.Count; i++)
                {
                    freshList2[i] += startItems[i][currentPosition] == '0' ? "1" : "0";
                }
                flipAll(returnItems, startItems, freshList2, flipCount + 1);
                
            }
        }

        class RecursiveResult
        {
            public List<string> items {get;set;}
            public int flipCount {get;set;}
        }
    }
}
