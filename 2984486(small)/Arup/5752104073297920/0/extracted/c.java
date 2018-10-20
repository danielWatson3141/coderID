import java.util.*;

public class c {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			int n = stdin.nextInt();
			int[] arr = new int[n];
			for (int i=0; i<n; i++)
				arr[i] = stdin.nextInt();

			boolean isBad = getIsBad(arr);

			if (isBad)
				System.out.println("Case #"+loop+": BAD");
			else
				System.out.println("Case #"+loop+": GOOD");


		}
	}

	public static boolean getIsBad(int[] arr) {
		int n = arr.length;
		int[] inv = new int[n];
		for (int i=0; i<n; i++)
			inv[arr[i]] = i;

		int cnt = 0;
		int total = 0;
		for (int i=1; i<arr.length/2; i++) {
			if (inv[i] < i) {
				cnt++;
				total = total + i - inv[i];
			}
		}

		for (int i=arr.length/2+1; i<arr.length; i++) {

			if (inv[i] < i && i-inv[i] < arr.length/2) {
				total = total + i - inv[i];
				cnt++;
			}
		}

		double avg = ((double)total)/cnt;
		//System.out.printf("%d %.6f ",cnt, avg);

		return cnt > n*.39;
	}
}