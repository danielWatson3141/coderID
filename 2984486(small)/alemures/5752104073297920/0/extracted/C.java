import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n;
		int[] ns;
 
		int t = sc.nextInt();
		for(int i = 1; i <= t; i++) {
			n = sc.nextInt();
			ns = new int[n];

			for(int j = 0; j < n; j++) {
				ns[j] = sc.nextInt();
			}

			System.out.printf("Case #%d: %s\n", i, solve(n, ns));
		}
	}

	public static String solve(int n, int[] ns) {
		int sum1 = 0, sum2 = 0;
		int mid = n/2;

		for(int i = 0; i < mid; i++)
			sum1 += ns[i];

		for(int i = mid; i < n; i++)
			sum2 += ns[i];

		if(sum1 > sum2)
			return "BAD";
		return "GOOD";
	}
}