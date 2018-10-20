using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_jam
{
	class Program
	{
        
        
		static void Main(string[] args)
		{
			int cases = int.Parse(Console.ReadLine());
			for (int cas = 1; cas <= cases; cas++)
			{
                int elem = int.Parse(Console.ReadLine());
				string[] bits = Console.ReadLine().Split(' ');
				List<int> numbers = bits.ToArray<string>().Select(Int32.Parse).ToList();
                int diff = 0;
                for (int ii = 0; ii < elem; ii++)
                {
                    if (ii == numbers[ii]) diff++;
                }
                if (diff > 1) { Console.Write("Case #"); Console.Write(cas); Console.Write(": "); Console.WriteLine("BAD"); }
                else
                {
                    Console.Write("Case #"); Console.Write(cas); Console.Write(": "); Console.WriteLine("GOOD");
                }


			}
		}
	}
}
