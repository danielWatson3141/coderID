import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class Main {
	//private static final String INPUT_NAME = "sample";
	private static final String INPUT_NAME = "A-small-attempt0";
	//private static final String INPUT_NAME = "B-large";

	Scanner scanner;
	private BufferedWriter outputFile;
	private int nbDevice;
	private int nbBits;

	public static void main(String[] args) throws IOException {
		new Main().start();
	}

	private void start() {
		openFiles();

		int caseNbTotal = scanner.nextInt();
		for (int caseNb = 0 ; caseNb < caseNbTotal ; caseNb++){
			solveOneTestCase(caseNb);
		}

		// The end
		closeFiles();
	}

	private void solveOneTestCase(int caseNb) {
		// read case data
		nbDevice  = scanner.nextInt();
		nbBits = scanner.nextInt();
		
		char[] [] deviceFlows = new char[nbDevice][]; 
		char[] [] plugFlows = new char[nbDevice][]; 
		for (int i = 0 ; i < nbDevice ; i++) {
			String bytes = scanner.next();
			deviceFlows[i] = bytes.toCharArray();
		}
		for (int i = 0 ; i < nbDevice ; i++) {
			String bytes = scanner.next();
			plugFlows[i] = bytes.toCharArray();
		}
		
		String[] deviceFlowsString = new String[nbDevice];
		for(int i = 0 ; i < nbDevice ; i++){
			deviceFlowsString[i] = new String (deviceFlows[i]);
		}
		Arrays.sort(deviceFlowsString);
		
		ArrayList<Integer> youcanTryToChange = new ArrayList<Integer>();
		
		for (int bitNumberToSwitch = 0 ; bitNumberToSwitch < nbBits ; bitNumberToSwitch ++ ) {
			int nb1Device = getNb1(bitNumberToSwitch, deviceFlows);
			int nb1Flow = getNb1(bitNumberToSwitch, plugFlows);
			if ((nbDevice - nb1Flow) == nb1Device ) {
				youcanTryToChange.add( bitNumberToSwitch );
			}
		}
		int minNumberOfSwithToChange = 1000;
		int size = youcanTryToChange.size();
		for (int i = 0 ; i < (1<<size) ; i++) {
			char[] [] testPlugFlows = shakeIt(plugFlows, youcanTryToChange, i);
			if ( areTheSame(testPlugFlows,deviceFlowsString)) {
				int nbChanged = Integer.bitCount(i);
				if (nbChanged < minNumberOfSwithToChange) {
					minNumberOfSwithToChange = nbChanged;
				}
			}
		}
		
		// write case solution
		String result = String.valueOf(minNumberOfSwithToChange);
		if (minNumberOfSwithToChange == 1000) {
			result = String.valueOf("NOT POSSIBLE");
		} 
		writeCase(caseNb, result);
	}

	private boolean areTheSame(char[][] testPlugFlows, String[] deviceFlowsString) {
		String[] testPlugFlowsString = new String[nbDevice];
		for(int i = 0 ; i < nbDevice ; i++){
			testPlugFlowsString[i] = new String (testPlugFlows[i]);
		}
		Arrays.sort(testPlugFlowsString);
		for (int i = 0 ; i < nbDevice ; i++){
			if (!testPlugFlowsString[i].equals(deviceFlowsString[i]))
				return false;
		}
		return true;
	}

	private char[][] shakeIt(char[][] plugFlows, ArrayList<Integer> youcanTryToChange, int combinasonToChange) {
		char[] [] plugFlowsResult = new char[nbDevice][]; 
		int nb = 0;
		for (char[] cs : plugFlows) {
			plugFlowsResult[nb++] = Arrays.copyOf(cs,nbBits);
		}
		for (char[] cs : plugFlowsResult) {
			for (int w = 0 ; w < nbBits; w++) {
				if ( (combinasonToChange & (1<<w)) > 0) {
					Integer bitToChange = youcanTryToChange.get(w);
					if (cs[bitToChange] == '1')
						cs[bitToChange] = '0';
					else {
						cs[bitToChange] = '1';
					}
				}
			}
		}
		return plugFlowsResult;
	}

	private int getNb1(int bitNumberToSwitch, char[][] li) {
		int r = 0;
		for (char[] d : li) {
			if (d[bitNumberToSwitch] == '1')
				r ++;
		}
		return r;
	}

	private void closeFiles() {
		try {scanner.close();
		outputFile.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	private void openFiles() {
		try {
			scanner = new Scanner(Main.class.getResourceAsStream(INPUT_NAME + ".in"));
			outputFile = new BufferedWriter(new FileWriter(INPUT_NAME + "-result.txt"));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	private  void writeCase(int caseNb, String result) {
		StringBuilder sb = new StringBuilder("Case #");
		sb.append(caseNb+1);
		sb.append(": ");
		sb.append(result);
		String line = sb.toString();
		System.out.println(line);
		try {
			outputFile.write(line);
			outputFile.write("\n");
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

}
