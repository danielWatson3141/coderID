using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChargingChaos
{
    class Program
    {
        static void Main(string[] args)
        {
            const bool debug = false;


            var inputFile = args[0];
            var inputStream = new StreamReader(inputFile);

            var numCases = int.Parse(inputStream.ReadLine());

            var output = new StringBuilder();

            
            for (var t = 0; t < numCases; t++)
            {
                var paramLine = inputStream.ReadLine().Split(' ');
                var deviceCount = int.Parse(paramLine[0]);
                var bitCount = int.Parse(paramLine[1]);

                var outlets = inputStream.ReadLine().Split(' ').ToList();
                outlets.Sort();
                var devices = inputStream.ReadLine().Split(' ').ToList();
                devices.Sort();

                var successList = new List<int>();

                // Brute force this shit IDFK
                // Start the bit flipping from 0 and keep fucking stacking
                // Once a winner is found, we win
                var exp = (int)Math.Floor(Math.Pow(2, bitCount));
                for (var flipCounter = 0; flipCounter <= exp; flipCounter++)
                {
                    var bits = Convert.ToString(flipCounter, 2).PadLeft(bitCount, '0').ToCharArray();

                    // Local outlet we can screw with
                    var tmpOutlets = new List<string>(outlets);

                    if (debug)
                    {
                        Console.WriteLine("----------" + Environment.NewLine + "case: " + (t + 1));
                        Console.WriteLine("B4: " + tmpOutlets.Aggregate((s, s1) => s + " " + s1));
                        Console.WriteLine("bits: " + new string(bits));
                    }

                    // Flip the bits
                    for (var index = 0; index < tmpOutlets.Count; index++)
                    {
                        var tmpOutletArr = tmpOutlets[index].ToCharArray();
                        // Loop through each bit flipping if matched
                        for (var b = 0; b < bits.Count() && b < tmpOutletArr.Count(); b++)
                        {
                            if (bits[b] == '1')
                                tmpOutletArr[b] = (tmpOutletArr[b] == '1') ? '0' : '1';
                        }
                        tmpOutlets[index] = new string(tmpOutletArr);
                    }

                    if(debug)
                        Console.WriteLine("after: " + tmpOutlets.Aggregate((s, s1) => s + " " + s1));

                    // sort that tmpOutlet
                    tmpOutlets.Sort();

                    // See if we match
                    var success = true;
                    for (var i = 0; i < outlets.Count && success; i++)
                    {
                        if (tmpOutlets[i] != devices[i])
                            success = false;
                    }
                    if (success)
                    {
                        //output.AppendLine("Case #" + (t + 1) + ": " + NumOfFlips(bits));

                        successList.Add(NumOfFlips(bits));

                        //break;
                    }
                    
                    // The end
                    if (flipCounter >= exp)
                    {
                        if(successList.Count < 1)
                            output.AppendLine("Case #" + (t + 1) + ": NOT POSSIBLE");
                        else
                        {
                            successList.Sort();
                            output.AppendLine("Case #" + (t + 1) + ": " + successList.First());
                        }
                    }

                }

            }

            // Save the output
            File.WriteAllText("_output.out", output.ToString().Trim());

            // Show me
            Console.WriteLine(output.ToString().Trim());

            Console.ReadKey();
        }

        public static int NumOfFlips(char[] bits)
        {
            var count = 0;
            for (int i = 0; i < bits.Count(); i++)
            {
                if (bits[i] == '1')
                    count++;
            }

            return count;
        }
    }


}
