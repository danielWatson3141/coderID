package com.clayosophy.codejam2014.r1a;

import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

import org.apache.commons.math3.util.Combinations;

import com.clayosophy.codejam2014.Main.ProblemData;
import com.clayosophy.codejam2014.Main.ProblemData.ProblemCase;
import com.clayosophy.codejam2014.Main.ProblemSolver;

public class ProblemA implements ProblemSolver {
	
	private static final String IMPOSSIBRU = "NOT POSSIBLE";

	@Override
	public ProblemData getCasesFromInput(List<String> input) {
		ProblemData data = new ProblemData();
		data.setCaseCount(Integer.parseInt(input.get(0)));
		for (int i = 1; i< input.size(); i += 3) {
			String[] nl = input.get(i).split(" ");
//			int n = Integer.parseInt(nl[0]);
			int l = Integer.parseInt(nl[1]);
			
			Case c = new Case();
			c.length = l;
			String[] outlets = input.get(i+1).split(" ");
			String[] devices = input.get(i+2).split(" " );
			Arrays.sort(outlets);
			Arrays.sort(devices);
			
			c.outlets = outlets;
			c.devices = devices;
			
			data.addCase(c);
		}
		return data;
	}

	@Override
	public String processCase(ProblemCase problemCase) {
		Case c = (Case)problemCase;
		
		System.out.println(Arrays.toString(c.devices) + "\n" + Arrays.toString(c.outlets));
		if (Arrays.equals(c.devices, c.outlets)) {
			return "0";
		}
		for (int count = 1; count <= c.length; count++) {
			Combinations combination = new Combinations(c.length, count);
			Iterator<int[]> iter = combination.iterator();
			String[] devTest = null;
			while (iter.hasNext()) {
				devTest = getFlipped(c.outlets, iter.next());
				Arrays.sort(devTest);
				if (Arrays.equals(devTest, c.devices)) {
					return String.valueOf(count);
				}
			}
		}
		return IMPOSSIBRU;
	}
	
	
	
	
	
	
	private static String[] getFlipped(String[] outlets, int[] indexes) {
		String[] in = outlets.clone();
		for (int idx : indexes) {
			for (int i = 0; i< in.length; i++ ) {
				char[] chars = in[i].toCharArray();
				chars[idx] = chars[idx] == '1'? '0':'1';
				in[i] = new String(chars);
			}
		}
		return in;
	}






	private static class Case implements ProblemCase {
		int length;
		String[] outlets;
		String[] devices;
		
		public void addOutlet(String[] outlets) {
			this.outlets = outlets;
		}
		
		public void addDevice(String[] devices) {
			this.devices= devices;
		}
		
		public boolean isValid() {
			return (outlets.length == length && devices.length == length);
		}
		
	}

}
