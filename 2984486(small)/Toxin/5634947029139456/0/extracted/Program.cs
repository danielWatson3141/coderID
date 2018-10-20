using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {


        static void Main(string[] args)
        {
            System.IO.StreamReader file = new System.IO.StreamReader("input");

            System.IO.StreamWriter output = new System.IO.StreamWriter("output");

            int size = int.Parse(file.ReadLine());

            for (int i = 0; i < size; i++)
            {
                string[] temp = file.ReadLine().Split(' ');

                int N = int.Parse(temp[0]);

                int L = int.Parse(temp[1]);

                string[] input1 = file.ReadLine().Split(' ');

                string[] input2 = file.ReadLine().Split(' ');

                int[] in1 = new int[input1.Length];

                for (int j = 0; j < input1.Length;j++ )
                    in1[j] = Convert.ToInt32( input1[j],2);

                int[] in2 = new int[input1.Length];

                for (int j = 0; j < input1.Length; j++)
                {
                    in2[j] = Convert.ToInt32(input2[j], 2);
                }

                int[] in3 = new int[input1.Length];

                int min = 10000;

                Array.Sort(in2);

                for (int j = 0; j < Math.Pow(2, L); j++)
                {
                    for (int k = 0; k < input1.Length; k++)
                    {
                        in3[k] = in1[k] ^ j;
                    }
                    Array.Sort(in3);


                    if (Enumerable.SequenceEqual(in2, in3))
                    {
                        Decimal w = j;
                        int count = Convert.ToString(j, 2).Count(x => x == '1');
                        if (count < min)
                            min = count;
                    }
                }

                if(min==10000)
                    output.WriteLine("Case #" + (i + 1).ToString() + ": " + "NOT POSSIBLE");
                else
                    output.WriteLine("Case #" + (i + 1).ToString() + ": " + min);
            }

            file.Close();

            output.Close();
            // Suspend the screen.

        }
    }
}
