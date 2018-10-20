import java.util.*;
import java.io.*;

public class FullBinaryTree {
	public static void main(String[] args)throws IOException {
		Scanner kb = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("full_binary.out"));
		int cases = kb.nextInt();
		
		for(int i=1; i <= cases; i++) {
			int nodes = kb.nextInt();
			MyGraph graph = new MyGraph(nodes);
			for(int j=1; j < nodes; j++) {
				graph.addConn(kb.nextInt()-1, kb.nextInt()-1);
			}
			int min = nodes;
			for(int j=0; j < nodes; j++) {
				int toDel = graph.findMin(j, -1);
				if(toDel < min)
					min = toDel;
			}
			out.println("Case #" + i + ": "+min);
		}
		out.close();
	}
}

class MyGraph {
	MyNode[] nodes;
	public MyGraph(int size) {
		nodes = new MyNode[size];
		for(int i=0; i < size; i++)
			nodes[i] = new MyNode();
	}
	public void addConn(int a, int b) {
		//System.out.println("here1");
		nodes[a].conns.add(b);
		//System.out.println("here2");
		nodes[b].conns.add(a);
	}
	public int findMin(int ind, int par) {
		int numChild = nodes[ind].conns.size();
		if(par != -1)
			numChild--;
		if(numChild == 0)
			return 0;
		if(numChild == 1){
			int ret = 0;
			for(Integer i: nodes[ind].conns)
				if(i != par)
					ret += totChild(i, ind);
			return ret;
		}
		if(numChild == 2){
			int ret = 0;
			for(Integer i: nodes[ind].conns)
				if(i != par)
					ret += findMin(i, ind);
			return ret;
		}
		ArrayList<Integer> numKeeps = new ArrayList<Integer>();
		for(Integer i: nodes[ind].conns)
			if(i != par)
				numKeeps.add(totChild(i, ind) - findMin(i, ind));
		Collections.sort(numKeeps);
		Collections.reverse(numKeeps);
		int tot = totChild(ind, par) - 1;
		return tot - numKeeps.get(0) - numKeeps.get(1);
		
	}
	public int totChild(int ind, int par) {
		int tot = 1;
		for(Integer i: nodes[ind].conns)
			if(i != par)
				tot += totChild(i, ind);
		return tot;
	}
}

class MyNode {
	ArrayList<Integer> conns;
	public MyNode() {
		conns = new ArrayList<Integer>();
	}
}