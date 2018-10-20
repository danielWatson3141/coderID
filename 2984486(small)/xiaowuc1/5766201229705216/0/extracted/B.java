import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static LinkedList<Integer>[] edges;
	static int[] parent;
	static int[] dp;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("b.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			int n = readInt();
			edges = new LinkedList[n];
			parent = new int[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			for(int qqq = 1; qqq < n; qqq++) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			int ret = 0;
			for(int chose = 0; chose < n; chose++) {
				Arrays.fill(parent, -1);
				parent[chose] = -2;
				LinkedList<Integer> q = new LinkedList<Integer>();
				q.add(chose);
				while(!q.isEmpty()) {
					int curr = q.removeFirst();
					for(int out: edges[curr]) {
						if(parent[out] == -1) {
							parent[out] = curr;
							q.add(out);
						}
					}
				}
				dp = new int[n];
				ret = Math.max(ret, solve(chose));
			}
			pw.println(n-ret);
		}
		pw.close();
	}

	public static int solve(int curr) {
		if(dp[curr] > 0) return dp[curr];
		int ret = 0;
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int out: edges[curr]) {
			if(parent[out] == curr) {
				list.add(solve(out));
			}
		}
		if(list.size() >= 2) {
			Collections.sort(list);
			ret = 1 + list.get(list.size()-1) + list.get(list.size()-2);
		}
		else {
			ret = 1;
		}
		dp[curr] = ret;
		return ret;
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
