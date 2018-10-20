using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2014Round1A
{
	internal class C
	{
		private static Random random = new Random(10);

		private static bool TestGood(ref int[] a,ref int[] b)
		{
			int n = b.Length;
			for (int i = 0; i < n; i++) a[i] = i+1;
			for (int i = 0; i < n; i++)
			{
				int p = random.Next(i, n);
				int t = a[i];
				a[i] = a[p];
				a[p] = t;
			}

			for (int i = 0; i < n; i++)
				if (a[i] != b[i]) return false;
			return true;
		}

		private static bool TestBad(ref int[]a, ref int[] b)
		{
			int n = b.Length;
			for (int i = 0; i < n; i++) a[i] = i + 1;
			for (int i = 0; i < n; i++)
			{
				int p = random.Next(0, n);
				int t = a[i];
				a[i] = a[p];
				a[p] = t;
			}

			for (int i = 0; i < n; i++)
				if (a[i] != b[i]) return false;
			return true;
		}



		private static void Main(string[] args)
		{
			TextReader tr = new StreamReader("C-small.in");
			TextWriter tw = new StreamWriter("C-small.out");

			int T;

			T = int.Parse(tr.ReadLine());

			int[] a = new int[1000];

			for (int t = 0; t < T; t++)
			{
				int n = 1000;
				tr.ReadLine();
				int[] b = tr.ReadLine().Split(' ').Select(int.Parse).ToArray();

				bool pr = false;
				int tt = 60;
				for (int i = 0; i < tt; i++)
				{
					if (b[i] > 1000 - tt)
					{
						tw.WriteLine("Case #" + (t + 1) + ": GOOD");
						pr = true;
						break;
					}
				}

				if (!pr)
				{
					tw.WriteLine("Case #" + (t + 1) + ": BAD");
				}
			}
			tr.Close();
			tw.Close();
		}
	}
}