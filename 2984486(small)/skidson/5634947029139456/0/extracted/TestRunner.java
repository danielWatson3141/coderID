package com.skidson.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import com.skidson.codejam.problems.ChargingChaos;

public class TestRunner {
	
	public static final String OUT_FORMAT = "Case #%d: %s";
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("input.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
		int numTests = Integer.parseInt(in.readLine());
		
		Test test = new ChargingChaos(in);
		for (int i = 0; i < numTests; i++) {
			printResult(out, i+1, test.run());
		}
		
		in.close();
		out.flush();
		out.close();
	}
	
	protected static void printResult(BufferedWriter out, int testNum, String result) {
		try {
			out.write(String.format(OUT_FORMAT, testNum, result) + "\n");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
}
