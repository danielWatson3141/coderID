using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using System.IO;

class Program
{

    static int[,] tree = new int[32, 32];
    static int[] degree = new int[32];
    static bool[] alive = new bool[32];
    static bool[] vis = new bool[32];

    static int n;
    static int best = 1234;

    static int get_deg( int node ){
        int cnt=0;
        for ( int i=0; i< degree[node]; i++ ){
            if ( alive[ tree[node,i] ]==true )
                cnt++;
        }

        return cnt;
    }

    static bool check_internal(int node)
    {
        if (vis[node] == true) return true;
        vis[node] = true;

        int d = get_deg(node);
        if (d != 3 && d != 1) return false;

        //bool res = true;
        for (int i = 0; i < degree[node]; i++)
        {
            if (alive[tree[node, i]] == true)
                if (check_internal(tree[node, i]) == false)
                    return false;
        }

        return true;
    }


    static bool check_root(int root)
    {
        if (alive[root] == false) return false;
        if (get_deg(root) != 2) return false;

        for (int i = 1; i <= n; i++) vis[i] = false;
        vis[root] = true;

        for (int i = 0; i < degree[root]; i++)
        {
            if (alive[tree[root, i]] == true)
                if (check_internal(tree[root, i]) == false)
                    return false;
        }

        for (int j = 1; j <= n; j++)
            if (alive[j] == true)
                if (vis[j] == false)
                    return false;

        return true;
    }

    static void recurse( int ind, int removed )
    {
        if (ind > n)
        {
            for ( int i=1; i<=n; i++ )
                if (check_root(i) == true)
                {
                    /*
                    Debug.WriteLine(string.Format("ind={0}, rem={1}", ind, removed));
                    for (int j = 1; j <= n; j++)
                        Debug.Write(alive[j].ToString() + ",");
                    Debug.WriteLine("");
                    for (int j = 1; j <= n; j++)
                        Debug.Write(vis[j].ToString() + ",");
                    Debug.WriteLine("");
                    */

                    best = Math.Min(best, removed);
                    break;
                }

            return;
        }

        if (removed > best) return;

        alive[ind] = true;
        recurse(ind + 1,removed);

        alive[ind] = false;
        recurse(ind + 1,removed+1);
    }
 
    static void Main(string[] args)
    {
        string prob = "Tree";

        TextReader input = new StreamReader(prob + ".in");
        TextWriter output = new StreamWriter(prob + ".out");

        int t, c = 0;
        t = Convert.ToInt32(input.ReadLine());

        for (c = 1; c <= t; c++)
        {
            string pre = string.Format("Case #{0}: ", c);
            string[] tokens = input.ReadLine().Split();
            n = Convert.ToInt32(tokens[0]);

            tree = new int[32, 32];
            degree = new int[32];
            alive = new bool[32];
            best = n-1;

            for (int i = 1; i < n; i++)
            {
                int x, y;
                tokens = input.ReadLine().Split();
                x=Convert.ToInt32(tokens[0]);
                y=Convert.ToInt32(tokens[1]);

                tree[x, degree[x]] = y;
                degree[x]++;

                tree[y, degree[y]] = x;
                degree[y]++;
            }

            Debug.WriteLine(pre);
            recurse(1,0);
            //if ( ans
            string ans = best.ToString();

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
