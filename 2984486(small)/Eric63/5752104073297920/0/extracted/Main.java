import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class Main {
	public class Casse implements Comparable<Casse> {

		private long score;
		private int caseNb;
		private String line = "";

		public Casse(long score, int caseNb) {
			this.score = score ;
			this.setCaseNb(caseNb);
		}

		@Override
		public int compareTo(Casse arg0) {
			return (int) (arg0.score - this.score);
		}

		public int getCaseNb() {
			return caseNb;
		}

		public void setCaseNb(int caseNb) {
			this.caseNb = caseNb;
		}

		public void setResult(String string) {
			StringBuilder sb = new StringBuilder("Case #");
			sb.append(caseNb+1);
			sb.append(": ");
			sb.append(string);
			this.line = sb.toString();
		}

		public String getLine() {
			return line;
		}

	

	}

	//private static final String INPUT_NAME = "sample";
	private static final String INPUT_NAME = "C-small-attempt3";


	Scanner scanner;
	private BufferedWriter outputFile;

	public static void main(String[] args) throws IOException {
		new Main().start();
	}

	private void start() {
		openFiles();

		Casse[] caseList = new Casse[120];
		int caseNbTotal = scanner.nextInt();
		for (int caseNb = 0 ; caseNb < caseNbTotal ; caseNb++){
			long score = solveOneTestCase(caseNb);
			caseList[caseNb] = new Casse(score, caseNb);
		}

		
		Arrays.sort(caseList);
		for (int i = 0 ; i < 60 ; i++){
			caseList[i].setResult("GOOD");
		}
		for (int i = 60 ; i < 120 ; i++){
			caseList[i].setResult("BAD");
		}
		
		
		Arrays.sort(caseList, new Comparator<Casse>() {
		   @Override
			public int compare(Casse arg0, Casse arg1) {
				return arg0.caseNb -arg1.caseNb;
			}
		});
		
		for (Casse casse : caseList) {
			writeCase(casse.getLine());
		}
		
		// The end
		closeFiles();
	}

	private long solveOneTestCase(int caseNb) {
		// read case data
		int n  = scanner.nextInt();
		int[] permutation = new int[1000];
		for (int i = 0 ; i < n ; i++){
			permutation[i] = scanner.nextInt();
		}
		long avgg = 0;
		long avgd = 0;
		for (int i = 0 ; i < 500 ; i++){
			avgg += permutation[i];
		}
		for (int i = 500 ; i < 1000 ; i++){
			avgd += permutation[i];
		}
		long diff = Math.abs(avgd - avgg);
		return diff;
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

	private  void writeCase( String line) {
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
