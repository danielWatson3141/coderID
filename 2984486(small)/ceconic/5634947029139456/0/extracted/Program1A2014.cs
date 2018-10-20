using System;
using System.IO;
using System.Linq;

namespace GoogleCode
{
    partial class Program
    {
        public static void ChargingChaos()
        {
            string[] lines = File.ReadAllLines(@"C:\temp\A-small-attempt1.in");

            int cases;
            int.TryParse(lines[0], out cases);

            string[] responses;
            responses = new string[cases];

            for (int c = 0; c < cases; c++)
            {
                string NLs = lines[3 * c + 1];

                int N = int.Parse(NLs.Split(' ')[0]);
                int L = int.Parse(NLs.Split(' ')[1]);

                string[] outlets = lines[3 * c + 2].Split(' ');
                string[] devices = lines[3 * c + 3].Split(' ');

                var intersect = outlets.Intersect(devices);

                string response = string.Empty;

                if (intersect.Count() == N)
                {
                    response = "0";
                }
                else
                {
                    bool found = true;

                    int min = L;

                    int switches = 0;

                    for (int n = 1; n < Math.Pow(2, L); n++)
                    {
                        char[] value = Convert.ToString(n, 2).PadLeft(L, '0').ToCharArray();

                        string[] test = new string[outlets.Length];

                        Array.Copy(outlets, test, outlets.Length);

                        for (int i = 0; i < N; i++)
                        {
                            char[] outlet = test[i].ToCharArray();

                            for (int j = 0; j < L; j++)
                            {
                                if (value[j] == '1')
                                {
                                    if (outlet[j] == '0')
                                        outlet[j] = '1';
                                    else
                                        outlet[j] = '0';
                                }
                            }

                            test[i] = new string(outlet);
                        }

                        intersect = test.Intersect(devices);

                        if (intersect.Count() == N)
                        {
                            switches = value.Count(f => f == '1');

                            if (switches < min)
                                min = switches;
                        }
                    }

                    if (switches == 0)
                        response = "NOT POSSIBLE";
                    else
                        response = min.ToString();
                }

                responses[c] = "Case #" + (c + 1).ToString() + ": " + response;
            }

            File.WriteAllLines(@"C:\temp\A-small-attempt1.out", responses);
        }
    }
}
