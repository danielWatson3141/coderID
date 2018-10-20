import java.util.*;

public class A {
	public static void main(String[] args) {
		new A();
	}

	public A() {
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for (int n = 0; n < cases; n++) {
			int numFlows = input.nextInt();
			int numBits = input.nextInt();
			long[] out = new long[numFlows];
			for (int i = 0; i < numFlows; i++) {
				out[i] = Long.parseLong(input.next(), 2);
			}
			input.nextLine();
			long[] in = new long[numFlows];
			for (int i = 0; i < numFlows; i++) {
				in[i] = Long.parseLong(input.next(), 2);
			}
			input.nextLine();

			Set<Long> inSet = new HashSet<Long>();
			for (int i = 0; i < numFlows; i++) {
				inSet.add(in[i]);
			}
			boolean possible = false;
			int b = 0;
			while (b < (1 << numBits)) {
				Set<Long> outSet = new HashSet<Long>();
				for (int i = 0; i < numFlows; i++) {
					outSet.add(out[i] ^ b);
				}
				if (outSet.equals(inSet)) {
					possible = true;
					break;
				}
				b++;
			}

			if (possible) {
				System.out.println("Case #" + (n+1) + ": " + Long.bitCount(b));
			} else {
				System.out.println("Case #" + (n+1) + ": NOT POSSIBLE");
			}
		}
	}
}
