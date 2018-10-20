import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ChargingChaos {

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(new FileReader("input/A-small-attempt2.in"));
        PrintWriter out = new PrintWriter("output/A-small-attempt2.out");

        int T = in.nextInt();
        int t = 0;

        while (++t <= T) {

            int N = in.nextInt();
            int L = in.nextInt();

            long[] outlets = new long[N];
            long[] devices = new long[N];

            for (int n = 0; n < N; ++n) outlets[n] = in.nextInt(2);
            for (int n = 0; n < N; ++n) devices[n] = in.nextInt(2);

            out.println("Case #" + t + ": " + solve(N, L, outlets, devices));

        }

        in.close();
        out.flush();
        out.close();

    }

    private static String solve(int N, int L, long[] outlets, long[] devices) {

        int minFlips = L+1;

        for (long mask = 0; mask < 1<<L; ++mask) {
            int cnt = popCount(mask);
            if (cnt < minFlips && isMatch(mask, outlets, devices))
                minFlips = cnt;
        }

        return minFlips <= L ? minFlips + "" : "NOT POSSIBLE";

    }

    private static boolean isMatch(long mask, long[] outlets, long[] devices) {

        long[] outletsFlip = new long[outlets.length];

        for (int i = 0; i < outlets.length; ++i)
            outletsFlip[i] = outlets[i] ^ mask;

        Arrays.sort(outletsFlip); Arrays.sort(devices);

        for (int i = 0; i < outlets.length; ++i)
            if (outletsFlip[i] != devices[i])
                return false;

        return true;

    }

    private static int popCount(long a) {
        int cnt = 0;
        while (a > 0) { cnt += a%2; a /= 2; }
        return cnt;
    }

}
