package code_jam;

import java.io.*;
import java.util.*;

public class b {
  static int n;
  static int[][] edges = new int[1001][];
  static int[] l = new int[1001];

  static int[] f = new int[1001], s = new int[1001];
  static boolean[] visited = new boolean[1001];
  static int ans;
  
  public static void visit(int cur) {
    visited[cur] = true;
    List<Integer> ch = new ArrayList<Integer>();
    s[cur] = 0;
    for (int i=0; i<l[cur]; i++) {
      if (!visited[edges[cur][i]]) {
        ch.add(edges[cur][i]);
        visit(edges[cur][i]);
        s[cur] += s[edges[cur][i]];
      }
    }
    s[cur]++;
    if (ch.size() == 0) {
      f[cur] = 0;
      return;
    } 
    if (ch.size() == 1) {
      f[cur] = s[cur] - 1;
      return;
    }
    f[cur] = 0;
    int max1 = 0;
    int max2 = 0;
    for (int i = 0; i < ch.size(); i++) {
      if (max1 < s[ch.get(i)] - f[ch.get(i)]) {
        max2 = max1;
        max1 = s[ch.get(i)] - f[ch.get(i)];
      } else if (max2 < s[ch.get(i)] - f[ch.get(i)]) {
        max2 = s[ch.get(i)] - f[ch.get(i)];
      }
      f[cur] += s[ch.get(i)];
    }
    f[cur] -= max1;
    f[cur] -= max2;
  }
  
  public static void main(String[] args) throws Exception{
    Scanner inf = new Scanner(new FileReader("in.txt"));
    int nn = inf.nextInt();
    for (int ii = 0; ii < nn; ii++) {
      n = inf.nextInt();
      for (int i=0; i<n; i++) {
        edges[i] = new int[n];
        l[i] = 0;
      }
      for (int i=1; i<n; i++) {
        int a = inf.nextInt() - 1;
        int b = inf.nextInt() - 1;
        edges[a][l[a]] = b;
        l[a]++;
        
        edges[b][l[b]] = a;
        l[b]++;
      }
      ans = n - 1;
      for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
          visited[j]=false;
          f[j]= -1;
          s[j]= -1;
        }
        visit(i);
        //System.out.println(ans + "\t" + (i+1) + "\t" + f[i]);
        //for (int j=0; j<n; j++)
        //  System.out.println(j + "\t" + f[j]);
        if (f[i] < ans) {
          ans = f[i];
        }
      }
      System.out.println("Case #" + (ii+1) + ": " + ans);
    }
    inf.close();
  }

}

