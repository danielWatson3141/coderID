import java.io.File;
import java.util.Random;
import java.util.Scanner;


public class BadSort {
	static double[] probs = new double[1000];
	public static void main(String[] args) throws Exception{
		
		


		int[] counts = new int[1000];

		for(int i = 0;i<10000;i++) {
			int[] result = bad(1000);
		
			for(int j = 0;j<1000;j++) {
				int offset = (j - result[j] + 1000) % 1000;
				counts[offset]++;
			}
		}
		
		for(int i = 0;i<1000;i++) {
			
			probs[i] = counts[i]/10000000.0;
		//	System.out.println(i + " " + probs[i]);
			
		}
		
		Scanner s = new Scanner(new File("C-small-attempt0.in"));
		int numCases = Integer.parseInt(s.nextLine());
		for(int c = 1;c<=numCases;c++) {
			String count = s.nextLine();
			String items = s.nextLine();
			String[] itemsArr = items.split(" ");
			int[] shuffled = new int[itemsArr.length];
			for(int i = 0;i<itemsArr.length;i++) {
				shuffled[i] = Integer.parseInt(itemsArr[i]);
			}
			boolean result = isGood(shuffled);
			if(result) {
				System.out.println("Case #" + c + ": GOOD");
			} else {
				System.out.println("Case #" + c + ": BAD");
			}
		}
		
	}
	
	public static boolean isGood(int[] shuffled) {
		double badresult = 0;
		double goodresult = 0;
		for(int i = 0;i<1000;i++) {
			int offset = (i - shuffled[i] + 1000) % 1000;
			double prob = probs[offset];
		//	System.out.println(prob);
			badresult+=Math.log(prob);
			goodresult+=Math.log(0.001);
		}
	//	System.out.println(badresult + " " + goodresult);
		if(badresult > goodresult) {
			return false;
		} else {
			return true;
		}
	}
	
	static Random r = new Random();
	public static int[] good(int size) {
		int[] result = new int[size];
		for(int i = 0;i<result.length;i++) {
			result[i] = i;
		}
		for(int k = 0;k<size;k++) {
			int p = r.nextInt(size-k) + k;
			int temp = result[p];
			result[p] = result[k];
			result[k] = temp;
		}
		
		return result;
	}
	public static int[] bad(int size) {
		int[] result = new int[size];
		for(int i = 0;i<result.length;i++) {
			result[i] = i;
		}
		for(int k = 0;k<size;k++) {
			int p = r.nextInt(size);
			int temp = result[p];
			result[p] = result[k];
			result[k] = temp;
		}
		
		return result;
	}
}
