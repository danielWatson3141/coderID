import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemASmall {
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("A-small-attempt0.in"));
		System.setOut(new PrintStream(new FileOutputStream("A-small-attempt0.out")));
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int N = in.nextInt();
			int L = in.nextInt();
			String[] flow = new String[N];
			for (int i = 0; i < N; i++) {
				flow[i] = in.next();
			}
			String[] dev = new String[N];
			for (int i = 0; i < N; i++) {
				dev[i] = in.next();
			}
			Arrays.sort(dev);
			
			int min = Integer.MAX_VALUE;
			for (int mask = 0; mask < (1<<L); mask++) {
				String[] newflow = flip(flow,mask);
				if (Arrays.deepEquals(dev, newflow)) {
					min = Math.min(min, Integer.bitCount(mask));
				}
			}
			
			if (min == Integer.MAX_VALUE) {
				System.out.printf("Case #%d: NOT POSSIBLE%n", caseNum);
			} else {
				System.out.printf("Case #%d: %d%n", caseNum, min);
			}
		}
	}
	
	public static String[] flip(String[] flow, int mask) {
		int N = flow.length;
		int L = flow[0].length();
		String[] res = new String[N];
		for (int i = 0; i < N; i++) {
			char[] cs = flow[i].toCharArray();
			for (int j = 0; j < L; j++) {
				if (((1<<j)&mask) != 0) {
					cs[j] = (cs[j]=='1')?'0':'1';
				}
			}
			res[i] = new String(cs);
		}
		Arrays.sort(res);
		return res;
	}
}
