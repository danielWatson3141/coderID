using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            
            
           

            Switches.Start();

            
        }

    }



    public class Input
    {
        public IDictionary<int, string> Lines;
        public Input(string filename)
        {
            StreamReader file = new StreamReader(string.Format(@"..\..\Resources\{0}.txt", filename));
            this.Lines = new Dictionary<int, string>();
            string line = string.Empty;
            int counter = 0;
            while ((line = file.ReadLine()) != null)
            {
                Lines.Add(counter, line);
                counter++;
            }
        }
    }

}
