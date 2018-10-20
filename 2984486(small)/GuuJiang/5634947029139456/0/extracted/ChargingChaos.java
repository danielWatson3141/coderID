import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;


public class ChargingChaos {
	
	public static void main(String[] args) throws Exception {
		BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(cin.readLine());
		for (int t = 1; t <= cases; ++t) {
			String[] strs = cin.readLine().split(" ");
			int n = Integer.parseInt(strs[0]);
			int l = Integer.parseInt(strs[1]);
			int[] source = new int[n];
			int[] target = new int[n];
			int[] temp = new int[n];
			strs = cin.readLine().split(" ");
			for (int i = 0; i < n; ++i) {
				source[i] = Integer.parseInt(strs[i], 2);
			}
			strs = cin.readLine().split(" ");
			for (int i = 0; i < n; ++i) {
				target[i] = Integer.parseInt(strs[i], 2);
			}
			Arrays.sort(target);
			int mask = 0;
			int min = l + 1;
			for (; mask < 1 << l;++mask) {
				temp = source.clone();
				for (int i = 0; i < n; ++i) {
					temp[i] ^= mask;
				}
				Arrays.sort(temp);
				if (Arrays.equals(temp, target)) {
					int c = numberOfOnes(mask);
					if (c < min) {
						min = c;
					}
				}
			}
			System.out.printf("Case #%d: ", t);
			if (min == l + 1) {
				System.out.println("NOT POSSIBLE");
			} else {
				System.out.println(min);
			}
		}
	}

	static int numberOfOnes(int n) {
		int c;
		for (c = 0; n != 0; ++c) {
			n &= (n - 1);
		}
		return c;
	}
}
