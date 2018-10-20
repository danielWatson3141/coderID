import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Scanner;


public class c {
  static int IGNORE_THRESHOLD = 100;
  static int n = 1000;
  static int trials = (int) 5e7;
  static int EXP = trials / n;
  static double prob = 1. / n;
  // static int allowedToFail = trials / 50000;
  static double EPS = .000155;
  static Random rand = new Random();
  
  public static void main(String[] args) throws IOException {
    // precomp();
    // if (1 == 1) return;
    readpre();
    boolean[][] ignore = new boolean[n][n];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        ignore[i][j] = Math.abs(f[i][j] - EXP) <= IGNORE_THRESHOLD;
        // System.out.printf("Ignoring if %d is in pos %d\n", i, j);
      }
    
    Scanner in = new Scanner(new File("c.in"));
    PrintWriter out = new PrintWriter(new File("c.out"));
    
    // Scanner temp = new Scanner(new File("cgen.out"));
    
    int cases = in.nextInt();
    int winCnt = 0, loseCnt = 0;
    int sumGood = 0, cntGood = 0, sumBad = 0, cntBad = 0;
    for (int co = 1; co <= cases; co++) {
      // String aa = temp.nextLine();
      // boolean goodGen = aa.contains("GOOD");
      
      int n = in.nextInt();
      int[] perm = new int[n];
      for (int i = 0; i < n; i++)
        perm[i] = in.nextInt();
      
      int cntBadWins = 0;
      for (int i = 0; i < n; i++) {
        if (ignore[perm[i]][i]) continue;
        int fCnt = f[perm[i]][i];
        double p = fCnt * 1. / trials;
        // System.out.printf("FOR %d in %d EXP was %.5f, sample was %.5f\n",
        // perm[i], i, prob, p);
        // System.out.printf("Good Range = [%.5f - %.5f]\n", prob - EPS, prob +
        // EPS);
        if (p < prob - EPS) cntBadWins++;
        if (p > prob + EPS) cntBadWins++;
      }
      // System.out.printf("CNT BAD WINS = %d, Good = %b\n", cntBadWins,
      // goodGen);
      // if (goodGen) {
      // cntGood++;
      // sumGood += cntBadWins;
      // } else {
      // cntBad++;
      // sumBad += cntBadWins;
      // }
      
      if (cntBadWins >= 188) {
        // if (!goodGen) winCnt++;
        // else loseCnt++;
         System.out.printf("Case #%d: BAD\n", co);
        out.printf("Case #%d: BAD\n", co);
      } else {
        // if (goodGen) winCnt++;
        // else loseCnt++;
         System.out.printf("Case #%d: GOOD\n", co);
        out.printf("Case #%d: GOOD\n", co);
      }
    }
    
    // System.out.printf("Correct: %d\nWrong: %d\n", winCnt, loseCnt);
    //
    // double a1 = sumGood * 1. / cntGood;
    // double a2 = sumBad * 1. / cntBad;
    // System.out.printf("AVG GOOD = %.5f, AVG BAD = %.5f\n", a1, a2);
    // System.out.printf("Diff = %.5f Middle = %.5f\n", a2 - a1, (a1 + a2) / 2);
    //
    out.close();
  }
  static int[][] f;
  
  public static void readpre() throws IOException {
    f = new int[n][n];
    Scanner in = new Scanner(new File("cfdump.txt"));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        f[i][j] = in.nextInt();
  }
  
  public static void precomp() throws IOException {
    long st = System.currentTimeMillis();
    f = new int[n][n];
    for (int i = 0; i < trials; i++) {
      if ((i % (int) 1e6) == 0) System.out.printf("Completed %d trials\n", i);
      int[] arr = new int[n];
      for (int j = 0; j < n; j++)
        arr[j] = j;
      shuffleBad(arr);
      for (int j = 0; j < n; j++)
        f[arr[j]][j]++;
    }
    PrintWriter out = new PrintWriter(new File("cfdump.txt"));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        out.printf("%d ", f[i][j]);
      }
      out.println();
    }
    out.close();
    System.out.printf("Done in %d ms\n", System.currentTimeMillis() - st);
  }
  
  public static void shuffleGood(int[] s) {
    for (int i = 0; i < s.length; i++) {
      int r = rand.nextInt(s.length - i) + i;
      swap(s, i, r);
    }
  }
  
  public static void shuffleBad(int[] s) {
    for (int i = 0; i < s.length; i++) {
      int r = rand.nextInt(s.length);
      swap(s, i, r);
    }
  }
  
  public static void swap(int[] arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
  }
}
