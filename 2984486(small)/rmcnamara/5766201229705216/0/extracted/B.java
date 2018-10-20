import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


class Node {

	HashMap<Node, Integer> hdp = new HashMap<Node, Integer>();
	HashMap<Node, Integer> cdp = new HashMap<Node, Integer>();
	
	public int getHeight( int i ){
		return adj.get(i).getHeight(this);
	}
	
	public int getCount( int i ){
		return adj.get(i).getCount(this);
	}

	public int getHeight(Node n){
		if ( hdp.containsKey(n) ){
			return hdp.get(n);
		}
		int ret = 0;
		
		if ( this.adj.size() <= 2 ){
			ret = 1;
		}
		else{
			for ( int a = 0; a < adj.size(); a++ ){
				for (int b = a+1; b < adj.size(); b++ ){
					if ( this.adj.get(a) == n || this.adj.get(b) == n ){
						continue;
					}
					int thisone = 1 + this.adj.get(a).getHeight(this) + this.adj.get(b).getHeight(this);
					ret = Math.max(ret, thisone);
				}
			}
		}
		
		hdp.put(n, ret);
		return ret;
	}
	public int getCount(Node n){
		if (cdp.containsKey(n) ){
			return cdp.get(n);
		}
		int ret = 0;
		ret++;
		for ( Node q : adj ){
			if ( n == q ) continue;
			ret += q.getCount(this);
		}
		cdp.put(n, ret);
		return ret;
	}
	
	
	ArrayList<Node> adj = new ArrayList<Node>();
}
public class B {
	
	public static void main( String[] args ) throws Exception{
		System.setIn(new FileInputStream("bsmall.in"));
		System.setOut(new PrintStream(new File("bsmall.out")));
		
		Scanner in = new Scanner(System.in);
		
		int t = in.nextInt();
		for ( int caseno = 1; caseno <= t; caseno++ ){
			int n = in.nextInt();
			Node[] nodes = new Node[n];
			for ( int i = 0;i < n; i++ ){
				nodes[i] = new Node();
			}
			for ( int i = 0; i < n-1; i++ ){
				int a = in.nextInt();
				int b = in.nextInt();
				//System.err.println("{" + a + "," + b + "},");
				nodes[a-1].adj.add(nodes[b-1]);
				nodes[b-1].adj.add(nodes[a-1]);
			}
			int best = Integer.MAX_VALUE;
			
			for ( int i = 0; i < nodes.length; i++ ){
				// root node i
				Node root = nodes[i];
				
				int totalChildren = 0;
				for ( int q = 0;q < root.adj.size(); q++ ){
					totalChildren += root.getCount(q);
				}
				
				if ( root.adj.size() >= 2  ){
					for ( int k = 0; k < root.adj.size(); k++){
						for ( int r1 = 0; r1<root.adj.size(); r1++){
							for ( int r2 = r1+1; r2<root.adj.size(); r2++){
								int h1 = root.getHeight(r1);
								int h2 = root.getHeight(r2);
								int c1 = root.getCount(r1);
								int c2 = root.getCount(r2);
								int rem = - h1 - h2 + totalChildren;
								
								best = Math.min(rem, best);
							}	
						}
					}
				}
				else{
					best = Math.min(best,n-1);
				}
			}
			
			System.out.println("Case #" + caseno + ": " + best);
		}
		
	}
}
