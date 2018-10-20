package cur;

import java.io.*;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: lisen
 * Date: 4/13/14
 * Time: 12:36 AM
 * To change this template use File | Settings | File Templates.
 */
public class GCJ_2014_B {

    public static ArrayList<ArrayList<Integer>> cur = new ArrayList<ArrayList<Integer> >();
    static int[] dp = new int[1024];

    static int dfs(int father,int index) {
        List<Integer> have = new ArrayList<Integer>();
        for (int i = 0 ; i < cur.get(index).size(); ++i) {
            if (cur.get(index).get(i) != father) {
                have.add(dfs(index, cur.get(index).get(i)));
                //have.push_back(help(x, con[x][i]));
            }

        }
        if (have.size() < 2) {
            return dp[index] = 1;
        }
        Collections.sort(have);
        return dp[index] = 1 + have.get(have.size() - 1) + have.get(have.size() - 2);

    }

    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = new FileInputStream("/Users/lisen/Downloads/B-large.in");
        OutputStream outputStream =  new FileOutputStream("/Users/lisen/Downloads/B-large.output");;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int caseNumber = in.nextInt();
        for (int ii = 1 ; ii <= caseNumber; ++ii){
            int n = in.nextInt();
            cur.clear();
            for (int i = 0; i < n; ++i) {
                ArrayList<Integer> t = new ArrayList<Integer>();
                cur.add(t);
            }
            for (int i = 1; i < n; ++i) {
                int x = in.nextInt();
                int y = in.nextInt();
                --x;
                --y;
                cur.get(x).add(y);
                cur.get(y).add(x);
            }
            int may = 0;
            for (int i = 0; i < n; ++i) {
                may = Math.max(may, dfs(-1, i));
            }
            int res = n - may;
            out.write("Case #" + ii + ": " + " " + res + "\n");
            out.flush();
        }
        out.close();

    }
}
