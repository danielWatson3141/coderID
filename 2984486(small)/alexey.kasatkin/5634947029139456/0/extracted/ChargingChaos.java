package ak.tournaments.google.code_jam2014.round1a;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URISyntaxException;
import java.util.Arrays;

public class ChargingChaos {

    
    
    static long solve(String[] s, String[] d) {
        int N=s.length, L=s[0].length();
        
        int[] si=new int[N], di=new int[N];
        for (int i=0; i<N; i++) {
            si[i]=Integer.parseInt(s[i], 2);
            di[i]=Integer.parseInt(d[i], 2);
        }
        Arrays.sort(di);
        int ret=Integer.MAX_VALUE;
        for (int set=0; set<(1<<L)-1; set++) {
            for (int j=0; j<N; j++) {
                si[j]^=set;
            }
            Arrays.sort(si);
            if(Arrays.equals(si, di)) {
                int k=set, bcnt=0;
                while(k>0) {
                    if((k&1)>0) {
                        bcnt++;
                    }
                    k=k>>1;
                }
                if(ret>bcnt) {
                    ret=bcnt;
                }
            }
            
            for (int j=0; j<N; j++) {
                si[j]^=set;
            }
        }
        
        return ret;
    }

    
    
    
    
    static StringBuilder sb=new StringBuilder();
    
    static void run_stream(InputStream ins) throws IOException, URISyntaxException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        
        int T=Integer.parseInt(br.readLine());
        
        for (int i=0; i<T; i++) {
            String[] NL=br.readLine().split(" ");
            int N=Integer.parseInt(NL[0]);
            int L=Integer.parseInt(NL[1]);
            
            String[] s=new String[N], d=new String[N];
            String l=br.readLine();
            for (int j=0; j<N; j++) {
                s[j]=l.substring(0, L); 
                if(j+1<N) {
                    l=l.substring(L+1);
                }
            }
            l=br.readLine();
            for (int j=0; j<N; j++) {
                d[j]=l.substring(0, L); 
                if(j+1<N) {
                    l=l.substring(L+1);
                }
            }

            long ret=solve(s, d);
            if(ret>L) {
                System.out.println("Case #"+(i+1)+": NOT POSSIBLE");
            } else {
                System.out.println("Case #"+(i+1)+": "+ret);
            }
        }
        
    }

    public static void main(String[] args) throws IOException, URISyntaxException {
        run_stream(System.in);
    }
}
