import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.HashSet;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Set;
import java.util.StringTokenizer;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author abra
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		B solver = new B();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class B extends SavingChelperSolution {

  List<Set<Integer>> edges;

  public void solve() {
    int n = in.nextInt();

    edges = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      edges.add(new HashSet<>());
    }

    for (int i = 0; i < n - 1; i++) {
      int a = in.nextInt() - 1;
      int b = in.nextInt() - 1;

      edges.get(a).add(b);
      edges.get(b).add(a);
    }

    int min = Integer.MAX_VALUE;

    for (int i = 0; i < n; i++) {
      size = new int[n];
      cost = new int[n];

      dfs(-1, i);

      if (cost[i] < min) {
        min = cost[i];
      }
    }

    out.println(min);
  }

  int[] size, cost;

  // size, to make
  void dfs(int from, int v) {
    size[v] = 1;
    int max1 = -1;
    int max2 = -1;

    for (Integer child : edges.get(v)) {
      if (child == from) {
        continue;
      }
      dfs(v, child);
      size[v] += size[child];
      cost[v] += size[child];

      int profit = size[child] - cost[child];

      if (profit > max1) {
        max2 = max1;
        max1 = profit;
      } else {
        if (profit > max2) {
          max2 = profit;
        }
      }
    }

    if (max2 != -1) {
      cost[v] -= max1 + max2;
    }
  }
}

abstract class SavingChelperSolution {

  public InputReader in;
  public OutputWriter out;

  private OutputWriter toFile;

  public SavingChelperSolution() {
    try {
      toFile = new OutputWriter("gcj-output.txt");
    } catch (FileNotFoundException e) {
      throw new RuntimeException(e);
    }
  }

  public abstract void solve();

  public void solve(int testNumber, InputReader in, OutputWriter out) {

    ByteArrayOutputStream saved = new ByteArrayOutputStream();

    OutputWriter savingOut = new OutputWriter(saved);

    this.in = in;
    this.out = savingOut;

    solve();
    savingOut.flush();

    String result = "Case #" + testNumber + ": " + saved.toString();
    if (!result.endsWith("\n")) {
      result += "\n";
    }

    out.write(result);
    out.flush();
    toFile.write(result);
    toFile.flush();
  }

}

class InputReader {

  BufferedReader br;
  StringTokenizer in;

  public InputReader(String fileName) {
    try {
      br = new BufferedReader(new FileReader(fileName));
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }

  public InputReader(InputStream inputStream) {
    br = new BufferedReader(new InputStreamReader(inputStream));
  }

  boolean hasMoreTokens() {
    while (in == null || !in.hasMoreTokens()) {
      String s = nextLine();
      if (s == null) {
        return false;
      }
      in = new StringTokenizer(s);
    }
    return true;
  }

  public String nextString() {
    return hasMoreTokens() ? in.nextToken() : null;
  }

  public String nextLine() {
    try {
      in = null; // riad legacy
      return br.readLine();
    } catch (Exception e) {
      e.printStackTrace();
      return null;
    }
  }

  public int nextInt() {
    return Integer.parseInt(nextString());
  }

  public String next() {
    return nextString();
  }
}

class OutputWriter extends PrintWriter {

  public OutputWriter(String fileName) throws FileNotFoundException {
    super(fileName);
  }

  public OutputWriter(OutputStream outputStream) {
    super(outputStream);
  }

  public OutputWriter(Writer writer) {
    super(writer);
  }

}

