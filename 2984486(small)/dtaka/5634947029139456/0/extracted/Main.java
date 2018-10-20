import java.io.*;
import java.util.*;

public class Main{
  static final String ANSWER = "Case #%d: %d\n";
  static final String NOTPOS = "Case #%d: NOT POSSIBLE\n";
  
  public static void main(String args[]) throws Exception {
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    String line;
    String[] prms;
    int T = Integer.parseInt(stdin.readLine());
    for (int t = 1; t <= T; t++) {
      line = stdin.readLine();
      prms = line.split(" ");
      int N = Integer.parseInt(prms[0]);
      int L = Integer.parseInt(prms[1]);
      
      long[] outlets = new long[N];
      line = stdin.readLine();
      prms = line.split(" ");
      for (int i = 0; i < N; i++) {
        outlets[i] = Long.parseLong(prms[i], 2);
      }
      
      long[] devices = new long[N];
      line = stdin.readLine();
      prms = line.split(" ");
      for (int i = 0; i < N; i++) {
        devices[i] = Long.parseLong(prms[i], 2);
      }
      
      int ans = 100000;
      for (int i = 0; i < N; i++) {
        boolean[] flag = new boolean[N];
        long val = outlets[0] ^ devices[i];
        flag[i] = true;
        if (dfs(N, outlets, devices, flag, val, 1)) {
          int cnt = 0;
          for (int j = 0; j < 40; j++) {
            if (val % 2 == 1) cnt++;
            val /= 2;
          }
          ans = Math.min(ans, cnt);
        }
      }
      
      if (ans == 100000) {
        System.out.printf(NOTPOS, t);
      } else {
        System.out.printf(ANSWER, t, ans);
      }
    }
  }
  static boolean dfs(int N, long[] outlets, long[] devices, boolean[] flag, long val, int index) {
    if (index == N) return true;
    for (int i = 0; i < N; i++) {
      if (!flag[i]) {
        long v = outlets[index] ^ devices[i];
        if (v == val) {
          flag[i] = true;
          if (dfs(N, outlets, devices, flag, val, index+1)) {
            return true;
          }
          flag[i] = false;
        }
      }
    }
    return false;
  }
}
