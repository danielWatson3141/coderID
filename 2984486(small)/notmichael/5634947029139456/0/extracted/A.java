import java.util.*;

public class A {

	private static String[][] swaps;
	private static int[][] counts;
	private static int n;
	private static int l;
	private static String ans;
	private static boolean possible;
	private static int countmax;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			n = in.nextInt();
			l = in.nextInt();
			in.nextLine();
			countmax = l + 1;
			String[] first = in.nextLine().split(" ");
			String[] last = in.nextLine().split(" ");
			swaps = new String[n][n];
			counts = new int[n][n];
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					String swap = "";
					int count = 0;
					for (int k=0; k<l; k++) {
						if(first[i].charAt(k)==last[j].charAt(k)) {
							swap = swap + "0";
						}
						else {
							swap = swap + "1";
							count++;
						}
					}
					swaps[i][j] = swap;
					counts[i][j] = count;
				}
			}
			possible = false;
			recursion();
			if (!possible) {
				System.out.println("Case #" + (a+1) + ": NOT POSSIBLE");
			}
			else {
				int count = 0;
				for (int i=0; i<l; i++) {
					if(ans.charAt(i)=='1') {
						count++;
					}
				}
				System.out.println("Case #" + (a+1) + ": " + count);
			}
		}
	}
	
	private static void recursion() {
		for (int i=0; i<n; i++) {
			if (countmax > counts[0][i]) {
				HashSet<Integer> used = new HashSet<Integer>();
				used.add(i);
				String out = swaps[0][i];
				recursion(1, out, used, i);
			}
		}
	}
	
	private static void recursion(int place, String check, HashSet<Integer> used, int firstplace) {
		if (place==n) {
			ans = check;
			possible = true;
			int counter = counts[0][firstplace];
			if (counter < countmax) {
				countmax = counts[0][firstplace];
			}
		}
		else {
			for (int i=0; i<n; i++) {
				if (countmax < counts[0][firstplace]) {
					break;
				}
				else if (used.contains(i)) {
					continue;
				}
				else {
					String out = swaps[place][i];
					if (out.equals(check)) {
						HashSet<Integer> used2 = new HashSet<Integer>(used);
						used2.add(i);
						recursion(place+1, check, used2, firstplace);
					}
				}
			}
		}
	}

}
