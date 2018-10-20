import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


public class ProblemC {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		long startTime = System.currentTimeMillis();
		int maxDim = 5;
		int[][][] scenarios = new int[maxDim + 1][maxDim + 1][maxDim * maxDim + 1];
		FileWriter writer = new FileWriter("C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\output.txt");
		String filename = "C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\input.txt";
		int[][] prob = new int[1000][1000];
		int trials = 3000000;
		for(int i = 0; i < trials; i++){
			int[] numbers = new int[1000];
			for(int index = 0; index < 1000; index++){
				numbers[index] = index;
			}
			for(int k = 0; k < 1000; k++){
				int p = (int)(Math.random()*1000);
				int temp = numbers[p];
				numbers[p] = numbers[k];
				numbers[k] = temp;
			}
			for(int k = 0; k < 1000; k++){
				prob[numbers[k]][k]++;
			}
		}
		int target = trials/1000;
		int error = target/5;
		int numBad = 0;
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			int numCases = Integer.parseInt(br.readLine());
			ArrayList<Integer> errorsSort = new ArrayList<Integer>();
			ArrayList<Integer> errors = new ArrayList<Integer>();
			for(int i = 0; i < numCases; i++){
				String line = br.readLine();
				line = br.readLine();
				int total = 0;
				StringTokenizer st = new StringTokenizer(line);
				for(int index = 0; index < 1000; index++){
					int next = Integer.parseInt(st.nextToken());
					if(prob[next][index] >target + error){
						total++;
					} else if(prob[next][index] < target - error){
						total--;
					}
				}
				errors.add(Math.abs(total));
				errorsSort.add(Math.abs(total));
			}	
			Collections.sort(errorsSort);
			int threshold = errorsSort.get(errorsSort.size()/2);
			for(int i = 0; i < numCases; i++){
				if(errors.get(i) > threshold){
					printAnswer("BAD", i + 1, writer);
					numBad++;
				} else {
					printAnswer("GOOD", i + 1, writer);
				}
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(numBad);
		writer.close();
		System.out.println(System.currentTimeMillis() - startTime);
	}
	
	public static void printAnswer(String answer, int caseNumber, FileWriter writer) throws IOException{
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
