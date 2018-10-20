package round_1A_2014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Charge {

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("Charge.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C:/Users/David/Desktop/Charge.txt"));
		StringTokenizer t = new StringTokenizer(f.readLine());
		int testCases = Integer.parseInt(t.nextToken());
		for (int i = 0; i < testCases; i++)
		{
			t = new StringTokenizer(f.readLine());
			int N = Integer.parseInt(t.nextToken());
			int L = Integer.parseInt(t.nextToken());
			
			int[] pull = new int[L]; //0 for leave, 1 for switch, 2 for both possible
			char[][] input = new char[N][L];
			char[][] output = new char[N][L];
			int[] countZeroIn = new int[L];
			int[] countZeroOut = new int[L];
			
			t = new StringTokenizer(f.readLine());
			for (int j = 0; j < N; j++)
			{
				String temp = t.nextToken();
				for (int k = 0; k < temp.length(); k++)
					input[j][k] = temp.charAt(k);
			}
			
			t = new StringTokenizer(f.readLine());
			for (int j = 0; j < N; j++)
			{
				String temp = t.nextToken();
				for (int k = 0; k < temp.length(); k++)
					output[j][k] = temp.charAt(k);
			}
			
			for (int j = 0; j < L; j++)
				for (int k = 0; k < N; k++)
					if (input[k][j] == '0') countZeroIn[j]++;
			for (int j = 0; j < L; j++)
				for (int k = 0; k < N; k++)
					if (output[k][j] == '0') countZeroOut[j]++;
			
			boolean possible = true;
			for (int j = 0; j < countZeroIn.length; j++)
			{
				if (countZeroIn[j] == countZeroOut[j])
				{
					if (countZeroIn[j] + countZeroOut[j] == N)
						pull[j] = 2;
					else
						pull[j] = 0;
				}
				else if (countZeroIn[j] + countZeroOut[j] == N)
					pull[j] = 1;
				else
					possible = false;
			}
			if (!possible)
			{
				String ans = "Case #" + (i+1) + ": NOT POSSIBLE";
				out.println(ans);
				System.out.println(ans);
			}
			else
			{
				int count = 0;
				for (int j = 0; j < L; j++)
					if (pull[j] == 1)
					{
						swap(input, j);
						count++;
					}
				int twos = 0;
				for (int j: pull)
					if (j==2)
						twos++;
				
				if (same(input, output))
				{
					String ans = "Case #" + (i+1) + ": " + count;
					out.println(ans);
					System.out.println(ans);
				}
				/*
				else if (twos > 0)
				{
					
					int[] pos = new int[twos];
					int c = 0;
					for (int j = 0; j < pull.length; j++)
						if (pull[j] == 2)
						{
							pos[c] = j;
							c++;
						}
					//System.out.println(twos);
					//for (int j: pos)
					//	System.out.print(j);
					
					possible = false;
					for (int s = 1; s <= twos; s++)
					{
						count++;
						if (works(input,output,pos,s, 0))
						{
							String ans = "Case #" + (i+1) + ": " + count;
							out.println(ans);
							System.out.println(ans);
							possible = true;
							break;
						}
					}
					if (!possible)
					{
						String ans = "Case #" + (i+1) + ": NOT POSSIBLE";
						out.println(ans);
						System.out.println(ans);
					}
				}
				*/
				else
				{
					String ans = "Case #" + (i+1) + ": NOT POSSIBLE";
					out.println(ans);
					System.out.println(ans);
				}
					
			}
			
					
		}

		out.close(); f.close(); System.exit(0);
	}
	public static boolean works(char[][] a, char[][] b, int[] pos, int twos, int p)
	{
		if (twos == 0)
		{
			return same(a,b);
		}
		if (p >= pos.length) return false;
		swap(a, pos[p]);
		boolean res = works(a,b,pos, twos-1, p+1);
		if (res) return true;
		swap(a, pos[p]); // swap back
		if (pos.length-p+1 > twos) //allowed to not swap
		{
			return works(a,b,pos,twos,p+1);
		}
		return false;
	}
	
	public static boolean same(char[][] a, char[][] b)
	{
		for (int i = 0; i < a.length; i++)
		{
			boolean ok = false;
			for (int j = 0; j < b.length; j++)
			{
				boolean same = true;
				for (int k = 0; k < b[j].length; k++)
				{
					if (a[i][k] != b[j][k])
					{
						same = false;
						break;
					}
				}
				if (same)
				{
					ok = true;
					break;
				}
			}
			if (!ok)
				return false;
		}
		return true;
	}
	
	public static void swap(char[][] a, int L)
	{
		for (int i = 0; i < a.length; i++)
			if (a[i][L] == '0')
				a[i][L] = '1';
			else
				a[i][L] = '0';
	}
}
