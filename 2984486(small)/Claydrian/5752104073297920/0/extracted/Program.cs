using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    class Program
    {

        static void Main(string[] args)
        {
            string path = "C-small-attempt0.in";
            System.IO.StreamReader reader = new System.IO.StreamReader(path);
            System.IO.StreamWriter output = new System.IO.StreamWriter("output.txt");
            int testCases = int.Parse(reader.ReadLine());
            for (int i = 0; i < testCases; i++)
            {
                output.Write("Case #");
                output.Write(i + 1);
                output.Write(": ");

                int count = int.Parse(reader.ReadLine());
                var rands = readRow(reader.ReadLine());
                if (rands.Select((d, index) => d * (index - count / 2)).Sum() < -Math.Sqrt(count))
                {
                    output.Write("BAD");
                }
                else
                {
                    output.Write("GOOD");
                }

                output.WriteLine();
            }
            output.Close();
            reader.Close();
        }


        static IEnumerable<double> readRow(string row)
        {
            return row.Split(' ').Select(s => double.Parse(s));
        }
    }
}
