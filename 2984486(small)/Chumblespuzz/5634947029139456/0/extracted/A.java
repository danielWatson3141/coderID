package round.one.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A
{

   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         int n = scan.nextInt();
         int size = scan.nextInt();
         String [] outlets = new String[n];
         String [] plugs = new String[n];
         for (int i = 0; i < n; i++) outlets[i] = scan.next();
         for (int i = 0; i < n; i++) plugs[i] = scan.next();
         
         int best = Integer.MAX_VALUE;
         for (int i = 0; i < plugs.length; i++)
         {
            boolean[] flip = new boolean[outlets[i].length()];
            int flipCount = 0;
            for (int j = 0; j < outlets[i].length(); j++)
            {
               if (plugs[i].charAt(j) != outlets[0].charAt(j))
               {
                  flip[j] = true;
                  flipCount++;
               }
            }
//            System.out.println(Arrays.toString(flip));
            
            if (isValidSolution(outlets, plugs, flip))
            {
//               System.out.println("valid");
               best = Math.min(best, flipCount);
            }
         }
         
         
         System.out.println("Case #" + z + ": " + (best == Integer.MAX_VALUE ? "NOT POSSIBLE" : best));
      }

      scan.close();
   }

   private static boolean isValidSolution(String[] outlets, String[] plugs,
         boolean[] flip)
   {
      boolean [] taken = new boolean[outlets.length];
      for (int i = 0; i < plugs.length; i++)
      {
         boolean found = false;
         for (int j = 0; j < outlets.length; j++)
         {
            if (!taken[j])
            {
               boolean bad = false;
               for (int k = 0; k < outlets[j].length(); k++)
               {
//                  System.out.println(Arrays.toString(flip) + "\n" + Arrays.toString(outlets) + "\n" + Arrays.toString(plugs));
                  if ((flip[k] == false && outlets[j].charAt(k) == plugs[i].charAt(k)) ||
                       (flip[k] == true && outlets[j].charAt(k) != plugs[i].charAt(k)))
                  {
                  }
                  else
                  {
                     bad = true;
//                     System.out.println(i + " " + j + " " + flip[k] + " " + outlets[j].charAt(k) + " " + plugs[i].charAt(k));
                     break;
                  }
               }
               if (!bad)
               {
                  found = true;
                  taken[j] = true;
                  break;
               }
            }
         }
         
         if (!found)
         {
            return false;
         }
      }
      
      return true;
   }

}

