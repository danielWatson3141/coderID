import java.util.*;

class A {
  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();
    for (int caseNo = 1; caseNo <= T; caseNo++) {
      int N = cin.nextInt();
      int L = cin.nextInt();
      int[] a = new int[N];
      int[] b = new int[N];
      for (int i = 0; i < N; i++) {
        String tmp = cin.next();
        a[i] = Integer.parseInt(tmp, 2);
      }
      for (int i = 0; i < N; i++) {
        String tmp = cin.next();
        b[i] = Integer.parseInt(tmp, 2);
      }

      int ans = Integer.MAX_VALUE;
      for (int i = 0; i < N; i++) {
        int x = a[0] ^ b[i];
        ArrayList<Integer> A = new ArrayList<Integer>();
        ArrayList<Integer> B = new ArrayList<Integer>();
        for (int c : a)
          A.add(c);
        for (int c : b)
          B.add(c^x);
        Collections.sort(A);
        Collections.sort(B);
        if (A.equals(B)) {
          ans = Math.min(ans, Integer.bitCount(x));
        }
      }
      if (ans == Integer.MAX_VALUE)
        System.out.format("Case #%d: NOT POSSIBLE\n", caseNo);
      else
        System.out.format("Case #%d: %d\n", caseNo, ans);
    }
  }
}
