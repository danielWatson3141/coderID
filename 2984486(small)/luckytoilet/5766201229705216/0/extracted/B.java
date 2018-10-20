
import java.util.*;

public class B{


  static class Node{

    ArrayList<Node> children = new ArrayList<Node>();
    int val = 0;

    Node(int v){
      val = v;
    }

    // adds and returns child node
    Node addChild(int ch){
      Node r = new Node(ch);
      children.add(r);
      return r;
    }

    String str(){

      String s = "";
      s += "" + val;

      for(Node node : children){
        s += "(" + node.str() + ")";
      }

      return s;
    }


    // including this one
    int size(){
      int sum = 1;
      for(Node node : children){
        sum += node.size();
      }
      return sum;
    }


    int recurse(){

      if(children.size() == 0) return 0;
      if(children.size() == 1) return children.get(0).size();
      if(children.size() == 2) return children.get(0).recurse() + children.get(1).recurse();

      // more than 2

      ArrayList<Integer> size_list = new ArrayList<>();
      ArrayList<Integer> recur_list = new ArrayList<>();

      for(Node node : children){
        size_list.add(node.size());
        recur_list.add(node.recurse());
      }

      // pick i,j to minimize i.recur + j.recur + sum(x.size)
      int min = 999999;
      for(int i=0; i<children.size(); i++){
        for(int j=0; j<children.size(); j++){
          if(i==j) continue;
          int s = 0;
          s += recur_list.get(i);
          s += recur_list.get(j);
          for(int k=0; k<children.size(); k++){
            if(k == i || k == j) continue;
            s += size_list.get(k);
          }
          if(s < min)
            min = s;
        }
      }

      return min;

    }

  }


  static int compute_with_root(ArrayList<Integer> edges1, ArrayList<Integer> edges2, int root){

    int N = edges1.size()+1;

    HashMap<Integer,Node> dict_nodes = new HashMap<>();

    // construct fucking tree
    Node root_node = new Node(root);
    dict_nodes.put(root,root_node);

    while(true){
      boolean loopAgain = false;
      for(int i=0; i<edges1.size();i++){

        int v1 = edges1.get(i);
        int v2 = edges2.get(i);

        boolean contains1 = dict_nodes.containsKey(v1);
        boolean contains2 = dict_nodes.containsKey(v2);

        if(contains1 && contains2) continue;
        else if(contains1){
          // contains v1, add v2 to child of v1
          Node newNode = dict_nodes.get(v1).addChild(v2);
          dict_nodes.put(v2,newNode);
        }
        else if(contains2){
          // contains v2, add v1 to child of v2
          Node newNode = dict_nodes.get(v2).addChild(v1);
          dict_nodes.put(v1,newNode);
        }
        else{
          loopAgain = true;
        }

      }

      if(!loopAgain) break;
    }

    if(root_node.size() != N){
      System.out.println("massive bug! " + root + " " + root_node.size() + " " + N);
    }


    return root_node.recurse();

  }


  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int ncases = sc.nextInt();

    for(int nc=1;nc<=ncases;nc++){

      int num_nodes = sc.nextInt();
      ArrayList<Integer> edges1 = new ArrayList<>();
      ArrayList<Integer> edges2 = new ArrayList<>();

      for(int i=0; i<num_nodes-1; i++){
        edges1.add(sc.nextInt());
        edges2.add(sc.nextInt());
      }

      int min = 100000;
      for(int i=1; i<=num_nodes;i++){
        int c = compute_with_root(edges1,edges2,i);
        if(c<min){
          min=c;
        }
      }

      System.out.println("Case #" + nc + ": " + min);
      
    }

  }
}
