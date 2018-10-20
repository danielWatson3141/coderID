import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class ChargingChaos {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = Integer.valueOf(in.nextLine());

		for (int cazz = 1; cazz <= T; cazz++) {

			int result = 0;

			String[] nl = in.nextLine().split(" ");
			int N = Integer.valueOf(nl[0]);
			int L = Integer.valueOf(nl[1]);

			String[] existing = in.nextLine().split(" ");
			String[] desired = in.nextLine().split(" ");

			List<String> ext = Arrays.asList(existing);
			List<String> des = Arrays.asList(desired);

			boolean cont = false;
			if (des.containsAll(ext)) {
				cont = true;
				result = 0;
			} else {
				result = L;
				long nbr = (long) Math.pow(2, L);
				for (long i = 0; i < nbr - 1; i++) {

					String cvrt = convert(i);
					for (long ll = cvrt.length(); ll < L; ll++) {
						cvrt = "0" + cvrt;
					}
					// System.out.println("binary   " + nbr);
					// System.out.println("i   " + i);

					List<String> newVct = new ArrayList<>();
					for (int j = 0; j < N; j++) {
						String nvl = ext.get(j);
						for (int k = 0; k < L; k++) {
							if (Integer.valueOf(cvrt.substring(k, k + 1)) == 1) {
								if (Integer.valueOf(nvl.substring(k, k + 1)) == 0) {
									nvl = nvl.substring(0, k) + '1' + nvl.substring(k + 1);
								} else {
									nvl = nvl.substring(0, k) + '0' + nvl.substring(k + 1);
								}

							}
						}

						newVct.add(nvl);
					}

					if (des.containsAll(newVct)) {
						cont = true;
						int cnt = 0;
						for (int p = 0; p < L; p++) {
							if (Integer.valueOf(cvrt.substring(p, p + 1)) == 1) {
								cnt++;
							}
						}
						if (cnt < result) {
							result = cnt;
						}
					}

				}
			}

			if (cont) {
				System.out.println("Case #" + cazz + ": " + result);
			} else {
				System.out.println("Case #" + cazz + ": NOT POSSIBLE");
			}
		}
	}

	public static String convert(long decimal) {
		String result = "";

		while (decimal > 0) {
			long residue = decimal % 2;
			decimal = decimal / 2;
			if (residue == 0) {
				result = "0" + result;
			} else {
				result = residue + result;
			}

		}

		return result;
	}
}
