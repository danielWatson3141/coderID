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


public class MainH {


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

        FastScanner ( BufferedReader _br ){
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
        new MainH().run();
    }

    ////////////////////////////////////////////////////////////////

    int n;
    ArrayList<Integer>[] gr;

    int dfs( int v, int p ){
        ArrayList<Integer> val = new ArrayList<>();
        for( int to : gr[v] ){
            if( to == p ) continue;
            val.add( dfs( to, v ) );
        }
        Collections.sort( val );
        int ans = 1;
        if( 2 <= val.size() ){
            ans += val.get( val.size()-1 );
            ans += val.get( val.size()-2 );
        }
        return ans;
    }

    void solveTest(){
        n = sc.nextInt();
        gr = new ArrayList[n+1];
        for( int i = 1; i <= n; ++i )
            gr[i] = new ArrayList<>();
        for( int i = 0; i < n-1; ++i ){
            int a = sc.nextInt();
            int b = sc.nextInt();
            gr[a].add(b);
            gr[b].add(a);
        }

        int ans = 0;
        for( int r = 1; r <= n; ++r ){
            int cur = dfs(r,-1);
            ans = max( ans, cur );
            System.err.println( cur );
        }
        out.println( n - ans );
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