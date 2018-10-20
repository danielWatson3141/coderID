package codejam.war;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public abstract class TestCaseIO {
	private String inputPath;
	private String outputPath;

	public TestCaseIO(String inputPath, String outputPath) {
		this.inputPath = inputPath;
		this.outputPath = outputPath;
	}

	protected abstract TestCase generateTestCase(BufferedReader file);

	public void doStuff() throws IOException {
		List<TestCase> cases = loadInput();
		List<String> output = solve(cases);
		writeOutput(output, outputPath);
	}

	private List<String> solve(List<TestCase> cases) {
		List<String> solved = new ArrayList<>();
		int caseNo = 1;
		for(TestCase singleCase : cases) {
			solved.add(singleCase.solve(caseNo++));
		}
		return solved;
	}

	private List<TestCase> loadInput() throws IOException {
		BufferedReader file = null;
		List<TestCase> testCases;
		try {
			file = new BufferedReader(new FileReader(inputPath));
			String l = file.readLine();
			int nOfCases = Integer.valueOf(l);
			testCases = new ArrayList<>(nOfCases);
			for (int i = 0; i < nOfCases; i++) {
				testCases.add(generateTestCase(file));
			}
		} finally {
			if (file != null) {
				file.close();
			}
		}
		return testCases;
	}
	
	private static void writeOutput(List<String> output, String path) throws IOException {
		PrintWriter file = null;
		try {
			file = new PrintWriter(new FileWriter(path, false));
			for (String solution : output) {
				file.println(solution);
			}
		} finally {
			if (file != null) {
				file.close();
			}
		}
	}
}
