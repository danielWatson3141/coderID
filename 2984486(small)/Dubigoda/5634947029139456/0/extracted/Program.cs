using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamShite
{
    class Program
    {
        public static string ReplaceAt(string input, int index, char newChar)
        {
            if (input == null)
            {
                throw new ArgumentNullException("input");
            }
            char[] chars = input.ToCharArray();
            chars[index] = newChar;
            return new string(chars);
        }

        static void Main(string[] args)
        {
            StreamReader r = new StreamReader("A-small-attempt1.in");
            StreamWriter w = new StreamWriter("output.txt");

            int nCases = int.Parse(r.ReadLine());

            for (int i = 0; i < nCases; i++)
            {
                string first = r.ReadLine();
                int N = int.Parse(first.Split(' ')[0]);
                int L = int.Parse(first.Split(' ')[1]);

                string socketLine = r.ReadLine();
                string[] sockets = socketLine.Split(' ');
                
                string deviceLine = r.ReadLine();
                string[] devices = deviceLine.Split(' ');
                Array.Sort(devices, StringComparer.InvariantCulture); 

                /*bool[,] bSockets = new bool[N, L];
                bool[,] bDevices = new bool[N, L];

                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < L; k++)
                    {
                        bSockets[j, k] = (sockets[j][k] == '1');
                        bDevices[j, k] = (devices[j][k] == '1');
                    }
                }*/
                int minMoves = 9999;

                for (int j = 0; j < Math.Pow(2, L); j++)
                {
                    int moves = 0;
                    for (int k = 0; k < N; k++)
                    {
                        moves = 0;
                        for (int m = 0; m < L; m++)
                        {
                            
                            bool isSet = (j & (1 << m)) != 0;
                            if (isSet)
                            {
                                if (sockets[k][m] == '1') sockets[k] = ReplaceAt(sockets[k], m, '0');
                                else sockets[k] = ReplaceAt(sockets[k], m, '1');
                                moves++;
                            }
                        }
                    }

                    //check the solution is correct
                    Array.Sort(sockets, StringComparer.InvariantCulture);
                    bool fine = true;
                    for (int k = 0; k < N; k++)
                    {
                        if (!sockets[k].Equals(devices[k]))
                        {
                            fine = false;
                            break;
                        }
                    }

                    if (fine)
                    {
                        if (moves < minMoves) minMoves = moves;
                    }

                    if (minMoves == 1) break;

                    //revert sockets
                    for (int k = 0; k < N; k++)
                    {
                        for (int m = 0; m < L; m++)
                        {
                            bool isSet = (j & (1 << m)) != 0;
                            if (isSet)
                            {
                                if (sockets[k][m] == '1') sockets[k] = ReplaceAt(sockets[k], m, '0');
                                else sockets[k] = ReplaceAt(sockets[k], m, '1');
                            }
                        }
                    }
                }

                if (minMoves < 9999)
                    w.WriteLine("Case #" + (i + 1) + ": " + minMoves);
                else
                    w.WriteLine("Case #" + (i + 1) + ": NOT POSSIBLE");
            }
            w.Flush();
            w.Close();
            r.Close();
        }
    }
}
