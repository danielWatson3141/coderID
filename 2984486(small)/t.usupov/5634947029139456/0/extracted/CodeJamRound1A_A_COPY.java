import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;

public class CodeJamRound1A_A_COPY {

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(bf.readLine());
		String[] s; int N, L, cnt, ans, x;
		String[] cntOut = new String[160], cntDvc = new String[160];
		String binar;
		boolean pp;
		for (int t = 0; t < T; t++) {
			ans = Integer.MAX_VALUE;
			s = bf.readLine().trim().split(" ");
			N = Integer.parseInt(s[0]);
			L = Integer.parseInt(s[1]);
			s = bf.readLine().trim().split(" ");
			for (int i = 0; i < N; i++) {
				cntOut[i] = s[i];
			}
			s = bf.readLine().trim().split(" ");
			for (int i = 0; i < N; i++) {
				cntDvc[i] = s[i];
			}
			Arrays.sort(cntDvc, 0, N);
			x = (int) Math.pow(2, L);
			for (int i = 0; i < x; i++) {
				binar = Integer.toBinaryString(i);
				while(binar.length() != L) binar = "0" + binar;
				cnt = 0;
				for (int j = 0; j < L; j++) {
					if (binar.charAt(j) != '1') {
						cnt++;
						for (int j2 = 0; j2 < N; j2++) {
							if (cntOut[j2].charAt(j) == '1') {
								cntOut[j2] = cntOut[j2].substring(0, j) + "0" + cntOut[j2].substring(j + 1);
							} else {
								cntOut[j2] = cntOut[j2].substring(0, j) + "1" + cntOut[j2].substring(j + 1);
							}
						}
					}
				}
				Arrays.sort(cntOut, 0, N);
				pp = true;
				for (int j2 = 0; j2 < N; j2++) {
					if (!cntOut[j2].equals(cntDvc[j2])) {
						pp = false;
						break;
					}
				}
				if (pp) {
					ans = Math.min(ans, cnt);
				}
				for (int j = 0; j < L; j++) {
					if (binar.charAt(j) != '1') {
						cnt++;
						for (int j2 = 0; j2 < N; j2++) {
							if (cntOut[j2].charAt(j) == '1') {
								cntOut[j2] = cntOut[j2].substring(0, j) + "0" + cntOut[j2].substring(j + 1);
							} else {
								cntOut[j2] = cntOut[j2].substring(0, j) + "1" + cntOut[j2].substring(j + 1);
							}
						}
					}
				}
			}
			if (ans != Integer.MAX_VALUE)
				pw.println("Case #" + (t + 1) + ": " + ans);
			else 
				pw.println("Case #" + (t + 1) + ": NOT POSSIBLE");
			pw.flush();
		}
		
	}

}