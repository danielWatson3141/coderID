import java.io.*;
import java.util.*;

public class Main{
  static final String ANSWER = "Case #%d: %d\n";
  
  public static void main(String args[]) throws Exception {
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    String line;
    String[] prms;
    int T = Integer.parseInt(stdin.readLine());
    for (int t = 1; t <= T; t++) {
      line = stdin.readLine();
      int N = Integer.parseInt(line);
      boolean[][] g = new boolean[N][N];
      int[] edgnum = new int[N];
      
      for (int i = 0; i < N-1; i++) {
        line = stdin.readLine();
        prms = line.split(" ");
        int n1 = Integer.parseInt(prms[0])-1;
        int n2 = Integer.parseInt(prms[1])-1;
        g[n1][n2] = true;
        g[n2][n1] = true;
      }
      
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (g[i][j]) edgnum[i]++;
        }
      }
      
      int ans = N;
      for (int i = 0; i < N; i++) {
        ans = Math.min(ans, check(N, g, edgnum, -1, i));
      }
      
      System.out.printf(ANSWER, t, ans);
    }
  }
  static int check(int N, boolean[][] g, int[] edgnum, int parent, int node) {
    int count = 0;
    int v1 = N;
    int v2 = N;
    int sum = 0;
    int cnum = 0;
    int child = -1;
    for (int i = 0; i < N; i++) {
      if (g[node][i] && i != parent) {
        cnum++;
        child = i;
        int v =  check(N, g, edgnum, node, i);
        if (v < v1) {
          v2 = v1;
          v1 = v;
        } else if (v < v2) {
          v2 = v;
        }
        sum += v;
      }
    }
    if (cnum == 0) {
      count = 0;
    } else if (cnum == 1) {
      count = countChildren(N, g, edgnum, node, child) + 1;
    } else {
      count = sum + cnum - 2;
    }
    //System.out.println("p:"+parent+", n:"+node+", count:"+count);
    return count;
  }
  static int countChildren(int N, boolean[][] g, int[] edgnum, int parent, int node) {
    int count = edgnum[node]-1;
    for (int i = 0; i < N; i++) {
      if (g[node][i] && i != parent) {
        count += countChildren(N, g, edgnum, node, i);
      }
    }
    return count;
  }
}
