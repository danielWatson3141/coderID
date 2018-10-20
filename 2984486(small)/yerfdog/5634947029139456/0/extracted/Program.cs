using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj14r1a
{
    class Program2
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\A1.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\A1.out");
            for (int a = 0; a < t; a++)
            {
                string[] line = lines[idx++].Split(' ');
                int n = int.Parse(line[0]);
                int l = int.Parse(line[1]);
                string[] switches = lines[idx++].Split(' ');
                string[] constant = lines[idx++].Split(' ');
                int ans = -1;
                for (int i = 0; i < Math.Pow(2, l); i++)
                {
                    string bits = Convert.ToString(i, 2) ?? "0";
                    string[] switches2 = new string[n];
                    Array.Copy(switches, switches2, n);
                    int curans = 0;
                    for (int j = 0; j < l; j++)
                    {
                        if (j< bits.Length && bits[bits.Length - 1 - j] == '1')
                        {
                            curans++;
                            for (int k = 0; k < n; k++)
                            {
                                StringBuilder sb = new StringBuilder(switches2[k]);
                                char next = switches2[k][j];
                                if (next == '1')
                                {
                                    sb[j] = '0';
                                }
                                else
                                {
                                    sb[j] = '1';
                                }
                                switches2[k] = sb.ToString();
                            }
                        }
                    }
                    if (matches(constant, switches2, 0, new bool[n]))
                    {
                        if (curans < ans || ans == -1)
                        {
                            ans = curans;
                        }
                    }
                }
                if (ans >= 0)
                {
                    tw.WriteLine("Case #{0}: {1}", a + 1, ans);
                }
                else
                {
                    tw.WriteLine("Case #{0}: NOT POSSIBLE", a + 1);
                }
            }
            tw.Close();
        }

        private static bool matches(string[] constant, string[] switches2, int index, bool[] notused)
        {
            if (index == switches2.Length)
            {
                return true;
            }
            for(int a =0; a< switches2.Length; a++){
                if (!notused[a] && constant[index] == switches2[a])
                {
                    notused[a] = true;
                    if (matches(constant, switches2, index + 1, notused))
                    {
                        return true;
                    }
                    notused[a] = false;
                }
            }
            return false;
        }
    }
}
