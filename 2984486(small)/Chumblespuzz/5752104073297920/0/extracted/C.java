package round.one.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Random;
import java.util.Scanner;

public class C
{

   static Random rand = new Random();
   static int n;
   static int [][] perms;
   static int [][] goodResults;
   static int [][] badResults;
   static final long LIMIT = 1_000_000;

   public static void main(String[] args) throws FileNotFoundException
   {
//      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      
      perms = new int[numCases][];
      for (int z = 1; z <= numCases; z++)
      {
         n = scan.nextInt();
         perms[z-1] = new int[n];
         for (int i = 0; i < n; i++)
         {
            perms[z-1][i] = scan.nextInt();
         }
      }
      
      scan.close();
      
      goodResults = new int[numCases][n+1];
      badResults = new int[numCases][n+1];

      int[] arr = new int[n];
      reset(arr);
      
      long currentTime = System.currentTimeMillis();
      
      while (currentTime + (1000 * 60 * 3) < System.currentTimeMillis())
      {
         for (int i = 0; i < LIMIT; i++)
         {
            good(arr);
            
            for(int j = 0; j < numCases; j++)
            {
               goodResults[j][eval(arr, j)]++;
            }
            
            reset(arr);
         }
         
         for (int i = 0; i < LIMIT; i++)
         {
            bad(arr);
            
            for(int j = 0; j < numCases; j++)
            {
               badResults[j][eval(arr, j)]++;
            }
            
            reset(arr);
         }
      }
      for (int z = 1; z <= numCases; z++)
      {
         boolean goodWins = true;
         for (int i = 0; i <= n; i++)
         {
            if (goodResults[z-1][i] > badResults[z-1][i])
            {
               goodWins = true;
               break;
            }
            else if (goodResults[z-1][i] < badResults[z-1][i])
            {
               goodWins = false;
               break;
            }
         }
         System.out.println("Case #" + z + ": " + (goodWins ? "GOOD" : "BAD"));
      }
      
   }
   public static void reset(int[] arr)
   {
      for (int i = 0; i < n; i++)
      {
         arr[i] = i;
      }
   }

   public static void good(int[] arr)
   {
      for (int i = 0; i < n; i++)
      {
         int to = i + rand.nextInt(n - i);
         int temp = arr[i];
         arr[i] = arr[to];
         arr[to] = temp;
      }
   }

   public static void bad(int[] arr)
   {
      for (int i = 0; i < n; i++)
      {
         int to = rand.nextInt(n);
         int temp = arr[i];
         arr[i] = arr[to];
         arr[to] = temp;
      }
   }

   private static int eval(int[] arr, int z)
   {
      int result = 0;
      for (int i = 0; i < n; i++)
      {
         if (arr[i] != perms[z][i])
         {
            result++;
         }
      }
      return result;
   }

}
