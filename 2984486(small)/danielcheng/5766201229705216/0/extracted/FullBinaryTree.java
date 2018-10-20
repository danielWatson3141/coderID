import java.util.*;

public class FullBinaryTree {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        for (int i = 1; i <= cases; i++) {
            int nodes = scanner.nextInt();
            boolean[][] graph = new boolean[nodes][nodes];
            for (int j = 0; j < nodes - 1; j++) readEdge(graph, scanner);
            System.out.println("Case #" + i + ": " + calculate(nodes, graph));
        }
        scanner.close();
    }

    private static int calculate(int nodes, boolean[][] graph) {
        int min = 9999;
        for (int i = 0; i < nodes; i++) {
            boolean[] visited = new boolean[nodes];
            if (!canBeRoot(graph, i, visited)) continue;
            int tmp = minToRemove(graph, visited, i);
            if (min > tmp) min = tmp;
        }
        return min;
    }

    private static int minToRemove(boolean[][] graph, boolean[] visited, int root) {
        visited[root] = true;

        int neighbors = countUnvisitedNeighbor(graph[root], visited);
        if (neighbors == 0) return 0;
        if (neighbors == 1) {
            for (int i = 0; i < graph[root].length; i++) {
                if (graph[root][i] && !visited[i]) return countBranch(graph, i, visited, false);
            }
        }
        int total = 0;

        if (neighbors > 2) {
            HashMap<Integer, List<Integer>> removesToNode = new HashMap<Integer, List<Integer>>();
            for (int i = 0; i < graph[root].length; i++) {
                if (graph[root][i] && !visited[i]) {
                    int nodesToRemove = countBranch(graph, i, visited, true);
                    if (!removesToNode.containsKey(nodesToRemove))
                        removesToNode.put(nodesToRemove, new ArrayList<Integer>());
                    List<Integer> integers = removesToNode.get(nodesToRemove);
                    integers.add(i);
                }
            }

            Integer[] counters = (Integer[]) new ArrayList<Integer>(removesToNode.keySet()).toArray(new Integer[]{});
            Arrays.sort(counters);
            int kk = 0;
            while (neighbors > 2) {
                Integer counter = counters[kk];
                List<Integer> integers = removesToNode.get(counter);
                countBranch(graph, integers.get(0), visited, false);
                total += counter;
                integers.remove(0);
                neighbors--;
                if (integers.size() == 0) {
                    kk++;
                }
            }
        }

        for (int i = 0; i < graph[root].length; i++) {
            if (graph[root][i] && !visited[i]) {
                total += minToRemove(graph, visited, i);
            }
        }
        return total;
    }

    private static int countBranch(boolean[][] graph, int currentNode, boolean[] visited, boolean trial) {
        int count = 1;
        visited[currentNode] = true;
        for (int i = 0; i < graph[currentNode].length; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                count += countBranch(graph, i, visited, false);
            }
        }
        if (trial) visited[currentNode] = false;
        return count;
    }

    private static boolean canBeRoot(boolean[][] graph, int root, boolean[] visited) {
        return countUnvisitedNeighbor(graph[root], visited) < 3;
    }

    private static int countUnvisitedNeighbor(boolean[] booleans, boolean[] visited) {
        int count = 0;
        for (int i = 0; i < booleans.length; i++) {
            if (booleans[i] && !visited[i]) count++;
        }
        return count;
    }

    private static void readEdge(boolean[][] graph, Scanner scanner) {
        int x = scanner.nextInt() - 1;
        int y = scanner.nextInt() - 1;
        graph[x][y] = true;
        graph[y][x] = true;
    }

}
