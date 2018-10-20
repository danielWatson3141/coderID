package gcj2014R1A;

import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	void solve(Scanner sc, int case_num) {
		int n = sc.nextInt();
		int l = sc.nextInt();
		long [] in = new long[n];
		long [] out = new long[n];
		for(int i = 0; i < n; i++) {
			String str = sc.next();
			for(int j = 0; j < l; j++) {
				char c = str.charAt(j);
				in[i] <<= 1;
				in[i] |= c == '1' ? 1 : 0;
			}
		}
		for(int i = 0; i < n; i++) {
			String str = sc.next();
			for(int j = 0; j < l; j++) {
				char c = str.charAt(j);
				out[i] <<= 1;
				out[i] |= c == '1' ? 1 : 0;
			}
		}
		int res = 10000;
		a:for(int i = 0; i < n; i++) {
			long type = in[0] ^ out[i];
			int count = Long.bitCount(type);
//			System.out.printf("%d: %x %d\n", i, type, count);
			if(count > res) continue;
			boolean check[] = new boolean[n];
			check[i] = true;
			b:for(int j = 1; j < n; j++) {
				long base = in[j] ^ type;
//				System.out.println(base);
				for(int k = 0; k < n; k++) if(out[k] == base && !check[k]) {
					check[k] = true;
//					System.out.printf("match: %d\n", k);
					continue b;
				}
				continue a;
			}
			res = count;
		}
		if(res == 10000) {
			System.out.printf("Case #%d: NOT POSSIBLE\n", case_num);
		} else {
			System.out.printf("Case #%d: %d\n", case_num, res);
		}
	}
}
