import java.io.*;
import java.util.*;
import static java.lang.System.*;
public class A {
    final int INF =100000;
    int N,L;
	public static void main (String [] args) throws Exception {new A().run();}
    String[] ele, dev;
    public int recur(String[] ar, int cur){
        if( cur == L){
            Arrays.sort(ar);
            if( Arrays.equals(ar, dev)) return 0;
            return INF;
        }
        String[] sr1 = new String[N], sr2 = new String[N];
        int[][] ct = new int[2][2];
        for(int i = 0; i<N; i++){
            sr1[i] = ar[i] + ele[i].charAt(cur);
            sr2[i] = ar[i] + (ele[i].charAt(cur)=='0'?'1':'0');
            ct[0][ele[i].charAt(cur)-'0']++;
            ct[1][dev[i].charAt(cur)-'0']++;
        }
        int min = INF;
        cur++;
        if( ct[0][0] == ct[1][0] ){
            min = Math.min(min, recur(sr1, cur));
        }
        if( ct[0][1] == ct[1][0]){
            min = Math.min(min, 1+recur(sr2, cur));
        }
        return min;
    }
	public void run() throws Exception{
		Scanner file = new Scanner(new File("A-small-attempt1.in.txt"));
		int T = file.nextInt();
        for(int asdf = 0; asdf<T; asdf++){
            out.printf("Case #%d: ",asdf+1);
            N = file.nextInt();
            L = file.nextInt();
            ele = new String[N];
            dev = new String[N];
            for(int i = 0; i<N; i++)
                ele[i] = file.next();
            for(int i = 0; i<N; i++)
                dev[i] = file.next();
            Arrays.sort(dev);
            String[] ar = new String[N];
            Arrays.fill(ar, "");
            int x = recur(ar,0);
            if( x >= INF)
                out.println("NOT POSSIBLE");
            else out.println(x);
		}
	}
}