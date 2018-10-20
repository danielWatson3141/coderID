import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class A {
    static final Scanner in = new Scanner(System.in);
    static final PrintStream out = System.out;

    public static void main(String[] args) {
        int t = in.nextInt();
        for (int i = 0; i < t; ++i) {
            solve(i + 1);
        }
    }

    private static Flow nextFlow(int l) {
        Flow result = new Flow(l);

        String s = in.next();

        for (int i = 0; i < l; ++i) {
            result.data[i] = s.charAt(i) - '0';
        }

        return result;
    }

    private static void solve(int testCase) {
        int n = in.nextInt();
        int l = in.nextInt();

        HashSet<Flow> initial = new HashSet<>();
        HashSet<Flow> required = new HashSet<>();

        for (int i = 0; i < n; ++i) {
            initial.add(nextFlow(l));
        }

        for (int i = 0; i < n; ++i) {
            required.add(nextFlow(l));
        }

        int result = solve(l, initial, required);
        out.print("Case #");
        out.print(testCase);
        out.print(": ");

        if (result == Integer.MAX_VALUE) {
            out.println("NOT POSSIBLE");
        } else {
            out.println(result);
        }
    }

    private static int solve(int length, HashSet<Flow> initial, HashSet<Flow> required) {
        long limit = 1 << length;
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < limit; ++i) {
            min = Math.min(min, solve(initial, required, i));
        }

        return min;
    }

    private static int solve(HashSet<Flow> initial, HashSet<Flow> required, int changes) {
        if (change(initial, changes).equals(required)) {
            return Integer.bitCount(changes);
        }

        return Integer.MAX_VALUE;
    }

    private static HashSet<Flow> change(HashSet<Flow> initial, int changes) {
        HashSet<Flow> result = new HashSet<>();

        for (Flow flow : initial) {
            result.add(flow.change(changes));
        }

        return result;
    }

    static class Flow {
        final int[] data;

        Flow(int l) {
            data = new int[l];
        }

        public Flow change(int changes) {
            int count = data.length;
            Flow result = new Flow(count);

            for (int i = 0; i < count; ++i) {
                if ((changes & (1 << i)) != 0) {
                    result.data[i] = (data[i] + 1) % 2;
                } else {
                    result.data[i] = data[i];
                }
            }

            return result;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Flow flow = (Flow) o;

            if (!Arrays.equals(data, flow.data)) return false;

            return true;
        }

        @Override
        public int hashCode() {
            return data != null ? Arrays.hashCode(data) : 0;
        }
    }
}
