/* Filename: R1A2014A.java
 * Author: Mushiyo
 */

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class R1A2014A {

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("pA.out"));

		while (input.hasNext()) {
			int T = input.nextInt();

			for (int t = 1; t <= T; ++t) {
				int N = input.nextInt();
				int L = input.nextInt();
				StringBuilder[] charge = new StringBuilder[N];
				HashSet<String> phone = new HashSet<String>();

				for (int i = 0; i < charge.length; ++i) {
					charge[i] = new StringBuilder(input.next());
				}

				for (int i = 0; i < charge.length; ++i) {
					phone.add(input.next());
				}
				
				//out.println(phone.contains(new StringBuilder("00")));
				
//				Iterator<StringBuilder> it = phone.iterator();
//				System.out.println("Set: ");
//				while(it.hasNext()){
//					System.out.println(it.next());
//				}
//				
//
//				System.out.println("T " + t);

				int minStep = count(charge, phone, 0, 0);

				out.printf("Case #%d: ", t);

				if (minStep >= 0) {
					out.println(minStep);
				} else {
					out.println("NOT POSSIBLE");
				}
			}
		}

		out.close();
	}

	public static int count(StringBuilder[] charge,
			HashSet<String> phone, int pos, int count) {
//		System.out.println("------------");
//		System.out.println("pos: " + pos);

		boolean match = true;
		for (int i = 0; i < charge.length; ++i) {
			if (!phone.contains(charge[i].toString())) {
				//System.out.println(charge[i]);
				match = false;
			} else {
				// System.out.println("@");
			}
		}

		if (match == true) {
			return count;
		}

		if (pos >= charge[0].length()) {
			return -1;
		}

		for (int i = 0; i < charge.length; ++i) {
			if (charge[i].charAt(pos) == '0') {
				charge[i].replace(pos, pos + 1, "1");
			} else {
				charge[i].replace(pos, pos + 1, "0");
			}
		}

		int bitMod = count(charge, phone, pos + 1, count + 1);

		for (int i = 0; i < charge.length; ++i) {
			if (charge[i].charAt(pos) == '0') {
				charge[i].replace(pos, pos + 1, "1");
			} else {
				charge[i].replace(pos, pos + 1, "0");
			}
		}

		int bitNonMod = count(charge, phone, pos + 1, count);

		//System.out.println(bitMod + " " + bitNonMod);

		if (bitMod < 0 || bitNonMod < 0) {
			return Math.max(bitMod, bitNonMod);
		} else
			return Math.min(bitMod, bitNonMod);
	}
}
