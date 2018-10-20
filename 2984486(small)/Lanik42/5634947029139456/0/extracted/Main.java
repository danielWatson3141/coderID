package com.clayosophy.codejam2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import com.clayosophy.codejam2014.Main.ProblemData.ProblemCase;
import com.clayosophy.codejam2014.q.ProblemQC;
import com.clayosophy.codejam2014.r1a.ProblemA;

public class Main {

	private static final String IN_FILE_PATH = "R:\\A-small-attempt0.in";
//	private static final String IN_FILE_PATH = "R:\\sample.in";
	private static final String OUT_FILE_PATH = "R:\\out.txt";
	
	
	public static void main(String [] args) {
		
		ProblemSolver solver = new ProblemA();
		
		List<String> contents = getLineContents();
		ProblemData data = solver.getCasesFromInput(contents);
		List<String> results = new ArrayList<>();
		
		for (ProblemCase pc : data.getCases()) {
			String output = String.format("Case #%d: %s", (results.size() + 1), solver.processCase(pc));
			System.out.println(output);
			results.add(output);
		}
		
		
		
		writeResults(results);
		
		for (String error : ProblemQC.errors) {
			System.out.println(error);
		}
		
	}


	private static void writeResults(List<String> results) {
		try (BufferedWriter bw = new BufferedWriter(new FileWriter(new File(OUT_FILE_PATH)))) {
			for(int i = 0;i < results.size();i++) {
				bw.write(results.get(i) + "\n");
			}
		} catch (IOException e ) {
			System.err.println("Error writing result file!");
			e.printStackTrace();
		}
	}


	private static List<String> getLineContents() {
		List<String> contents = new ArrayList<>();
		try (BufferedReader br = new BufferedReader(new FileReader(new File(IN_FILE_PATH))) ) {
			String line = null;
			while ((line = br.readLine()) != null) {
				contents.add(line);
			}
		} catch (IOException e) {
			System.out.println("Problem with file access:");
			e.printStackTrace();
			System.exit(1);
		}
		return contents;
	}
	
	
	public interface ProblemSolver {
		ProblemData getCasesFromInput(List<String> input);
		
		String processCase(ProblemCase problemCase);
	}
	

	public static class ProblemData {
		private int caseCount;
		private List<ProblemCase> cases = new ArrayList<>();
		
		public int getCaseCount() {
			return caseCount;
		}
		public void setCaseCount(int caseCount) {
			this.caseCount = caseCount;
		}
		
		public void addCase(ProblemCase newCase) {
			cases.add(newCase);
		}
		
		public List<ProblemCase> getCases() {
			return cases;
		}
		
		/**
		 * Tag interface for problem case dto's
		 * @author Clay
		 *
		 */
		public interface ProblemCase {

		}
	}


}
