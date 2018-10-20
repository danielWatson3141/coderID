
import java.util.*;
import java.io.*;

public class Main {
	public static long time = 0;
	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		
		IN = System.in;
		OUT = System.out;
		if (true){
			IN = new FileInputStream("input.txt");
			OUT = new FileOutputStream("output.txt");
		}
		in = new BufferedReader(new InputStreamReader(IN));
		out = new PrintWriter(OUT, FLUSH);
		solveTwo();
		out.flush();
	}
	public static void swap(int[] l1, int a, int b){
		int temp = l1[a];
		l1[a] = l1[b];
		l1[b] = temp;
	}
	public static void goodShuffle(int[] l1){
		for (int i = 0 ; i < l1.length; i++){
			l1[i] = i;
		}
		for (int i = 0 ; i < l1.length; i++){
			int rand = (int)(Math.random() * l1.length - i) + i;
			swap(l1, i , rand);
		}
	}
	public static void badShuffle(int[] l1){
		for (int i = 0 ; i < l1.length; i++){
			l1[i] = i;
		}
		for (int i = 0 ; i < l1.length; i++){
			int rand = (int)(Math.random() * l1.length);
			swap(l1, i , rand);
		}
	}
	public static int[] badShuffle(int n1){
		int[] fin = new int[n1];
		for (int i = 0; i < n1; i++) fin[i] = i;
		for (int i = 0 ; i < n1; i++){
			int rand = (int)(Math.random() * n1);
			swap(fin, i, rand);
		}
		return fin;
	}
	public static double[][] stats = null;
	public static int k1 = 100;
	public static boolean isGood(int[] l1, boolean isGood){
		double score = 0;
		for (int i = 0 ; i < k1; i++){
			int idx = i;
			int val = l1[idx];
			if (stats[val][i] > 1){
			}
			score += Math.pow(stats[val][i], 10);
		}
//		px(isGood, score, cnt);
		return score < 200 ? false: true;
	}
	public static double factReverse(int n1){
		double fin = 1;
		for (int i = 1; i <= n1; i++){
			fin /= i;
		}
		return fin;
	}
	public static HashMap<ArrayList<Integer>, Integer> m1 = new HashMap<>();
	public static void solveOne() throws Exception {
		
	}
	public static class C implements Comparable<C>{
		int[] cont = null;
		int idx = 0;
		public double score (){
			double fin = 0;
			for (int i = 0; i <cont.length; i++){
				double diff = i - cont[i];
				fin += diff * diff;
			}
			return fin;
		}
		@Override
		public int compareTo(C arg0) {
			double k1 = this.score() - arg0.score();
			if (k1 > 0) return 1;
			if (k1 < 0) return -1;
			return 0;
		}
		
	}
	public static void solveTwo() throws Exception {
		int no = ni();
		C[] l1 = new C[no];
		for (int i = 0 ; i < l1.length; i++){
			l1[i] = new C();
		}
		boolean[] res = new boolean[no];
		Arrays.fill(res, true);
		for (int i = 0; i < no; i++){
			int n1 = ni();
			l1[i].cont = new int[n1];
			for (int j = 0; j < n1; j++ ){
				l1[i].cont[j] = ni();
			}
			l1[i].idx = i;
		}
		Arrays.sort(l1);
		for (C e : l1){
			px(e.cont);
		}
		for (int i = 0; i < no / 2; i++){
			res[l1[i].idx] = false;
		}
		for (int kase = 1; kase <= no; kase++){
			out.printf("Case #%d: ", kase);
			out.print(res[kase - 1] ? "GOOD" : "BAD" );
			out.println();
		}
	}
	
	public static void solveThree() throws Exception {
		
	}
	
	public static BufferedReader in;
	public static StringTokenizer st;
	public static InputStream IN;
	public static OutputStream OUT;
	public static String nx() throws Exception {
		for (;st == null || !st.hasMoreTokens();){
			String k1 = in.readLine();
			if (k1 == null) return null;
			st = new StringTokenizer(k1);
		}
		return st.nextToken();
	}
	public static int ni () throws Exception {
		return Integer.parseInt(nx());
	}
	public static long nl() throws Exception{
		return Long.parseLong(nx());
	}
	public static double nd() throws Exception{
		return Double.parseDouble(nx());
	}
	public static void px(Object ... l1){
		System.out.println(Arrays.deepToString(l1));
	}
	public static boolean FLUSH = false;
	public static PrintWriter out;
	public static void p(Object ... l1){
		for (int i = 0; i < l1.length; i++){
			if (i != 0) out.print(' ');
			out.print(l1[i].toString());
		}
	}
	public static void pn(Object ... l1){
		for (int i = 0; i < l1.length; i++){
			if (i != 0) out.print(' ');
			out.print(l1[i].toString());
		}
		out.println();
	}
	
	public static void pn(Collection l1){
		boolean first = true;
		for (Object e: l1){
			if (first) first = false;
			else out.print(' ');
			out.print(e.toString());
		}
		out.println();
	}

}
