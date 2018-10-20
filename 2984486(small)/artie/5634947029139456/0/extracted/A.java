import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws Exception {
		new A().run();
	}
	
	int n, l, mc, best, bestDumb;
	long outlet[], device[], mask[], noutlet[];
	boolean was, wasDumb;
	HashSet<Integer> can, ncan;

	private void run() throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("src\\input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int tc = sc.nextInt();
		outlet = new long[200];
		device = new long[200];
		noutlet = new long[200];
		mask = new long[1 << 20];
		can = new HashSet<Integer>();
		ncan = new HashSet<Integer>();
		for (int t = 1; t <= tc; t++) {
			n = sc.nextInt();
			l = sc.nextInt();
			for (int i = 0; i < n; i++) {
				outlet[i] = Long.parseLong(sc.next(), 2);
			}
			for (int i = 0; i < n; i++) {
				device[i] = Long.parseLong(sc.next(), 2);
			}
			mc = 0;
			for (int msk = 0; msk < 1 << (l / 2); msk++) {
				mask[mc++] = msk << (l - (l / 2)); 
			}
			was = false;
			wasDumb = false;
			best = Integer.MAX_VALUE;
			bestDumb = Integer.MAX_VALUE;
			//dumb(0, 0);
			go(0, 0);
/*			if (was != wasDumb || best != bestDumb) {
				System.err.println("ERROR " + t + " " + bestDumb);
			}
*/			if (was)
				pw.printf("Case #%d: %d\n", t, best);
			else
				pw.printf("Case #%d: NOT POSSIBLE\n", t);
		}
		pw.close();
	}

	private void dumb(int i, int msk) {
		// TODO Auto-generated method stub
		if (i == l) {
			checkDumb(msk);
			return;
		}
		dumb(i + 1, msk << 1);
		dumb(i + 1, (msk << 1) + 1);
	}

	private void checkDumb(int msk) {
		// TODO Auto-generated method stub
		for (int i = 0; i < n; i++)
			noutlet[i] = outlet[i] ^ msk;
		Arrays.sort(noutlet, 0, n);
		boolean can = true;
		for (int i = 0; i < n; i++)
			if (Arrays.binarySearch(noutlet, 0, n, device[i]) < 0) {
				can = false;
			}
		if (can) {
			wasDumb = true;
			int cur = Integer.bitCount(msk);
			if (cur == 5)
				cur += 0;
			bestDumb = Math.min(bestDumb, cur);
		}
	}

	private void go(int i, int msk) {
		// TODO Auto-generated method stub
		if (i == l - (l / 2)) {
			check(msk);
			return;
		}
		go(i + 1, msk << 1);
		go(i + 1, (msk << 1) + 1);
	}

	private void check(int msk) {
		// TODO Auto-generated method stub
		can.clear();
		for (int i = 0; i < mc; i++) {
			long first;
			for (int j = 0; j < n; j++) {
				first = (mask[i] + msk) ^ outlet[j];
				if (first == device[0]) {
					can.add(i);
				}
			}
		}		
		for (int i = 1; i < n; i++) {
			ncan.clear();
			for (int x : can) {				
				long first;
				for (int j = 0; j < n; j++) {
					first = (mask[x] + msk) ^ outlet[j];
					if (first == device[i])
						ncan.add(x);
				}
			}
			can.clear();
			can.addAll(ncan);
		}
		for (int x : can) {
			was = true;
			best = Math.min(Integer.bitCount(msk) + Long.bitCount(mask[x]), best);
		}
	}

}
