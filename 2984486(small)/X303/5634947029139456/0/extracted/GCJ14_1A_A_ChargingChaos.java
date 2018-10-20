import java.awt.*;
import java.awt.datatransfer.DataFlavor;
import java.io.*;
import java.util.Scanner;

public class GCJ14_1A_A_ChargingChaos {

	private static final String PROBLEM_NAME = "A";

	private final boolean[][] outlets;
	private final boolean[][] devices;

	public GCJ14_1A_A_ChargingChaos(Scanner in) {
		int n = in.nextInt();
		int l = in.nextInt();
		outlets = new boolean[n][l];
		devices = new boolean[n][l];
		for (int i = 0 ; i < n ; i++) {
			String s = in.next();
			if (s.length() != l) {
				throw new RuntimeException();
			}
			int j = 0;
			for (char c : s.toCharArray()) {
				outlets[i][j++] = c == '1';
			}
		}
		for (int i = 0 ; i < n ; i++) {
			String s = in.next();
			if (s.length() != l) {
				throw new RuntimeException();
			}
			int j = 0;
			for (char c : s.toCharArray()) {
				devices[i][j++] = c == '1';
			}
		}
	}

	public String solve() {
		//brute-force
		int max = (int) Math.pow(2, outlets[0].length);
		int minFlips = Integer.MAX_VALUE;
	flips:
		for (int i = 0 ; i < max ; i++) {
			boolean[] flipped = new boolean[outlets[0].length];
			for (int j = 0 ; j < outlets[0].length ; j++) {
				flipped[j] = ((i >> j) & 1) == 1;
			}

			for (boolean[] device : devices) {
				boolean found = false;
				for (boolean[] outlet : outlets) {
					boolean ok = true;
					for (int j = 0 ; j < outlet.length ; j++) {
						if (device[j] != (outlet[j] ^ flipped[j])) {
							ok = false;
							break;
						}
					}
					if (ok) {
						found = true;
						break;
					}
				}
				if (!found) {
					continue flips;
				}
			}
			int flips = 0;
			for (boolean flip : flipped) {
				if (flip) {
					flips++;
				}
			}
			minFlips = Math.min(minFlips, flips);
		}

		if (minFlips < Integer.MAX_VALUE) {
			return Integer.toString(minFlips);
		} else {
			return "NOT POSSIBLE";
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
			out.write(new GCJ14_1A_A_ChargingChaos(in).solve());
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
