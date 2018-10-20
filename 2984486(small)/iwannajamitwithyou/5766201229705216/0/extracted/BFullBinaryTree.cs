using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

class BFullBinaryTree
{
    static void Main()
    {
        var T = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
        for (int t = 1; t <= T; t++)
        {
            var N = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
            var nodes = Enumerable.Range(0, N).Select(_ => new Node()).ToArray();
            var count = new int[Math.Max(N, 4)];
            //var byNeighCount = new SortedDictionary<int, HashSet<Node>>();
            //foreach (var node in nodes)
            //    byNeighCount[0].Add(node);
            //Action<Node, Node, bool> addRemove = (x, y, add) =>
            //{
            //    byNeighCount[x.Neigh.Count].Remove(x);
            //    byNeighCount[y.Neigh.Count].Remove(y);
            //    if (add)
            //    {
            //        x.Neigh.Add(y);
            //        y.Neigh.Add(x);
            //    }
            //    else
            //    {
            //        x.Neigh.Remove(y);
            //        y.Neigh.Remove(x);
            //    }
            //    byNeighCount[x.Neigh.Count].Add(x);
            //    byNeighCount[y.Neigh.Count].Add(y);
            //};

            for (int i = 0; i < N - 1; i++)
            {
                var xy = Console.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
                if (xy.Length != 2)
                    throw new InvalidOperationException("Expected 2 items in line, actual count " + xy.Length);
                var x = int.Parse(xy[0], CultureInfo.InvariantCulture) - 1;
                var y = int.Parse(xy[1], CultureInfo.InvariantCulture) - 1;

                nodes[x].Neigh.Add(nodes[y]);
                nodes[y].Neigh.Add(nodes[x]);
            }

            for (int i = 0; i < N; i++)
                count[nodes[i].Neigh.Count]++;

            int result = 0;
            for (int i = N - 1; i > 3; i--)
            {
                if (count[i] > 0)
                {
                    count[3] += count[i];
                    result += count[i] * (i - 3);
                    count[i] = 0;
                }
            }

            if (count[2] == 0 && count[3] > 0)
            {
                result++;
                count[2]++;
                count[3]--;
            }

            if (count[2] > 1)
            {
                result += count[2] - 1;
                count[2] = 1;
            }

            Console.WriteLine("Case #{0}: {1}", t, result);
        }
    }
}

class Node
{
    public readonly HashSet<Node> Neigh = new HashSet<Node>();
}
