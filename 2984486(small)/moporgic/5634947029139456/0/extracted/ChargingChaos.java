import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class ChargingChaos {

	static {
		try {
			String input = "A-small-attempt2.in";
			String output = input.substring(0, input.lastIndexOf('.')) + ".out";
			System.setIn(new FileInputStream(input));
			System.setOut(new PrintStream(new FileOutputStream(output), true));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		HashSet<Long> data = new HashSet<>();
		HashSet<Long> tget = new HashSet<>();
		HashSet<Long> proc = new HashSet<>();

		for (int t = 1, T = input.nextInt(); t <= T; t++) {
			int n = input.nextInt(), l = input.nextInt();
			for (int i = 0; i < n; i++)
				data.add(Long.parseLong(input.next(), 2));
			for (int i = 0; i < n; i++)
				tget.add(Long.parseLong(input.next(), 2));

			int s = Integer.MAX_VALUE;
			for (int i = 0, L = (1 << (l)) - 1; i <= L; i++) {
				proc.addAll(tget);
				for (long v : data) {
					proc.remove((v & ~i) | (~(v & i) & i));
				}
				if (proc.size() == 0) {
					s = Math.min(s, Integer.bitCount(i));
					if (s == 0)
						break;
				}
			}
			if (s != Integer.MAX_VALUE) {
				System.out.printf("Case #%d: %d\n", t, s);
			} else {
				System.out.printf("Case #%d: NOT POSSIBLE\n", t);
			}
			data.clear();
			tget.clear();
			proc.clear();
		}
		input.close();
	}
}
