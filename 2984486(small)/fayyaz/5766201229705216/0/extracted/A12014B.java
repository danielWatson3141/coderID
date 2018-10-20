import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;



public class A12014B {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new A12014B();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			graph = new boolean[n][n];
			for (int i = 0; i < n-1; i++) {
				int a = nextInt()-1;int b = nextInt()-1;
				graph[a][b] = graph[b][a] = true;
			}
			size = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if(size[i][j] == 0 && graph[i][j])
						 size(i,j);
				}
			}
			del = new int[n][n];
			for (int i = 0; i < del.length; i++) 
				Arrays.fill(del[i], -1);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (del[i][j] == -1 && graph[i][j])
						binaryz(i,j);
				}
			}
			int ret = n+1;
			for (int i = 0; i < del.length ; i++) {
				ret = Math.min(ret, process(i));
			}
			writeln("Case #"+counter+": "+ret);
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	private static int process(int node) {
		int sum = 0;int count = 0;
		for (int i = 0; i < graph[node].length; i++) {
			if(graph[node][i]){
				sum += size[i][node];
				count++;
			}
		}
		if(count >= 2){
			PriorityQueue<Integer> dd = new PriorityQueue<Integer>();
			for (int i = 0; i < graph[node].length; i++) {
				if(graph[node][i]){
					int del = binaryz(i, node);
					dd.add(-1*(size[i][node] - del));
				}
			}
			sum += dd.poll();
			sum += dd.poll();
		}
		return sum;
	}

	private static int binaryz(int node, int parent) {
		if(del[node][parent]!=-1) return del[node][parent];
		int sum = 0;int count = 0;
		for (int i = 0; i < graph[node].length; i++) {
			if(i==parent) continue;
			if(graph[node][i]){
				sum += size[i][node];
				count++;
			}
		}
		if(count >= 2){
			PriorityQueue<Integer> dd = new PriorityQueue<Integer>();
			for (int i = 0; i < graph[node].length; i++) {
				if(i==parent) continue;
				if(graph[node][i]){
					int del = binaryz(i, node);
					dd.add(-1*(size[i][node] - del));
				}
			}
			sum += dd.poll();
			sum += dd.poll();
		}
		return del[node][parent] = sum;
	}

	private static int size(int i, int j) {
		if(size[i][j] !=0 ) return size[i][j];
		int val = 0;
		for (int k = 0; k < graph[i].length; k++) {
			if(k == j) continue;
			if(graph[i][k])
				val += size(k, i);
		}
		return size[i][j] = val + 1;
	}

	static boolean [][] graph;
	static int [][] size;
	static int [][] del;
	
	public A12014B() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Template.in"));
		out = new PrintWriter("A12014B.out");
		//-------------------------------------------------------------------------
		//Initalize Stringtokenizer input
		input = new StringTokenizer(in.readLine());
	}

	private static int nextInt() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Integer.parseInt(input.nextToken());
	}
	private static long nextLong() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Long.parseLong(input.nextToken());
	}
	private static double nextDouble() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Double.parseDouble(input.nextToken());
	}
	private static String nextString() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return input.nextToken();
	}
	private static void write(String output){
		out.write(output);
		out.flush();
	}
	private static void writeln(String output){
		out.write(output+"\n");
		out.flush();
	}
	private static void end() throws IOException{
		in.close();
		out.close();
		System.exit(0);
	}
	
}
