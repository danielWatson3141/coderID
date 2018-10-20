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
      int K = cin.nextInt();

      String in[] = new String[N];
      for(int i=0; i<N; ++i) { in[i] = cin.next(); }
      String out[] = new String[N];
      for(int i=0; i<N; ++i) { out[i] = cin.next(); }

      int res = solve(toLong(in, N), toLong(out, N), N, K);
      String ans = "NOT POSSIBLE";
      if( res >= 0 ) { ans = "" + res; }
      System.out.println("Case #" + C + ": " + ans);

    }

  }

  long[] toLong(String in[], int N){
    long out[] = new long[N];
    for(int i=0; i<N; ++i) {
      out[i] = Long.parseLong(in[i], 2);
    }
    return out;
  }

  int solve(long in[], long out[], int N, int K) {

    int ans = K + 1;

    // in[0] => out[N];
  MAIN:
    for(int i=0; i<N; ++i) {
      boolean used[] = new boolean[N];
      used[i] = true;
      long xor = in[0] ^ out[i];
    SUB:
      for(int j=1; j<N; ++j) {
        for(int k=0; k<N; ++k) {
          if( used[k] ) { continue; }
          if( (in[j] ^ xor) == out[k] ) {
            used[k] = true;
            // found;
            continue SUB;
          }
        }
        // failed;
        continue MAIN;
      }
      ans = Math.min(ans, Long.bitCount(xor));
    }


    if( ans == K + 1 ) { ans = -1; }
    return ans;

  }

}
