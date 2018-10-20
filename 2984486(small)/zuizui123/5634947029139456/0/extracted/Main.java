import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
import java.math.BigInteger;

public class Main {
	final int INF = 1000000000;
	final int MAXN = 200 + 5;
	final int MODULO = 100000;
	
	Scanner input = new Scanner(System.in);
	BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(System.out);
	StringTokenizer ST;
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
	
	int T, N, L;
	int[] outlet, device;
	
	void run() throws IOException {
		T = input.nextInt();
		for (int t = 1; t <= T; ++t) {
			out.print("Case #" + t + ": ");
			N = input.nextInt();
			L = input.nextInt();
			outlet = new int[N];
			device = new int[N];
			for (int i = 0; i < N; ++i) {
				String str = input.next();				
				outlet[i] = 0;
				for (int k = 0; k < str.length(); ++k) {
					outlet[i] = outlet[i] * 2 + (str.charAt(k) - '0'); 
				}
			}
			for (int i = 0; i < N; ++i) {
				String str = input.next();
				device[i] = 0;
				for (int k = 0; k < str.length(); ++k) {
					device[i] = device[i] * 2 + (str.charAt(k) - '0');
				}
			}
			Arrays.sort(device);
			int res = INF;
			for (int state = 0; state < (1 << L); ++state) {
				int count = 0;
				for (int i = 0; i < L; ++i) {
					if ((state & (1 << i)) != 0) {
						++count;
						for (int k = 0; k < N; ++k) {
							if ((outlet[k] & (1 << i)) != 0) {
								outlet[k] = outlet[k] & (~(1 << i));
							} else {
								outlet[k] |= (1 << i);
							}
						}
					}
				}
				if (state == 2) {
					System.out.println(outlet[0]);
				}
				int[] temp = outlet.clone();
				Arrays.sort(temp);
				boolean flag = true;
				for (int i = 0; i < N; ++i) {
					if (temp[i] != device[i]) {
						flag = false;
						break;					
					}
				}
				if (flag) res = Math.min(res, count);
				for (int i = 0; i < L; ++i) {
					if ((state & (1 << i)) != 0) {						
						for (int k = 0; k < N; ++k) {
							if ((outlet[k] & (1 << i)) != 0) {
								outlet[k] = outlet[k] & (~(1 << i));
							} else {
								outlet[k] |= (1 << i);
							}
						}
					}
				}
			}
			if (res == INF) out.println("NOT POSSIBLE");
			else out.println(res);
		}
		out.close();
	}
}