import java.math.BigInteger;
import java.util.Random;
import java.util.Scanner;

public class ProperShuffle {

	public static void main(String[] args) {
		ProperShuffle me = new ProperShuffle();
		// me.nickRun();
		me.runAll();
	}

	public void nickRun() {
		Scanner in = new Scanner(System.in);
		nTrial = in.nextInt();
		N = in.nextInt();

		counts = new int[N][N];
		fillProbs();
		System.err.println("Done filling probs");

		// Calculate 1 / N!
		goodVal = new BigFraction(1, 1);
		for (int i = 1; i <= N; i++) {
			goodVal.mult(new BigFraction(1, i));
		}
		System.out.println(goodVal.num + " " + goodVal.den);

		int good = 0;
		for (int iTrial = 0; iTrial < nTrial; iTrial++) {

			System.out.print("Case #" + (iTrial + 1) + ": ");

			// Run the bad shuffle
			int[] arr = new int[N];
			for (int j = 0; j < N; j++) {
				arr[j] = j;
			}
			for (int j = 0; j < N; j++) {
				int p = r.nextInt(N);
				int temp = arr[p];
				arr[p] = arr[j];
				arr[j] = temp;
			}

			boolean goodVal = testVals(arr);
			if (goodVal) {
				good++;
			}
			if (goodVal) {
				System.out.println("GOOD");
			} else {
				System.out.println("BAD");
			}

		}
		System.out.println("good = " + good);
	}

	public void runAll() {

		Scanner in = new Scanner(System.in);
		nTrial = in.nextInt();
		N = in.nextInt();

		counts = new int[N][N];
		fillProbs();
		System.err.println("Done filling probs");

		// Calculate 1 / N!
		goodVal = new BigFraction(1, 1);
		for (int i = 1; i <= N; i++) {
			goodVal.mult(new BigFraction(1, i));
		}

		int[] vals = new int[N];
		for (int iTrial = 0; iTrial < nTrial; iTrial++) {

			System.out.print("Case #" + (iTrial + 1) + ": ");

			if (iTrial > 0) {
				in.nextInt();
			}

			for (int i = 0; i < N; i++) {
				vals[i] = in.nextInt();
			}

			boolean goodVal = testVals(vals);
			if (goodVal) {
				System.out.println("GOOD");
			} else {
				System.out.println("BAD");
			}
		}
	}

	int N;
	int nTrial;
	int nGenTrial = 1000000;
	Random r = new Random();
	BigFraction goodVal;

	int[][] counts;

	public boolean testVals(int[] vals) {

		BigFraction thisVal = new BigFraction(1, 1);
		boolean[] used = new boolean[N];
		for (int i = 0; i < N; i++) {

			// Conditional probability
			int val = vals[i];
			long den = 0;
			for (int j = 0; j < N; j++) {
				if (!used[j]) {
					den += counts[i][j];
				}
			}
			long num = counts[i][val];
			thisVal.mult(new BigFraction(num, den));

			used[val] = true;
		}

//		System.err.println("Good val = " + goodVal.num + " / " + goodVal.den);
		// System.err.println("This val = " + thisVal.num + " / " +
		// thisVal.den);
		// System.err.println("This val = " + thisVal.num.floatValue() + " / " +
		// thisVal.den.floatValue());
//		System.err.println("Ratio = " + goodVal.num.floatValue() / goodVal.den.floatValue() + " --- "
//				+ thisVal.num.floatValue() / thisVal.den.floatValue());

		return goodVal.compareTo(thisVal) > 0;
	}

	public void fillProbs() {

		for (int i = 0; i < nGenTrial; i++) {

			if (i % 100000 == 0) {
				System.err.println("Generating trial " + i);
			}

			// Run the bad shuffle
			int[] arr = new int[N];
			for (int j = 0; j < N; j++) {
				arr[j] = j;
			}
			for (int j = 0; j < N - 1; j++) {
				int p = r.nextInt(N);
				int temp = arr[p];
				arr[p] = arr[j];
				arr[j] = temp;
			}
			for (int j = 0; j < N; j++) {
				counts[j][arr[j]]++;
			}
		}

	}

	public class BigFraction {

		public BigFraction(long numL, long denL) {
			num = BigInteger.valueOf(numL);
			den = BigInteger.valueOf(denL);
		}

		BigInteger num, den;

		public void mult(BigFraction o) {
			this.num = num.multiply(o.num);
			this.den = den.multiply(o.den);
		}

		public int compareTo(BigFraction o) {
			return num.multiply(o.den).compareTo(o.num.multiply(den));
		}

	}

}
