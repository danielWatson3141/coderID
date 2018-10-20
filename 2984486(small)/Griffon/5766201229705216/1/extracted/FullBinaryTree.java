package fullBinaryTree;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class FullBinaryTree {
	
	interface ClassName {
		public String getClassName();
	}

	public static void main(String[] args) {

		ClassName name = new ClassName() {
			public String getClassName() {
				return this.getClass().getEnclosingClass().getSimpleName();
			}
		};
		String[] input, out;
		String folder = name.getClassName().replaceFirst("\\.\\w*", "");
		String file = "E:\\Ignacio\\Trabajo\\Codejam2014\\src\\" + folder
				+ "\\B-large.in";
		input = readTxt(file);
		out = execute(input);
		writeTxt(file, out);
	}

	private static void writeTxt(String file, String[] out) {

		try {
			PrintWriter pw = new PrintWriter(new FileWriter(file + ".txt"));
			for (int i = 0; i < out.length; i++) {
				pw.println(out[i]);
			}
			pw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static String[] readTxt(String file) {

		String line;
		String[] r = null;
		ArrayList<String> list = new ArrayList<String>();
		try {
			BufferedReader bf = new BufferedReader(new FileReader(file));
			while ((line = bf.readLine()) != null) {
				list.add(line);
			}
			bf.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

		r = list.toArray(new String[0]);
		return r;
	}

	public static String[] execute(String[] input) {

		String[] out = null;
		String[] splitted;				

		int test = 1;
		int ntests;

		ntests = Integer.parseInt(input[0]);
		out = new String[ntests];

		for (int i = 1; test < 1 + ntests;) {			
			int n = Integer.parseInt(input[i++]);						
			int[] x = new int[n-1];
			int[] y = new int[n-1];			
			for (int j = 0; j < n-1; j++) {
				splitted = input[i++].split("\\s");
				x[j] = Integer.parseInt(splitted[0]);
				y[j] = Integer.parseInt(splitted[1]);
			}			
			int result = minDeletions(x, y);
			out[test - 1] = "Case #" + test + ": " + result;
			System.out.println(out[test - 1]);

			test++;
		}
		return out;
	}
	
	static int[][] connected;
	static int[] edges;
	
	private static int minDeletions(int[] x, int[] y) {		
		int min = Integer.MAX_VALUE;
		int n = Math.max(max(x), max(y));
		buildGraph(n, x, y);
		for (int i = 0; i < n; i++) {
			int delete = minDelete(i+1, -1);
			if(delete<min)
				min = delete;			
		}		
		return min;
	}
	
	
	private static int max(int[] x) {
		int max = 0;
		for (int i = 0; i < x.length; i++) {
			if(x[i]>max)
				max = x[i];
		}
		return max;
	}

	private static void buildGraph(int n, int[] x, int[] y) {
		boolean[][] edge = new boolean[n][n];
		connected = new int[n][n];
		edges = new int[n];
		for (int i = 0; i < x.length; i++) {
			if(edge[x[i]-1][y[i]-1])
				continue;
			connected[x[i]-1][edges[x[i]-1]++] = y[i];
			connected[y[i]-1][edges[y[i]-1]++] = x[i];
			edge[x[i]-1][y[i]-1] = true;
		}
	}

	private static int minDelete(int node, int parent) {
		int childs = edges[node-1];
		if(parent>0)
			childs--;		
		if(childs==1)
			return recursiveChilds(node, parent)-1;
		else if(childs==0)
			return 0;
		
		int[][] childs_removal = new int[childs][2];		
		childs = 0;
		for (int i = 0; i < edges[node-1]; i++) {
			int ch = connected[node-1][i];
			if(ch==parent)
				continue;
			childs_removal[childs][1] = minDelete(ch, node);
			childs_removal[childs++][0] += recursiveChilds(ch, node);
		}
		
		Comparator<int[]> c = new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0]==b[0])
					return ((Integer)a[1]).compareTo(b[1]);
				return ((Integer)b[0]).compareTo(a[0]);
			}
		};
		Arrays.sort(childs_removal, c);
		int total = 0;
		for (int i = 0; i < 2; i++) {
			total += childs_removal[i][1];
		}
		for (int i = 2; i < childs; i++) {
			total += childs_removal[i][0];
		}
		return total;
	}

	private static int recursiveChilds(int node, int parent) {
		int count = 0;
		for (int i = 0; i < edges[node-1]; i++) {
			int ch = connected[node-1][i];
			if(ch==parent)
				continue;			
			count += recursiveChilds(ch, node);			
		}
		return count+1;
	}
}
