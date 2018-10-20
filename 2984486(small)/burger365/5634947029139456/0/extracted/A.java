import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by burger on 4/26/14.
 */
public class A {
    public String solveSmall(int N, int L, String[] flows, String[] devices) {
        int[] f = new int[N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < L; j++)
                if (flows[i].charAt(j) == '1')
                    f[i] |= (1 << (L - j - 1));

        int[] d = new int[N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < L; j++)
                if (devices[i].charAt(j) == '1')
                    d[i] |= (1 << (L - j - 1));

        int res = Integer.MAX_VALUE;
        for (int mask = 0; mask < (1 << L); mask++) {
            int[] cf = new int[N];
            for (int i = 0; i < N; i++)
                cf[i] = f[i] ^ mask;

            boolean ok = true;
            for (int i = 0; i < N && ok; i++) {
                boolean found = false;
                for (int j = 0; j < N && !found; j++) {
                    if (cf[i] == d[j])
                        found = true;
                }
                if (!found) ok = false;
            }

            if (ok) {
                int count = 0;
                for (int i = 0; i < L; i++)
                    if ((mask & (1 << i)) != 0)
                        count++;
                res = Math.min(res, count);
            }
        }

        return (res != Integer.MAX_VALUE) ? String.valueOf(res) : "NOT POSSIBLE";
    }

    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("small.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("answer.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int L = in.nextInt();
            in.nextLine();

            String[] flows = in.nextLine().split(" ");
            String[] devices = in.nextLine().split(" ");

            out.write("Case #" + t + ": " + new A().solveSmall(N, L, flows, devices) + "\n");
        }

        out.close();
    }
}
