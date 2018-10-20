package round1A_C;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
	static boolean debug = false;
	private static StringBuilder ansSB = new StringBuilder();
	public static void main(String[] args) {
		//test();
		solve();
		outstd();
		outfile();
	}
	private static void test() {
		int times = 5000;
		int correct = 0;
		for(int i=0;i<times;i++) {
			if (!isGood(getBadRandomPermutation(1000))) {
				correct++;
			}
			if (isGood(getGoodRandomPermutation(1000))) {
				correct++;
			}
		}
		System.out.println(correct + "/" + (times*2));
	}
	public static void test2() {
		int times = 1000;
		long count1 = 0;
		long count2 = 0;
		for(int i=0;i<times;i++) {
			count1+=countswap(getBadRandomPermutation(1000));
			count2+=countswap(getGoodRandomPermutation(1000));
		}
		System.out.println(count1/times);
		System.out.println(count2/times);
	}
	private static void solve() {
		Scanner sc = new Scanner(System.in);
		int testCaseNum = sc.nextInt();
		for(int testCase=0;testCase<testCaseNum;testCase++) {
			int n = sc.nextInt();
			int[] p = new int[n];
			for(int i=0;i<n;i++) {
				p[i] = sc.nextInt();
			}
			solveCase(p);
		}
	}
	private static boolean isGood(int[] p) {
		if (countswap(p) > 245000) {
			return true;
		}else{
			return false;
		}
	}
	private static void solveCase(int[] p) {
		outCase(isGood(p) ? "GOOD" : "BAD");
	}
	private static int[] getGoodRandomPermutation(int n) {
		int[] p = new int[n];
		for(int i=0;i<n;i++) {
			p[i] = i;
		}
		for(int i=0;i<n;i++) {
			int x = (int) (Math.random() * (n-i)) + i;
			swap(p,i,x);
		}
		return p;
	}
	private static int[] getBadRandomPermutation(int n) {
		int[] p = new int[n];
		for(int i=0;i<n;i++) {
			p[i] = i;
		}
		for(int i=0;i<n;i++) {
			int x = (int) (Math.random() * n);
			swap(p,i,x);
		}
		return p;
	}
	private static void swap(int[] a,int i,int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	private static int countNotMove(int[] p) {
		int ret = 0;
		for(int i=0;i<p.length;i++) {
			if (i == p[i]) {
				ret++;
			}
		}
		return ret;
	}
	private static long getMoment(int[] p) {
		long ret = 0;
		for(int i=0;i<p.length;i++) {
			ret += ((long) i)*i*p[i];
		}
		return ret;
	}
	private static int countswap(int[] p) {
		int ret = 0;
		for(int i=1;i<p.length;i++) {
			for(int j=0;j<i;j++) {
				if (p[j] > p[i]) {
					ret++;
				}
			}
		}
		return ret;
	}
	
	public static int outnum = 0;
	public static BufferedWriter bw;
	public static void outCase(Object o) {
		outnum++;
		ansSB.append("Case #" + outnum + ": " + o + "\n");
	}
	private static void outfile() {
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
			bw.write(ansSB.toString());
			bw.close();
		}catch (IOException e) {
			e.printStackTrace();
		}
	}
	private static void outstd() {
		System.out.println(ansSB);
	}
}
