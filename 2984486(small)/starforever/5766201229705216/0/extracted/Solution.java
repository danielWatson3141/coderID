import java.util.Scanner;
import java.util.LinkedList;

public class Solution
{

  private int N;
  private LinkedList<Integer>[] adj;

  public Solution (Scanner sc)
  {
    N = sc.nextInt();
    adj = (LinkedList<Integer>[]) new LinkedList[N];
    for (int i = 0; i < N; ++i)
      adj[i] = new LinkedList<Integer>();
    for (int i = 0; i < N - 1; ++i)
    {
      int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
      adj[u].add(v);
      adj[v].add(u);
    }
  }

  public int solve ()
  {
    int maxFull = Integer.MIN_VALUE;
    for (int i = 0; i < N; ++i)
      maxFull = Math.max(maxFull, full(i, -1));
    return N - maxFull;
  }

  private int full (int u, int p)
  {
    int numChild = adj[u].size();
    if (p != -1)
      --numChild;
    if (numChild < 2)
      return 1;
    int c1 = Integer.MIN_VALUE, c2 = Integer.MIN_VALUE;
    for (int v : adj[u])
    {
      if (v == p)
        continue;
      int f = full(v, u);
      if (f > c1)
      {
        c2 = c1;
        c1 = f;
      }
      else if (f > c2)
      {
        c2 = f;
      }
    }
    return c1 + c2 + 1;
  }

  public static void main (String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int t = 1; t <= T; ++t)
    {
      Solution sol = new Solution(sc);
      System.out.format("Case #%d: %d\n", t, sol.solve());
    }
    sc.close();
  }

}
