using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Lawnmower
{
	class Program
	{
		private static List<List<KeyValuePair<int, int>>> result = new List<List<KeyValuePair<int, int>>>();

		static void Main(string[] args)
		{
			string input = "a.in";
			string output = input.Replace(".in", ".out");
			using (StreamReader sr = new StreamReader(input)) {
				using (StreamWriter sw = new StreamWriter(output)) {
					int n = Convert.ToInt32(sr.ReadLine());
					for (int i = 1; i <= n; i++) {
						Solve(i, sr, sw);
					}
				}
			}
		}

		private static void Solve(int caseNum, StreamReader sr, StreamWriter sw)
		{
			var input = sr.ReadLine().Split(' ').Select(x => Convert.ToInt32(x)).ToList();
			int n = input[0];
			int l = input[1];

			var outlets = sr.ReadLine().Split(' ').ToList();

			var devs = sr.ReadLine().Split(' ');
			
			int minFlip = l + 1;
			int m = 2 << (l - 1);

			for (int i = 0; i < m; i++) {
				bool ok = true;
				int flip = 0;
				var devices = devs.ToDictionary(a => a);
				for (int j = 0; j < n; j++) {
					StringBuilder sb = new StringBuilder();
					for (int k = 0; k < l; k++) {
						if (((1 << k) & i) == 0) {
							sb.Append(outlets[j][k]);
						} else {
							if (j == 0) {
								flip++;
							}
							if (outlets[j][k] == '0') {
								sb.Append('1');
							} else {
								sb.Append('0');
							}
						}
					}
					var newOutlet = sb.ToString();
					if (!devices.ContainsKey(newOutlet)) {
						ok = false;
						break;
					} else {
						devices.Remove(newOutlet);
					}
				}
				if (ok && flip < minFlip) {
					minFlip = flip;
				}
			}

			if (minFlip == l + 1) {
				sw.WriteLine("Case #{0}: {1}", caseNum, "NOT POSSIBLE");
			} else {
				sw.WriteLine("Case #{0}: {1}", caseNum, minFlip);
			}

			//sw.WriteLine("Case #{0}: {1} {2}", caseNum, result1, result2);
		}
	}
}
