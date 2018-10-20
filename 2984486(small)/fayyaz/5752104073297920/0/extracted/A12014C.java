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
import java.util.Random;
import java.util.StringTokenizer;



public class A12014C {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	private static Random r = new Random();
	private static Random rr = new Random();
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new A12014C();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			int [] p = new int[n];
			for (int i = 0; i < p.length; i++) p[i] = nextInt();
			int itr = n;
			boolean good = true;
			while(itr-->0){
				if(good(n,p)){
					writeln("Case #"+counter+": "+("GOOD"));
					good = false;
					break;
				}
				if(bad(n,p)){
					writeln("Case #"+counter+": "+("BAD"));
					good = false;
					break;
				}	
			}
			if(good)
				writeln("Case #"+counter+": "+("GOOD"));
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	private static boolean bad(int n,int []  res) {
		int [] nums = new int[n];
		for (int i = 0; i < nums.length; i++) {
			nums[i] = i;
		}
		for (int i = 0; i < nums.length; i++) {
			int p = r.nextInt(n);
			int t = nums[i];
			nums[i] = nums[p];
			nums[p] = t;
		}
		return equal(res,nums);
	}
	
	private static boolean good(int n,int []  res) {
		int [] nums = new int[n];
		for (int i = 0; i < nums.length; i++) {
			nums[i] = i;
		}
		for (int i = 0; i < nums.length; i++) {
			int p = i + rr.nextInt(n-i);
			int t = nums[i];
			nums[i] = nums[p];
			nums[p] = t;
		}
		return equal(res,nums);
	}
	
	private static boolean equal(int[] res, int[] nums) {
		for (int i = 0; i < nums.length; i++) {
			if(res[i]!=nums[i]) return false;
		}
		return true;
	}

	public A12014C() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Template.in"));
		out = new PrintWriter("A12014C.out");
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
