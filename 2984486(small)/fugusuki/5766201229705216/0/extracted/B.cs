using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    double Solve(List<int[]> _edge)
    {
        var flg = true;
        var result = 0;
        List<List<int>> edge = new List<List<int>>();
        for (int i = 0; i <= _edge.Count + 1; i++) edge.Add(new List<int>());
        foreach (var e in _edge)
        {
            edge[e[0]].Add(e[1]);
            edge[e[1]].Add(e[0]);
        }
        while (flg)
        {
            flg = false;
            int root = edge.Count(e => e.Count == 2);
            for (int i = 1; i < edge.Count; i++)
            {
                if (edge[i].Count == 1)
                {
                    int j = edge[i][0];
                    if (edge[j].Count != 3 && !(edge[j].Count == 2 && root == 1))
                    {
                        edge[j].Remove(i);
                        edge[i].Clear();
                        result++;
                        flg = true;
                        break;
                    }
                }
            }
        }
        return result;
    }

    static IEnumerable<string> Output()
    {
        yield return new B().Solve(Enumerable.Range(0, int.Parse(Console.ReadLine()) - 1).Select(line=>Console.ReadLine().Split(' ').Select(int.Parse).ToArray()).ToList()).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}