package code_jam;

import java.io.*;
import java.util.*;

public class a {    
  static int[] a = new int[12];
  static int[] b = new int[12];
  static int n,l,ans;
  public static boolean ok() {
    HashSet<Integer> x = new HashSet<Integer>();
    for (int i=0; i<n; i++) x.add(a[i]);
    for (int i=0; i<n; i++)
      if (!x.contains(b[i])) return false;
    return true;
  }
  
  public static void search(int i, int cur) {
    if (cur >= ans) return;
    if (i == l) {
      if (ok()) ans = cur;
      return;
    }
    search(i+1, cur);
    
    for (int j=0; j<n; j++) {
      a[j] = a[j] ^ (1<<i);
    }
    search(i+1, cur+1);
    for (int j=0; j<n; j++) {
      a[j] = a[j] ^ (1<<i);
    }
  }
  
  public static void main(String[] args) throws Exception{
    Scanner inf = new Scanner(new FileReader("in.txt"));
    int nn = inf.nextInt();
    for (int ii = 0; ii < nn; ii++) {
      n = inf.nextInt();
      l = inf.nextInt();
      inf.nextLine();
      String[] line = inf.nextLine().split(" ");
      for (int i = 0; i < n; i++) {
        a[i] = 0;
        for (int j = 0; j < l; j++) {
          if (line[i].charAt(j) == '1') a[i] += (1<<j);
        }
      }
      
      line = inf.nextLine().split(" ");
      for (int i = 0; i < n; i++) {
        b[i] = 0;
        for (int j = 0; j < l; j++) {
          if (line[i].charAt(j) == '1') b[i] += (1<<j);
        }
      }
      ans = l + 1;
      search(0, 0);
      System.out.print("Case #" + (ii+1) + ": ");
      if (ans == l+1) {
        System.out.println("NOT POSSIBLE");
      } else {
        System.out.println(ans);
      }
    }
  }

}
