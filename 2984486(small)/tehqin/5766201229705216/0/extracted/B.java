
import java.util.*;

public class B
{
   public static void main(String[] args)
   {
      new B(new Scanner(System.in));
   }

   int N;
   ArrayList<Integer>[] adj;

   int getId(int i, int p)
   {
      return i + N*p;
   }

   long getId2(int i, int p, int numLeft, int c)
   {
      long res = c*3+numLeft;
      res *= N*N;
      res += getId(i, p);
      return res;
   }

   int[] sizeMemo;
   int getSize(int i, int p)
   {
      // memoize TODO
      int id = getId(i, p);
      if (sizeMemo[id] != -1)
         return sizeMemo[id];

      int res = 1;
      for (int j : adj[i]) if (j != p)
         res += getSize(j, i);
      return sizeMemo[id] = res;
   }

   HashMap<Long, Integer> memo;
   int go(int i, int p, int numLeft, int c)
   {
      if (numLeft < 0)
         return N;
      if (c == adj[i].size())
         return numLeft == 0 ? 0 : N;

      long id = getId2(i, p, numLeft, c);
      Integer res = memo.get(id);
      if (res != null)
         return res;

      res = N;
      int j = adj[i].get(c);
      if (j == p)
         res = go(i, p, numLeft, c+1);
      else
      {
         // Don't take it
         int r1 = go(i, p, numLeft, c+1)+getSize(j, i);

         // Take it
         int r2 = Math.min(go(j, i, 2, 0), go(j, i, 0, 0));
         r2 += go(i, p, numLeft-1, c+1);
      
         //System.out.printf("%d %d %d %d------%n", i, p, numLeft, c);
         //System.out.printf("%d %d%n", r1, r2);
         res = Math.min(r1, r2);
      }

      memo.put(id, res);
      return res;
   }

   public B(Scanner in)
   {
      int T = in.nextInt();
      for (int tc=1; tc<=T; tc++)
      {
         N = in.nextInt();
         adj = new ArrayList[N];      
         for (int i=0; i<N; i++)
            adj[i] = new ArrayList<Integer>();
         
         Arrays.fill(sizeMemo = new int[N*N], -1);
         memo = new HashMap<Long, Integer>();
         for (int v=1; v<N; v++)
         {
            int i = in.nextInt()-1;
            int j = in.nextInt()-1;
            adj[i].add(j);
            adj[j].add(i);
         }
         
         int res = N;
         for (int i=0; i<N; i++)
         {
            int rr = Math.min(go(i, i, 0, 0), go(i, i, 2, 0));
            res = Math.min(res, rr);
         }

         System.out.printf("Case #%d: %d%n", tc, res);
      }
   }
}
