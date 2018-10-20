package codejam.yr2014;

import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;

/**
 * Created with IntelliJ IDEA.
 * User: ashwinjain
 * Date: 26/04/14
 * Time: 6:43 AM
 * To change this template use File | Settings | File Templates.
 */
public class ChargingChaos {
    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(
                new FileInputStream("/Users/ashwinjain/Downloads/codejam/p1.txt")));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
                new FileOutputStream("/Users/ashwinjain/Downloads/codejam/p1_out.txt")));
        int cases = Integer.parseInt(br.readLine());

        for(int xx=0;xx<cases;xx++){
            br.readLine();
            String s[] = br.readLine().split(" ");
            long a1[] = new long[s.length];
            for(int i=0;i<a1.length;i++)
                a1[i] = new BigInteger(s[i], 2).longValue();


            long a2[] = new long[s.length];
            s = br.readLine().split(" ");
            for(int i=0;i<a2.length;i++)
                a2[i] = new BigInteger(s[i], 2).longValue();

            int min = Integer.MAX_VALUE;
            for(long i=0;i<=(4096);i++){
                long newArr[] = new long[a1.length];
                for(int j=0;j<a1.length;j++)
                    newArr[j] = a1[j]^i;
                boolean x=chk(newArr, a2);
                if(x){
                    int t = calc1(i);
                    if(t<min){
                        min = t;
                    }
                }
            }

            if(min == Integer.MAX_VALUE){
                bw.write(String.format("Case #%d: NOT POSSIBLE\n", (xx + 1)));
                System.out.printf("Case #%d: NOT POSSIBLE\n", (xx + 1), min);
            }else{
                bw.write(String.format("Case #%d: %d\n", (xx + 1), min));
                System.out.printf("Case #%d: %d\n", (xx + 1), min);
            }
            bw.flush();
        }
        bw.close();
    }

    public static boolean chk(long a1[], long a2[]){
        Arrays.sort(a1);
        Arrays.sort(a2);
        for(int i=0;i<a1.length;i++){
//            System.out.print(a1[i] + " " + a2[i]);
            if(a1[i] != a2[i])
                return false;
        }
        return true;
    }

    public static int calc1(long x){
        int i =0;
        while(x>0){
            x=x&(x-1);
            i++;
        }
        return i;
    }
}
