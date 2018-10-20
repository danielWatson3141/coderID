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
	public static final String INPUT_FILE_NAME = "al.in" ;
	public static final String OUTPUT_FILE_NAME = "out.txt" ;
	public static final boolean DO_OUTPUT_TO_FILE = true ;
	
	public void solveCase( PrintWriter pwObj ) {
		int i , j , lim , a , b , c , mask , k , r1 , u , x ;
		int res ;
		char[][] crr , drr ;
		crr = new char[ this.lim2 ][ this.lim2 ] ;
		drr = new char[ this.lim2 ][ this.lim2 ] ;
		res = Integer.MAX_VALUE ;
		for( i = 0 ; i < this.n ; i++ ) {
			for( j = 0 ; j < this.l ; j++ ) {
				crr[ i ][ j ] = this.srr[ i ].charAt( j ) ;
			}
		}
		for( i = 0 ; i < this.n ; i++ ) {
			for( j = 0 ; j < this.l ; j++ ) {
				drr[ i ][ j ] = this.trr[ i ].charAt( j ) ;
			}
		}
		for( i = 0 ; i < this.n ; i++ ) {
			r1 = 0 ;
			this.cn = 0 ;
			for( k = 0 ; k < this.l ; k++ ) {
				if( crr[ 0 ][ k ] != drr[ i ][ k ] ) {
					r1++ ;
					this.arr[ this.cn ] = k ;
					this.cn++ ;
				}
			}
			char[][] err ;
			err = new char[ this.lim2 ][ this.lim2 ] ;
			for( k = 0 ; k < this.n ; k++ ) {
				for( u = 0 ; u < this.l ; u++ ) {
					err[ k ][ u ] = crr[ k ][ u ] ; 
				}
			}
			for( k = 0 ; k < this.n ; k++ ) {
				for( u = 0 ; u < this.cn ; u++ ) {
					x = this.arr[ u ] ;
					if( err[ k ][ x ] == '0' ) {
						err[ k ][ x ] = '1' ;
					}
					else {
						err[ k ][ x ] = '0' ;
					}
				}
			}
			Arrays.fill( this.brr , 0 ) ;
			for( j = 0 ; j < this.n ; j++ ) {
				for( k = 0 ; k < this.n ; k++ ) {
					if( this.brr[ k ] == 0 ) {
						a = 1 ;
						for( u = 0 ; u < this.l ; u++ ) {
							if( err[ j ][ u ] != drr[ k ][ u ] ) {
								a = 0 ;
								break ;
							}
						}
						if( a == 1 ) {
							this.brr[ k ] = 1 ;
							break ;
						}
					}
				}
			}
			a = 1 ;
			for( j = 0 ; j < this.n ; j++ ) {
				if( this.brr[ j ] == 0 ) {
					a = 0 ;
					break ;
				}
			}
			if( a == 1 ) {
				res = Math.min( res , r1 ) ;
			}
		}
		if( res == Integer.MAX_VALUE ) {
			pwObj.println( "Case #" + this.ind + ": NOT POSSIBLE" ) ;			
		}
		else {
			pwObj.println( "Case #" + this.ind + ": " + res ) ;
		}
	}
	
	private void init() {
		//default values
		this.lim1 = 210 ;
		this.lim2 = 210 ;		
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
		this.l = irObj.nextInt() ;
		for( i = 0 ; i < this.n ; i++ ) {
			this.srr[ i ] = irObj.nextString() ;
		}
		for( i = 0 ; i < this.n ; i++ ) {
			this.trr[ i ] = irObj.nextString() ;
		}
		return true ;
	}
	
	private int lim1 , lim2 , cn , ind , cc , n , l ; 
	private String[] srr , trr ;
	private int[] arr , brr ;
	private Node[] nrr ;
	private long[] lrr ;
	private int[][] memo , done ;
	private ArrayList< Integer >[] adj_list ;
	
	public void clearPerCase() {
		this.incrementInd() ;
		this.incrementCc() ;
		this.n = 0 ;
		this.cn = 0 ;
	}
	
	private void declareArrays() {
		//array declarations
		this.arr = new int[ this.lim1 ] ;
		this.brr = new int[ this.lim1 ] ;
		this.lrr = new long[ this.lim1 ] ;
		this.srr = new String[ this.lim1 ] ;
		this.trr = new String[ this.lim1 ] ;
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
