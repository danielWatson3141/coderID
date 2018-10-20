
import java.util.*;

public class A
{
   public static void main(String[] args)
   {
      new A(new Scanner(System.in));
   }

   long makeInt(String s)
   {
      long res = 0;
      for (char c : s.toCharArray())
      {
         int v = (int)(c-'0');
         res = res*2+v;
      }
      return res;
   }

   public A(Scanner in)
   {
      int T = in.nextInt();
      for (int tc=1; tc<=T; tc++)
      {
         int N = in.nextInt();
         int L = in.nextInt();

         long[] switches = new long[N];
         long[] target = new long[N];
         for (int i=0; i<N; i++)
            switches[i] = makeInt(in.next());
         for (int i=0; i<N; i++)
            target[i] = makeInt(in.next());
         Arrays.sort(target);

         int res = Integer.MAX_VALUE;
         long[] switch2 = new long[N];
         for (int s1=0; s1<N; s1++)
         {
            for (int s2=0; s2<N; s2++)
            {
               long mask = switches[s1] ^ target[s2];
               int rr = Long.bitCount(mask);
               for (int i=0; i<N; i++)
                  switch2[i] = switches[i] ^ mask;
               Arrays.sort(switch2);
               boolean passed = true;
               for (int i=0; i<N; i++)
               {
                  if (switch2[i] != target[i])
                  {
                     passed = false;
                     break;
                  }
               }

               if (passed)
                  res = Math.min(res, rr);
            }
         }
         
         
         String result = "NOT POSSIBLE";
         if (res < Integer.MAX_VALUE)
            result = Integer.toString(res);
         System.out.printf("Case #%d: %s%n", tc, result);
      }
   }
}

class Node
{
   int numNodes;
   int id, numThings;
   Node left, right;
   public Node(int ii)
   {
      id = ii;
      numThings = 0;
      numNodes = 0;
      left = right = null;
   }
}
