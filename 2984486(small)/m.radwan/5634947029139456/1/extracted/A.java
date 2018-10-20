import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;

public class A {
	public static void main(String[] args) throws Exception {
		String fileName = "A-large";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(fileName + ".out");
		int tc = in.nextInt();
		int cc = 1;
		while (tc-- > 0) {
			int n = in.nextInt();
			int l = in.nextInt();
			long[] outlets = new long[n];
			long[] devices = new long[n];
			for (int i = 0; i < n; i++)
				outlets[i] = in.nextLong(2);
			for (int i = 0; i < n; i++)
				devices[i] = in.nextLong(2);
			int ret = l + 1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					long zor = outlets[i] ^ devices[j];
					int value = Long.bitCount(zor);
					TreeSet<Long> S = new TreeSet<>();
					for (long k : devices)
						S.add(k);
					for (long k : outlets)
						S.remove(k ^ zor);
					if (S.isEmpty()) {
						ret = Math.min(ret, value);
					}
				}
			}
			if (ret <= l) {
				System.out.printf("Case #%d: %d\n", cc, ret);
				out.printf("Case #%d: %d\n", cc, ret);
			} else {
				System.out.printf("Case #%d: NOT POSSIBLE\n", cc, ret);
				out.printf("Case #%d: NOT POSSIBLE\n", cc, ret);
			}
			cc++;
		}
		out.close();
	}
}
