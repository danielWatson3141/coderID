import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
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
		Task1 solver = new Task1();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task1 {
    /////////////////////////////////////////////////////////////
    public void solve(int testNumber, FastScanner in, FastPrinter out) {

            int T=in.nextInt();
            int cc=1;
            while(T-->0){
                System.out.println("Case #"+cc+": ");
                out.print("Case #"+cc+": ");
                cc++;
            int N=in.nextInt(),L=in.nextInt();
            String[] outlets= new String[N];
              String[] dev= new String[N];
                for (int i = 0; i < N; i++) {
                    outlets[i]=in.next();
                }
                for (int i = 0; i < N; i++) {
                    dev[i]=in.next();
                }
            int count=L+5;
            TreeSet<String> ts= new TreeSet<>();
                for (int i = 0; i < N; i++) {
                    ts.add(dev[i]);
                }
                for (int i = 0; i < N; i++) {     //otlet
                  boolean[] sw= new boolean[L];
                  int cct=0;
                    for (int j = 0; j < L; j++) {
                        if(dev[0].charAt(j)!=outlets[i].charAt(j)){sw[j]=true;
                        cct++;
                        }
                    }
                    int chk=1;
                    for (int j = 0; j < N; j++) {
                        StringBuilder sb= new StringBuilder();
                        for (int k = 0; k < L; k++) {
                            char c=outlets[j].charAt(k);
                          if(sw[k]){
                            if(c=='0')sb.append('1');
                              else sb.append('0');
                          }   else
                              sb.append(c);
                        }
                        if(!ts.contains(sb.toString())) {
                            chk=0;
                            break;
                        }
                    }

                   if(chk==1)count=Math.min(count,cct);

                }

               if(count>L){
                   out.println("NOT POSSIBLE");
               }
                else out.println(count);


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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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

