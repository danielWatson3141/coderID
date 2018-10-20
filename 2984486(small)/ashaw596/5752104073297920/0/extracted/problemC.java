import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Random;

public class problemC {

	static int []startArray = new int[1000];
	
	static private int countLower(int[] array) {
		int count = 0;
	/*	for (int y=1; y<=500; y++) { 
			for (int x=0; x<y; x++) {
				if (array[x]<=y) {
					count++;
				}
			}
		}*/
		int y=1000;
			for (int x=0; x<y; x++) {
				if (array[x]>=x+1) {
					count++;
				}
			}
		return count;
	}
	static private int[] goodShuffle() {
		Random rand = new Random();
		int []newArray = Arrays.copyOf(startArray, 1000);
		int temp;
		int y;
		for (int x=0; x<1000; x++) {
			y = rand.nextInt(1000-x)+x;
			temp = newArray[x];
			newArray[x] = newArray[y];
			newArray[y] = temp;
		}
		return newArray;
	}
	
	private static int[] badShuffle() {
		Random rand = new Random();
		int []newArray = Arrays.copyOf(startArray, 1000);
		int temp;
		int y;
		for (int x=0; x<1000; x++) {
			y = rand.nextInt(1000);
			temp = newArray[x];
			newArray[x] = newArray[y];
			newArray[y] = temp;
		}
		return newArray;
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(new File("C-small-attempt6.in"));
		PrintWriter out = new PrintWriter(new FileWriter("outputC.txt")); 
		int testCases = input.nextInt();
		int []count = new int[120];
		for (int x=0; x<1000; x++) {
			startArray[x] = x;
		}
		int [][]array = new int[120][1000];
		for (int i=1; i<=testCases; i++) {
			int size = input.nextInt();
			
			
			for (int x = 0; x<size; x++) {
				array[i-1][x] = input.nextInt();
			}
		}
			
		for (int i=0; i<120; i++) {
			count[i] = countLower(array[i]);
		}
		int[]sortCount = Arrays.copyOf(count, 120);
		Arrays.sort(sortCount);
		int ave = sortCount[60];
		/*for (int i=0; i<=600000; i++) {
			int[]badArray = badShuffle();
			int[]goodArray = goodShuffle();
			for(int x=0; x<120; x++) {
				if (Arrays.equals(badArray, array[x])) {
					badCount[x]++;
				}
				if (Arrays.equals(goodArray, array[x])) {
					goodCount[x]++;
				}
			}
		}*/
		
		for (int i=1; i<=120; i++) {
			out.print("Case #" + i + ": ");
			if (count[i-1]<ave) {
				out.print("GOOD");
			} else {
				out.print("BAD");
			}
			out.println();
		}
		out.close();
	}

}
