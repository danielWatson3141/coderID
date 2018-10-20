import java.util.*;

class B{


	static ArrayList<Integer>[] adj;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int kases = sc.nextInt();
		for(int k = 1; k<=kases; k++){
			int N = sc.nextInt();
			adj = new ArrayList[N];
			for(int i = 0; i<N; i++) adj[i] = new ArrayList<Integer>();
			for(int i = 1; i<N; i++){
				int s = sc.nextInt(); int t = sc.nextInt();
				adj[s-1].add(t-1);
				adj[t-1].add(s-1);
			}
			int min = N-1;
			for(int root = 0; root< N; root++){
				if(adj[root].size()!=1){
					int rem = count(root,-1);
					if(rem< min) min = rem;
				}
			}
			System.out.println("Case #"+k+": "+min);
		}
	}
	
	//returns teh size of the subtree including the node
	static int size(int node, int parent){
		if(adj[node].size()==1){
			if(adj[node].contains(parent))return 1;
			else return 0;
		}
		int size = 1;
		for(int child: adj[node])
			if(child != parent) size+=size(child, node);
		return size;
	}


	//returns the minimum number to remove in the subtree
	static int count(int node, int parent){
		if(adj[node].size()==1){
			if(adj[node].contains(parent))return 0;
			else return 1;
		}
		else if(adj[node].size()==2){
			if(adj[node].contains(parent)) return size(node,parent)-1;
		}
		int cnt1 = -1; int cnt2 = -1; int removed = 0;
		int size1 = 0; int size2 = 0;
		for(int child: adj[node]){
			if(child != parent){
				int cnt = count(child, node);
				int size = size(child, node);
				if(cnt1==-1){cnt1 = cnt; size1 = size; removed+=cnt;}
				else if(cnt2==-1){cnt2 = cnt; size2 = size; removed+=cnt;}
				else{
					int rel1 = size-cnt-size1+cnt1;
					int rel2 = size-cnt-size2+cnt2;
					if(rel1>rel2 && rel1>0){
						removed += size1-cnt1;
						size1 = size;
						cnt1 = cnt;
						removed+=cnt1;
					}
					else if (rel2>=rel1 &&rel2>0){
						removed+= size2-cnt2;
						size2 = size;
						cnt2 = size;
						removed += cnt2;
					}
					else removed += size-1;
				}
			}
		}
		return removed;
	}
				
}
