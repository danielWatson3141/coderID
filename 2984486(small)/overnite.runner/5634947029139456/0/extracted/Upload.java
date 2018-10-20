/// A. Charging Chaos
//import java.awt.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

class Main
{
	int L, N;
//	int[][] dp;
	String[] oo, dd;
	
	int tenta()
	{
		boolean ok1 = false;
		int resp = Integer.MAX_VALUE;
		for (int i = 0; i <= (1 << L) - 1; ++i)
		{
			boolean ok2 = true; 
			for (int j = 0; j < N; ++j)
			{
				StringBuilder[] oo2 = new StringBuilder[N];
				for (int k = 0; k < N; ++k)
				{
					oo2[k] = new StringBuilder();
					for (int p = 0; p < L; ++p)
					{
						if (((1 << p) & i) != 0)
						{
							if (oo[k].charAt(p) == '0')
								oo2[k].append('1');
							else
								oo2[k].append('0');
						}
						else
						{
							oo2[k].append(oo[k].charAt(p));
						}
					}
				}
				boolean ok3 = false; 
				for (int k = 0; k < N; ++k)
					if (oo2[j].toString().equals(dd[k]))
					{
//						System.err.println(oo2[j].toString());
						ok3 = true;
						break;
					}
				if (!ok3)
				{
					ok2 = false;
					break;
				}
			}
			if (ok2)
			{
				ok1 = true;
				int contagem = Integer.bitCount(i);
				resp = Math.min(resp, contagem);
			}
		}
		return (ok1 ? resp : -1);
	}
	
	void executa() throws Exception
	{
		int caso = 1;

		BufferedReader leitor = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer fluxo = new StreamTokenizer(leitor);
		PrintWriter escritor = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

 		fluxo.resetSyntax();
		fluxo.ordinaryChars(0, 255);
		fluxo.wordChars('!', '~');
		fluxo.whitespaceChars('\n', ' ');
		fluxo.eolIsSignificant(false);

		try
		{
			int nt = Integer.parseInt(leitor.readLine());
			while (--nt >= 0)
			{
				fluxo.nextToken();
				N = Integer.parseInt(fluxo.sval);
				fluxo.nextToken();
				L = Integer.parseInt(fluxo.sval);
				oo = new String[N];
				for (int i = 0; i < N; ++i)
				{
					fluxo.nextToken();
					oo[i] = fluxo.sval;
//					System.err.println(oo[i]);
				}
				dd = new String[N];
				for (int i = 0; i < N; ++i)
				{
					fluxo.nextToken();
					dd[i] = fluxo.sval;
				}
				int resp = tenta();
				escritor.print("Case #" + caso + ": ");
				escritor.println(resp == -1 ? "NOT POSSIBLE" : resp);
				++caso;
			}
		}
		catch (Exception e)
		{
			System.err.println("Problema no caso " + caso);
			e.printStackTrace();
			throw new Exception();
		}
		finally
		{
			escritor.close();
		}
	}
	
	public static void main (String[] args) throws Exception
	{
		(new Main()).executa();
	}
}