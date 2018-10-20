import com.google.common.collect.Lists;
import com.google.common.io.CharStreams;


import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Created by bert on 4/26/14.
 */
public class GoogleC2B {

    public static void main(String[] args) {

            new GoogleC2B().solve(new Scanner(System.in));



    }

    public void solve(String input) {

        Scanner scan = new Scanner(input);
        solve(scan);
    }

    public void solve(Scanner scan) {

        int numberOfTestCases = scan.nextInt();

        for (int i = 0; i < numberOfTestCases; i++) {
            int numberOfNodesN = scan.nextInt();

            boolean[][] associationTable = new boolean[numberOfNodesN + 1][];
            for (int k = 0; k < associationTable.length; k++) {
                associationTable[k] = new boolean[numberOfNodesN + 1];
            }

            for (int j = 0; j < numberOfNodesN - 1 ; j++) {
                int n1 = scan.nextInt();
                int n2 = scan.nextInt();

                associationTable[n1][n2] = true;
                associationTable[n2][n1] = true;
            }

            BPTD bestTreeDepth = solve(associationTable);
            System.out.println(String.format("Case #%s: %s", i+1, bestTreeDepth.nodesToDelete));


        }
    }

    private BPTD solve(boolean[][] associationTable) {

        BPTD currentBest = new BPTD(-1, Integer.MAX_VALUE);

        for (int i = 1; i < associationTable.length; i++) {
            BPTD bestPerfectTreeDepth = bestPerfectTreeDepth(associationTable, i, -1);
            if (bestPerfectTreeDepth.treeDepth > currentBest.treeDepth) {
                if (bestPerfectTreeDepth.nodesToDelete < currentBest.nodesToDelete)
                currentBest = bestPerfectTreeDepth;
            }
        }

        return currentBest;
    }

    private BPTD bestPerfectTreeDepth(boolean[][] associationTable, int currentRoot, int comingFrom) {

        List<Integer> children = getChildren(associationTable, currentRoot, comingFrom);

        if (children.size() == 2) {
            BPTD bestPerfectLeftTree = bestPerfectTreeDepth(associationTable, children.get(0), currentRoot);
            BPTD bestPerfectRightTree = bestPerfectTreeDepth(associationTable, children.get(1), currentRoot);
            return new BPTD(Math.min(bestPerfectLeftTree.treeDepth, bestPerfectRightTree.treeDepth) + 1, bestPerfectLeftTree.nodesToDelete + bestPerfectRightTree.nodesToDelete);

        } else if (children.size() == 3) {
            BPTD[] threeTrees= new BPTD[3];

            threeTrees[0] = bestPerfectTreeDepth(associationTable, children.get(0), currentRoot);
            threeTrees[1] = bestPerfectTreeDepth(associationTable, children.get(1), currentRoot);
            threeTrees[2] = bestPerfectTreeDepth(associationTable, children.get(2), currentRoot);

            Arrays.sort(threeTrees);

            return new BPTD(threeTrees[1].treeDepth + 1, threeTrees[1].nodesToDelete + threeTrees[2].nodesToDelete);

        } else {
            return new BPTD(1, children.size());
        }

    }

    private List<Integer> getChildren(boolean[][] associationTable, int parent,  int ignoreIncoming) {
        List<Integer> children = Lists.newArrayList();

        boolean[] childrenVector = associationTable[parent];
        for (int i = 1; i < childrenVector.length; i++) {

            if ((i != ignoreIncoming) && childrenVector[i]) {
                children.add(i);
            }
        }

        return children;
    }

    public class BPTD implements Comparable<BPTD> {
        public int nodesToDelete;
        public int treeDepth;

        public BPTD(int treeDepth, int nodesToDelete) {
            this.nodesToDelete = nodesToDelete;
            this.treeDepth = treeDepth;
        }

        @Override
        public int compareTo(BPTD o) {
            if (o.treeDepth != this.treeDepth) {
                return this.treeDepth - o.treeDepth;
            } else {
                return o.nodesToDelete - this.nodesToDelete;
            }
        }
    }

}
