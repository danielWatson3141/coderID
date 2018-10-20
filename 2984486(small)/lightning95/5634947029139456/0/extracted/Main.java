import java.io.*;
import java.util.*;

public class Main {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "-1";
            }
        }
        return st.nextToken();
    }

    void run() throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        String name = "name";
        try {
            File f = new File(name + ".in");
            if (f.exists() && f.canRead()) {
                input = new FileInputStream(f);
                output = new PrintStream(name + ".out");
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        br.close();
        out.close();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    void solve() {
        for (int test_id = 1, test_num = nextInt(); test_id <= test_num; ++test_id) {
            int n = nextInt(), len = nextInt();
            HashMap<ArrayList<Long>, Integer> map = new HashMap<ArrayList<Long>, Integer>(n);
            ArrayList<Long> list = new ArrayList<Long>(n);
            for (int i = 0; i < n; ++i) {
                String s = nextToken();
                list.add(Long.parseLong(s, 2));
            }
            Collections.sort(list);
            map.put(list, 0);
            ArrayDeque<ArrayList<Long>> q = new ArrayDeque<ArrayList<Long>>();
            q.add(list);
            while (!q.isEmpty()){
                ArrayList<Long> cur = q.pollFirst();
                int c = map.get(cur);
                for (int i = 0; i < len; ++i){
                    ArrayList<Long> nw = new ArrayList<Long>(n);
                    long p = (long) 1 << i;
                    for (int j = 0; j < n; ++j){
                        nw.add(cur.get(j) ^ p);
                    }
                    Collections.sort(nw);
                    if (!map.containsKey(nw)){
                        map.put(nw, c + 1);
                        q.add(nw);
                    }
                }
            }

            ArrayList<Long> end = new ArrayList<Long>(n);
            for (int i = 0; i < n; ++i) {
                String s = nextToken();
                end.add(Long.parseLong(s, 2));
            }
            Collections.sort(end);
            out.print("Case #" + test_id + ": ");
            if (map.containsKey(end)) {
                out.println(map.get(end));
            } else {
                out.println("NOT POSSIBLE");
            }
        }
    }

}