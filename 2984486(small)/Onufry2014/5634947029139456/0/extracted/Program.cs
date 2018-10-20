using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Application
{
	class Program
	{
		static void Main(string[] inputs)
		{
			Console.WriteLine("Executing {0}", typeof(Program).FullName);
			Console.WriteLine();

			if (inputs == null || !inputs.Any())
				inputs = Directory.GetFiles(".", "*.in");

			foreach (string input in inputs)
			{
				Process(input);
			}

			Console.WriteLine();
			Console.WriteLine("Done.");
			Console.WriteLine();

			Console.ReadLine();
		}

		public static void Process(string input)
		{
			Console.WriteLine("Processing {0}", input);

			using (StreamWriter writer = new StreamWriter(input.Replace(".in", ".out"), false))
			{
				foreach (var testCase in GetTestCases(input))
				{
					Solution solution = Solve(testCase);

					writer.Write("Case #{2}: {3}{1}", " ", (char)10, solution.ID, solution.ToString());
				}
			}
		}

		public static Solution Solve(TestCase testCase)
		{
			Tuple<UInt64, int>[] switchesToBeFlipped = GetSwitchesToBeFlipped(testCase.L).OrderBy(t => t.Item2).ToArray();

			var orderedInitialFlow = testCase.InitialFlow.OrderBy(n => n).ToArray();
			var orderedRequiredFlow = testCase.RequiredFlow.OrderBy(n => n).ToArray();

			for (int i = 0; i < switchesToBeFlipped.Length; i++)
			{
				var orderedFlippedFlow = testCase.InitialFlow.Select(f => f ^ switchesToBeFlipped[i].Item1).OrderBy(n => n).ToArray();

				if (orderedRequiredFlow.SequenceEqual(orderedFlippedFlow))
				{
					return new Solution
					{
						ID = testCase.ID,
						N = testCase.N,
						L = testCase.L,
						InitialFlow = testCase.InitialFlow,
						RequiredFlow = testCase.RequiredFlow,
						firstLine = testCase.firstLine,
						secondLine = testCase.secondLine,
						thirdLine = testCase.thirdLine,
						MinimumFlipped = switchesToBeFlipped[i].Item2,
					};
				}
			}

			return new Solution
			{
				ID = testCase.ID,
				N = testCase.N,
				L = testCase.L,
				InitialFlow = testCase.InitialFlow,
				RequiredFlow = testCase.RequiredFlow,
				firstLine = testCase.firstLine,
				secondLine = testCase.secondLine,
				thirdLine = testCase.thirdLine,
				MinimumFlipped = -1,
			};
		}

		private static IEnumerable<Tuple<ulong, int>> GetSwitchesToBeFlipped(int length)
		{
			for (int i = 0; i < (0x1 << length); i++)
			{
				yield return new Tuple<ulong, int>((ulong)i, CountOnes((ulong)i));
			}
		}

		private static int CountOnes(ulong p)
		{
			int result = 0;

			for (int i = 0; i < 64; i++)
			{
				if ((p & (0x1UL << i)) != 0)
					result++;
			}

			return result;
		}

		public static IEnumerable<TestCase> GetTestCases(string input)
		{
			using (StreamReader reader = new StreamReader(input))
			{
				string @string = reader.ReadToEnd();

				var lines = @string.Split(new char[] { (char)10, (char)13 }, StringSplitOptions.RemoveEmptyEntries);

				int testCases = Int32.Parse(lines.First());

				int lineIndex = 1;

				for (int testCase = 1; testCase <= testCases; testCase++)
				{
					string firstLine = lines[lineIndex++];
					string secondLine = lines[lineIndex++];
					string thirdLine = lines[lineIndex++];

					int N = Int32.Parse(firstLine.Split(' ')[0]);
					int L = Int32.Parse(firstLine.Split(' ')[1]);

					yield return new TestCase
					{
						ID = testCase,
						N = N,
						L = L,
						InitialFlow = secondLine.Split(' ').Select(s => ParseBits(s)).ToArray(),
						RequiredFlow = thirdLine.Split(' ').Select(s => ParseBits(s)).ToArray(),
						firstLine = firstLine,
						secondLine = secondLine,
						thirdLine = thirdLine,
					};
				}
			}
		}

		private static UInt64 ParseBits(string bits)
		{
			UInt64 result = 0;

			for (int i = 0; i < bits.Length; i++)
			{
				result = (result << 1) | ((UInt64)(bits[i] == '1' ? 0x1 : 0x0));
			}
			return result;
		}

		public class TestCase : IEquatable<TestCase>, IEqualityComparer<TestCase>
		{
			public int ID { get; set; }

			public bool Equals(TestCase other)
			{
				if (other == null) return false;

				if (this.ID != other.ID) return false;

				return true;
			}

			public bool Equals(TestCase x, TestCase y)
			{
				return x.Equals(y);
			}

			public int GetHashCode(TestCase obj)
			{
				return obj.GetHashCode();
			}

			public override bool Equals(object obj)
			{
				var other = obj as TestCase;

				return this.Equals(other);
			}

			public override int GetHashCode()
			{
				return ID.GetHashCode();
			}

			public override string ToString()
			{
				return String.Format("{0}", ID);
			}

			public string firstLine { get; set; }

			public string secondLine { get; set; }

			public string thirdLine { get; set; }

			public int N { get; set; }

			public int L { get; set; }

			public ulong[] InitialFlow { get; set; }

			public ulong[] RequiredFlow { get; set; }
		}

		public class Solution : TestCase, IEquatable<Solution>, IEqualityComparer<Solution>
		{
			public int ID { get; set; }

			public bool Equals(Solution other)
			{
				if (other == null) return false;

				if (this.ID != other.ID) return false;

				return true;
			}

			public bool Equals(Solution x, Solution y)
			{
				return x.Equals(y);
			}

			public int GetHashCode(Solution obj)
			{
				return obj.GetHashCode();
			}

			public override bool Equals(object obj)
			{
				var other = obj as Solution;

				return this.Equals(other);
			}

			public override int GetHashCode()
			{
				return ID.GetHashCode();
			}

#if true
			public override string ToString()
			{
				return String.Format("{0}",
					MinimumFlipped >= 0 ? String.Format("{0}", MinimumFlipped) : "NOT POSSIBLE");
			}
#else			
			public override string ToString()
			{
				return String.Format("{0} {1} {2} [{3}] [{4}] '{5}' '{6}' {7}",
					ID,
					N,
					L,
					InitialFlow.Aggregate("", (a, c) => String.Format("{0} : {1:X8}", a, c)).TrimStart(new char[] { ' ', ':' }),
					RequiredFlow.Aggregate("", (a, c) => String.Format("{0} : {1:X8}", a, c)).TrimStart(new char[] { ' ', ':' }),
					secondLine,
					thirdLine,
					MinimumFlipped >= 0 ? String.Format("{0}", MinimumFlipped) : "NOT POSSIBLE");
			}
#endif

			public int MinimumFlipped { get; set; }
		}
	}
}
