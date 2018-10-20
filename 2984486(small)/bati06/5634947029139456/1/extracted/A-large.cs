using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
	class Program
	{
		static void Main(string[] args)
		{
			using (var reader = new StreamReader(args[0]))
			using (var writer = new StreamWriter(args.Length > 1 ? args[1] : args[0].Replace(".in", ".out")))
			{
				var t = reader.Next<int>();
				for (int i = 1; i <= t; i++)
				{
					var N = reader.Next<int>();
					var L = reader.Next<int>();
					var currentFlows = reader.Next<string>(N);
					var deviceFlows = reader.Next<string>(N);

					var res = Solve(currentFlows, deviceFlows);

					writer.WriteLine("Case #{0}: {1}", i, res != int.MaxValue ? res.ToString() : "NOT POSSIBLE");
				}
			}
		}

		private static int Solve(string[] outlets, string[] devices)
		{
			int minSwitch = int.MaxValue;
			var firstDev = devices[0];
			for (int i = 0; i < outlets.Length; i++)
			{
				var devCopy = new List<string>(devices);
				var mask = new string(firstDev.Select((x, idx) => x == outlets[i][idx] ? '0' : '1').ToArray());
				var numOfSwitches = mask.Count(x => x == '1');
				devCopy.Remove(firstDev);
				for (int j = 0; j < outlets.Length; j++)
				{
					if (j == i) continue;
					var switchedOutlet = new string(outlets[j].Select((x, idx) => mask[idx] == '0' ? x : (x == '0' ? '1' : '0')).ToArray());
					if (!devCopy.Remove(switchedOutlet)) break;
				}
				if (!devCopy.Any()) minSwitch = Math.Min(minSwitch, numOfSwitches);
			}
			return minSwitch;
		}


		//private static int Solve(string[] currentFlows, string[] goal)
		//{
		//	int minSwitch = int.MaxValue;
		//	int n = currentFlows[0].Length;
		//	int psc = 1 << n;
		//	for (int i = 0; i < psc; i++)
		//	{
		//		var mask = Convert.ToString(i, 2).PadLeft(n, '0');
		//		var numOfSwitches = mask.Count(x => x == '1');
		//		var flows = currentFlows.Select(x => Switch(mask, x)).ToList();
		//		if (flows.OrderBy(x => x).SequenceEqual(goal.OrderBy(x => x)))
		//		{
		//			minSwitch = Math.Min(minSwitch, numOfSwitches);
		//		}
		//	}
		//	return minSwitch;
		//}

		//private static string Switch(string mask, string flow)
		//{
		//	var res = new StringBuilder(flow);
		//	for (int i = 0; i < mask.Length; i++)
		//	{
		//		//if (mask[i] == '0') res[i] = flow[i];
		//		if (mask[i] == '1') res[i] = flow[i] == '0' ? '1' : '0';
		//	}
		//	return res.ToString();
		//}
	}

	public static class StreamReaderExtensions
	{
		private static List<string> currLine;

		public static T Next<T>(this StreamReader reader)
		{
			if (currLine == null || !currLine.Any()) currLine = reader.ReadLine().Split(' ').ToList();
			var res = (T)Convert.ChangeType(currLine[0], typeof(T), CultureInfo.InvariantCulture);
			currLine.RemoveAt(0);
			return res;
		}

		public static T[] Next<T>(this StreamReader reader, int count)
		{
			if (currLine == null || !currLine.Any()) currLine = reader.ReadLine().Split(' ').ToList();
			if (count == 0) count = currLine.Count;
			var res = currLine.Take(count).Select(i => (T)Convert.ChangeType(i, typeof(T), CultureInfo.InvariantCulture)).ToArray();
			currLine.RemoveRange(0, count);
			return res;
		}
	}
}
