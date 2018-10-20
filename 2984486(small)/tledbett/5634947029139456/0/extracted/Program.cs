using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            string[] delimiters = new string[]{" "};
            int testCaseNumber = 1;
            for (int i = 1; i < lines.Length; i+=3, testCaseNumber++)
            {
                string NL = lines[i];
                string[] switchesString = lines[i + 1].Split(delimiters, StringSplitOptions.RemoveEmptyEntries);
                string[] devicesString = lines[i + 2].Split(delimiters, StringSplitOptions.RemoveEmptyEntries);

                long[] switchFlows = new long[switchesString.Length];
                for(int k=0; k < switchesString.Length; k++)
                {
                    string switchString = switchesString[k];
                    long flow = 0;
                    for (int j = 0; j < switchString.Length; j++)
                    {
                        char c = switchString[j];
                        if (c != '0')
                        {
                            flow = flow | ((long)1 << j);
                        }
                    }
                    switchFlows[k] = flow;
                }

                long[] deviceFlows = new long[devicesString.Length];
                for(int k=0; k < devicesString.Length; k++)
                {
                    string devicString = devicesString[k];
                    long flow = 0;
                    for (int j = 0; j < devicString.Length; j++)
                    {
                        char c = devicString[j];
                        if (c != '0')
                        {
                            flow = flow | ((long)1 << j);
                        }
                    }
                    deviceFlows[k] = flow;
                }

                //pick a device
                bool foundSwitch = false;
                int switches = 0;
                foreach (var deviceFlow in deviceFlows)
                {
                    //find the switch that has
                    var closestMatches = switchFlows.OrderBy(item => GetNumberOf1s(item ^ deviceFlow));
                    foreach (var closestSwitch in closestMatches)
                    {
                        //find the bits to flip
                        //List<int> switchesToFlip = closestSwitch.Select(
                        //                                (item, index)=> new {index=index, isMatch=(item==deviceFlow[index])})
                        //                                .Where(item => item.isMatch==false).Select(item => item.index).ToList();
                        long[] newSwitchFlows = new long[switchFlows.Length];
                        long switchesToPerform = deviceFlow ^ closestSwitch;
                        switches = GetNumberOf1s(switchesToPerform);
                        for (int j = 0; j < switchFlows.Length; j++)
                        {
                            newSwitchFlows[j] = switchFlows[j] ^ switchesToPerform;
                        }

                        if (deviceFlows.Intersect(newSwitchFlows).Count() == deviceFlows.Length)
                        {
                            foundSwitch = true;
                            break;
                        }
                    }
                    if (foundSwitch)
                    {
                        break;
                    }
                }
                Console.Write("Case #{0}: ", testCaseNumber);
                if (foundSwitch)
                {
                    Console.WriteLine(switches);
                }
                else
                {
                    Console.WriteLine("NOT POSSIBLE");
                }
            }
        }

        public static int GetNumberOf1s(long n)
        {
            int count = 0;
            while (n != 0)
            {
                n = n & (n - 1);
                count++;
            }
            return count;
        }
    }
}
