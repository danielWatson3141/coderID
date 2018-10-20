import java.io.*;
import java.math.*;
import java.util.*;

public class B{
	public static void main (String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			pw.print("Case #" + t + ": ");
			
			int n = nextInt(br);
			
			Node[] nodes = new Node[n];
			
			for(int i = 0; i < n; i++){
				nodes[i] = new Node(i);
			}
			
			for(int i = 0; i < n-1; i++){
				StringTokenizer st = getst(br);
				int a = nextInt(st);
				int b = nextInt(st);
				nodes[a-1].connections.add(nodes[b-1]);
				nodes[b-1].connections.add(nodes[a-1]);
			}
			
			int ans = 1000;
			
			for(int i = 0; i < n; i++){
				nodes[i].clear(null);
				int a = nodes[i].getAns(null);
				//System.out.println(a);
				ans = Math.min(ans, a);
			}
			
			pw.println(ans);
		}
		
		br.close();
		pw.close();
	}
	
	static class Node implements Comparable<Node>{
		public HashSet<Node> connections;
		public int children;
		public boolean included;
		public int size;
		public int answ;
		public int id;
		
		public Node(int i){
			connections = new HashSet<Node>();
			children = 0;
			size = 0;
			included = false;
			answ = 0;
			id = i+1;
		}
		
		public void clear(Node parent){
			children = connections.size();
			if(parent != null){
				children--;
			}
			size = 1;
			for(Node n : connections){
				if(n != parent){
					n.clear(this);
					size += n.size;
				}
			}
			included = true;
			answ = 0;
		}
		
		public int getAns(Node parent){
			int ans = 0;
			Node[] ch = new Node[children];
			int i = 0;
			for(Node n : connections){
				if(n != parent){
					int a = n.getAns(this);
					ans += a;
					ch[i] = n;
					i++;
				}
			}
			Arrays.sort(ch);
			if(children == 0){
				
			} else if(children == 1){
				ans = ch[0].size;
			} else if(children == 2){
				
			} else {
				i = 0;
				while(children > 2){
					ans += ch[i].size - ch[i].answ;
					i++;
					children--;
				}
			}
			answ = ans;
			//System.out.println(id + " " + ans + " " + children + " " + size);
			return ans;
		}
		
		public int compareTo(Node o){
			return (size - answ) - (o.size - o.answ);
		}
	}
	
	public static int nextInt(BufferedReader br) throws Exception{
		return Integer.parseInt(br.readLine());
	}
	
	public static int nextInt(StringTokenizer st) throws Exception{
		return Integer.parseInt(st.nextToken());
	}
	
	public static StringTokenizer getst(BufferedReader br) throws Exception{
		return new StringTokenizer(br.readLine(), " ");
	}
}