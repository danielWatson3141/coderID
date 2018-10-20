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
import java.util.Comparator;
import java.util.StringTokenizer;



public class A12014A {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new A12014A();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			int l = nextInt();
			char[][] outlets = new char[n][];
			for (int i = 0; i < outlets.length; i++) 
				outlets[i] = nextString().toCharArray();
			char[][] charge = new char[n][];
			for (int i = 0; i < outlets.length; i++) 
				charge[i] = nextString().toCharArray();
			Arrays.sort(charge, new comp());
			int min = l+1;
			for (int i = 0; i < (1<<l); i++) {
				if(check(outlets,i,charge)){
					min = Math.min(min, Integer.bitCount(i));
				}
			}
			writeln("Case #"+counter+": "+(min == l+1?"NOT POSSIBLE":(min+"")));
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	private static boolean check(char[][] outlets, int mask, char[][] charge) {
		play(outlets,mask);
		Arrays.sort(outlets , new comp());
		boolean eq = true;
		for (int i = 0; i < charge.length; i++) {
			for (int j = 0; j < charge[i].length; j++) {
				if(charge[i][j]!=outlets[i][j]) eq = false;
			}
		}
		play(outlets,mask);
		return eq;
	}

	private static void play(char[][] outlets, int mask) {
		for (int i = 0; i < outlets.length; i++) {
			for (int j = 0; j < outlets[i].length; j++) {
				if((mask & (1<<j)) != 0)
					outlets[i][j] = (outlets[i][j]=='0'?'1':'0'); 
			}
		}
	}

	public A12014A() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Template.in"));
		out = new PrintWriter("A12014A.out");
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

class comp implements Comparator<char []>{

	public int compare(char[] a, char[] b) {
		for (int i = 0; i < b.length; i++) {
			if(a[i] > b[i]) return -1;
			if(a[i] < b[i]) return 1;
		}
		return 0;
	}
	
}
