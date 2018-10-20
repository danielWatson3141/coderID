package gcj2014.r1;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class ASmall {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + ASmall.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		int n = ni(), L = ni();
		long[] a = new long[n];
		long[] b = new long[n];
		for(int i = 0;i < n;i++){
			a[i] = Long.parseLong(in.next(), 2);
		}
		for(int i = 0;i < n;i++){
			b[i] = Long.parseLong(in.next(), 2);
		}
		Arrays.sort(b);
		int min = 9999;
		for(int i = 0;i < 1<<L;i++){
			long[] c = new long[n];
			for(int j = 0;j < n;j++){
				c[j] = a[j] ^ i;
			}
			Arrays.sort(c);
			if(Arrays.equals(b, c)){
				min = Math.min(min, Integer.bitCount(i));
			}
		}
		if(min == 9999){
			out.println("NOT POSSIBLE");
		}else{
			out.println(min);
		}
	}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public ASmall(int cas, Scanner in, PrintWriter out)
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
			new ASmall(i+1, in, out).call();
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
