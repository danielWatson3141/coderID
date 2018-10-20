import java.util.BitSet;
import java.util.HashSet;
import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numCases = scan.nextInt();
		for (int caseNum = 1; caseNum <= numCases; caseNum++) {
			System.out.printf("Case #%d: ", caseNum);
			System.out.println(solve(scan));
		}
	}

	private static String solve(Scanner scan) {
		int n = scan.nextInt();
		int l = scan.nextInt();
		BitSet[] outlets = new BitSet[n];
		BitSet[] devices = new BitSet[n];
		setup(scan, n, l, outlets);
		setup(scan, n, l, devices);
		int bestCard = -1;
		for (int i = 0; i < n; i++) {
			HashSet<BitSet> bits = new HashSet<BitSet>();
			BitSet difference = (BitSet) outlets[i].clone();
			difference.xor(devices[0]);
			int thisCard = difference.cardinality();
			if (bestCard >= 0 && thisCard >= bestCard)
				continue;
			for (int j = 0; j < n; j++) {
				BitSet toAdd = (BitSet) devices[j].clone();
				toAdd.xor(difference);
				bits.add(toAdd);
			}
			for (int j = 0; j < n; j++) {
				if (!bits.remove(outlets[j])) {
					thisCard = -1;
					break;
				}
			}
			if (thisCard >= 0)
				bestCard = thisCard;
		}
		if(bestCard == -1)
			return "NOT POSSIBLE";
		else
			return Integer.toString(bestCard);
	}

	private static void setup(Scanner scan, int n, int l, BitSet[] outlets) {
		for (int i = 0; i < n; i++) {
			String dev = scan.next();
			assert (dev.length() == l);
			outlets[i] = new BitSet();
			int j = 0;
			for (char c : dev.toCharArray()) {
				if (c == '1')
					outlets[i].set(j);
				else
					assert (c == '0');
				j++;
			}
		}
	}
}
