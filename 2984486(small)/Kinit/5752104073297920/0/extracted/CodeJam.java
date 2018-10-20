import java.math.*;
import java.io.*;
import java.util.*;

public class CodeJam {
	
	public static void main(String[] args) throws IOException {
		Scanner in = null;
		Scanner stats = null;
		PrintWriter out = null;
		Random rand = new Random();

		try {
			System.out.println(args[0]);
			in = new Scanner(new BufferedReader(new FileReader(args[0])));
			stats = new Scanner(new BufferedReader(new FileReader(args[1])));
			out = new PrintWriter(args[0] + ".out");
			
			int e= 1000;
			
			int[][] p = new int[e][e];

			for(int r=0; r<e; r++) {
				for(int c=0; c<e; c++) {
					p[r][c] = stats.nextInt()-10000;
				}
			}


			/*
			for(int r=0; r<e; r++) {
				for(int c=0; c<e; c++) {
					p[r][c] = 0;
				}
			}

			for(int i=0; i<10000000; i++) {
				int[] a = new int[e];
				for(int k=0; k<e; k++) {
					a[k] = k;
				}
				for(int k=0; k<e; k++) {
					int temp = a[k];
					int z = rand.nextInt(e);
					a[k] = a[z];
					a[z] = temp;
				}

				for(int k=0; k<e; k++) {
					p[a[k]][k]++;
				}
			}

			for(int r=0; r<e; r++) {
				for(int c=0; c<e; c++) {
					out.print(p[r][c] + " ");
				}
				out.println(" ");
			}
			*/


			//total test cases
			int testCases = in.nextInt();
			int total = 0;
			double low = 10000000;
			//for each test case
			for(int testCase=1; testCase<=testCases; testCase++) {
				//Read Inputs
				int x = in.nextInt();
				
				String result = "GOOD";
				double score = 0;

				for(int k=0; k<1000; k++){
					x = in.nextInt();
					score += p[x][k];
				}

				//Solve
				if(score > 50000) {
					result = "BAD";
				}

				if((result.equals("BAD") && (testCase-1)%2 == 0) || ((testCase-1)%2 == 1 &&  result.equals("GOOD"))) {
					System.out.println("PASS: " + score);
					total++;
					if(score > low) {
						low = score;
					}
				} else {
					System.out.println("FAIL: " + score);
					
				}


				//Output Result
				out.println("Case #"+testCase+": " + result);
			}

			System.out.println(total + " " + low);

		} finally {
			if(in != null) {
				in.close();
			}

			if(out != null) {
				out.close();
			}
		}
	}
}
