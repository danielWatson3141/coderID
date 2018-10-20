package coding;


import java.io.*;

import java.math.BigInteger;
import java.util.*;

/**
* Built using CHelper plug-in
* Actual solution is at the top
* @author Nipuna Samarasekara
*/
public class Tests {
    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        String name= "/Users/Nipuna_Sam/Downloads/C-small-attempt4.in";
        FastScanner in = new FastScanner(new FileInputStream(new File(name)));
        FastPrinter out = new FastPrinter(new FileWriter(new File("output.txt")));
       // FastPrinter out = new FastPrinter(outputStream);

        HH solver = new HH();
            solver.solve(1, in, out);
            out.flush();
            out.close();
    }
}

class HH {
    public static void deb(int[] A){

        for (Object oo : A) {
            System.out.print(oo+" ");
        }
        System.out.println("");
    }

    /////////////////////////////////////////////////////////////
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int T=in.nextInt();
        int t=T;
        int cc=1;
//        double norm=0;
//        for (int i = 1; i <=1000 ; i++) {
//             norm-=Math.log10((double)i);
//        }
//        System.out.println(norm);

        pp[] A= new pp[T];
        int[] ans= new int[T];
        for (int i = 0; i < T; i++) {
            A[i]= new pp(0,i);
        }
        for (int z = 0; z < t; z++){
            int N=in.nextInt();

            int[] aa= in.readIntArray(N);
           // deb(aa);
            System.out.println("________");
            //   boolean[] found= new boolean[N];
            for (int i = 0; i < N; i++) {
//               found[aa[i]]=true;
//               int ss=0;
//               for (int j = 0; j <=i; j++) {
//                   if(found[j])ss++;
//               }
//             A[z].score+=ss;
                for (int j = 0; j < i; j++) {
                    if(aa[i]>aa[j])A[z].score++;
                }

            }

           long sc=0;
            for (int g = 0; g < N; g++) {


                sc+=Math.abs(g-aa[g]);

            }
         A[z].score=(int)sc;


        }
        Arrays.sort(A,new Comparator<pp>() {
            @Override
            public int compare(pp o1, pp o2) {
                return o1.score-o2.score;  //To change body of implemented methods use File | Settings | File Templates.
            }
        });
        for (int i = 0; i < t/2; i++) {
            ans[A[i].pos]=1;
        }
        for (int i = 0; i < t; i++) {
            System.out.println(A[i].score);
        }

        for (int i = 0; i < t; i++) {
            System.out.println("Case #"+cc+": ");
            out.print("Case #"+cc+": ");
            cc++;









            if(ans[i]==0)
                out.println("GOOD");
            else
                out.println("BAD");

        }


    }
    class pp{
        int score=0;
        int pos=1;

        pp(int score, int pos) {
            this.score = score;
            this.pos = pos;
        }
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

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
        }
        return ret;
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
