using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace R1A1
{
    internal class Program
    {
        public static void RunTestCases(string[] rawTestCases,
            int numTestCases,
            Action<String> outputAction,
            Action<String> debugAction)
        {
            int currentLine = 0;
            for (int i = 0; i < numTestCases; i++)
            {
                int[] settings = rawTestCases.GetSettings(currentLine++);
                int numItems = settings[0];
                int numBits = settings[1];

                debugAction("Test Case " + (i + 1) + " items:" + numItems + " bits:" + numBits);

                char[][] outlets = rawTestCases[currentLine++].Split(' ').Select(x => x.Trim().ToCharArray()).ToArray();
                string[] devices = rawTestCases[currentLine++].Split(' ').Select(x=>x.Trim()).ToArray();

                string outcome = "Not Implimented";

                int toggles = 0;


                List<int> possibleToggles = new List<int>();
                for (int j = 0; j < numBits; j++)
                {
                    int outletCount = 0;
                    foreach (var outlet in outlets)
                    {
                        outletCount += outlet[j]=='1'?1:0;
                    }

                    int deviceCount = 0;
                    foreach (var device in devices)
                    {
                        deviceCount += device[j] == '1'?1:0;
                    }

                    debugAction("Bit"+j+":" + outletCount + ":" + deviceCount);

                    if (outletCount == deviceCount)
                    {
                        if (outletCount == numItems/(decimal) 2)
                        {
                            possibleToggles.Add(j);
                        }
                        continue;
                    }
                    if (numItems - outletCount == deviceCount)
                    {
                        for (int k = 0; k < numItems; k++)
                        {
                            outlets[k][j] = outlets[k][j]=='1'?'0':'1';
                        }
                        toggles += 1;
                        continue;
                    }
                    toggles = -1;
                    break;
                }

                List<string> devicesL = devices.ToList();
                List<string> outletsL = outlets.Select(x => new string(x)).ToList();

                while (devicesL.Count > 0 && outletsL.Contains(devicesL.First()))
                {
                    outletsL.Remove(devicesL.First());
                    devicesL.Remove(devicesL.First());
                }


                if (devicesL.Count > 0 && toggles != -1)
                {
                    var result = permutationworks(possibleToggles, outlets, devices, toggles);
                    if (result.Item1)
                    {
                        toggles = result.Item2;
                    }
                    else
                    {
                        toggles = -1;
                    }
                }

                outcome = toggles == -1 ? "NOT POSSIBLE" : toggles.ToString();


                debugAction("Case #" + (i + 1) + ": " + outcome);
                outputAction("Case #" + (i + 1) + ": " + outcome);
            }
        }

        private static Tuple<bool,int> permutationworks(List<int> bits, char[][] outlets, string[] devices, int toggles)
        {
            if (bits.Count == 0)
            {
                List<string> devicesL = devices.ToList();
                List<string> outletsL = outlets.Select(x => new string(x)).ToList();

                while (devicesL.Count > 0 && outletsL.Contains(devicesL.First()))
                {
                    outletsL.Remove(devicesL.First());
                    devicesL.Remove(devicesL.First());
                }

                if (devicesL.Count == 0) return Tuple.Create(true,toggles);
                return Tuple.Create(false, 0);
            }
            
            //Toggle
            char[][] toggledOutlets = outlets.Select(x=>new string(x).ToCharArray()).ToArray();
            for (int k = 0; k < outlets.Length; k++)
            {
                toggledOutlets[k][bits.First()] = outlets[k][bits.First()] == '1' ? '0' : '1';
            }
            var newBits = bits.Skip(1).ToList();
            var toggleResult = permutationworks(newBits, toggledOutlets, devices, toggles + 1);

            //NoToggle
            var nonToggleResult = permutationworks(newBits, outlets, devices, toggles);

            if (nonToggleResult.Item1 && toggleResult.Item1)
            {
                if (nonToggleResult.Item2 > toggleResult.Item2)
                {
                    return toggleResult;
                }
                return nonToggleResult;
            }
            if (nonToggleResult.Item1) return nonToggleResult;
            return toggleResult;
        }

        private static void Main(string[] args)
        {
            string filename = args.Length == 0 ? "" : args[0];
            if (filename == "")
            {
                var filenames = Directory.GetFiles(Environment.CurrentDirectory).Where(x => x.EndsWith(".in")).ToArray();
                Console.WriteLine("Test file?");
                int n = 0;
                foreach (var f in filenames)
                {
                    Console.WriteLine(n++ + ":" + f);
                }
                var i = int.Parse(Console.ReadLine());
                filename = filenames[i];
            }
            if (filename == "")
            {
                filename = Directory.GetFiles(Environment.CurrentDirectory).First(x => x.EndsWith(".in"));
            }

            string[] testFile = File.ReadAllLines(filename);
            int NumberOfTestCases = int.Parse(testFile.First().Trim());

            List<string> output = new List<string>();
            RunTestCases(testFile.Skip(1).ToArray(),
                NumberOfTestCases,
                output.Add,
                Console.WriteLine);
            File.WriteAllLines("output.out", output);
            Console.WriteLine("Finished " + filename);
            Console.WriteLine("-- press any key --");
            Console.ReadKey();
        }
    }

    internal static class Helpers
    {
        public static int[] GetSettings(this string[] rawFile, int line)
        {
            return rawFile[line].Split(' ')
                .Select(x => int.Parse(x.Trim())).ToArray();
        }

        public static long GetIntegerFromBinaryString(string binary, int bitCount)
        {
            if (binary.Length == bitCount && binary[0] == '1')
                return Convert.ToInt64(binary.PadLeft(32, '1'), 2);
            else
                return Convert.ToInt64(binary, 2);
        }
    }
}
