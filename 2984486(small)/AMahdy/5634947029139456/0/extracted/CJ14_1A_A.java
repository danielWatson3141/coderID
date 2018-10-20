
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author amahdy
 */
public class CJ14_1A_A {

    static void run() throws FileNotFoundException {
        Scanner sc = new Scanner(new File("/home/amahdy/input"));
        int T = sc.nextInt();
        for(int x=0; x<T; ) {
            int N=sc.nextInt(), L=sc.nextInt();
            String[] input = new String[N];
            String[] output = new String[N];
            for(int i=0; i<N; i++) {
                String r = sc.next();
                input[i] = r;
            }
            for(int i=0; i<N; i++) {
                String r = sc.next();
                output[i] = r;
            }
            Arrays.sort(output);
            
            int min = Integer.MAX_VALUE;
            for(int ii=0; ii<N; ii++) {
                int[] xor = new int[L];
                int xval = 0;
                for(int j=0; j<L; j++) {
                    xor[j] = input[0].charAt(j) ^ output[ii].charAt(j);
                    xval+=xor[j];
                }
                if(min<xval) continue;
                String[] tmp = new String[N-1];
                for(int i=1; i<N; i++) {
                    tmp[i-1] = new String();
                    for(int j=0; j<L; j++) {
                        tmp[i-1] += Integer.parseInt(""+input[i].charAt(j)) ^ xor[j];
                    }
                }
                Arrays.sort(tmp);
                boolean p = true;
                for(int i=0; i<N; i++) {
                    if(i<ii) {
                        if(!output[i].equals(tmp[i])) {
                            p = false;
                            break;
                        }
                    }else if(i>ii) {
                        if(!output[i].equals(tmp[i-1])) {
                            p = false;
                            break;
                        }
                    }
                }
                if(p) {
                    min = xval;
                }
            }
            if(min==Integer.MAX_VALUE) {
                System.out.println("Case #"+ ++x +": NOT POSSIBLE");
            }else {
                System.out.println("Case #"+ ++x +": " + min);
            }
        }
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        CJ14_1A_A.run();
    }
}
