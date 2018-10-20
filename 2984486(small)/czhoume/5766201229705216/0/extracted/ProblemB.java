import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;


public class ProblemB {
	static int[][] sol;
	static int[][] all;
	static int n;
	
	public static class Node{
		int val;
		ArrayList<Node> next;
		
		public Node(int v){
			val=v;
			next=new ArrayList<Node>();
		}
	}
	
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException{
		Scanner sc = new Scanner(new File("E:\\gcj\\data\\B-small-attempt3.in"));
//		Scanner sc = new Scanner(new File("E:\\gcj\\data\\test.txt"));
		PrintWriter writer = new PrintWriter("E:\\gcj\\data\\output.txt", "UTF-8");
		int T, N;
		T=sc.nextInt();
		for(int i=0; i<T; i++){
			int index = i+1;
			int min=10000;
			writer.print("Case #"+index+": ");
			N=sc.nextInt();
			sol=new int[N+1][N+1];
			all=new int[N+1][N+1];
			for(int j=0; j<N+1; j++)
				for(int k=0; k<N+1; k++){
					sol[j][k]=-1;
					all[j][k]=-1;
				}
			HashMap<Integer, Node> m = new HashMap<Integer, Node>();
			for(int j=0; j<N-1; j++){
				Node na, nb;
				int a= sc.nextInt();
				int b= sc.nextInt();
				if(m.containsKey(a)){
					na=m.get(a);
				}else{
					na=new Node(a);
					m.put(a, na);
				}
				if(m.containsKey(b)){
					nb=m.get(b);
				}else{
					nb=new Node(b);
					m.put(b, nb);
				}
				na.next.add(nb);
				nb.next.add(na);
			}
			n=m.size();
		    Iterator it = m.entrySet().iterator();
		    while (it.hasNext()) {
		        Map.Entry pairs = (Map.Entry)it.next();
		        Node tmp1=(Node)pairs.getValue();
		        int tmp=getMin(tmp1);
		        if(tmp<min)
		        	min=tmp;
		    }
		    writer.println(min);
		}
		sc.close();
		writer.close();
	}


	private static int getMin(Node root) {
		if(root.next.size()==1)
			return n-1;
		else if(root.next.size()==0)
			return 0;
		else if(root.next.size()==2)
			return helper(root, root.next.get(0))+helper(root, root.next.get(1));
		else{
			int min=10000;
			for(int i=0; i<root.next.size(); i++){
				for(int j=i+1; j<root.next.size(); j++){
					int tmp=helper(root, root.next.get(i))+helper(root, root.next.get(j));
					for(int k=0; k<root.next.size(); k++){
						if(root.next.get(k).val!=root.next.get(i).val&&root.next.get(k).val!=root.next.get(j).val)
							tmp=tmp+allnodes(root, root.next.get(k));
					}
					if(tmp<min)
						min=tmp;
				}
			}
			return min;
		}
	}


	private static int helper(Node root, Node node) {
		if(sol[root.val][node.val]!=-1)
			return sol[root.val][node.val];
		else{
			if(node.next.size()==1){
				sol[root.val][node.val]=0;
				return sol[root.val][node.val];
			}else if(node.next.size()==3){
				int tmpsum=0;
				for(int i=0; i<3; i++){
					if(node.next.get(i).val==root.val)
						continue;
					tmpsum=tmpsum+helper(node, node.next.get(i));
				}
				sol[root.val][node.val]= tmpsum;
				return sol[root.val][node.val];
			}else if(node.next.size()==2){
				int tmpsum=0;
				for(int i=0; i<2; i++){
					if(node.next.get(i).val==root.val)
						continue;
					tmpsum=tmpsum+allnodes(node, node.next.get(i));
				}
				sol[root.val][node.val]= tmpsum;
				return sol[root.val][node.val];
			}else if(node.next.size()>=4){
				int min=10000;
				for(int i=0; i<node.next.size(); i++){
					for(int j=i+1; j<node.next.size(); j++){
						if(node.next.get(i).val==root.val||node.next.get(j).val==root.val)
							continue;
						int tmp=helper(node, node.next.get(i))+helper(node, node.next.get(j));
						for(int k=0; k<node.next.size(); k++){
							if(node.next.get(k).val!=node.next.get(i).val&&node.next.get(k).val!=node.next.get(j).val&&node.next.get(k).val!=root.val)
								tmp=tmp+allnodes(node, node.next.get(k));
						}
						if(tmp<min)
							min=tmp;
					}
				}
				sol[root.val][node.val]= min;
				return sol[root.val][node.val];
			}
		}
		return 0;
	}


	private static int allnodes(Node node, Node node2) {
		if(all[node.val][node2.val]!=-1)
			return all[node.val][node2.val];
		else{
			int tmpall=1;
			for(int i=0; i<node2.next.size(); i++){
				if(node2.next.get(i).val==node.val)
					continue;
				tmpall=tmpall+allnodes(node2, node2.next.get(i));
			}
			all[node.val][node2.val]=tmpall;
			return all[node.val][node2.val];
		}
	}
}
