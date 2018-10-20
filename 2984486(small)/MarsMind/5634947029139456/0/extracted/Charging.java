import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class Charging
{
	static int len;
	public static void main (String[] args) throws FileNotFoundException
	{
		Scanner s = new Scanner (new File ("A-small-attempt0.in"));
		FileWriter f;
		try
		{
			f = new FileWriter ("output.txt");
	
			int tests = s.nextInt ();
			for (int i = 1; i <= tests; i++)
			{
				int sets = s.nextInt ();
				len = s.nextInt ();
				
				s.nextLine ();
				
				String is = s.nextLine ();
				boolean [] init = new boolean [sets*len];
				for (int a = 0, b=0; a < is.length() && b<init.length; a++, b++)
				{
					if (is.charAt ( a ) == ' ')
					{
						b--;
						continue;
					}
					init [b] = (is.charAt ( a ) == '0') ? false : true;
				}
				
				String gs = s.nextLine ();
				boolean [] goal = new boolean [sets*len];
				for (int a = 0, b=0; a < gs.length() && b<goal.length; a++, b++)
				{
					if (gs.charAt ( a ) == ' ')
					{
						b--;
						continue;
					}
					goal [b] = (gs.charAt ( a ) == '0') ? false : true;
				}

				f.write ("Case #" + i + ": ");
				int res = flip (init, goal, 0, 0);
				if (res == Integer.MAX_VALUE)
				{
					f.write ("NOT POSSIBLE\n");
				}
				else
				{
					f.write(res+ "\n");
				}
			}
			f.close ();
		}
		catch (IOException e){}
		
	}
	
	public static int flip (boolean[] init, boolean[] goal, int flips, int index)
	{
		if (matches (init, goal))
		{
			return flips;
		}
		if(index >= len)
		{
			return Integer.MAX_VALUE;
		}
		boolean[] temp = Arrays.copyOf ( init, init.length );
		
		
		for (int i = index; i < init.length; i+=len)
			temp[i] = !temp[i];		
		
		return 	Math.min ( flip(temp, goal, flips+1, index+1), flip(init, goal, flips, index+1) );
	}
	
	public static boolean matches (boolean[] init, boolean[] goal)
	{
		boolean doesBreak = false;
		boolean[] checked = new boolean [goal.length];
		Arrays.fill(checked, false);
		for(int i=0; i<init.length; i+=len)
		{	
			for(int j=0; j<goal.length; j+=len)
			{
				doesBreak = false;
				for(int x = i,y = j; x < i+len &&y < j+len; x++, y++)
				{
					if (checked[y] || init[x] != goal[y])
					{
						doesBreak = true;
						break;
					}
				}
				if (doesBreak)
				{
					continue;
				}
				for(int y = j; y < j+len; y++)
				{
					checked[y] = true;
				}
			}
			
		}
		
		for(int i=0; i<checked.length; i++)
		{
			if(!checked[i])
			{
				return false;
			}
		}
		return true;
	}
	
}
