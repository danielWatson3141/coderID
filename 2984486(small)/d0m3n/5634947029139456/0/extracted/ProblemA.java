package si.cj2014.Round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Arrays;


public class ProblemA {

	public static void main(String[] args) {
		try {
			String inputFileName = "input_small.txt";
			BufferedReader br = new BufferedReader(new InputStreamReader(ProblemA.class.getResourceAsStream(inputFileName)));
			System.out.println(ProblemA.class.getResource(inputFileName).getPath().replaceAll("input", "output"));
			BufferedWriter bw = new BufferedWriter(new FileWriter(ProblemA.class.getResource(inputFileName).getPath().replaceAll("input", "output").replaceAll("bin", "src")));
			int num = Integer.parseInt(br.readLine());
			int icase = 1;
			for (int i=0; i<num; i++) {
				String scase = br.readLine();
				String[] splt = scase.split(" ");
				int N = Integer.parseInt(splt[0]);
				int L = Integer.parseInt(splt[1]);
				
				scase = br.readLine();
				String[] init = scase.split(" ");
				scase = br.readLine();
				String[] req = scase.split(" ");
				
				int res = solve(N,L,init,req, 0);
				if (res<0) {
					bw.write("Case #" + icase + ": NOT POSSIBLE\r\n");
					System.out.println("Case #" + icase + ": NOT POSSIBLE");	
				}
				else {
					bw.write("Case #" + icase + ": " + res + "\r\n");
					System.out.println("Case #" + icase + ": " + res);
				}
				
				icase++;
			}
			br.close();
			bw.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("Done.");
	}
	
	private static int solve(int n, int l, String[] init, String[] req, int swtchd) {
		if (compare(init, req)) {
			return swtchd;
		}
		for (int i=1; i<=l; i++) {
			int[] combo = new int[i];
			int k = 0;
			for (int j=i-1; j>=0; j--) {
				combo[j] = k;
				k++;
			}
			if (checkCombo(combo, init, req)) {
				return combo.length;
			}
			//outArr(combo);
			int[] next = getNextCombination(combo, l-1);
			if (next!=null && checkCombo(next, init, req)) {
				return combo.length;
			}
				
			while (next!=null) {
				//outArr(next);
				next = getNextCombination(next, l-1);
				if (next!=null && checkCombo(next, init, req)) {
					return combo.length;
				}
			}
		}
		
		return -1;
	}
	
	private static boolean checkCombo(int[] combo, String[] init, String[] req) {
		for (int i=0; i<combo.length; i++) {
			init = switchi(init, combo[i]);
		}
		return compare(init, req);
	}

	private static int[] getNextCombination(int[] comb, int m) {
		int[] res = Arrays.copyOf(comb, comb.length);
		boolean combo = false;
		for (int i=0; i<comb.length; i++) {
			if (comb[i]<(m-i)) {
				res[i]++;
				// fix trailing combo
				for (int j=i-1; j>=0; j--) {
					res[j] = res[j+1] + 1;
				}
				combo = true;
				break;
			}
		}
		if (combo) {
			return res;
		}
		return null;
	}
	
	private static String[] switchi(String[] sol, int idx) {
		String[] ret = new String[sol.length];
		for (int i=0; i<sol.length; i++) {
			String s = sol[i];
			String sn = s;
			if (s.charAt(idx)=='0') {
				sn = s.substring(0, idx) + "1" + s.substring(idx+1);
			}
			else {
				sn = s.substring(0, idx) + "0" + s.substring(idx+1);
			}
			ret[i] = sn;
		}
		return ret;
	}
	
	private static boolean compare(String[] sol, String[] req) {
		for (int i=0; i<sol.length; i++) {
			boolean iExists = false;
			for (int j=0; j<req.length; j++) {
				if (sol[i].equals(req[j])) {
					iExists = true;
				}
			}
			if (!iExists) {
				return false;
			}
		}
		return true;
	}
	
	private static int comb(int n, int r) {
		return (factorial(n)/(factorial(r)*factorial(n-r)));
	}
	
	private static int factorial(int n) {
        int fact = 1; // this  will be the result
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
	
	private static void outArr(int[] arr) {
		for (int i=arr.length-1; i>=0; i--) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
}
