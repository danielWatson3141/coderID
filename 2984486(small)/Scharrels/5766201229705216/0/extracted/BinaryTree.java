import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.*;

public class BinaryTree {
    Scanner input;
    PrintWriter output;
    boolean tree[][];
    int edges[];

    public BinaryTree(Scanner input, PrintWriter output){
        this.input = input;
        this.output = output;

    }

    public void solveProblem(int testCase){
        int nodes = input.nextInt();
        tree = new boolean[nodes][nodes];
        for(int i = 0; i < nodes - 1; i++){
            int start = input.nextInt() - 1;
            int end = input.nextInt() - 1;
            tree[start][end] = true;
            tree[end][start] = true;
        }

        if(nodes == 1 || nodes == 3){ // these trees are always correct
            output.println("Case #" + testCase + ": 0");
            return;
        } else if(nodes == 2){ // always remove one of the nodes
            output.println("Case #" + testCase + ": 1");
            return;
        }


        edges = new int[nodes];
        int numRoots = 0;
        for(int node = 0; node < nodes; node++){
            for(int edge = 0; edge < nodes; edge++){
                if(tree[node][edge]){
                    edges[node]++;
                }
            }
            if(edges[node] == 2){ // this is a possible root node
                numRoots++;
            }
        }

        if(numRoots == 0){
            output.println("Case #" + testCase + ": 1"); // remove 1 leaf to create a root node
            return;
        } else if(numRoots == 1){
            output.println("Case #" + testCase + ": 0"); // this tree is already a binary tree
            return;
        }

        int maxSize = 0;
        for(int rootNode = 0; rootNode < nodes; rootNode++){
            int size = binaryTreeSize(rootNode);
            if(size > maxSize){
                maxSize = size;
            }
        }
        int nodesToRemove = nodes - maxSize;

        output.println("Case #" + testCase + ": " + nodesToRemove); // this tree is already a binary tree
    }

    private int binaryTreeSize(int rootNode) {
        List<Integer> nodesProcessed = new ArrayList<>();
        nodesProcessed.add(rootNode);
        Queue<Integer> nodesToProcess = new LinkedList<>();
        int size = 1;
        for(int edge = 0; edge < tree.length; edge++){
            if(tree[rootNode][edge]){
                nodesToProcess.add(edge);
            }
        }
        while(!nodesToProcess.isEmpty()){
            int node = nodesToProcess.poll();
            nodesProcessed.add(node);
            size++;
            if(edges[node] == 3){ // correct intermediate node; continue searching
                for(int edge = 0; edge < tree.length; edge++){
                    if(tree[node][edge] && !nodesProcessed.contains(edge)){
                        nodesToProcess.add(edge);
                    }
                }
            }
        }
        return size;
    }

    public static void main(String[] args){
        final long startTime = System.currentTimeMillis();
        File file = new File("binarytree.in");
        Scanner input = null;
        try {
            input = new Scanner(file).useLocale(Locale.US);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        PrintWriter output = null;
        try {
            output = new PrintWriter("binarytree.out", "UTF-8");
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        int problems = input.nextInt();
        input.nextLine();
        for(int i = 1; i <= problems; i++){
            new BinaryTree(input, output).solveProblem(i);
        }
        output.close();
        final long endTime = System.currentTimeMillis();
//        System.out.println("Total execution time: " + (endTime - startTime) + " ms");
    }
}
