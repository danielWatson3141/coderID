package gcj2014.round1a;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class A
{
	private static int debugCC = -1;
	private static int cc;
	private static void putput() throws IOException
	{
		int cases = INT();
		cc: for (cc = 1; cc<=cases; cc++)
		{
			int N = INT();
			int L = INT();
			int[] Osource = new int[N];
			int[] Otarget = new int[N];

			for (int i=0;i<N;i++) Osource[i] = Integer.parseInt(STRING(), 2);
			for (int i=0;i<N;i++) Otarget[i] = Integer.parseInt(STRING(), 2);
			Arrays.sort(Otarget);
			
			int maxB = (int) Math.pow(2, L);
			int bruteMin = Integer.MAX_VALUE;

			debugln(Arrays.toString(Osource));
			debugln(Arrays.toString(Otarget));
			
			for (int b=0;b<maxB;b++)
			{
				int[] OsourceBrute = Osource.clone();
				
				String brute = Integer.toBinaryString(b);
				char[] tmp = new char[L-brute.length()];
				Arrays.fill(tmp,'0');
				brute = new String(tmp)+brute;
				debugln(brute);
				
				for (int i=0;i<N;i++) OsourceBrute[i] = OsourceBrute[i] ^ b;
				Arrays.sort(OsourceBrute);
				debugln(Arrays.toString(OsourceBrute));

				if (Arrays.equals(OsourceBrute, Otarget)) bruteMin = Math.min(bruteMin, Integer.bitCount(b));
			}
			if (bruteMin == Integer.MAX_VALUE) println("Case #"+cc+": "+"NOT POSSIBLE");
			else println("Case #"+cc+": "+bruteMin);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 03:00 - 
//		String problemFile = "test";
		
//		String problemFile = "%s-small-attempt0";
		String problemFile = "%s-small-attempt1";
//		String problemFile = "%s-large";
		
		try
		{
			String problem = new Object(){}.getClass().getEnclosingClass().getSimpleName();
			String folder = "_"+new Object(){}.getClass().getPackage().getName();
			
			init(folder+"/"+String.format(problemFile, problem));
			putput(); 
			done();
		}
		catch (Throwable e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}

	private static File input;
	private static FileReader inputReader;
	private static BufferedReader in;
	private static File output;
	private static FileWriter outputWriter;
	private static BufferedWriter out;
	private static StringTokenizer st;

	private static void init (String fileName) throws IOException
	{
		// input
		input = new File(fileName+".in");
		inputReader = new FileReader(input);
		in = new BufferedReader(inputReader);
		
		// output
		output = new File(fileName+".out");
		outputWriter = new FileWriter(output);
		out = new BufferedWriter(outputWriter);
	}
	
	private static void done ()
	{
		try	{in.close();} catch (Exception e){}
		try	{inputReader.close();} catch (Exception e){}
		try	{out.close();} catch (Exception e){}
		try	{outputWriter.close();} catch (Exception e){}
	}
	
	// in
	private static String LINE() throws IOException
	{
		return in.readLine();
	}
	private static String TOKEN() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
		{
			st = new StringTokenizer(LINE());
		}
		return st.nextToken();
	}
	private static int INT() throws IOException
	{
		return parseInt(TOKEN());
	}
	private static long LONG() throws IOException
	{
		return parseLong(TOKEN());
	}
	private static double DOUBLE() throws IOException
	{
		return parseDouble(TOKEN());
	}
	private static String STRING() throws IOException
	{
		return TOKEN();
	}
	private static int[] INT_ARRAY() throws IOException
	{
		String[] s = LINE().split(" ");
		int[] r = new int[s.length];
		for(int i=0; i<s.length; i++) r[i] = Integer.parseInt(s[i]);
		return r;
	}
	private static long[] LONG_ARRAY() throws IOException
	{
		String[] s = LINE().split(" ");
		long[] r = new long[s.length];
		for(int i=0; i<s.length; i++) r[i] = Long.parseLong(s[i]);
		return r;
	}
	
	// putput
	private static String DOUBLE_STRING(Double d)
	{
		NumberFormat f = NumberFormat.getInstance();
		f.setGroupingUsed(false);
//		f.setMaximumFractionDigits(7);
//		f.setMinimumFractionDigits(7);
		return f.format(d);
	}
	private static DecimalFormat _DF = new DecimalFormat("0000");
	private static String DF(int i)
	{
		return _DF.format(i);
	}
	private static DecimalFormat _DF2 = new DecimalFormat();
	private static String DF2(double i)
	{
		NumberFormat numberFormat = NumberFormat.getNumberInstance(Locale.US);
        ((DecimalFormat) numberFormat).applyPattern("#0.0000000"); 
		return numberFormat.format(i);
	}
	
	// out
	private static void print (String str) throws IOException
	{
		out.write(str);
		debug(str,true);
	}
	private static void println (String str) throws IOException
	{
		print(str+"\r\n");
	}
	private static void debug (String str, boolean force) throws IOException
	{
		if (debugCC==0 || cc==debugCC || force)
			System.out.print(str);
	}
	private static void debug (String str) throws IOException
	{
		if (debugCC==0 || cc==debugCC)
			System.out.print(str);
	}
	private static void debugln (String str) throws IOException
	{
		debug(str+"\r\n");
	}
}
