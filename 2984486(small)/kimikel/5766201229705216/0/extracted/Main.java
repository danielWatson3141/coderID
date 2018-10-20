import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String args[]) throws FileNotFoundException {
        
        final Scanner in = new Scanner(new File("/home/mikel/Desktop/codejam/Round1A/input.txt"));
        final PrintWriter out = new PrintWriter(new File("/home/mikel/Desktop/codejam/Round1A/output.txt"));
        
        final int t = in.nextInt();
        for (int it = 1; it <= t; it++) {
            
            int n = in.nextInt();
            
            /*int[][] edges = new int[n-1][];
            for (int i = 1; i < n; i++) {
                edges[i] = new int[2];
                edges[i][0] = in.nextInt()-1;
                edges[i][1] = in.nextInt()-1;
            }*/
            
            boolean[][] linked = new boolean[n][n];
            for (int i = 1; i < n; i++) {
                int x = in.nextInt()-1;
                int y = in.nextInt()-1;
                linked[x][y] = linked[y][x] = true;
            }
            
            int best = 0;
            for (int i = 0; i < n; i++) {
                boolean[][] clone = clone(linked, n);
                Set<Integer> visited = new HashSet<>();
                visited.add(i);
                solve(clone, n, i, -1, visited);
                if (visited.size() > best) best = visited.size();
            }
            
            out.println("Case #" + it + ": " + (n-best));
            
        }
        
        out.close();
    }
    
    
    
    
    public static void solve(boolean[][] linked, int n, int node, int parent, Set<Integer> visited) {
        
        final List<Integer> candidates = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (linked[node][i] && i != parent && !visited.contains(i)) {
                candidates.add(i);
            }
        }
        
        Set<Integer> bestVisited = new HashSet<>(visited);
        boolean[][] bestLinked = clone(linked, n);
        for (int k = 0; k < n; k++) {
            if (candidates.contains(k)) {
                for (int l = 0; l < n; l++) {
                    bestLinked[k][l] = bestLinked[l][k] = false;
                }
            }
        }
        
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                
                if (candidates.contains(i) && candidates.contains(j)) {
                
                    boolean[][] linked1 = clone(linked, n);
                    boolean[][] linked2 = clone(linked, n);
                    for (int k = 0; k < n; k++) {
                        if (candidates.contains(k) && k != i && k != j) {
                            for (int l = 0; l < n; l++) {
                                linked1[k][l] = linked1[l][k] = false;
                                linked2[k][l] = linked2[l][k] = false;
                            }
                        }
                    }

                    Set<Integer> visited1 = new HashSet<>(visited);
                    Set<Integer> visited2 = new HashSet<>(visited);
                    visited1.add(i); visited1.add(j);
                    visited2.add(i); visited2.add(j);
                    solve(linked1, n, i, node, visited1);
                    solve(linked1, n, j, node, visited1);
                    solve(linked2, n, j, node, visited2);
                    solve(linked2, n, i, node, visited2);

                    if (visited1.size() > bestVisited.size()) {
                        bestVisited = visited1;
                        bestLinked = linked1;
                    }
                    if (visited2.size() > bestVisited.size()) {
                        bestVisited = visited2;
                        bestLinked = linked2;
                    }
                }
            }
        }
        
        visited.clear();
        visited.addAll(bestVisited);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) linked[i][j] = bestLinked[i][j];
    }
    
    
    public static boolean[][] clone(boolean[][] arg, int length) {
        boolean res[][] = new boolean[length][length];
        for (int i = 0; i < length; i++) for (int j = 0; j < length; j++) res[i][j] = arg[i][j];
        return res;
    }
    
    
    
    
    /*
    
    public int solve(int[][] edges, int n) {
        List<Integer>[] children = new List[n];
        for (int i = 0; i < n; i++) children[i] = new ArrayList();
        return solve(edges, n, 0, 0, children);
    }
    
    public int solve(int[][] edges, int n, int pos, int inside, List<Integer>[] children) {
        List<Integer>[] addingChildren = clone(children, n);
        addingChildren[edges[pos][0]].add(edges[pos][1]);
        addingChildren[edges[pos][1]].add(edges[pos][0]);
        
        int x = solve(edges, n, pos+1, inside, );
        return Math.max(, n)
    }
    
    public static List<Integer>[] clone(List<Integer>[] arg, int len) {
        List<Integer>[] res = new List[len];
        for (int i = 0; i < len; i++) res[i] = new ArrayList(arg[i]);
        return res;
    }
    
    public boolean check(List<Integer> children[], int len) {
        for (int i = 0; i < children.length; i++) {
            Set<Integer> visited = new TreeSet<>();
            visited.add(i);
            if (check(i, children, -1, visited) && visited.size() == len) return true;
        }
        return false;
    }
    
    // -1 not binary tree
    public boolean check(int node, List<Integer> children[], int parent, Set<Integer> visited) {
        int len = children[node].size();
        if (parent != -1) len--;
        
        if (len != 0 && len != 2) return false;
        
        for (int child : children[node]) {
            if (child != parent) {
                if (visited.contains(child)) return false;
                visited.add(child);
                if (!check(child, children, node, visited)) return false;
            }
        }
        return true;
    }
    
    
    
    
    public static boolean[][] clone(boolean[][] arg, int length) {
        boolean res[][] = new boolean[length][length];
        for (int i = 0; i < length; i++) for (int j = 0; j < length; j++) res[i][j] = arg[i][j];
        return res;
    }
    
    */
}