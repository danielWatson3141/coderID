import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

/**
 * @author khelman
 */
public class Charging {

    private static void loadOutlets(long[] outlets, String[] input, int n, int l) {
        for (int i = 0; i < n; i++) {
            outlets[i] = loadOutlet(input[i], l);
        }
    }

    private static long loadOutlet(String s, int l) {

        long ret = 0;

        for (int i = 0; i < l; i++) {
            ret *= 2l;
            if (s.charAt(i) == '1') {
                ret += 1l;
            }
        }

        return ret;
    }

    private static int countOnes(long in) {
        int ret = 0;

        while (in > 0l) {
            if (in % 2l == 1) {
                ret++;
            }

            in = in / 2l;
        }

        return ret;
    }

    public static void main(String... args) throws IOException {
        FileReader fr = new FileReader("d:\\charging.in");
        BufferedReader br = new BufferedReader(fr);
        String s = br.readLine();

        FileWriter f0 = new FileWriter("d:\\charging.out");

        int t = Integer.parseInt(s.trim());

        for (int i = 1; i <= t; i++) {
            s = br.readLine();
            String[] elems = s.split(" ");

            int n = Integer.parseInt(elems[0]);
            int l = Integer.parseInt(elems[1]);

            long[] outlets = new long[n];
            long[] devices = new long[n];

            s = br.readLine();
            elems = s.split(" ");

            loadOutlets(outlets, elems, n, l);

            s = br.readLine();
            elems = s.split(" ");

            loadOutlets(devices, elems, n, l);

            HashSet<Long> outletsSet = new HashSet<Long>(n);
            for (int j = 0; j < n; j++) {
                outletsSet.add(outlets[j]);
            }

            long mask = 0;
            int min = l + 1;
            while (true) {

                boolean matched = true;

                for (int j = 0; j < n; j++) {
                    if(!outletsSet.contains(devices[j]^mask)) {
                        matched = false;
                        break;
                    }
                }

                if (matched && countOnes(mask) < min) {
                    min = countOnes(mask);
                }

                if (countOnes(mask) == l) {
                    break;
                }

                mask++;
            }

            if (min <= l) {
                System.out.println("Case #" + i + ": " + min);

                f0.write("Case #" + i + ": " + min + "\r\n");
            } else {
                System.out.println("Case #" + i + ": NOT POSSIBLE");

                f0.write("Case #" + i + ": NOT POSSIBLE" + "\r\n");
            }
        }

        fr.close();
        f0.close();

    }

}
