package codejam.round1A;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Created by khuongnd on 4/26/14.
 */
public class FullBinary {

    static class Pair implements Comparable<Pair> {
        public int key, value;

        public Pair() {
            this.key = this.value = 0;
        }

        public Pair(int key, int value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public int compareTo(Pair o) {
            return o.value - value;
        }
    }

    static int maxn = 1001;
    int N;
    Pair F[][] = new Pair[maxn][3];
    int keep[] = new int[maxn];
    int trace[] = new int[maxn];
    List<Integer> order = new ArrayList<Integer>();
    List<Integer> edges[] = new List[maxn];

    public void read(Scanner reader) {
        N = reader.nextInt();
        for (int i = 1; i <= N; i++) {
            edges[i] = new ArrayList();
            for (int j = 0; j < 3; j++) {
                //System.out.println(i + " " + j);
                F[i][j] = new Pair();
            }
        }
        for (int i = 0; i < N - 1; i++) {
            int x = reader.nextInt();
            int y = reader.nextInt();
            edges[x].add(y);
            edges[y].add(x);
        }
    }

    public int forward(int x) {
        order.add(x);
        for (int i = 0; i < edges[x].size(); i++)
            if (trace[edges[x].get(i)] == 0) {
                int y = edges[x].get(i);
                trace[y] = x;
                forward(y);
                if (keep[y] > F[x][2].value)
                    F[x][2] = new Pair(y, keep[y]);
                Arrays.sort(F[x]);
            }
        if (F[x][1].value > 0)
            keep[x] = 1 + F[x][0].value + F[x][1].value;
        else
            keep[x] = 1;
        System.out.println(x + " " + keep[x]);
        for (int j = 0; j < 3; j++)
            System.out.print(" " + F[x][j].key + ":" + F[x][j].value);
        System.out.println();
        return keep[x];
    }

    public int reverse(int x) {
        int parent = trace[x];
        int noX = noKeep(parent, x);
        if (noX > F[x][2].value) {
            F[x][2] = new Pair(parent, noX);
            Arrays.sort(F[x]);
        }
        if (F[x][1].value > 0)
            keep[x] = 1 + F[x][0].value + F[x][1].value;
        else
            keep[x] = 1;
        System.out.println(x + " " + keep[x]);
        for (int j = 0; j < 3; j++)
            System.out.print(" " + F[x][j].key + ":" + F[x][j].value);
        System.out.println();
        return keep[x];
    }

    private int keepMax(int x, int y) {
        if (y == 0)
            return 1;
        else
            return 1 + x + y;
    }

    private int noKeep(int parent, int x) {
        if (F[parent][0].key == x)
            return keepMax(F[parent][1].value, F[parent][2].value);
        else if (F[parent][1].key == x)
            return keepMax(F[parent][0].value, F[parent][2].value);
        else
            return keepMax(F[parent][0].value, F[parent][1].value);
    }

    public int getRes() {
        trace[1] = 1;
        int best = forward(1);
        System.out.println();
        for (int i = 1; i < N; i++)
            best = Math.max(best, reverse(order.get(i)));
        return N - best;
    }

    public static void main(String args[]) {
        try {
            String input = "B-large.in";
            String output = "result.out";
            Scanner reader = new Scanner(
                    new BufferedInputStream(new FileInputStream(input), 10 * 1024 * 1024));
            PrintStream writer = new PrintStream(new FileOutputStream(output));
            int T = reader.nextInt();
            reader.nextLine();
            for (int t = 1; t <= T; t++) {
                FullBinary fullBinary = new FullBinary();
                fullBinary.read(reader);
                writer.println("Case #" + t + ": " + fullBinary.getRes());
            }
            writer.flush();
            writer.close();
            reader.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
