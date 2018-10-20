import java.util.*;
public class c {
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int n = 1000;
		long[][] bfreq = new long[n][n];
		long[][] gfreq = new long[n][n];
		Random r = new Random();
		int iters = 100000;
		for(int i = 0;i<iters;i++){
			int[] cperm = new int[n];
			for(int j = 0;j<n;j++){
				cperm[j] = j;
			}
			for(int j = 0;j<n;j++){
				int p = r.nextInt(n);
				int temp = cperm[j];
				cperm[j] = cperm[p];
				cperm[p] = temp;
			}
			for(int j = 0;j<n;j++){
				bfreq[j][cperm[j]]++;
			}
			cperm = new int[n];
			for(int j = 0;j<n;j++){
				cperm[j] = j;
			}
			for(int j = 0;j<n;j++){
				int p = r.nextInt(n-j)+j;
				int temp = cperm[j];
				cperm[j] = cperm[p];
				cperm[p] = temp;
			}
			for(int j = 0;j<n;j++){
				gfreq[j][cperm[j]]++;
			}
		}
//		for(int i = 0;i<n;i++){
//			for(int j = 0;j<n;j++){
//				System.out.print(bfreq[i][j]*1.0/iters+" ");
//			}
//			System.out.println();
//		}
//		System.out.println();
//		for(int i = 0;i<n;i++){
//			for(int j = 0;j<n;j++){
//				System.out.print(gfreq[i][j]*1.0/iters+" ");
//			}
//			System.out.println();
//		}
		System.out.println("done");
		int t = br.nextInt();
		Score[] ss = new Score[t];
		for(int c = 1;c<=t;c++){
			int rn = br.nextInt();
			int[] perm = new int[rn];
			for(int i = 0;i<rn;i++){
				perm[i] = br.nextInt();
			}
			long gs = 0;
			long bs = 0;
			for(int i = 0;i<rn;i++){
				gs+=gfreq[i][perm[i]];
				bs+=bfreq[i][perm[i]];
			}
			ss[c-1] = new Score(gs, bs, c-1);
		}
		Arrays.sort(ss);
		String[] ans = new String[t];
		int ga = 0;
		for(int i = 0;i<t;i++){
			if(((ss[i].gs-ss[i].bs >= 0) || i < t*1.0/2.3) && !(ga > 62)){
				ans[ss[i].index] = "GOOD";
				ga++;
			}
			else{
				ans[ss[i].index] = "BAD"; 
			}
		}
		for(int i = 0;i<t;i++){
			System.out.println("Case #"+(i+1)+": "+ans[i]);
		}
	}
	public static class Score implements Comparable<Score>{
		long gs, bs;
		int index;
		public Score(long a, long b, int c){
			gs = a;
			bs = b;
			index = c;
		}
		public int compareTo(Score o){
			return (int)Math.signum((gs-bs)-(o.gs-o.bs));
		}
	}
}
