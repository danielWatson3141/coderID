using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace charging
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();
            using (var reader = File.OpenText("1.txt"))
            {
                int caseNumber = 1;
                reader.ReadLine();
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    int length = int.Parse(line.Split(' ')[1]);
                    var outletsStr = reader.ReadLine().Split(' ').Select(s => Convert.ToInt32(s, 2));
                    var devices = reader.ReadLine().Split(' ').Select(s => Convert.ToInt32(s, 2));

                    var i = SolveCase(outletsStr, devices, length).ToString();

                    if(i == "-1") i = "NOT POSSIBLE";

                    sb.AppendLine("Case #" + caseNumber + ": " + i);
                    Console.WriteLine("Case #" + caseNumber + ": " + i); 

                    caseNumber++;
                }
            }

            File.WriteAllText("2.txt", sb.ToString());
            Console.ReadLine();
        }

        private static int SolveCase(IEnumerable<int> outlets, IEnumerable<int> devices, int length)
        {
            int tryNumber = 0;

            bool found = false;

            int max = (int)Math.Pow((double)2, (double)length + 1);

            IEnumerable<int> newOutlets = outlets.Select(o => o);

            while (tryNumber < max)
            {
                newOutlets = outlets.Select(o => o ^ tryNumber);
                found = true;
                foreach (var outlet in newOutlets)
                {
                    if (!devices.Contains(outlet)) { found = false; break; }
                }

                if (found) break;
                tryNumber++;
            }

            if (tryNumber == max) return -1;

            return CountBits(tryNumber);
        }

        public static int CountBits(int value)
        {
            int count = 0;
            while (value != 0)
            {
                count++;
                value &= value - 1;
            }
            return count;
        }
    }
}