using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        private static string INPUT_SMAPLE = @"Inputs\sample.in.txt";
        private static string INPUT_SAMLL = @"Inputs\A-small-attempt1.in";
        private static string INPUT_LARGE = @"Inputs\A-large.in";

        static void Main(string[] args)
        {
            StreamReader sReader = new StreamReader(INPUT_LARGE);
            StreamWriter sWriter = new StreamWriter(@"output.txt");

            int T = 0;

            try
            {
                string line = sReader.ReadLine();
                T = int.Parse(line);
            }
            catch (Exception e)
            {
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
            }

            // solve the problem!!!
            int N, L;
            int minimumFlips;
            
            Console.WriteLine("Problem A:");
            for (int t = 1; t <= T; t++)
            {
                minimumFlips = int.MaxValue;

                string line = sReader.ReadLine();
                string[] splits = line.Split(' ');
                N = int.Parse(splits[0]);
                L = int.Parse(splits[1]);

                ulong[] outlets = new ulong[N];
                ulong[] devices = new ulong[N];

                line = sReader.ReadLine();
                splits = line.Split(' ');
                for (int n = 0; n < N; n++)
                {
                    outlets[n] = Convert.ToUInt64(splits[n], 2);
                    //Console.WriteLine(outlets[n]);
                }

                line = sReader.ReadLine();
                splits = line.Split(' ');
                for (int n = 0; n < N; n++)
                {
                    devices[n] = Convert.ToUInt64(splits[n], 2);
                }

                Array.Sort(devices);

                // flip the switch to make one outlet able to charge one specfic device
                for (int n = 0; n < N; n++)
                {
                    ulong[] outletsFlipped = new ulong[N];
                    Array.Copy(outlets, outletsFlipped, outlets.Length);

                    int switchesFlipped = 0;
                    for (int l = 0; outletsFlipped[n] != devices[0] && l < L; l++)
                    {
                        ulong mask = ((ulong)1) << l;
                        if ((outletsFlipped[n] & mask) != (devices[0] & mask))
                        {
                            // a flip is required
                            switchesFlipped++;
                            for (int p = 0; p < N; p++)
                            {
                                if ((outletsFlipped[p] & mask) == mask)
                                {
                                    outletsFlipped[p] = outletsFlipped[p] & ~mask;
                                }
                                else
                                {
                                    outletsFlipped[p] = outletsFlipped[p] | mask;
                                }
                            }
                        }
                    }

                    //Console.Write("Outlets: ");
                    //for (int p = 0; p < N; p++)
                    //{
                    //    Console.Write(Convert.ToString((long)outletsFlipped[p], 2) + " ");
                    //}
                    //Console.WriteLine();


                    //Console.Write("Devices: ");
                    //for (int p = 0; p < N; p++)
                    //{
                    //    Console.Write(Convert.ToString((long)devices[p], 2) + " ");
                    //}
                    //Console.WriteLine();
                    //Console.WriteLine("Flipped: " + switchesFlipped);

                    bool impossible = false;
                    if (outletsFlipped[n] == devices[0] && switchesFlipped < minimumFlips)
                    {
                        // match is found, check all other devices
                        for (int p = 0; p < N; p++)
                        {
                            if (p == N)
                            {
                                continue;
                            }

                            int index = Array.BinarySearch(devices, outletsFlipped[p]);
                            if (index < 0)
                            {
                                // a match is not found
                                impossible = true;
                                break;
                            }
                        }
                        
                        // all matches
                        if (!impossible)
                        {
                            minimumFlips = switchesFlipped;
                        }
                    }
                }

                if (minimumFlips < int.MaxValue)
                {
                    Console.WriteLine(string.Format("Case #{0}: {1}", t, minimumFlips));
                    sWriter.WriteLine(string.Format("Case #{0}: {1}", t, minimumFlips));
                }
                else
                {
                    Console.WriteLine(string.Format("Case #{0}: NOT POSSIBLE", t));
                    sWriter.WriteLine(string.Format("Case #{0}: NOT POSSIBLE", t));
                }
            }

            sReader.Close();
            sWriter.Close();

            Console.WriteLine("----------------------------------");
            Console.WriteLine("done");
            Console.ReadKey();
        }
    }
}
