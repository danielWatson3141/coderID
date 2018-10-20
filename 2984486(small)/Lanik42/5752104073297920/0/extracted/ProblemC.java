package com.clayosophy.codejam2014.r1a;

import java.util.Arrays;
import java.util.List;

import com.clayosophy.codejam2014.Main.ProblemData;
import com.clayosophy.codejam2014.Main.ProblemData.ProblemCase;
import com.clayosophy.codejam2014.Main.ProblemSolver;

public class ProblemC implements ProblemSolver {

	@Override
	public ProblemData getCasesFromInput(List<String> input) {
		ProblemData data = new ProblemData();
		for (int i = 2; i< input.size(); i +=2) {
			String[] items = input.get(i).split(" ");
			Case c = new Case();
			int[] perms = new int[items.length];
			for (int j = 0; j < items.length; j++) {
				perms[j] = Integer.parseInt(items[j]);
			}
			c.permutation = perms;
			data.addCase(c);
		}
		return data;
	}

	@Override
	public String processCase(ProblemCase problemCase) {
		Case c = (Case)problemCase;
		System.out.println(Arrays.toString(c.permutation));
		int med = c.permutation.length/2;
		int underCount = 0;
		for (int i = 0;i<med;i++) {
			if (c.permutation[i] < med) {
				underCount++;
			}
		}
		if (underCount < c.permutation.length* .25 || underCount > c.permutation.length * .34)
			return "BAD";
		
		return "GOOD";
	}
	
	
	
	
	private static class Case implements ProblemCase {
		int[] permutation;
	}

}
