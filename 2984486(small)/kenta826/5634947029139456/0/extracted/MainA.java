package gcj.r1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class MainA {

	static final int INF = 10000000;

	public static void main(String[] args) throws FileNotFoundException {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/gcj/r1a/in.txt"));

		int T = sc.nextInt();

		for (int t=1; t<T+1; t++) {
			int N = sc.nextInt();
			int L = sc.nextInt();

			List<String> C = new ArrayList<String>();
			List<String> D = new ArrayList<String>();

			for(int i=0; i<N; i++) {
				String c = sc.next();
				C.add(c);
			}
			for(int i=0; i<N; i++) {
				String d = sc.next();
				D.add(d);
			}

			output(t, solve(N, L, C, D));

		}
	}

	static int solve(int N, int L, List<String> C, List<String> D) {

		List<List<String>> nC = new ArrayList<List<String>>();
		List<List<String>> nD = new ArrayList<List<String>>();

		nC.add(C);
		nD.add(D);

		return dfs(0,nC,nD);
	}

	static int dfs(int ans, List<List<String>> C, List<List<String>> D) {
		int N = C.size();

		int[] num0c = new int[N];
		int[] num1c = new int[N];
		int[] num0d = new int[N];
		int[] num1d = new int[N];

		for (int i=0; i<N; i++) {
			List<String> cs = C.get(i);
			List<String> ds = D.get(i);


			for (int j=0; j<cs.size(); j++) {
				String c = cs.get(j);
				String d = ds.get(j);

				if (c.length() == 0 || d.length() == 0) {
					return ans;
				}

				if (c.charAt(0) == '0')
					num0c[i]++;
				if (c.charAt(0) == '1')
					num1c[i]++;
				if (d.charAt(0) == '0')
					num0d[i]++;
				if (d.charAt(0) == '1')
					num1d[i]++;
			}

		}

		boolean b1 = true;
		boolean b2 = true;
		boolean b3 = true;


		for (int i=0; i<N; i++) {
			if (num0c[i] == num0d[i] && num0c[i] == num1c[i]) {

			} else {
				b1 = false;
				if (num0c[i] == num0d[i]) {
					b3 = false;
				} else if (num0c[i] == num1d[i]) {
					b2 = false;
				} else {
					b2 = false;
					b3 = false;
				}
			}
		}


		if (b1) {
			// 全部同じ場合

			List<List<String>> nC1 = new ArrayList<List<String>>();
			List<List<String>> nD1 = new ArrayList<List<String>>();
			List<List<String>> nC2 = new ArrayList<List<String>>();
			List<List<String>> nD2 = new ArrayList<List<String>>();

			for (int i=0; i<N; i++) {
				List<String> cs = C.get(i);
				List<String> ds = D.get(i);

				List<String> nc0 = new ArrayList<String>();
				List<String> nc1 = new ArrayList<String>();
				List<String> nd0 = new ArrayList<String>();
				List<String> nd1 = new ArrayList<String>();

				for (int j=0; j<cs.size(); j++) {
					String c = cs.get(j);
					String d = ds.get(j);

					if (c.charAt(0) == '0')
						nc0.add(c.substring(1,c.length()));
					if (c.charAt(0) == '1')
						nc1.add(c.substring(1,c.length()));
					if (d.charAt(0) == '0')
						nd0.add(d.substring(1,d.length()));
					if (d.charAt(0) == '1')
						nd1.add(d.substring(1,d.length()));
				}

				nC1.add(nc0);
				nC1.add(nc1);
				nD1.add(nd0);
				nD1.add(nd1);

				nC2.add(nc0);
				nC2.add(nc1);
				nD2.add(nd1);
				nD2.add(nd0);
			}

			return Math.min(dfs(ans, nC1, nD1), dfs(ans+1, nC2, nD2));

		} else if (b2) {
			// スイッチしない
			List<List<String>> nC = new ArrayList<List<String>>();
			List<List<String>> nD = new ArrayList<List<String>>();

			for (int i=0; i<N; i++) {
				List<String> cs = C.get(i);
				List<String> ds = D.get(i);

				List<String> nc0 = new ArrayList<String>();
				List<String> nc1 = new ArrayList<String>();
				List<String> nd0 = new ArrayList<String>();
				List<String> nd1 = new ArrayList<String>();

				for (int j=0; j<cs.size(); j++) {
					String c = cs.get(j);
					String d = ds.get(j);

					if (c.charAt(0) == '0')
						nc0.add(c.substring(1,c.length()));
					if (c.charAt(0) == '1')
						nc1.add(c.substring(1,c.length()));
					if (d.charAt(0) == '0')
						nd0.add(d.substring(1,d.length()));
					if (d.charAt(0) == '1')
						nd1.add(d.substring(1,d.length()));
				}

				nC.add(nc0);
				nC.add(nc1);
				nD.add(nd0);
				nD.add(nd1);
			}

			return dfs(ans, nC, nD);

		} else if (b3) {
			//スイッチする
			List<List<String>> nC = new ArrayList<List<String>>();
			List<List<String>> nD = new ArrayList<List<String>>();

			for (int i=0; i<N; i++) {
				List<String> cs = C.get(i);
				List<String> ds = D.get(i);

				List<String> nc0 = new ArrayList<String>();
				List<String> nc1 = new ArrayList<String>();
				List<String> nd0 = new ArrayList<String>();
				List<String> nd1 = new ArrayList<String>();

				for (int j=0; j<cs.size(); j++) {
					String c = cs.get(j);
					String d = ds.get(j);

					if (c.charAt(0) == '0')
						nc0.add(c.substring(1,c.length()));
					if (c.charAt(0) == '1')
						nc1.add(c.substring(1,c.length()));
					if (d.charAt(0) == '0')
						nd0.add(d.substring(1,d.length()));
					if (d.charAt(0) == '1')
						nd1.add(d.substring(1,d.length()));
				}

				nC.add(nc0);
				nC.add(nc1);
				nD.add(nd1);
				nD.add(nd0);
			}

			return dfs(ans+1, nC, nD);

		} else {
			//もう無理
			return INF;
		}

	}


	static void output(int i, int a) {
		if (a != INF)
			System.out.println("Case #" + i + ": " + a);
		else
			System.out.println("Case #" + i + ": " + "NOT POSSIBLE");
	}
}