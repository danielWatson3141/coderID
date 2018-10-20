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
            StreamReader streamReader = new StreamReader(@"D:\Work\Programming Challange\CodeJam 2014\Round 1\Problem A\inputSmall.txt");
            StreamWriter streamWriter = new StreamWriter(@"D:\Work\Programming Challange\CodeJam 2014\Round 1\Problem A\outputSmall.txt", false);
            
            string line = streamReader.ReadLine();
            int nrOfTests = 0;
            if(!int.TryParse(line, out nrOfTests))
            {
                Console.WriteLine("Number of tests is not an int!");
                return;
            }
            
            Console.WriteLine("Number of tests: "+nrOfTests.ToString());
            for(int i=0; i<nrOfTests;i++)
            {
                int caseNR = i+1;
                Console.WriteLine("Case #"+caseNR.ToString()+": reading input");
                //read the input
                string input = streamReader.ReadLine();
                string[] split = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int nrOfOutlets = 0;
                if(!int.TryParse(split[0], out nrOfOutlets))
                    Console.WriteLine("Case #" + caseNR.ToString() + ": failed parsing the number of outlets");
                int nrOfSwitches = 0;
                if (!int.TryParse(split[1], out nrOfSwitches))
                    Console.WriteLine("Case #" + caseNR.ToString() + ": failed parsing the number of switches");

                input = streamReader.ReadLine();
                split = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                List<Int64> outlets = split.Select<string, Int64>(text => Convert.ToInt64(text, 2)).ToList();

                input = streamReader.ReadLine();
                split = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                List<Int64> devices = split.Select<string, Int64>(text => Convert.ToInt64(text, 2)).ToList();

                //process it
                Console.WriteLine("Case #" + caseNR.ToString() + ": processing input");
                List<Int64> switchPositions = null;
                for (int z = 0; z < nrOfOutlets; z++)
                {
                    List<Int64> options = new List<long>();
                    Int64 currentOutlet = outlets[z];
                    for(int j=0; j < nrOfOutlets; j++)
                    {
                        options.Add(currentOutlet ^ devices[j]);
                    }
                    if (z == 0)
                    {
                        switchPositions = options;
                    }
                    else
                    {
                        switchPositions = switchPositions.Where(pos => options.Contains(pos)).ToList();
                    }
                }

                List<Int64> finalSwitchPositions = new List<long>();
                int minSwitches = -1;
                if (switchPositions.Count > 0)
                {
                    //sort the devices
                    devices = devices.OrderBy(d => d).ToList();
                    //validate that all devices get covered
                    for (int z = 0; z < switchPositions.Count; z++)
                    {
                        List<Int64> tmpOutlets = outlets.Select(outlet => outlet ^ switchPositions[z]).OrderBy(outlet => outlet).ToList();
                        bool accepted = true;
                        for(int j=0; j<nrOfOutlets;j++)
                        {
                            if(tmpOutlets[j] != devices[j])
                            {
                                accepted = false;
                                break;
                            }
                        }
                        if (accepted)
                        {
                            finalSwitchPositions.Add(switchPositions[z]);
                        }
                    }


                    for (int z = 0; z < finalSwitchPositions.Count; z++)
                    {
                        string binarySwitch = Convert.ToString(finalSwitchPositions[z], 2);
                        int tmpCount = binarySwitch.ToCharArray().Where(c => c == '1').Count();
                        if (minSwitches == -1 || tmpCount < minSwitches)
                            minSwitches = tmpCount;
                    }
                }
                string message = string.Empty;
                message = minSwitches==-1?"NOT POSSIBLE":minSwitches.ToString();
                Console.WriteLine("Case #" + caseNR.ToString() + ": result is "+ message);
                Console.WriteLine("Case #" + caseNR.ToString() + ": writing output");
                streamWriter.WriteLine("Case #" + caseNR + ": " + message); 
            }
            streamReader.Close();
            streamWriter.Close();
            Console.ReadLine();
        }
    }
}
