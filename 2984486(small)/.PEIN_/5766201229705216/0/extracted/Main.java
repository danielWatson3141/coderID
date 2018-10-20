import java.util.* ;
import java.io.* ;
import java.util.regex.* ;
import java.text.* ;
import java.math.* ;

public class Main {
	public static void main( String[] args ) {
		InputStream isObj ;
		OutputStream osObj ;
		InputReader irObj ;
		PrintWriter pwObj ;
		String inputFileName , outputFileName ;
		File fObj1 , fObj2 ;
		int T , ind ;
		boolean hasMoreInput , hasTestCases ;
		ProblemSolver psObj ;
		//only variable to be changed here is hasTestCases and osObj(optional for file output)
		hasTestCases = ProblemSolver.HAS_TEST_CASES ;
		isObj = System.in ;
		osObj = System.out ;
		inputFileName = ProblemSolver.INPUT_FILE_NAME ;
		outputFileName = ProblemSolver.OUTPUT_FILE_NAME ;
		try {
			fObj1 = new File( System.getProperty( "user.dir" ).toString() + "\\" + inputFileName ) ;
			fObj2 = new File( System.getProperty( "user.dir" ).toString() + "\\" + outputFileName ) ;
			if( fObj1.exists() == false ) {
				fObj1 = new File( System.getProperty( "user.dir" ).toString() + "\\src\\" + inputFileName ) ;
				fObj2 = new File( System.getProperty( "user.dir" ).toString() + "\\src\\" + outputFileName ) ;
			}
			isObj = new FileInputStream( fObj1 ) ;
			if( ProblemSolver.DO_OUTPUT_TO_FILE == true ) {
				osObj = new FileOutputStream( fObj2 ) ;
			}
		}
		catch( Exception ex ) {
			ex.printStackTrace() ;
			isObj = System.in ;
			osObj = System.out ;
		}
		irObj = new InputReader( isObj ) ;
		pwObj = new PrintWriter( osObj ) ;
		try {
			psObj = new ProblemSolver() ;
			if( hasTestCases == true ) {
				//for input with test cases
				T = irObj.nextInt() ;
				for( ind = 1 ; ind <= T ; ind++ ) {        	
					psObj.clearPerCase() ;
					psObj.getInput( irObj ) ;
					psObj.solveCase( pwObj ) ;
				}
			}
			else {
				//for end of file input
				for( ind = 1 ; ; ind++ ) {        	
					psObj.clearPerCase() ;
					hasMoreInput = psObj.getInput( irObj ) ;
					if( hasMoreInput == false ) {
						break ;
					}
					psObj.solveCase( pwObj ) ;
				}
			}
			pwObj.flush() ;
			isObj.close() ;
			osObj.close() ;
		}
		catch( Exception ex ) {
			ex.printStackTrace() ;
			throw new RuntimeException( ex ) ;
		}
		finally {
			pwObj.close() ;
		}
	}
}

class ProblemSolver {
	public static final boolean HAS_TEST_CASES = true ;
	public static final String INPUT_FILE_NAME = "bs.in" ;
	public static final String OUTPUT_FILE_NAME = "out.txt" ;
	public static final boolean DO_OUTPUT_TO_FILE = true ;
	
	private void dfs( int u ) {
		if( this.drr[ u ] != 1 ) {
			return ;
		}
		int v , sz , i , a ;
		this.vis[ u ] = 1 ;
		sz = this.adj_list[ u ].size() ;
		a = 0 ;
		for( i = 0 ; i < sz ; i++ ) {
			v = this.adj_list[ u ].get( i ) ;
			if( this.vis[ v ] == 0 && this.drr[ v ] == 1 ) {
				this.dfs( v ) ;
				a++ ;
			}
		}
		this.crr[ u ] = a ;
	}
	
	public void solveCase( PrintWriter pwObj ) {
		int i , j , u , v , a , b , c , x , lim , k , mask , r1 ;
		int res ;
		res = Integer.MAX_VALUE ;
		for( i = 0 ; i < this.n - 1 ; i++ ) {
			u = this.arr[ i ] ;
			v = this.brr[ i ] ;
			this.adj_list[ u ].add( v ) ;
			this.adj_list[ v ].add( u ) ;
		}
		x = this.n ;
		lim = ( 1 << x ) ;
		for( j = 0 ; j < lim ; j++ ) {
			for( u = 1 ; u <= this.n ; u++ ) {
				for( int zrr[] : this.done ) {
					Arrays.fill( zrr , 0 ) ;
				}
				for( int zrr[] : this.memo ) {
					Arrays.fill( zrr , -1 ) ;
				}
				Arrays.fill( this.vis , 0 ) ;
				Arrays.fill( this.crr , 0 ) ;
				Arrays.fill( this.drr , 0 ) ;
				mask = j ;
				r1 = 0 ;
				for( k = 0 ; k < this.n ; k++ ) {
					if( ( mask & ( 1 << k ) ) != 0 ) {
						r1++ ;
					}
					else {
						this.drr[ k + 1 ] = 1 ;
					}
				}
				if( this.drr[ u ] == 0 ) {
					continue ;
				}
				this.dfs( u ) ;
				a = 1 ;
				for( i = 1 ; i <= this.n ; i++ ) {
					if( this.crr[ i ] == 0 || this.crr[ i ] == 2 ) {
					}
					else {
						a = 0 ;
						break ;
					}
				}
				for( i = 1 ; i <= this.n ; i++ ) {
					if( this.vis[ i ] == 0 && this.drr[ i ] == 1 ) {
						a = 0 ;
						break ;
					}
				}
				if( a == 1 ) {
					res = Math.min( res , r1 ) ;
				}
			}
		}
		pwObj.println( "Case #" + this.ind + ": " + res ) ;
	}
	
