import java.util.*;

public class A {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    StringBuilder output = new StringBuilder();
    int tests = in.nextInt();
    for (int test = 1; test <= tests; ++test) {
      output.append(String.format("Case #%d: ", test));
      int n = in.nextInt();
      int len = in.nextInt();
      long[] devices = new long[n];
      long[] outlets = new long[n];
      for (int i = 0; i < n; ++i) {
        devices[i] = Long.parseLong(in.next(), 2);
      }
      for (int i = 0; i < n; ++i) {
        outlets[i] = Long.parseLong(in.next(), 2);
      }
      int min = -1;
      Arrays.sort(devices);
      for (int i = 0; i < n; ++i) {
        long[] changed = new long[n];
        long flipset = devices[0] ^ outlets[i];
        int cost = Long.bitCount(flipset);
        for (int j = 0; j < n; ++j) {
          changed[j] = outlets[j] ^ flipset;
        }
        Arrays.sort(changed);
        if (Arrays.equals(devices, changed)) {
          if (min == -1 || cost < min) {
            min = cost;
          }
        }
      }
      if (min == -1) {
        output.append("NOT POSSIBLE\n");
      } else {
        output.append(min);
        output.append('\n');
      }
    }
    System.out.print(output);
  }
}