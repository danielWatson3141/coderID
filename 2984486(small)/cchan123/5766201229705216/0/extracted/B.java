import java.util.*;
import java.io.*;
public class B
{
  static int min=9999;
  static int tries=0;
  public static boolean isBinaryTree(ArrayList<ArrayList<Integer>>tree)
  {
    tries++;
    boolean empty=true;
    for(int x=1;x<tree.size();x++)
      if(tree.get(x).size()!=0)
    {
      empty=false;
      break;
    }
    if(empty)
      return true;
    for(int x=1;x<tree.size();x++)
      //for(int x=2;x<=2;x++)
    {
      ArrayList<Integer> q=new ArrayList<Integer>();
      q.add(x);
      boolean good=true;
      int[]pre=new int[tree.size()];
      for(int y=1;y<tree.size();y++)
        pre[y]=-1;
      while(!q.isEmpty())
      {
        //System.out.println(x+" "+q.get(0));
        if(tree.get(q.get(0)).size()==2)
        {
          for(int y=0;y<2;y++)
          {
            if(pre[tree.get(q.get(0)).get(y)]==-1)
            {
              q.add(tree.get(q.get(0)).get(y));
              pre[tree.get(q.get(0)).get(y)]=q.get(0);
            }
            else
            {
              good=false;
              break;
            }
          }
        }
        else if(tree.get(q.get(0)).size()==1)
        {
          if(tree.get(q.get(0)).get(0)!=pre[q.get(0)])
          {
            good=false;
            break;
          }
        }
        else if(tree.get(q.get(0)).size()==3)
        {
          int temp=0;
          for(int y=0;y<3;y++)
          {
            if(tree.get(q.get(0)).get(y)!=pre[q.get(0)])
            {
              if(pre[tree.get(q.get(0)).get(y)]==-1)
              {
                q.add(tree.get(q.get(0)).get(y));
                pre[tree.get(q.get(0)).get(y)]=q.get(0);
              }
              else
              {
                good=false;
                break;
              }
              temp++;
            }
          }
          if(temp!=2)
          {
            good=false;
            break;
          }
        }
        else
        {
          good=false;
          break;
        }
        q.remove(0);
      }
      if(good)
      {
        //System.out.println("x "+x);
        return true;
      }
    }
    return false;
  }
  public static ArrayList<ArrayList<Integer>> listmaker(ArrayList<ArrayList<Integer>> treeclone)
  {
    ArrayList<ArrayList<Integer>>tree=new ArrayList<ArrayList<Integer>>();
    for(int x=0;x<treeclone.size();x++)
    {
      tree.add((ArrayList<Integer>)(treeclone.get(x).clone()));
    }
    return tree;
  }
  public static void remover(ArrayList<ArrayList<Integer>> tree,int changes,int index)
  {
    if(changes>=min)
      return;
    if(isBinaryTree(tree))
    {
      min=Math.min(min,changes);
      return;
    }
    for(int x=index+1;x<tree.size();x++)
    {
      if(changes>=min)
          return;
      if(tree.get(x).size()==1)
      {
        ArrayList<ArrayList<Integer>> treetemp=listmaker(tree);
        for(int y=0;y<treetemp.size();y++)
          treetemp.get(y).remove(new Integer(x));
        treetemp.get(x).clear();
        //System.out.println(x+" "+treetemp+" "+(changes+1));
        remover(treetemp,changes+1,x);
      }
    }
  }
  public static void remover2(ArrayList<ArrayList<Integer>> tree,int changes)
  {
    if(tries>1000000)
      return;
    if(changes>=min)
      return;
    if(isBinaryTree(tree))
    {
      min=Math.min(min,changes);
      return;
    }
    for(int x=1;x<tree.size();x++)
    {
      if(changes>=min)
          return;
      if(tree.get(x).size()==1)
      {
        ArrayList<ArrayList<Integer>> treetemp=listmaker(tree);
        for(int y=0;y<treetemp.size();y++)
          treetemp.get(y).remove(new Integer(x));
        treetemp.get(x).clear();
        //System.out.println(x+" "+treetemp+" "+(changes+1));
        remover2(treetemp,changes+1);
      }
    }
  }
  public static void main(String[]args)throws IOException
  {
    Scanner in=new Scanner(new FileReader("B-small-attempt3.in"));
    PrintWriter out=new PrintWriter(new FileWriter("B.out"));
    int n=in.nextInt();
    
    for(int asd=1;asd<=n;asd++)
      //for(int asd=1;asd<=1;asd++)
    {
      out.print("Case #"+asd+": ");
      min=9999;
      int nodes=in.nextInt();
      ArrayList<ArrayList<Integer>>connections=new ArrayList<ArrayList<Integer>>();
      for(int x=0;x<nodes+1;x++)
        connections.add(new ArrayList<Integer>());
      for(int x=0;x<nodes-1;x++)
      {
        int a=in.nextInt();
        int b=in.nextInt();
        connections.get(a).add(b);
        connections.get(b).add(a);
      }
        //System.out.println(connections);
      //remover(connections,0,-1);
      tries=0;
      if(min==9999)
        remover2(connections,0);
      out.println(min);
      out.flush();
    }
    in.close();
    out.close();
  }
}