import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author securuskeeper - Kevin Wong
 */
public class Chaos {
    
    
    // To store inputs    

    public static void main(String[] args) {
        String base="./";
        String input=base + "A-small-attempt2.in";
        String output=base + "A-small-attempt2.out";
        
        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);
            
            int n = sc.nextInt();
            sc.nextLine();
            for (int c=0; c<n; c++) {
                System.out.println("Test case " + (c+1) + "...");
                pw.print("Case #" + (c+1) + ": ");                
                test(sc, pw);
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Chaos.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }

    private static void test(Scanner sc, PrintWriter pw) {

        int n = sc.nextInt();
        int l = sc.nextInt();

        String s1[]=new String[n];
        String s2[]=new String[n];
        
        int ss[][]=new int[2][l];

        for(int i=0;i<n;i++)
        {            
            s1[i]=sc.next();
            for(int j=0;j<l;j++)
            	ss[0][j]+=(s1[i].charAt(j)=='0')?0:1;
        }
        for(int i=0;i<n;i++)
        {
            s2[i]=sc.next();
            for(int j=0;j<l;j++)
            	ss[1][j]+=(s2[i].charAt(j)=='0')?0:1;
        }

/*
 *         for(int i=0;i<l;i++)

        	System.out.print(ss[0][i]+",");
    	System.out.print("\n");
        for(int i=0;i<l;i++)
        	System.out.print(ss[1][i]+",");
    	System.out.print("\n");
*/
    	int c1=0;
    	int c2=0;
    	boolean sw[]=new boolean[l];
        for(int i=0;i<l;i++)
        {
        	if(ss[0][i]==ss[1][i])
        		c1++;
        	else if(ss[0][i]==(n-ss[1][i]))
        	{
        		c2++;
        		sw[i]=true;
        	}
        	else 
        	{
        		pw.println("NOT POSSIBLE");
        		return;
        	}        			
        }

        for(int i=0;i<n;i++)
        {
        	String ss1="";
        	String ss2="";
            for(int j=0;j<l;j++)
            if(!sw[j])
            {
            	ss1+=s1[i].charAt(j);
            	ss2+=s2[i].charAt(j);
            }
            s1[i]=ss1;
            s2[i]=ss2;
        }
        Arrays.sort(s1);
        Arrays.sort(s2);
        

        for(int i=0;i<n;i++)
        {
        	if(!s1[i].equals(s2[i]))
        	{
        		pw.println("NOT POSSIBLE");
        		return;
        	}        			
        }
                
        pw.println(c2);
        
    }
}