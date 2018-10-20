import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class B {
	ArrayList<ArrayList<Integer> > tr;
	int[] cnum;

	void cnums(int p, int n) {
		int cnt = 0;
		ArrayList<Integer> con = tr.get(n);
		for (int i=0; i<con.size(); i++) {
			if (con.get(i) == p) {
				continue;
			}
			cnums(n, con.get(i));
			cnt += cnum[con.get(i)] + 1;
		}
		cnum[n] = cnt;
	}

	int dels(int p, int n) {
		ArrayList<Integer> con = tr.get(n);
		int hos = p >= 0 ? 1 : 0;
		if (con.size() == 0 + hos) {
			//System.err.println("p:" + p + "n:" + n + "res:" + 0);
			return 0;
		}
		if (con.size() == 1 + hos) {
			//System.err.println("p:" + p + "n:" + n + "res:" + cnum[n]);
			return cnum[n];
		}
		int fstn = -1;
		int sndn = -1;
		int fsta = 0;
		int snda = 0;
		for (int i=0; i<con.size(); i++) {
			if (con.get(i) == p) {
				continue;
			}
			int del = dels(n, con.get(i));
			int alive = cnum[con.get(i)] - del + 1;
			if (alive > fsta) {
				snda = fsta;
				sndn = fstn;
				fsta = alive;
				fstn = con.get(i);
			} else if (alive > snda) {
				snda = alive;
				sndn = con.get(i);
			}
		}
		//System.err.println("p:" + p + "n:" + n + "res:" + (cnum[n] - fsta - snda));
		return cnum[n] - fsta - snda;
	}
	void run() {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t=1; t<=T; t++) {
			int N = in.nextInt();
			tr = new ArrayList<ArrayList<Integer>>();
			for (int i=0; i<N; i++) {
				tr.add(new ArrayList<Integer>());
			}
			for (int i=0; i<N-1; i++) {
				int src = in.nextInt()-1;
				int dst = in.nextInt()-1;
				tr.get(src).add(dst);
				tr.get(dst).add(src);
			}
			cnum = new int[N];
			int res = N;
			for (int r=0; r<N; r++) {
				Arrays.fill(cnum, 0);
				cnums(-1, r);
				res = Math.min(res, dels(-1, r));
			}
			System.out.println("Case #" + t + ": " + res);
		}
	}
	static public void main(String[] args) {
		new B().run();
	}
}
