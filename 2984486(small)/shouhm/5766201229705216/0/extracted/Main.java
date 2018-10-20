import java.util.*;
import java.io.*;

public class Main {
	static public final int maxn = 200;
	static public int gg[][] = new int[maxn][maxn];
	static public int deg[] = new int[maxn];
	static public int f[] = new int[maxn];
	static public int root;
	static public int n;
	
	static public void init(Scanner scan) {
		n = scan.nextInt();
		for (int i = 1; i <= n; i ++)
			deg[i] = 0;
		for (int i = 0; i < n-1; i ++) {
			int x = scan.nextInt();
			int y = scan.nextInt();
			deg[x] ++;
			gg[x][deg[x]] = y;
			deg[y] ++;
			gg[y][deg[y]] = x;
		}
	}
	
	static public void dp(int x, int fa) {
		int first = -1, second = -1;
		for (int yi = 1; yi <= deg[x]; yi ++) { 
			int y = gg[x][yi];
			if (y != fa) {
				dp(y, x);
				int backup_first = first;
				int backup_second = second;
				if (f[y] > first) {
					first = f[y];
					second = backup_first;
				} else
				if (f[y] > second) {
					second = f[y];
				}
			}
		}
		if (first != -1 && second != -1)
			f[x] = first + second + 1;
		else
			f[x] = 1;
	}
	
	static public void work(PrintWriter pw) {
		//enumerate root
		int best = 0;
		for (root = 1; root <= n; root ++) {
			for (int i = 1; i <= n; i ++)
				f[i] = 0;
			dp(root, -1);
			if (f[root] > best) best = f[root]; 
		}
		pw.println(n - best);
	}
	
	static public void main(String[] args) throws IOException {
		Scanner scan = new Scanner(new File("B-small.in"));
		PrintWriter pw = new PrintWriter(new File("B-small.out"));
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
