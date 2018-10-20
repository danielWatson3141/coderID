

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class main {

	public static void main(String[] args) throws Exception {


		Scanner sc = new Scanner(new File("in.txt"));
		FileWriter out = new FileWriter(new File("out.txt"));
		int T = new Integer(sc.nextLine());
		for(int i = 1 ; i < T+1 ; i++)
		{
			String res = "GOOD";
			int N = sc.nextInt();
			int [] nn = new int[N];
			for(int j = 0 ; j < N ; j++)
			{
				nn[j]  = sc.nextInt();
			}
			int inplace = 0;
			int before = 0;
			for(int j = 0 ; j <  N; j++)
			{
				if(nn[j] == j)
					inplace++;
				if(nn[j] == j+1)
					before++;
			}
			System.out.println(inplace + "   " + before);
			
			 if(before>1)
				res = "BAD";
			if(before>2)
				res="BAD";
			System.out.println("Case #"+i+": "+res);
			out.write("Case #"+i+": "+res+"\n");
			try{ sc.nextLine();}
			catch(Exception e){}

		}
		out.flush();
		sc.close();
		out.close();
	}
	
}
