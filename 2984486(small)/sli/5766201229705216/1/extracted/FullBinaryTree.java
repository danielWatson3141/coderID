import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;


public class FullBinaryTree {
	public static void main(String[] args) throws FileNotFoundException{
		System.setIn(new FileInputStream("src\\B-large.in"));
		System.setOut(new PrintStream("B-large.out"));
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for(int t = 0; t < tests; t++){
			ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();
			int n = sc.nextInt();
			for(int i = 0; i < n; i++){
				g.add(new ArrayList<Integer>());
			}
			for(int i = 0; i < n-1; i++){
				int a = sc.nextInt()-1;
				int b = sc.nextInt()-1;
				g.get(a).add(b);
				g.get(b).add(a);
			}
			int best = Integer.MAX_VALUE;
			for(int i = 0; i < n; i++){
				best = Math.min(best, findCost(i, g));
			}
			System.out.println("Case #" + (t+1) + ": " + best);
		}
	}

	private static int findCost(int r, ArrayList<ArrayList<Integer>> g) {
		int[] costRemove = new int[g.size()];
		int[] costKeep = new int[g.size()];
		int[] parent = new int[g.size()];
		Arrays.fill(parent, -1);
		boolean[] vis = new boolean[g.size()];
		parent[r] = r;
		Stack<Integer> s = new Stack<Integer>();
		s.push(r);
		while(!s.isEmpty()){
			int cur = s.pop();
			if(vis[cur]){
				int zeroChild = 0;
				ArrayList<Integer> keepWin = new ArrayList<Integer>();
				for(int i = 0; i < g.get(cur).size(); i++){
					if(parent[cur] != g.get(cur).get(i)){
						zeroChild+=costRemove[g.get(cur).get(i)];
						keepWin.add(-costRemove[g.get(cur).get(i)]+costKeep[g.get(cur).get(i)]);
					}
				}
				Collections.sort(keepWin);
				if(keepWin.size() >= 2){
					int twoChild = zeroChild + keepWin.get(0) + keepWin.get(1);
					costKeep[cur] = Math.min(zeroChild,twoChild);
					costRemove[cur] = zeroChild+1;
				}
				else{
					costKeep[cur] = zeroChild;
					costRemove[cur] = zeroChild+1;
				}
			}
			else{
				s.push(cur);
				for(int i = 0; i < g.get(cur).size(); i++){
					if(g.get(cur).get(i) == parent[cur] || parent[g.get(cur).get(i)] != -1){
						
					}
					else{
						parent[g.get(cur).get(i)] = cur;
						s.push(g.get(cur).get(i));
					}
				}
			}
			vis[cur] = true;
		}
		return Math.min(costRemove[r], costKeep[r]);
	}
}
