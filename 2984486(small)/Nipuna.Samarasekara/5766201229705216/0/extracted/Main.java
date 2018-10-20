import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Nipuna Samarasekara
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		Task2 solver = new Task2();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task2 {
    /////////////////////////////////////////////////////////////
  static int nn;
  static int[][] edges;
    static int[] nct;
   public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int T=in.nextInt();
        int cc=1;
        while(T-->0){
            System.out.println("Case #"+cc+": ");
            out.print("Case #"+cc+": ");
            cc++;

            nn=in.nextInt();
           int[] from= new int[nn-1];
            int[] to= new int[nn-1];
            nct= new int[nn+1];
            for (int i = 0; i < nn - 1; i++) {
                from[i]=in.nextInt();
                to[i]=in.nextInt();
            }
           edges= GraphUtils.getEdgesUndirectedUnweighted(nn+1,from,to);
          int ans=nn;
            for (int root = 1; root <=nn ; root++) {
             int ct= getct(-1,root);
              ans=Math.min(ct,ans);
            }

            out.println(ans);

        }


    }

    static int getct(int par, int node){
      int ans=0,nodect=0;
     //   System.out.println(par+"xxx "+node);
      //  deb(edges[node]);
        int[] counts= new int[edges[node].length-1];
        int[] nncounts= new int[edges[node].length-1];

        if(par==-1){counts= new int[edges[node].length];
                nncounts= new int[edges[node].length];
        }
        int xx=0;
        for (int nn : edges[node]) {
          //  System.out.println(nn+" nnn "+node);
           if(nn==par)continue;

            counts[xx]=getct(node,nn);
            nodect+=nct[nn];
            nncounts[xx]=nct[nn];
            xx++;
        }
       // Arrays.sort(counts);

        if(counts.length>2){

           int nnsum=0,csum=0;
            for (int i = 0; i < counts.length; i++) {
              nnsum+=nncounts[i];
              counts[i]=nncounts[i]-counts[i];
            }
            ans=nnsum;
         Arrays.sort(counts);
            ans-=counts[counts.length-1];
            ans-=counts[counts.length-2];

        }
        else if(counts.length==2){
            ans+=counts[0]+counts[1];

        }
        else if(counts.length==1){

            ans=nncounts[0];

        }
      //  System.out.println(ans+" sol "+node);


      nct[node]=nodect+1;
      return ans;
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

class GraphUtils {
    public static int[][] getEdgesUndirectedUnweighted(int n, int[] v, int[] u) {
        int[][] edges = new int[n][];
        int[] deg = getDegreeUndirected(n, v, u);
        for (int i = 0; i < n; i++) {
            edges[i] = new int[deg[i]];
        }
        int m = v.length;
        Arrays.fill(deg, 0);
        for (int i = 0; i < m; i++) {
            edges[v[i]][deg[v[i]]++] = u[i];
            edges[u[i]][deg[u[i]]++] = v[i];
        }
        return edges;
    }

    public static int[] getDegreeUndirected(int n, int[] v, int[] u) {
        int[] deg = new int[n];
        for (int i : v) {
            deg[i]++;
        }
        for (int i : u) {
            deg[i]++;
        }
        return deg;
    }


}

