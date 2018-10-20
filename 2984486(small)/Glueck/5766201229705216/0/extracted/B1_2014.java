/**
 * Created with IntelliJ IDEA.
 * User: den
 * Date: 4/26/14
 * Time: 4:25 AM
 * To change this template use File | Settings | File Templates.
 */


import sun.jvm.hotspot.opto.Node_Array;

import java.io.*;
import java.util.*;

public class B1_2014 extends Thread {
    class Node {
        int id;
        int deg;
        ArrayList<Node> adj = new ArrayList<Node>();

        public Node(int id) {
            this.id = id;
            deg = 0;
        }

        public void addEdge(Node n) {
            adj.add(n);
            deg++;
        }
    }

    static Node[] a;

    int maxSize(Node a, int from) {
        ArrayList<Integer> masses = new ArrayList<Integer>();
        if (a.deg == 1){
            return 1;
        }

        for (Node node : a.adj) {
            if (node.id == from)
                continue;
            masses.add(maxSize(node,a.id));
        }

        if (masses.size() < 2)
            return 1;
        Collections.sort(masses, Collections.reverseOrder());
        return 1 + masses.get(0) + masses.get(1);
    }

//    int minRoot(Node a){
//
//    }
//
//    int minNode(Node a){
//
//    }
//
//    int minLeave(Node a){
//
//    }


    private void solve() throws IOException {
        int T = _int();
        for (int test = 1; test <= T; test++) {
            int n = _int();
            a = new Node[n];
            for (int i = 0; i < n; i++)
                a[i] = new Node(i);
            for (int i = 0; i < n - 1; i++) {
                int from = _int()-1;
                int to = _int()-1;

                a[from].addEdge(a[to]);
                a[to].addEdge(a[from]);
            }


            int bestValue = 1;
            for (Node node : a) {
                if (node.deg == 1)
                    continue;
                int current = maxSize(node,-1);
                if (current > bestValue) {
                    bestValue = current;
                }

            }

            out.println("Case #" + test + ": " + (n - bestValue));
        }
    }

    public void run() {
        try {
            solve();
        } catch (Exception e) {
            System.out.println("System exiting....");
            e.printStackTrace();
            System.exit(888);
        } finally {
            out.flush();
            out.close();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        new B1_2014().run();
    }

    public B1_2014() throws FileNotFoundException {
        in = new BufferedReader(new FileReader("b-test.in"));
        out = new PrintWriter(new File("b-test.out"));
//        in = new BufferedReader(new InputStreamReader(System.in));
//        out = new PrintWriter(System.out);
        setPriority(Thread.MAX_PRIORITY);
    }

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;

    private int _int() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private double _double() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private long _long() throws IOException {
        return Long.parseLong(nextToken());
    }

    private char[] _chars() throws IOException {
        return nextToken().toCharArray();
    }

    private String nextToken() throws IOException {
        if (st == null || !st.hasMoreElements())
            st = new StringTokenizer(in.readLine(), " \t\r\n");
        return st.nextToken();
    }
}

