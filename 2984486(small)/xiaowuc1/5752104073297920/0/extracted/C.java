import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		int good = 0;
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			int n = readInt();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			int badness = -list[0];
			for(int i = 0; i < n-1; i++) {
				if(list[i] == (i+1)%n) {
					badness++;
				}
			}
			if(badness <= -475) {
				good++;
				pw.println("GOOD");
			}
			else {
				pw.println("BAD");
			}
		}
		System.out.println(good);
		pw.close();
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
