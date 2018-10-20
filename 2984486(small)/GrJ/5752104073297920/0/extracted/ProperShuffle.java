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

public class ProperShuffle  {

	public class Result {
		public Result(int i, int solveIt) {
			number = i;
			solveIt = result;
		}
		int number;
		int result;
		public String getResult () {
			
			double a = Math.random();
			if (a> 0.5) return "BAD";
			return "GOOD";
			
		}
	}

	public static void main(String[] args) {
		BufferedReader br = null;
		File file;

		Locale.setDefault(Locale.US);
		
		ProperShuffle x = new ProperShuffle();
		ArrayList<Result> resultList = new ArrayList<Result>();
		

		try {

			file = new File("c:\\CodeJam\\ProperShuffle\\result.txt");
			if (file.exists())
				file.delete();
			file.createNewFile();

			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);

			br = new BufferedReader(new FileReader(
					"c:\\CodeJam\\ProperShuffle\\C-small-attempt0.in"));

			int t = Integer.parseInt(br.readLine());
			for (int i = 0; i < t; i++) {
				int n = Integer.parseInt(br.readLine());
				
				
				StringTokenizer a = new StringTokenizer(br.readLine());
				
				Integer[] initial = new Integer[n];
				
				for (int j = 0; j< n ; j++) {
					initial[j] = Integer.parseInt(a.nextToken());
				}
			

				resultList.add(x.new Result(i,solveIt(initial)));

				System.out.println(i + 1 + " -> " + (i + 1.0) * 100 / t + "%");
			}
			
			for (Result result : resultList) {
				bw.write("Case #" + (result.number+1) + ": " + result.getResult());
				bw.newLine();	
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

	private static int solveIt(Integer[] initial) {
		return 0;
	}


	
}
