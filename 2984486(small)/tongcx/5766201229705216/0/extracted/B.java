import java.util.*;

class B {
  static ArrayList<ArrayList<Integer>> graph;
  static int[] cnt;
  static int[] score;

  static void solve(int u, int father) {
    int child = 0;
    for (int v : graph.get(u)) if (v != father) {
      solve(v, u);
      cnt[u] += cnt[v];
      child++;
    }
    cnt[u] += 1;
    if (child == 0) score[u] = 0;
    else if (child == 1) score[u] = cnt[u]-1;
    else {
      int[] best = new int[2];
      best[0] = Integer.MAX_VALUE;
      best[1] = Integer.MAX_VALUE;
      for (int v : graph.get(u)) if (v != father) {
        if (score[v] - cnt[v] < best[1]) {
          best[1] = score[v] - cnt[v];
          if (best[0] > best[1]) {
            int t = best[0];
            best[0] = best[1];
            best[1] = t;
          }
        }
      }
      score[u] = cnt[u] - 1 + best[0] + best[1];
    }
  }

  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();
    for (int caseNo = 1; caseNo <= T; caseNo++) {
      int N = cin.nextInt();
      graph = new ArrayList<ArrayList<Integer>>();
      for (int i = 0; i < N; i++)
        graph.add(new ArrayList<Integer>());
      for (int i = 0; i < N-1; i++) {
        int X = cin.nextInt() - 1;
        int Y = cin.nextInt() - 1;
        graph.get(X).add(Y);
        graph.get(Y).add(X);
      }

      int ans = Integer.MAX_VALUE;
      for (int i = 0; i < N; i++) {
        cnt = new int[N];
        score = new int[N];
        solve(i, -1);
        ans = Math.min(ans, score[i]);
      }
      System.out.format("Case #%d: %d\n", caseNo, ans);
    }
  }
}
