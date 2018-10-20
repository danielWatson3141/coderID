import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;


public class Main {

	static Main main;
	
	static ArrayList<ArrayList<Integer>> edges ;
	
	static int n;
	
	public class Node implements Comparable<Node> {
		int index;
		ArrayList<Node> children;
		Node parent;
		int min ;
		int below;
		public Node(int a) {
			index = a;
			children = new ArrayList<Node>();
			parent = null;
			min = 0;
			below = 0;
		}
		public int compareTo(Node node) {
			return new Integer(below-min).compareTo(node.below-node.min);
		}
	}
	
	static Node [] nodes;

	public static void main(String[] args) {
		main = new Main();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedOutputStream bos = new BufferedOutputStream(System.out);
		String eol = System.getProperty("line.separator");
		byte[] eolb = eol.getBytes();
		byte[] spaceb = " ".getBytes();
		byte[] caseb = "Case #".getBytes();
		byte[] colonb = ":".getBytes();
		try {
			String str = br.readLine();
			int t = Integer.parseInt(str);
			for(int i = 0 ; i < t ; i++) {
				str = br.readLine();
				n = Integer.parseInt(str);
				edges = new ArrayList<ArrayList<Integer>>();
				nodes = new Node[n];
				for(int j = 0 ; j < n ; j++) {
					edges.add(new ArrayList<Integer>());
					//nodes[j] = main.new Node(j);
				}
				for(int j = 1 ; j < n ; j++) {
					str = br.readLine();
					int blank = str.indexOf(" ");
					int a = Integer.parseInt(str.substring(0,blank));
					int b = Integer.parseInt(str.substring(blank+1));
					edges.get(a-1).add(b-1);
					edges.get(b-1).add(a-1);
				}
				int ans = Integer.MAX_VALUE;
				for(int j = 0 ; j < n ; j++) {
					int x = getMin(j);
					ans = Math.min(ans,x);
				}
				bos.write(caseb);
				bos.write(new Integer(i+1).toString().getBytes());
				bos.write(colonb);
				bos.write(spaceb);
				bos.write(new Integer(ans).toString().getBytes());
				bos.write(eolb);
			}
			bos.flush();
		} catch(IOException ioe) {
			ioe.printStackTrace();
		}
	}
	
	public static int getMin(int a) {
		int ans = 0;
		for(int j = 0 ; j < n ; j++) {
			nodes[j] = main.new Node(j);
		}
		boolean [] visited = new boolean[n];
		Arrays.fill(visited, false);
		ArrayList<Integer> expand = new ArrayList<Integer>();
		ArrayList<ArrayList<Integer>> hash = new ArrayList<ArrayList<Integer>>();
		expand.add(a);
		visited[a] = true;
		int numVisited = 1;
		while(expand.size()>0) {
			hash.add(expand);
			ArrayList<Integer> newExpand = new ArrayList<Integer>();
			for(int i = 0 ; i < expand.size() ; i++) {
				int x = expand.get(i);
				for(int j = 0 ; j < edges.get(x).size() ; j++) {
					int y = edges.get(x).get(j);
					if(!visited[y]) {
						visited[y] = true;
						newExpand.add(y);
						nodes[y].parent = nodes[x];
						nodes[x].children.add(nodes[y]);
						numVisited++;
					}
				}
			}
			expand = newExpand;
		}
		for(int i = hash.size() - 1 ; i >= 0 ;i--) {
			ArrayList<Integer> list = hash.get(i);
			for(int j = 0 ; j < list.size() ; j++) {
				int x = list.get(j);
				Node node = nodes[x];
				if(node.children.size()==0) {
					node.below = 1;
				} else {
					node.below = 1;
					for(int k = 0 ; k < node.children.size() ; k++) {
						node.below += node.children.get(k).below;
					}
				}
			}
		}
		for(int i = hash.size() - 1 ; i >= 0 ;i--) {
			ArrayList<Integer> list = hash.get(i);
			for(int j = 0 ; j < list.size() ; j++) {
				int x = list.get(j);
				Node node = nodes[x];
				if(node.children.size()==0) {
					node.min = 0;
				} else if(node.children.size()==1) {
					node.min = node.children.get(0).below ;
				} else {
					int tn = node.children.size();
					Node [] ar = new Node[node.children.size()];
					for(int k = 0 ; k < node.children.size() ; k++) {
						ar[k] = node.children.get(k);
					}
					Arrays.sort(ar);
					node.min = ar[tn-1].min + ar[tn-2].min;
					for(int k = 0 ; k < tn-2 ; k++) {
						node.min +=ar[k].below;
					}
				}
			}
		}
		ans = nodes[a].min;
		//System.out.println("ans = " + ans + " a = " + a);
		return ans;
	}
	
	

}
