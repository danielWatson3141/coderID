import java.util.*;
import java.io.*;

public class RandomPermutation {
	
	public static void main(String[] args) throws IOException {
	//	int n = 3;
	//	System.out.println(-n*Math.log(n));
	//	holdTest2();
		int atasi = 1000;
		holdTest(atasi);
		String filename = "test";
		Scanner sc = new Scanner(new File(filename));
		int asoci = sc.nextInt();
		int[] arr = new int[1000];
		Pair[] p = new Pair[asoci];
		double x = 1000; // should be 1000
		double thres = x*Math.log(x);
	//	System.out.println(thres);
		PrintWriter pw = new PrintWriter(System.out);
		for(int t=1; t<=asoci; t++){
			atasi = sc.nextInt();
			for(int j=0; j<atasi; j++){
				arr[j] = sc.nextInt();
			}
			double val = value(arr, atasi)/thres;
	//		pw.println(val);
	//		System.out.println(Arrays.toString(arr));
			p[t-1] = new Pair(t, val);
		}
		Arrays.sort(p, Pair.comp);
		boolean[] g = new boolean[121];
		for(int i=0; i<60; i++){
			g[p[i].x] = true;
		}
		for(int t=1; t<=120; t++){
			if(g[t]){
				pw.println("Case #"+t+": GOOD");
			}
			else{
				pw.println("Case #"+t+": BAD");
			}
		}
		pw.flush();
		pw.close();
	//	System.out.println(Arrays.toString(p));
	//	Arrays.sort(p, Pair.comp);
	//	System.out.println(Arrays.toString(p));
	}
	
	static final int N = 1000;
	
	
	static double[][] CNT = new double[1001][1001];
	static int[][] cnt = new int[1001][1001];
	
	private static void holdTest2(){
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		int sz = 3;
		for(int i=0; i<1000000; i++){
			int[] res = generateBad(sz);
			String s = "";
			for(int j=0; j<res.length; j++) s += " "+res[j];
			if(!map.containsKey(s)) map.put(s, 0);
			map.put(s, map.get(s)+1);
		}
		Iterator<String> iter = map.keySet().iterator();
		while(iter.hasNext()){
			String cur = iter.next();
			StringTokenizer tok = new StringTokenizer(cur);
			int[] arr = new int[sz];
			for(int a=0; a<sz; a++) arr[a] = Integer.parseInt(tok.nextToken());
			int cnt = 0;
			int max = 0;
			for(int a=0; a<sz; a++){
				if(arr[a]==a) cnt++;
				max = Math.max(max, Math.abs(arr[a]-a));
			}
			System.out.println(cur+": "+map.get(cur)+" "+max);
		}
	}
	
	private static void holdTest(int sz){
		for(int i=0; i<10000; i++){
			int[] arr = generateBad(sz);
			for(int j=0; j<sz; j++){
				cnt[j][arr[j]] ++;
			}
		}
		for(int i=0; i<sz; i++){
			double total = 0;
			for(int j=0; j<sz; j++){
				total += cnt[i][j];
			}
			for(int j=0; j<sz; j++){
				CNT[i][j] = (cnt[i][j] / total);
			}
			if(i==1) System.out.println(Arrays.toString(CNT[i]));
		}
	}
	
	private static double value(int[] arr, int size){
		double res = 0;
		for(int i=0; i<size; i++){
			res += -Math.log(CNT[i][arr[i]]);
		}
		return res;
	}
	
	private static int[] generateBad(int size){
		int[] a = new int[size];
		for(int i=0; i<size; i++) a[i] = i;
		for(int i=0; i<size; i++){
			int rand = Math.abs(rgen.nextInt())%size;
			int temp = a[i];
			a[i] = a[rand];
			a[rand] = temp;
		}
		return a;
	}
	
	
	
	static Random rgen = new Random();
	
}

class Pair{
	public int x;
	public double y;
	
	public Pair(int x, double y){
		this.x = x;
		this.y = y;
	}
	
	public static Comparator<Pair> comp = new Comparator<Pair>() {
		
		@Override
		public int compare(Pair arg0, Pair arg1) {
			// TODO Auto-generated method stub
			return arg0.y>arg1.y ? 1 : (arg0.y<arg1.y ? -1: arg0.x - arg1.x);
		}
	};
	
	public String toString(){
		return x+" : "+y;
	}
	
}
