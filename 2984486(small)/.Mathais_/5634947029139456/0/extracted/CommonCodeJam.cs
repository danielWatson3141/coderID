using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qual_1
{
    interface ITestCase
    {
        string findResult();
    }

    class CommonCodeJam
    {
        static List<ITestCase> testCases = new List<ITestCase>();

        public static void Run()
        {
            Console.WriteLine("(l)arge or (s)mall?");
            char x = Console.ReadKey().KeyChar;

            StreamReader reader;

            if(x.Equals('l'))
                reader = new StreamReader(@"G:\Users\Matt\Downloads\A-large.in");
            else
                reader = new StreamReader(@"G:\Users\Matt\Downloads\A-small-attempt1.in");

            StreamWriter writer = new StreamWriter(@"../../output.txt");

            int numberOfCases = int.Parse(reader.ReadLine());

            while(!reader.EndOfStream)
            {
                reader.ReadLine();
                testCases.Add(new TestCase(reader.ReadLine(), reader.ReadLine()));
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
}
