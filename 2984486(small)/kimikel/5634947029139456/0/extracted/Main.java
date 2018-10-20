import java.io.*;
import java.util.*;

public class Main {
    
    static int n, l;
    static String outlets[], devices[];
    
    public static void main(String args[]) throws FileNotFoundException {
        
        final Scanner in = new Scanner(new File("/home/mikel/Desktop/codejam/Round1A/input.txt"));
        final PrintWriter out = new PrintWriter(new File("/home/mikel/Desktop/codejam/Round1A/output.txt"));
        
        final int t = in.nextInt();
        for (int it = 1; it <= t; it++) {
            n = in.nextInt();
            l = in.nextInt();
            in.nextLine();
            outlets = new String[n];
            devices = new String[n];
            for (int i = 0; i < n; i++) outlets[i] = in.next();
            for (int i = 0; i < n; i++) devices[i] = in.next();
            
            // igarren devicea jgarren outletean jartzea posible?
            final boolean[][] possible = new boolean[n][n];
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) possible[i][j] = true;
            
            int result = solve(possible, 0, 0);
            
            out.print("Case #" + it + ": ");
            if (result == -1) out.println("NOT POSSIBLE");
            else out.println(result);
        }
        
        out.close();
    }
    
    public static int solve(boolean[][] possible, int pos, int currentResult) {
        if (pos > 0) {
            for (int i = 0; i < n; i++) {
                boolean found = false;
                for (int j = 0; j < n; j++) {
                    if (possible[i][j]) {
                        found = true;
                        break;
                    }
                }
                if (!found) return -1;
            }
        }
        
        if (pos == l) return currentResult;
        
        boolean switchedPossible[][] = clone(possible, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (possible[i][j]) {
                    if (devices[i].charAt(pos) != outlets[j].charAt(pos)) {
                        possible[i][j] = false;
                    } else {
                        switchedPossible[i][j] = false;
                    }
                }
            }
        }
        
        int x = solve(possible, pos+1, currentResult);
        int y = solve(switchedPossible, pos+1, currentResult+1);
        
        if (x == -1 && y == -1) return -1;
        else if (x == -1) return y;
        else if (y == -1) return x;
        else return Math.min(x, y);
    }
    
    public static boolean[][] clone(boolean[][] arg, int length) {
        boolean res[][] = new boolean[length][length];
        for (int i = 0; i < length; i++) for (int j = 0; j < length; j++) res[i][j] = arg[i][j];
        return res;
    }
    
    
}