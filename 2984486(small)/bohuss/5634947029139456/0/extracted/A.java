package actual;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class A
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
		new A(argv[0]);
	}
	
	
	public A(String inputFile)
	{
		openInput(inputFile);
		readNextLine();

		int TC = NextInt();
		
		
		for(int tt=0; tt<TC; tt++)
		{	
			
			String output=solve();
			System.out.println("Case #"+(tt+1)+": "+output);
		}
		closeInput();
	}

	private String solve() {
		readNextLine();
		int N=NextInt();
		int L=NextInt();
		int [] p = new int[N];
		readNextLine();
		for(int i=0; i<N; i++)
		{
			String sw = NextString();
			for(int j=0; j<L; j++)
				if(sw.charAt(L-j-1)=='1')p[i]|=(1<<j);
		}
		int[] r = new int [N];
		readNextLine();
		for(int i=0; i<N; i++)
		{
			String sw = NextString();
			for(int j=0; j<L; j++)
				if(sw.charAt(L-j-1)=='1')r[i]|=(1<<j);
		}
		
		int ret=Integer.MAX_VALUE;
		for(int i=0; i<1<<L; i++)
		{
			if(ok(i,p,r,L))ret=Math.min(ret, Integer.bitCount(i));
		}
		if(ret==Integer.MAX_VALUE)return "NOT POSSIBLE";
		
		return ""+ret;
	}

	private boolean ok(int x, int [] p, int [] r, int L) {
		int N=p.length;
		
		int [] pp = new int[N];
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<L; j++)
			{
				if((x&(1<<j))==0)
				{
					if((p[i]&(1<<j))>0)pp[i]|=(1<<j);//pp[i]|=(p[i]&(1<<j));
				}
				else 
				{
					if((p[i]&(1<<j))==0)pp[i]|=(1<<j);
				}
			}
		}
		Arrays.sort(pp);
		Arrays.sort(r);
		for(int i=0; i<N; i++)
			if(pp[i]!=r[i])return false;
		return true;
	}
		
}

