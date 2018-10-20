import java.util.*;

public class B {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	//int nCase = Integer.parseInt(scanner.nextLine());
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int N = scanner.nextInt();
		boolean[][] m = new boolean[N][N];
		
		
		
		for (int i = 0; i < N-1; i++) {
			int X = scanner.nextInt();
			int Y = scanner.nextInt();
			m[X-1][Y-1] = true;
			m[Y-1][X-1] = true;
		}
		
		boolean[][] a = new boolean[N][N];
		int best = N+1;
		int S = 1 << N;
		for (int k = 0; k < S; k++) {
			for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				a[i][j] = m[i][j];
			
			boolean[] remain = new boolean[N];
			Arrays.fill(remain, true);
			for (int j = 0; j < N; j++)
				if (((k >> (N-j-1)) & 1) > 0) {
					remain[j] = false;
					for (int i = 0; i < N; i++) {
						a[i][j] = false;
						a[j][i] = false;
					}
				}
				
			for (int i = 0; i < N; i++) {
				if (remain[i] && check(a, remain)) {
					best = Math.min(best, Integer.bitCount(k));
					break;
				}
			}
		}
		
		System.out.println("Case #" + nc + ": " + best);
	}
}

public static boolean check(boolean[][] a, boolean[] remain) {
int N = a.length;

// check connect
for (int i = 0; i < N; i++)
	if (remain[i]) {
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.add(i);
		boolean[] connect = new boolean[N];
		connect[i] = true;
		while (list.size() > 0) {
			int k = list.remove();
			for (int j = 0; j < N; j++) {
				if (a[k][j] && !connect[j]) {
					connect[j] = true;
					list.add(j);
				}
			}
		}
		for (int j = 0; j < N; j++)
			if (remain[j] && !connect[j])
				return false;
	}

for (int root = 0; root < N; root++) {
	if (remain[root]) {
		boolean[] pass = new boolean[N];
		pass[root] = true;
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.add(root);
		boolean ok = true;
		while (list.size() > 0 && ok) {
			int k = list.remove();
			int nChild = 0;
			for (int j = 0; j < N; j++) {
				if (a[k][j] && !pass[j]) {
					pass[j] = true;
					list.add(j);
					nChild++;
				}
			}
			if (nChild != 0 && nChild != 2)
				ok = false;
		}
		if (ok) return true;
	}
}

return false;
}
}