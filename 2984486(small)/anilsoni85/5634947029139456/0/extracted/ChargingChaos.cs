using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;
using System.Linq;

namespace GCJ2014.R1A
{
    public class ChargingChaos
    {
        static class Program
        {
            [STAThread]
            static void Main(string[] args)
            {
                string inpFilePath = "R1A\\InputOutputFiles\\A-small-attempt1.in";
                if (args.Length > 0) inpFilePath = args[0];
                ChargingChaos b = new ChargingChaos(inpFilePath);
                b.Run();
            }
        }

        StreamReader inputFile;
        StreamWriter outPutFile;

        long totalCases, testCase;
        string fileLine, inputFilePath, outputFilePath;

        int[] devices, outlets;

        public ChargingChaos(string inputFilePath)
        {
            this.inputFilePath = Path.GetFullPath(inputFilePath);
            this.outputFilePath = Path.Combine(Path.GetDirectoryName(inputFilePath), Path.GetFileNameWithoutExtension(inputFilePath) + ".out");
        }

        public void Run()
        {
            this.inputFile = new StreamReader(this.inputFilePath);
            this.outPutFile = new StreamWriter(this.outputFilePath);

            fileLine = this.inputFile.ReadLine();
            totalCases = Convert.ToInt32(fileLine);

            for (testCase = 0; testCase < totalCases; testCase++)
            {
                InitTestCase();
                RunTestCase();
                this.outPutFile.Flush();
            }

            this.outPutFile.Close();
            this.inputFile.Close();
        }

        private void InitTestCase()
        {
            this.inputFile.ReadLine(); //N L
            string line = this.inputFile.ReadLine();
            outlets = line.Split().Select(s => Convert.ToInt32(s, 2)).ToArray();
            line = this.inputFile.ReadLine();
            devices = line.Split().Select(s => Convert.ToInt32(s, 2)).ToArray();
            Console.WriteLine("Initialized testcase#{0}", testCase);
        }

        private void RunTestCase()
        {
            int firstDevice = devices[0];
            int[] switchedOutlets = (int[])outlets.Clone();
            int outletAttempt = 0;
            int map = 0;
            string ans = string.Empty;
            int switchedRequired = -1;
            bool switchingRequired = true;
            if (devices.Count(d => switchedOutlets.Contains(d)) == devices.Length)
            {
                switchingRequired = false;
                switchedRequired = 0;
            }
            while (switchingRequired)
            {
                if (outletAttempt >= outlets.Length)
                {
                    break;
                }
                map = firstDevice ^ outlets[outletAttempt];
                if (map != 0)
                {
                    switchedOutlets = outlets.Select(o => o ^ map).ToArray();
                    if (devices.Count(d => switchedOutlets.Contains(d)) == devices.Length)
                    {
                        int s = Convert.ToString(map, 2).ToCharArray().Count(c => c == '1');
                        if (switchedRequired == -1 || s < switchedRequired)
                            switchedRequired = s;
                    }
                }
                outletAttempt++;
            }
            ans = switchedRequired == -1? "NOT POSSIBLE": switchedRequired.ToString();
            this.outPutFile.WriteLine(string.Format("Case #{0}: {1}", this.testCase + 1, ans));
        }
    }
}
