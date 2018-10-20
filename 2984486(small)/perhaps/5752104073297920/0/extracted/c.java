package code_jam;

import java.io.*;
import java.util.*;

public class c {
  static int[] a = new int[1002];
  
  public static void main(String[] args) throws Exception{
    Scanner inf = new Scanner(new FileReader("in.txt"));
    FileWriter outf = new FileWriter("out.txt");
    int nn = inf.nextInt();
    for (int ii=0; ii<nn; ii++) {
      int n = inf.nextInt();
      for (int i=0; i<n; i++)
        a[i] = inf.nextInt();
      int c=0, d=0;
      for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++) {
          c++;
          if (a[i] < a[j]) d++;
        }
      
      System.out.print("Case #" + (ii+1) + ": ");
      if (d*2 > c) {
        System.out.println("BAD");
      } else {
        System.out.println("GOOD");
      }
    }
     
    inf.close();
    outf.close();
  }
}
