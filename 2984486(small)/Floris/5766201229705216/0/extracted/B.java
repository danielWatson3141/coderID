import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/B-small-attempt0.in");
        System.setOut(new PrintStream("/home/floris/temp/codejam2014/src/B.out"));
        Scanner sc = new Scanner(in);

        for (int c = 1, cases = sc.nextInt(); c <= cases; c++) {
            int N = sc.nextInt();
            Node[] tree = new Node[N];
            for (int i = 0; i < N; i++) tree[i] = new Node();
            for (int i = 0; i < N-1; i++) {
                int a = sc.nextInt()-1;
                int b = sc.nextInt()-1;
                tree[a].links.add(tree[b]);
                tree[b].links.add(tree[a]);
            }
            int result = Integer.MAX_VALUE;
            for (int i = 0; i < N; i++) {
//                System.out.println("root " + i + " " + cut(tree, tree[i], null));
                result = Math.min(result, cut(tree, tree[i], null));
            }
            System.out.printf("Case #%d: %d%n", c, result);
        }
    }
    private static int cut(Node[] tree, Node root, Node parent) {
        int[] count = new int[root.links.size()];
        for (int i = 0; i < count.length; i++) {
            if (root.links.get(i) == parent) count[i] = 0;
            else count[i] = 1 + cut(tree, root.links.get(i), root);
        }
        Arrays.sort(count);
        int result = 0;
        for (int i = 0; i < count.length; i++) result += count[i];
        if (parent == null) {
            if (count.length >= 2) result -= 2;
        } else {
            if (count.length >= 3) result -= 2;
            
        }
        return result;
    }

    static class Node {
        List<Node> links = new ArrayList<>();
        int count(Node parent) {
            int result = 1;
            for (int i = 0; i< links.size(); i++) {
                if (links.get(i)!=parent) result+= links.get(i).count(this);
            }
            return result;
        }
    }
}
