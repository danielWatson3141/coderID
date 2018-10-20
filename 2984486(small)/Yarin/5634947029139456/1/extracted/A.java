package round1a;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.Arrays;

public class A {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round1a/A-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round1a/A-small-attempt0.in"), new FileOutputStream("round1a/A-small-0.out"));
        io = new Kattio(new FileInputStream("round1a/A-large.in"), new FileOutputStream("round1a/A-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new A().solve(io);
        }
        io.close();
    }


    private long getLong(Kattio io) {
        String word = io.getWord();
        long l = 0;
        for(char c : word.toCharArray()) {
            l = l * 2 + c - '0';
        }
        return l;
    }

    private int countBits(long l) {
        if (l == 0) return 0;
        return (int) (l % 2) + countBits(l/2);
    }

    private void solve(Kattio io) {
        int N = io.getInt(), L = io.getInt();
        long a[] = new long[N], b[] = new long[N];
        for (int i = 0; i < N; i++) a[i] = getLong(io);
        for (int i = 0; i < N; i++) b[i] = getLong(io);
        Arrays.sort(a);
        Arrays.sort(b);

        int best = 1000;
        for (int i = 0; i < N; i++) {
            // match element 0 in a with element i in b
            long xor = a[0] ^ b[i];
            long c[] = new long[N];
            for (int j = 0; j < N; j++) {
                c[j] = a[j] ^ xor;
            }
            Arrays.sort(c);
            boolean ok = true;
            for (int j = 0; j < N; j++) {
                if (c[j] != b[j]) ok = false;
            }
            if (ok) best = Math.min(best, countBits(xor));
        }

        if (best == 1000) {
            io.println("NOT POSSIBLE");
        } else {
            io.println(best);
        }
    }

}
