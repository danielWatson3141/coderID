import java.util.*;
import java.io.*;
import static java.lang.System.*;
import static java.lang.Integer.*;

public class B{
	public static void dfs(Node n, Node p, boolean root){
		for(int i=0; i<n.cons.size(); i++){
			if(n.cons.get(i) == p) continue;
			dfs(n.cons.get(i), n, false);
			
			n.subsize += n.cons.get(i).subsize;
		}
		
		if(n.cons.size() == 1 + (root?0:1)){
			n.minrem = n.subsize-1;
		}else if(n.cons.size() >= 3 + (root?0:1)){
			Collections.sort(n.cons);
			if(n.cons.get(0) == p){
				n.cons.remove(0);
			}
			if(n.cons.get(1) == p){
				n.cons.remove(1);
			}
			for(int i=2; i<n.cons.size(); i++){
				if(n.cons.get(i) == p) continue;
				n.minrem += n.cons.get(i).subsize;
			}
			n.minrem += n.cons.get(0).minrem;
			n.minrem += n.cons.get(1).minrem;
		}else if(n.cons.size() == 2 + (root?0:1)){
			for(int i=0; i<n.cons.size(); i++){
				if(n.cons.get(i) == p) continue;
				n.minrem += n.cons.get(i).minrem;
			}
		}
	}

	public static void main(String[] args)throws Exception{
		BufferedReader sc = new BufferedReader(new InputStreamReader(in));
		
		int cases = parseInt(sc.readLine());
		for(int z=1; z<=cases; z++){
			int n = parseInt(sc.readLine());
			
			ArrayList<Node> nodes = new ArrayList<Node>();
			for(int i=0; i<n; i++){
				nodes.add(new Node());
			}
			
			for(int i=1; i<n; i++){
				StringTokenizer st = new StringTokenizer(sc.readLine());
				Node a = nodes.get(parseInt(st.nextToken())-1);
				Node b = nodes.get(parseInt(st.nextToken())-1);
				a.cons.add(b);
				b.cons.add(a);
				a.adj++;
				b.adj++;
			}
			
			// Node root = null;
			// int left = n;
			// while(root == null){
				// ArrayList<Node> rem = new ArrayList<Node>();
				// for(int i=0; i<n; i++){
					// if(!nodes.get(i).ontree) continue;
					// if(left == 1){
						// root = nodes.get(i);
						// break;
					// }
					// if(nodes.get(i).adj == 1){
						// rem.add(nodes.get(i));
					// }
				// }
				// for(int i=0; i<rem.size(); i++){
					// Node node = rem.get(i);
					// left--;
					// if(left == 0){
						// root = node;
					// }
					// node.ontree = false;
					// for(int j=0; j<node.cons.size(); j++){
						// node.cons.get(j).adj--;
					// }
				// }
			// }
			// dfs(root, root, true);
			// out.println("Case #"+z+": "+root.minrem);
			
			int ans = MAX_VALUE;
			int ind = -1;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					nodes.get(j).subsize = 1;
					nodes.get(j).minrem = 0;
				}
				dfs(nodes.get(i), nodes.get(i), true);
				if(nodes.get(i).minrem < ans){
					ind = i;
					ans = nodes.get(i).minrem;
				}
			}
			out.println("Case #"+z+": "+ans);
		}
	}
}

class Node implements Comparable<Node>{
	ArrayList<Node> cons = new ArrayList<Node>();
	int adj = 0;
	int subsize = 1;
	int minrem = 0;
	boolean ontree = true;
	public int compareTo(Node n){
		return n.subsize-n.minrem - subsize+minrem;
	}
}