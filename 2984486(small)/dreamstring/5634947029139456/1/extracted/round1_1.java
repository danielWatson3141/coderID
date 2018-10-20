package codejam;

import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class round1_1 {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args) {
		round1_1 test = new round1_1();
		test.start();
	}
	
	public void solve() throws IOException {
		int num_test = readInt();
		for (int i = 0; i < num_test; ++i) {
			int N = readInt();
			int L = readInt();
			int[][] data = new int[N][L];
			for (int j = 0; j < N; ++j) {
				String str = readString();
				for (int k = 0; k < L; ++k) {
					data[j][k] = str.charAt(k)-'0';
				}
			}
			int[][] dest = new int[N][L];
			for (int j = 0; j < N; ++j) {
				String str = readString();
				for (int k = 0; k < L; ++k) {
					dest[j][k] = str.charAt(k)-'0';
				}
			}
			solveEach(data, dest, i+1);
		}
	}
	
	public void solveEach(int[][] data, int[][] dest, int num_test) {
		out.print("Case #" + num_test + ": ");

		int num_flip = dfs(data, dest, 0, 0);
		if (num_flip == -1) {
			out.println("NOT POSSIBLE");
		} else {
			out.println(num_flip);
		}
		System.out.println("Solved " + num_test);
	}
	
	public int dfs(int[][] data, int[][] dest, int col, int num_flip) {
		int N = data.length;
		int L = data[0].length;
		if (col == L) {
			return num_flip;
		}
		
		int dfs_result_1 = -1;
		int dfs_result_2 = -1;
		if (isValid(data, dest, col)) {
			dfs_result_1 = dfs(data, dest, col+1, num_flip);
		}
		
		flip(data, col);
		if (isValid(data, dest, col)) {
			dfs_result_2 = dfs(data, dest, col+1, num_flip+1);
		}
		flip(data, col); // flip back
		if (dfs_result_1 == -1 && dfs_result_2 == -1) {
			return -1;
		} else if (dfs_result_1 == -1 || dfs_result_2 == -1) {
			return dfs_result_1 == -1 ? dfs_result_2 : dfs_result_1;
		} else {
			return Math.min(dfs_result_1, dfs_result_2);
		}
	}

	public void flip(int[][] a, int col) {
		for (int i = 0; i < a.length; ++i) {
			a[i][col] = (a[i][col] == 0) ? 1 : 0;
		}
	}
	
	public boolean isValid(int[][] data, int[][] dest, int col) {
		int N = data.length;
		
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= col; ++j) {
				sb.append((char)(dest[i][j]+'0'));
			}
			String str = sb.toString();
			if (map.containsKey(str)) {
				map.put(str, map.get(str)+1);
			} else {
				map.put(str, 1);
			}
			sb.delete(0, col+1);
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= col; ++j) {
				sb.append((char)(data[i][j]+'0'));
			}
			String str = sb.toString();
			if (map.containsKey(str)) {
				map.put(str, map.get(str)-1);
				if (map.get(str) == 0) {
					map.remove(str);
				}
			} else {
				return false;
			}
			sb.delete(0, col+1);
		}
		return map.isEmpty();
	}

	public void start()
	{
		try {
			/*in = new BufferedReader(new FileReader("/Users/congli/Documents/javaworkspace/usaco/src/com/congli/usaco/input.txt"));
			out = new PrintWriter(System.out);*/
			in = new BufferedReader(new FileReader("/Users/congli/Downloads/A-large.in"));
			out = new PrintWriter(new BufferedWriter(new FileWriter("/Users/congli/Documents/javaworkspace/codejam/src/codejam/output.txt")));
			solve();
			in.close();
			out.close();
		} catch (Throwable t) {
			// TODO Auto-generated catch block
			t.printStackTrace();
		}
	}
	
	public String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	public long readLong() throws IOException {
		return Long.parseLong(readString());
	}

	public double readDouble() throws IOException {
		return Double.parseDouble(readString());
	}
}
