package codejam2014.round1A;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class ProblemA {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "A-small-attempt1";
			File folder = new File(new File("files", "codejam2014"), "round1A");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				List<Integer> parameters = parseIntegers(reader.readLine());
				int n = parameters.get(0);
				int l = parameters.get(1);
				Set<Long> initialSetting = parseBinary(reader.readLine());
				Set<Long> requiredSetting = parseBinary(reader.readLine());
				System.out.println("Case #" + (i+1));
				writer.printf("Case #%d: %s\n", i+1,
						solveIt(n, l, initialSetting, requiredSetting));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static String solveIt(int n, int l, Set<Long> initialSetting, Set<Long> requiredSetting) {
		int leastMoves = Integer.MAX_VALUE;
		for (long i = 0; i < (1 << l); i++) {
			int moves = countBits(i);
			if (leastMoves < moves) {
				continue;
			}
			Set<Long> updatedSetting = new HashSet<>();
			for (long switchValue : initialSetting) {
				updatedSetting.add(switchValue ^ i);
			}
			if (updatedSetting.equals(requiredSetting)) {
				leastMoves = moves;
			}
		}
		return leastMoves == Integer.MAX_VALUE ? "NOT POSSIBLE" : String.valueOf(leastMoves);
	}

	private static int countBits(long i) {
		int n = 0;
		while (i > 0) {
			n += i & 1;
			i >>= 1;
		}
		return n;
	}

	private static List<Integer> parseIntegers(String line) {
		return Arrays.stream(line.split("\\s")).map(Integer::parseInt).collect(Collectors.toList());
	}

	private static Set<Long> parseBinary(String line) {
		return Arrays.stream(line.split("\\s")).map(s -> Long.parseLong(s, 2)).collect(Collectors.toSet());
	}

	private static void close(Closeable file) {
		if (file != null) {
			try {
				file.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
