package con2014R1a;

import java.io.*;
import java.util.*;

public class A {
	
//	private static final String islarge = "-large";
	private static final String fileName = "results/con2014R1a/"+A.class.getSimpleName().toLowerCase();//+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	static final String NOTPOSSIBLE = "NOT POSSIBLE";
	private void solve() {
		int N = in.nextInt(),
			L = in.nextInt();
		long[] A = new long[N],
			B = new long[N];
		// read start values
		for(int i=0;i<N;i++){
			String s = in.next();
			for(int l=0;l<L;l++){
				A[i]*=2;
				if(s.charAt(l)=='1'){
					A[i]++;
				}
			}
		}
		// read end values
		for(int i=0;i<N;i++){
			String s = in.next();
			for(int l=0;l<L;l++){
				B[i]*=2;
				if(s.charAt(l)=='1'){
					B[i]++;
				}
			}
		}
		Arrays.sort(B);
		long[]C = new long[N];
		int res = L+1;
		F1:
		for(int i=0;i<N;i++){
			long xor = A[i]^B[0];
			for(int j=0;j<N;j++){
				C[j]=A[j]^xor;
			}
			Arrays.sort(C);
			for(int j=0;j<N;j++){
				if(C[j]!=B[j])continue F1;
			}
			int tot = 0;
			for(int j=0;j<=40;j++){
				if((xor&(1L<<j)) > 0){
					tot++;
				}
			}
			res = Math.min(res, tot);
		}
		if(res > L){
			out.println(NOTPOSSIBLE);
		}else{
			out.println(res);
		}
	}
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
