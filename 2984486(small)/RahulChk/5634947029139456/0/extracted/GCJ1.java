import java.io.*;
import java.util.*;
import java.lang.Math.*;
public class GCJ1
{
    public static void main(String args[])throws Exception
    {
        //Scanner in=new Scanner(System.in);
        //BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       // PrintWriter pw = new PrintWriter(System.out);
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\rahul\\Desktop\\GCJ1.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\rahul\\Desktop\\GCJ1out")));
         
        StringTokenizer st;
        // new StringTokenizer();
        // Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(br.readLine());
        int ctr = 0;
        while(t>0)
        {
            t--;
            ctr++;
            int i,j,k,flips = 100;
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());

            
            st = new StringTokenizer(br.readLine());
            int a[]=new int[n];
            for(i=0;i<n;i++)
            {
                a[i]=Integer.parseInt(st.nextToken(),2);
            }
            int b[]=new int[n];
            st = new StringTokenizer(br.readLine());
            for(i=0;i<n;i++)
            {
                b[i]=Integer.parseInt(st.nextToken(),2);
            }
            Arrays.sort(a);
            Arrays.sort(b);
            
            int c[]=new int[n];
            
            boolean status = false;
            for(i=0;i<n;i++)
            {
               int xor = a[i]^b[0];
               
               for(j=0;j<n;j++)
               {
                   c[j] = a[j] ^ xor;
               }
               
               Arrays.sort(c);
               
               
              /* pw.println("case"+ctr+"iteration"+(i+1));
               
               for(i=0;i<n;i++)
               {
                   pw.println(a[i] + "   " + b[i] + "     " + c[i]);
               }
               
               */
               
               
               status = true;
               
               for(j=0;j<n;j++)
               {
                   if(c[j]!=b[j])
                   {
                       status = false;
                       break;
                   }
               }
               if(status)
               {
                   k = count1(xor);
                   flips = Math.min(flips, k);
               }
            }
            if(flips<=50)
            pw.println("Case #"+ctr+": "+flips);
            else
                pw.println("Case #"+ctr+": "+"NOT POSSIBLE");
        }
        pw.flush();
    }
    
    public static int count1(int n)
    {
        int count =0;
        while(n>0)
        {
            if(n%2==1)
                count++;
            n=n/2;
        }
        return count;
    }
}
