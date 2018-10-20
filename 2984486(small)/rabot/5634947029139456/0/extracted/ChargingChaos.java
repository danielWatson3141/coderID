package r1a2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class ChargingChaos {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ChargingChaos obj = new ChargingChaos();
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
			dev = new HashSet<Long>();

			str = br.readLine();
			token = new StringTokenizer(str, " ");
			for (int j = 0; j < N; j++) {
				out[j] = Long.parseLong(token.nextToken(), 2);
			}
			str = br.readLine();
			token = new StringTokenizer(str, " ");
			for (int j = 0; j < N; j++) {
				dev.add(Long.parseLong(token.nextToken(), 2));
			}

			min = Integer.MAX_VALUE;
			rc(0, 0, out);

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

	private void rc(int idx, int cnt, long[] a) {
		if (idx >= L) {
			boolean flg = true;
			for (int i = 0; i < a.length; i++) {
				if (dev.contains(a[i])) {
					continue;
				} else {
					flg = false;
					break;
				}
			}
			if (flg) {
				min = Math.min(min, cnt);
			}
			return;
		}
		rc(idx + 1, cnt, a);
		long tmp = (1L << idx);
		for (int i = 0; i < a.length; i++) {
			a[i] = (a[i] ^ tmp);
		}
		rc(idx + 1, cnt + 1, a);
		for (int i = 0; i < a.length; i++) {
			a[i] = (a[i] ^ tmp);
		}
	}
}
