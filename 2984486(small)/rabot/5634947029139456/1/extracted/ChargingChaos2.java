package r1a2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class ChargingChaos2 {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ChargingChaos2 obj = new ChargingChaos2();
		obj.solve(fileName);
	}

	int min = 0;
	HashSet<Long> dev = null;
	int L = 0;

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str, " ");
			int N = Integer.parseInt(token.nextToken());
			L = Integer.parseInt(token.nextToken());
			long[] out = new long[N];
			long[] deva = new long[N];
			dev = new HashSet<Long>();

			str = br.readLine();
			token = new StringTokenizer(str, " ");
			for (int j = 0; j < N; j++) {
				out[j] = Long.parseLong(token.nextToken(), 2);
			}
			str = br.readLine();
			token = new StringTokenizer(str, " ");
			for (int j = 0; j < N; j++) {
				deva[j] = Long.parseLong(token.nextToken(), 2);
				dev.add(deva[j]);
			}

			min = Integer.MAX_VALUE;
			for (int j = 0; j < N; j++) {
				int cnt = 0;
				long sw = 0;
				for (int k = 0; k < L; k++) {
					long filter = (1L << k);
					if ((out[0] & filter) != (deva[j] & filter)) {
						cnt += 1;
						sw += filter;
					}
				}
				if (cnt > min) {
					continue;
				}
				boolean flg = true;
				for (int k = 0; k < N; k++) {
					if (dev.contains((out[k] ^ sw))) {
						continue;
					} else {
						flg = false;
						break;
					}
				}
				if (flg) {
					min = Math.min(min, cnt);
				}
			}

			if (min == Integer.MAX_VALUE) {
				bw.write("Case #" + (i + 1) + ": " + "NOT POSSIBLE");
			} else {
				bw.write("Case #" + (i + 1) + ": " + min);
			}
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
