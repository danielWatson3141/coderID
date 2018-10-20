import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class b {
  
  static ArrayList<Integer>[] t;
  
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("b.in"));
    PrintWriter out = new PrintWriter(new File("b.out"));
    int cases = in.nextInt();
    for (int co = 1; co <= cases; co++) {
      n = in.nextInt();
      t = new ArrayList[n];
      for (int i = 0; i < n; i++)
        t[i] = new ArrayList<Integer>();
      for (int i = 0; i < n - 1; i++) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        t[x].add(y);
        t[y].add(x);
      }
      
      int answer = solve();
      System.out.printf("Case #%d: %d\n", co, answer);
      out.printf("Case #%d: %d\n", co, answer);
    }
    out.close();
  }
  
  static int solve() {
    int ans = (int) 1e9;
    for (int root = 0; root < n; root++) {
      root(root);
      memo = new int[n];
      Arrays.fill(memo, -1);
      int pAns = go(root);
      ans = Math.min(ans, pAns);
    }
    return ans;
  }
  
  static int n;
  static ArrayList<Integer>[] c;
  static int[] size;
  
  public static void root(int r) {
    c = new ArrayList[n];
    for (int i = 0; i < n; i++)
      c[i] = new ArrayList<Integer>();
    Queue<Integer> q = new ArrayDeque<Integer>();
    boolean[] visited = new boolean[n];
    visited[r] = true;
    q.add(r);
    size = new int[n];
    Stack<Integer> s = new Stack<Integer>();
    while (!q.isEmpty()) {
      int at = q.poll();
      s.push(at);
      for (int adj : t[at]) {
        if (!visited[adj]) {
          c[at].add(adj);
          visited[adj] = true;
          q.add(adj);
        }
      }
    }
    
    while (!s.isEmpty()) {
      int at = s.pop();
      size[at] = 1;
      for (int child : c[at])
        size[at] += size[child];
    }
    // System.out.printf("With %d as root size = %s\n", r,
    // Arrays.toString(size));
    // System.out.printf("Tree:\n");
    // for (int i = 0; i < n; i++) {
    // System.out.printf("%d: %s\n", i, c[i]);
    // }
  }
  
  static int[] memo;
  
  public static int go(int at) {
    if (c[at].size() == 0) return 0;
    if (c[at].size() == 1) return size[c[at].get(0)];
    if (memo[at] != -1) return memo[at];
    int[] savings = new int[2];
    for (int i = 0; i < c[at].size(); i++) {
      int child = c[at].get(i);
      int save = size[child] - go(child);
      if (save >= savings[0]) {
        savings[1] = savings[0];
        savings[0] = save;
      } else if (save >= savings[1]) {
        savings[1] = save;
      }
    }
    return memo[at] = size[at] - 1 - savings[0] - savings[1];
  }
}
