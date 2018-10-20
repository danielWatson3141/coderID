import java.util.*;
import java.io.*;

public class Solution {

	private static Scanner in;
	private static PrintWriter out;

	//input
	private static int n, l;
	private static boolean[][] source;
	private static boolean[][] target;

	private static int res;

	private static void readBits(boolean[][] bits){
		String s = in.nextLine();
		String[] tmp = s.split(" ");
		for(int i = 0; i < n; i = i + 1){
			for(int j = 0; j < l; j = j + 1){
				bits[j][i] = (tmp[i].charAt(j) == '1'? true:false);
			}
		}
	}

	private static StringBuilder[] getString(boolean[][] bits){
		StringBuilder[] builder = new StringBuilder[n];
		for(int i = 0; i < n; i ++){
			builder[i] = new StringBuilder();
			for(int j = 0; j < l; j ++){
				builder[i].append(bits[j][i] == true? 1:0);
			}
		}
		return builder;
	}

	private static boolean check(StringBuilder[] sou, StringBuilder[] tar){
		HashSet<String> set = new HashSet<String>();
		for(int i = 0; i < sou.length; i ++){
			set.add(sou[i].toString());
		}
		for(int i = 0; i < tar.length; i ++){
			if(!set.contains(tar[i].toString())){
				return false;
			}
		}
		return true;
	}

	private static void dfs(int i, int count){
		if(check(getString(source), getString(target))){
			//get it
			if(res > count){
				res = count;
			}
			return;
		}
		else if(i == l){
			//impossible
			return;
		}
		else{
			for(int j = 0; j < source[i].length; j ++){
				source[i][j] = !source[i][j];
			}
			dfs(i + 1, count + 1);
			for(int j = 0; j < source[i].length; j ++){
				source[i][j] = !source[i][j];
			}
			dfs(i + 1, count);
		}
	}

	private static void solve(){
		res = Integer.MAX_VALUE;
		dfs(0, 0);
		if(res == Integer.MAX_VALUE){
			out.println("NOT POSSIBLE");
		}
		else{
			out.println(res);
		}
	} 


	public static void main(String[] args) throws IOException {
		File inFile = new File("A-small-attempt0.in");
		File outFile = new File("A-small.out");
		in = new Scanner(inFile);
		out = new PrintWriter(outFile);

		int t = in.nextInt();
		for(int k = 1; k <= t; k = k + 1){
			n = in.nextInt();
			l = in.nextInt();
			in.nextLine();
			source = new boolean[l][n];
			target = new boolean[l][n];
			readBits(source);
			readBits(target);
			out.print("Case #" + k + ": ");
			solve();
		}
		
		in.close();
		out.close();
	}
	
}