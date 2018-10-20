package actual;
import java.io.*;
import java.util.*;

public class C
{
	String line;
	StringTokenizer inputParser;
	BufferedReader is;
	FileInputStream fstream;
	DataInputStream in;
	
	void openInput(String file)
	{

		//is = new BufferedReader(new InputStreamReader(System.in));//stdin
		try{
			fstream = new FileInputStream(file);
			in = new DataInputStream(fstream);
			is = new BufferedReader(new InputStreamReader(in));
		}catch(Exception e)
		{
			System.err.println(e);
		}

	}
	
	void readNextLine()
	{
		try {
			line = is.readLine();
			inputParser = new StringTokenizer(line, " ");
			//System.err.println("Input: " + line);
		} catch (IOException e) {
			System.err.println("Unexpected IO ERROR: " + e);
		}	
		
	}
	
	int NextInt()
	{
		String n = inputParser.nextToken();
		int val = Integer.parseInt(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	long NextLong()
	{
		String n = inputParser.nextToken();
		long val = Long.parseLong(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	String NextString()
	{
		String n = inputParser.nextToken();
		return n;
	}
	
	void closeInput()
	{
		try {
			is.close();
		} catch (IOException e) {
			System.err.println("Unexpected IO ERROR: " + e);
		}
			
	}
	
	public static void main(String [] argv)
	{
		new C(argv[0]);
	}
	
	public C(String inputFile)
	{
		openInput(inputFile);
		readNextLine();

		int TC = NextInt();
		
		for(int t=0; t<TC; t++)
		{	
			
			readNextLine();
			int N=NextInt();
			int [] p = new int[N];
			readNextLine();
			for(int i=0; i<N; i++)
				p[i]=NextInt();
			
			int c=0;
			int cc=0;
			for(int i=0; i<N; i++)
				for(int j=i+1; j<N; j++)
					if(p[i]<p[j])c++;else cc++;
			
			
			System.out.println("Case #"+(t+1)+": "+(c>cc?"GOOD":"BAD"));
		}
		closeInput();
	}

	
}

