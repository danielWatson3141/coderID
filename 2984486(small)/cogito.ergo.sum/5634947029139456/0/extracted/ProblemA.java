
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;


public class ProblemA {

    static int switches = Integer.MAX_VALUE; 
    static HashSet<String> hs = null;
    static int N = 0; 
    static int L = 0; 
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader("/Users/hadoop/codejam/A-small-attempt3.in.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("/Users/hadoop/codejam/problemA3.txt"));
        
        int T = sc.nextInt();
        for(int cs = 1; cs <= T; cs++)
        {
            pw.printf("Case #%d: ", cs);
            System.out.printf("Case #%d: ", cs);
            solver(sc, pw);
        }
        
        pw.flush();
        pw.close();
        sc.close();
    }
    
    private static void solver(Scanner sc, PrintWriter pw)
    {
        N = sc.nextInt(); 
        L = sc.nextInt();
        ArrayList<String> from = new ArrayList<String>();
        ArrayList<String> to = new ArrayList<String>(); 
        switches = Integer.MAX_VALUE;
        for(int i = 0; i < N ; i++)
            from.add(sc.next());
        
        for(int i = 0; i < N; i++)
            to.add(sc.next());
        Collections.sort(to);
        
        
        
        //match 1 to each in matcher and set bits
        for(String matcher : to)
        {
            boolean[] flipbits = new boolean[L];
            int flips = 0; 
            for(int i = 0; i < L; i++)
            {
                if(matcher.charAt(i) != from.get(0).charAt(i))
                {
                    flipbits[i] = true;
                    flips++;
                }
            }
                
            if(setncheck(flipbits, from, to))
                switches = Math.min(switches, flips);
        }
        
        if(switches == Integer.MAX_VALUE)
        {
            pw.printf("%s%n","NOT POSSIBLE");
            System.out.printf("%s%n", "NOT POSSIBLE");
        }
        else
        {
            pw.printf("%d%n",switches);
            System.out.printf("%d%n", switches);
        }
        
    }
    
    private static boolean setncheck(boolean[] bits, ArrayList<String> from, ArrayList<String> to)
    {
        ArrayList<String> newArr = new ArrayList<String>();
        
        for(String str: from)
        {
            char[] chrarr = str.toCharArray();
            for(int i = 0; i < L; i++)
            {
                if(bits[i])
                chrarr[i] = (chrarr[i] == '0')? '1':'0';
            }
            newArr.add(String.valueOf(chrarr));
        }
        
        Collections.sort(newArr);
        for(int i= 0; i < N; i++)
            if(!newArr.get(i).equals(to.get(i)))
                return false ;
        
        return true; 
        
    }
    
    
}
