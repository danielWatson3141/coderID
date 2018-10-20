//package denxx;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.lang.reflect.Array;
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

    static boolean ok(char[][] c, String[] r, int mask) {
        int n = c.length;
        int l = c[0].length;

        String[] cc = new String[n];
        for (int i = 0; i < n; ++i) {
            StringBuilder str = new StringBuilder();
            for (int j = 0; j < l; ++j) {
                if ((mask & (1 << j)) != 0) {
                    str.append(c[i][j] == '1' ? '0' : '1');
                } else {
                    str.append(c[i][j]);
                }
            }
            cc[i] = str.toString();
        }
        Arrays.sort(cc);
        for (int i = 0; i < n; ++i)
            if (!cc[i].equals(r[i]))
                return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            int n = in.nextInt();
            int l = in.nextInt();
            char[][] c = new char[n][];
            for (int i = 0; i < n; ++i) {
                c[i] = in.next().toCharArray();
            }
            String[] r = new String[n];
            for (int i = 0; i < n; ++i) {
                r[i] = in.next();
            }
            Arrays.sort(r);
            int res = Integer.MAX_VALUE;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int mask = 0;
                    int count = 0;
                    for (int k = 0; k < l; ++k) {
                        if (c[i][k] != r[j].charAt(k)) {
                            mask |= (1 << k);
                            ++count;
                        }
                    }
                    if (ok(c, r, mask)) {
                        res = Math.min(res, count);
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