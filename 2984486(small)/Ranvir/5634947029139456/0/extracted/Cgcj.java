/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cgcj;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.util.*;
/**
 *
 * @author mac
 */
public class Cgcj {
int t;
int N;
int L;
long charges[];
long devices[];
long dist [][];
public void readInput(File file)
    {
        try {
        BufferedReader br = new BufferedReader(new FileReader(file));
String line;
line =br.readLine();
t = Integer.parseInt(line);
for (int i=1;i<=t;i++){
line = br.readLine();
String [] splitted = line.split("\\s+");
N=Integer.parseInt(splitted[0]);
L=Integer.parseInt(splitted[1]);
charges = new long[N];
devices = new long[N];
dist = new long[N][N];
line=br.readLine();
splitted = line.split("\\s+");
for (int j=0;j<N;j++)
{
    charges[j]=Integer.parseInt(splitted[j],2);
}
line=br.readLine();
splitted = line.split("\\s+");
for (int j=0;j<N;j++)
{
    devices[j]=Integer.parseInt(splitted[j],2);
}

solve(i);


}
br.close();
        } catch(Exception e){}
    }
public void solve(int i)
        
{
    //Arrays.sort(charges);
    //Arrays.sort(devices);
    for (int p=0;p<N;p++)
    {
        for (int q=0;q<N;q++)
        {
            dist[p][q]=charges[p] ^ devices[q];
        }
    }
    
    Arrays.sort(dist[0]);
   // System.err.println(Arrays.toString(dist[0]));
    
   boolean flag=false;
    int q;
        for ( q=0;q<N;q++)
        {
         for (int r=0;r<N;r++)
         {
             //System.err.print(dist[0][q]);
             //System.err.println(Arrays.toString(dist[r]));
             
           if (!foundInArray(dist[r],N,dist[0][q]))
           {
               flag=true;
               r=N;
               break;
           }
            
        }
         if (!(flag))
         {
            // System.err.println("found");
             System.out.println(String.format("Case #%d: %d",i,Long.bitCount(dist[0][q])));
             break;
         }
         flag=false;    
             
    }
    if (q==N)
    {
       System.out.println(String.format("Case #%d: %s",i,"NOT POSSIBLE")); 
    }
    }
public boolean foundInArray(long x[],int n,long no)
{
    boolean flag=false;
    for (int k=0;k<n;k++)
    {
       if (x[k]==no) {
           flag=true;
           break;
       } 
    }
    return flag;
}

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String infile ="A-small-attempt2.in";
        File file = new File("src/"+infile);
        PrintStream out;
        try {
         out = new PrintStream(new FileOutputStream("src/"+infile+".out.txt"));
System.setOut(out);
        } catch (Exception e){}
        Cgcj gcj = new Cgcj();
        gcj.readInput(file);
    }

}
