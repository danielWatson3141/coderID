using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    int Solve(int L, long[] outlets, long[] devices)
    {
        return Enumerable.Range(0, 1 << L).Min(mask =>
            outlets.Select(o => o ^ mask).Except(devices).Any() ? int.MaxValue : BitCount(mask)
        );
    }

    static int BitCount(long x)
    {
        int ret = 0;
        for (; x != 0; x >>= 1) if ((x & 1) != 0) ret++;
        return ret;
    }

    static long ParseBit(string s)
    {
        return Enumerable.Range(0, s.Length).Sum(i => s[i] == '0' ? 0 : 1 << (s.Length - i - 1));
    }

    static IEnumerable<string> Output()
    {
        int ret = new A().Solve(Console.ReadLine().Split(' ').Select(int.Parse).Skip(1).First(), Console.ReadLine().Split(' ').Select(ParseBit).ToArray(), Console.ReadLine().Split(' ').Select(ParseBit).ToArray());
        yield return ret == int.MaxValue ? "NOT POSSIBLE" : ret.ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}