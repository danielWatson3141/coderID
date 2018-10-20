import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class ChargingChaosBrute {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		caseloop: for (int ca = 1; ca <= cases; ca++) {
			int N = in.nextInt();
			int L = in.nextInt();
			in.nextLine();
			String[] flows = in.nextLine().split(" ");
			String[] required = in.nextLine().split(" ");
			Arrays.sort(flows);
			Arrays.sort(required);
			Random rand = new Random();
			for (int i = 0; i <= L; i++) {
				for (int r = 0; r < 100000; r++) {
					String[] flowsnew = Arrays.copyOf(flows, flows.length);
					int[] toPermute = new int[i];
					for (int k = 0; k < toPermute.length; k++) {
						outer: while (true) {
							int next = rand.nextInt(L);
							for (int p = 0; p < k; p++) {
								if (toPermute[p] == next)
									continue outer;
							}
							toPermute[k] = next;
							break outer;
						}
					}
					for (int index : toPermute) {
						for (int k = 0; k < N; k++) {
							StringBuilder b = new StringBuilder(flowsnew[k]);
							if (b.charAt(index) == '0')
								b.setCharAt(index, '1');
							else
								b.setCharAt(index, '0');
							flowsnew[k] = b.toString();
						}
					}
					Arrays.sort(flowsnew);
					boolean mismatch = false;
					for (int k = 0; k < N; k++) {
						if (!flowsnew[k].equals(required[k])) {
							mismatch = true;
							break;
						}
					}
					if (!mismatch) {
						System.out.printf("Case #%d: %d%n", ca, i);
						continue caseloop;
					}
				}
			}
			System.out.printf("Case #%d: NOT POSSIBLE%n", ca);
		}
	}
}
