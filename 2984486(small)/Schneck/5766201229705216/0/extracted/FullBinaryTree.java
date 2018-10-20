
import java.io.*;
import java.util.*;

public class FullBinaryTree {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int N = scan.nextInt();
        
        Node[] nodes = new Node[N+1];
        for (int i = 1; i <= N; i++) {
            nodes[i] = new Node();
            nodes[i].number = i; 
        }
        
        for (int i = 0; i < N - 1; i++) {
            line = in.readLine();
            scan = new Scanner(line);
            int a = scan.nextInt();
            int b = scan.nextInt();
            nodes[a].links.add(b);
            nodes[b].links.add(a);
        }
        
        int least = Integer.MAX_VALUE;
        for (int root = 1; root <= N; root++) {
            //System.out.println("ROOT " + root);
            processOut(N, nodes, -1, root);
            int howMany = nodes[root].numDeleteToMakeFBT;
            if (howMany < least) least = howMany;
            if (least == 0) break;
        }
        
        System.out.println(least);
    }
    
    void processOut(int N, Node[] nodes, int parent, int child) {
        for (int a : nodes[child].links) {
            if (a == parent) continue;
            processOut(N, nodes, child, a);
        }
        
        nodes[child].numInTree = 1;
        for (int a : nodes[child].links) {
            if (a == parent) continue;
            nodes[child].numInTree += nodes[a].numInTree;
        }
        //System.out.println(child + " size=" + nodes[child].numInTree);
        
        int size = nodes[child].links.size();
        if (parent > 0) size--;
        if (size == 0 || size == 2) {
            nodes[child].numDeleteToMakeFBT = 0;
            for (int a : nodes[child].links) {
                if (a == parent) continue;
                nodes[child].numDeleteToMakeFBT += nodes[a].numDeleteToMakeFBT;
            }
            //System.out.println(child + " nd=0*");
        } else if (size == 1) {
            nodes[child].numDeleteToMakeFBT = nodes[child].numInTree - 1;
            //System.out.println(child + " nd=*" + (nodes[child].numInTree-1));
        } else {
            int least = Integer.MAX_VALUE;
            for (int a : nodes[child].links) {
                if (a == parent) continue;
                for (int b : nodes[child].links){
                    if (b == parent || a == b) continue;
                    int val = nodes[child].numInTree - 1 - nodes[a].numInTree + nodes[a].numDeleteToMakeFBT - nodes[b].numInTree + nodes[b].numDeleteToMakeFBT;
                    if (val < least) least = val;
                }
            }
            nodes[child].numDeleteToMakeFBT = least;
            //System.out.println(child + " nd=" + least);
        }
        
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new FullBinaryTree().run();
    }

    static class Node {
        int number;
        List<Integer> links = new ArrayList<Integer>();
        int numInTree;
        int numDeleteToMakeFBT;
    }
    
}
