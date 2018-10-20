using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qual_3
{
    interface ITestCase
    {
        string findResult();
    }

    class CommonCodeJam
    {
        static List<ITestCase> testCases = new List<ITestCase>();
        static void Main(string[] args)
        {
            CommonCodeJam.Run();
        }

        public static void Run()
        {
            Console.WriteLine("(l)arge or (s)mall?");
            char x = Console.ReadKey().KeyChar;

            StreamReader reader;

            if (x.Equals('l'))
                reader = new StreamReader(@"..\..\small.in");
            else
                reader = new StreamReader(@"G:\Users\Matt\Downloads\C-small-attempt12.in");

            StreamWriter writer = new StreamWriter(@"../../output.txt");

            int numberOfCases = int.Parse(reader.ReadLine());

            while(!reader.EndOfStream)
            {
                reader.ReadLine();
                testCases.Add(new TestCase(reader.ReadLine()));
            }

            if (testCases.Count != numberOfCases)
                throw new Exception("Error reading inputs");

            output(testCases, writer);

            reader.Close();
            writer.Close();

            Console.WriteLine("Press any key to quit...");
            Console.ReadKey();
        }

        private static void output(List<ITestCase> cases, StreamWriter writer)
        {
            for (int i = 0; i < cases.Count; i++)
            {
                string output = string.Format("Case #{0}: {1}", (i + 1), cases[i].findResult());

                Console.WriteLine(output);
                writer.WriteLine(output);
            }
        }
    }

    class TestCase : ITestCase
    {
        private List<int> input;

        public TestCase(string inputStr)
        {
            input = new List<int>();

            foreach (string s in inputStr.Split(' '))
                input.Add(int.Parse(s));
        }

        public Boolean isBad(int count, List<int> list)
        {
            int size = list.Count() / 2;

            int first = input.Take(size).Sum();
            int last = input.Skip(size).Take(size).Sum();

            double diff = (double)last / (double)first;

            if (size % 2 != 0)
                size--;

            if (diff > 1.02)
            {
                count++;

                if (count > 3)
                    return true;
                else
                    return isBad(count, list.Skip(list.Count() - size).Take(size).ToList());
            }
            else
                return false;
        }

        public Boolean isBad()
        {
            int count = 0;

            for (int i = 0; i < input.Count(); i++)
                if (input[i] == i)
                    count++;

            if (count > 3)
                return true;
            else
                return false;
        }

        public string findResult()
        {
            if(isBad())
                return "BAD";
            else
                return "GOOD";
        }
    }
}
