using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CodeJam1A
{
	class ProblemA
	{
		void Solve()
		{
			var testCount = Int32.Parse(input[0]);
			for (int test = 0; test < testCount; ++test)
			{
				var firstIn = input[1 + (test * 3)].Split(' ');
				var count = Int32.Parse(firstIn[0]);
				var length = Int32.Parse(firstIn[1]);
				var outlets = input[2 + (test * 3)].Split(' ').ToArray();
				var devices = input[3 + (test * 3)].Split(' ').ToArray();
				var flips = 0;

				for (int i = 0; i < length; ++i)
				{
					var co = 0;
					for (int j = 0; j < count; ++j)
						if (outlets[j][i] == '0')
							++co;
					var cd = 0;
					for (int j = 0; j < count; ++j)
						if (devices[j][i] == '0')
							++cd;

					var allSame = co == cd;
					var allOpposite = (co == count - cd) && !allSame;
					if (allOpposite)
						++flips;
					else if (!allSame)
					{
						flips = -1;
						break;
					}
				}

				output.Add(String.Format("Case #{0}: {1}", test + 1, (flips == -1 ? "NOT POSSIBLE" : flips.ToString())));
			}
		}

		string inFile = "C://Users//luke//Desktop//A-small-attempt0.in";
		string outFile = "C://Users//luke//Desktop//out.txt";
		string[] input;
		List<String> output;

		static void Main(string[] args)
		{
			new ProblemA();
		}

		ProblemA()
		{
			input = File.ReadAllLines(inFile);
			output = new List<string>();
			Solve();
			File.WriteAllLines(outFile, output);
		}
	}
}
