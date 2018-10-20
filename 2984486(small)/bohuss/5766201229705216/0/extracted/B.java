package actual;
import java.io.*;
import java.util.*;

public class B
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
	
	double NextDouble()
	{
		String n = inputParser.nextToken();
		double val = Double.parseDouble(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	int NextInt()
	{
		String n = inputParser.nextToken();
		int val = Integer.parseInt(n);
		
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
		new B(argv[0]);
	}

	public B(String inputFile)
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
		int ret=Integer.MAX_VALUE;
		readNextLine();
		int N=NextInt();
		Graph G = new Graph(N);
		for(int i=0; i<N-1; i++)
		{
			readNextLine();
			int a=NextInt()-1, b=NextInt()-1;
			G.addEdge(a, b);
		}
		for(int i=0; i<(1<<N); i++)
		{
			Graph gg=G.remake(i);
			if(gg.isGood())
			{
				ret=Math.min(ret, Integer.bitCount(i));
			}
		}
		if(ret==Integer.MAX_VALUE)
		{
			ret=N-1;
			
		}
		return ""+ret;
	}
	
	private class Node
	{
		TreeSet <Integer> ngh = new TreeSet<Integer>();
		boolean used=true;
	}
	
	private class Graph
	{
		Node [] p;
		int N;
		
		Graph(int N)
		{
			this.N=N;
			p = new Node[N];
			for(int i=0; i<N; i++)
				p[i] = new Node();
		}

		public Graph remake(int x) {
			Graph g = new Graph(N);
			for(int i=0; i<N; i++)
				if((x&(1<<i))>0)g.p[i].used=false;
			for(int i=0; i<N; i++)
			{
				if(!g.p[i].used)continue;
				for(int y:p[i].ngh)
				{
					if(!g.p[y].used)continue;
					g.addEdge(i, y);
				}
			}
			return g;
		}

		public boolean isGood() {
			boolean no2=false;
			for(int i=0; i<N; i++)
			{
				switch(p[i].ngh.size())
				{
					case 2:
						if(no2)return false;
						no2=true;
						break;
					case 1:
					case 3:
					case 0:
						continue;
					default:
						return false;
				}
			}
			int id=0;
			while(id<N&&!p[id].used)id++;
			if(id==N)return false;
			boolean [] seen = new boolean[N];
			ArrayList <Integer> q = new ArrayList<Integer>();
			q.add(id);
			while(!q.isEmpty())
			{
				int x=q.remove(0);
				seen[x]=true;
				for(int y:p[x].ngh)
				{
					if(!seen[y])
					{
						seen[y]=true;
						q.add(y);
					}
				}
			}
			for(int i=0; i<N; i++)
				if(p[i].used&&!seen[i])return false;
			
			return no2;
		}

		public void addEdge(int a, int b) {
			p[a].ngh.add(b);
			p[b].ngh.add(a);
		}
	}
	
}

