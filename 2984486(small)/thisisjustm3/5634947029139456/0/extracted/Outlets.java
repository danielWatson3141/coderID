import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

/**
 * @author arshsab
 * @since 04 2014
 */

public class Outlets {
    public static void main(String... args) throws IOException {
        final String FILE_NAME = "outlet";

        BufferedReader br = new BufferedReader(new FileReader(FILE_NAME + ".in"));

        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(FILE_NAME + ".out")));

        final int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            String[] log = br.readLine().split(" ");

            final int N = Integer.parseInt(log[0]);
            final int L = Integer.parseInt(log[1]);

            String[] contained = br.readLine().split(" ");
            String[] required = br.readLine().split(" ");

            int attempt = recurse(contained, required, 0, 0, L);

            switch (attempt) {
                case Integer.MAX_VALUE:
                    out.println("Case #" + t + ": NOT POSSIBLE");
                    break;
                default:
                    out.println("Case #" + t + ": " + attempt);
            }

            System.out.println("-----");
        }

        out.flush();
        out.close();
    }

    private static int recurse(String[] contained, String[] required, int changes, int pos, int L) {
        if (pos == L) {
            System.out.println(Arrays.toString(contained));
            System.out.println(Arrays.toString(required));

            Set<String> cont = new HashSet<>();

            Collections.addAll(cont, contained);

            for (String req : required) {
                if (cont.contains(req)) {
                    cont.remove(req);
                } else {
                    changes = Integer.MAX_VALUE;
                }
            }

            System.out.println(changes);

            return changes;
        }

        String[] flipped = flip(contained, pos);

        return Math.min(recurse(contained, required, changes, pos + 1, L),
                recurse(flipped, required, changes + 1, pos + 1, L));
    }


    private static String[] flip(String[] strings, int pos) {
        String[] ret = new String[strings.length];

        for (int i = 0; i < ret.length; i++) {
            String copy = strings[i].substring(0, pos)
                    + (strings[i].charAt(pos) == '1' ? '0' : '1')
                    + strings[i].substring(pos + 1);

            ret[i] = copy;
        }

        System.out.println("Flipped " + Arrays.toString(strings) + " into " + Arrays.toString(ret));

        return ret;
    }
}
