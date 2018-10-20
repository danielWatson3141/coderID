package round1A2014;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class C_ProperShuffle {

	int numTests;
	int arraySize;
	
	public C_ProperShuffle() throws IOException
	{

//		File txt = new File("src\\round1A2014\\C_InputTest");
//		File out = new File("src\\round1A2014\\C_OutputTest");
		File txt = new File("src\\round1A2014\\C_InputSmall");
		File out = new File("src\\round1A2014\\C_OutputSmall");
		
		FileWriter fw = new FileWriter(out);
		Scanner s = new Scanner(txt);
		StringBuilder sb = new StringBuilder();
		Random r = new Random();
		
		numTests = 120;
//		numTests = 2;
		s.nextLine(); //skip reading line with T
		
		arraySize = 1000; //stated
//		arraySize = 3;
		//build probability map
		int accuracy = 200000;
		
		//bad shuffle
		int[][] badCount = new int[arraySize][arraySize]; //[slot][number]
		for (int tries = 0; tries < accuracy; tries++)
		{
			int[] badShuffle = new int[arraySize];
			for (int k = 0; k < arraySize; k++)
			{
				badShuffle[k] = k;
			}
			for (int k = 0; k < arraySize; k++)
			{
				int p = r.nextInt(arraySize);
				int hold = badShuffle[k];
				badShuffle[k] = badShuffle[p];
				badShuffle[p] = hold;
			}
			for (int i = 0; i < arraySize; i++)
			{
				badCount[i][badShuffle[i]]++;
//				System.out.print(badShuffle[i]);
			}
//			System.out.println();
		}

//		System.out.println("number #: (times in slot)");
		
		double[][] pGrid = new double[arraySize][arraySize];
		
		for (int number = 0; number < arraySize; number++)
		{
//			System.out.print("number "+number+": ");
			for (int slot = 0; slot < arraySize; slot++)
			{
//				System.out.print(badCount[slot][number]+" ");
				pGrid[slot][number] = badCount[slot][number]*1.0/accuracy;
			}
//			System.out.println();
		}

//		System.out.println("\nnumber #: p(slot)");
//		for (int number = 0; number < arraySize; number++)
//		{
//			System.out.print("number "+number+": ");
//			for (int slot = 0; slot < arraySize; slot++)
//			{
//				System.out.print(pGrid[slot][number]+" ");
//			}
//			System.out.println();
//		}

		
		int numBad = 0;
		int numGood = 0;
		double threshold = 1.0085;
	
		for (int caseNum = 1; caseNum <= numTests; caseNum++)
		{
			s.nextLine(); //skip reading line with N
			Scanner lineScanner = new Scanner(s.nextLine());
			int[] inputArray = new int[arraySize];
			for (int n = 0; n < arraySize; n++)
			{
				inputArray[n] = lineScanner.nextInt();;
			}
			lineScanner.close();
			
			double worth = 0;

//			System.out.println();
			for (int n = 0; n < arraySize; n++)
			{
//				System.out.print(inputArray[n]);
				worth += pGrid[n][inputArray[n]];
			}
//			System.out.println();
//			System.out.println("Worth: "+worth);
		
			sb.setLength(0);
			sb.append("Case #");
			sb.append(caseNum);
			sb.append(": ");
			
			if (worth >= threshold)
			{
				sb.append("BAD");
				numBad++;
			}
			else
			{
				sb.append("GOOD");
				numGood++;
			}
			
			if (caseNum != numTests)
			{
				sb.append('\n');
			}
			fw.write(sb.toString());
		}
		
//		System.out.println();
		
		System.out.println("numBad: "+numBad);
		System.out.println("numGood: "+numGood);
		
		s.close();
		fw.close();
		
		
	}
	
	public static void main(String[] args)
	{
		try {
			new C_ProperShuffle();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
