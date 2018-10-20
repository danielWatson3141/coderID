package chargingChaos;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class ChargingChaos {
	
	interface ClassName {
		public String getClassName();
	}

	public static void main(String[] args) {

		ClassName name = new ClassName() {
			public String getClassName() {
				return this.getClass().getEnclosingClass().getSimpleName();
			}
		};
		String[] input, out;
		String folder = name.getClassName().replaceFirst("\\.\\w*", "");
		String file = "E:\\Ignacio\\Trabajo\\Codejam2014\\src\\" + folder
				+ "\\A-small-attempt0.in";
		input = readTxt(file);
		out = execute(input);
		writeTxt(file, out);
	}

	private static void writeTxt(String file, String[] out) {

		try {
			PrintWriter pw = new PrintWriter(new FileWriter(file + ".txt"));
			for (int i = 0; i < out.length; i++) {
				pw.println(out[i]);
			}
			pw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static String[] readTxt(String file) {

		String line;
		String[] r = null;
		ArrayList<String> list = new ArrayList<String>();
		try {
			BufferedReader bf = new BufferedReader(new FileReader(file));
			while ((line = bf.readLine()) != null) {
				list.add(line);
			}
			bf.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

		r = list.toArray(new String[0]);
		return r;
	}

	public static String[] execute(String[] input) {

		String[] out = null;
		String[] splitted;				

		int test = 1;
		int ntests;

		ntests = Integer.parseInt(input[0]);
		out = new String[ntests];

		for (int i = 1; test < 1 + ntests;) {
			splitted = input[i++].split("\\s");
			int n = Integer.parseInt(splitted[0]);
			int l = Integer.parseInt(splitted[1]);			
			long[] outlet = new long[n];
			splitted = input[i++].split("\\s");
			for (int j = 0; j < n; j++) {				
				outlet[j] = Long.parseLong(splitted[j], 2);
			}
			long[] shota = new long[n];
			splitted = input[i++].split("\\s");
			for (int j = 0; j < n; j++) {				
				shota[j] = Long.parseLong(splitted[j], 2);
			}
			String result = minChanges(l, outlet, shota);
			out[test - 1] = "Case #" + test + ": " + result;
			System.out.println(out[test - 1]);

			test++;
		}
		return out;
	}
	
	private static String minChanges(int l, long[] outlet, long[] shota) {
		final String bad = "NOT POSSIBLE";
		int n = shota.length;
		int switches = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			long xor = outlet[i]^shota[0];
			Set<Long> set = createSet(shota);
			boolean good = true;
			for (int j = 0; j < n; j++) {
				if(i!=j) {
					if(!set.remove(outlet[j]^xor)) {
						good = false;
						break;
					}
				}
			}
			if(good) {
				int count = countOnes(xor);
				if(count<switches) {
					switches = count;
				}
			}
		}		
		if(switches>64)
			return bad;
		return ""+switches;		
	}
	
	private static int countOnes(long n) {
		int count = 0;
		for (int i = 0; i < 64; i++) {
			if( (n&(1L<<i))>0)
				count++;
		}
		return count;
	}

	private static Set<Long> createSet(long[] shota) {
		Set<Long> set = new HashSet<>();
		for (int i = 0; i < shota.length; i++) {
			set.add(shota[i]);
		}
		return set;
	}
}
