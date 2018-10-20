import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Tree {

    static int N, result;
    static ArrayList<Integer>[] e = new ArrayList[1000];

    static void cut(int node) {
        for (int i : e[node]) {
            e[i].remove((Integer)node);
        }
    }

    static void recover(int node) {
        for (int i : e[node]) {
            e[i].add(node);
        }
    }

    static int go(int root) {
        ArrayList<Integer> edge = e[root];
        int size = edge.size();
        if (size < 2)
            return 1;
        cut(root);
        try {
            if (size == 2) {
                return go(edge.get(0)) + go(edge.get(1)) + 1;
            } else {
                int x = 0;
                for (int i = 0; i < size - 1; i++)
                    for (int j = i + 1; j < size; j++) {
                        x = Math.max(x, go(edge.get(i)) + go(edge.get(j)) + 1);
                    }
                return x;
            }
        } finally {
            recover(root);
        }
    }

    static void resove() {
        int x = 0;
        for (int i = 0; i < N; i++) {
            x = Math.max(x, go(i));
        }
        result = N - x;
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
            Arrays.fill(e, null);
            for (int i = 0; i < N; i++) {
                e[i] = new ArrayList<Integer>();
            }
            int n = N - 1;
            while (n-- > 0) {

                int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
                e[a].add(b);
                e[b].add(a);
            }
            resove();
            System.out.printf("Case #%d: %d\n", ++caseIndex, result);
        }
    }
}
