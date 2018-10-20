import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Stack;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author securuskeeper - Kevin Wong
 */
public class Tree {
    
    
    // To store inputs    
    private static int[]o  = null;
    private static int[][]g  = null;

    public static void main(String[] args) {
        String base="./";
        String input=base + "B-small-attempt2.in";
        String output=base + "B-small-attempt2.out";
        
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
            Logger.getLogger(Tree.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }

    public static int maxtr(int x,int d,int n,boolean[] p)
    {
    	int m=0,m2=0,c=0;
    	for(int i=0;i<n;i++)
    	{
    		if(p[i]||g[x][i]==0)continue;
        	for(int j=i+1;j<n;j++)
        	{
        		if(p[j]||g[x][j]==0)continue;
        		
    			boolean[] p2=new boolean[n];
    			for(int k=0;k<n;k++)p2[k]=p[k];
    			p2[i]=true;
    			p2[j]=true;
    			m2=maxtr(i,d,n,p2)+maxtr(j,d,n,p2);        		
        		if(m2>m)m=m2;
        	}
    	}
    	
    	return d+m;
    }
    
    private static void test(Scanner sc, PrintWriter pw) {

    	int r=0;
        int n = sc.nextInt();
        o  = new int[n];
        g  = new int[n][n];
        
        for(int i=0;i<n-1;i++)
        {
            int a = sc.nextInt()-1;
            int b = sc.nextInt()-1;
        	o[a]++;
        	o[b]++;
        	g[a][b]=1;
        	g[b][a]=1;
        }
        	
/*         for(int i=0;i<n;i++)
 
        	System.out.print(o[i]+",");
    	System.out.println();
        for(int i=0;i<n;i++)
       {
            for(int j=0;j<n;j++)
            	System.out.print(g[i][j]+",");
            System.out.println();            
       }	
*/        
       int m=0,d=0;       
       for(int rt=0;rt<n;rt++)
       {
           boolean []p=new boolean[n];
           p[rt]=true;
           d=maxtr(rt,1,n,p);
           if(d>m)m=d;
       }
       System.out.println(n-m);
       pw.println(n-m);
        
    }
}