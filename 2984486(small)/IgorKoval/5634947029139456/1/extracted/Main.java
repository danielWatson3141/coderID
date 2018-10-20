import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
import java.util.Calendar.*;
import static java.lang.Math.*;
import static java.lang.Math.min;
import static java.util.Arrays.*;
import static java.math.BigInteger.*;

import java.util.jar.*;

public class Main{

    public class SpamChecker{

    }

    void run(){
        boolean oj = System.getProperty("ONLINE_JUDGE") != null;
//        boolean oj = true;
        Locale.setDefault(Locale.US);
        try{
            err = new PrintWriter(new OutputStreamWriter(System.err));
            try{
                sc  = new FastScanner(new BufferedReader(new FileReader("input.txt" )));
                out = new PrintWriter   (new FileWriter("output.txt"));
                oj = false;
            }
            catch ( Exception e ){
                sc = new FastScanner(new BufferedReader(new InputStreamReader(System.in)));
                out = new PrintWriter(new OutputStreamWriter(System.out));
                oj = true;
            }
        }catch(Exception e){
            MLE();
        }
        tBeg = System.currentTimeMillis();
        solve();
        if( !oj )
            err.println( "TIME: " + (System.currentTimeMillis() - tBeg ) / 1e3 );
        exit(0);
    }

    void exit( int val ){
        err.flush();
        out.flush();
        System.exit(val);
    }

    double tBeg;
    FastScanner sc;
    PrintWriter err, out;

    class FastScanner{

        StringTokenizer st;
        BufferedReader br;

        FastScanner( BufferedReader _br ){
            br = _br;
        }

        String readLine(){
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        String next(){
            while( st==null || !st.hasMoreElements() )
                st = new StringTokenizer(readLine());
            return st.nextToken();
        }

        int nextInt(){ return Integer.parseInt(next()); }
        long nextLong(){ return Long.parseLong(next()); }
        double nextDouble(){ return Double.parseDouble(next()); }
    }

    void MLE(){
        int[][] arr = new int[1024*1024][]; for( int i = 0; i < 1024*1024; ++i ) arr[i] = new int[1024*1024];
    }

    void TLE(){
        for(;;);
    }

    public static void main(String[] args) {
        new Main().run();
    }

    ////////////////////////////////////////////////////////////////

    int n, l;
    boolean[][] a;
    boolean[][] b;
    boolean[] doF;
    long[] pow;{
        pow = new long[100_000];
        pow[0] = 1;
        for( int i = 1; i < pow.length; ++i )
            pow[i] = 2011 * pow[i-1];
    }

    long getH( boolean[] a ){
        long h = 0;
        for( int i = 0; i < a.length; ++i ){
            if( a[i] )
                h += pow[i];
        }
        return h;
    }

    boolean getAns(){
        Long[] aa = new Long[n];
        Long[] bb = new Long[n];
        int cnt;

        cnt = 0;
        for( boolean[] ai : a )
            aa[cnt++] = getH(ai);

        cnt = 0;
        boolean[] s = new boolean[l];
        for( boolean[] bi : b ){
            for( int i = 0; i < bi.length; ++i )
                s[i] = ( bi[i] ^ doF[i] );
            bb[cnt++] = getH(s);
        }

        sort(aa);
        sort(bb);
        for( int i = 0; i < n; ++i ){
            long aaa = aa[i];
            long bbb = bb[i];
            if( aaa != bbb )
                return false;
        }

        return true;
    }

    boolean[] f(){
        char[] s = sc.next().toCharArray();
        boolean[] rez = new boolean[s.length];
        for( int i = 0; i < s.length; ++i ){
            if     ( s[i] == '0' ) rez[i] = false;
            else if( s[i] == '1' ) rez[i] = true;
            else MLE();
        }
        return rez;
    }

    void solveTest(){
        n = sc.nextInt();
        l = sc.nextInt();
        a = new boolean[n][];
        b = new boolean[n][];
        for( int i = 0; i  < n; ++i ) a[i] = f();
        for( int i = 0; i  < n; ++i ) b[i] = f();

        int ans = Integer.MAX_VALUE;
        for( int i = 0; i < n; ++i ){
        for( int j = 0; j < n; ++j ){
            boolean f = false;
            int cnt = 0;
            doF = new boolean[l];
            for( int pos = 0; pos < l; ++pos ){
                if( a[i][pos] != (b[j][pos] ^ f) ){
                    doF[pos] = true;
                    f ^= true;
                    ++cnt;
                }
            }
            for( int pos = 1; pos < l; ++pos )
                doF[pos] ^= doF[pos-1];
            if( getAns() )
                ans = min( ans, cnt );
        }
        }
        if( ans == Integer.MAX_VALUE )
            out.println( "NOT POSSIBLE" );
        else
            out.println( ans );
    }

    void solve(){
        int t = sc.nextInt();
        for( int i = 0; i < t; ++i ){
            out.printf( "Case #%d: ", i + 1 );
            System.err.printf( "Case #%d: \n", i + 1 );
            solveTest();
        }
    }
}