package round1AProblemA;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class Main {
  
  private static Map<Set<String>, Integer> visited = new HashMap<>();
  private static int N;
  private static int L;
  
  private static List<Set<String>> neighbors(Set<String> v, int l) {
    List<Set<String>> ns = new ArrayList<>();
    for (int i = 0; i < L; i++) { // For each column
      Set<String> n = new HashSet<>();
      //System.out.println("n(" + v +")");
      for (String s : v) { // For each string
        char newChar = s.charAt(i) == '0' ? '1' : '0';
        String sn = s.substring(0,i) + newChar + s.substring(i + 1);
        n.add(sn);
        //System.out.println("added " + sn + ": " + n);
      }
      if (!visited.containsKey(n)) {
        ns.add(n);
        visited.put(n, l);
      }
    }
    return ns;
  }
  
  public static void main(String[] args) 
      throws NumberFormatException, IOException {
    
    PrintWriter    out = null;
    BufferedReader in  = null;
    
    try {
      // Parse input.
      //in  = new BufferedReader(new FileReader("input.txt"));
      in  = new BufferedReader(new FileReader("A-small-attempt1.in"));
      out = new PrintWriter(new FileWriter("output.txt"));
      
      int numTestCases = Integer.parseInt(in.readLine());
      for (int i = 0; i < numTestCases; i++) {
        System.out.println("case " + (i+1));
        String[] NL = in.readLine().split(" ");
        N = Integer.parseInt(NL[0]);
        L = Integer.parseInt(NL[1]);
        
        List<String> outs = Arrays.asList(in.readLine().split(" "));
        List<String> reqs = Arrays.asList(in.readLine().split(" "));
        Set<String> requirements = new HashSet<>();
        Set<String> outlets      = new HashSet<>();
        
        Queue<Set<String>> frontier = new LinkedList<>();
        Queue<Integer> frontierLevels = new LinkedList<>();
        for (String req : reqs) {
          requirements.add(req);
        }
        for (String o : outs) {
          outlets.add(o);
        }
        
        frontier.add(outlets);
        visited.put(outlets, 0);
        //frontierLevels.add(0);
        //System.out.println(requirements);
        boolean success = false;
        int myLevel = 0;
        while (!frontier.isEmpty()) {
          Set<String> current = frontier.remove();
          int level = visited.get(current);
          if (level < myLevel)
            System.out.println("Invariant violation");
          if (level - myLevel > 1)
            System.out.println("Invariant violation2");
          myLevel = level;
          
          if (current.containsAll(requirements)) {
            System.out.println("Success in " + level + " moves!");
            success = true;
            out.print("Case #" + (i + 1) + ": " + level);
            break;
          }
          
          List<Set<String>> ns = neighbors(current, level + 1);
          for (Set<String> n : ns) {
            frontier.add(n);
            //frontierLevels.add(level + 1);
          }
        }
        if (!visited.containsKey(requirements)) {
          System.out.println(" failed");
        } else {
          System.out.println(visited.get(requirements));
        }
        //if (visited.contains(o))
        
        if (!success) {
          out.print("Case #" + (i + 1) + ": NOT POSSIBLE");
        }
        
        out.println(" ");
      }
    } finally {
      out.close();
      in.close();
    }
  }
}
