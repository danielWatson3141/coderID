using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfTestCases = 0;

            StreamReader reader = File.OpenText(@"C:\Users\ankush2011.NAGARRO\Downloads\A-small-attempt1.in");
            StreamWriter writer = new StreamWriter(@"C:\Users\ankush2011.NAGARRO\Downloads\abc.txt");

            numberOfTestCases = Convert.ToInt32(reader.ReadLine());

            for (int count = 0; count < numberOfTestCases; count++)
            {
                writer.WriteLine("Case #{0}: {1}", count + 1, RunTestCase(reader));
                Console.WriteLine(count + 1);
            }

            writer.Flush();

        }

        private static string RunTestCase(StreamReader reader)
        {
            int count = 0;
            int index = 0;
            int flips = 0;

            string str = reader.ReadLine();
            string[] array = str.Split(' ');

            int numberOfOutlets = Convert.ToInt32(array[0]);
            int LengthOfOutlet = Convert.ToInt32(array[1]);

            string[] outlets = new string[numberOfOutlets];
            string[] devices = new string[numberOfOutlets];

            ReadInput(reader, ref outlets, ref devices);

            count = Match(outlets, devices);
            if (count == outlets.Length)
            {
                return "0";
            }

            flips = StartFlip(outlets, devices, count, index, flips);

            if (flips == Int32.MaxValue)
                return "NOT POSSIBLE";
            else
                return flips.ToString();

        }

        private static int StartFlip(string[] outlets, string[] devices, int count, int index, int flips)
        {
            int countNew = 0;

            Flip(ref outlets, index);
            countNew = Match(outlets, devices);

            if (countNew == outlets.Length)
            {
                return flips+1;
            }
            else
            {
                if (index == outlets[0].Length - 1)
                {
                    return Int32.MaxValue;
                }

                int tempCount = 0;
                int tempCount1 = 0;
                tempCount = StartFlip(outlets.ToArray(), devices, countNew, index+1, flips+1);

                Flip(ref outlets, index);
                tempCount1 = StartFlip(outlets.ToArray(), devices, countNew, index+1, flips);

                if (tempCount >= tempCount1)
                {
                    return tempCount1;
                }
                else
                    return tempCount;
            }
        }

        private static int Match(string[] outlets, string[] devices)
        {
            int matchCount = 0;
            Array.Sort(outlets);

            for (int i = 0; i < outlets.Length; i++)
            {
                if (outlets[i] == devices[i])
                    matchCount++;
            }

            return matchCount;
        }

        private static void Flip(ref string[] outlets, int index)
        {
            for (int i = 0; i < outlets.Length; i++)
            {
                string x = outlets[i];

                StringBuilder sb = new StringBuilder(x);

                if (x[index] == '1')
                {
                    sb[index] = '0';
                    x = sb.ToString();
                }
                else
                {
                    sb[index] = '1';
                    x = sb.ToString();
                }

                outlets[i] = x;
            }
        }


        private static void ReadInput(StreamReader reader, ref string[] outlets, ref string[] devices)
        {
            string str = reader.ReadLine();
            outlets = str.Split(' ');

            //outlets = array.Select(n => Convert.ToInt32(n)).ToArray();

            str = reader.ReadLine();
            devices = str.Split(' ');

            Array.Sort(devices);
            //devices = array.Select(n => Convert.ToInt32(n)).ToArray();
        }
    }
}
