import java.util.*;

class B {

  static int N;
  static boolean[][] graf;
  static int[] dp, dp2;
  static ArrayList<ArrayList<Integer>> adjList;
  
  static int countNode(int node, int par) {
    if (dp2[node] != -1) return dp2[node];
    int result = 1;
    for (Integer x : adjList.get(node)) {
      if (x == par)continue;
      result += countNode(x, node);
    }
    return dp2[node] = result;
  }

  static int f(int node, int par) {
    if (dp[node] != -1) return dp[node];
    ArrayList<Integer> neigh = adjList.get(node);
    if (neigh.size() == 1) {
      return dp[node] = par == -1 ?
        countNode(neigh.get(0), node) : 0;
    }
    int all = 0;
    for (Integer x : neigh) {
      if (x == par) continue;
      all += countNode(x, node);
    }
    int res = all;
    for (int i = 0; i < neigh.size(); i++) {
      if(neigh.get(i) == par) continue;
      for (int j = i + 1; j < neigh.size(); j++) {
        if (neigh.get(j) == par) continue;
        int tempres = all - countNode(neigh.get(i), node)
          - countNode(neigh.get(j), node) + f(neigh.get(i), node)
          + f(neigh.get(j), node);
        if (res == -1 || tempres < res) {
          res = tempres;
        }
      }
    }
    return dp[node] = res;
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int T = input.nextInt();
    for (int t = 1; t <= T; t++) {
      System.out.print("Case #" + t + ": ");
      N = input.nextInt();
      graf = new boolean[N][N];
      adjList = new ArrayList<ArrayList<Integer>>();
      for (int i = 0; i < N; i++) {
        adjList.add(new ArrayList<Integer>());
      }
      for (int i = 0; i < N-1; i++) {
        int a = input.nextInt();
        int b = input.nextInt();
        a--; b--;
        graf[a][b] = graf[b][a] = true;
        adjList.get(a).add(b);
        adjList.get(b).add(a);
      }
      int sol = -1;
      for (int i = 0; i < N; i++) {
        dp = new int[N];
        dp2 = new int[N];
        Arrays.fill(dp, -1);
        Arrays.fill(dp2, -1);
        int tempsol = f(i, -1);
        if (sol == -1 || sol > tempsol) {
          sol = tempsol;
        }
      }
      System.out.println(sol);
    }
  }
}
