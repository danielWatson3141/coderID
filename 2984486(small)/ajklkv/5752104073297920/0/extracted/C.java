package a1;

import java.io.File;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Scanner;

public class C {
    private static int random(int a, int b) {
        int r = (int) (Math.random() * (b - a));
        return r + a;
    }
    private static void swap(int[] arr, int i, int j) {
        int a = arr[i];
        arr[i] = arr[j];
        arr[j] = a;
    }
    private static void fill(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }
    }
    private static void good(int[] arr) {
        fill(arr);
        for (int i = 0; i < arr.length; i++) {
            int p = random(i, arr.length);
            swap(arr, p, i);
        }
    }

    private static void bad(int[] arr) {
        fill(arr);
        for (int i = 0; i < arr.length; i++) {
            int p = random(0, arr.length);
            swap(arr, p, i);
        }
    }

    private static double evaluate(int[] arr) {
        double r = Math.log(2)*arr.length;
        double eval = 0;
        for(int i = 0; i < arr.length; i++) {
            int k = arr[i];

            if (i <= k - 1) {
                eval += 5.0*i/arr.length;
            } else {
                eval += 1.0/(arr.length - i);
            }
        }
        return eval;
    }

    public static void main(String[] args) throws Exception {
        /*int[] arr = new int[1000];

        int N = 120;
        double allBad = 0;
        double allGood = 0;
        for (int i = 0; i < N; i++) {
            //bad(arr);
            good(arr);
            allGood += evaluate(arr);
            bad(arr);
            allBad += evaluate(arr);
            //System.out.println(evaluate(arr));
        }
        System.out.println(allGood / N);
        System.out.println(allBad / N);*/

        File file = new File("a1/c.in");
        Writer writer = new FileWriter(new File(file.getCanonicalPath().replace(".in", ".out")));
        Scanner scanner = new Scanner(file);

        int[] arr = new int[1000];
        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = scanner.nextInt();
            for (int i = 0; i < arr.length; i++) {
                arr[i] = scanner.nextInt();
            }

            double e = evaluate(arr);
            String a = e < 880 ? "GOOD" : "BAD";
            writer.write("Case #" + t + ": " + a + "\n");
        }

        writer.close();
        scanner.close();
    }
}
