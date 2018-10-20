using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace task1
{
    class Program
    {
        private static long FromBinary(string s)
        {
            long r = 0;
            foreach (var ch in s)
            {
                r <<= 1;
                switch (ch)
                {
                    case '1':
                        r += 1;
                        break;
                    default:
                        break;
                }
            }
            return r;
        }

        static void Main(string[] args)
        {
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
                    var parameters = reader.ReadLine().Split(new[] { ' ' });
                    var n = int.Parse(parameters[0]);
                    var l = int.Parse(parameters[1]);
                    var outlets = reader.ReadLine().Split(new[] { ' ' })
                        .Select(FromBinary).ToArray();
                    var demands = reader.ReadLine().Split(new[] { ' ' })
                        .Select(FromBinary).ToArray();
                    var r = Try(l, 0, outlets, demands);
                    var rs = r != int.MaxValue  ? r.ToString() : "NOT POSSIBLE";
                    var result = String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", i, rs);
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

        private static int Try(int l, int bit, long[] outlets, long[] demands)
        {
            if (bit == l)
            {
                return 0;
            }
            var switchMask = 1 << bit;
            var compareMask = (switchMask << 1) - 1;
            Array.Sort(demands, (x,y) => Comparer<long>.Default.Compare(x & compareMask, y & compareMask));
            Array.Sort(outlets, (x,y) => Comparer<long>.Default.Compare(x & compareMask, y & compareMask));
            var i = 0;
            for (; i < demands.Length; ++i)
            {
                if ((demands[i] & compareMask) != (outlets[i] & compareMask))
                {
                    break;
                }
            }
            var r1 = int.MaxValue;
            if (i == demands.Length)
            {
                r1 = Try(l, bit + 1, outlets, demands);
                Array.Sort(demands, (x, y) => Comparer<long>.Default.Compare(x & compareMask, y & compareMask));
            }
            var newOutlets = outlets.Select(_ => _ ^ switchMask).ToArray();
            Array.Sort(newOutlets, (x, y) => Comparer<long>.Default.Compare(x & compareMask, y & compareMask));
            i = 0;
            for (; i < demands.Length; ++i)
            {
                if ((demands[i] & compareMask) != (newOutlets[i] & compareMask))
                {
                    break;
                }
            }
            var r2 = int.MaxValue;
            if (i == demands.Length)
            {
                r2 = Try(l, bit + 1, newOutlets, demands);
                if (r2 < int.MaxValue)
                {
                    ++r2;
                }
            }
            return Math.Min(r1, r2);
        }
    }
}
