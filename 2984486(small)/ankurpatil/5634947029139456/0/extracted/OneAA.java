import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

import org.apache.commons.lang.ArrayUtils;


public class OneAA {
	static Scanner sc;
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		sc = new Scanner(new FileReader(args[0]));
		long T = sc.nextLong();
		for(long t = 1; t <= T ; t++)
		{
			int N = sc.nextInt();
			int L = sc.nextInt();
			char[] x;
			ArrayList<Integer> out = new ArrayList<Integer>();
			ArrayList<Integer> dev = new ArrayList<Integer>();
			for(int i=0; i< N; i++)
			{
				x = sc.next().toCharArray();
				int j = x.length-1;
				int sum = 0;
				for(char c: x)
				{
					if(c=='1')
					{
						sum = sum + (int) Math.pow(2, j);
					}
					j--;
				}
				out.add(sum);
			}

			for(int i=0; i< N; i++)
			{
				x = sc.next().toCharArray();
				int j = x.length-1;
				int sum = 0;
				for(char c: x)
				{
					if(c=='1')
					{
						sum = sum + (int) Math.pow(2, j);
					}
					j--;
				}
				dev.add(sum);
			}
			Collections.sort(out);
			Collections.sort(dev);
			ArrayList<Integer> newOut;
			int i = 0;
			int num = 0;
			int masterNum = 0;
			int n = L;
			int min = L+1;
			int max = (int) Math.pow(2, L);
			if(matching(out, dev))
			{
				System.out.println("Case #"+t+": 0");
			}
			else
			{
				do
				{
					newOut = new ArrayList<Integer>();
					for(int j =0;j<N;j++)
					{
						newOut.add(out.get(j) ^ num);
					}
					Collections.sort(newOut);
					i++;

					if(matching(newOut, dev))
					{
						int count = 0;
						int temp = num;
						while(temp > 0)
						{
							count = count + temp%2;
							temp = (int) Math.floor(temp/2);
						}
						if(count < min)
							min = count;
					}
					num++;
				}while(num < max);
				if(min > L)
					System.out.println("Case #"+t+": NOT POSSIBLE");
				else
				{

					System.out.println("Case #"+t+": "+min);
				}
			}
		}
	}

	public static boolean matching(ArrayList<Integer> out, ArrayList<Integer> dev)
	{
		int N = out.size();
		for(int i = 0; i<N; i++)
		{
			if(out.get(i).intValue()!= dev.get(i).intValue())
			{
				return false;
			}
		}
		return true;
	}
}

