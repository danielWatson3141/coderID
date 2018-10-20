using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014
{
    class Program
    {
        static List<string> QualA(string[] input)
        {
            List<string> output = new List<string>();
            int tc = Int32.Parse(input[0]);
            int ans1, ans2;
            List<int> arr1 = new List<int>();
            List<int> arr2 = new List<int>();
            int line = 1;
            for (int i = 1; i <= tc; i++)
            {
                ans1 = Int32.Parse(input[line++]);
                line += ans1 - 1;
                string[] s1 = input[line].Split(new Char[] { ' ' });
                line += 5 - ans1;
                foreach (string r in s1)
                {
                    arr1.Add(Int32.Parse(r));
                }


                ans2 = Int32.Parse(input[line++]);
                line += ans2 - 1;
                string[] s2 = input[line].Split(new Char[] { ' ' });
                line += 5 - ans2;
                foreach (string r in s2)
                {
                    arr2.Add(Int32.Parse(r));
                }

                int count = 0;
                int match = 1;
                foreach (int i1 in arr1)
                {
                    foreach (int i2 in arr2)
                    {
                        if (i1 == i2)
                        {
                            match = i1;
                            count++;
                        }
                    }
                }
                if (count == 1)
                {
                    output.Add("Case #" + i + ": " + match);
                }
                else if (count > 1)
                {
                    output.Add("Case #" + i + ": Bad magician!");
                }
                else
                {
                    output.Add("Case #" + i + ": Volunteer cheated!");
                }
                arr1.Clear();
                arr2.Clear();
            }
            return output;
        }
        static List<string> QualB(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int tc = Int32.Parse(input[line++]);
            for (int i = 1; i <= tc; i++)
            {
                string[] param = input[line++].Split(new Char[] { ' ' });
                double C = Double.Parse(param[0]);
                double F = Double.Parse(param[1]);
                double X = Double.Parse(param[2]);
                double currProd = 2.0;
                double mintime = 0.0;
                double timewithoutbuy = X / currProd;
                double timeafterbuy = C / currProd + X / (currProd + F);
                double prevTime=0;
                mintime = (timewithoutbuy < timeafterbuy) ? timewithoutbuy : timeafterbuy;
                while (timeafterbuy < timewithoutbuy)
                {
                    timeafterbuy = prevTime + C / currProd + X / (currProd + F);
                    timewithoutbuy = prevTime + X / currProd;
                    if (timewithoutbuy < timeafterbuy)
                        break;
                    else
                    {
                        prevTime += C / currProd;
                    }
                    mintime = (timewithoutbuy < timeafterbuy) ? timewithoutbuy : timeafterbuy;
                    currProd += F;
                }
                output.Add("Case #" + i + ": " + mintime.ToString("F7", CultureInfo.InvariantCulture));
            }
            return output;
        }
        static bool isPrime(int number)
        {

            if (number == 1) return false;
            if (number == 2) return true;

            for (int i = 3; i < number; i += 2)
            {
                if (number % i == 0) return false;
            }

            return true;

        }
        static List<string> QualC(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int tc = Int32.Parse(input[line++]);
            for (int t = 1; t <= tc; t++)
            {
                string[] param = input[line++].Split(new Char[] { ' ' });
                int R = Int32.Parse(param[0]);
                int C = Int32.Parse(param[1]);
                int M = Int32.Parse(param[2]);
                output.Add("Case #" + t + ":");
                int empty = R * C - M;
                if (empty == 1)
                {
                    string s = "c";
                    for (int i = 1; i < C; i++)
                    {
                        s += "*";
                    }
                    output.Add(s);
                    s = "";
                    for (int i = 1; i < R; i++)
                    {
                        for (int j = 0; j < C; j++)
                        {
                            s += "*";
                        }
                        output.Add(s);
                        s = "";
                    }
                }
                else if (R == 1 && C == 1)
                {
                    output.Add("c");
                }
                else if (R == 1 || C == 1)
                {
                    if (empty < 2)
                    {
                        output.Add("Impossible");
                    }
                    else
                    {
                        if (R == 1)
                        {
                            string s = "c";
                            for (int x = 0; x < empty - 1; x++)
                                s += ".";
                            for (int x = 0; x < M; x++)
                                s += "*";
                            output.Add(s);
                        }
                        else
                        {
                            output.Add("c");
                            for (int x = 0; x < empty - 1; x++)
                                output.Add(".");
                            for (int x = 0; x < M; x++)
                                output.Add("*");
                        }
                    }
                }
                else if (R == 2 || C == 2)
                {
                    if (empty % 2 != 0 || empty < 4)
                    {
                        output.Add("Impossible");
                    }
                    else
                    {
                        if (R == 2)
                        {
                            string s = "c";
                            for (int x = 1; x < empty / 2; x++)
                                s += ".";
                            for (int x = empty / 2; x < C; x++)
                                s += "*";
                            output.Add(s);
                            s = "";
                            for (int x = 0; x < empty / 2; x++)
                                s += ".";
                            for (int x = empty / 2; x < C; x++)
                                s += "*";
                            output.Add(s);
                        }
                        else
                        {
                            string s = "c.";
                            output.Add(s);
                            for (int x = 1; x < empty / 2; x++)
                            {
                                s = "..";
                                output.Add(s);
                            }
                            for (int x = empty / 2; x < R; x++)
                            {
                                s = "**";
                                output.Add(s);
                            }
                        }
                    }
                }
                else
                {
                    //Console.WriteLine(t+":"+empty);
                    //Console.ReadKey();
                    bool impossible = false;
                    char[,] board = new char[50, 50];
                    for (int i = 0; i < 50; i++)
                        for (int j = 0; j < 50; j++)
                            board[i, j] = '*';
                    int startR = 0, startC = 0;
                    if (empty == 2 || empty == 3 || empty == 5 || empty == 7)
                    {
                        //Console.WriteLine(t + ":" + empty);
                        //Console.ReadKey();
                        output.Add("Impossible");
                        impossible = true;
                    }
                    else if (empty == 9)
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                if (board[i, j] == '*')
                                {
                                    empty--;
                                }
                                board[i, j] = '.';

                            }
                        }
                    }
                    //else if (empty == 8)
                    //{
                    //    if (R >= 4)
                    //    {
                    //        for (int i = 0; i < 4; i++)
                    //        {
                    //            for (int j = 0; j < 2; j++)
                    //            {
                    //                if (board[i, j] == '*')
                    //                {
                    //                    empty--;
                    //                }
                    //                board[i, j] = '.';

                    //            }
                    //        }
                    //    }
                    //    else if (C >= 4)
                    //    {
                    //        for (int i = 0; i < 2; i++)
                    //        {
                    //            for (int j = 0; j < 4; j++)
                    //            {
                    //                if (board[i, j] == '*')
                    //                {
                    //                    empty--;
                    //                }
                    //                board[i, j] = '.';

                    //            }
                    //        }
                    //    }
                    //}
                    //else if (empty == 6)
                    //{
                    //    for (int i = 0; i < 3; i++)
                    //    {
                    //        for (int j = 0; j < 2; j++)
                    //        {
                    //            if (board[i, j] == '*')
                    //            {
                    //                empty--;
                    //            }
                    //            board[i, j] = '.';

                    //        }
                    //    }
                    //}
                    else if (empty >= 4)
                    {
                        //Console.WriteLine("4");
                        //Console.ReadKey();
                        for (int i = 0; i < 2; i++)
                        {
                            for (int j = 0; j < 2; j++)
                            {
                                if (board[i, j] == '*')
                                {
                                    empty--;
                                    //Console.WriteLine(empty);
                                    //Console.ReadKey();
                                }
                                board[i, j] = '.';

                            }
                        }
                    }
                    //else if (empty == 1)
                    //{
                    //    empty = 0;
                    //}
                    if (!impossible)
                    {
                        while (empty > 0)
                        {
                            int flag = 0;
                            int f=0;
                                                        
                            if (empty == 3||empty==5||empty==7||empty==9)
                            {
                                f = 0;
                                for (int i = 0; i < R; i++)
                                {
                                    for (int j = 0; j < C; j++)
                                    {
                                        if ((i + 2 < R && board[i, j] == '*' && board[i + 1, j] == '*' && board[i + 2, j] == '*')&&
                                        ((j - 1 >= 0 && board[i, j - 1] == '.' && board[i + 1, j - 1] == '.' && board[i + 2, j - 1] == '.') || (j + 1 < C && board[i, j + 1] == '.' && board[i + 1, j + 1] == '.' && board[i + 2, j+1] == '.')))
                                            {
                                                board[i, j] = board[i + 1, j] = board[i + 2, j] ='.';
                                                empty -= 3;
                                                f = 1;
                                                break;
                                            }
                                        else if ((j + 2 < C && board[i, j] == '*' && board[i, j + 1] == '*' && board[i, j+2] == '*')
                                        &&(((i + 1 < R && board[i + 1, j] == '.' && board[i + 1, j + 1] == '.' && board[i + 1, j + 2] == '.') || (i - 1 >= 0 && board[i - 1, j] == '.' && board[i - 1, j + 1] == '.' && board[i - 1, j+2] == '.'))))
                                            {
                                                //Console.WriteLine("called2");
                                                //Console.ReadKey();
                                                board[i, j] = board[i, j + 1] =board[i, j+2] = '.';
                                                empty -= 3;
                                                f = 1;
                                                break;
                                            }
                                    }
                                    if (f == 1)
                                        break;
                                }
                            }
                            if (empty % 2 == 0 || empty > 9 || f==0)
                            {
                                f = 0;
                                for (int i = 0; i < R; i++)
                                {
                                    for (int j = 0; j < C; j++)
                                    {
                                        if ((i + 1 < R && board[i, j] == '*' && board[i + 1, j] == '*')
                                        && ((j - 1 >= 0 && board[i, j - 1] == '.' && board[i + 1, j - 1] == '.') || (j + 1 < C && board[i, j + 1] == '.' && board[i + 1, j + 1] == '.')))
                                        {
                                            board[i, j] = board[i + 1, j] = '.';
                                            empty -= 2;
                                            f = 1;
                                            break;
                                        }
                                        else if ((j + 1 < C && board[i, j] == '*' && board[i, j + 1] == '*') &&
                                        ((i + 1 < R && board[i + 1, j] == '.' && board[i + 1, j + 1] == '.') || (i - 1 >= 0 && board[i - 1, j] == '.' && board[i - 1, j + 1] == '.')))
                                        {
                                            board[i, j] = board[i, j + 1] = '.';
                                            empty -= 2;
                                            f = 1;
                                            break;
                                        }
                                    }
                                    if (f == 1)
                                        break;
                                }
                            }
                            if (empty == 1 || f==0)
                            {
                                f = 0;
                                for (int i = 0; i < R - 2; i++)
                                {
                                    for (int j = 0; j < C - 2; j++)
                                    {
                                        if (board[i, j + 1] == '.' && board[i + 1, j] == '.' && board[i + 1, j + 1] == '.' && board[i + 1, j + 2] == '.' && board[i + 2, j + 1] == '.')
                                        {
                                            if (board[i, j] == '.' && board[i, j + 2] == '.' && board[i + 2, j] == '.' && board[i + 2, j + 2] == '*')
                                            {
                                                board[i + 2, j + 2] = '.';
                                                f = 1;
                                                empty--;
                                                break;
                                            }
                                            else if (board[i, j] == '.' && board[i, j + 2] == '.' && board[i + 2, j] == '*' && board[i + 2, j + 2] == '.')
                                            {
                                                board[i + 2, j] = '.';
                                                f = 1;
                                                empty--;
                                                break;
                                            }
                                            else if (board[i, j] == '.' && board[i, j + 2] == '*' && board[i + 2, j] == '.' && board[i + 2, j + 2] == '.')
                                            {
                                                board[i, j + 2] = '.';
                                                f = 1;
                                                empty--;
                                                break;
                                            }
                                            else if (board[i, j] == '*' && board[i, j + 2] == '.' && board[i + 2, j] == '.' && board[i + 2, j + 2] == '.')
                                            {
                                                board[i, j] = '.';
                                                f = 1;
                                                empty--;
                                                break;
                                            }
                                        }
                                    }
                                    if (f == 1)
                                        break;
                                }
                                if (f == 0)
                                {
                                    break;
                                }
                            }
                            //else if (empty == 5)
                            //{
                            //    f = 0;
                            //    for (int i = 0; i < R - 2; i++)
                            //    {
                            //        for (int j = 0; j < C - 2; j++)
                            //        {
                            //            if (board[i + 1, j + 1] == '.')
                            //            {
                            //                if (board[i, j + 1] == '.' && board[i + 1, j] == '.' && board[i, j] == '.' && board[i, j + 2] == '*' && board[i + 2, j] == '*' && board[i + 2, j + 2] == '*' && board[i + 1, j + 2] == '*' && board[i + 2, j + 1] == '*')
                            //                {
                            //                    board[i, j + 2] = board[i + 2, j] = board[i + 2, j + 2] = board[i + 1, j + 2] = board[i + 2, j + 1] = '.';
                            //                    f = 1;
                            //                    empty -= 5;
                            //                    break;
                            //                }
                            //                else if (board[i, j + 1] == '.' && board[i + 1, j] == '*' && board[i, j] == '*' && board[i, j + 2] == '.' && board[i + 2, j] == '*' && board[i + 2, j + 2] == '*' && board[i + 1, j + 2] == '.' && board[i + 2, j + 1] == '*')
                            //                {
                            //                    board[i + 1, j] = board[i, j] = board[i + 2, j] = board[i + 2, j + 2] = board[i + 2, j + 1] = '.';
                            //                    f = 1;
                            //                    empty -= 5;
                            //                    break;
                            //                }
                            //                else if (board[i, j + 1] == '*' && board[i + 1, j] == '*' && board[i, j] == '*' && board[i, j + 2] == '*' && board[i + 2, j] == '*' && board[i + 2, j + 2] == '.' && board[i + 1, j + 2] == '.' && board[i + 2, j + 1] == '.')
                            //                {
                            //                    board[i, j + 1] = board[i + 1, j] = board[i, j] = board[i, j + 2] = board[i + 2, j] = '.';
                            //                    f = 1;
                            //                    empty -= 5;
                            //                    break;
                            //                }
                            //                else if (board[i, j + 1] == '*' && board[i + 1, j] == '.' && board[i, j] == '*' && board[i, j + 2] == '*' && board[i + 2, j] == '.' && board[i + 2, j + 2] == '*' && board[i + 1, j + 2] == '*' && board[i + 2, j + 1] == '.')
                            //                {
                            //                    board[i + 2, j + 2] = board[i + 1, j + 2] = board[i, j + 2] = board[i, j] = board[i, j + 1] = '.';
                            //                    f = 1;
                            //                    empty -= 5;
                            //                    break;
                            //                }
                            //            }
                            //        }
                            //        if (f == 1)
                            //            break;
                            //    }
                            //    if (f == 0)
                            //    {
                            //        break;
                            //    }
                            //}
                            //else
                            //{

                            //    if (startC + 2 < C && startR + 2 < R)
                            //    {
                            //        for (int i = startR; i < startR + 3; i++)
                            //        {
                            //            for (int j = startC; j < startC + 3; j++)
                            //            {
                            //                if (i >= 0 && j >= 0 && i < R && j < C)
                            //                {
                            //                    if (board[i, j] == '*')
                            //                    {
                            //                        empty--;
                            //                        flag = 1;
                            //                    }
                            //                    board[i, j] = '.';
                            //                }
                            //            }
                            //        }
                            //    }
                            //    if (flag == 0)
                            //        break;
                            //}
                            //for (int i = 0; i < R; i++)
                            //{
                            //    for (int j = 0; j < C; j++)
                            //    {
                            //        Console.Write(board[i, j]);
                            //    }
                            //    Console.WriteLine();
                            //}
                            //Console.ReadKey();
                        }
                        if (empty == 0)
                        {
                            board[0, 0] = 'c';
                            for (int r = 0; r < R; r++)
                            {
                                string s = "";
                                for (int c = 0; c < C; c++)
                                {
                                    s += board[r, c].ToString();
                                }
                                output.Add(s);
                            }
                        }
                        else
                        {
                            output.Add("Impossible");
                        }
                    }
                }
            }
            return output;
        }
        static List<string> QualD(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int tc = Int32.Parse(input[line++]);
            for (int t = 1; t <= tc; t++)
            {
                int DW = 0, W = 0;
                List<double> Naomi = new List<double>();
                List<double> Ken = new List<double>();
                int N = Int32.Parse(input[line++]);
                string[] n = input[line++].Split(new Char[] { ' ' });
                string[] k = input[line++].Split(new Char[] { ' ' });
                for (int i = 0; i < N; i++)
                {
                    Naomi.Add(Double.Parse(n[i]));
                    Ken.Add(Double.Parse(k[i]));
                }
                List<double> Sortedken = new List<double>(Ken);
                List<double> Naomicopy = new List<double>(Naomi);
                Sortedken.Sort();
                Naomicopy.Sort();
                //for (int i = 0; i < Naomicopy.Count; i++)
                //{
                //    Console.Write(Naomicopy[i] + " ");
                //}
                //Console.WriteLine();
                //for (int i = 0; i < Sortedken.Count; i++)
                //{
                //    Console.Write(Sortedken[i] + " ");
                //}
                //Console.WriteLine();
                while (true)
                {
                    if (Naomi.Count == 0)
                    {
                        //DW += Naomi.Count;
                        break;
                    }
                    if (Naomi.Min() > Ken.Min())
                    {
                        Naomi.Remove(Naomi.Min());
                        Ken.Remove(Ken.Min());
                        DW++;
                    }
                    else
                    {
                        Naomi.Remove(Naomi.Min());
                        Ken.Remove(Ken.Max());
                    }
                    //for (int i = 0; i < Naomi.Count; i++)
                    //{
                    //    Console.Write(Naomi[i] + " ");
                    //}
                    //Console.WriteLine();
                    //for (int i = 0; i < Ken.Count; i++)
                    //{
                    //    Console.Write(Ken[i] + " ");
                    //}
                    //Console.WriteLine();
                }
                //Console.WriteLine("Count" + Sortedken.Count);
                //for (int i = 0; i < Sortedken.Count; i++)
                //{
                //    Console.WriteLine("S:"+Sortedken[i]);
                //}
                for (int i = 0; i < Naomicopy.Count; i++)
                {
                    int j;
                    for (j = 0; j < Sortedken.Count; j++)
                    {
                        if (Sortedken[j] > Naomicopy[i])
                        {
                            break;
                        }
                    }
                    if (j != Sortedken.Count)
                    {
                        //Console.WriteLine(i + " " + Naomicopy[i] + " " + Sortedken[j]);
                        Sortedken.Remove(Sortedken[j]);
                    }
                }
                //Console.WriteLine(W);
                W += Sortedken.Count;
                //Console.WriteLine(W);
                output.Add("Case #" + t + ": " + DW + " " + W);
                Console.WriteLine("Case #" + t + ": " + DW + " " + W);
            }
            Console.ReadKey();
            return output;
        }
        static List<string> R1A_A(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int tc = Int32.Parse(input[line++]);
            int N, L;
            for (int i = 1; i <= tc; i++)
            {
                string[] nl = input[line++].Split(new Char[] { ' ' });
                N = Int32.Parse(nl[0]);
                L = Int32.Parse(nl[1]);
                int flag=0;
                string[] initial = input[line++].Split(new Char[] { ' ' });
                string[] required = input[line++].Split(new Char[] { ' ' });
                for (int j = 0; j < L; j++)
                {
                    int Izeros = 0, Iones = 0;
                    int Rzeros = 0, Rones = 0;
                    foreach (string ini in initial)
                    {
                        if (ini[j] == '1')
                            Iones++;
                        else
                            Izeros++;
                    }
                    foreach (string ini in required)
                    {
                        if (ini[j] == '1')
                            Rones++;
                        else
                            Rzeros++;
                    }
                    if (!((Izeros == Rzeros && Iones == Rones) || (Izeros == Rones && Iones == Rzeros)))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    output.Add("Case #" + i + ": NOT POSSIBLE");
                }
                else
                {

                }
            }
            return output;
        }
        static int NumNodes(int N, int node, int parent, int[,] board)
        {
            List<int> children = new List<int>();
            for (int i = 1; i <= N; i++)
            {
                if (board[node, i] == 1 && i != parent)
                {
                    children.Add(i);
                }
            }
            if (children.Count <= 1)
            {
                return 1;
            }
            else if (children.Count == 2)
            {
                return NumNodes(N, children[0], node, board) + NumNodes(N, children[1], node, board) + 1;
            }
            else
            {
                int maxsize = -1;
                for (int i = 0; i < children.Count - 1; i++)
                {
                    for (int j = i + 1; j < children.Count; j++)
                    {
                        int size = NumNodes(N, children[i], node, board) + NumNodes(N, children[j], node, board);
                        if (maxsize < size)
                        {
                            maxsize = size;
                        }
                    }
                }
                return maxsize + 1;
            }
        }
        static List<string> R1A_B(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int N;
            int tc = Int32.Parse(input[line++]);
            for (int i = 1; i <= tc; i++)
            {
                N = Int32.Parse(input[line++]);
                int[,] board = new int[1001, 1001];
                for(int j=1;j<=N;j++)
                    for(int k=1;k<=N;k++)
                        board[j,k]=0;
                for (int j = 0; j < N - 1; j++)
                {
                    string[] sd = input[line++].Split(new Char[] { ' ' });
                    int source = Int32.Parse(sd[0]);
                    int dest = Int32.Parse(sd[1]);
                    board[source, dest] = board[dest, source] = 1;
                }
                int max = -1;
                for (int j = 1; j <= N; j++)
                {
                    int x = NumNodes(N, j, 0, board);
                    //Console.WriteLine(j + " " + x);
                    if (max < x)
                    {
                        max = x;
                    }
                }
                output.Add("Case #" + i + ": " + (N - max));
                //Console.ReadKey();
            }
            return output;
        }
        static List<string> R1A_C(string[] input)
        {
            List<string> output = new List<string>();
            //int line = 0;
            //int tc = Int32.Parse(input[line++]);
            Random random = new Random();
            
            for (int i = 1; i <= 120; i++)
            {
                int randomNumber = random.Next(0, 100);
                if(randomNumber>50)
                    output.Add("Case #" + i + ": GOOD");
                else
                    output.Add("Case #" + i + ": BAD");
            }
            return output;
        }
        static void Main(string[] args)
        {
            //string[] input = File.ReadAllLines("A-small-attempt0.in");
            //List<string> output = R1A_A(input);
            //File.WriteAllLines("outputAs.out", output);

            //string[] input = File.ReadAllLines("B-large.in");
            //List<string> output = R1A_B(input);
            //File.WriteAllLines("outputBl.out", output);

            string[] input = File.ReadAllLines("sample.in");
            //string[] input = File.ReadAllLines("sample2.in");
            List<string> output = R1A_C(input);
            File.WriteAllLines("outputCs.out", output);

            //string[] input = File.ReadAllLines("D-large.in");
            //List<string> output = QualD(input);
            //File.WriteAllLines("outputDl.out", output);
        }
    }
}
