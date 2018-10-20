
package codejam2014;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class R1AProblemA 
{
    public static void flip(String [] a, int fIdx){
        for(int i = 0; i < a.length; i++){
            if(a[i].charAt(fIdx) == '1')
                a[i] = a[i].substring(0,fIdx)+'0'+ a[i].substring(fIdx+1);
            else
                a[i] = a[i].substring(0,fIdx)+'1'+ a[i].substring(fIdx+1);
        }
    }
    public static boolean test(String [] outlets, String [] devices, int N, int L, boolean [] matched, int nMatched)
    {
        if(nMatched == N)
            return true;
        
        for(int j = 0; j < N; j++){
            if(!matched[j] && devices[nMatched].equals(outlets[j])){
                matched[j] = true;
                if(test(outlets, devices, N, L, matched, nMatched + 1))
                    return true;
                matched[j] = false;
            }
        }
        return false;
    }
    
    public static boolean goo(String [] outlets, String [] devices, int N, int L, ArrayList<Integer> pFlips, int iFlip, int flipsLeft)
    {
        if(flipsLeft == 0){
            boolean [] matched = new boolean [N];
            for(int i = 0; i < N; i++)
                matched[i] = false;
            return test(outlets, devices, N, L, matched, 0);
        }
        if(iFlip >= pFlips.size())
            return false;
        else{
            for(int i = iFlip; i < pFlips.size(); i++){
                flip(devices, pFlips.get(i));
                if(goo(outlets, devices, N, L, pFlips, i+1, flipsLeft-1))
                    return true;
                flip(devices, pFlips.get(i));
            }
        }
        return false;
    }
    
    public static int solve(String [] outlets, String [] devices, int N, int L)
    {
        int flips = 0;
        ArrayList<Integer> pFlip = new ArrayList();
        
        //bits to flip
        for(int i = 0; i < L; i++)
        {
            int outlet_zeros = 0;
            int device_zeros = 0;
            for(int j = 0; j < N; j++){
                if(outlets[j].charAt(i) == '0')
                    outlet_zeros++;
                
                if(devices[j].charAt(i) == '0')
                    device_zeros++;
            }
            if(outlet_zeros == N-device_zeros && outlet_zeros != N-outlet_zeros){
                flip(devices, i); flips++;
            }
            if(outlet_zeros == device_zeros && outlet_zeros == N-outlet_zeros){
                pFlip.add(i);
            }
            if(outlet_zeros != device_zeros && outlet_zeros != N - device_zeros){
                return -1;
            }
            //assert(outlet_zero == device_zero && outlet_zero != outlet_one);
        }
        
        for(int nFlips = 0; nFlips <= pFlip.size(); nFlips++){
            if(goo(outlets, devices, N, L, pFlip, 0, nFlips))
                return flips + nFlips;
        }
        return -1;
    }
    
    public static void go() throws Exception
    {
        try(Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
            PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out")))
        {
            int T = sc.nextInt();
            for(int t = 1; t <= T; t++)
            {
                int N = sc.nextInt();
                int L = sc.nextInt();
                
                String [] outlets = new String [N];
                for(int i = 0; i < N; i++)
                    outlets[i] = sc.next();
                String [] devices = new String [N];
                for(int i = 0; i < N; i++)
                    devices[i] = sc.next();
                
                int x = solve(outlets, devices, N, L);
                if(x < 0)
                {
                    pw.println("Case #" + t + ": NOT POSSIBLE");
                }
                else{
                    pw.println("Case #" + t + ": " + x);
                }
            }
        }
    }
}
