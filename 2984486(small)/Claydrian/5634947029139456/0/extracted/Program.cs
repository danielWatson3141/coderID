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
            string path = "A-small-attempt1.in";
            System.IO.StreamReader reader = new System.IO.StreamReader(path);
            System.IO.StreamWriter output = new System.IO.StreamWriter("output.txt");
            int testCases = int.Parse(reader.ReadLine());
            for (int i = 0; i < testCases; i++)
            {
                output.Write("Case #");
                output.Write(i + 1);
                output.Write(": ");

                var line = readRow(reader.ReadLine());
                int N = (int) line.ElementAt(0);
                int L = (int) line.ElementAt(1);

                var outlets = readRow2(reader.ReadLine());
                var devices = readRow2(reader.ReadLine());

                try
                {
                    output.Write(testy(outlets, devices));
                }
                catch( InvalidOperationException e )
                {
                    output.Write("NOT POSSIBLE");
                }
                output.WriteLine();
            }
            output.Close();
            reader.Close();
        }

        private static int testy(IEnumerable<long> outlets, IEnumerable<long> devices)
        {
            long firstOutlet = outlets.First();
            IEnumerable<long> devices2 = devices.Select(d => d ^ firstOutlet).OrderBy(d => Bits(d)).Where( d => !devices.Except(outlets.Select(e => e ^ d )).Any());
            return Bits(devices2.First());

        }

        private static int Bits(long l)
        {
            int count = 0;
            while (l > 0)
            {
                if ((l & 1) == 1)
                {
                    count += 1;
                }
                l >>= 1;
            }
            return count;
        }


        static IEnumerable<double> readRow(string row)
        {
            return row.Split(' ').Select(s => double.Parse(s));
        }

        static IEnumerable<long> readRow2(string row)
        {
            return row.Split(' ').Select(s => Convert.ToInt64(s, 2));
        }
    }
}
