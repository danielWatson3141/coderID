import java.io.FileNotFoundException;
import java.util.Comparator;
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
import java.util.Collections;
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
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A extends SavingChelperSolution {

  public void solve() {
    int n = in.nextInt();
    int l = in.nextInt();

    List<List<Boolean>> start = new ArrayList<>();
    List<List<Boolean>> end = new ArrayList<>();

    for (int i = 0; i < n; i++) {
      String s = in.nextString();
      List<Boolean> row = new ArrayList<>();

      for (int j = 0; j < l; j++) {
        row.add(s.charAt(j) == '1');
      }

      start.add(row);
    }
    for (int i = 0; i < n; i++) {
      String s = in.nextString();
      List<Boolean> row = new ArrayList<>();

      for (int j = 0; j < l; j++) {
        row.add(s.charAt(j) == '1');
      }

      end.add(row);
    }

    int result = Integer.MAX_VALUE;

    Set<List<Boolean>> actions = new HashSet<>();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        actions.add(xor(start.get(i), end.get(j)));
      }
    }

    for (List<Boolean> action : actions) {
      List<List<Boolean>> ends = new ArrayList<>();

      for (List<Boolean> row : start) {
        ends.add(xor(row, action));
      }

      if (equal(end, ends)) {
        int cost = sum(action);

        if (cost < result) {
          result = cost;
        }
      }
    }

    if (result == Integer.MAX_VALUE) {
      out.println("NOT POSSIBLE");
    } else {
      out.println(result);
    }
  }

  List<Boolean> xor(List<Boolean> a, List<Boolean> b) {
    List<Boolean> result = new ArrayList<>();

    for (int i = 0; i < a.size(); i++) {
      result.add(!a.get(i).equals(b.get(i)));
    }

    return result;
  }

  boolean equal(List<List<Boolean>> a, List<List<Boolean>> b) {
    Comparator<List<Boolean>> comparator = (List<Boolean> o1, List<Boolean> o2) -> {
      for (int i = 0; i < o1.size(); i++) {
        if (!o1.get(i).equals(o2.get(i))) {
          if (o1.get(i)) {
            return 1;
          } else {
            return -1;
          }
        }
      }
      return 0;
    };

    a = new ArrayList<>(a);
    b = new ArrayList<>(b);

    Collections.sort(a, comparator);
    Collections.sort(b, comparator);

    return a.equals(b);
  }

  int sum(List<Boolean> row) {
    int result = 0;
    for (Boolean i : row) {
      if (i) {
        result++;
      }
    }
    return result;
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

