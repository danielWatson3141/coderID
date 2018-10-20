import java.util.Scanner;
import java.io.*;

public class CodeJam {
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("in.txt"));
		PrintStream out = new PrintStream(new File("out.txt"));
		int t=in.nextInt();
		for(int q=1;q<=t;q++)
		{
			int r=(int)(Math.random()*3);
			if(r==0)
				out.println("Case #"+q+": GOOD");
			else
				out.println("Case #"+q+": BAD");
		}
		in.close();
		out.close();
	}
}
