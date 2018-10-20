import java.io.*;
import java.util.*;

public class P2
{
	static Node[] nodes;
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File("B-small-attempt0.in"));
		PrintWriter p = new PrintWriter("B-small-attempt0.out");
		int numCases = in.nextInt();
		for(int caseNo = 1; caseNo <= numCases; caseNo++){
			int n = in.nextInt();
			nodes = new Node[n];
			for(int i = 0; i < n; i++){
				nodes[i] = new Node();
			}
			for(int i = 0; i < n-1; i++){
				int x = in.nextInt()-1, y = in.nextInt()-1;
				nodes[x].nodes.add(y);
				nodes[y].nodes.add(x);
			}
			ArrayList<Integer> possibleRoots = new ArrayList<Integer>();
			int maxliveNodes = 0;
			for(int i = 0; i < n; i++){
				if(nodes[i].nodes.size()==2){
					possibleRoots.add(i);
					int sz = size(nodes[i].nodes.get(0), i)+size(nodes[i].nodes.get(1), i)+1;
					if(maxliveNodes<sz){
						maxliveNodes = sz;
					}
				}
			}
			if(possibleRoots.size()==0){
				for(int i = 0; i < n; i++){
					if(nodes[i].nodes.size()==3){
						possibleRoots.add(i);
						int sz = size(nodes[i].nodes.get(0), i)+size(nodes[i].nodes.get(1), i)+1;
						if(maxliveNodes<sz){
							maxliveNodes = sz;
						}
					}
				}
				p.printf("Case #%d: %d%n", caseNo, n-maxliveNodes);
			}
			else{
				p.printf("Case #%d: %d%n", caseNo, n-maxliveNodes);
			}
		}
		in.close();
		p.close();
	}
	static int size(int to, int from){
		if(nodes[to].nodes.size()<3){
			return 1;
		}
		int max1 = 0; int max2 = 0;
		for(int i: nodes[to].nodes){
			if(i!=from){
				int cr = size(i, to);
				if(cr>max1){
					max2=max1;
					max1=cr;
				}else if(cr>max2){
					max2=cr;
				}
			}
		}
		return max1 + max2 + 1;
	}
}
class Node{
	ArrayList<Integer> nodes = new ArrayList<Integer>();
	ArrayList<Integer> sizes = new ArrayList<Integer>();
}
