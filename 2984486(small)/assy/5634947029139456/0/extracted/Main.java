package codejam2014round1AA;

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
			sc = new Scanner(new File("/Users/ryo/Documents/procon/codejam2014r1a/A-small-attempt0.in"));
			pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("/Users/ryo/Documents/procon/codejam2014r1a/A-small-attempt0.out"))));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		int t = sc.nextInt();
		
		
		List<String> target = new ArrayList<String>();
		List<String> check = new ArrayList<String>();
		for (int x = 1; x <= t; x++) {
			int n = sc.nextInt(), l = sc.nextInt();
			char[][] outlet = new char[n][l];
			char[][] copy = new char[n][l];
			target.clear();
			for (int i = 0; i < n; i++) {
				String s = sc.next();
				for (int j = 0; j < l; j++) {
					outlet[i][j] = s.charAt(j);
				}
			}
			for (int i = 0; i < n; i++) {
				target.add(sc.next());
			}
			Collections.sort(target);
			int res = 10000;
			for (int i = 0; i < 1<<l; i++) {
				for (int p = 0; p < n; p++) {
					for (int q = 0; q < l; q++) {
						copy[p][q] = outlet[p][q];
					}
				}
				for (int j = 0; j < l; j++) {
					if ((i>>j & 1) == 1) {
						for (int k = 0; k < n; k++) {
							copy[k][j] = (copy[k][j] == '0') ? '1' : '0';
						}
					}
				}
				check.clear();
				for (int j = 0; j < n; j++) {
					StringBuilder sb = new StringBuilder();
					for (int k = 0; k < l; k++)
						sb.append(copy[j][k]);
					check.add(sb.toString());
				}
				Collections.sort(check);
				boolean flag = true;
				for (int j = 0; j < n; j++) {
					String s1 = target.get(j), s2 = check.get(j);
					if (!s1.equals(s2)) {
						flag = false;
						break;
					}
				}
				if (flag) {
					res = min(res, Integer.bitCount(i));
				}
			}
			if (res > 1000) {
				pw.printf("Case #%d: NOT POSSIBLE\n", x);
			} else {
				pw.printf("Case #%d: %d\n", x, res);
			}
		}
		sc.close();
		pw.close();
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}