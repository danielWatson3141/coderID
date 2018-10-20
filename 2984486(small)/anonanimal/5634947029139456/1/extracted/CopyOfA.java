import java.util.Scanner;

public class CopyOfA {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            System.out.printf("Case #%d: ", t);
            solve(in);
        }

    }

    public static void solve(Scanner in) {
        int N = in.nextInt();
        int L = in.nextInt();

        String noGood = "NOT POSSIBLE";

        char[][] flow = new char[N][L];
        char[][] req = new char[N][L];

        for (int i = 0; i < N; i++) {
            flow[i] = in.next().toCharArray();
        }
        for (int i = 0; i < N; i++) {
            req[i] = in.next().toCharArray();
        }

        String[][] toChange = new String[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                String res = "";
                for (int k = 0; k < L; k++) {
                    if (req[i][k] != flow[j][k])
                        res += '1';
                    else
                        res += '0';
                }
                toChange[i][j] = res;
            }
        }

        int MAX = 999999999;
        int ans = MAX;

        // Match up the 0'th item with outlet i and
        // let the others fall into place
        for (int i = 0; i < N; i++) {

            int cost = 0;
            for (int j = 0; j < toChange[0][i].length(); j++) {
                if (toChange[0][i].charAt(j) == '1') cost++;
            }

            boolean[] used = new boolean[N];
            used[i] = true;
            // Item j
            for (int j = 1; j < N; j++) {
                boolean found = false;
                for (int k = 0; k < N; k++) {
                    if (used[k]) continue;
                    if (toChange[j][k].equals(toChange[0][i])) {
                        found = true;
                        used[k] = true;
                        break;
                    }
                }

                if (!found) {
                    cost = MAX;
                    break;
                }
            }

            ans = Math.min(cost, ans);
        }

        if (ans == MAX) {
            System.out.println(noGood);
        }
        else {
            System.out.println(ans);
        }
    }

}
