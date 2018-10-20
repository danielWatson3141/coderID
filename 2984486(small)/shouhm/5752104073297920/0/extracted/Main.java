import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
	static public int n;
	static public int m;
	static public int f[];
	static public int a[];
	
	static public void init(Scanner scan) {
		n = scan.nextInt();
		a = new int[n+10];
		f = new int[n+10];
		for (int i = 0; i < n; i ++) {
			a[i] = scan.nextInt();
		}
	}
	static public void work(PrintWriter pw) {
		
		for (int i = 0; i < n; i ++) {
			f[i] = 0;
		}
		m = 0;
		for (int i = 0; i < n; i ++) {
			if (f[a[i]] == 0) {
				m ++;
				int p = i;
				while (f[p] == 0) {
					f[p] = 1;
					p = a[p];
				}
			}
		}
		
		BigInteger s1 = BigInteger.ONE;
		BigInteger s2 = BigInteger.ONE;
		for (int i = 1; i <= n; i ++)
			s1 = s1.multiply(BigInteger.valueOf(i));
		for (int i = 1; i <= n - m; i ++)
			s2 = s2.multiply(BigInteger.valueOf(n));;
		if (s1.compareTo(s2) < 0) 
			pw.println("GOOD");
		else
			pw.println("BAD");
	}
	
	static public void main(String[] args) throws IOException {
		Scanner scan = new Scanner(new File("C-small.in"));
		PrintWriter pw = new PrintWriter(new File("C-small.out"));
		int T = scan.nextInt();
		for (int ti = 1; ti <= T; ti ++) {
			init(scan);
			pw.print("Case #" + ti + ": ");
			work(pw);
		}
		pw.close();
		scan.close();
	}
}
