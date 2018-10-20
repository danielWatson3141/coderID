using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "B-small-attempt0 (1)";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
			}
		}

		private static void Solve()
		{
			var n = cin.NextInt();
			var nodeMap = new Dictionary<int, Node>();
			for (var i = 0; i < n - 1; i++)
			{
				var x = cin.NextInt();
				var y = cin.NextInt();
				if (!nodeMap.ContainsKey(x))
				{
					nodeMap[x] = new Node { Name = x };
				}
				if (!nodeMap.ContainsKey(y))
				{
					nodeMap[y] = new Node { Name = y };
				}
				nodeMap[x].Children.Add(nodeMap[y]);
				nodeMap[y].Children.Add(nodeMap[x]);
			}
			var best = int.MaxValue;
			foreach (var node in nodeMap.Values)
			{
				node.Parent = -1;
				best = Math.Min(best, Calc(node));
			}
			Console.WriteLine(best);
		}

		private static int Calc(Node node)
		{
			var children = node.Children.Where(x => x.Name != node.Parent).ToList();
			foreach (var c in children)
			{
				c.Parent = node.Name;
			}
			if (children.Count == 0)
			{
				return 0;
			}
			if (children.Count == 1)
			{
				return Len(children.Single());
			}
			if (children.Count == 2)
			{
				return Calc(children[0]) + Calc(children[1]);
			}
			var best = int.MaxValue;
			for (var i = 0; i < children.Count; i++)
			{
				for (var j = i + 1; j < children.Count; j++)
				{
					var len = 0;
					for (var k = 0; k < children.Count; k++)
					{
						if (k != i && k != j)
						{
							len += Len(children[k]);
						}
					}
					best = Math.Min(best, Calc(children[i]) + Calc(children[j]) + len);
				}
			}
			return best;
		}

		public static int Len(Node node)
		{
			var len = 1;
			var children = node.Children.Where(x => x.Name != node.Parent).ToList();
			foreach (var c in children)
			{
				c.Parent = node.Name;
				len += Len(c);
			}
			return len;
		}

		public class Node
		{
			public int Parent { get; set; }
			public int Name { get; set; }
			public List<Node> Children { get; set; }

			public Node()
			{
				Children = new List<Node>();
			}
		}
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string Next()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			if (line == string.Empty)
			{
				return Next();
			}
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(Next());
		}

		public int NextInt()
		{
			return int.Parse(Next());
		}

		public long NextLong()
		{
			return long.Parse(Next());
		}
	}
}