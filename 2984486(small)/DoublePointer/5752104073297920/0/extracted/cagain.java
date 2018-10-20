import java.util.*;

public class cagain {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t=1; t<=T; t++) {
			int n = in.nextInt();
			int[] v = new int[n];
			int z = 0;
			for(int i=0; i<n; i++) v[i] = in.nextInt();
			boolean[] seen = new boolean[n];
			ArrayList<Integer> lens = new ArrayList<Integer>();
			for(int i=0; i<n; i++) {
				if(seen[i]) continue;
				int len = 0;
				int cur = i;
				while(!seen[cur]) {
					seen[cur] = true;
					len++;
					cur = v[cur];
				}
				lens.add(len);
				z = Math.max(z, len);
			}
			double expected = 0;
			for(int i=1; i<=n; i++)
				expected += 1./i;
			Collections.sort(lens);
			boolean bad = false;
			if(lens.size() < 6 || lens.size() > 9) bad = true;
			System.out.printf("Case #%d: ", t);
			if(bad) System.out.println("BAD");
			else System.out.println("GOOD");
		}
	}
}