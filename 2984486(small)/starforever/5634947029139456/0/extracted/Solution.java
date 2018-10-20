import java.util.Scanner;
import java.util.Arrays;

public class Solution
{

  private int N, L;

  private long[] S1, S2, T;

  public Solution (Scanner sc)
  {
    N = sc.nextInt();
    L = sc.nextInt();
    S1 = new long[N];
    for (int i = 0; i < N; ++i)
      S1[i] = toInt(sc.next());
    S2 = new long[N];
    for (int i = 0; i < N; ++i)
      S2[i] = toInt(sc.next());
    // for (int i = 0; i < N; ++i)
    //   System.out.format(" %d", S1[i]);
    // System.out.println();
    // for (int i = 0; i < N; ++i)
    //   System.out.format(" %d", S2[i]);
    // System.out.println();
  }

  public int solve ()
  {
    T = new long[N];
    Arrays.sort(S2);
    int minSwitch = Integer.MAX_VALUE;
    for (int i = 0; i < N; ++i)
    {
      long mask = S1[0] ^ S2[i];
      if (check(mask))
        minSwitch = Math.min(minSwitch, Long.bitCount(mask));
    }
    return minSwitch < Integer.MAX_VALUE ? minSwitch : -1;
  }

  private long toInt (String s)
  {
    long r = 0;
    for (int i = 0; i < L; ++i)
      r = r << 1 | s.charAt(i) - '0';
    return r;
  }

  private boolean check (long mask)
  {
    for (int i = 0; i < N; ++i)
      T[i] = S1[i] ^ mask;
    Arrays.sort(T);
    return Arrays.equals(T, S2);
  }

  public static void main (String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int t = 1; t <= T; ++t)
    {
      Solution sol = new Solution(sc);
      System.out.format("Case #%d: ", t);
      int ans = sol.solve();
      if (ans != -1)
        System.out.format("%d\n", ans);
      else
        System.out.format("NOT POSSIBLE\n");
    }
    sc.close();
  }

}
