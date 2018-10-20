import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class A {
	void run() {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t=1; t<=T; t++) {
			int N = in.nextInt();
			int L = in.nextInt();
			long[] src = new long[N];
			long[] dst = new long[N];
			for (int i=0; i<N; i++) {
				String str = in.next();
				long now = 0;
				for (int j=0; j<L; j++) {
					now <<= 1;
					if (str.charAt(j) == '1') {
						now += 1;
					}
				}
				src[i] = now;
			}
			for (int i=0; i<N; i++) {
				String str = in.next();
				long now = 0;
				for (int j=0; j<L; j++) {
					now <<= 1;
					if (str.charAt(j) == '1') {
						now += 1;
					}
				}
				dst[i] = now;
			}
			Arrays.sort(src);
			Arrays.sort(dst);

			boolean cut = false;
			for (long j=1; j<(1L<<L); j<<=1) {
				int scnt = 0;
				int dcnt = 0;
				for (int i=0; i<N; i++) {
					if ((src[i]&j) > 0) {
						scnt++;
					}
					if ((dst[i]&j) > 0) {
						dcnt++;
					}
				}
				if (scnt != dcnt && scnt != N-dcnt) {
					cut = true;
				}
			}
			//System.out.println("" + cut);
			ArrayList<Long> ar = new ArrayList<Long>();
			ArrayList<Long> nar = new ArrayList<Long>();
			if (!cut) {
				ar.add(0L);
				long[] sub = new long[N];
				long[] dsub = new long[N];
				for (long j=1; j<(1L<<L); j<<=1) {
					long mask = (j<<1) - 1;
					for (int i=0; i<N; i++) {
						dsub[i] = dst[i]&mask;
					}
					Arrays.sort(dsub);
					for (int i=0; i<ar.size(); i++) {
						long l = ar.get(i);
						for (int k=0; k<N; k++) {
							sub[k] = (src[k]^l)&mask;
						}
						Arrays.sort(sub);
						boolean flg = true;
						for (int k=0; k<N; k++) {
							if (dsub[k] != sub[k]) {
								flg = false;
								break;
							}
						}
						if (flg) {
							nar.add(l);
						}

						l = ar.get(i) + j;
						for (int k=0; k<N; k++) {
							sub[k] = (src[k]^l)&mask;
						}
						Arrays.sort(sub);
						flg = true;
						for (int k=0; k<N; k++) {
							if (dsub[k] != sub[k]) {
								flg = false;
								break;
							}
						}
						if (flg) {
							nar.add(l);
						}
					}
					if (nar.size() == 0) {
						ar.clear();
						break;
					}
					ar = nar;
					nar = new ArrayList<Long>();
				}
			}
			int res = L+1;
			for (int i=0; i<ar.size(); i++) {
				int cnt = 0;
				long l = ar.get(i);
				for (long j=1; j<(1<<L); j<<=1) {
					if ((l&j) > 0) {
						cnt++;
					}
				}
				res = Math.min(res, cnt);
			}
			if (res <= L) {
				System.out.println("Case #" + t + ": " + res);
			} else {
				System.out.println("Case #" + t + ": NOT POSSIBLE");
			}
		}
	}
	static public void main(String[] args) {
		new A().run();
	}
}
