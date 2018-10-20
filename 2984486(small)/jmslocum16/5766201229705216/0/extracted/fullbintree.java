package round1a;

import java.io.*;
import java.util.*;

public class fullbintree {
	static ArrayList<Integer>[] adjList;
	public static void main(String[] args) throws IOException {
		PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
		BufferedReader br = new BufferedReader(new FileReader(new File("test.txt")));
		int T = Integer.parseInt(br.readLine().trim());
		for (int casenum = 1; casenum <= T; casenum++) {
			int N = Integer.parseInt(br.readLine().trim());
			//System.out.print("Case #" + casenum + ": ");
			out.print("Case #" + casenum + ": ");
			adjList = new ArrayList[N+1];
			for (int i = 1; i <= N; i++) {
				adjList[i] = new ArrayList<Integer>();
			}
			StringTokenizer st;
			for (int i = 0; i < N-1; i++) {
				st = new StringTokenizer(br.readLine().trim());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				adjList[a].add(b);
				adjList[b].add(a);
			}
			int min = tryAllRoots(N);
			//System.out.println(min);
			out.println(min);
		}
		out.close();
	}
	/*static int calc(int node, int currentNum, boolean[] visited) {
		ArrayList<Integer> curChildren = new ArrayList<Integer>(2);
		for (int i : adjList[node])
			if (visited[i]) curChildren.add(i);
		if (curChildren.size() == 0) return currentNum;
		if (curChildren.size() == 1) { // have to cut it off or cut me off, cutting it off equal if there is subtree of size one, otherwise worse, soo
			visited[node] = true;
			int cutMeOff = tryAllRoots(visited, currentNum + 1);
			visited[node] = false;
			return cutMeOff;			
		}
		visited[node] = true;
		ArrayList<Integer> left = getUnvisitedSubtree(curChildren.get(0));
		ArrayList<Intetger> right = getUnvisitedSubtree();
		..... is this too complicated
	}
	
	static int tryAllRoots(boolean[] visited, int currentNum) {
		int ret = Integer.MAX_VALUE;
		for (int i = 1; i < visited.length; i++) {
			if (!visited[i]) {
				visited[i] = true;
				ret = Math.min(calc(i, currentNum, visited), ret);
				visited[i] = false;
			}
		}
		return ret;
	}*/
	static int tryAllRoots(int N) {
		int ret = Integer.MAX_VALUE;
		for (int i = 1; i <= N; i++) {
			ret = Math.min(ret, numberToCut(i, new boolean[N+1], false));
		}
		return ret;
	}
	static int numberToCut(int node, boolean[] visited, boolean destroy) {
		visited[node] = true;
		if (destroy) {
			// you are not meant to be included in the final tree, count you and your descendents
			int total = 1;
			for (int i : adjList[node]) {
				if (!visited[i])
					total += numberToCut(i, visited, true);
			}
			visited[node] = false;
			return total;
		}
		// you are meant to occur in the final tree, but your descendents may not be
		ArrayList<Integer> curChildren = new ArrayList<Integer>(2);
		for (int i : adjList[node])
			if (!visited[i]) curChildren.add(i);
		if (curChildren.size() == 0) {
			visited[node] = false;
			return 0;
		}
		if (curChildren.size() == 1) { // have to cut off this branch to be full
			int ret = numberToCut(curChildren.get(0), visited, true);
			visited[node] = false;
			return ret;
		} else {
			// keep 2 direct children
			int min = Integer.MAX_VALUE;
			int total = 0;
			for (int i = 0; i < curChildren.size(); i++) {
				for (int j = 0; j < i; j++) {
					if (i != j) {
						total = 0;
						for (int k = 0; k< curChildren.size(); k++) {
							if (k == i || k == j) {
								total += numberToCut(curChildren.get(k), visited, false);
							} else {
								total += numberToCut(curChildren.get(k), visited, true);
							}
						}
						min = Math.min(min, total);
					}
				}
			}
			visited[node] = false;
			return min;
		}
	}
}
