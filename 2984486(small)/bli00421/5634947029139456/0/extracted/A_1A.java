import java.io.*;
import java.util.*;

public class A_1A {
	static final int INF = 1 << 30;
	static final String inFile = "A-small-attempt0.in", outFile = "output.txt";
	
	static final Comparator<char[]> cmp = new Comparator<char[]>() {
		public int compare(char[] A, char[] B) { return new String(A).compareTo(new String(B)); }
	};
	
	static char toggle(char a) {
		if (a == '0') return '1';
		return '0';
	}
	
	static boolean eq(char[] a, char[] b) {
		for (int i = 0; i < a.length; i++) {
			if (a[i] != b[i])
				return false;
		}
		return true;
	}
	
	static void print(char[][] a) {
		for (char[] b : a) System.out.println(new String(b));
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File(inFile));
		PrintWriter out = new PrintWriter(new FileWriter(outFile));
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int n = in.nextInt(), m = in.nextInt(), min = INF;
			
			char device[][] = new char[n][m];
			char charge[][] = new char[n][m];
			
			for (int i = 0; i < n; i++) device[i] = in.next().toCharArray();
			for (int i = 0; i < n; i++) charge[i] = in.next().toCharArray();
			Arrays.sort(charge, cmp);
			
			boolean used[] = new boolean[m];
			for (int i = 0; i < (1 << m); i++) {
				int count = 0;
				for (int j = 0; j < m; j++) {
					used[j] = ((i & (1 << j)) > 0);
					if (used[j]) count++;
				}
				
				char dev_copy[][] = new char[n][m];
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < m; b++)
						dev_copy[a][b] = device[a][b];
				}
				
				for (char[] s : dev_copy) {
					for (int j = 0; j < m; j++) {
						if (used[j])
							s[j] = toggle(s[j]);
					}
				}
				
				Arrays.sort(dev_copy, cmp);
				
				boolean good = true;
				for (int k = 0; k < n; k++) {
					if (!eq(dev_copy[k], charge[k])) {
						good = false;
						break;
					}
				}
				/*
				if (i == 0) {
					System.out.println(t + " " + count);
					print(dev_copy);
					System.out.println("The " + t);
					print(charge);
				}*/
				
				if (good) min = Math.min(min, count);
			}
			
			out.print("Case #" + t + ": ");
			out.println((min == INF) ? "NOT POSSIBLE" : min);
		}
		
		out.close();
	}
}
