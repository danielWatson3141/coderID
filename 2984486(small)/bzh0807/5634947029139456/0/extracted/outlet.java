import java.util.*;
import java.io.*;
public class outlet
{
   public static void main(String[] args) throws IOException
   {
      BufferedReader in = new BufferedReader(new FileReader("A-small-attempt2.in"));
      PrintStream out = new PrintStream(new File("outlet.out"));
      int num = Integer.parseInt(in.readLine());
      for(int k = 0; k < num; k++)
      {
         String dat = in.readLine();
         int sp = dat.indexOf(" ");
         int x = Integer.parseInt(dat.substring(0, sp));
         int y = Integer.parseInt(dat.substring(sp+1));
         String init = in.readLine();
         String des = in.readLine();
         String[] ii = init.split(" ");
         String[] dd = des.split(" ");
         ArrayList<String> arr = new ArrayList<String>();
         genposs(arr, y, "");
         //System.out.println(arr);
         boolean ch = false;
         int lowest = y+1;
         for(String dc: arr)
         {
            int total = 0;
            String[] nn = new String[ii.length];
            for(int z = 0; z < nn.length; z++)
            {
               nn[z] = ii[z];
            }
            for(int kk = 0; kk < dc.length() && ch == false; kk++)
            {
               if(dc.substring(kk, kk+1).equals("c"))
               {
                  total++;
                  for(int zz = 0; zz < ii.length; zz++)
                  {
                     String s = nn[zz];
                     String front = s.substring(0, kk);
                    // System.out.print("F: "+front);
                     String back = s.substring(kk+1);
                     //System.out.print("B: "+back);
                     String change = s.substring(kk, kk+1);
                     //System.out.print("C: "+change);
                     //System.out.println();
                     String nS = "";
                     if(change.equals("0"))
                     {
                        nS = "1";
                     }
                     else
                     {
                        nS = "0";
                     }
                     s = front+nS+back;
                     nn[zz] = s;
                  }
               }
               boolean dada = poss(nn, dd);
               //System.out.print(dc+" ");
               //if(k <= 1)
                  //print(nn);
               if(ch == false)
                  ch = dada;
               if(ch)
               {
                  lowest = total;
               }
            }
         }
         if(lowest <= y)
         {
            out.println("Case #"+(k+1)+": "+lowest);
         }
         else
         {
            out.println("Case #"+(k+1)+": "+"NOT POSSIBLE");
         }
      }
   }
   static void print(String[] a)
   {
      for(int k = 0; k < a.length; k++)
      {
         System.out.print(a[k]+" ");
      }
      System.out.println();
   }
   static void genposs(ArrayList<String> a, int tot, String cont)
   {
      if(tot == 0)
      {
         a.add(cont);
      }
      else
      {
      String c1 = cont+"d";
      String c2 = cont+"c";
      genposs(a, tot-1, c1);
      genposs(a, tot-1, c2);
      }
   }
   static boolean poss(String[] a, String[] b)
   {
      Arrays.sort(a);
      Arrays.sort(b);
      boolean re = true;
      for(int k = 0; k < a.length; k++)
      {
         if(!a[k].equals(b[k]))
         {
            re= false;
         }
      }
      return re;
   }
}
