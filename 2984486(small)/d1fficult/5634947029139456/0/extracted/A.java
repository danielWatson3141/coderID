import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		in.useLocale(Locale.US);
		int T, N, L;
		T = in.nextInt();
		long [] out;
		long [] dev;
		boolean [] ok;
		boolean finished = false;
		for (int k=0; k<T; k++) {
			N = in.nextInt();
			out = new long [N];
			dev = new long [N];
			ok = new boolean [N];
			finished = false;
			L = in.nextInt();
			for (int i=0; i<N; i++) {
				out[i] = Long.parseLong(in.next(), 2);
			}
			for (int i=0; i<N; i++) {
				dev[i] = Long.parseLong(in.next(), 2);
			}
			
			int i=0, minCount=41;
			for (i=0; i<N; i++) {
				for (int j=0; j<N; j++)
				{
					long need = out[i] ^ dev[j];
					ok = new boolean [N];
					ok[j] = true;
					int u, d=0;
					for (u=0; u<N; u++) {
						d=0;
						if (u!=i) {
							for (d=0; d<N; d++) {
								if (ok[d] == false && (out[u] ^ need) == dev[d]) {
									ok[d] = true;
									break;
								}
							}
						}
						if (u==N-1 && d!=N) break;
						if (d == N) break;
					}
					if (u<N && d<N) {
						String ans = Long.toBinaryString(need);
						int count = 0;
						for (int z=0; z<ans.length(); z++) {
							if (ans.charAt(z) == '1') count++;
						}
						if (count < minCount) minCount = count;
					}
				}
			}
			if (minCount==41) 
				System.out.println("Case #" + (k+1) + ": NOT POSSIBLE");
			else 
				System.out.println("Case #" + (k+1) + ": " + minCount);
		}
		in.close();
	}
}
