import java.util.Random;
import java.util.Scanner;

public class C {

    public static void main(String[] args) {

        double[][] good = goodFreq();
        double[][] bad = badFreq();

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            System.out.printf("Case #%d: ", t);
            solve(in, good, bad);
        }

    }

    public static double[][] badFreq() {

        int N = 1000;
        int[] a = new int[N];

        // likelihood of [i][position(i)]
        double[][] freq = new double[N][N];

        double testNums = 100000;
        for (int lol = 0; lol < testNums; lol++) {
            for (int i = 0; i < N; i++)
                a[i] = i;

            Random r = new Random();
            for (int i = 0; i < N; i++) {
                int p = r.nextInt(N);
                int temp = a[p];
                a[p] = a[i];
                a[i] = temp;
            }

            for (int i = 0; i < N; i++) {
                freq[a[i]][i]++;
            }
        }

        for (int i = 0; i < freq.length; i++) {
            for (int j = 0; j < freq[0].length; j++) {
                freq[i][j] = freq[i][j] / testNums;
                //                System.out.print(freq[i][j] / testNums + " ");
            }
            //            System.out.println();
        }

        return freq;
    }

    public static double[][] goodFreq() {

        int N = 1000;
        int[] a = new int[N];

        // likelihood of [i][position(i)]
        double[][] freq = new double[N][N];

        double testNums = 100000;
        for (int lol = 0; lol < testNums; lol++) {
            for (int i = 0; i < N; i++)
                a[i] = i;

            Random r = new Random();
            for (int i = 0; i < N; i++) {
                int p = r.nextInt(N - i) + i;
                int temp = a[p];
                a[p] = a[i];
                a[i] = temp;
            }

            for (int i = 0; i < N; i++) {
                freq[a[i]][i]++;
            }
        }

        for (int i = 0; i < freq.length; i++) {
            for (int j = 0; j < freq[0].length; j++) {
                freq[i][j] = freq[i][j] / testNums;
                //                System.out.print(freq[i][j] / testNums + " ");
            }
            //            System.out.println();
        }

        return freq;
    }

    static Random r = new Random();

    public static void solve(Scanner in, double[][] good, double[][] bad) {
        int N = in.nextInt();

        int[] a = new int[N];

        double pGood = 0;
        double pBad = 0;
        for (int i = 0; i < N; i++) {
            a[i] = in.nextInt();
            pGood += good[a[i]][i];
            pBad += bad[a[i]][i];
        }

        double outputGood = pGood / (pGood + pBad);
        double sample = r.nextDouble();

        if (sample <= outputGood) {
            System.out.println("GOOD");
        }
        else {
            System.out.println("BAD");
        }

    }
}
