using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;
using System.Linq;

namespace GCJ2014.R1A
{
    public class ProperSuffle
    {
        static class Program
        {
            [STAThread]
            static void Main(string[] args)
            {
                string inpFilePath = "R1A\\InputOutputFiles\\C-small-attempt1.in";
                if (args.Length > 0) inpFilePath = args[0];
                ProperSuffle b = new ProperSuffle(inpFilePath);
                b.Run();
            }
        }

        StreamReader inputFile;
        StreamWriter outPutFile;

        long totalCases, testCase;
        string fileLine, inputFilePath, outputFilePath;

        int[] p;
        public ProperSuffle(string inputFilePath)
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
            this.inputFile.ReadLine();
            string line = this.inputFile.ReadLine();
            p = line.Split().Select(s => Convert.ToInt32(s)).ToArray();
            Console.WriteLine("Initialized testcase#{0}", testCase);
        }

        private void RunTestCase()
        {
            double[] batchAvg = new double[100];
            int index=0;
            for (int i = 0; i < 100; i++ )
            {
                int[] batch = new int[10];
                for (int k=0; k < 10; k++)
                {
                    batch[k] = p[index++];
                }
                batchAvg[i] = batch.Sum(d=>d)/10;
            }
            bool isBad = (batchAvg[0] > 400 && batchAvg[9] < 400);
            this.outPutFile.WriteLine(string.Format("Case #{0}: {1}", this.testCase + 1, isBad ? "BAD" : "GOOD"));
        }
    }
}
