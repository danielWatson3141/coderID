package round1;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ProbA {
public static void main(String[] args)
{
	Scanner sc = new Scanner(System.in);
	int numcases = sc.nextInt();
	for(int curcase = 1 ; curcase <=numcases;curcase++)
	{
	int N = sc.nextInt();
	int L = sc.nextInt();
	boolean[][] outlets = new boolean[N][L];
	boolean[][] devices = new boolean[N][L];
	for(int i=0;i<N;i++)
	{
		//outlets[i] = new boolean[L];
	
	String s = sc.next();
	for(int j=0;j<L;j++)
		outlets[i][j] = (s.charAt(j)=='1');
	}
	for(int i=0;i<N;i++)
	{
		//devices[i] = new boolean[L];
	
	String s = sc.next();
	for(int j=0;j<L;j++)
		devices[i][j] = (s.charAt(j)=='1');
	}
	int minflip = Integer.MAX_VALUE;
	LOOP:
	for(int i=0;i<N;i++)
	{
		boolean[] mask = new boolean[L];
		for(int j=0;j<L;j++)
		{
			mask[j] = outlets[0][j]^devices[i][j];
		}
		Set<String> modoutlets = new HashSet<String>();
		for(int j=0;j<N;j++)
		{
			modoutlets.add(transl(outlets[j],mask));
		}
		//System.out.println(modoutlets.size());
		for(int j=0;j<N;j++)
		{
			if(!modoutlets.contains(transl2(devices[j])))
				continue LOOP;
		}
		int flips = 0;
		for(int j=0;j<L;j++)
		{
			if (mask[j])
					flips++;
		}
		if(flips<minflip)
		{
			minflip = flips;
//		System.out.println(transl2(mask));
		}
	}
	
	if(minflip <Integer.MAX_VALUE)
	System.out.println("Case #"+curcase+": "+minflip);
	else
	System.out.println("Case #"+curcase+": NOT POSSIBLE");

	}
	
}
public static String transl(boolean[] b,boolean[] mask)
{
	String ret = "";
	for(int i=0;i<b.length;i++)
		ret+=(b[i]^mask[i])?"1":"0";
	return ret;
}
public static String transl2(boolean[] b)
{
	String ret = "";
	for(int i=0;i<b.length;i++)
		ret+=(b[i])?"1":"0";
	return ret;
}
}