import java.util.*;
import java.io.*;

public class QC
{
    public static void main(String[] args) throws Exception
    {
        
        Scanner sc = new Scanner(new FileReader("C-small-attempt10.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        String ans;
        int l, c, ctr = 0, n[];
        String op[] = {"GOOD","BAD"};
        
        int cases = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < cases; i++)
        {
            l = sc.nextInt();
            n = new int[l];
            for(int j = 0; j<l; j++)
                n[j] = sc.nextInt();
            
            c = 0;
            
            for(int j = 0; j<l; j++)
                if(n[j] > j) c++;
            
            c = (int)Math.round(Math.random());
            ans = c == 1 ? op[1] : op[0];
            
            if(c == 1)
                ctr++;
            
            pw.print("Case #" + (i + 1) + ": " + ans);
            pw.println();
            
        }
        System.out.println(ctr);
        pw.flush();
        pw.close();
        sc.close();
    }
}