import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class a {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("a.in"));
    PrintWriter out = new PrintWriter(new File("a.out"));
    int cases = in.nextInt();
    for (int co = 1; co <= cases; co++) {
      int n = in.nextInt();
      int l = in.nextInt();
      String[] dev = new String[n];
      for (int i = 0; i < n; i++)
        dev[i] = in.next();
      Arrays.sort(dev);
      
      char[][] sw = new char[n][l];
      for (int i = 0; i < n; i++)
        sw[i] = in.next().toCharArray();
      
      int min = (int) 1e9;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          String[] other = buildSWSet(dev[i], sw[j], sw);
          boolean works = true;
          for (int k = 0; k < n && works; k++)
            if (!dev[k].equals(other[k])) works = false;
          if (works) {
            boolean[] ff = flipSet(dev[i], sw[j]);
            int cnt = 0;
            for (boolean aa : ff)
              if (aa) cnt++;
            min = Math.min(min, cnt);
          }
        }
      }
      if (min == (int) 1e9) {
        System.out.printf("Case #%d: NOT POSSIBLE\n", co);
        out.printf("Case #%d: NOT POSSIBLE\n", co);
      } else {
        System.out.printf("Case #%d: %d\n", co, min);
        out.printf("Case #%d: %d\n", co, min);
      }
    }
    out.close();
  }
  
  static boolean[] flipSet(String dev, char[] match) {
    boolean[] flip = new boolean[dev.length()];
    for (int i = 0; i < match.length; i++)
      if (match[i] != dev.charAt(i)) flip[i] = true;
    return flip;
  }
  
  static String[] buildSWSet(String dev, char[] match, char[][] sw) {
    boolean[] flip = flipSet(dev, match);
    String[] ret = new String[sw.length];
    for (int i = 0; i < sw.length; i++) {
      char[] cur = new char[sw[i].length];
      for (int j = 0; j < cur.length; j++)
        cur[j] = flip[j] ? flip(sw[i][j]) : sw[i][j];
      ret[i] = new String(cur);
    }
    Arrays.sort(ret);
    return ret;
  }
  
  static char flip(char c) {
    return c == '0' ? '1' : '0';
  }
}
