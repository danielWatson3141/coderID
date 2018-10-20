package yudhi.pkg;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by yudhi on 26-4-2014.
 */
public class FullBinaryTree {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        for (int caseNo = 1; caseNo <= cases; caseNo++) {
            int nodes = scanner.nextInt();
            int[]  nodesConn = new int[nodes];
            ArrayList<Integer>[] connectedTo = new ArrayList[nodes];
            for (int i=0; i<(nodes-1); i++)
            {
                int node1 = scanner.nextInt()-1;
                int node2 = scanner.nextInt()-1;
                nodesConn[node1] ++;
                nodesConn[node2] ++;
                //if ()
                //connectedTo[node1].add(node2);
                //connectedTo[node2].add(node1);


            }
            int cnt =0;
            int rootCnt = 0;
            for (int i=0; i<nodes; i++)
            {
                if (nodesConn[i]>3)
                {
                    cnt+= nodesConn[i]-3;

                }
                if (nodesConn[i]==2)
                {
                    rootCnt++;
                }
            }
            if (rootCnt==0) cnt++;
            if (rootCnt>1) cnt+=rootCnt-1;
            System.out.println("Case #" + caseNo+": "+cnt);
        }
    }
}
