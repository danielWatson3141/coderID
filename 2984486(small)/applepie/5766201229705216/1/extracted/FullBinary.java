import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class FullBinary {
	private static final String NAME = "binary";
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(NAME + ".in"));
		PrintWriter out = new PrintWriter(new File(NAME + ".out"));
		int numCases = Integer.parseInt(br.readLine());
		for(int CASE = 1; CASE <= numCases; CASE++){
			int N = Integer.parseInt(br.readLine());
			Node[] nodes = new Node[N];
			for(int i = 0; i < N; i++){
				nodes[i] = new Node(i);
			}
			for(int i = 0; i < N-1; i++){
				StringTokenizer st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken()) - 1;
				int b = Integer.parseInt(st.nextToken()) - 1;
				nodes[a].edges.add(nodes[b]);
				nodes[b].edges.add(nodes[a]);
			}
			int maxSize = -1;
			for(int i = 0; i < N; i++){
				for(Node n: nodes)
					n.size = 0;
				int size = nodes[i].root();
				if(size > maxSize)
					maxSize = size;
			}
			out.println("Case #" + CASE + ": " + (N - maxSize));
		}
		out.close();
		System.exit(0);
	}
}

class Node {
	int x; int size; boolean visited;
	ArrayList<Node> edges;
	public Node(int x){
		this.x = x; size = 0; visited = false;
		edges = new ArrayList<Node>();
	}
	
	public int root(){
		if (edges.size() < 2)
			return 1;
		for(Node n: edges){
			n.prune(this);
		}
		int max1 = (edges.get(0).size > edges.get(1).size) ? 0 : 1;
		int max2 = (max1 == 0) ? 1 : 0;
		for(int i = 2; i < edges.size(); i++){
			Node n = edges.get(i);
			if(n.size > edges.get(max1).size){
				max2 = max1;
				max1 = i;
			} else if(n.size > edges.get(max2).size) {
				max2 = i;
			}
		}
		
		size = edges.get(max1).size + edges.get(max2).size + 1;
		return size;
	}
	
	private void prune(Node parent){
		if(edges.size() <= 2){
			size = 1;
			return;
		}
		for(Node n: edges){
			if(n != parent)
				n.prune(this);
		}
		edges.remove(parent);
		int max1 = (edges.get(0).size > edges.get(1).size) ? 0 : 1;
		int max2 = (max1 == 0) ? 1 : 0;
		for(int i = 2; i < edges.size(); i++){
			Node n = edges.get(i);
			if(n.size > edges.get(max1).size){
				max2 = max1;
				max1 = i;
			} else if(n.size > edges.get(max2).size) {
				max2 = i;
			}
		}
		edges.add(parent);
		size = edges.get(max1).size + edges.get(max2).size + 1;
	}
}