	private void init() {
		//default values
		this.lim1 = 20 ;
		this.lim2 = 20 ;		
		this.cc = 1 ;
		this.ind = 0 ;
		this.declareArrays() ;
		this.fillAllArrays() ;
	}
	
	public boolean getInput( InputReader irObj ) {
		int i ;
		try {
			this.n = irObj.nextInt() ;
		}
		catch( Exception ex ) {
			return false ;
		}
		for( i = 0 ; i < this.n - 1 ; i++ ) {
			this.arr[ i ] = irObj.nextInt() ;
			this.brr[ i ] = irObj.nextInt() ;
		}
		return true ;
	}
	
	private int lim1 , lim2 , cn , ind , cc , n ; 
	private String[] srr ;
	private int[] arr , brr , vis , crr , drr ;
	private Node[] nrr ;
	private long[] lrr ;
	private int[][] memo , done ;
	private ArrayList< Integer >[] adj_list ;
	
	public void clearPerCase() {
		int i ;
		this.incrementInd() ;
		this.incrementCc() ;
		this.n = 0 ;
		this.cn = 0 ;
		Arrays.fill( this.vis , 0 ) ;
		Arrays.fill( this.crr , 0 ) ;
		for( int zrr[] : this.done ) {
			Arrays.fill( zrr , 0 ) ;
		}
		for( i = 0 ; i < this.lim1 ; i++ ) {
			this.adj_list[ i ].clear() ;
			this.adj_list[ i ] = new ArrayList< Integer >() ;
		}
	}
	
	private void declareArrays() {
		//array declarations
		this.arr = new int[ this.lim1 ] ;
		this.brr = new int[ this.lim1 ] ;
		this.crr = new int[ this.lim1 ] ;
		this.drr = new int[ this.lim1 ] ;
		this.vis = new int[ this.lim1 ] ;
		this.lrr = new long[ this.lim1 ] ;
		this.srr = new String[ this.lim1 ] ;
		this.nrr = new Node[ this.lim1 ] ;
		this.memo = new int[ this.lim2 ][ this.lim2 ] ;
		this.done = new int[ this.lim2 ][ this.lim2 ] ;
		this.adj_list = new ArrayList[ this.lim1 ] ;
	}
	
	private void fillAllArrays() {
		int i ;
		//array initiations
		Arrays.fill( this.arr , 0 ) ;
		Arrays.fill( this.brr , 0 ) ;
		Arrays.fill( this.crr , 0 ) ;
		Arrays.fill( this.drr , 0 ) ;
		Arrays.fill( this.lrr , 0 ) ;
		for( int zrr[] : this.memo ) {
			Arrays.fill( zrr , -1 ) ;
		}
		for( int zrr[] : this.done ) {
			Arrays.fill( zrr , 0 ) ;
		}
		for( i = 0 ; i < this.lim1 ; i++ ) {
			this.srr[ i ] = new String( "" ) ;
			this.nrr[ i ] = new Node( Integer.MIN_VALUE , Integer.MIN_VALUE ) ;
			this.adj_list[ i ] = new ArrayList< Integer >() ;
		}
	}
	
	private void incrementInd() {
		this.ind++ ;
	}
	
	public void setCn( int c ) {
		this.cn = c ;  
	}
	
	public void incrementCn() {
		this.cn++ ;
	}
	
	public void incrementCc() {
		this.cc++ ;
	}
	
	public int getCn() {
		return this.cn ;
	}
	
	public ProblemSolver() {
		this.init() ;
	}
}

class Node implements Comparable< Node > {
	private int v , f ;
	
	private Node() {
	}
	
	public Node( int vParam , int fParam ) {
		this.v = vParam ;
		this.f = fParam ;
	}
	
	public void setV( int vParam ) {
		this.v = vParam ;
	}
	
	public void setF( int fParam ) {
		this.f = fParam ;
	}
	
	public int getV() {
		return this.v ;
	}
	
	public int getF() {
		return this.f ;
	}
	
	public int compareTo( Node nParam ) {
		return this.getV() - nParam.getV() ;
	}
}

class InputReader {
	private BufferedReader reader ;
	private StringTokenizer tokenizer ;

	public InputReader( InputStream stream ) {
		this.reader = new BufferedReader( new InputStreamReader( stream ) ) ;
		this.tokenizer = null ;
	}

	private String next( int fl ) {
		while( this.tokenizer == null || ! this.tokenizer.hasMoreTokens() ) {
			try {                
				this.tokenizer = new StringTokenizer( this.reader.readLine() ) ;
			}
			catch( IOException e ) {
				throw new RuntimeException( e ) ;
			}
		}
		String s ;
		s = "" ;
		if( fl == 1 ) {
			s = this.tokenizer.nextToken() ; 
		}
		return s ;
	}

	public String nextLine() {
		this.next( 0 ) ;
		int fl ;
		String line ;
		line = "" ;
		fl = 0 ;
		if( this.tokenizer != null ) {
			while( this.tokenizer.hasMoreTokens() ) {
				if( fl == 1 ) {
					line += " " ;
				}
				fl = 1 ;
				line += this.tokenizer.nextToken() ;
			}
		}
		return line ;
	}

	public int nextInt() {
		return Integer.parseInt( this.next( 1 ) ) ;
	}

	public long nextLong() {
		return Long.parseLong( this.next( 1 ) ) ;
	}

	public double nextDouble() {
		return Double.parseDouble( this.next( 1 ) ) ;
	}

	public String nextString() {
		return this.next( 1 ) ;
	}
}
