using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Reading input file...");
            StreamReader streamReader = new StreamReader(@"D:\Work\Programming Challange\CodeJam 2014\Round 1\Problem C\inputSmall.txt");
            StreamWriter streamWriter = new StreamWriter(@"D:\Work\Programming Challange\CodeJam 2014\Round 1\Problem C\outputSmall.txt", false);
            
            string line = streamReader.ReadLine();
            int nrOfTests = 0;
            if(!int.TryParse(line, out nrOfTests))
            {
                Console.WriteLine("Number of tests is not an int!");
                return;
            }

            List<List<int>> goodAttempts = null;
            List<List<int>> badAttempts = null;
            
            Console.WriteLine("Number of tests: "+nrOfTests.ToString());
            for(int i=0; i<nrOfTests;i++)
            {
                int caseNR = i+1;
                Console.WriteLine("Case #"+caseNR.ToString()+": reading input");
                //read the input
                string input = streamReader.ReadLine();
                int numbers = int.Parse(input);
                if (goodAttempts == null)
                {
                    goodAttempts = GenerateAttempts(numbers, true);
                    badAttempts = GenerateAttempts(numbers, false);
                }

                input = streamReader.ReadLine();
                string[] split = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                List<int> currentPerm = split.Select<string, int>(text => int.Parse(text)).ToList();

                //process it
                Console.WriteLine("Case #" + caseNR.ToString() + ": processing input");
                int minDistance = int.MaxValue;
                bool resultGood = true;
                int countGood = 0, countBad = 0;
                List<int> distancesGood = new List<int>();
                List<int> distancesBad = new List<int>();


                for (int z = 0; z < numbers; z++)
                {
                    int distanceGood = 0;
                    int distanceBad = 0;
                    for (int j = 0; j < numbers; j++)
                    {
                        distanceGood += Math.Abs(goodAttempts[z][j] - currentPerm[j]);
                        distanceBad += Math.Abs(badAttempts[z][j] - currentPerm[j]);
                    }

                    distancesGood.Add(distanceGood);
                    distancesBad.Add(distanceBad);

                    //if (Math.Abs(distanceGood) < minDistance)
                    //{
                    //    minDistance = Math.Abs(distanceGood);
                    //    resultGood = true;
                    //}
                    //if (Math.Abs(distanceBad) < minDistance)
                    //{
                    //    minDistance = Math.Abs(distanceBad);
                    //    resultGood = false;
                    //}
                }

                distancesGood = distancesGood.OrderBy(x => Math.Abs(x)).ToList();
                distancesBad = distancesBad.OrderBy(x => Math.Abs(x)).ToList();

                for (int z = 0; z < numbers; z++)
                {
                    if (Math.Abs(distancesGood[z]) < Math.Abs(distancesBad[z]))
                        countGood++;
                    else
                        countBad++;
                }
                resultGood = Math.Abs(distancesGood[0]) < Math.Abs(distancesBad[0]);

                string message = string.Empty;
                message = resultGood?"GOOD":"BAD";
                Console.WriteLine("Case #" + caseNR.ToString() + ": result is "+ message);
                Console.WriteLine("Case #" + caseNR.ToString() + ": writing output");
                streamWriter.WriteLine("Case #" + caseNR + ": " + message); 
            }
            streamReader.Close();
            streamWriter.Close();
            Console.ReadLine();
        }

        private static List<List<int>> GenerateAttempts(int numbers, bool good)
        {
            List<List<int>> attempts = new List<List<int>>();
            List<int> basicList = new List<int>();
            Random r = new Random(numbers);
            for (int i = 1; i <= numbers; i++)
            {
                basicList.Add(i);
            }
            for(int i=0; i<100*numbers;i++)
            {
                List<int> attempt = new List<int>(basicList);
                for (int j = 0; j < numbers; j++)
                {
                    int index = 0;
                    index = r.Next(good?j:0, numbers);
                    int tmp = attempt[j];
                    attempt[j] = attempt[index];
                    attempt[index] = tmp;
                }
                attempts.Add(attempt);
            }
            return attempts;
        }

    }
}
