import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class one 
{
	static int min = Integer.MAX_VALUE , n , k;

	public static void main(String[] args)throws IOException
	{
		BufferedReader ds = new BufferedReader(new InputStreamReader(System.in)) ;
		PrintWriter out = new PrintWriter(new FileWriter("file1.txt")) ;
		int t = Integer.parseInt(ds.readLine());
		
		StringTokenizer st ;
		int po = 1 ;
		while(t-->0)
		{
			st = new StringTokenizer(ds.readLine()) ;
			
			n = Integer.parseInt(st.nextToken()) ;
			k = Integer.parseInt(st.nextToken()) ;
			String s[] = new String[n] ;
			String r[] = new String[n] ;
			st = new StringTokenizer(ds.readLine()) ;
			for( int i = 0 ; i < n ; i++)
			{
				s[i] = st.nextToken() ;
			}
			st = new StringTokenizer(ds.readLine()) ;
			for( int i = 0 ; i < n ; i++)
			{
				r[i] = st.nextToken() ;
			}
			String r1[] = new String[n] ;
			min = Integer.MAX_VALUE ;
			for( int i = 0 ; i < n ; i++)	// i of s
			{	
				
				for( int c = 0 ; c < n ; c++){
					r1[c] = r[c] ;
				}
				boolean color[] = new boolean[n];
				int val  = 0 ;
				color[i] = true ;
				
				for( int j = 0 ; j < k ; j++)	//character-wise
				{	try{
					if(s[i].charAt(j) != r1[0].charAt(j))
					{	val++;
						for( int p = 0 ; p < n ; p++)
						{
							if(r1[p].charAt(j)=='1')
							{
								StringBuffer sp = new StringBuffer(r1[p]) ;
								sp.replace(j, j+1, "0") ;
								r1[p] = sp.toString() ;
							}
							else 
							{
								StringBuffer sp = new StringBuffer(r1[p]) ;
								
								sp.replace(j, j+1, "1") ;
								
								r1[p] = sp.toString() ;
							}
							
						}
					}}
				catch(Exception e){System.out.println(r1[0]);System.exit(0);}
					/*for( int p = 0 ; p < n ; p++)
						System.out.print(r1[p]+" ");
					System.out.println();*/
				}
				
				if(combos(s,r1,color,1))
					if(val < min ) min = val ;
				//System.out.println(val+" "+min);
				
			}
			if(min != Integer.MAX_VALUE)
			out.println("Case #"+po+": "+min);
			else
			out.println("Case #"+po+": "+"NOT POSSIBLE") ;
			po++;
		}
			out.close();
		
	}
	
	static boolean combos(String s[],String r[],boolean color[], int x )
	{
		if( x == n )
		{	
			return true;
		}
		
		for( int i = 0 ; i < n ; i++)
		{
			if( !color[i] && r[x].compareTo(s[i])==0 )
			{	
				color[i] = true ;
				if(combos(s,r,color,x+1))
					return true;
				color[i] = false ;
			}
				
		}
		return false ;
	}
}
