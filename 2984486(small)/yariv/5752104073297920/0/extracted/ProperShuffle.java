import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class ProperShuffle {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("/home/yariv/Downloads/C-small-attempt0.in")));
        int T = Integer.parseInt(reader.readLine());
        for (int i=1; i<=T; i++) {
            int N = Integer.parseInt(reader.readLine());
            int[] permutation = new int[N];
            StringTokenizer tok = new StringTokenizer(reader.readLine());
            for (int j=0; j<N; j++) {
                permutation[j] = Integer.parseInt(tok.nextToken());
            }
            int oneBefores = 0;
            for (int j = 0; j < N; j++) {
                if (permutation[j] == j+1) oneBefores++;
            }

            if (oneBefores > 0)
                System.out.printf("Case #%d: BAD\n", i);
            else
                System.out.printf("Case #%d: GOOD\n", i);
        }
    }
}

