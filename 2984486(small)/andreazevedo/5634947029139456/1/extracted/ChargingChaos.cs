using System;
using System.Globalization;
using System.IO;
using System.Linq;

namespace Round1A.Console
{
    class ChargingChaos
    {
        static void Flip(char[][] outlets, int k)
        {
            for (int i = 0; i < outlets.Length; i++)
            {
                outlets[i][k] = outlets[i][k] == '0' ? '1' : '0';
            }
        }

        static bool Match(int n, int k, int len, char[][] a1, char[][] a2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = k; j < len; j++)
                {
                    if (a1[i][j] != a2[i][j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        static int Compare(char[] s1, char[] s2, int k)
        {
            for (int i = k; i < s1.Length; i++)
            {
                if (s1[i] != s2[i])
                {
                    return s1[i] - s2[i];
                }
            }

            return 0;
        }

        static long Solve(int n, int k, int len, char[][] outlets, char[][] devices)
        {
            Array.Sort(outlets, (c, c1) => Compare(c, c1, k+1));
            Array.Sort(devices, (c, c1) => Compare(c, c1, k+1));

            // early prunning
            if (!Match(n, k+1, len, outlets, devices))
            {
                return len + 1;
            }

            // base case
            if (k < 0)
            {
                return 0;
            }


            int o1 = 0; int o0 = 0; int d1 = 0; int d0 = 0;

            for (int i = 0; i < n; i++)
            {
                if (outlets[i][k] == '0') o0++; else o1++;
                if (devices[i][k] == '0') d0++; else d1++;
            }

            bool thisSide = false;
            int sidesToTry = 0;
            if (o0 == d0 && o1 == d1)
            {
                sidesToTry++;
                thisSide = true;
            }
            if (o0 == d1 && o1 == d0)
            {
                sidesToTry++;
            }



            long ans;
            if (sidesToTry == 0)
            {
                ans = len + 1;
            }
            else if (sidesToTry == 1)
            {
                if (thisSide)
                {
                    ans = Solve(n, k - 1, len, outlets, devices);
                }
                else
                {
                    Flip(outlets, k);
                    ans = 1 + Solve(n, k - 1, len, outlets, devices);
                    Flip(outlets, k);
                }
            }
            else // sidesToTry == 2
            {
                long noFlip = Solve(n, k - 1, len, outlets, devices);

                Flip(outlets, k);
                long flip = 1 + Solve(n, k - 1, len, outlets, devices);
                Flip(outlets, k);

                ans = Math.Min(noFlip, flip);
            }

            return ans;
        }

        static string Solve(string[] data)
        {
            string[] line1 = data[0].Split(' ');
            int n = Int32.Parse(line1[0]);
            int l = Int32.Parse(line1[1]);

            char[][] outlets = data[1].Split(' ').Select(s => s.ToCharArray()).ToArray();

            char[][] devices = data[2].Split(' ').Select(s => s.ToCharArray()).ToArray();

            long ans = Solve(n, l - 1, l, outlets, devices);

            if (ans > l)
            {
                return "NOT POSSIBLE";
            }

            return ans.ToString(CultureInfo.InvariantCulture);
        }

        static void Main(string[] args)
        {
            const string dir = "..\\..\\ChargingChaos\\";
            const string filename = "A-large";

            // Clean
            if (File.Exists(Path.Combine(dir, filename + ".out")))
            {
                File.Delete(Path.Combine(dir, filename + ".out"));
            }

            using (TextReader reader = File.OpenText(Path.Combine(dir, filename + ".in")))
            {
                int N = Int32.Parse(reader.ReadLine());
                using (TextWriter writer = File.CreateText(Path.Combine(dir, filename + ".out")))
                {
                    for (int i = 0; i < N; i++)
                    {
                        string[] data = new string[3];
                        data[0] = reader.ReadLine();
                        data[1] = reader.ReadLine();
                        data[2] = reader.ReadLine();

                        string ans = Solve(data);

                        string strRes = String.Format("Case #{0}: {1}", i + 1, ans);
                        writer.WriteLine(strRes);
                        System.Console.WriteLine(strRes);
                    }
                    writer.Close();
                }
                reader.Close();
            }
        }
    }
}
