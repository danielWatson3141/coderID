package round1a;

import java.util.ArrayList;
import java.util.List;

public class FullBinaryTree {
	
	public int solve(List<Pair<String, String>> edges) {
		
		Graph graph = new Graph();
		List<Pair<String, String>> l = new ArrayList<Pair<String,String>>();
		for(Pair<String, String> p : edges) {
			
			l.add(new Pair(p.getRight(), p.getLeft()));
			
		}
		edges.addAll(l);
		graph.setGraph(edges);
		int ans = Integer.MAX_VALUE;
		for(int v : graph.V) {
			
			int dfs = graph.dfs(v);
			ans = Math.min(ans, l.size() + 1 - dfs);
			
		}
		return ans;
		
	}

}
