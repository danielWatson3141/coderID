package com.levneiman.alg_cmp;
import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.lang.reflect.Array;
import java.math.*;
import java.awt.geom.*;

import com.levneiman.alg_cmp.GCJ_2014.QualificationRound.A;

/**
 * Google Code Jam problems solved (sometimes incorrectly) by Lev. A. Neiman.
 *
 * @author Lev Neiman - lev.neiman@gmail.com
 *
 */
public class Problems
{

	public static PrintStream SO = System.out;

	public interface Problem
	{
		public void solve( InputStream in, PrintStream out ) throws Exception;
	}

	public abstract static class GCJProblem implements Problem
	{
	    private static final String ANSWER_FORMAT = "Case #%d: %s";

        @Override
        public void solve(InputStream in, PrintStream out) throws Exception
        {
            Scanner scanner = new Scanner(in);
            int T = Integer.parseInt(scanner.nextLine());
            SO.println(String.format("Will attempt to solve %d cases.  Godspeed.", T));
            for (int CASE = 1; CASE <=T; ++CASE)
            {
                SO.println(String.format("=== Doing case %d ===", CASE));
                out.println(String.format(ANSWER_FORMAT, CASE, solve(scanner)));
            }
        }

        public abstract String solve(Scanner in);
	}

	public interface acm_problem extends Problem {}

	public interface facebook_problem extends Problem {}


	public static class Util< T >
	{

	    public static class PrettyPrint
	    {
	        public static <E> String print(E[] arr)
	        {
	            String ret = "";
	            for (int i = 0; i < arr.length; ++i)
	            {
	                ret += arr[i].toString() + ", ";
	            }
	            return ret;
	        }
	    }

	    /**
	     * Mmmmmmmmulti Map!
	     * @author lneiman
	     *
	     * @param <T>
	     * @param <V>
	     */
	    public static class MultiMap< T, V> implements Map, Cloneable
	    {
	        public static interface CollectionFactory<V>
	        {
	            Collection<V> makeNewEntry();
	        }

	        public static <V> CollectionFactory<V> HASH_SET()
	        {
	            return new CollectionFactory<V>()
                {
                    @Override
                    public Collection<V> makeNewEntry() {
                       return new HashSet<V>();
                    }
                };
	        }

	        public static <V> CollectionFactory<V> ARRAY_LIST()
            {
                return new CollectionFactory<V>()
                {
                    @Override
                    public Collection<V> makeNewEntry() {
                       return new ArrayList<V>();
                    }
                };
            }

	        Map<T,Collection<V>> data = null;
	        CollectionFactory<V> factory;

	        Class<? extends Collection<V>> collType;

	        public MultiMap()
	        {
	            this(MultiMap.<V>ARRAY_LIST());
	        }

	        public MultiMap(CollectionFactory<V> factory)
	        {
	            data = new HashMap<T,Collection<V>>();
	            this.factory = factory;
	        }
	        
	        public CollectionFactory<V> getFactory() {
	        	return factory;
	        }

            @Override
            public void clear()
            {
                data.clear();
            }

            @Override
            public boolean containsKey(Object key)
            {
                return data.containsKey(key);
            }

            @Override
            public boolean containsValue(Object value)
            {
                for (T key : data.keySet())
                {
                    if (data.get(key).contains(value))
                    {
                        return true;
                    }
                }
                return false;
            }

            @Override
            public Set<java.util.Map.Entry<T, Collection<V>>> entrySet()
            {
                return data.entrySet();
            }

            @Override
            public Collection<V> get(Object key)
            {
                return data.get(key);
            }

            @Override
            public boolean isEmpty()
            {
                return data.isEmpty();
            }

            @Override
            public Set<T> keySet()
            {
                return data.keySet();
            }

            @Override
            public Object put(Object key, Object value)
            {
                Collection<V> coll = data.get(key);
                if (coll == null)
                {
                    coll = factory.makeNewEntry();
                    data.put((T)key, coll);
                }
                coll.add((V)value);
                return null;
            }

            @Override
            public void putAll(Map m)
            {

            }

            @Override
            public Object remove(Object key)
            {
                return data.remove(key);
            }

            @Override
            public int size()
            {
                return data.size();
            }

            @Override
            public Collection<Collection<V>> values() {
                return null;
            }
            
            /**
             * shallow copy of all keys and values.
             */
            @Override
            public MultiMap<T,V> clone() 
            {
            	MultiMap<T,V> ret = new MultiMap<T,V>(getFactory());
            	for (T key : keySet())
            	{
            		for (V val : get(key)) 
            		{
            			ret.put( key, val );
            		}
            	}
            	return ret;
            }
            
            @Override
            public String toString()
            {
            	String ret = "";
            	for (T key : keySet())
            	{
            		ret += key + ":  ";
            		for (V val : get(key)) 
            		{
            			ret += val +", ";
            		}
            		ret += "\n";
            	}
            	return ret;
            }


	    }

		public static class Pair< T, U >
		{
			private final T first;
			private final U second;
			private transient final int hash;

			public Pair( T f, U s )
			{
				this.first = f;
				this.second = s;
				hash = ( first == null ? 0 : first.hashCode() * 31 )
						+ ( second == null ? 0 : second.hashCode() );
			}

