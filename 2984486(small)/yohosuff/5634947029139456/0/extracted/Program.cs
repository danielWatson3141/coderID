using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    struct Case
    {
        public List<string> outlets;
        public List<string> devices;
        public int N, L;

        public Case(int N, int L, List<string> outlets, List<string> devices)
        {
            this.outlets = outlets;
            this.devices = devices;
            this.N = N;
            this.L = L;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<string> lines = new List<string>(File.ReadAllLines("A-small-attempt1.in"));
            int numberOfCases = int.Parse(lines[0]);
            lines.RemoveAt(0);
            List<Case> cases = new List<Case>();
            List<string> tokens = new List<string>(); ;
            List<string> outlets = new List<string>();
            List<string> devices = new List<string>();
            int N, L;
            List<int> solutions = new List<int>();
            List<string> outputLines = new List<string>();

            for (int i = 0; i < numberOfCases; i++)
            {
                outlets.Clear();
                devices.Clear();
                tokens = new List<string>(lines[0].Split(' '));
                N = int.Parse(tokens[0]);
                L = int.Parse(tokens[1]);
                lines.RemoveAt(0);
                tokens = new List<string>(lines[0].Split(' '));
                foreach (string token in tokens)
                {
                    outlets.Add(token);
                }

                lines.RemoveAt(0);
                tokens = new List<string>(lines[0].Split(' '));
                foreach (string token in tokens)
                {
                    devices.Add(token);
                }
                lines.RemoveAt(0);
                Case c = new Case(N, L, new List<string>(outlets), new List<string>(devices));
                cases.Add(c);
            }

            int currentCase = 0;

            foreach (Case c in cases)
            {
                string master = "";
                solutions.Clear();
                currentCase++;

                for (int i = 0; i < c.L; i++)
                {
                    master += "0";
                }

                for (int i = 0; i < (int)Math.Pow(2, c.L); i++)
                {
                    //make copy of original outlets
                    List<string> outletsCopy = new List<string>(c.outlets);
                    
                    
                    //apply master to outlets
                    for (int outlet = 0; outlet < c.N; outlet++)
                    {
                        for (int j = 0; j < c.L; j++)
                        {
                            if (master[j] == '1')
                            {
                                if (c.outlets[outlet][j] == '1')
                                {
                                    StringBuilder sb = new StringBuilder(outletsCopy[outlet]);
                                    sb[j] = '0';
                                    outletsCopy[outlet] = sb.ToString();
                                }
                                else
                                {
                                    StringBuilder sb = new StringBuilder(outletsCopy[outlet]);
                                    sb[j] = '1';
                                    outletsCopy[outlet] = sb.ToString();
                                }
                            }
                        }
                    }

                    
                    //check for a match
                    outletsCopy.Sort();
                    c.devices.Sort();
                    bool match = true;
                    for (int j = 0; j < outletsCopy.Count; j++)
                    {
                        if (outletsCopy[j] != c.devices[j])
                        {
                            match = false;
                            j = outletsCopy.Count;
                        }
                    }

                    if (match)
                    {
                        int count = 0;
                        foreach (char ch in master)
                            if (ch == '1')
                                count++;
                        solutions.Add(count);
                    }
                    
                    //get next master
                    master = GetNextMaster(master, c);
                }

                solutions.Sort();

                if (solutions.Count != 0)
                {
                    Console.WriteLine("Case #{0}: {1}", currentCase, solutions[0]);
                    outputLines.Add(string.Format("Case #{0}: {1}", currentCase, solutions[0]));
                }
                else
                {
                    Console.WriteLine(string.Format("Case #{0}: NOT POSSIBLE", currentCase));
                    outputLines.Add(string.Format("Case #{0}: NOT POSSIBLE", currentCase));
                }

            } //foreach case

            File.WriteAllLines("output.txt", outputLines.ToArray());

            Console.ReadKey();

        }

        static public string GetNextMaster(string master, Case c)
        {

            int j = Convert.ToInt32(master, 2) +1;

            string s = Convert.ToString(j, 2);

            while (s.Length < c.L)
                s = "0" + s;

            return s;
        }
    }
}
