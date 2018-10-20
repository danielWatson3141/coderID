using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QRound1A_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int casenum = int.Parse(Console.In.ReadLine());

            for (int i = 1; i <= casenum; i++)
            {
                SolveCase(i);
            }
        }

        private static void SolveCase(int num_casenum)
        {
            String[] str_caseparam = (Console.In.ReadLine()).Split(' ');
            int num_N = int.Parse(str_caseparam[0]);
            int num_L = int.Parse(str_caseparam[1]);

            String[] str_startflow = (Console.In.ReadLine()).Split(' ');
            int[] num_startflow = new int[num_N];
            for (int i = 0; i < num_N; i++)
            {
                num_startflow[i] = Convert.ToInt32(str_startflow[i], 2);
                Debug("debug startflow" + num_startflow[i]);

            }

            String[] str_endflow = (Console.In.ReadLine()).Split(' ');
            int[] num_endflow = new int[num_N];
            for (int i = 0; i < num_N; i++)
            {
                num_endflow[i] = Convert.ToInt32(str_endflow[i], 2);
                Debug("debug endflow" + num_endflow[i]);
            }

            int num_smallestflip = num_L + 1;

            for (int num_base = 0; num_base < Math.Pow(2,num_L); num_base++)
            {

                int num_currentflipped = 0;
                int num_tmp= num_base;

                Debug("try numbase" + num_base);

                while(num_tmp != 0){
                    if (num_tmp % 2 == 1)
                    {
                        num_currentflipped++;
                    }
                    num_tmp /= 2;
                }

                if (num_currentflipped >= num_smallestflip)
                {
                    Debug("tobasu");
                    continue;
                }

                bool[] is_found = new bool[num_N];
                for (int i = 0; i < num_N; i++)
                {
                    is_found[i] = false;
                }

                for (int i = 0; i < num_N; i++)
                {
                    int num_flipped = num_base ^ num_startflow[i];
                    bool is_catchanynum = false;

                    Debug("num_flipped = " + num_flipped);

                    for (int j = 0; j < num_N; j++)
                    {
                        if (!is_found[j] && num_flipped == num_endflow[j])
                        {
                            is_catchanynum = true;
                            is_found[j] = true;
                            break;
                        }
                    }

                    if (!is_catchanynum)
                    {
                        break;
                    }
                }

                bool is_all_found = true;
                for (int i = 0; i < num_N; i++)
                {
                    if (!is_found[i])
                    {
                        is_all_found = false;
                    }
                }

                Debug("is_all_found is " + is_all_found);

                if (is_all_found)
                {
                    num_smallestflip = num_currentflipped;
                }
            }

            Console.Out.Write("Case #" + num_casenum + ": ");
            if (num_smallestflip == num_L + 1)
            {
                Console.Out.WriteLine("NOT POSSIBLE");
            }
            else
            {
                Console.Out.WriteLine(num_smallestflip);
            }

        }

        private static void Debug(string p)
        {
            //Console.Out.WriteLine(p);
            //throw new NotImplementedException();
        }

    }
}