			@Override
			public boolean equals( Object oth )
			{
				if( this == oth )
				{
					return true;
				}
				if( oth == null || !( getClass().isInstance( oth ) ) )
				{
					return false;
				}
				Pair< T, U > other = getClass().cast( oth );
				return ( first == null ? other.first == null : first
						.equals( other.first ) )
						&& ( second == null ? other.second == null : second
								.equals( other.second ) );
			}

			public T getFirst()
			{
				return first;
			}

			public U getSecond()
			{
				return second;
			}

			@Override
			public int hashCode()
			{
				return hash;
			}

		}

		public static class Primes
		{
			public static boolean [] primes = null;

			public static boolean [] prime_numbers( int lim )
			{
				if( primes != null )
					return primes;
				primes = new boolean[lim];
				for( int i = 0; i < lim; ++i )
					primes[i] = true;
				primes[0] = primes[1] = false;
				for( int k = 2; k < lim; ++k )
					if( primes[k] )
						for( int c = 2; c * k < lim; ++c )
							primes[c * k] = false;

				return primes;
			}

			public void testPrimes()
			{
				boolean [] p = prime_numbers( ( int ) 1e6 );
				for( int i = 0; i < 100; ++i )
					if( p[i] )
						System.out.println( i );
			}
		}

		public static class TrivialComporator< T > implements Comparator
		{
			@Override
            public int compare( Object a, Object b )
			{
				if( a instanceof Comparable && b instanceof Comparable )
					return ( ( Comparable ) a ).compareTo( b );
				throw new IllegalArgumentException(
						"passed arguments are not Comparable!" );
			}
		}
		
		public static int numberOfSetBits(int i)
		{
		     i = i - ((i >> 1) & 0x55555555);
		     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
		     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
		}

		/**
		 * Convert number in given base given as a string into base 10.
		 *
		 * @param numb
		 * @param base
		 * @return
		 */
		public static int convert( String numb, int base )
		{
			int ret = 0;
			int c = 0;
			for( int i = numb.length() - 1; i >= 0; --i )
			{
				ret += Math.pow( base, c ) * ( numb.charAt( i ) - 48 );
				++c;
			}
			return ret;
		}

		public static void main( String [] arg )
		{
			Integer [] a = { 0, 1, 2, 3 };
			reverseArray( a, 0, a.length );
			System.out.println( Arrays.toString( a ) );
		}

		public static boolean next_permutation( Comparable [] s )
		{
			int i = -1, j = 0;

			for( int x = s.length - 2; x >= 0; x-- )
				if( s[x].compareTo( s[x + 1] ) < 0 )
				{
					i = x;
					break;
				}

			if( -1 == i )
				return false;

			for( int x = s.length - 1; x > i; x-- )
				if( s[x].compareTo( s[i] ) > 0 )
				{
					j = x;
					break;
				}

			// Swapping elements pointed by i and j;
			swap( s, i, j );

			// Reversing elements after i

			reverseArray( s, i + 1, s.length - ( i + 1 ) );
			return true;
		}

		public static < T > boolean next_permutation( T [] s,
				Comparator< T > comp )
		{

			int i = -1, j = 0;

			for( int x = s.length - 2; x >= 0; x-- )
				if( comp.compare( s[x], s[x + 1] ) < 0 )
				{
					i = x;
					break;
				}

			if( -1 == i )
				return false;

			for( int x = s.length - 1; x > i; x-- )
				if( comp.compare( s[x], s[i] ) > 0 )
				{
					j = x;
					break;
				}

			// Swapping elements pointed by i and j;
			swap( s, i, j );

			// Reversing elements after i

			reverseArray( s, i + 1, s.length - ( i + 1 ) );
			return true;
		}

		public static < T > void reverseArray( T [] a, int start, int length )
		{
			int end = start + length - 1;
			while( start < end )
			{
				swap( a, start++, end-- );
			}
		}

		public static String Stream2String( InputStream is ) throws IOException
		{
			String ret = "";
			while( is.available() > 0 )
			{
				byte [] buff = new byte[is.available()];
				is.read( buff );
				String t = new String( buff );
				ret += t;
			}
			return ret;
		}

		public static < T > void swap( T [] a, int i, int k )
		{
			T t = a[i];
			a[i] = a[k];
			a[k] = t;
		}

	}

	public static void solveProblem( Problem prob, String input_file,
			String output_file ) throws Exception
	{
		boolean gcj_problem = true;

		PrintStream out;
		InputStream in;
		if( prob instanceof acm_problem )
		{
			in = System.in;
			out = System.out;
			gcj_problem = false;
		}
		else
		{
			in = new FileInputStream( input_file );
			if( !( prob instanceof facebook_problem ) )
			{
				FileOutputStream ofs = new FileOutputStream( output_file );
				out = new PrintStream( ofs );
			}
			else
			{
				out = System.out;
				gcj_problem = false;
			}
		}

		long start = System.currentTimeMillis();
		prob.solve( in, out );
		long end = System.currentTimeMillis();
		double duration = ( end - start ) / 1e3;

		if( gcj_problem )
			SO.println( "Problem was solved in " + duration
					+ " seconds." );
	}
	
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main( String [] args )
	{
		try
		{
			solveProblem(
					new GCJ_2014.Round1A.B(),
					"input.txt", "output.txt" );
		}
		catch( Exception e )
		{
			e.printStackTrace();
		}
	}
}