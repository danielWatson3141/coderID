import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      int N = cin.nextInt();
      int edge[][] = new int[N - 1][2];
      for(int i=0; i<N-1; ++i) {
        edge[i][0] = cin.nextInt() - 1;
        edge[i][1] = cin.nextInt() - 1;
      }

      System.out.println("Case #" + C + ": " + solve(edge, N));

    }

  }

  int solve(int edge[][], int N) {

    // self + current;
    int score[][] = new int[N][N];
    int count[][] = new int[N][N];
    for(int i=0; i<N; ++i) {
      for(int j=0; j<N; ++j) {
        score[i][j] = -1;
      }
    }

    for(int i=0; i<N; ++i) {
      count(i, -1, edge, N, count);
    }

    int ans = N;
    for(int i=0; i<N; ++i) {
      ans = Math.min(ans, sub(i, -1, edge, N, score, count));
    }
    return ans;

  }

  int count(int cur, int parent, int edge[][], int N, int count[][]) {
    if( parent != -1 && count[cur][parent] > 0 ) { return count[cur][parent]; }
    // self;
    int ans = 1;
    for(int i=0; i<N - 1; ++i) {
      int op = getOp(edge[i], cur);
      if( op == -1 || op == parent ) { continue; }
      ans += count(op, cur, edge, N, count);
    }
    if( parent != -1 ) { count[cur][parent] = ans; }
    return ans;
  }

  int getOp(int val[], int cur) {
    if( val[0] == cur ) { return val[1]; }
    if( val[1] == cur ) { return val[0]; }
    return -1;
  }

  int sub(int cur, int parent, int edge[][], int N, int score[][], int count[][]) {
    if( parent != -1 && score[cur][parent] >= 0 ) {
      return score[cur][parent];
    }
    int ans = 0;
    List<Integer> child = new ArrayList<Integer>();
    for(int i=0; i<N - 1; ++i) {
      int op = getOp(edge[i], cur);
      if( op == -1 || op == parent ) { continue; }
      // must remove all;
      ans += count[op][cur];
      // do not have to remove;
      child.add( count[op][cur] - sub(op, cur, edge, N, score, count) );
    }
    Collections.sort(child);
    if( child.size() >= 2 ) {
      ans -= child.get(child.size() - 1);
      ans -= child.get(child.size() - 2);
    }
    if( parent != -1 ) { score[cur][parent] = ans; }
    return ans;
  }

}
