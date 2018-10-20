import java.util.*;
import java.io.*;
public class rand
{
   public static void main(String[] args) throws IOException
   {
      BufferedReader in = new BufferedReader(new FileReader("C-small-attempt7.in"));
      PrintStream out = new PrintStream(new File("c6.out"));
      in.readLine();
      for(int k = 0; k < 120; k++)
      {
         in.readLine();
         String next = in.readLine();
         String[] i = next.split(" ");
         int[] ii = new int[i.length];
         int[] jj = new int[i.length];
         for(int l = 0; l < ii.length; l++)
         {
            ii[l] = Integer.parseInt(i[l]);
            jj[l] = Integer.parseInt(i[l]);
         }
         Arrays.sort(ii);
         int totsam = 0;
         for(int l = 0; l < ii.length; l++)
         {
            if(ii[l] == jj[l])
            {
               totsam++;
            }
         }
         double d = Math.random();
         if(totsam >= 1)
         {
            if(d < 0.66)
            {
            out.println("Case #"+(k+1)+": "+"BAD");
            }
            else
            {
               out.println("Case #"+(k+1)+": "+"GOOD");
            }
            
         }
         else
         {
            if(d < 0.66)
            {
            out.println("Case #"+(k+1)+": "+"GOOD");
            }
            else
            {
               out.println("Case #"+(k+1)+": "+"BAD");
            }
         }
      }
   }
}