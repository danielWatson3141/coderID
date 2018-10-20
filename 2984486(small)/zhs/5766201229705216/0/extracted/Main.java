
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author zhs
 */
public class Main {

    private static class Node {

        int n;
        int r;
        int count;
        ArrayList<Node> nodes = new ArrayList<>();
    }

    private static void get(Node parent, Node node) {
        node.count = 1;
        ArrayList<Node> children = new ArrayList<>();
        for (Node child : node.nodes) {
            if (child != parent) {
                children.add(child);
                get(node, child);
                node.count += child.count;
            }
        }
        if (children.isEmpty()) {
            node.r = 0;
        } else if (children.size() == 1) {
            node.r = children.get(0).count;
        } else if (children.size() > 1) {
            node.r = Integer.MAX_VALUE;
            for (int i = 0; i < children.size(); i++) {
                for (int j = i + 1; j < children.size(); j++) {
                    int r = 0;
                    for (int k = 0; k < children.size(); k++) {
                        if (k == i || k == j) {
                            r += children.get(k).r;
                        } else {
                            r += children.get(k).count;
                        }
                    }
                    node.r = Math.min(node.r, r);
                }
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream(
                "/home/zhs/file/code/codejam/20140426/B-small-attempt0.in"));
        System.setOut(new PrintStream(
                "/home/zhs/file/code/codejam/20140426/B-small-attempt0.out"));
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int cs = 1; cs <= t; cs++) {
            System.out.print("Case #" + cs + ": ");
            int n = scanner.nextInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].n = i + 1;
            }
            for (int i = 0; i < n - 1; i++) {
                int x = scanner.nextInt() - 1;
                int y = scanner.nextInt() - 1;
                nodes[x].nodes.add(nodes[y]);
                nodes[y].nodes.add(nodes[x]);
            }
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                get(null, nodes[i]);
                min = Math.min(min, nodes[i].r);
            }
            System.out.println(min);
        }
    }
}
