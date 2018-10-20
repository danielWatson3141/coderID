import java.io.*;
import java.util.*;

public class FullBinaryTree {
  private static final String OUTPUT_FILE = "output.txt";

  public static void main(String[] args) throws IOException {
    FastScanner sc = new FastScanner();
    FileWriter writer = new FileWriter(OUTPUT_FILE);
    try {
      int T = sc.nextInt();

      for(int i = 1; i <= T; i++) {
        System.out.println("Current test: " + i);
        String result = solve(sc);
        printCase(writer, i, result);
      }
    } finally {
      writer.flush();
      writer.close();
    }
  }

  private static String solve(FastScanner sc) {
    int N = sc.nextInt();
    List<List<Integer>> edges = new ArrayList<List<Integer>>();
    for(int i = 0; i < N; i++) {
      edges.add(new LinkedList<Integer>());
    }
    for(int i = 0; i < N - 1; i++) {
      int x = sc.nextInt() - 1;
      int y = sc.nextInt() - 1;
      edges.get(x).add(y);
      edges.get(y).add(x);
    }

    int minDeletions = Integer.MAX_VALUE;
    for(int i = 0; i < N; i++) {
      minDeletions = Math.min(minDeletions, getMinDeletions(edges, i, N));
    }
    return Integer.toString(minDeletions);
  }

  private static int getMinDeletions(List<List<Integer>> edges, int root, int N) {
    NodeResults[] memo = new NodeResults[N];
    return getMinDeletions(edges, -1, root, memo).minDeletions;
  }

  private static NodeResults getMinDeletions(List<List<Integer>> edges, int parent, int node, NodeResults[] memo) {
    if(memo[node] != null) {
      return memo[node];
    }

    NodeResults result = new NodeResults();
    List<NodeResults> results = new ArrayList<NodeResults>();
    for(int child : edges.get(node)) {
      if(parent == child) continue;
      results.add(getMinDeletions(edges, node, child, memo));
    }

    if(results.size() == 1) {
      result.minDeletions = results.get(0).nodesCount + results.get(0).minDeletions;
    } else if(results.size() > 0) {
      Collections.sort(results, new Comparator<NodeResults>() {
        @Override
        public int compare(NodeResults o1, NodeResults o2) {
          return o2.nodesCount.compareTo(o1.nodesCount);
        }
      });
      result.nodesCount += results.get(0).nodesCount + results.get(1).nodesCount;
      result.minDeletions = results.get(0).minDeletions + results.get(1).minDeletions;
      for(int i = 2; i < results.size(); i++) {
        result.minDeletions += results.get(i).nodesCount + results.get(i).minDeletions;
      }
    }
    memo[node] = result;
    return result;
  }

  private static void printCase(Writer writer, int testNum, String result) throws IOException {
    //System.out.println("Case #" + testNum + ": " + result + "\n");
    writer.write("Case #" + testNum + ": " + result + "\n");
  }

  private static class NodeResults {
    Integer minDeletions = 0;
    Integer nodesCount = 1;
  }

  private static class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(String s) {
      try {
        br = new BufferedReader(new FileReader(s));
      } catch (FileNotFoundException e) {
        e.printStackTrace();
      }
    }

    public FastScanner() {
      br = new BufferedReader(new InputStreamReader(System.in));
    }

    String nextToken() {
      while (st == null || !st.hasMoreElements()) try {
        st = new StringTokenizer(br.readLine());
      } catch (IOException e) {
        e.printStackTrace();
      }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(nextToken());
    }

    long nextLong() {
      return Long.parseLong(nextToken());
    }

    double nextDouble() {
      return Double.parseDouble(nextToken());
    }
  }
}
