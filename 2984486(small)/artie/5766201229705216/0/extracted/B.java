import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;


public class B {

	public static void main(String[] args) throws Exception {
		new B().run();
	}
	
	int n, col[], e[], next[], f[], ec, a[], b[];

	private void run() throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("src\\input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int tc = sc.nextInt();
		col = new int[1000];
		e = new int[2000];
		next = new int[2000];
		f = new int[1000];
		a = new int[1000];
		b = new int[1000];
		for (int t = 1; t <= tc; t++) {
			n = sc.nextInt();
			int best = Integer.MAX_VALUE;
			ec = 0;
			Arrays.fill(f, -1);
			for (int i = 0; i < n - 1; i++) {
				int x = sc.nextInt() - 1;
				int y = sc.nextInt() - 1;
				add(x, y);
				add(y, x);
			}
			for (int i = 0; i < n; i++) {
				Arrays.fill(col, 0);
				if (i == 1)
					i += 0;
				go(i);
				if (b[i] == 4)
					best += 0;
				best = Math.min(best, b[i]);
			}
			pw.printf("Case #%d: %d\n", t, best);
		}
		pw.close();
	}

	private void go(int i) {
		// TODO Auto-generated method stub
		col[i] = 1;
		int j = f[i];
		int cnt = 0;
		int delAll = 0;
		int[][] cd = new int[1000][3];
		while (j != -1) {
			if (col[e[j]] == 0) {
				go(e[j]);
				delAll += a[e[j]];
				cd[cnt][0] = a[e[j]];
				cd[cnt][1] = b[e[j]];
				cd[cnt][2] = b[e[j]] - a[e[j]];
				cnt++;
			}
			j = next[j];
		}
		if (cnt == 0) {
			a[i] = 1;
			b[i] = 0;
			return;
		}
		Arrays.sort(cd, new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				// TODO Auto-generated method stub				
				return o1[2] - o2[2];
			}
		});
		a[i] = delAll + 1;
		//leave 0 or 2
		int cost = 0;
		for (j = 2; j < cnt; j++)
			cost += cd[j][0];
		if (cnt >= 2) {
			cost += cd[0][1] + cd[1][1];
		} else {
			cost += cd[0][0];
		}
		b[i] = cost;
	}

	private void add(int x, int y) {
		// TODO Auto-generated method stub
		e[ec] = y;
		next[ec] = f[x];
		f[x] = ec++;
	}

}
