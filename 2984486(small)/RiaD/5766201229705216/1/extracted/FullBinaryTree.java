package main;

import name.admitriev.spsl.io.OutputWriter;
import name.admitriev.spsl.io.Reader;

import java.util.ArrayList;
import java.util.Collections;

public class FullBinaryTree {
    private int deleted;

    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        ArrayList<Integer>[] graph = new ArrayList[n];
        for(int i = 0; i < n; ++i) {
            graph[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i < n - 1; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            graph[x].add(y);
            graph[y].add(x);
        }

        int answer = n - 1;

        for(int i = 0; i < n; ++i) {
            deleted = 0;
            rec(graph, i, -1);

            answer = Math.min(answer, deleted);
        }
        out.println("Case #" + testNumber + ": " + answer);
    }

    private int rec(ArrayList<Integer>[] graph, int v, int p) {

        ArrayList<Integer> sizes = new ArrayList<Integer>();
        for (int to : graph[v]) {
            if(to != p)
                sizes.add(rec(graph, to, v));
        }
        if(sizes.isEmpty())
            return 1;
        if(sizes.size() == 1) {
            deleted += sizes.get(0);
            return 1;
        }
        Collections.sort(sizes, Collections.reverseOrder());
        for(int i = 2; i < sizes.size(); ++i) {
            deleted += sizes.get(i);
        }
        return 1 + sizes.get(0) + sizes.get(1);
    }
}
