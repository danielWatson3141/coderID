package jam14.r1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class ChargingChaos {
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("A-small-attempt0.bin"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("A-small-attempt0.out"));
		int t = Integer.parseInt(reader.readLine());
		for (int i = 0; i < t; i++) {
			String[] inps = reader.readLine().split(" ");
			int n = Integer.parseInt(inps[0]);
			int l = Integer.parseInt(inps[1]);
			long[] varIns = new long[n];
			long[] reqOut = new long[n];
			long[] toComp = new long[n];
			inps = reader.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				varIns[j] = Long.parseLong(inps[j], 2);
			}
			inps = reader.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				reqOut[j] = Long.parseLong(inps[j], 2);
			}
			Arrays.sort(reqOut);
			//System.out.println(Arrays.toString(varIns));

			long perm = new Double(Math.pow(2, l)).longValue();
			Set<Long> possibleFlips = new HashSet<>();
			for (long j = 0; j < perm; j++) {
				for (int k = 0; k < n; k++) {
					toComp[k] = varIns[k] ^ j;
				}
				Arrays.sort(toComp);
				//System.out.println("C1"+Arrays.toString(toComp));
				//System.out.println("C2"+Arrays.toString(reqOut));
				if (Arrays.equals(reqOut, toComp)) {
					possibleFlips.add(j);
				}
			}

			StringBuilder builder=new StringBuilder("Case #").append(i+1).append(": ");
			if (possibleFlips.isEmpty()) {
				builder.append("NOT POSSIBLE");
			} else {
				int reqFlips = Integer.MAX_VALUE;
				for (Long flip : possibleFlips) {
					int bitCount = Long.bitCount(flip);
					if (bitCount < reqFlips) {
						reqFlips = bitCount;
					}
				}
				builder.append(reqFlips);
				//System.out.println(reqFlips);
			}
			builder.append('\n');
			writer.write(builder.toString());
		}
		reader.close();
		writer.close();
	}
}
