using System;
using System.Collections.Generic;
using System.Linq;

class C
{
    static int test = 0;
    bool Solve(int[] num)
    {
        if (num.Where((i, j) => i == j).Count() > 1 || num.Take(800).Where((i, j) => i == j).Count() > 0)
        {
            test++;
            return true;
        }
        else return false;
    }

    static IEnumerable<string> Output()
    {
        Console.ReadLine();
        yield return new C().Solve(Console.ReadLine().Split(' ').Select(int.Parse).ToArray()) ? "GOOD" : "BAD";
    }
    static void Main()
    {
        foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray()));
    }
}