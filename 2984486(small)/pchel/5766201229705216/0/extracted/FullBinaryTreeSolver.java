import java.io.*;
import java.util.*;

public class FullBinaryTreeSolver {
    //    private static final String INPUT_FILE_NAME = "C-large.in";
                        private static final String INPUT_FILE_NAME = "B-small-attempt0.in";
//    private static final String INPUT_FILE_NAME = "input.in";
    //    private static final String OUTPUT_FILE_NAME = "C-large.out";
                    private static final String OUTPUT_FILE_NAME = "B-small-attempt0.out";
//    private static final String OUTPUT_FILE_NAME = "output.out";

    private int n;
    private Node[] nodes;
    private int[] subTree;
    private int[] toDelete;
    private int min;

    public static void main(String[] args) throws IOException {
        StringBuilder builder = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(INPUT_FILE_NAME)))) {
            Scanner scanner = new Scanner(reader);
            scanner.useLocale(Locale.ENGLISH);
            int testCasesCount = scanner.nextInt();

            for (int i = 1; i <= testCasesCount; i++) {
                System.out.println("Case #" + i);
                scanner.nextLine();
                FullBinaryTreeSolver solver = new FullBinaryTreeSolver();

                solver.readData(scanner);
                int solution = solver.solve();

                builder.append("Case #");
                builder.append(i);
                builder.append(": ");
                builder.append(solution);
                builder.append("\r\n");
            }
        }

        try (BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT_FILE_NAME)
        ))) {
            writer.write(builder.toString());
        }
    }

    private int solve() {
        subTree = new int[n];
        toDelete = new int[n];
        min = n;

        for (int i = 0; i < n; i++) {
            // i - the root
            Arrays.fill(subTree, 0);
            Arrays.fill(toDelete, 0);

            go(i, -1);
            min = Math.min(min, toDelete[i]);
        }

        return min;
    }

    private void go(int x, int parent) {
        List<Node> children = new ArrayList<>();
        for (Node child : nodes[x].children) {
            if (child.i != parent) {
                children.add(child);
                go(child.i, x);
                subTree[x] += subTree[child.i];
            }
        }
        subTree[x]++;

        int size = children.size();
        if (size == 0) {
            toDelete[x] = 0;
        } else if (size == 1) {
            toDelete[x] = subTree[x] - 1;
        } else if (size == 2) {
            toDelete[x] = toDelete[children.get(0).i] + toDelete[children.get(1).i];
        } else {
            toDelete[x] = n;
            for (int i = 0; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    // we leave i-th and j-th child
                    toDelete[x] = Math.min(toDelete[x], subTree[x] - 1 - subTree[children.get(i).i] -
                            subTree[children.get(j).i] + toDelete[children.get(i).i] +
                            toDelete[children.get(j).i]);
                }
            }
        }
    }

    private void readData(Scanner scanner) {
        n = scanner.nextInt();

        nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }

        for (int i = 0; i < n - 1; i++) {
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt() - 1;

            nodes[x].children.add(nodes[y]);
            nodes[y].children.add(nodes[x]);
        }
    }

    private static class Node {
        private int i;
        private List<Node> children = new ArrayList<>();

        private Node(int i) {
            this.i = i;
        }
    }
}
