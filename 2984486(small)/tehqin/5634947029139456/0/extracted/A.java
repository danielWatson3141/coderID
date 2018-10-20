
import java.util.*;

public class A
{
   public static void main(String[] args)
   {
      new A(new Scanner(System.in));
   }

   int makeInt(String s)
   {
      int res = 0;
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

         int[] switches = new int[N];
         int[] target = new int[N];
         for (int i=0; i<N; i++)
            switches[i] = makeInt(in.next());
         for (int i=0; i<N; i++)
            target[i] = makeInt(in.next());
         Arrays.sort(target);

         int res = Integer.MAX_VALUE;
         int[] switch2 = new int[N];
         for (int mask=0; mask<(1<<L); mask++)
         {
            int rr = Integer.bitCount(mask);
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

         String result = "NOT POSSIBLE";
         if (res < Integer.MAX_VALUE)
            result = Integer.toString(res);
      
         System.out.printf("Case #%d: %s%n", tc, result);
      }
   }
}
