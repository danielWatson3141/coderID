import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Round1A_C_small {

	public static void main(String[] args) throws IOException {

		BufferedReader inputReader = new BufferedReader(
				new FileReader("fileRound1A_C\\C-small-attempt5.in"));
		BufferedWriter outputWriter = new BufferedWriter(
				new FileWriter("fileRound1A_C\\C-small-attempt5.out"));
		int testCaseNumber = Integer.valueOf(inputReader.readLine());
		for (int i = 1 ; i <= testCaseNumber ; i++) {
			int N = Integer.valueOf(inputReader.readLine());
			String permString = inputReader.readLine();
			String[] permArray = permString.split(" ");
			int[] permInt = new int[N];
			boolean isGood = true;
			
			for (int j = 0 ; j < N ; j++) {
				for (int k = j-1 ; k > 0 ; k--) {
					if (permInt[k] < j) {
						isGood = false;
					}
				}
			}
			
			if (isGood) {
				outputWriter.write("Case #" + Integer.toString(i) + ": GOOD");
			} else {
				outputWriter.write("Case #" + Integer.toString(i) + ": BAD");
			}
			
			outputWriter.newLine();
		}
		
		inputReader.close();
		outputWriter.close();
	}
	
	public static int[] good_perm(int N) {
		int[] perm = new int[N];
		for (int i = 0 ; i < N ; i++) {
			perm[i] = i;
		}
		for (int i = 0 ; i < N ; i++) {
			int p = i + (int)(Math.random()*(N-i));
			perm = swap(perm, i, p);
		}
		return perm;
	}
	
	public static int[] bad_perm(int N) {
		int[] perm = new int[N];
		for (int i = 0 ; i < N ; i++) {
			perm[i] = i;
		}
		for (int i = 0 ; i < N ; i++) {
			int p = (int)(Math.random()*N);
			perm = swap(perm, i, p);
		}
		return perm;
	}
	
	public static int[] swap(int[] perm, int i, int j) {
		int temp = perm[i];
		perm[i] = perm[j];
		perm[j] = temp;
		
		return perm;
	}
	
	public static int compare_two_array(int[] perm, int N) {
		int count = 0;
		for (int i = 0 ; i < N ; i++) {
			if(perm[i] == i) {
				count++;
			}
		}
		return count;
	}
}
