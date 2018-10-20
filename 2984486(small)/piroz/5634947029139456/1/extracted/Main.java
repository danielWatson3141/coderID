package round1A;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	static boolean debug = false;
	private static StringBuilder ansstr = new StringBuilder();
	public static void main(String[] args) {
		solve();
		//outstd();
		outfile();
	}
	private static void solve() {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for(int t=0;t<test;t++) {
			int n = sc.nextInt();
			int l = sc.nextInt();
			long[] outlets = new long[n];
			long[] devices = new long[n];
			for(int i=0;i<n;i++) {
				outlets[i] = Long.parseLong(sc.next(), 2);
			}
			for(int i=0;i<n;i++) {
				devices[i] = Long.parseLong(sc.next(), 2);
			}
			solveCase(n,l,outlets,devices);
		}
	}
	private static void solveCase(int n,int l,long[] outlets,long[] devices) {
		int ans = 10000;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				long mask = outlets[i] ^ devices[j];
				int maskn = Long.bitCount(mask);
				if (maskn >= ans) {
					continue;
				}
				HashSet<Long> hs = new HashSet<>();
				for(int k=0;k<n;k++) {
					hs.add(outlets[k] ^ mask);
				}
				boolean flag = true;
				for(int k=0;k<n;k++) {
					if (!hs.contains(devices[k])) {
						flag = false;
						break;
					}
				}
				if (flag) {
					ans = maskn;
				}
			}
		}
		if (ans < 10000) {
			outCase(ans);
		}else{
			outCase("NOT POSSIBLE");
		}
	}
	
	public static int outnum = 0;
	public static BufferedWriter bw;
	public static void outCase(Object o) {
		outnum++;
		ansstr.append("Case #" + outnum + ": " + o + "\n");
	}
	private static void outfile() {
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
			bw.write(ansstr.toString());
			bw.close();
		}catch (IOException e) {
			e.printStackTrace();
		}
	}
	private static void outstd() {
		System.out.println(ansstr);
	}
}
