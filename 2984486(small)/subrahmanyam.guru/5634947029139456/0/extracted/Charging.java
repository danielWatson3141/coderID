package codejam.a1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Charging {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("c://codejam//a1//charging//A-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new File("c://codejam//a1//charging//out.txt"));
		int T = sc.nextInt();
		for(int i=1;i<=T;i++)
		{
			int N = sc.nextInt();
			int L = sc.nextInt();
			String[] soc = new String[N];
			String[] dev = new String[N];
			
			for(int j=0;j<N;j++)
				soc[j] = sc.next();
			for(int j=0;j<N;j++)
				dev[j] = sc.next();
			Arrays.sort(soc);
			Arrays.sort(dev);
			int min = 900;
			for(int j=0;j<N;j++)
			{
				String cur = dev[j];
				for(int k=0;k<N;k++)
				{
					String tsoc = soc[k];
					String chstr = cstrchange(cur,tsoc);
					boolean val = parsenum(dev,soc,chstr);
					if(val)
						min = Math.min(callen(chstr), min);
					
				}
			}
			
			if(min == 900)
				out.println("Case #"+i+": NOT POSSIBLE");
			else
				out.println("Case #"+i+": "+min);
			
		}
		out.close();
	}

	private static int callen(String chstr) {
		int count = 0;
		for(int i=0;i<chstr.length();i++)
		{
			if(chstr.charAt(i) == '1')
				count++;
		}
		return count;
	}

	private static boolean parsenum(String[] dev, String[] soc, String chstr) {
		
		changedev(dev,chstr);
		Arrays.sort(dev);
		boolean x = checkcorrect(dev,soc);
		changedev(dev,chstr);
		Arrays.sort(dev);
		return x;
	}

	private static boolean checkcorrect(String[] dev, String[] soc) {

		for(int i=0;i<dev.length;i++)
		{
			if(!dev[i].equals(soc[i]))
			{
				return false;
			}
		}
		return true;
	}

	private static void changedev(String[] dev, String chstr) {
		// TODO Auto-generated method stub
		for(int i=0;i<dev.length;i++)
		{
			int inlen = dev[i].length();
			int num = Integer.parseInt(dev[i],2);
			int map = Integer.parseInt(chstr,2);
			int cal = num^map;
			String k = Integer.toBinaryString(cal);
			dev[i]=addzero(inlen,k.length())+k;
		}
	}

	private static String addzero(int inlen, int length) {
		String zero = "";
		for(int i=0;i<inlen-length;i++)
			zero = zero+"0";
		return zero;
	}

	private static String cstrchange(String cur, String tsoc) {
		
		String chstr = "";
		for(int i=0;i<cur.length();i++)
		{
			if(cur.charAt(i) == tsoc.charAt(i))
			{
				chstr = chstr + "0";
			}
			else
				chstr = chstr + "1";
		}
		// TODO Auto-generated method stub
		return chstr;
	}

}
