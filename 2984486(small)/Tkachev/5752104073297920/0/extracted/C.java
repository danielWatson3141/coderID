import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class C {

    int n;
    int[] a;
    Map<String, Integer> cnt;
    int total;


    void precalc() {
        int n = 1000;
        a = new int[n];
        Random rand = new Random();
        cnt = new TreeMap<>();
        total = 5000000;
        for (int it = 0; it < total; ++it) {
            if (it % 1000000 == 0) {
                System.err.println(it);
            }
            for (int i = 0; i < n; ++i) {
                a[i] = i;
            }
            for (int i = 0; i < n; ++i) {
                int p = rand.nextInt(n);
                swap(a, i, p);
            }
            StringBuilder cur = new StringBuilder();
            for (int i = 0; i < n; ++i) {
                cur.append(a[i]);
                cur.append(" ");
                /*if (i == 1) {
                    break;
                }*/
                break;
            }
            Integer tmp = cnt.get(cur.toString());
            cnt.put(cur.toString(), tmp == null ? 1 : tmp + 1);
            /*for (int i = 0; i < n; ++i) {
                out.print(a[i] + " ");
            }
            out.println();*/
        }
        /*double cur = 1;
        for (int i = 1; i < 10; ++i) {
            cur /= i;
            out.println(i + " " + cur);
        }*/

        /*final String[] s = new String[cnt.size()];
        final int[] counts = new int[cnt.size()];
        int ind = 0;
        for (Map.Entry<String, Integer> entry : cnt.entrySet()) {
            s[ind] = entry.getKey();
            counts[ind++] = entry.getValue();
        }
        Integer[] indices = new Integer[cnt.size()];
        for (int i = 0; i < cnt.size(); ++i) {
            indices[i] = i;
        }
        Arrays.sort(indices, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return Integer.compare(counts[b], counts[a]);
            }
        });
        for (int i = 0; i < 1000; ++i) {
            out.println(s[indices[i]] + " " + counts[indices[i]]);
        }*/
    }

	private void solve() throws Exception {
        n = nextInt();
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
        }
        String cur = a[0] + " ";
        if (cnt.containsKey(cur) && cnt.get(cur) / (double) total > 1. / 1000) {
            out.println("BAD");
        } else {
            out.println("GOOD");
        }
    }

    private void swap(int[] a, int fr, int to) {
        int tmp = a[fr];
        a[fr] = a[to];
        a[to] = tmp;
    }

    public void run() {
		try {
            precalc();
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
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

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private C(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		long start = System.currentTimeMillis();
		new C("C").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
