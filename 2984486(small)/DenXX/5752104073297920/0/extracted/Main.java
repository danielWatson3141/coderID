//package denxx;

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

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            int swap = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (a[i] > a[j])
                        ++swap;
                }
            }
            if (swap < (n - 1) * (n - 2) / 4) {
                System.out.println("Case #" + t + ": BAD");
            } else {
                System.out.println("Case #" + t + ": GOOD");
            }
        }
    }
}