package codejam.mc.y2014.r1a;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;
import java.math.*;

import static java.lang.Math.*;

public class A
{
  static int L;
  static int N;
  static char[][] dev;
  static char[][] florg;
  static int mincount = Integer.MAX_VALUE;
  static boolean pos = false;

  static void solve() throws Throwable
  {
    int T = sc.nextInt();
    for (int i = 1; i <= T; i++)
    {
      //
      pos = false;
      mincount = Integer.MAX_VALUE;
      N = sc.nextInt();
      L = sc.nextInt();
      florg = new char[N][L];
      dev = new char[N][L];
      for (int j = 0; j < N; j++)
        florg[j] = sc.next().toCharArray();
      for (int j = 0; j < N; j++)
        dev[j] = sc.next().toCharArray();

      match(deepCopy(florg), 0, 0);

      if (pos)
        out("Case #" + i + ": " + mincount);
      else
        out("Case #" + i + ": NOT POSSIBLE");
    }
  }

  static char[][] deepCopy(char[][] f)
  {
    char[][] result = new char[f.length][];
    for (int i = 0; i < f.length; i++)
      result[i] = Arrays.copyOf(f[i], f[i].length);

    return result;
  }

  static void match(char[][] fl, int p, int count) throws Throwable
  {
    // check match
    List<String> flows = new ArrayList<>();
    List<String> devs = new ArrayList<>();
    for (int j = 0; j < N; j++)
    {
      char[] d = dev[j];
      char[] f = fl[j];

      String ds = "";
      String fs = "";
      for (int i = 0; i < p; i++)
      {
        ds += d[i];
        fs += f[i];
      }
      devs.add(ds);
      flows.add(fs);
    }
    for (String d : devs)
    {
      if (!flows.contains(d))
        return;
      else
        flows.remove(d);
      // if (!flows.remove(d))
      // return;
    }
    // check previous
    if (p == L)
    {
      pos = true;
      mincount = Math.min(mincount, count);
      // out(Arrays.deepToString(florg));
      // out(Arrays.deepToString(fl));
      // out(Arrays.deepToString(dev));
      return;
    }

    int onef = 0;
    int oned = 0;
    int zerf = 0;
    int zerd = 0;
    for (int j = 0; j < N; j++)
    {
      char f = fl[j][p];
      if (f == '0')
        zerf++;
      else
        onef++;
      char d = dev[j][p];
      if (d == '0')
        zerd++;
      else
        oned++;
    }
    if (onef != oned && onef != zerd)
      return;

    // ok
    if (onef == oned)
    {
      char[][] flcop = deepCopy(fl);
      match(flcop, p + 1, count);
    }
    // switch
    if (onef == zerd)
    {
      char[][] flcop = deepCopy(fl);
      for (int j = 0; j < N; j++)
      {
        char c = flcop[j][p];
        if (c == '0')
          flcop[j][p] = '1';
        else
          flcop[j][p] = '0';
      }

      match(flcop, p + 1, count + 1);
    }

  }

  // =====================
  // no changes
  // =====================

  public static void main(String[] args) throws Throwable
  {
    long start = System.currentTimeMillis();
    Properties prop = new Properties();
    ClassLoader cl = A.class.getClassLoader();
    prop.load(cl.getResourceAsStream("build.properties"));
    String task = prop.getProperty("input");
    sc = new Scanner(new File(prop.getProperty("download.dir") + task + ".in"));
    sc.useLocale(Locale.US);
    pw = new PrintWriter(prop.getProperty("upload.dir") + task + ".out");
    solve();
    sc.close();
    pw.flush();
    pw.close();
    float dur = ((float) (System.currentTimeMillis() - start)) / 1000f;
    System.out.println("Finished in : " + dur + " sek.");
  }

  static void out(Object result) throws Exception
  {
    System.out.println(result.toString());
    pw.println(result.toString());
  }

  static PrintWriter pw;
  static Scanner sc;
}