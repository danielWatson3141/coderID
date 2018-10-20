using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2014Round1A
{
	internal class B
	{
		private static int Calc(int node, int parent, List<List<int>> v)
		{
			if (v[node].Count == 1 && parent>=0) return 0;
			if (v[node].Count == 1 && parent < 0) return Cutoff(v[node][0], node, v);
			if (v[node].Count == 2 && parent>=0)
			{
				int p = -1;
				foreach (var i in v[node])
				{
					if (i != parent) p = i;
				}
				return Cutoff(p, node, v);
			}
			List<int> fixval = new List<int>();
			List<int> cutoffval = new List<int>();

			foreach (var next in v[node])
			{
				if (next==parent) continue;
				fixval.Add(Calc(next, node, v));
				cutoffval.Add(Cutoff(next, node, v));
			}

			int s = cutoffval.Sum();

			int x = -1, y = -1, mn = int.MaxValue;
			for (int i = 0; i < fixval.Count; i++)
			{
				for (int j = i + 1; j < cutoffval.Count; j++)
				{
					if (mn > s - cutoffval[i] - cutoffval[j] + fixval[i] + fixval[j])
					{
						x = i;
						y = j;
						mn = s - cutoffval[i] - cutoffval[j] + fixval[i] + fixval[j];
					}
				}
			}

			return mn;
		}

		private static int Cutoff(int node, int parent, List<List<int>> v)
		{
			int s = 1;
			foreach (var i in v[node])
			{
				if (i == parent || i<0) continue;
				s += Cutoff(i, node, v);
			}
			return s;
		}


		private static void Main(string[] args)
		{
			TextReader tr = new StreamReader("B-large.in");
			TextWriter tw = new StreamWriter("B-large.out");

			int T;

			T = int.Parse(tr.ReadLine());

			for (int t = 0; t < T; t++)
			{
				List<List<int>> v = new List<List<int>>();
				int n = int.Parse(tr.ReadLine());
				for (int i = 0; i < n; i++)
				{
					v.Add(new List<int>());
				}

				for (int i = 0; i < n-1; i++)
				{
					int[] nums = tr.ReadLine().Split(' ').Select(int.Parse).ToArray();
					nums[0]--;
					nums[1]--;
					v[nums[0]].Add(nums[1]);
					v[nums[1]].Add(nums[0]);
				}

				int mn = int.MaxValue;
				for (int i = 0; i < n; i++)
				{
					int rs = Calc(i, -1, v);
					if (mn > rs) mn = rs;
				}

				tw.WriteLine("Case #" + (t + 1) + ": " + mn);
			}
			tr.Close();
			tw.Close();
		}
	}
}