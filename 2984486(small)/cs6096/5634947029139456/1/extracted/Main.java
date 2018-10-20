
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
	public static String decode(char[] outlet, char[] need){
		char[] fin = new char[need.length];
		for (int i = 0; i < need.length; i++){
			if (need[i] == outlet[i]){
				fin[i] = '0';
			}
			else {
				fin[i] = '1';
			}
		}
		return String.valueOf(fin);
	}
	public static String encode(String code, char[] outlet){
		char[] fin = new char[outlet.length];
		for (int i = 0 ; i < fin.length; i++){
			char cur = outlet[i];
			if (code.charAt(i) == '0'){
				fin[i] = cur;
				
			}
			else {
				if (cur == '0'){
					fin[i] = '1';
				}
				else {
					fin[i] = '0';
				}
			}
		}
		return String.valueOf(fin);
	}
	public static void solveOne() throws Exception {
		int no = ni();
		for (int kase = 1; kase <= no; kase++){
			int best = Integer.MAX_VALUE;
			int n = ni();
			ni();
			char[][] outletList = new char[n][];
			for (int i = 0 ; i < n; i++){
				outletList[i] = nx().toCharArray();
			}
			char[][] needList = new char[n][];
			String[] wantList = new String[n];
			for (int i = 0 ; i < n; i++){
				needList[i] = nx().toCharArray();
				wantList[i] = String.valueOf(needList[i]);
			}
			HashSet<String> dp1 = new HashSet<>();
			HashSet<String> dp2 = new HashSet<>();
			for (int i = 0; i < needList.length; i++){
				char[] e = needList[i];
				for (char[] f: outletList){
					String cur = decode(f, e);
					if (i == 0){
						dp2.add(cur);
					}
					else {
						if (dp1.contains(cur)){
							dp2.add(cur);
						}
					}
				}
				dp1 = dp2;
				dp2 = new HashSet();
//				px(dp1);
			}
			Arrays.sort(wantList);
			for (String e: dp1){
				int ptr = 0;
				String[] cur = new String[n];
				for (char[] f: outletList){
					cur[ptr++] = encode(e, f);
				}
				Arrays.sort(cur);
				if (Arrays.equals(cur, wantList) ){
					
					int cnt = 0;
					for (char f: e.toCharArray()) if (f == '1') cnt++;
					if (best > cnt) best = cnt;
					px("cnt",cnt, e);
				}
			}
			
			px("ans", kase, best);
			out.printf("Case #%d: ", kase);
			if (best == Integer.MAX_VALUE){
				out.print("NOT POSSIBLE");
			}
			else {
				out.print(best);
			}
			
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
