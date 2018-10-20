package eu.grzegorzjankowski;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Locale;
import java.util.StringTokenizer;

public class ChargingChaos  {

	public static void main(String[] args) {
		BufferedReader br = null;
		File file;

		Locale.setDefault(Locale.US);

		try {

			file = new File("c:\\CodeJam\\ChargingChaos\\result.txt");
			if (file.exists())
				file.delete();
			file.createNewFile();

			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);

			br = new BufferedReader(new FileReader(
					"c:\\CodeJam\\ChargingChaos\\A-small-attempt0.in"));

			int t = Integer.parseInt(br.readLine());
			for (int i = 0; i < t; i++) {
				StringTokenizer a = new StringTokenizer(br.readLine());
				int n = Integer.parseInt(a.nextToken());
				int l = Integer.parseInt(a.nextToken());
				
				
				StringTokenizer data = new StringTokenizer(br.readLine());
				
				Long[] initial = new Long[n];
				for (int j = 0; j< n ; j++) {
					initial[j] = Long.parseLong(data.nextToken(), 2);
				}
			
				Long[] required = new Long[n];
				StringTokenizer switches = new StringTokenizer(br.readLine());
				
				for (int j = 0; j< n ; j++) {
					required[j] = Long.parseLong(switches.nextToken(), 2);
				}
				
				bw.write("Case #" + (i+1) + ": " + solveIt(initial,required,l));
				bw.newLine();
				System.out.println(i + 1 + " -> " + (i + 1.0) * 100 / t + "%");
			}
			bw.close();
			

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}

	}

	private static String solveIt(Long[] initial, Long[] required, int l) {
		
		
		int result = Integer.MAX_VALUE;
		
		for (long i = 0; i < Math.pow(2,l); i++) {
			//System.out.println(i);
			
			ArrayList<Long> newRequired = new ArrayList<Long>(Arrays.asList(required));
			for (long m : initial) {
				if (newRequired.contains(m^i)) {
					newRequired.remove(m^i);
				} else break;
			}
			
			if (newRequired.size() == 0) {
				int m = count(i);
				if (m < result) result = m;
			}
		}
		if (result < Integer.MAX_VALUE) return ""+result;
		return "NOT POSSIBLE";
	}

	private static int count(Long i) {
		int result = 0;
		System.out.println(Long.toBinaryString(i));
		char[] a = Long.toBinaryString(i).toCharArray();
		for (int j = 0; j < a.length; j++) {
			if (a[j] == '1') result++;
		}
		return result;
	}


	


	
}
