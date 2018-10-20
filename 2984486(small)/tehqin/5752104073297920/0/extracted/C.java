
import java.util.*;

public class C
{
   public static void main(String[] args)
   {
      new C(new Scanner(System.in));
   }

   int maxIter = 250000;

   int[][] genMatrix1(int N)
   {
      int[] v = new int[N];
      int[][] res = new int[N][N];
      for (int s=0; s<maxIter; s++)
      {
         for (int k=0; k<N; k++)
            v[k] = k;
         for (int k=0; k<N; k++)
         {
            int p = (int)(Math.random()*(N-k));
            p += k;

            int tmp = v[k];
            v[k] = v[p];
            v[p] = tmp;
         }

         for (int i=0; i<N; i++)
            res[v[i]][i] += 1;
      }

      return res;
   }

   int[][] genMatrix2(int N)
   {
      int[] v = new int[N];
      int[][] res = new int[N][N];
      for (int s=0; s<maxIter; s++)
      {
         for (int k=0; k<N; k++)
            v[k] = k;
         for (int k=0; k<N; k++)
         {
            int p = (int)(Math.random()*N);

            int tmp = v[k];
            v[k] = v[p];
            v[p] = tmp;
         }

         for (int i=0; i<N; i++)
            res[v[i]][i] += 1;
      }

      return res;
   }

   public C(Scanner in)
   {
      int N = 1000;
      int[][] m1 = genMatrix1(N);
      int[][] m2 = genMatrix2(N);
      
      int T = in.nextInt();
      for (int tc=1; tc<=T; tc++)
      {
         N = in.nextInt();

         int[] v = new int[N];
         for (int i=0; i<N; i++)
            v[i] = in.nextInt();

         int sum1 = 0;
         for (int i=0; i<N; i++)
            sum1 += m1[v[i]][i];

         int sum2 = 0;
         for (int i=0; i<N; i++)
            sum2 += m2[v[i]][i];

         
         String res = sum1 > sum2 ? "GOOD" : "BAD";
         System.out.printf("Case #%d: %s%n", tc, res);
      }
   
   }
}
