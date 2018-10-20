import java.util.*;

public class FullBinaryTree {
    static Scanner in;

    public static class Solution {
        public static class Node {
            public List<Node> neighbours = new LinkedList<Node>();

            int solve() {
                return solveFrom(null);
            }

            int solveFrom(Node parent) {
                ArrayList<Integer> children = new ArrayList<Integer>();


                if (neighbours.size() < 2) {
                    return 1;
                }

                for (Node neighbour : neighbours) {
                    if (neighbour == parent) {
                        continue;
                    }

                    children.add(neighbour.solveFrom(this));

                    if (children.size() > 2) {
                        Collections.sort(children);
                        children.remove(0);
                    }
                }

                if (children.size() < 2) {
                    return 1;
                }
                else {
                    return 1 + children.get(0) + children.get(1);
                }
            }

            public void relate(Node neighbour) {
                neighbours.add(neighbour);
                neighbour.neighbours.add(this);
            }
        }

        Solution(int testCase) {
            int numNodes = in.nextInt();
            int edges = numNodes - 1;

            HashMap<Integer, Node> nodes = new HashMap<Integer, Node>();

            // Create nodes
            for (int i = 0; i < numNodes; i++) {
                nodes.put(i + 1, new Node());
            }

            // Make relationships
            for (int i = 0; i < edges; i++) {
                Node a = nodes.get(in.nextInt());
                Node b = nodes.get(in.nextInt());

                a.relate(b);
            }

            int maxRemaining = 0;

            for (Node node : nodes.values()) {
                maxRemaining = Math.max(maxRemaining, node.solve());
            }

            System.out.println("Case #" + testCase + ": " + (numNodes - maxRemaining));
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        final int testCases = in.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            new Solution(testCase);
        }
    }
}
