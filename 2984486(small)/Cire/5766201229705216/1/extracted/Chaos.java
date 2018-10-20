import java.io.*;
import java.util.*;

public class Chaos {
	//private DataInputStream in;
	private PrintWriter out;
	private Scanner in;
	
	Chaos() throws IOException {
		out = new PrintWriter(new FileWriter("output.txt"), true);		
	
		in = new Scanner(new File("input.txt"));
	}
	
	int size(int root, Stack<Integer>[] next, int parent) {
		int s = 1;
		for(int child: next[root]) {
				if (child != parent)
					s += size(child, next, root);
		}
		return s;
	}
	
	int minTree(int root, Stack<Integer>[] next, int parent) {
		int l = next[root].size();
		if (parent != -1)
			l--;
		if (l == 0)
			return 0;
		if (l == 1) {
			for(int child: next[root]) {
				if (child != parent)
					return size(child, next, root);
			}
			out.println("huh");
			return 0;
		}
		else {
			int s = 0;
			PriorityQueue<Integer> a = new PriorityQueue<Integer>();
			for(int child: next[root]) {
				if (child != parent) {
					int r = minTree(child, next, root);
					s += r;
					a.add(size(child, next, root) - r);
					
				}
				while (a.size()>2)
					s += a.poll();
			}
			if (a.size()!=2)
				out.println("huh2");
			return s;
		}
	}
	
	
	void run() {
		int N = in.nextInt();
		
		Stack<Integer>[] next =  (Stack<Integer>[]) new Stack[N+1];
	
		for(int i = 0; i < N + 1; i++) {
			next[i] = new Stack<Integer>();
		}
		for(int i = 0; i < N - 1; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			next[a].add(b);
			next[b].add(a);
		}
		int minimum = Integer.MAX_VALUE;
		for(int i = 1; i < N + 1; i++) {
			minimum = Math.min(minimum, minTree(i, next, -1));
		}
		out.println(minimum);
	}
	
	public static void main(String[] args) throws IOException {

		Chaos m = new Chaos();
		
		
		int T = m.in.nextInt();
		for(int i=1; i<=T; i++) {
			m.out.print("Case #" + i + ": ");
			m.run();
		}
		
		return;
	}
}
