import java.util.*;
import java.io.*;

public class FullBinaryTree {
	static class IntList extends ArrayList<Integer>{
		private static final long serialVersionUID = -4267284443406013080L;
	};
	
	static class Tuple{
		int node;
		int parent;
		Tuple(int node, int parent){
			this.node = node;
			this.parent = parent;
		}
		
		public int hashCode(){
			return node*1000003 + parent;
		}
		
		public boolean equals(Object o){
			if(o instanceof Tuple){
				Tuple other = (Tuple)o;
				return node == other.node && parent == other.parent;
			}
			return false;
		}
	}
	static HashMap<Tuple, Integer> cutMemo;
	static HashMap<Tuple, Integer> clearMemo;
	static IntList[] edges;

	static int cut(int node, int parent){
		Tuple hash = new Tuple(node, parent);
		if(cutMemo.containsKey(hash)){
			return cutMemo.get(hash);
		}
		int total = 1;
		for(int child : edges[node]){
			if(child == parent) continue;
			total += cut(child, node);
		}
		cutMemo.put(hash, total);
		return total;
	}
	
	static int clear(int node, int parent){
		Tuple hash = new Tuple(node, parent);
		if(clearMemo.containsKey(hash)){
			return clearMemo.get(hash);
		}
		int children;
		if(parent < 0)
			children = edges[node].size();
		else
			children = edges[node].size()-1;
		int answer = 0;
		if(children == 0){
			return 0;
		}else if(children == 1){
			for(int child : edges[node]){
				if(child == parent) continue;
				answer = cut(child, node);
			}
		}else if(children == 2){
			int sum = 0;
			for(int child : edges[node]){
				if(child == parent) continue;
				sum += clear(child, node);
			}
			answer = sum;
		}else{
			int total = 0;
			IntList savingsList = new IntList();
			for(int child: edges[node]){
				if(child == parent) continue;
				int cutCost = cut(child, node);
				int clearCost = clear(child, node);
				int savings = cutCost - clearCost;
				savingsList.add(savings);
				total += cutCost;
			}
			Collections.sort(savingsList);
			int len = savingsList.size();
			int t1 = savingsList.get(len-1);
			int t2 = savingsList.get(len-2);
			answer = total - t1 - t2;
		}
		clearMemo.put(hash, answer);
		return answer;
	}


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.valueOf(br.readLine());
		for(int ctr=0; ctr<cases; ctr++){
			cutMemo = new HashMap<Tuple, Integer>();
			clearMemo = new HashMap<Tuple, Integer>();
			int nodes = Integer.valueOf(br.readLine());
			edges = new IntList[nodes];
			for(int i=0; i<nodes; i++){
				edges[i] = new IntList();
			}
			for(int i=0; i<nodes-1; i++){
				String[] ss = br.readLine().split("\\s+");
				int x = Integer.valueOf(ss[0])-1;
				int y = Integer.valueOf(ss[1])-1;
				edges[x].add(y);
				edges[y].add(x);
			}

			int best = nodes;
			for(int root=0; root<nodes; root++){
				int temp = clear(root, -1);
				if(temp < best){
					best = temp;
				}
				//System.out.printf("Rooted at %d %d\n", root, temp);
			}

			System.out.printf("Case #%d: %d\n", ctr+1, best);
		}
	}
}
