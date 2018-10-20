import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

public class A {
	//private static String inputFileName = "/Users/study/Downloads/A-sample-attempt0.in";
	 private static String inputFileName = "/Users/study/Downloads/A-small-attempt2.in";
	// private static String inputFileName =
	// "/Users/study/Downloads/A-large-attempt0.in";

	private static String outputFileName = "/Users/study/Downloads/A-small-attempt2.out";

	// private static String inputFileName =
	// "/Users/study/Downloads/A-large-attempt0.out";

	public static void main(String[] args) throws Exception {
		StringBuilder output = new StringBuilder();

		Reader r = new FileReader(new File(inputFileName));
		BufferedReader reader = new BufferedReader(r);

		String strLine;

		int lineNumber = 0;
		int noOfTestCases = -1;
		int activeTestCaseNumber = 0;

		strLine = reader.readLine();
		noOfTestCases = Integer.parseInt(strLine);

		while (noOfTestCases-- != 0) {
			strLine = reader.readLine();
			String[] nl = strLine.split(" ");
			int n = Integer.parseInt(nl[0]); // N device
			int l = Integer.parseInt(nl[1]); // L switches.

			strLine = reader.readLine();
			String[] ori = strLine.split(" ");

			strLine = reader.readLine();
			String[] s = strLine.split(" ");

			int cnt = 0;
			int i, j = 0;
			Arrays.sort(s);
			int f = 0;

			String maxStr = "";
			for (i = 0; i < l; i++) {
				maxStr += "1";
			}

			int max = Integer.parseInt(maxStr, 2);

			Stack<String> a = new Stack<String>();

			for (i = 0; i <= max; i++) {
				a.push(String.format("%" + l + "s", Integer.toBinaryString(i))
						.replace(' ', '0'));
				//System.out.println(String.format("%" + l + "s",
					//	Integer.toBinaryString(i)).replace(' ', '0'));
			}
			
			boolean flag = false;
			Arrays.sort(ori);
			int minChange = Integer.MAX_VALUE;

			cnt = 0;
			for (j = 0; j < n; j++) {
				if (ori[j].equals(s[j])) {
					cnt++;
				}
				if (cnt == n) {
					minChange = 0;
					flag = true;
					break;
				}
			}
			
			if(false == flag)
			while (a.size() != 0) {
				String now = a.pop();

				String[] nori = (String[]) ori.clone();
				int change = 0;
				for(int c = 0; c < now.length(); c++) {
					if(now.charAt(c) != nori[0].charAt(c)) {
						change++;
						for(int x = 1; x < ori.length; x++) {
							char[] na = nori[x].toCharArray();
							if(na[c] == '1')
								na[c] = '0';
							else
								na[c] = '1';
							nori[x] = new String(na);
						}
					}
				}
				nori[0] = now;

				
				// change f switch
				Arrays.sort(nori);

				cnt = 0;
				for (j = 0; j < n; j++) {
					if (nori[j].equals(s[j])) {
						cnt++;
					}
					if (cnt == n) {
						if(minChange > change) {
							minChange = change;
						}
					}
				}

			}

			String solutionToTestCase = "1";

			if (minChange == 0)
				solutionToTestCase = "0";
			else if (minChange != Integer.MAX_VALUE) {
				solutionToTestCase = "" + minChange;
			} else {
				solutionToTestCase = "NOT POSSIBLE";
			}

			activeTestCaseNumber++;

			System.out.println(solutionToTestCase);
			output.append("Case #").append(activeTestCaseNumber).append(": ")
					.append(solutionToTestCase);
			output.append("\n");
		}
		/*
		 * while ((strLine = reader.readLine()) != null) {
		 * 
		 * if (lineNumber == 0) { noOfTestCases = Integer.parseInt(strLine); }
		 * else { activeTestCaseNumber++;
		 * 
		 * 
		 * // Invoke algorithm here String solutionToTestCase = "121";
		 * 
		 * // Prepare output string System.out.println(solutionToTestCase);
		 * output.append("Case #").append(activeTestCaseNumber)
		 * .append(": ").append(solutionToTestCase); output.append("\n"); }
		 * lineNumber++; }
		 */

		// Pass output string to method to write to file
		writeOutputToFile(output.toString());
		reader.close();
	}

	private static void writeOutputToFile(String str) throws URISyntaxException {
		File file = new File(outputFileName);
		try {
			FileWriter fw = new FileWriter(file);
			fw.write(str);
			fw.flush();
			fw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void permutation(String str) {
		permutation("", str);
	}

	private static void permutation(String prefix, String str) {
		int n = str.length();
		if (n == 0)
			System.out.println(prefix);
		else {
			for (int i = 0; i < n; i++)
				permutation(prefix + str.charAt(i),
						str.substring(0, i) + str.substring(i + 1, n));
		}
	}
}
