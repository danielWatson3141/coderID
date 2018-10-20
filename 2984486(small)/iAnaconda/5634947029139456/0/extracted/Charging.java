package codejam.round1A;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by khuongnd on 4/26/14.
 */
public class Charging {

    int N;
    int L;
    String ins[];
    Set<String> outs;
    int best = Integer.MAX_VALUE;


    public void read(Scanner reader) {
        N = reader.nextInt();
        L = reader.nextInt();
        ins = new String[N];
        outs = new HashSet<String>();
        for (int i = 0; i < N; i++)
            ins[i] = reader.next();
        for (int i = 0; i < N; i++)
            outs.add(reader.next());
    }

    public boolean[] mask(String in, String out) {
        boolean[] res = new boolean[L];
        for (int i = 0; i < L; i++)
            res[i] = (in.charAt(i) != out.charAt(i));
        return res;
    }

    public int count_bits(boolean mask[]) {
        int res = 0;
        for (int i = 0; i < L; i++)
            if (mask[i])
                res++;
        return res;
    }

    public void process() {
        for (int i = 0; i < N; i++)
            for (String out : outs) {
                boolean bit_mask[] = mask(ins[i], out);
                int counter = count_bits(bit_mask);
                if (check(bit_mask) && counter < best)
                    best = counter;
                //System.out.println();
            }
    }

    private boolean check(boolean[] mask) {
        for (int i = 0; i < N; i++) {
            if (!check(ins[i], mask))
                return false;
        }
        return true;
    }

    private boolean check(String in, boolean[] mask) {
        StringBuilder s = new StringBuilder(L);
        for (int i = 0; i < L; i++)
            if (mask[i]) {
                if (in.charAt(i) == '0')
                    s.append('1');
                else
                    s.append('0');
            } else
                s.append(in.charAt(i));
        //System.out.println(s);
        return outs.contains(s.toString());
    }

    public String getRes() {
        if (best == Integer.MAX_VALUE)
            return "NOT POSSIBLE";
        else
            return "" + best;
    }


    public static void main(String args[]) {
        try {
            String input = "A-small-attempt0.in";
            String output = "result.out";
            Scanner reader = new Scanner(
                    new BufferedInputStream(new FileInputStream(input), 10 * 1024 * 1024));
            PrintStream writer = new PrintStream(new FileOutputStream(output));
            int T = reader.nextInt();
            reader.nextLine();
            for (int t = 1; t <= T; t++) {
                Charging charging = new Charging();
                charging.read(reader);
                charging.process();
                writer.println("Case #" + t + ": " + charging.getRes());
            }
            writer.flush();
            writer.close();
            reader.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
