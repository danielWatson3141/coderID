import java.util.*;

public class B {
  
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int k = 1; k <= T; k++) {
      int N = in.nextInt();
      List<List<Integer>> list = new ArrayList<List<Integer>>();
      for (int i = 0; i < N + 1; i++) {
        list.add(new ArrayList<Integer>());
      }
      for (int i = 0; i < N - 1; i++) {
        int n1 = in.nextInt();
        int n2 = in.nextInt();
        list.get(n1).add(n2);
        list.get(n2).add(n1);
      }
      int min = 99999;
      for (int i = 1; i <= N; i++) {
        List<List<Integer>> newList = new ArrayList<List<Integer>>();
        for (int j = 0; j < N + 1; j++) {
           newList.add(new ArrayList<Integer>(list.get(j)));
        }
        //System.out.println(newList);
        int curr = makeFull(i, newList, 0);
        //System.out.println("i curr " + i + " " + curr);
        min = Math.min(min, curr);
      }
      System.out.printf("Case #%d: %d\n", k, min);
    }
    in.close();
  }
  
  private static int prune(int i, List<List<Integer>> adjList, int count) {
    List<Integer> children = adjList.get(i);
   // System.out.println("prune! " + i + " " + children + " " + count);
    for (Integer c : children) {
      for (Integer r : adjList.get(c)) {
        if (r == i) {
          adjList.get(c).remove(adjList.get(c).indexOf(r));
          break;
        }
      }
    }
    if (children.size() == 0) {
      return 1;
    }
    for (Integer c : children) {
      count += prune(c, adjList, 1);
    }
    return count;
  }
  
  private static int makeFull(int i, List<List<Integer>> adjList, int count) {
    List<Integer> children = adjList.get(i);
   // System.out.println("here! " + i + " " + children + " " + count);
    for (Integer c : children) {
      for (Integer r : adjList.get(c)) {
        if (r == i) {
          adjList.get(c).remove(adjList.get(c).indexOf(r));
          break;
        }
      }
    }
    if (children.size() == 0) {
      return count;
    }
    if (children.size() == 1) {
      return count + prune(children.get(0), adjList, 1);
    }
    if (children.size() > 2) {
      int min = 99999;
      int picked1, picked2;
      for (int j = 0; j < children.size(); j++) {
        for (int k = j + 1; k < children.size(); k++) {
          List<List<Integer>> newList = new ArrayList<List<Integer>>();
          for (int l = 0; l < adjList.size(); l++) {
             newList.add(new ArrayList<Integer>(adjList.get(l)));
          }
          int currCount = count;
          currCount = makeFull(children.get(j), newList, currCount);
          currCount = makeFull(children.get(k), newList, currCount);
          for (int l = 0; l < children.size(); l++) {
            if (l != j && l != k) {
              currCount += prune(children.get(l), newList, 1);
            }
          }
          if (currCount < min) {
            min = currCount;
            picked1 = children.get(j);
            picked2 = children.get(k);
          }
        }
      }
     // System.out.println(i + " " + min);
      return min;
    }
    //System.out.println("count now " + count);
    count = makeFull(adjList.get(i).get(0), adjList, count);
    count = makeFull(adjList.get(i).get(1), adjList, count);
    //System.out.println("count " + count);
    return count;
  }
}
