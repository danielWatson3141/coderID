using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using System.IO;

class Program
{
    static int n, l;
    static List<string> have, want;
    static List<int> haveTot, wantTot;
    static int found = 10001;

    static char[,] haveBits = new char[256, 256];
    static char[,] wantBits = new char[256, 256];

    static void check(int ind, int flips)
    {
        //Debug.WriteLine(string.Format("ind={0}, flips={1}", ind, flips));

        if (ind == l)
        {
            
            List<string> res = new List<string>();
            for (int i = 0; i < n; i++)
            {
                string cur = "";
                for (int j = 0; j < l; j++)
                    cur += haveBits[i,j];
                res.Add(cur);
            }

            res.Sort();

            /*
            Console.WriteLine("RES:");
            res.ForEach(Console.WriteLine);
            Console.WriteLine("");
            */

            bool match = true;

            for (int i = 0; i < n; i++)
                if (res[i] != want[i])
                {
                    match = false;
                    break;
                }

            if (match == true)
                found = Math.Min( found, flips );
            return;
        }
        if (flips > found) return;
        //if (found != -1) return;

        if (haveTot[ind] == wantTot[ind])
        {
            /*
            bool match = true;

            for ( int i=0; i<n; i++ )
                if (have[i][ind] != want[i][ind])
                {
                    match = false;
                    break;
                }

            if ( match==true )*/
                check(ind + 1, flips);
            //return;
        }

        if (n-haveTot[ind] == wantTot[ind])
        {
            /*
            bool match = true;

            for (int i = 0; i < n; i++)
                if (have[i][ind] == want[i][ind])
                {
                    match = false;
                    break;
                }

            Debug.WriteLine(string.Format("ind={0}, match={1}", ind, match));

            if (match == true)
            {*/
                for (int i = 0; i < n; i++)
                    if (haveBits[i,ind] == '0')
                        haveBits[i,ind] = '1';
                    else
                        haveBits[i,ind] = '0';

                check(ind + 1, flips + 1);

                for (int i = 0; i < n; i++)
                    if (haveBits[i, ind] == '0')
                        haveBits[i, ind] = '1';
                    else
                        haveBits[i, ind] = '0';
            //}
        }
    }

    static void Main(string[] args)
    {
        string prob = "Charging";

        TextReader input = new StreamReader(prob + ".in");
        TextWriter output = new StreamWriter(prob + ".out");

        have=new List<string>();
        want=new List<string>();
        haveTot = new List<int>();
        wantTot = new List<int>();

        int t, c = 0;
        t = Convert.ToInt32(input.ReadLine());

        for (c = 1; c <= t; c++)
        {
            string pre = string.Format("Case #{0}: ", c);
            string[] tokens = input.ReadLine().Split();
            n = Convert.ToInt32(tokens[0]);
            l = Convert.ToInt32(tokens[1]);

            found = 10001;
            have.Clear();
            want.Clear();
            haveTot.Clear();
            wantTot.Clear();

            tokens = input.ReadLine().Split();
            for (int i = 0; i < n; i++ )
                have.Add(tokens[i]);
            
            tokens = input.ReadLine().Split();
            for (int i = 0; i < n; i++ )
                want.Add(tokens[i]);

            //Debug.WriteLine("\n"+pre);
            want.Sort();
            have.Sort();

            /*
            have.ForEach(Console.WriteLine);
            Console.WriteLine("");
            want.ForEach(Console.WriteLine);
            Console.WriteLine("");
             */

            for (int i = 0; i < l; i++)
            {
                int sumH = 0;
                int sumW = 0;
                for (int j = 0; j < n; j++)
                {
                    haveBits[j,i] = have[j][i];
                    wantBits[j, i] = want[j][i];
                    sumH += have[j][i]-'0';
                    sumW += want[j][i]-'0';
                }
                haveTot.Add(sumH);
                wantTot.Add(sumW);
                //Debug.WriteLine(string.Format("i={0}, H={1}, W={2}", i, sumH, sumW));
            }

            check(0,0);
            string ans = "NOT POSSIBLE";
            if (found < 10001)
                ans = found.ToString();
            output.WriteLine(pre + ans);
            Console.WriteLine(pre + ans);
        }

        // close the streams
        output.Close();
        input.Close();

        Console.WriteLine("\n*DONE*");
        Console.ReadKey();
    }
}
