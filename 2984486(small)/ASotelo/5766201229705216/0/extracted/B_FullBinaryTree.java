// Author: Alejandro Sotelo Arevalo
package round1;

import java.io.*;
import java.util.*;

public class B_FullBinaryTree {
  // --------------------------------------------------------------------------------
  private static String ID="B";
  private static String NAME="small-attempt1";
  private static String STAGE="round1";
  private static boolean STANDARD_OUTPUT=false;
  // --------------------------------------------------------------------------------
  private static BufferedReader reader=null;
  private static PrintStream output=null;
  // --------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    try (BufferedReader bufferedReader=reader=new BufferedReader(new FileReader(new File("data/"+STAGE+"/"+ID+"-"+NAME+".in")))) {
      try (PrintStream printStream=output=STANDARD_OUTPUT?System.out:new PrintStream(new File("data/"+STAGE+"/"+ID+"-"+NAME+".out"))) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static void process() throws Throwable {
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      int N=Integer.parseInt(reader.readLine());
      @SuppressWarnings("unchecked")
      List<Integer>[] ady=new List[N];
      for (int v=0; v<N; v++) {
        ady[v]=new ArrayList<>();
      }
      for (int z=1; z<N; z++) {
        String w[]=reader.readLine().split(" +");
        int v1=Integer.parseInt(w[0])-1,v2=Integer.parseInt(w[1])-1;
        ady[v1].add(v2);
        ady[v2].add(v1);
      }
      int min=N;
      for (int d=0,D=1<<N; d<D; d++) {
        boolean ok=true;
        int count[]=new int[4];
        List<Integer> nodes=new ArrayList<>();
        for (int v=0; v<N; v++) {
          if (((d>>>v)&1)==1) nodes.add(v);
        }
        if (nodes.isEmpty()) continue;
        @SuppressWarnings("unchecked")
        List<Integer>[] ady2=new List[N];
        for (int v=0; v<N; v++) {
          List<Integer> list=new ArrayList<>(ady[v]);
          list.retainAll(nodes);
          if (!nodes.contains(v)) list.clear();
          if (list.size()>=count.length) ok=false;
          else if (nodes.contains(v)) count[list.size()]++;
          ady2[v]=list;
        }
        if (nodes.size()>1) {
          if (count[2]!=1) ok=false;
          if (count[0]!=0) ok=false;
        }
        Deque<Integer> deque=new ArrayDeque<>();
        Set<Integer> visited=new HashSet<>();
        int first=nodes.iterator().next();
        deque.add(first);
        visited.add(first);
        while (!deque.isEmpty()) {
          int v1=deque.removeFirst();
          for (int v2:ady2[v1]) {
            if (!visited.contains(v2)) {
              deque.add(v2);
              visited.add(v2);
            }
          }
        }
        if (visited.size()!=nodes.size()) ok=false;
        if (ok) min=Math.min(min,N-Integer.bitCount(d));
      }
      output.println("Case #"+c+": "+min);
    }
  }
}
