package codejam.round1A;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by khuongnd on 4/26/14.
 */
public class ProperShuffle {

    int N;
    int a[] = new int[1000];

    void read(Scanner reader) {
        N = reader.nextInt();
        for (int i = 0; i < N; i++)
            a[i] = reader.nextInt();
    }

    String getRes() {
        //System.out.println(Arrays.toString(a));
        for (int i = 0; i < N; i++)
            if (a[i] == i)
                return "BAD";
        return "GOOD";
    }

    public static void main(String args[]) {
        try {
            String input = "C-small-attempt0.in";
            String output = "result.out";
            Scanner reader = new Scanner(
                    new BufferedInputStream(new FileInputStream(input), 10 * 1024 * 1024));
            PrintStream writer = new PrintStream(new FileOutputStream(output));
            int T = reader.nextInt();
            reader.nextLine();
            for (int t = 1; t <= T; t++) {
                ProperShuffle properShuffle = new ProperShuffle();
                properShuffle.read(reader);
                writer.println("Case #" + t + ": " + properShuffle.getRes());
            }
            writer.flush();
            writer.close();
            reader.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
