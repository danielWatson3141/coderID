import java.io.*;
import java.util.*;

/**
 * Created by Rafal on 4/12/14.
 */
public class C {

    public static void main(String[] args) {
        try {
//            for (int i = 0; i < 100; i++) {
//                generateGood();
//                generateBad();
//            }
            InputStream in = new FileInputStream("c:/projekty/codejam/src/C.in");
            Scanner scanner = new Scanner(in);
            OutputStream out = new FileOutputStream("c:/projekty/codejam/src/C.out");
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(out, "utf8"));
            int t = scanner.nextInt();
            for (int i = 0; i < t; i++) {
                solve(scanner, i+1, writer);
            }
            writer.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
            e.printStackTrace();
        }
    }


    public static void solve(Scanner scanner, int t, PrintWriter out) {
        scanner.nextInt();
        int a[] = new int[1000];
        double d = 0;
        for (int i = 0; i < 1000; i++) {
            a[i] = scanner.nextInt();
            d += (double)(i+1) * a[i];
        }
        String resultTxt = "";
        if (d < 2.54e8) {
            resultTxt = "GOOD";
        } else {
            resultTxt = "BAD";
        }
        System.out.println("Case #" + t + ": " + resultTxt);
        out.println("Case #" + t + ": " + resultTxt);
    }


//    public static void generateGood() {
//        int n = 1000;
//        int a[] = new int[n];
//        double d = 0;
//        for (int k = 0; k < n; k++) {
//            a[k] = k;
//            d += (double)(i+1) * a[i];
//        }
//
//        Random r = new Random(System.currentTimeMillis());
//        for (int k = 0; k < n; k++) {
//            int idx = k + r.nextInt(n - k);
//            int x = a[k];
//            a[k] = a[idx];
//            a[idx] = x;
//        }
//
//        double d = 0;
//        for (int i = 0; i < a.length; i++) {
//            d += (double)(i+1) * a[i];
//
//        }
//        System.out.println(d);
//    }
//    public static void generateBad() {
//        int n = 1000;
//        int a[] = new int[n];
//        for (int k = 0; k < n; k++) {
//            a[k] = k;
//        }
//
//        Random r = new Random(System.currentTimeMillis());
//        for (int k = 0; k < n; k++) {
//            int idx = r.nextInt(n);
//            int x = a[k];
//            a[k] = a[idx];
//            a[idx] = x;
//        }
//
//        double d = 0;
//        for (int i = 0; i < a.length; i++) {
//            d += (double)(i+1) * a[i];
//
//        }
//        System.out.println(d);
//    }
}
