import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;


public class Charging {
	static int n, l;
	static StringBuilder[] plugs;
	static StringBuilder[] devices;
	static int[] needs, haves;

	private static class c implements Comparator<StringBuilder>
	{
		public int compare(StringBuilder x, StringBuilder y)
		{
			for (int i = 0; i < x.length(); i++) {
				int k = Character.compare(x.charAt(i), y.charAt(i));
				if (k != 0) {
					return k;
				}
			}
			return 0;
		}
		
		public boolean equals(StringBuilder x, StringBuilder y)
		{
			return compare(x, y) == 0;
		}
	}
	private static c comp = new c();
	
	static int solve(int i)
	{
		if (i >= l) {
			return 0;
		}
		if (needs[i] != n - haves[i]) {
			// Simple case -- we either must flip or do not need to flip. We will
			// already have flipped this if we need to.
			
			// Check that our devices correctly match up on this bit.
			for (int j = 0; j < n; j++) {
				if (plugs[j].charAt(i) != devices[j].charAt(i)) {
					return -1;
				}
			}
			
			return solve(i + 1);
		}
		else {
			// Try without flipping, then flip.
			int t1 = solve(i + 1);
			for (int j = 0; j < n; j++) {
				plugs[j].setCharAt(i, (char) ('0' + ('1' - plugs[j].charAt(i))));
			}
			Arrays.sort(plugs, comp); // XXX
			int t2 = solve(i + 1);
			if (t2 != -1) {
				t2++;
			}
			for (int j = 0; j < n; j++) {
				plugs[j].setCharAt(i, (char) ('0' + ('1' - plugs[j].charAt(i))));
			}
			Arrays.sort(plugs, comp); // XXX
			
			if (t1 == -1) {
				return t2;
			}
			else if (t2 == -1) {
				return t1;
			}
			else {
				return Math.min(t1, t2);
			}
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int caseNum = 1; caseNum <= t; caseNum++) {
			n = sc.nextInt();
			l = sc.nextInt();
			plugs = new StringBuilder[n];
			devices = new StringBuilder[n];
			needs = new int[l];
			haves = new int[l];
			for (int i = 0; i < n; i++) {
				String plug = sc.next();
				plugs[i] = new StringBuilder(plug);
			}
			for (int i = 0; i < n; i++) {
				String device = sc.next();
				devices[i] = new StringBuilder(device);
			}
			Arrays.sort(devices, comp);
			boolean ok = true;
			int switches = 0;
			for (int i = 0; i < l; i++) {
				int need = 0;
				int have = 0;
				for (int j = 0; j < n; j++) {
					if (plugs[j].charAt(i) == '1') {
						have++;
					}
					if (devices[j].charAt(i) == '1') {
						need++;
					}
				}
				needs[i] = need;
				haves[i] = have;
				if (have == need || have == n - need) {
					if (need != n - need) {
						// Forced to either flip or leave alone.
						if (have != need) {
							// Flip.
							switches++;
							for (int j = 0; j < n; j++) {
								plugs[j].setCharAt(i, (char) ('0' + ('1' - plugs[j].charAt(i))));
							}
						}
					}
					continue;
				}
				else {
					ok = false;
					break;
				}
			}
			Arrays.sort(plugs, comp);
			
			if (!ok) {
				System.out.println("Case #" + caseNum + ": NOT POSSIBLE");
				
			}
			else {
				int canSolve = solve(0);
				System.out.println("Case #" + caseNum + ": " + (canSolve == -1 ? "NOT POSSIBLE" : switches + canSolve));
			}
		}
	}
}
