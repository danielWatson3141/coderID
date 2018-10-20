import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class B {
	public static final String FILENAME = "B-large";
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/"+FILENAME+".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"+FILENAME+".out"));
		Scanner s = new Scanner(in);
		int T = s.nextInt();
		for(int i = 1; i <= T; i++) {
			System.out.println(i);
			int N = s.nextInt();
			List<Integer>[] adj = new LinkedList[N];
			for (int j = 0; j < adj.length; j++) {
				adj[j] = new LinkedList<>();
			}
			for (int j = 0; j < N-1; j++) {
				int a = s.nextInt()-1;
				int b = s.nextInt()-1;
				adj[a].add(b);
				adj[b].add(a);
			}
			int min = Integer.MAX_VALUE;
			for (int root = 0; root < adj.length; root++) {
				//System.out.println(i + "-" + root);
				//System.out.println("-"+solve(adj, root));
				min = Math.min(min, solve(adj, root));
			}
			out.write("Case #"+i+": "+min+"\n");
		}
		in.close();
		out.close();
	}

	private static int solve(List<Integer>[] adj, int root) {
		int N = adj.length;
		if(adj[root].size() <= 1) {
			return N-1;
		}
		
		
		//BFS
		int[] order = new int[N];
		boolean[] visited = new boolean[N];
		order[0] = root;
		visited[root] = true;
		int free = 1;
		for (int cur = 0; cur < N; cur++) {
			for(int i: adj[order[cur]]) {
				if(!visited[i]) {
					order[free++] = i;
					visited[i] = true;
					//System.out.print(i + " ");
				}
			}
		}
		//System.out.println();
		
		//delete
		int del = 0;
		int[] children = new int[N];
		boolean[] done = new boolean[N];
		for (int i = N-1; i >= 0; i--) {
			int c = order[i];
			if(c != root && adj[c].size() == 1) {
				//everything ok, leaf
			}
			else if(c != root && adj[c].size() == 2) {
				//delete child
				int child = done[adj[c].get(0)] ? adj[c].get(0) : adj[c].get(1);
				del += children[child] + 1;
				//System.out.println("del "+(children[child] + 1)+" at "+c);
			}
			else {
				int max1 = Integer.MAX_VALUE;
				int max2 = Integer.MAX_VALUE;
				int allchildren = 0;
				for(int t: adj[c]) {
					if(done[t]) {
						allchildren += children[t] + 1;
						if(max1 == Integer.MAX_VALUE) {
							max1 = t;
						}
						else if(children[max1] < children[t]) {
							max2 = max1;
							max1 = t;
						}
						else if(max2 == Integer.MAX_VALUE) {
							max2 = t;
						}
						else if(children[max2] < children[t]) {
							max2 = t;
						}
					}
				}
				//System.out.println("k"+max1);
				//System.out.println("k"+max2);
				children[c] = children[max1] + children[max2] + 2;
				del += allchildren - children[c];
				//System.out.println("del "+(allchildren - children[c])+" at "+c);
			}
			done[c] = true;
		}
		
		return del;
	}
}
