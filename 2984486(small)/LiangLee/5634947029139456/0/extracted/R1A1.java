package org.lianglee.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class R1A1 {

	static int N;
	static int L;
	
	static int[][] de;
	static int[][] sw;

	public static void ch(int i) {
		for (int j = 0; j < N; j++) {
			sw[j][i] = sw[j][i] == 0 ? 1 : 0;
		}
	}
	
	public static boolean diff() {
		int[] dv = new int[N];
		int[] sv = new int[N];
		for (int i = 0; i < sv.length; i++) {
			dv[i] = 0;
			sv[i] = 0;
			for (int j = 0; j < L; j++) {
				dv[i] = dv[i]*2 + de[i][j];
				sv[i] = sv[i]*2 + sw[i][j];
			}
		}
		Arrays.sort(dv);
		Arrays.sort(sv);
		for (int j = 0; j < sv.length; j++) {
			if (dv[j] != sv[j])
				return false;
		}
		return true;
	}
	
	public static int cnt = 0;
	public static int[] dif;
	
	public static int ge() {
		dif = new int[L];
		cnt = 0;
		for (int i = 0; i < dif.length; i++) {
			int d = 0;
			int s = 0;
			for (int j = 0; j < N; j++) {
				d += de[j][i];
				s += sw[j][i];
			}
			if (d == s)
				dif[i] = 0;
			else if (N-d == s)
				dif[i] = 1;
			else
				return -1;
			
			if (dif[i] == 0 && N-d == s) {
				dif[i] = 2;
			}
			if (dif[i] == 1) {
				ch(i);
				cnt++;
			}
		}
		if (dfs(0))
			return cnt;
		return -1;	
	}
	
	public static boolean dfs(int d) {
		if (diff()) {
			return true;
		}
		if (d == L) {
			return false;
		}
		if (dif[d] == 2) {
			boolean ret = dfs(d+1);
			if (ret) {
				return ret;
			}
			ch(d);
			cnt++;
			ret = dfs(d+1);
			if (ret) {
				return ret;
			}
			ch(d);
			cnt--;
			return ret;
		} else {
			return dfs(d+1);
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		PrintStream out;
		try {
			out = new PrintStream(
					new File(
							"C:/lang/workspace/CodeJam2014/src/org/lianglee/codejam/output.txt"));
			int T = scan.nextInt();
			for (int i = 0; i < T; i++) {
				out.print("Case #" + (i + 1) + ": ");

				N = scan.nextInt();
				L = scan.nextInt();

				sw = new int[N][L];
				de = new int[N][L];
				for (int j = 0; j < N; j++) {
					int x = scan.nextInt();
					for (int j2 = 0; j2 < L; j2++) {
						sw[j][j2] = x % 10;
						x = x/10;
					}
				}
				for (int j = 0; j < N; j++) {
					int x = scan.nextInt();
					for (int j2 = 0; j2 < L; j2++) {
						de[j][j2] = x % 10;
						x = x/10;
					}
				}
				
				int r = ge();
				if (r < 0)
					out.print("NOT POSSIBLE");
				else
					out.print(r);
				out.println();
			}

			out.close();
			scan.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

}
