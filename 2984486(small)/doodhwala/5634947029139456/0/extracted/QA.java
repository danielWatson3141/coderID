import java.util.*;
import java.io.*;

public class QA
{
    public static void main(String[] args) throws Exception
    {
        
        Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int n,l,total,flips;
        int ip[], op[], c[];
        String ans = null;
        int cases = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < cases; i++)
        {
            n = sc.nextInt();
            l = sc.nextInt();
            total = flips = 0;
            ip = new int[n];
            op = new int[n];
            c = new int[n];
            int min = l;
            for(int j = 0; j<n; j++)
                ip[j] = Integer.parseInt(sc.next(),2);
            
            for(int j = 0; j<n; j++)
                op[j] = Integer.parseInt(sc.next(),2);
            
            Arrays.sort(op);
            
            boolean never = true;
            int m = (1<<l) - 1;
            for(int j = 0; j<= m; j++)
            {
                for(int k = 0; k<n; k++)
                {
                    c[k] = j^ip[k];
                }
                Arrays.sort(c);
                boolean s = true;
                for(int k = 0; k<n; k++)
                {
                    if(c[k] != op[k])
                    {
                        s = false;
                        break;
                    }
                }
                if(s)
                {
                    never = false;
                    int x = Integer.bitCount(j);
                    min = x < min ? x : min;
                }
                
            }
            if(never) ans = "NOT POSSIBLE";
            else
            {
                ans = min+"";
            }
            pw.print("Case #" + (i + 1) + ": " + ans);
            pw.println();
            
        }
        
        pw.flush();
        pw.close();
        sc.close();
    }
}