using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            Problem p1 = new Problem();
            p1.solve();
            Console.Read();
        }
    }
    public class Problem
    {
        static List<string> cpy;
        static int cnt, rws, cols;
        private int testcases = 0;
        public void solve()
        {
            int rows = 0;
            int switches = 0;
            List<int> res = new List<int>();
            System.IO.StreamWriter fileresult = new System.IO.StreamWriter(@"E:\CODE JAM\Round1\first_r1\ConsoleApplication2\output.txt");
            System.IO.StreamReader file = new System.IO.StreamReader(@"E:\CODE JAM\Round1\first_r1\ConsoleApplication2\input.txt");
            testcases = Convert.ToInt32(file.ReadLine());
            Console.WriteLine("started test cases are:-" + testcases);
            for (int i = 0; i < testcases; i++)
            {
                cnt = 0;
                List<string> t1 = file.ReadLine().Split(' ').ToList();
                rows = Convert.ToInt32(t1[0]);
                switches = Convert.ToInt32(t1[1]);
                List<string> inp = file.ReadLine().Split(' ').ToList();
                List<string> outp = file.ReadLine().Split(' ').ToList();
                cpy = outp;
                int[,] devices = new int[inp.Count, inp[0].Length];
                int[,] output = new int[outp.Count, outp[0].Length];

                for (int j = 0; j < inp.Count; j++)
                {
                    for (int k = 0; k < inp[0].Length; k++)
                    {
                        devices[j, k] = inp[j][k]-48;
                        output[j, k] = outp[j][k]-48;
                    }

                }
                rws = inp.Count;
                cols = inp[0].Length;
                if (CompareLists2(inp, outp))
                {
                    res.Add(-1);

                }
                else
                {
                    getRes(devices, output);
                    res.Add(cnt);
                }
            }

            for (int i = 0; i < testcases; i++)
            {
                string tp=string.Empty;
                if (res[i] == 0)
                    tp = "NOT POSSIBLE";
                else if (res[i] == -1)
                    tp = "0";
                else
                    tp =Convert.ToString(res[i]);
                string result = "Case #" + (i + 1) + ": " + tp;
                fileresult.WriteLine(result);
            }
            file.Close();
            fileresult.Close();
        }

        private void getRes(int[,] devices, int[,] output)
        {
            for (int i = 0; i < rws; i++)
            {
                check(i, devices, output);
            }
        }

        private void check(int i, int[,] devices, int[,] output)
        {

            for (int z = 0; z < rws; z++)
            {
                StringBuilder sb = new StringBuilder();
                List<string> final = new List<string>();
                int p = 0;
                int[] ch = new int[cols];
                int[] flags = new int[cols];
                for (int q = 0; q < cols; q++)
                {
                    flags[q] = '0';
                }
                bool flg = true;
                for (int j = 0; j < cols; j++)
                {
                    if (devices[i, j] != output[z, j])
                        flags[j] = 1;
                    else
                        flags[j] = 0;

                }

                for (int j = 0; j < rws; j++)
                {
                    sb = new StringBuilder();
                    ch = new int[cols];
                    for (int x = 0; x < cols; x++)
                    {
                        if (flags[x] == 1)
                        {
                            if (devices[j, x] == 0)
                                ch[x] = 1;
                            else
                                ch[x] = 0;
                        }
                        else
                        {
                            ch[x] = devices[j, x];
                        }
                        sb.Append(ch[x]);
                    }
                    final.Add(sb.ToString());


                    /*
                    for (p = 0; p < cols; p++)
                    {
                        if (ch[p] != devices[j, p])
                            break;
                    }
                    if (p == cols)
                    {
                        flg = false;
                        break;
                    }
                     * */

                }

                //check

                if (!CompareLists2(final,cpy.ToList()))
                {
                    flg = false;
                }

                if (flg == true && cnt==0)
                    cnt = flags.Count(x => x == 1);
                else if (flg == true && cnt >flags.Count(x => x == 1))
                    cnt = flags.Count(x => x == 1);
            }

        }

        public bool CompareLists2(List<string> list1,List<string>  list3)
        {
            List<string> list2 = new List<string>();
            foreach (var item in list3)
            {
                list2.Add(item);
            }
            if (list1.Count != list2.Count)
                return false;

            for (int i = 0; i < list1.Count; i++)
            {
                for (int j = 0; j < list2.Count; j++)
                {
                    if (list1[i].Equals(list2[j]))
                            list2.RemoveAt(j);        
                }
            }
            if (list2.Count == 0)
                return true;
            else
               return false;
        }



    }
}
