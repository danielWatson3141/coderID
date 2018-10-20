import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Asmall {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(args.length == 0 ? System.in : new FileInputStream(args[0]));
        IntStream.rangeClosed(1, sc.nextInt()).forEach( tc -> {
			int res = -1;
			// double res = 0.0;
			// String res = "";
			int n = sc.nextInt();
			int len = sc.nextInt();
			//int nc = sc.nextInt();
			long[] ols = new long[n];
			long[] devs = new long[n];
            //ArrayList xx = new ArrayList();
            //ArrayList yy = new ArrayList();

            IntStream.range(0, n).forEach( i -> {
                ols[i] = Integer.parseInt(sc.next(), 2);
            });

            IntStream.range(0, n).forEach( i -> {
                devs[i] = Integer.parseInt(sc.next(), 2);
            });

            for (int i = 0; i < 1<<len; i++) {
                boolean allFound = true;
                for (long ol : ols) {
                    boolean found = false;
                    for (long dev : devs) {
                        found |= ((ol ^ i) == dev);
                    }
                    allFound &= found;
                }
                if (allFound) {
                    res = i;
                    break;
                }
            }
            String sres = (res < 0) ? "NOT POSSIBLE" : ("" + Integer.bitCount(res));

			System.out.printf("Case #%d: %s%n", tc, sres);
			// System.out.printf("Case #%d: %.6f%n", tc, res);
			// System.out.printf("Case #%d: %s%n", tc, res);
			// System.out.printf("Case #%d: %d %d%n", tc, x, y);
        }); //tc
	}

    public static void p(Object s) {System.out.println(s);}
    public static void pf(String f, Object... aa) {System.out.printf(f, aa);}
}
