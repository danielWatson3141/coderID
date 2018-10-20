import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	
	public static Scanner in;
	public static PrintWriter out;
	public static int flips;
	
	public static void main(String[] args) throws FileNotFoundException {
		boolean sample = false;
		String input = "A-large.in";
		String output = "A-large.out";
		if(sample){
			input = "bigsample.in";
			output = "bigsample.out";
		}
		
		in = new Scanner(new File(input));
		out  = new PrintWriter(new File(output));
		
		int t = in.nextInt();
		for(int c = 1; c <= t; c++){
			solve(c);
		}
		
		
		in.close();
		out.close();
	}
	
	
	public static void solve(int t){
		int n = in.nextInt();
		int l = in.nextInt();
		
		char [][] flow = new char [n][l];
		char [][] req = new char[n][l];
		
		for(int i = 0; i < n; i++){
			flow[i] = in.next().toCharArray();
		}
		
		
		
		for(int i = 0; i < n; i++){
			req[i] = in.next().toCharArray();
		}
		flips = Integer.MAX_VALUE;
		
		
		//flip(flow, 1);
		//System.out.println(validToL(flow, req, 1));
		
		find(flow, req, 0, 0);
		
		if(flips == Integer.MAX_VALUE){
			System.out.printf("Case #%d: NOT POSSIBLE\n", t);
			out.printf("Case #%d: NOT POSSIBLE\n", t);
		}
		else{
			System.out.printf("Case #%d: %d\n", t, flips);
			out.printf("Case #%d: %d\n", t, flips);
		}
		
	}
	
	public static void find(char [][] flow, char [][] req, int l, int f){
		if(l >= flow[0].length){
			flips = Math.min(f, flips);
			return;
		}
		
		if(f >= flips)
			return;
		
		if(validToL(flow, req, l)){
			find(flow, req, l+1, f);
		}
		
		flip(flow, l);
		if(validToL(flow, req, l)){
			find(flow, req, l+1, f+1);
		}
		flip(flow, l);
	}
	
	public static boolean validToL(char[][] flow, char[][]req , int l){
		boolean [] matched = new boolean[flow.length];
		int numMatched = 0;
		
		for(int x = 0; x < req.length; x++){
			
			boolean reqFound = false;
			
			for(int i = 0; i < flow.length && !reqFound; i++){
				if(!matched[i]){
					boolean ok = true;
					for(int j = 0; j <= l && ok; j++){
						if(flow[i][j] != req[x][j]){
							ok = false;
						}
					}
					if(ok){
						matched[i] = true;
						numMatched++;
						reqFound = true;
					}
				}
			}
		}
		
		return numMatched == flow.length;
	}
	
	
	public static void flip(char[][] flow, int l){
		for(int i = 0; i < flow.length; i++){
			if(flow[i][l] == '0')
				flow[i][l] = '1';
			else
				flow[i][l] = '0';
		}
	}
}
