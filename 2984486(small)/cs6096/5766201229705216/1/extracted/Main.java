
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
		solveOne();
		out.flush();
	}
	public static int bfs(ArrayList<Integer>[] al, int at, int from){
		int ans = 1;
		ArrayList<Integer> val = new ArrayList<>();
		for (int e : al[at]){
			if (e == from) continue;
			int cur = bfs(al, e, at);
			val.add(cur);
		}
		if (val.size() < 2) return ans;
		Collections.sort(val);
		ans += val.get(val.size() - 1);
		ans += val.get(val.size() - 2);
		return ans;
	}
	
	public static void solveOne() throws Exception {
		int no = ni();
		for (int kase = 1; kase <= no; kase++){
			int n1 = ni();
			ArrayList<Integer>[] adjList = new ArrayList[n1];
			for (int i = 0 ; i < n1; i++){
				adjList[i] = new ArrayList();
			}
			for (int i = 0; i < n1 - 1; i++){
				int a = ni() - 1;
				int b= ni() - 1;
				adjList[a].add(b);
				adjList[b].add(a);
			}
			int ans = 1;
			for (int i =0 ; i < n1; i++){
				int val = bfs(adjList, i, -1);
				if (val > ans) ans = val;
			}
			px("ans", kase, ans, n1 - ans);
			out.printf("Case #%d: ", kase);
			out.print(n1 - ans);
			out.println();
		}
	}
	
	public static void solveTwo() throws Exception {
		
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
