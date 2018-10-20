import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class ProblemB {
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("B-large.in"));
		System.setOut(new PrintStream(new FileOutputStream("B-large.out")));
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int N = in.nextInt();
			int[][] edges = new int[N-1][2];
			for (int i = 0; i < N-1; i++) {
				for (int j = 0; j < 2; j++) {
					edges[i][j] = in.nextInt() - 1;
				}
			}
			
			int min = N;
			for (int i = 0; i < N; i++) {
				min = Math.min(min, N-dfs(edges,new boolean[N],i));
			}
			
			System.out.printf("Case #%d: %d\n", caseNum, min);
		}
	}
	
	public static int dfs(int[][] edges,boolean[]visited,int cur) {
		ArrayList<Integer> sizes = new ArrayList<Integer>();
		visited[cur] = true;
		for (int i = 0; i < edges.length; i++) {
			if (edges[i][0] == cur && !visited[edges[i][1]]) {
				sizes.add(dfs(edges,visited,edges[i][1]));
			} else if (edges[i][1] == cur && !visited[edges[i][0]]) {
				sizes.add(dfs(edges,visited,edges[i][0]));
			}
		}
		if (sizes.size() < 2) return 1;
		Collections.sort(sizes);
		return sizes.get(sizes.size() - 1) + sizes.get(sizes.size() - 2) + 1; 
	}
}
