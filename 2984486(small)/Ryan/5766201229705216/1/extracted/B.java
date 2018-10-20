import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.io.BufferedReader;

public class B{
  private static final int ORPHAN=-1;

  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    for(int t=0;t<cases;t++){
      int n=solve(readTree(scanner));
      System.out.println("Case #"+(t+1)+": "+n);
    }
  }

  private static int solve(ArrayList<Integer>[] adjList){
    int best=adjList.length;
    for(int i=0;i<adjList.length;i++)
      best=Math.min(best,solve(adjList,i));
    return best;
  }

  private static ArrayList[] readTree(Scanner scanner){
    int nodes=scanner.nextInt();
    ArrayList<Integer>[] adjList=(ArrayList<Integer>[])new ArrayList[nodes];
    for(int i=0;i<nodes;i++)
      adjList[i]=new ArrayList<Integer>();
    for(int i=1;i<nodes;i++){
      int a=scanner.nextInt()-1;
      int b=scanner.nextInt()-1;
      adjList[a].add(b);
      adjList[b].add(a);
    }
    return adjList;
  }


  static public class Answer{
    public int nodes;
    public int deletes;
  }

  private static int solve(ArrayList<Integer>[] adjList,int root){
    Answer a=dfs(adjList,root,ORPHAN);
    //System.out.println(" With root: "+root+" answer is "+a.deletes);
    return a.deletes;
  }

  private static Answer dfs(ArrayList<Integer>[] adjList,int node,int parent){
    Answer ret=new Answer();
    ret.nodes=1;
    ret.deletes=0;

    ArrayList<Answer> children=new ArrayList<Answer>();

    for(int i=0;i<adjList[node].size();i++){
      int child=adjList[node].get(i);
      if(child==parent)
        continue;
      Answer a=dfs(adjList,child,node);
      children.add(a);
      ret.nodes+=a.nodes;
    }

    int childrenCount=children.size();
    if(childrenCount==1)
      ret.deletes=children.get(0).nodes;

    if(childrenCount<=1)
      return ret;

    int[] keeps=new int[childrenCount];
    for(int i=0;i<childrenCount;i++)
      keeps[i]=children.get(i).nodes-children.get(i).deletes;

    Arrays.sort(keeps);
    ret.deletes=ret.nodes-1-keeps[childrenCount-1]-keeps[childrenCount-2];
    return ret;
  }
}
