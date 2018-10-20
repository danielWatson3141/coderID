import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: udit.aga
 * Date: 4/26/14
 * Time: 8:15 AM
 * To change this template use File | Settings | File Templates.
 */
public class FullBinaryTree {
    private static BufferedReader bufferedReader;
    private static BufferedWriter bufferedWriter;
    private static int N;
    private static List<List<Integer>> edges;


    public static void main(String[] args) throws IOException {
        bufferedReader = new BufferedReader(new FileReader("C:\\Users\\udit.aga\\Downloads\\B-small-attempt0.in"));
        bufferedWriter = new BufferedWriter(new FileWriter("C:\\Users\\udit.aga\\Downloads\\out1.txt"));
        int T = readInt();
        int k=0;
        while (T > 0){
            T--;
            k++;
            N = readInt();
            edges = loadEdges();
            int minNodesToDelete = findMinimumNumberOfNodesToDelete(edges);

            bufferedWriter.write("Case #"+k+": "+minNodesToDelete+"\n");
            bufferedWriter.flush();
        }
        bufferedWriter.close();
        bufferedReader.close();
        return;
    }

    private static int findMinimumNumberOfNodesToDelete(List<List<Integer>> edges) {
        int minNodesToDelete = N;
        for(int i=0;i<(N);i++){

            int root = i;
            minNodesToDelete = Math.min(minNodesToDelete,calculateNodesToDelete(root,true,-1,edges,false));
        }
        return minNodesToDelete;
    }

    private static int calculateNodesToDelete(int root, boolean isRoot, int parent, List<List<Integer>> edges, boolean toDelete) {

        if(isRoot && edges.get(root).size() == 0)
            return 0;
        if(isRoot && edges.get(root).size() != 2)
            return N-1;
        int deleteCount = 0;
        if(toDelete)
            deleteCount++;
        if(!isRoot && edges.get(root).size() != 1 && edges.get(root).size() != 3)
            toDelete = true;


        if(!isRoot && edges.get(root).size() == 1)
            return deleteCount;

        List<Integer> rootLinks = edges.get(root);
        for(int i=0;i<rootLinks.size();i++){
            if(rootLinks.get(i) != parent)
                deleteCount += calculateNodesToDelete(rootLinks.get(i),false,root,edges,toDelete);
        }
        return deleteCount;
    }

    private static List<List<Integer>> loadEdges() throws IOException {
        List<List<Integer>> edges = new ArrayList<List<Integer>>(N);
        for(int i=0;i<N;i++)
            edges.add(new ArrayList<Integer>());
        for(int i=0;i<(N-1);i++){
            int[] inputArray = readIntArray();
            int x = inputArray[0];
            int y = inputArray[1];
            edges.get(x-1).add(y-1);
            edges.get(y-1).add(x-1);
        }
        return edges;
    }

    private static int readInt() throws IOException {
        String input;
        input = bufferedReader.readLine();
        int val;
        val = Integer.parseInt(input);
        return val;
    }

    private static int[] readIntArray() throws IOException {
        String input;
        input = bufferedReader.readLine();
        String[] temp = input.split(" ");
        int[] val = new int[temp.length];
        for(int i=0;i<temp.length;i++)
            val[i] = Integer.parseInt(temp[i]);
        return val;
    }
}
