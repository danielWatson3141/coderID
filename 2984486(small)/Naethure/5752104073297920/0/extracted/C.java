import java.util.*;

public class C {
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		long time = System.currentTimeMillis();
		double[][] freq = getFreq();
	//	System.out.println("Ready: " + (System.currentTimeMillis() - time));
		
		int numCases = s.nextInt();
		for(int z = 1; z <= numCases; z++){
			int n = s.nextInt();
			int[] arr = new int[n];
			double[] freqVals = new double[n];
			double res = 0;
			
			for(int a = 0; a < n; a++){
				arr[a] = s.nextInt();
				freqVals[a] = freq[arr[a]][a];
			}
			System.out.println("Case #" + z + ": " + (sum(freqVals) > 7.2 ? "BAD" : "GOOD"));
			//System.out.println("Sum: " + sum(freqVals));
			//System.out.println("Mean: " + mean(freqVals));
			
			//System.out.println("Stddev: " + stddev(freqVals));
		}
	}
	
	public static double sum(double[] arr){
		double res = 0;
		for(int a = 0; a < arr.length; a++){
			res += arr[a];
		}
		return res;
	}
	public static double mean(double[] arr){
		return sum(arr)/arr.length;
	}
	public static double stddev(double[] arr){
		double mean = mean(arr);
		double sqDiffSum = 0;
		for(int a = 0; a < arr.length; a++){
			double toSquare = mean - arr[a];
			sqDiffSum += toSquare * toSquare;
		}
		double sqDiffMean = sqDiffSum / arr.length;
		return Math.sqrt(sqDiffMean);
	}

	public static double[][] getFreq() {
		int length = 1000;//1000;
		int numRuns = 100000; // 10000;
		int[][] timesInPosition = new int[length][length]; // [a][b] times that value a is in slot b

		for (int a = 0; a < numRuns; a++) {
			int[] arr = new int[length];
			for (int i = 0; i < length; i++) {
				arr[i] = i;
			}
			for (int k = 0; k < length; k++) {
				int p = rand(0, length);
				int tmp = arr[k];
				arr[k] = arr[p];
				arr[p] = tmp;
			}
			for (int n = 0; n < length; n++) {
				timesInPosition[arr[n]][n]++;
			}
		}
		double[][] positionVals = new double[length][length];
		for (int a = 0; a < length; a++) {
			for (int b = 0; b < length; b++) {
				positionVals[a][b] = timesInPosition[a][b] * length / (double) numRuns;
				positionVals[a][b] -= 1;
			}
		}
		return positionVals;
	}

	private static int rand(int min, int max) { // min inclusive, max exclusive
		return ((int) (Math.random() * (max - min))) + min;
	}
}
