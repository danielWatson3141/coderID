package Round1A;

import java.io.*;
import java.util.*;

public class ProblemB {
	
  private static int getLen(int from, int to, LinkedList<Integer>[] edge, HashMap<String, Integer> memory){
	  if(memory.containsKey(from+"-"+to)){
		  return memory.get(from+"-"+to);
	  }
	  LinkedList<Integer> sons = new LinkedList<Integer>();
	  for(int s : edge[to]){
		  if(s!=from) sons.add(s);
	  }
	  if(sons.size()<2) return 1;
	  LinkedList<Integer> ls = new LinkedList<Integer>();
	  for(int i = 0; i<sons.size(); i++){
		  ls.add(getLen(to,sons.get(i),edge,memory));
	  }
	  Collections.sort(ls,Collections.reverseOrder());
	  return 1 + ls.get(0) + ls.get(1);
  }
	
  private static String solve(Scanner in){
  	int nodes = in.nextInt();
  	@SuppressWarnings("unchecked")
	LinkedList<Integer> edge[] = new LinkedList[nodes+1];
  	for(int i=1;i<=nodes;i++){
  		edge[i] = new LinkedList<Integer>();
  	}
  	for(int i=1;i<nodes;i++){
  		int x = in.nextInt();
  		int y = in.nextInt();
  		edge[x].add(y);
  		edge[y].add(x);
  	}
  	int max = 1;
  	for(int i=1;i<=nodes;i++){
  		HashMap<String, Integer> memory = new HashMap<String, Integer>();
  		int aux = getLen(0,i,edge,memory);
  		max = aux >  max ? aux : max;
  	}  	
  	return "" + (nodes-max);
  }

  public static void main(String[] args) {
  	String file = "Round1A\\ProblemBlarge";
  	try{
  		System.out.println(file);
  		Scanner in = new Scanner(new File(file + ".in"));
  		PrintWriter out = new PrintWriter(new File(file + ".out"));
  		int T = in.nextInt(); in.nextLine();
  		for (int i = 1; i <= T; i++) {
  			String s = "Case #" + i + ": " + ProblemB.solve(in);
  			out.println(s);
  			System.out.println(s);
  		}
  		out.close();
  	}catch(Exception e){ e.printStackTrace(); }
  }
}