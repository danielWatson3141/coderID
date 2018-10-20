using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2014Round1A
{
	internal class A
	{
		private static void Main(string[] args)
		{
			TextReader tr = new StreamReader("A-small.in");
			TextWriter tw = new StreamWriter("A-small.out");

			int T;

			T = int.Parse(tr.ReadLine());

			for (int t = 0; t < T; t++)
			{
				int[] nums = tr.ReadLine().Split(' ').Select(int.Parse).ToArray();
				int n = nums[0];
				int l = nums[1];
				List<string> init = tr.ReadLine().Split(' ').ToList();
				List<string> rslt = tr.ReadLine().Split(' ').ToList();

				List<int> sw = new List<int>();

				bool poss = true;

				for (int i = 0; i < l; i++)
				{
					int si = 0;
					int sr = 0;
					for (int j = 0; j < n; j++)
					{
						si += init[j][i] - '0';
						sr += rslt[j][i] - '0';
					}
					if (si != sr)
					{
						if (si != n - sr)
						{
							poss = false;
							break;
						}
						else
						{
							sw.Add(i);
						}
					}
				}

				foreach (var i in sw)
				{
					for (int j = 0; j < n; j++)
					{
						string newstr = "";
						newstr += init[j].Substring(0, i);

						if (init[j][i] == '0') newstr += '1';
						else newstr += '0';

						newstr += init[j].Substring(i + 1, l - (i + 1));

						init[j] = newstr;
					}
				}

				foreach (var r in rslt)
				{
					if (init.Contains(r))
					{
						init.Remove(r);
					}
					else
					{
						poss = false;
						break;
					}
				}

				if (poss)
					tw.WriteLine("Case #" + (t + 1) + ": " + sw.Count);
				else
					tw.WriteLine("Case #" + (t + 1) + ": NOT POSSIBLE");

			}
			tr.Close();
			tw.Close();
		}
	}
}