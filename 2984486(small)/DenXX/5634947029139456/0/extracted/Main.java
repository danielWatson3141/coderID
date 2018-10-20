
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.util.NoSuchElementException;
import java.io.Writer;
import java.math.BigInteger;
import java.io.FilenameFilter;
import java.io.InputStream;
import java.util.Scanner;

public class Main {

    private static int countBits(int mask) {
        int res = 0;
        while (mask != 0) {
            mask = (mask & (mask - 1));
            ++res;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            int n = in.nextInt();
            int l = in.nextInt();
            char[][] c = new char[n][l];
            for (int i = 0; i < n; ++i) {
                c[i] = in.next().toCharArray();
            }
            String[] r = new String[n];
            for (int i = 0; i < n; ++i) {
                r[i] = in.next();
            }
            Arrays.sort(r);

            int res = Integer.MAX_VALUE;

            for (int mask = 0; mask < (1 << l); ++mask) {
                for (int i = 0; i < l; ++i) {
                    if ((mask & (1 << i)) != 0) {
                        for (int j = 0; j < n; ++j) {
                            c[j][i] = (c[j][i] == '0') ? '1' : '0';
                        }
                    }
                }
                String[] cc = new String[n];
                for (int i = 0; i < n; ++i) {
                    StringBuilder el = new StringBuilder("");
                    for (int j = 0; j < l; ++j) {
                        el.append(c[i][j]);
                    }
                    cc[i] = el.toString();
                }
                Arrays.sort(cc);
                boolean ok = true;
                for (int j = 0; j < n; ++j) {
                    if (!r[j].equals(cc[j])) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    res = Math.min(res, countBits(mask));
                }


                for (int i = 0; i < l; ++i) {
                    if ((mask & (1 << i)) != 0) {
                        for (int j = 0; j < n; ++j) {
                            c[j][i] = (c[j][i] == '0') ? '1' : '0';
                        }
                    }
                }
            }

            if (res == Integer.MAX_VALUE) {
                System.out.println("Case #" + t + ": NOT POSSIBLE");
            } else {
                System.out.println("Case #" + t + ": " + res);
            }

        }
    }
}