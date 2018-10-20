/**
 * 
 */
package googleJam.Round1A2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

/**
 * @author Kisna
 *
 */
public class CargingChaos {
	public static void main(String[] args) {
		BufferedReader br = null;
		try {
			
			FileWriter fstream = new FileWriter("output.out");
			BufferedWriter out = new BufferedWriter(fstream);
			String sCurrentLine;

			br = new BufferedReader(new FileReader("A-large.in"));
			sCurrentLine = br.readLine();
			int i = 1;
			
			while ((sCurrentLine = br.readLine()) != null) {
				
				String ans = "NOT POSSIBLE";
				String[] temp = sCurrentLine.split(" ");
				int N = Integer.parseInt(temp[0]);
				int L = Integer.parseInt(temp[1]);
				String[] initial = br.readLine().split(" ");
				String[] required = br.readLine().split(" ");
				
				int[][] diffs = new int[N][N];
				int[][][] pos = new int[N][N][];
				
				for (int j = 0; j < N; j++) {
					for (int j2 = 0; j2 < N; j2++) {
						diffs[j][j2] = getBitDiff(initial[j], required[j2]);
						pos[j][j2] = new int[diffs[j][j2]];
						for (int k = 0; k < pos[j][j2].length; k++) {
							setPos(pos[j][j2], initial[j], required[j2]);
						} 
					}
				}
				
				int[] temp2 = new int[N];
				for (int j = 0; j < temp2.length; j++) {
					temp2[j] = diffs[0][j];
				}
				
				Arrays.sort(temp2);
				
				boolean[] lens = new boolean[N];
				boolean[] done = new boolean[N];
				boolean[] done2 = done;
				
				int index = 0;
				int first = 0;
				
				for (int j = 0; j < temp2.length; ) {					
					int t = getIndex(diffs[index], done2, temp2[j]);
					
					if(t == -1)
					{
						done2 = done;
						lens = new boolean[N];
						index = 0;
						j++;
						continue;
					}
					else
					{
						if(lens[t] || (index != 0 && lens[t] == false && !areSame(pos[index][t], pos[0][first])))
						{
							continue;
						}
						else
						{
							if(index == 0)
							{
								first = t;
							}
							lens[t] = true;
							
							if(index == N-1 && checkBool(lens))
							{
								if(checkBool(lens))
								{
									ans = String.valueOf(temp2[j]);
									break;
								}
								else
								{
									done2 = done;
									lens = new boolean[N];
									index = 0;
									j++;
									continue;
								}
							}
							
							done2 = new boolean[N];
							index++;
							continue;
						}
					}
					
				}
				
				out.write("Case #" + i++ + ": " + ans);
				//System.out.println("Case #" + i + ": " + ans);
				out.write("\n");
			}
			
			out.close();

		} catch (IOException e) {
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ex) {
			}
		}
	}
	
	public static boolean areSame(int[] a, int[] b)
	{
		for (int i = 0; i < b.length; i++) {
			if(a[i] == b[i])
			{
				continue;
			}
			else
				return false;
		}
		
		return true;
	}
	
	public static void setPos(int[] arr, String a, String b)
	{
		int id = 0;
		for (int i = 0; i < a.length(); i++) {
			if(a.charAt(i) != b.charAt(i))
			{
				arr[id] = i;
				id++;
			}
		}
	}
	
	public static int getBitDiff(String a, String b)
	{
		int diff = 0;
		for (int i = 0; i < a.length(); i++) {
			if(a.charAt(i) != b.charAt(i))
				diff++;
		}
		
		return diff;
	}
	
	public static int getIndex(int[] arr, boolean[] done, int val)
	{
		for (int i = 0; i < arr.length; i++) {
			if(arr[i] == val && done[i] == false)
			{
				done[i] = true;
				return i;
			}
		}
		
		return -1;
	}
	
	public static boolean checkBool(boolean[] arr)
	{
		for (int i = 0; i < arr.length; i++) {
			if(arr[i] == true)
				continue;
			else
				return false;
		}
		
		return true;
	}
}
