import java.io.File;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Lazar on 26/04/2014.
 */
public class Round1C {
    private Scanner in;
    private PrintWriter out;

    public void run() throws Exception{
        String fileName = "B_small";
        in = new Scanner(new File("InputFiles\\" + fileName+ ".in"));
        out = new PrintWriter("OutputFiles\\" + fileName + ".out");


        int T = in.nextInt();
        for(int i=0; i<T; i++)
        {
            solve();
            out.println(String.format("Case #%d: %d", i+1, minDeletion));
        }
        in.close();
        out.flush();
        out.close();
    }

    Map<Integer, List<Integer>> graph;
    int minDeletion = -1;
    int currentDeletionCount = 0;

    private int solve() {
        int N = in.nextInt();
        graph = new HashMap<Integer, List<Integer>>();

        for(int i=0; i<N-1; i++)
        {
            int X = in.nextInt();
            int Y = in.nextInt();

            addToGraph(X, Y);
            addToGraph(Y, X);
        }

        minDeletion = -1;
        for(int i : graph.keySet())
        {
            currentDeletionCount = makeBinaryTree(-1, i);
            if(currentDeletionCount < minDeletion || minDeletion == -1)
            {
                minDeletion = currentDeletionCount;
            }
        }
        return minDeletion;
    }

    private int makeBinaryTree(int parent, int current){

        List<Integer> children = graph.get(current);
        int childrenCount = parent == -1 ? children.size() : children.size()-1;
        if(childrenCount==0)
            return 0;
        if(childrenCount==1)
        {
            for(int child : children)
            {
                if(child != parent)
                    return deleteNode(current, child);
            }
        }
        else if(childrenCount==2)
        {
            int tempDeletionsCount = 0;
            for(int child : children)
                if(child != parent)
                    tempDeletionsCount += makeBinaryTree(current, child);
            return tempDeletionsCount;
        }
        else {
            List<Integer> results_make = new ArrayList<Integer>();
            List<Integer> results_del = new ArrayList<Integer>();
            for (int child : children)
            {
                if (child != parent) {
                    results_make.add(makeBinaryTree(current, child));
                    results_del.add(deleteNode(current, child));
                }
            }
            int tempMinimumDeletion = -1;
            for(int i=0; i<results_make.size(); i++)
            {
                for(int y=0; y<results_make.size(); y++)
                {
                    if(i==y)
                        continue;
                    int tempCurrDel = 0;
                    tempCurrDel += results_make.get(i);
                    tempCurrDel += results_make.get(y);
                    for(int z=0; z<results_make.size(); z++)
                    {
                        if(z == i || z == y)
                            continue;
                        tempCurrDel += results_del.get(z);
                    }
                    if(tempCurrDel<tempMinimumDeletion || tempMinimumDeletion==-1)
                        tempMinimumDeletion = tempCurrDel;
                }
            }
            return tempMinimumDeletion;
        }
        // shouldn't get to this
        return -1;
    }

    private int deleteNode(int parent, int current)
    {
        List<Integer> children = graph.get(current);
        int childrenCount = parent == -1 ? children.size() : children.size() - 1;
        if(childrenCount==0)
            return 1;

        int tempDelCount = 1;
        for(int child : children)
        {
            if(child != parent)
                tempDelCount += deleteNode(current, child);
        }
        return tempDelCount;
    }

    private void addToGraph(int from, int to){
        List<Integer> list = graph.get(from);
        if(list==null)
        {
            list = new ArrayList<Integer>();
            list.add(to);
            graph.put(from, list);
        }
        else
        {
            list.add(to);
        }
    }

    public static void main(String[] args) throws Exception{
        new Round1C().run();
    }
}
