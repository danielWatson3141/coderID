import java.io.*;
import java.util.*;

public class ChargingChaos {
  private static final String OUTPUT_FILE = "output.txt";

  public static void main(String[] args) throws IOException {
    FastScanner sc = new FastScanner();
    FileWriter writer = new FileWriter(OUTPUT_FILE);
    try {
      int T = sc.nextInt();

      for(int i = 1; i <= T; i++) {
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
    int L = sc.nextInt();
    String[] flow = new String[N];
    for(int i = 0; i < N; i++) {
      flow[i] = sc.nextToken();
    }
    String[] devices = new String[N];
    for(int i = 0; i < N; i++) {
      devices[i] = sc.nextToken();
    }

    int minFlips = Integer.MAX_VALUE;

    for(int i = 0; i < N; i++) {
      int currentFlips = 0;
      boolean[] flips = new boolean[L];
      for(int j = 0; j < L; j++) {
        if(devices[0].charAt(j) != flow[i].charAt(j)) {
          flips[j] = true;
          currentFlips++;
        }
      }

      if(isConfigurationPossible(devices, flow, flips)) {
        minFlips = Math.min(minFlips, currentFlips);
      }
    }

    if(minFlips == Integer.MAX_VALUE) {
      return "NOT POSSIBLE";
    } else {
      return Integer.toString(minFlips);
    }
  }

  private static boolean isConfigurationPossible(String[] devices, String[] flow, boolean[] flips) {
    int N = flow.length;
    boolean[] chosen = new boolean[N];
    for(int i = 0; i < N; i++) {
      boolean deviceFit = false;
      for(int j = 0; j < N; j++) {
        if(chosen[j]) continue;

        if(isDeviceFit(devices[i], flow[j], flips)) {
          deviceFit = true;
          chosen[j] = true;
          break;
        }
      }

      if(!deviceFit) {
        return false;
      }
    }
    return true;
  }

  private static boolean isDeviceFit(String device, String flow, boolean[] flips) {
    for(int i = 0; i < device.length(); i++) {
      if(flips[i] == (device.charAt(i) == flow.charAt(i))) {
        return false;
      }
    }
    return true;
  }

  private static void printCase(Writer writer, int testNum, String result) throws IOException {
    //System.out.println("Case #" + testNum + ": " + result + "\n");
    writer.write("Case #" + testNum + ": " + result + "\n");
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
