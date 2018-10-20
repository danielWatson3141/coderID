import java.util.*;

public class C {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		int X = 40000;
		int L = 2;
		HashMap<List<Integer>, Integer> map = new HashMap<List<Integer>, Integer>();
		for (int i=0; i<X; i++) {
			int[] a = new int[1000];
			for (int k=0; k<1000; k++) {
				a[k] = k;
			}
			Random r = new Random();
			for (int k=0; k<1000; k++) {
				int p = r.nextInt(1000);
				int swap = a[p];
				a[p] = a[k];
				a[k] = swap;
			}
			ArrayList<Integer> check = new ArrayList<Integer>(1000);
			for (int j=0; j<1000; j++) {
				check.add(a[j]);
			}
			List<Integer> into = check.subList(0, L);
			if (map.containsKey(into)) {
				int out = map.get(into);
				map.put(into, out+1);
			}
			else {
				map.put(into, 1);
			}
		}
		int p = 1;
		for (int b=0; b<cases; b++) {
			int n = Integer.parseInt(in.nextLine());
			ArrayList<Integer> arr = new ArrayList<Integer>(n);
			for (int i=0; i<n; i++) {
				arr.add(in.nextInt());
			}
			if (b!=cases-1) {
				in.nextLine();
			}
			List<Integer> into = arr.subList(0, L);
			if (map.containsKey(into)) {
				int out = map.get(into);
				if (out >= p) {
					System.out.println("Case #" + (b+1) + ": BAD");
				}
				else {
					System.out.println("Case #" + (b+1) + ": GOOD");
				}
			}
			else {
				System.out.println("Case #" + (b+1) + ": GOOD");
			}
		}
	}

}
