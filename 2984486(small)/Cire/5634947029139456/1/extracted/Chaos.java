import java.io.*;
import java.util.*;

public class Chaos {
	//private DataInputStream in;
	private PrintWriter out;
	private Scanner in;
	
	Chaos() throws IOException {
		out = new PrintWriter(new FileWriter("output.txt"), true);		
	
		in = new Scanner(new File("input.txt"));
	}
	
	int Magnitude(long x) {
		int a = 0;
		while (x != 0) {
			a += x & ((long) 1);
			x>>>=1;
		}
		return a;
	}
	boolean test(long[] elec, long[] requ, long sw) {
		long a[] = elec.clone();
		long b[] = requ.clone();
		for(int i = 0; i < b.length; i++) {
			b[i]^=sw;
		}
		Arrays.sort(a);
		Arrays.sort(b);
		for(int i = 0; i < a.length; i++) {
			if (a[i] != b[i])
				return false;
		}
		return true;
	}
	
	
	void run() {
		int N = in.nextInt();
		int L = in.nextInt();
		long[] elec = new long[N];
		long[] requ = new long[N];
		String temp;
		for(int j = 0; j < N; j++) {
			temp = in.next();
			for(int i = 0; i < L; i++) {
				
				elec[j]<<=1;
				if (temp.charAt(i) == '1')
					elec[j]++;
				
			}
		}
		for(int j = 0; j < N; j++) {
			temp = in.next();
			for(int i = 0; i < L; i++) {
				requ[j]<<=1;
				if (temp.charAt(i) == '1')
					requ[j]++;
			}
		}
		int Best = Integer.MAX_VALUE;
		for(int i = 0; i < N; i++) {
			long sw = requ[i] ^ elec[0];
			if (Magnitude(sw) < Best) {
				if (test(elec, requ, sw))
					Best = Magnitude(sw);
			}
		}
		if (Best > L)
			out.println("NOT POSSIBLE");
		else
			out.println(Best);
	}
	
	public static void main(String[] args) throws IOException {

		Chaos m = new Chaos();
		
		
		int T = m.in.nextInt();
		for(int i=1; i<=T; i++) {
			m.out.print("Case #" + i + ": ");
			m.run();
		}
		
		return;
	}
}
