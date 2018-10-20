import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static int maxLen;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			int n = readInt();
			int l = readInt();
			maxLen = l;
			String[] list = new String[n];
			for(int i = 0; i < n; i++) {
				list[i] = nextToken();
			}
			HashMap<String, Integer> map = new HashMap<String, Integer>();
			for(int i = 0; i < n; i++) {
				String s = nextToken();
				for(int a = 1; a <= l; a++) {
					String key = s.substring(0, a);
					if(!map.containsKey(key)) {
						map.put(key, 0);
					}
					map.put(key, 1 + map.get(key));
				}
			}
			int ret = Math.min(solve(list, 0, 1, map), solve(list, 1, 1, map));
			if(ret >= 200) {
				pw.println("NOT POSSIBLE");
			}
			else {
				pw.println(ret);
			}
		}
		pw.close();
	}

	public static int solve(String[] list, long mask, int len, Map<String, Integer> map) {
		Map<String, Integer> temp = new HashMap<String, Integer>();
		for(String out: list) {
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < len; i++) {
				int val = out.charAt(i) - '0';
				if((mask&(1L<<i)) != 0) {
					val ^= 1;
				}
				sb.append(val);
			}
			String key = sb.toString();
			if(!temp.containsKey(key)) {
				temp.put(key, 0);
			}
			temp.put(key, 1 + temp.get(key));
		}
		for(String out: temp.keySet()) {
			if(!map.containsKey(out) || map.get(out).intValue() != temp.get(out).intValue()) {
				return 200;
			}
		}
		if(len == maxLen) {
			return Long.bitCount(mask);
		}
		return Math.min(solve(list, mask, len+1, map), solve(list, mask | (1L << len), len+1, map));
	}
	
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}

	public static String readLine() throws IOException	{
		st = null;
		return br.readLine();
	}

}
