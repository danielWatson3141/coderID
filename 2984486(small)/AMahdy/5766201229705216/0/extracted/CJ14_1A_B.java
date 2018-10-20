
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author amahdy
 */

class T {
    public ArrayList<T> c = new ArrayList<T>();
}

public class CJ14_1A_B {

    static void run() throws FileNotFoundException {
        Scanner sc = new Scanner(new File("/home/amahdy/input"));
        int T = sc.nextInt();
        for(int x=0; x<T; ) {
            
            int min=Integer.MAX_VALUE;
            
            int N=sc.nextInt();
            T[] t =  new T[N];
            for(int i=0; i<N; i++) {
                t[i] = new T();
            }
            for(int i=1; i<N; i++) {
                int X=sc.nextInt()-1,Y=sc.nextInt()-1;
                t[X].c.add(t[Y]);
                t[Y].c.add(t[X]);
            }
            for(int i=0; i<N; i++) {
                int c = N - count(t[i], null);
                if(c<min) {
                    min=c;
                }
            }
            System.out.println("Case #"+ ++x +": " + min);
        }
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        CJ14_1A_B.run();
    }

    private static int count(T t, T x) {
        int[] C = new int[2];
        C[0]=0; C[1]=0;
        for(int i=0; i<t.c.size(); i++) {
            if(t.c.get(i).equals(x)) {
                continue;
            }
            int tmp=0;
            if(t.c.get(i).c.size()>=3) {
                tmp=count(t.c.get(i), t);
            }else if(t.c.get(i).c.size()==1 || t.c.get(i).c.size()==2) {
                tmp=1;
            }
            if(C[0]<tmp) {
                if(C[0]<C[1])
                    C[0]=tmp;
                else
                    C[1]=tmp;
            }else if(C[1]<tmp) {
                C[1]=tmp;
            }
        }
        if(C[0]>0 && C[1]>0) {
            return C[0]+C[1]+1;
        }else {
            return 0;
        }
        
    }
}
