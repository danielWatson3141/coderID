import java.awt.*;
import java.awt.datatransfer.DataFlavor;
import java.io.*;
import java.util.Random;
import java.util.Scanner;

public class GCJ14_1A_C_ProperShuffle {

	private static final String PROBLEM_NAME = "C";

	private static final int[][] P = new int[1000][1000];
	private static final Random RANDOM = new Random();

	private final int[] arr;

	static {
		for (int iter = 0 ; iter < 500000 ; iter++) {
			int[] aa = new int[1000];
			for (int i = 0 ; i < 1000 ; i++) {
				aa[i] = i;
			}
			for (int i = 0 ; i < 1000 ; i++) {
				int r = RANDOM.nextInt(1000);
				int t = aa[i];
				aa[i] = aa[r];
				aa[r] = t;
			}
			for (int i = 0 ; i < 1000 ; i++) {
				P[aa[i]][i]++;
			}
		}
	}

	public GCJ14_1A_C_ProperShuffle(Scanner in) {
		int n = in.nextInt();
		arr = new int[n];
		for (int i = 0 ; i < n ; i++) {
			arr[i] = in.nextInt();
		}
	}

	public String solve() {
		int sum = 0;
		for (int i = 0 ; i < 1000 ; i++) {
			sum += P[arr[i]][i];
		}
		if (sum < 503750) {
			return "GOOD";
		} else {
			return "BAD";
		}
	}

	public static void main(String[] args) throws Exception {
		//solveFromClipboard();
		solveFromFile("small", 0);
		//solveFromFile("large", 0);
	}

	public static void solveAll(Scanner in, BufferedWriter out) throws Exception {
		int t = in.nextInt();
		for (int i = 1 ; i <= t ; i++) {
			System.out.println("Case #" + i);
			out.write("Case #" + i + ": ");
			out.write(new GCJ14_1A_C_ProperShuffle(in).solve());
			out.newLine();
			out.flush();
		}
	}

	public static void solveFromFile(String inputSize, int attempt) throws Exception {
		String fullName = PROBLEM_NAME + "-" + inputSize;
		if (attempt != -1) {
			fullName += "-attempt" + attempt;
		}
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(fullName + "-Output.txt")));
		Scanner in = new Scanner(new File(fullName+ ".in"));

		solveAll(in, out);

		System.out.println("Finished solving " + fullName);
	}

	//TODO copy output as well and autocheck that it matches the programs output
	public static void solveFromClipboard() throws Exception {
		String input = (String) Toolkit.getDefaultToolkit().getSystemClipboard().getContents(null).getTransferData(DataFlavor.stringFlavor);
		Scanner in = new Scanner(input);
		BufferedWriter out = new BufferedWriter(new PrintWriter(System.out));

		solveAll(in, out);
	}

}
