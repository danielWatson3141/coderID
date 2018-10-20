using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace task3
{
    class Program
    {

        static int Calc()
        {
            var r = new Random();
            var p = Enumerable.Range(0, 1000).ToArray();
            for (var i = 0; i < 1000; ++i)
            {
                var j = r.Next(0, 1000);
                var t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
            var s = 0;
            for (var i = 0; i < 500; ++i)
            {
                if (p[i] < 500)
                {
                    ++s;
                }
            }
            return s;
        }

        static void Ave()
        {
            long l = 0;
            for (var i = 0; i < 200; ++i)
            {
                l += Calc();
            }
            Console.WriteLine(l / 200.0);
        }


        static void Main(string[] args)
        {
            //Ave();
            //return;
            TextReader reader = null;
            TextWriter writer = null;
            try
            {
                reader = new StreamReader(args[0], Encoding.ASCII);
                writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII);
                var cases = int.Parse(reader.ReadLine());
                Console.WriteLine("Cases {0}", cases);
                for (var i = 1; i <= cases; ++i)
                {
                    var n = int.Parse(reader.ReadLine());
                    var p = reader.ReadLine().Split(new[] { ' ' }).Select(int.Parse).ToArray();
                    var ind1 = 0;
                    for (var j = 0; j < 500; ++j)
                    {
                        if (p[j] < 500)
                        {
                            ++ind1;
                        }
                    }
                    var ind2 = 0;
                    for (var j = 500; j < 1000; ++j)
                    {
                        if (p[j] > 500)
                        {
                            ++ind2;
                        }
                    }
                    var ans = Math.Abs(ind1 - ind2) > 10 ? "BAD" : "GOOD";
                    var result = String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", i, ans);
                    writer.WriteLine(result);
                }
            }
            finally
            {
                if (writer != null)
                    writer.Close();
                if (reader != null)
                    reader.Close();
            }
        }
    }
}
