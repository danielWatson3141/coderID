import java.util.*;

public class A {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int c = 1; c <= T; c++) {
      int N = in.nextInt();
      int L = in.nextInt();
      int[] outlet = new int[N];
      int[] lights = new int[N];
      int minFlips = 999999;
      for (int i = 0; i < N; i++) {
        outlet[i] = Integer.parseInt(in.next(), 2);
      }
      for (int i = 0; i < N; i++) {
        lights[i] = Integer.parseInt(in.next(), 2);
      }
      Arrays.sort(lights);
      outer:
      for (int i = 0; i < 1 << L; i++) {
        int[] curr = new int[N];
        curr = Arrays.copyOf(outlet, outlet.length);
        for (int j = 0; j < N; j++) {
          curr[j] ^= i;
        }
        Arrays.sort(curr);
        /*System.out.println(i);
        for (int j = 0; j < N; j++) {
          System.out.print(curr[j] + " ");
        }
        System.out.println();
        for (int j = 0; j < N; j++) {
          System.out.print(lights[j] + " ");
        }
        System.out.println();*/
        for (int j = 0; j < N; j++) {
          if (curr[j] != lights[j]) {
            continue outer;
          }
        }
        minFlips = Math.min(minFlips, countOnes(i));
      }
      if (minFlips == 999999) {
        System.out.printf("Case #%d: NOT POSSIBLE\n", c);
      } else {
        System.out.printf("Case #%d: %d\n", c, minFlips);
      }
    }
    in.close();
  }
  
  private static int countOnes(int n) {
    int count = 0;
    while (n > 0) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  }
}
