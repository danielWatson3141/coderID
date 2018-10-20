using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A
{
	public class Program
	{
		private static readonly List<string> Tokens = new List<string>();
		private static int position = 0;
		private const string InputFile = @"A-small-attempt0.in";
		private const string OutputFile = @"A-small-attempt0.out";
		private const string Folder = @"D:\DotNetProjects\GoogleCodeJam2014\";
		private static readonly StringBuilder sb = new StringBuilder();
		
		static void Main()
		{
			ReadInput();
			int taskCount = NextInt();
			for (int t = 0; t < taskCount; t++)
			{
				Solve(t + 1);
			}
			FlushOutput();
			
		}

		private static void Solve(int taskNumber)
		{
			int n = NextInt();
			int l = NextInt();
			var outlets = Read(n, l);
			var dev = Read(n, l);
			var devices = new List<string>();
			foreach (var d in dev)
			{
				devices.Add(Str(d));
			}

			int minChanges = int.MaxValue;
			F(l, 0, 0, outlets, devices, ref minChanges);
			var result = ""+minChanges;
			if (minChanges == int.MaxValue)
				result = "NOT POSSIBLE";
			WriteLineFormat("Case #{0}: {1}", taskNumber, result);
		}

		private static int[][] Read(int n, int l)
		{
			var outlets = new int[n][];
			for (int i = 0; i < n; i++)
			{
				outlets[i] = new int[l];
				var str = NextToken().ToCharArray();
				int j = 0;
				foreach (var s in str)
				{
					if (s == '1')
						outlets[i][j] = 1;
					j++;
				}
			}
			return outlets;
		}

		static void F(int len, int curPos, int changed, int[][] outlets, List<string> devices, ref int minChanges)
		{
			if (curPos == len)
			{
				var keys = new HashSet<string>();
				foreach (var outlet in outlets)
				{
					var item = Str(outlet);
					keys.Add(item);
				}
				foreach (var device in devices)
				{
					if (!keys.Contains(device))
						return;
					keys.Remove(device);
				}
				if (changed < minChanges)
					minChanges = changed;
				return;
			}
			
			F(len, curPos + 1, changed, outlets, devices, ref minChanges);

			ChangeOutlets(curPos, outlets);

			F(len, curPos + 1, changed + 1, outlets, devices, ref minChanges);
			foreach (var outlet in outlets)//revert
				Change(curPos, outlet);
		}

		private static void ChangeOutlets(int curPos, int[][] outlets)
		{
			foreach (var outlet in outlets)
			{
				Change(curPos, outlet);
			}
		}

		private static string Str(int[] outlet)
		{
			var r = "";
			for (int i = 0; i < outlet.Length; i++)
				r += outlet[i];
			return r;
		}

		public static void Change(int i, int[] outlet)
		{
			outlet[i] = (outlet[i] + 1) % 2;
		}
		
		private static void FlushOutput()
		{
			File.WriteAllText(Folder + OutputFile, sb.ToString());
		}

		private static void ReadInput()
		{
			var lines = File.ReadAllLines(Folder + InputFile);
			foreach (var line in lines)
			{
				var strings = line.Split(' ', '\n');
				Tokens.AddRange(strings);
			}
		}

		private static void WriteLine(string line)
		{
			sb.AppendLine(line);
		}

		private static void WriteLineFormat(string format, params object[] args)
		{
			sb.AppendLine(string.Format(format, args));
		}

		private static void Write(string str)
		{
			sb.Append(str);
		}

		private static string NextToken()
		{
			return Tokens[position++];
		}

		public static int NextInt()
		{
			return int.Parse(NextToken());
		}
		
		public static long NextLong()
		{
			return long.Parse(NextToken());
		}
	}
}
