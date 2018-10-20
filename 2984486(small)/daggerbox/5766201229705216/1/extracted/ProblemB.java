package com.forthgo.contest.g2014.r1a;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;


public class ProblemB {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("B.in.txt"));
            PrintWriter out = new PrintWriter(new FileWriter("B.out.txt"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                out.printf("Case #%d: ", i + 1);
                solve(in, out);
                out.println();
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    private static void solve(Scanner in, PrintWriter out) {
        int N = in.nextInt();
        @SuppressWarnings("unchecked")
        List<Integer>[] links = new ArrayList[N + 1];//new ArrayList<Integer>[N];
        for (int i = 1; i <= N; i++) {
            links[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < N - 1; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            links[a].add(b);
            links[b].add(a);
        }
        int best = N;
        for (int i = 1; i <= N; i++) {
            int cost = rootCost(links, i);
            if (cost < best)
                best = cost;
        }
        out.print(best);
    }

    private static int rootCost(List<Integer>[] links, int r) {
        if (links[r].size() == 0)
            return 0;
        if (links[r].size() == 1)
            return chopCost(links, links[r].get(0), r);
        return parentCost(links, r, 0);
    }

    private static int childCost(List<Integer>[] links, int x, int r) {
        if (links[x].size() == 0)
            throw new RuntimeException();
        if (links[x].size() == 1)
            return 0;
        if (links[x].size() == 2) {
            for (int ia = 0; ia < links[x].size(); ia++) {
                int a = links[x].get(ia);
                if (a == r)
                    continue;
                return chopCost(links, a, x);
            }
        }
        return parentCost(links, x, r);
    }

    private static int parentCost(List<Integer>[] links, int x, int r) {
        int best = Integer.MAX_VALUE;
        for (int ia = 0; ia < links[x].size() - 1; ia++) {
            int a = links[x].get(ia);
            if (a == r)
                continue;
            for (int ib = ia + 1; ib < links[x].size(); ib++) {
                int b = links[x].get(ib);
                if (b == r)
                    continue;
                int cost = 0;
                for (int ic = 0; ic < links[x].size(); ic++) {
                    int c = links[x].get(ic);
                    if (c != a && c != b && c != r)
                        cost += chopCost(links, c, x);
                }
                cost += childCost(links, a, x);
                cost += childCost(links, b, x);
                if (cost < best) {
                    best = cost;
                }
            }
        }
        if (best == Integer.MAX_VALUE)
            throw new RuntimeException();
        return best;
    }

    private static int chopCost(List<Integer>[] links, int n, int r) {
        int cost = 1;
        for (int i = 0; i < links[n].size(); i++) {
            if (links[n].get(i) != r)
                cost += chopCost(links, links[n].get(i), n);
        }
        return cost;
    }

}


