import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Problem
{
	public static void main(String[] args) throws IOException
	{
		Scanner scan = new Scanner(new File("test.in"));
		int numCases = scan.nextInt();
		scan.nextLine();
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("test.out")));
		
		for(int caseN = 1; caseN <= numCases; caseN++)
		{
			int n = scan.nextInt(), size = scan.nextInt();
			boolean[][] switches = new boolean[n][size], devices = new boolean[n][size];
			scan.nextLine();
			String[] s = scan.nextLine().split(" "), d = scan.nextLine().split(" ");
			int[] tot1 = new int[size], tot2 = new int[size];
			for(int i = 0; i < n; i++) for(int j = 0; j < size; j++)
			{
				switches[i][j] = s[i].charAt(j) == '1';
				tot1[j] += switches[i][j] ? 1 : 0;
			}
			for(int i = 0; i < n; i++) for(int j = 0; j < size; j++)
			{
				devices[i][j] = d[i].charAt(j) == '1';
				tot2[j] += devices[i][j] ? 1 : 0;
			}
			int answer = put(-1, tot1, tot2, switches, devices, 0);
			writer.write("Case #" + caseN + ": " + (answer == -1 ? "NOT POSSIBLE" : answer) + "\n");
		}
		
		scan.close();
		writer.close();
	}
	
	public static int put(int index, int[] tot1, int[] tot2, boolean[][] s, boolean[][] d, int changes)
	{
		if(++index == s[0].length)
		{
			ArrayList<boolean[]> sa = new ArrayList<boolean[]>(Arrays.asList(s)),
					           da = new ArrayList<boolean[]>(Arrays.asList(d));
			for(int i = 0; i < sa.size(); i++)
			{
				for(int j = 0; j < da.size(); j++)
				{
					boolean good = true;
					for(int k = 0; k < s[0].length; k++) good &= sa.get(i)[k] == da.get(j)[k];
					if(good)
					{
						sa.remove(i--);
						da.remove(j--);
						break;
					}
				}
			}
			
			if(sa.size() == 0) return changes;
			return -1;
		}
		
		if(tot1[index] == tot2[index])
		{
			int notchange = put(index, tot1, tot2, s, d, changes),
				change = put(index, tot1, tot2, negate(copy(s), index), d, changes + 1);
			if(change != -1 && (change < notchange || notchange == -1)) return change;
			return notchange;
		}
		else if(tot1[index] == s.length - tot2[index]) return put(index, tot1, tot2, negate(copy(s), index), d, changes + 1);
		return -1;
	}
	
	public static boolean[][] negate(boolean[][] a, int index)
	{
		for(int i = 0; i < a.length; i++) a[i][index] = !a[i][index];
		return a;
	}
	
	public static boolean[][] copy(boolean[][] init)
	{
		boolean[][] copy = new boolean[init.length][init[0].length];
		for(int i = 0; i < init.length; i++) for(int j = 0; j < init[0].length; j++) copy[i][j] = init[i][j];
		return copy;
	}
}