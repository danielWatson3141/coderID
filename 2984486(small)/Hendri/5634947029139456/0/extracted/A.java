import java.util.*;

class A {

  static int N,L;
  static String[] left, right;
  static int[][] dist, memo;
  static boolean[] vis;
  static int[] match,inv;
  static int now;
  static ArrayList<TreeSet<String>> difset;
  static String setNow;

  static int calc(int i, int j) {
    int dif = 0;
    String model = "";
    for (int x = 0; x < L; x++) {
      if (left[i].charAt(x) != right[j].charAt(x)) {
        dif++;
        model += "1";
      } else {
        model += "0";
      }
    }
    difset.get(dif).add(model);
    return dif;
  }
  
  static int check(int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    if (dist[i][j] != now) return memo[i][j] = 0;
    String model = "";
    for (int x = 0; x < L; x++) {
      if (left[i].charAt(x) != right[j].charAt(x)) {
        model += "1";
      } else {
        model += "0";
      }
    }
    if(model.equals(setNow)) return memo[i][j] = 1;
    return memo[i][j] = 0;
  }

  static boolean augment(int node) {
    if (vis[node]) return false;
    vis[node] = true;
    for (int i = 0; i < N; i++) {
      if (check(node, i) == 1 && (inv[i] == -1 || augment(inv[i]))) {
        match[node] = i;
        inv[i] = node;
        return true;
      }
    }
    return false;
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int T = input.nextInt();
    for (int t = 1; t <= T; t++) {
      System.out.print("Case #" + t + ": ");
      N = input.nextInt();
      L = input.nextInt();
      left = new String[N];
      right = new String[N];
      for (int i = 0; i < N; i++) {
        left[i] = input.next();
      }
      for (int i = 0; i < N; i++) {
        right[i] = input.next();
      }
      dist = new int[N][N];
      difset = new ArrayList<TreeSet<String>>();
      for (int i = 0; i < L+1; i++) {
        difset.add(new TreeSet<String>());
      }
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          dist[i][j] = calc(i, j);
        }
      }

      int sol = -1;
      for (int tempsol = 0; tempsol <= L; tempsol++) {
        now = tempsol;
        TreeSet<String> set = difset.get(tempsol);
        boolean found = false;
        while(!set.isEmpty()) {
          setNow = set.first();
          set.remove(setNow);
          vis = new boolean[N];
          match = new int[N];
          inv = new int[N];
          memo = new int[N][N];
          Arrays.fill(vis, false);
          Arrays.fill(match, -1);
          Arrays.fill(inv, -1);
          for (int[] m:memo)Arrays.fill(m, -1);
          int ok = 0;
          for (int i = 0; i < N; i++) {
            if (augment(i)) {
              ok++;
            }
          }
          if (ok == N) {
            sol = tempsol;
            found = true;
            break;
          }
        }
        if (found)break;
      }
      System.out.println((sol == -1 ? "NoT PosSiBLe" : sol));
    }
  }
}
