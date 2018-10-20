package codejam2014round1AC;

import java.util.*;
import java.io.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Main {

//	Scanner sc = new Scanner(in);
	Scanner sc; 
	PrintWriter pw;
	
	void run() {
		try {
			sc = new Scanner(new File("/Users/ryo/Documents/procon/codejam2014r1a/C-small-attempt3.in"));
			pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("/Users/ryo/Documents/procon/codejam2014r1a/C-small-attempt3.out"))));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		int t = sc.nextInt();
		
		for (int x = 1; x <= t; x++) {
			int n = sc.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
			}
			
			int count = 0;
			for (int i = 0; i < n; i++) {
				count += (i == a[i]) ? 1: 0;
			}
//			out.println(count);
			if (count > 2) {
				pw.printf("Case #%d: BAD\n", x);
			} else {
				pw.printf("Case #%d: GOOD\n", x);
			}
		}
		sc.close();
		pw.close();
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}