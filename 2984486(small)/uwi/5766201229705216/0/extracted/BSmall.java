package gcj2014.r1;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class BSmall {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + BSmall.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		int n = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int min = 9999;
		outer:
		for(int i = 0;i < (1<<n)-1;i++){ // erase
			DJSet ds = new DJSet(n);
			for(int j = 0;j < n;j++){
				for(int e : g[j]){
					if(i<<31-j>=0 && i<<31-e>=0){
						ds.union(j, e);
					}
				}
			}
			for(int j = 0;j < n;j++){
				for(int k = j+1;k < n;k++){
					if(i<<31-j >= 0 && i<<31-k >= 0){
						if(!ds.equiv(j, k))continue outer;
					}
				}
			}
			
			int[] degf = new int[4];
			for(int j = 0;j < n;j++){
				if(i<<31-j >= 0){
					int deg = 0;
					for(int e : g[j]){
						if(i<<31-e>=0){
							deg++;
						}
					}
					if(deg > 3){
						continue outer;
					}
					degf[deg]++;
				}
			}
			if(degf[0] == 0){
				if(!(degf[3] + 2 == degf[1] && degf[2] == 1))continue outer;
			}
			min = Math.min(min, Integer.bitCount(i));
		}
		out.println(min);
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if(x != y){
				if(upper[y] < upper[x]){
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for(int u : upper)
				if(u < 0)
					ct++;
			return ct;
		}
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public BSmall(int cas, Scanner in, PrintWriter out)
	{
		this.cas = cas;
		this.in = in;
		this.out = out;
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		boolean real = INPUT.isEmpty();
		
		if(real){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
		Scanner in = real ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = real ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			new BSmall(i+1, in, out).call();
			out.flush();
			if(real)System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
		if(real){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
	}
}
