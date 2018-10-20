import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;


public class GCJPB {
    private static Scanner sc;
    private static PrintWriter out;

    public static void main(String[] args) {

        try {
            sc = new Scanner( new File("/nfs/sgururaj/Downloads/B-small-attempt0.in"));
            out = new PrintWriter("/nfs/sgururaj/Downloads/op.txt", "UTF-8");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        int C = sc.nextInt();
        //l(C);
        for(int test=1; test<=C; test++) {
            int N = sc.nextInt();
            int[][]g = new int[N][N];
            for(int i=0; i<N-1; i++) {
                int x = sc.nextInt()-1;
                int y = sc.nextInt()-1;
                g[x][y] = g[y][x] = 1;
            }
            int min = Integer.MAX_VALUE;
            for(int root=0; root<N; root++) {
                int nodes = solve(N, g, root);
                min = Math.min(min, nodes);
            }
            String pr = "Case #"+test+": "+ min;
            out.println(pr);
            System.out.println(pr);
        }
        out.close();

    }

    //cost t make g at root a binary tree
    private static int solve(int N, int[][] g, int root) {
        boolean done[] = new boolean[N];
        int[]ret = dfs(N, g, root, done);
        return ret[1];
    }

    //return [count, cost]
    private static int[] dfs(int N, int[][] g, int node, boolean[] done) {
        done[node] = true;
        int children = 0;
        int deletes = 0;
        int maxa = 0, maxb  = 0;

        for(int i=0; i<N; i++) {
            if(g[node][i]==0) continue;
            if(done[i]) continue;
            children++;
            int[] ans = dfs(N, g, i, done);
            deletes+=ans[0];
            int dmk = ans[0] - ans[1];
            if(dmk>=maxa) {
                maxb = maxa;
                maxa = dmk;
            }
        }
        if(children<2) return new int[]{deletes+1, deletes};
        return new int[]{deletes+1, deletes-maxa-maxb};
    }


    public static void l(Object ...o) {
        String s = "";
        for(Object oo : o) {
            if(oo instanceof int[]) {
                s+=Arrays.toString((int[])oo)+" ";
                continue;
            }
            if(oo instanceof double[]) {
                s+=Arrays.toString((double[])oo)+" ";
                continue;
            }
            if(oo instanceof boolean[]) {
                s+=Arrays.toString((boolean[])oo)+" ";
                continue;
            }
            if(oo instanceof char[]) {
                s+=Arrays.toString((char[])oo)+" ";
                continue;
            }
            if(oo instanceof long[]) {
                s+=Arrays.toString((long[])oo)+" ";
                continue;
            }
            if(oo instanceof String[]) {
                s+=Arrays.toString((String[])oo)+" ";
                continue;
            }
            if(oo instanceof Object[]) {
                s+=Arrays.deepToString((Object[])oo)+" ";
                continue;
            }
            s += (oo.toString())+" ";
        }
        System.out.println(s);
    }
}
