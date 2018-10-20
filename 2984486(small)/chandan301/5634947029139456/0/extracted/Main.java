package codejam2014.round1A.chargingchaos;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = new FileInputStream(
                "/Users/chandangiri/Documents/workspace/Competetions/src/codejam2014/round1A/chargingchaos/A-small-attempt.in");
        OutputStream outputStream = new FileOutputStream(
                "/Users/chandangiri/Documents/workspace/Competetions/src/codejam2014/round1A/chargingchaos/out.txt");
        //        InputStream inputStream = System.in;
        //        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ChargingChaos solver = new ChargingChaos();
        int testCount = in.nextInt();
        for (int i = 1; i <= testCount; i++) {
            out.printf("Case #%d: ", i);
            solver.solve(in, out);
        }
        out.close();
    }
}

class ChargingChaos {

    int bit[] = new int[11];
    {
        for (int i = 0; i <= 10; i++) {
            bit[i] = (1 << i);
        }
    }

    public void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int l = in.nextInt();
        String flow[] = new String[n];
        String rflow[] = new String[n];
        String dev[] = new String[n];
        Set<String> devs = new HashSet<>();

        for (int i = 0; i < n; i++) {
            flow[i] = in.next();
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < l; j++) {
                if (flow[i].charAt(j) == '0') {
                    sb.append('1');
                } else {
                    sb.append('0');
                }
            }
            rflow[i] = sb.toString();
        }

        for (int i = 0; i < n; i++) {
            dev[i] = in.next();
            devs.add(dev[i]);
        }

        int mx = (1 << l) - 1;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < mx; i++) {
            StringBuilder tflow[] = new StringBuilder[n];
            for (int j = 0; j < n; j++) {
                tflow[j] = new StringBuilder();
            }

            int ct = 0;
            for (int j = 0; j < l; j++) {
                int b = (i & bit[j]);
                if(b == 0) {
                    for (int k = 0; k < n; k++) {
                        tflow[k].append(flow[k].charAt(j));
                    }
                } else {
                    for (int k = 0; k < n; k++) {
                        tflow[k].append(rflow[k].charAt(j));
                    }
                    ct++;
                }
            }

            Set<String> ndevSet = new HashSet<>();
            for (int j = 0; j < n; j++) {
                ndevSet.add(tflow[j].toString());
            }
            if (devs.containsAll(ndevSet)) {
                min = Math.min(min, ct);
            }
        }

        if(min == Integer.MAX_VALUE) {
            out.println("NOT POSSIBLE");
        } else {
            out.println(min);
        }
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}


