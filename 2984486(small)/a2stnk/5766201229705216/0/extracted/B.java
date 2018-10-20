package cj2014.r1A;
import java.io.*;
import java.util.*;

public class B {
	public class Node {
		ArrayList<Node> children;
		public Node() {
			children = new ArrayList<Node>();
		}
	}
	
	public class Tree {
		Node[] nodes;
		public Tree(int N, int[] x, int[] y) {
			nodes = new Node[N];
			for(int i=0; i<N; i++)
				nodes[i] = new Node();
			for(int i=0; i<N-1; i++) {
				nodes[x[i]].children.add(nodes[y[i]]);
				nodes[y[i]].children.add(nodes[x[i]]);
			}
		}
		
		public int makeFullBT(int root) {
			return makeFullBT(nodes[root], null);
		}
		
		public int makeFullBT(Node node, Node parent) {
			int best1=-1;
			int best2=-1;
			for(Node child : node.children) {
				if(child==parent)
					continue;
				int childSize = makeFullBT(child, node);
				if(best1<childSize) {
					best2 = best1;
					best1 = childSize;
				} else if(best2<childSize) {
					best2 = childSize;
				}
			}
			
			if(best2>=0) {
				return best1+best2+1;
			} else {
				return 1;
			}

		}
	}
	
	Scanner sc;
	PrintWriter pw;
	int N;
	int[] x,y;
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"B-small-attempt0";

		try {
			new B().run(filePrefix);
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void run(String filePrefix) throws Exception {
		sc = new Scanner(new FileReader(filePrefix + ".in"));
		pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			read(sc);
			pw.print("Case #" + test + ": ");
			System.out.print("Case #" + test + ": ");
			solve();
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
		
	}
	
	void read(Scanner sc) {
		N = sc.nextInt();
		x = new int[N-1];
		y = new int[N-1];
		for(int i=0; i<N-1; i++) {
			x[i] = sc.nextInt()-1;
			y[i] = sc.nextInt()-1;
		}
	}
	
	void print(Object s) {
		pw.print(s);
		System.out.print(s);
	}
	
	void println(Object s) {
		pw.println(s);
		System.out.println(s);
	}	
	
	public void solve() {
		int ans = 0;
		Tree t = new Tree(N, x, y);
		
		for(int i=0; i<N; i++) {
			ans = Math.max(ans, t.makeFullBT(i));
		}
		println(N-ans);
	}
}
