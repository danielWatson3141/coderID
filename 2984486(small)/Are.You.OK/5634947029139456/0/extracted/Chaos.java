import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Chaos {

    static int N, L;
    static State deviceState;
    static State outletState;

    static class State {
        String[] s;

        State() {
            s = new String[N];
        }

        State change(int i) {
            State news = new State();
            for (int j = 0; j < N; j++) {
                news.s[j] = change(s[j], i);
            }
            news.sort();
            return news;
        }

        void sort() {
            Arrays.sort(s);
        }

        static String change(String s, int i) {
            String news = s.substring(0, i) + (s.charAt(i) == '0' ? '1' : '0')
                    + s.substring(i + 1);
            return news;
        }

        @Override
        public boolean equals(Object aotherState) {
            State as = (State) aotherState;
            for (int j = 0; j < N; j++) {
                if (!s[j].equals(as.s[j])) {
                    return false;
                }
            }
            return true;
        }
    }

    static State readState(Scanner sc) {
        State st = new State();
        for (int i = 0; i < N; i++) {
            st.s[i] = sc.next();
        }
        st.sort();
        return st;
    }

    static int result = Integer.MAX_VALUE;

    static void go(State s, int i, int changed) {
        if (i == L) {
            if (s.equals(deviceState)) {
                result = Math.min(result, changed);
            }
            
            return;
        }
        go(s, i + 1, changed);
        s = s.change(i);
        go(s, i + 1, changed + 1);
        s = s.change(i);
    }

    static int resove() {
        result = Integer.MAX_VALUE;
        go(outletState, 0, 0);
        return result;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc;
        if (args != null && args.length > 0 && args[0].equals("-d")) {
            sc = new Scanner(new File(args[1]));
        } else {
            sc = new Scanner(System.in);
        }

        int caseIndex = 0;
        int nCase = sc.nextInt();
        while (nCase-- > 0) {
            N = sc.nextInt();
            L = sc.nextInt();
            outletState = readState(sc);
            deviceState = readState(sc);
            resove();
            if (result == Integer.MAX_VALUE)
                System.out.printf("Case #%d: NOT POSSIBLE\n", ++caseIndex);
            else
                System.out.printf("Case #%d: %d\n", ++caseIndex, result);
        }
    }
}