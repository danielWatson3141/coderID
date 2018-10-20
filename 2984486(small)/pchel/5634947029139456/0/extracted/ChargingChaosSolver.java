import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.Scanner;

public class ChargingChaosSolver {
    //    private static final String INPUT_FILE_NAME = "B-large.in";
                            private static final String INPUT_FILE_NAME = "A-small-attempt0.in";
//    private static final String INPUT_FILE_NAME = "input.in";
    //    private static final String OUTPUT_FILE_NAME = "B-large.out";
                        private static final String OUTPUT_FILE_NAME = "A-small-attempt0.out";
//    private static final String OUTPUT_FILE_NAME = "output.out";

    private int n;
    private int l;
    private byte[][] a;
    private byte[][] copyA;
    private byte[][] b;
    private byte[][] copyB;

    private int answer;
    private ByteArrayComparator c;

    public static void main(String[] args) throws IOException {
        StringBuilder builder = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(INPUT_FILE_NAME)))) {
            Scanner scanner = new Scanner(reader);
            scanner.useLocale(Locale.ENGLISH);
            int testCasesCount = scanner.nextInt();

            for (int i = 1; i <= testCasesCount; i++) {
                System.out.println("Case #" + i);
                scanner.nextLine();
                ChargingChaosSolver solver = new ChargingChaosSolver();

                solver.readData(scanner);
                int solution = solver.solve();

                builder.append("Case #");
                builder.append(i);
                builder.append(": ");
                builder.append(solution == Integer.MAX_VALUE ? "NOT POSSIBLE" : solution);
                builder.append("\r\n");
            }
        }

        try (BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT_FILE_NAME)
        ))) {
            writer.write(builder.toString());
        }
    }

    private int solve() {
        answer = Integer.MAX_VALUE;

        c = new ByteArrayComparator();
        Arrays.sort(b, c);

        for (int i = 0; i < (1 << l); i++) {
            int switches = 0;
            copyA = copy(a);
            for (int j = 0; j < l; j++) {
                if ((i & (1 << j)) > 0) {
                    switches++;
                    for (int k = 0; k < n; k++) {
                        copyA[k][j] = (byte) (1 - copyA[k][j]);
                    }
                }
            }
            if (equals(copyA, b)) {
                answer = Math.min(answer, switches);
            }
        }

        return answer;
    }

    private byte[][] copy(byte[][] x) {
        byte[][] result = new byte[n][];

        for (int i = 0; i < n; i++) {
            result[i] = Arrays.copyOf(x[i], l);
        }

        return result;
    }

    private boolean equals(byte[][] x, byte[][] sorted) {
        Arrays.sort(x, c);

        for (int i = 0; i < n; i++) {
            if (!Arrays.equals(x[i], sorted[i])) {
                return false;
            }
        }

        return true;
    }

    private void readData(Scanner scanner) {
        n = scanner.nextInt();
        l = scanner.nextInt();

        a = read(scanner);
        b = read(scanner);
    }

    private byte[][] read(Scanner scanner) {
        byte[][] x = new byte[n][];
        for (int i = 0; i < n; i++) {
            x[i] = new byte[l];
            String s = scanner.next();
            for (int j = 0; j < s.length(); j++) {
                x[i][j] = (byte) (s.charAt(j) == '1' ? 1 : 0);
            }
        }
        return x;
    }

    private static class ByteArrayComparator implements Comparator<byte[]> {
        @Override
        public int compare(byte[] left, byte[] right) {
            for (int i = 0, j = 0; i < left.length && j < right.length; i++, j++) {
                int a = (left[i] & 0xff);
                int b = (right[j] & 0xff);
                if (a != b) {
                    return a - b;
                }
            }
            return left.length - right.length;
        }
    }
}
