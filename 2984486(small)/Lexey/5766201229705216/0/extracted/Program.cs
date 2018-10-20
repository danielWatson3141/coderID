using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace task2
{
    class Program
    {
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
                    var n = int.Parse(reader.ReadLine());
                    var m = new bool[n, n];
                    for (var j = 0; j < n - 1; ++j)
                    {
                        var parameters = reader.ReadLine().Split(new[] { ' ' });
                        var k = int.Parse(parameters[0]) - 1;
                        var l = int.Parse(parameters[1]) - 1;
                        m[k, l] = true;
                        m[l, k] = true;
                    }
                    var r = Count(n, m);
                    var result = String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", i, r);
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

        private static int Count(int n, bool[,] m)
        {
            // пробуем каждый узел в качестве корня
            var deleted = n;
            for (var i = 0; i < n; ++i)
            {
                var v = CountSubtree(n, m, i, -1).Item2;
                if (v < deleted)
                {
                    deleted = v;
                }
            }
            return deleted;
        }

        private static Tuple<int, int> CountSubtree(int n, bool[,] m, int root, int parent)
        {
            var subCounts = new List<Tuple<int, int>>(); // пары: <число узлов, число удаленных узлов>
            for (var i = 0; i < n; ++i)
            {
                if (!m[root, i])
                {
                    continue;
                }
                if (i == parent) // родителя не считаем
                {
                   continue;
                }
                subCounts.Add(CountSubtree(n, m, i, root));
            }
            var unconditionallyDeleted = subCounts.Sum(c => c.Item2); // то, что удаляем в любом случае
            switch (subCounts.Count)
            {
                case 0:
                    return Tuple.Create(1, 0);
                case 1:
                    // удаляем единственное поддерево
                    return Tuple.Create(1, subCounts[0].Item1 + unconditionallyDeleted);
                case 2:
                    return Tuple.Create(1 + subCounts[0].Item1 + subCounts[1].Item1, unconditionallyDeleted);
                default:
                    subCounts = subCounts.OrderByDescending(_ => _.Item1).ToList();
                    var left = subCounts[0].Item1 + subCounts[1].Item1;
                    var extraDeleted = subCounts.Skip(2).Sum(subCount => subCount.Item1);
                    return Tuple.Create(1 + left, unconditionallyDeleted + extraDeleted);
            }
        }
    }
}
