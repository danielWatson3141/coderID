using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using System.Linq;

class Scenario
{
    public int N;
    public int L;
    public char[][] D;
    public char[][] P;
}

internal class Program
{
    private const string Imp = "NOT POSSIBLE";
    private static void Main(string[] args)
    {
        if (args.Length != 1)
            throw new InvalidOperationException();

        string fileName = args[0];

        using (var sr = new StreamReader(fileName))
        using (var sw = new StreamWriter(fileName + ".out"))
        {
            int n = int.Parse(sr.ReadLine());
            for (int i = 0; i < n; i++)
            {
                var p = sr.ReadLine().Split().Select(l => int.Parse(l)).ToArray();
                var s = new Scenario() { N = p[0], L = p[1] };
                s.P = sr.ReadLine().Split().Select(l => l.ToCharArray()).ToArray();
                s.D = sr.ReadLine().Split().Select(l => l.ToCharArray()).ToArray();

                var r = Run(s);
                sw.WriteLine("Case #{0}: {1}", i + 1, r);
            }
        }


        Console.WriteLine("done");
        Console.ReadLine();
    }

    private static string Run(Scenario s)
    {
        var d = new HashSet<int>();
        var p = new HashSet<int>();
    
        for (int i = 0; i < s.N; i++)
        {
            int dv = 0, pv = 0;
            for (int j = 0; j < s.L; j++)
            {
                if (s.D[i][j] == '1')
                {
                    dv |= (1 << j);
                }
                if (s.P[i][j] == '1')
                {
                    pv |= (1 << j);
                }
            }
            if(p.Contains(pv))
                throw new InvalidOperationException();
            if (d.Contains(dv))
                throw new InvalidOperationException();
            d.Add(dv);
            p.Add(pv);
        }

        var m = (1 << s.L) - 1;

        int minChanges = int.MaxValue;

        for (int i = 0; i <= m; i++)
        {
            int changes = 0;
            for (int j = 0; j <= s.L; j++)
            {
                if ((i & (1 << j)) > 0)
                    changes++;
            }

            if (changes >= minChanges)
                continue;

            bool found = true;
            foreach (var pv in p)
            {
                var x = pv ^ i;

                if (!d.Contains(x))
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                if (changes < minChanges)
                    minChanges = changes;
            }
        }

        if (minChanges == int.MaxValue)
            return Imp;

        return minChanges.ToString();
    }
}
