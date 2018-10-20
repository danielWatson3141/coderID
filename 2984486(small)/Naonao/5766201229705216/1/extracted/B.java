import java.util.*;
public class B {
	public static void main(String[]args) {
		Scanner in = new Scanner(System.in);
		int inputs = in.nextInt();
		for(int caseNum = 1; caseNum <= inputs; caseNum++) {
			int numNodes = in.nextInt();
			int best =numNodes -1;
			Node[] nodes = new Node[numNodes];
			for(int i = 0 ; i < numNodes ;i++) {
				nodes[i] = new Node(i, numNodes);
			}
			for(int i = 0; i < numNodes-1; i++){
				int a = in.nextInt()-1;
				int b = in.nextInt()-1;
				nodes[a].add(nodes[b]);
				nodes[b].add(nodes[a]);
			}
			for(int i = 0 ; i < numNodes; i++) {
				//System.out.println(i + " " + nodes[i].trimCost(numNodes));
				best = Math.min(nodes[i].trimCost(numNodes), best);
			}
			System.out.printf("Case #%d: %d\n", caseNum, best);
		}
	}
}

class Node{
	int number;
	int total;
	ArrayList<Node> connected;
	int[] children;
	int[] trim;
	public Node(int number, int total){
		this.number = number;
		connected = new ArrayList<Node>();
		children = new int[total+1];
		trim = new int[total+1];
		Arrays.fill(trim, -1);
		this.total = total;
	}
	
	public void add(Node i) {
		this.connected.add(i);
	}
	
	public int numChildren(int parent) {
		if(parent == total) return total;
		if(children[parent] != 0) {
			return children[parent];
		}
		int count = 1;
		for(int i =0; i < connected.size(); i++) {
			if(connected.get(i).number != parent){
				count += connected.get(i).numChildren(this.number);
			}
		}
		children[parent] = count;
		return count;
	}
	
	public int trimCost(int parent) {
		int add = parent == total? 0: 1;
		//System.out.println(add + " " + parent + " " +total);
		if(trim[parent] != -1) {
			return trim[parent];
		}
		int ans = this.numChildren(parent)-1;
		int children = connected.size() - add;
		//System.out.println(parent + " " + this.number + " " + children);
		if(children == 1) {
			ans = this.numChildren(parent) - 1;
		} else if (children >= 2) {
			int[] save = new int[connected.size()];
			for(int i = 0 ; i<connected.size();i ++) {
				if(connected.get(i).number == parent) save[i] = 0;
				else {
					save[i] = connected.get(i).numChildren(this.number) - connected.get(i).trimCost(this.number);
				}
			}
			Arrays.sort(save);
			ans = Math.min(ans, this.numChildren(parent) - 1 -  (save[save.length - 1] + save[save.length-2]));
		}
		
		trim[parent] = ans;
		//System.out.println(parent + " " + this.number + " " + children + " " + ans + "!");
		return ans;
	}
}
