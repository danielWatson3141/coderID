import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

/**
 * Created by Rafal on 4/12/14.
 */
public class B {

    public static void main(String[] args) {
        try {

            InputStream in = new FileInputStream("c:/projekty/codejam/src/B.in");
            Scanner scanner = new Scanner(in);
            OutputStream out = new FileOutputStream("c:/projekty/codejam/src/B.out");
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(out, "utf8"));
            int t = scanner.nextInt();
            for (int i = 0; i < t; i++) {
                solve(scanner, i+1, writer);
            }
            writer.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
            e.printStackTrace();
        }
    }


    public static void solve(Scanner scanner, int t, PrintWriter out) {
        int n = scanner.nextInt();
        // for each node - try it as root
        Node []nodes = new Node[n];
        for (int i = 0; i < nodes.length; i++) {
            nodes[i] = new Node();

        }
//        Edge[]edges = new Edge[n-1];

        for (int i = 0; i < n-1; i++) {
//            edges[i] = new Edge();
            int i1 = scanner.nextInt();
//            edges[i].i = i1;
            int i2 = scanner.nextInt();
//            edges[i].j = i2;

            nodes[i1-1].addNode(i2-1);
            nodes[i2-1].addNode(i1-1);
        }

        int bestResult = n;
        for (int i = 0; i < n; i++) {
            // try node i as tree root
            Node []nodesCopy = new Node[n];
            for (int j = 0; j < nodesCopy.length; j++) {
                nodesCopy[j] = new Node();
                nodesCopy[j].nodes = new HashSet<>(nodes[j].nodes);
            }

            // build the tree with i as root
            TreeNode root = buildTree(nodesCopy, i);

            int result = 0;
            result = cleanUpNode(root);
            if (result < bestResult) {
                bestResult = result;
            }
        }


        String resultTxt = "";
        System.out.println("Case #" + t + ": " + bestResult);
        out.println("Case #" + t + ": " + bestResult);
    }

    private static int cleanUpNode(TreeNode root) {
        int result = 0;
        int totalNodes = 1;
        for (int i = 0; i < root.nodes.size(); i++) {
            TreeNode child = root.nodes.get(i);
            result += cleanUpNode(child);
            totalNodes += child.totalNodes;
        }
        root.totalNodes = totalNodes;
        if (root.nodes.size() == 0 || root.nodes.size() == 2) {
            return result;
        }
        if (root.nodes.size() == 1) {
            int nodesToBeRemoved = root.nodes.get(0).totalNodes;
            result += nodesToBeRemoved;
            root.totalNodes -= nodesToBeRemoved;
            return result;
        }

        TreeNode bestChild1 = root.nodes.get(0), bestChild2 = root.nodes.get(1);
        for (int i = 2; i < root.nodes.size(); i++) {
            TreeNode child = root.nodes.get(i);
            if (child.totalNodes > bestChild1.totalNodes) {
                bestChild1 = child;
            } else if (child.totalNodes > bestChild2.totalNodes) {
                bestChild2 = child;
            }
        }

        for (int i = 0; i < root.nodes.size(); i++) {
            TreeNode child = root.nodes.get(i);
            if (child != bestChild1 && child != bestChild2) {
                result += child.totalNodes; // remove this node
                root.totalNodes -= child.totalNodes;
            }
        }
        return result;
    }

    private static TreeNode buildTree(Node[] nodes, int i) {
        Node root = nodes[i];
        TreeNode rootTreeNode = new TreeNode();
        for (Integer child : root.nodes) {
            Node childNode = nodes[child];
            childNode.nodes.remove(i);

            TreeNode childTreeNode = buildTree(nodes, child);
            rootTreeNode.nodes.add(childTreeNode);
        }
        return rootTreeNode;
    }


    static DecimalFormat df = new DecimalFormat("#######################0.00000000000");
    private static String formatDouble(double seconds) {
        return df.format(seconds);
    }

    static class Node {
        Set<Integer> nodes;        // nodes connected to that one

        public void addNode(int ii) {
            if (nodes == null) nodes = new HashSet<>();
            nodes.add(ii);
        }
    }

    static class TreeNode {
        List<TreeNode> nodes = new ArrayList<>();
        int totalNodes;
    }

    static class Edge {
        int i, j;
    }
}
