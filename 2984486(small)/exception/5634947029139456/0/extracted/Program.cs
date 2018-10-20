using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace DirectorySize
{
    class Program
    {
        public static string xorIt(string key, string input, ref int val)
        {
            string sb = "";
            val = 0;
            for (int i = 0; i < input.Length; i++)
            {
                if (key[i] == input[i])
                    sb += "0";
                else
                {
                    sb += "1";
                    val++;
                }
            }

            return sb;
        }
        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("input.txt");
            TextWriter tw = new StreamWriter("output.txt");

            string input = null;

            input = tr.ReadLine();
            int T = int.Parse(input);
            for (int caseno = 1; caseno <= T; caseno++)
            {

                input = tr.ReadLine();
                string[] tokens;
                tokens = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                int N = int.Parse(tokens[0]);
                int L = int.Parse(tokens[1]);

                input = tr.ReadLine();
                string[] set1;
                set1 = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                Array.Sort(set1);

                input = tr.ReadLine();
                string[] set2;
                set2 = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                Array.Sort(set2);

                bool possible = false;
                int flips = 0;
                int final = 0;
                int minflips = int.MaxValue;

                int count1 = 0;
                for (int k = 0; k < N; k++)
                {
                    if (string.Compare(set1[k], set2[k]) == 0)
                        count1++;
                }
                if (count1 == N)
                {
                    possible = true;
                    minflips = Math.Min(minflips, final);
                }

                if (possible == false)
                {
                    for (int i = 0; i < N; i++)
                    {
                        string res = xorIt(set1[0], set2[i], ref flips);
                        final = flips;
                        string[] set3 = new string[N];
                        for (int j = 0; j < N; j++)
                        {
                            set3[j] = xorIt(res, set1[j], ref flips);
                        }
                        Array.Sort(set3);

                        int count = 0;
                        for (int k = 0; k < N; k++)
                        {
                            if (string.Compare(set2[k], set3[k]) == 0)
                                count++;
                        }
                        if (count == N)
                        {
                            possible = true;
                            minflips = Math.Min(minflips, final);
                        }
                    }
                }
                if (possible == false)
                    tw.WriteLine("Case #{0}: NOT POSSIBLE", caseno);
                else
                {                   
                    tw.WriteLine("Case #{0}: {1}", caseno, minflips);
                }

            }

            tr.Close();
            tw.Close();
        }

    }
}
