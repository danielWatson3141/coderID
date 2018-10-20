package cj2014.r1A;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc;
	PrintWriter pw;
	int N,L;
	long[] src;
	long[] dst;
	final int INF = 10000;
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"A-small-attempt1";

		try {
			new A().run(filePrefix);
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void run(String filePrefix) throws Exception {
		sc = new Scanner(new FileReader(filePrefix + ".in"));
		pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			read(sc);
			pw.print("Case #" + test + ": ");
			System.out.print("Case #" + test + ": ");
			solve();
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
		
	}
	
	void read(Scanner sc) {
		N = sc.nextInt();
		L = sc.nextInt();
		src = new long[N];
		for(int i=0; i<N; i++) {
			src[i] = Long.parseLong(sc.next(), 2);
		}
		dst = new long[N];
		for(int i=0; i<N; i++) {
			dst[i] = Long.parseLong(sc.next(), 2);
		}
	}
	
	void print(Object s) {
		pw.print(s);
		System.out.print(s);
	}
	
	void println(Object s) {
		pw.println(s);
		System.out.println(s);
	}	
	
	public void solve() {
		Arrays.sort(src);
		Arrays.sort(dst);
		
		int ans = check(L, src);
		if(ans<INF)
			println(ans);
		else
			println("NOT POSSIBLE");
	}
	
	public int check(int len, long[] cur) {
		if(len==0)
			return 0;
		long mask = ((1l<<L)-1) ^ ((1l<<(len-1))-1);
		
		int ans=INF;
		
		boolean ok = true;
		for(int i=0; i<N; i++) {
			if((cur[i]&mask) != (dst[i]&mask)) {
				ok = false;
				break;
			}
		}
		if(ok)
			ans = Math.min(ans, check(len-1, cur));
		
		long[] rev = new long[N];
		for(int i=0; i<N; i++)
			rev[i] = cur[i]^(1l<<(len-1));
		Arrays.sort(rev);

		ok = true;
		for(int i=0; i<N; i++) {
			if((rev[i]&mask) != (dst[i]&mask)) {
				ok = false;
				break;
			}
		}
		if(ok)
			ans = Math.min(ans, check(len-1, rev)+1);

		return ans;
	}
}
