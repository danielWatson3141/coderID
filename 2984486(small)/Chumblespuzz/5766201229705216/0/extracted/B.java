package round.one.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B
{

   private static int n;
   private static boolean [][] graph;
   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         n = scan.nextInt();
         graph = new boolean[n][n];
         
         for (int i = 0; i < n - 1; i++)
         {
            int from = scan.nextInt() - 1;
            int to = scan.nextInt() - 1;
            graph[from][to] = true;
            graph[to][from] = true;
         }
         
         int best = Integer.MAX_VALUE;
         for (int i = 0; i < n; i++)
         {
            boolean [] visited = new boolean[n];
            best = Math.min(solve(i, visited).deleteToValid, best);
         }
         
         System.out.println("Case #" + z + ": " + best);
      }

      scan.close();
   }
   
   
   private static Pair solve(int current, boolean[] visited)
   {
      visited[current] = true;
      
      int totalDeletes = 0;
      
      Pair[] values = new Pair[n];
      for (int i = 0; i < n; i++)
      {
         if (i != current && graph[i][current] && !visited[i])
         {
            Pair value = solve(i, visited);
            totalDeletes += value.deleteTotal;
            values[i] = value;
         }
      }

      int best = totalDeletes;
      for (int i = 0 ; i < n; i++)
      {
         for (int j = i + 1; j < n; j++)
         {
            if (values[i] != null && values[j] !=  null)
            {
               int costToKeep = values[i].deleteToValid + values[j].deleteToValid;
               int costForOthers = totalDeletes - values[i].deleteTotal - values[j].deleteTotal;
               best = Math.min(best, costToKeep + costForOthers);
            }
         }
      }
      
      return new Pair(best, totalDeletes + 1);
   }

}

class Pair
{
   public int deleteToValid;
   public int deleteTotal;
   
   public Pair(int deleteToValid, int deleteTotal)
   {
      this.deleteToValid = deleteToValid;
      this.deleteTotal = deleteTotal;
   }
}

