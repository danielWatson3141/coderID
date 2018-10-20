package cookie;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.regex.Pattern;


public class charging {
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		sc.useDelimiter(Pattern.compile(System.getProperty("line.separator")+"| "));
		//Scanner sc = new Scanner(new FileReader("B-small-attempt0.in"));
		
		int cases = sc.nextInt();
		int n, l;
		
		for(int i = 0; i < cases; i++){
			int equal = 0, found = 0;
			ArrayList<String> initial = new ArrayList<String>();
			ArrayList<String> required = new ArrayList<String>();
			ArrayList<String> copy = new ArrayList<String>();			
			n = sc.nextInt();
			l = sc.nextInt();
			int min = l;

			for(int j = 0; j < n; j++)
			{
				String temp = sc.next();
				initial.add(temp);
			}
			
			for(int j = 0; j < n; j++)
			{
				String temp = sc.next();
				required.add(temp);
			}		
			Collections.sort(required);
			
			/*ArrayList<Integer> result = new ArrayList<Integer>();
			for(int k = 0; k < l && min != -1; k++)
			{
				int requiredzero = 0, initialzero = 0;
				for(int j = 0; j < n; j++)
				{
					if(required.get(j).charAt(k) == '0')
						requiredzero += 1;
					if(initial.get(j).charAt(k) == '0')
						initialzero += 1;
				}

				if(initialzero == requiredzero)
				{
					if(initialzero == n - requiredzero)
					{
						result.add(2);
						equal++;
					}
					else
						result.add(0);
				}
				else if(initialzero == n -requiredzero)
				{
					result.add(1);
					for(int j = 0; j < n ; j++)
					{
						if(initial.get(j).charAt(k) == '0')
						{
							char[] temp = initial.get(j).toCharArray();
							temp[k] = '1';
							initial.set(j, String.valueOf(temp));
						}
						if(initial.get(j).charAt(k) == '1')
						{
							char[] temp = initial.get(j).toCharArray();
							temp[k] = '0';
							initial.set(j, String.valueOf(temp));
						}
					}
					min ++;
				}
				else
				{
					min = -1;
				}
			}*/
			
			String first = initial.get(0);
			for(int j = 0; j < n; j++)
			{
				int tempmin = 0;
				copy.clear();
				copy.addAll(initial);
				String r = required.get(j);
				for(int k = 0; k < l; k++)
				{
					if(first.charAt(k) != r.charAt(k))
					{
						for(int m = 0; m < n; m++)
						{
							if(copy.get(m).charAt(k) == '0')
							{
								char[] temp = copy.get(m).toCharArray();
								temp[k] = '1';
								copy.set(m, String.valueOf(temp));
							}
							else if(copy.get(m).charAt(k) == '1')
							{
								char[] temp = copy.get(m).toCharArray();
								temp[k] = '0';
								copy.set(m, String.valueOf(temp));
							}
						}
						tempmin ++;
					}

				}
				//System.out.println(copy.toString());
				Collections.sort(copy);

				if(copy.equals(required))
				{
						found = 1;
						if(tempmin < min)
						{
							min = tempmin;
						}
					}
			}

			if(found == 1)
				System.out.println("Case #" + (i+1) + ": " + min);
			else
				System.out.println("Case #" + (i+1) + ": NOT POSSIBLE");
		}
	}
}