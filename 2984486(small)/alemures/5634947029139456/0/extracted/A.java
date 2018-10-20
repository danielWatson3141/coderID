import java.util.Scanner;
import java.util.HashMap;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n, l;
		String[] electricFlow;
		HashMap<String, Integer> electricFlowRequired;

		int t = sc.nextInt();
		for(int i = 1; i <= t; i++) {
			n = sc.nextInt(); l = sc.nextInt();

			electricFlow = new String[n];
			electricFlowRequired = new HashMap<>(n);

			for(int j = 0; j < n; j++) {
				electricFlow[j] = sc.next();
			}
			for(int j = 0; j < n; j++) {
				electricFlowRequired.put(sc.next(), j);
			}

			System.out.printf("Case #%d: %s\n", i, solve(n, l, electricFlow, electricFlowRequired));
		}
	}

	public static String solve(int n, int l, String[] electricFlow, HashMap<String, Integer> electricFlowRequired) {
		String[] copy;
		HashMap<String, Integer> copy2;

		int max = (int)Math.pow(2, l);
		boolean lomo;

		int sol = 1000000000;
		boolean res = false;
		for(int i = 0; i < max; i++) {
			lomo = false;
			copy = new String[electricFlow.length];
			System.arraycopy( electricFlow, 0, copy, 0, electricFlow.length );

			copy2 = new HashMap<>(electricFlow.length);
			copy2.putAll(electricFlowRequired);

			flip(copy, i);

			
			for (int j = 0; j < copy.length; j++) {
				if(!copy2.containsKey(copy[j])) {
					lomo = true;
					break;
				} else {
					// Remove key
					copy2.remove(copy[j]);
				}
			}

			if(lomo) continue;

			/*for (int j = 0; j < copy.length; j++) {
				System.out.println(copy[j]);
			}
			System.out.println("--");
			for(String j: copy2.keySet()) {
				System.out.println(j);
			}*/

			if(Integer.bitCount(i) < sol) {
				sol = Integer.bitCount(i);
			}
			res = true;

		}

		if(res) {
			return String.valueOf(sol);
		}

		return "NOT POSSIBLE";
	}

	public static void flip(String[] electricFlow, int mask) {
		int sizeMask = String.valueOf(Integer.toBinaryString(mask)).length();
		int check = 0x1;

		for(int i = 0; i < sizeMask; i++) {

			for(int j = 0; j < electricFlow.length; j++) {
				char[] outlet = electricFlow[j].toCharArray();

				if((mask & check) > 0) {
					if(outlet[i] == '1') {
						outlet[i] = '0';
					} else {
						outlet[i] = '1';
					}
				}
				electricFlow[j] = String.valueOf(outlet);
			}
			check <<= 1;
		}
	}
}