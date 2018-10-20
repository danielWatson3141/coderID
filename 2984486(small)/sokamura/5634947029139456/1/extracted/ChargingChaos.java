import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ChargingChaos {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("A-large.in"));

		int caseNum = s.nextInt();
		for (int t = 1; t <= caseNum; ++t) {
			int N = s.nextInt();
			int L = s.nextInt();
			s.nextLine();
			String line = s.nextLine();
			String outlet[] = line.split(" ");
			line = s.nextLine();
			String device[] = line.split(" ");

			System.out.println("Case #" + t + ": " + ChargingChaos.solve(N, L, outlet, device));
		}
	}

	public static String solve(int N, int L, String[] outlet, String[] device) {
		List<Long> answer = new ArrayList<Long>();
		for (int i = 0; i < N; ++i) {
			answer.add(calcDiff(outlet[0], device[i]));
		}

		for (int j = 1; j < N; ++j) {
			List<Long> diff = new ArrayList<Long>();
			for (int i = 0; i < N; ++i) {
				diff.add(calcDiff(outlet[j], device[i]));
			}

			for (int i = answer.size() - 1; i >= 0; --i) {
				if (!diff.contains(answer.get(i))) {
					answer.remove(i);
				}
			}
		}

		if (answer.isEmpty()) {
			return "NOT POSSIBLE";
		}

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < answer.size(); ++i) {
			int bit = Long.bitCount(answer.get(i));
			if (min > bit) {
				min = bit;
			}
		}
		return String.valueOf(min);
	}

	public static long calcDiff(String outlet, String device) {
		long o = Long.parseLong(outlet, 2);
		long d = Long.parseLong(device, 2);
		return o ^ d;
	}
}
