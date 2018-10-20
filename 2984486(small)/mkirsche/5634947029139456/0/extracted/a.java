import java.util.Arrays;
import java.util.Scanner;
public class a {
	static int oo = 987654321;
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		System.out.printf("Case #%d: ", t+1);
		int n = input.nextInt(), L = input.nextInt();
		String[] start = new String[n], end = new String[n];
		for(int i = 0; i<n; i++) start[i] = input.next();
		for(int i = 0; i<n; i++) end[i] = input.next();
		Arrays.sort(start);
		Arrays.sort(end);
		int res = oo;
		for(int i = 0; i<n; i++)
		{
			char[][] copy = new char[n][L];
			for(int j =0; j<n; j++)
				for(int k = 0; k<L; k++)
				{
					copy[j][k] = start[j].charAt(k);
				}
			int count = 0;
			//System.out.println(new String(copy[i]));
			for(int j = 0; j<L; j++)
			{
				if(copy[i][j] != end[0].charAt(j))
				{
					//System.out.println(i+" "+j);
					flip(copy, j);
					count++;
				}
			}
			String[] ss = new String[n];
			for(int j = 0; j<n; j++) ss[j] = new String(copy[j]);
			if(same(ss, end)) res = Math.min(res, count);
		}
		System.out.println(res == oo ? "NOT POSSIBLE" : res);
	}
}
static void flip(char[][] copy, int x)
{
	int n = copy.length;
	for(int i = 0; i<n; i++)
	{
		char c = copy[i][x];
		if(c == '0') copy[i][x] = '1';
		else copy[i][x] = '0';
	}
}
static boolean same(String[] a, String[] b)
{
	Arrays.sort(a);
	Arrays.sort(b);
	int n = a.length;
	for(int i = 0; i<n; i++) if(!a[i].equals(b[i])) return false;
	return true;
}
}
