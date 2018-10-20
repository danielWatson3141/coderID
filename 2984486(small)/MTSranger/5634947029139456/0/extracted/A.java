import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	public static boolean eq(long[] a, long[] b) {
		for (int i = 0; i < a.length; i++) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}
	public static int dfs(long[] outlets, long[] devices, int i, int count) {
		if (eq(outlets, devices)) {
			return count;
		}
		if (i == -1) {
			return -1;
		}
		int res1 = dfs(outlets, devices, i-1, count);
		long s = (1L << (long)i);
		for (int j = 0; j < outlets.length; j++) {
			if ((outlets[j] & s) > 0) {
				outlets[j] -= s;
			} else {
				outlets[j] += s;
			}
		}
		Arrays.sort(outlets);
		int res2 = dfs(outlets, devices, i-1, count+1);
		for (int j = 0; j < outlets.length; j++) {
			if ((outlets[j] & s) > 0) {
				outlets[j] -= s;
			} else {
				outlets[j] += s;
			}
		}
		Arrays.sort(outlets);
		if (res1 == -1) {
			return res2;
		}
		if (res2 == -1) {
			return res1;
		}
		return Math.min(res1, res2);
	}
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		int ncases = sc.nextInt();
		for (int csnum = 1; csnum <= ncases; csnum++) {
			int n = sc.nextInt();
			int l = sc.nextInt();
			long[] outlets = new long[n];
			long[] devices = new long[n];
			for (int i = 0; i < n; i++) {
				String str = sc.next();
				outlets[i] = 0;
				for (int j = 0; j < l; j++) {
					if (str.charAt(j) == '1') {
						outlets[i] += (1L << (long)(l - j - 1));
					}
				}
			}
			for (int i = 0; i < n; i++) {
				String str = sc.next();
				devices[i] = 0;
				for (int j = 0; j < l; j++) {
					if (str.charAt(j) == '1') {
						devices[i] += (1L << (long)(l - j - 1));
					}
				}
			}
			Arrays.sort(devices);
			Arrays.sort(outlets);
			//System.out.println(Arrays.toString(outlets));
			//System.out.println(Arrays.toString(devices));
			
			int res = dfs(outlets, devices, l-1, 0);
			System.out.print("Case #" + csnum + ": ");
			if (res == -1) {
				System.out.println("NOT POSSIBLE");
			} else {
				System.out.println(res);
			}
		}
	}
}
