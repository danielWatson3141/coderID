package codejam2014round1AB;

import java.util.*;
import java.io.*;

import static java.lang.System.*;
import static java.lang.Math.*;

public class Main {

//	Scanner sc = new Scanner(in);
	Scanner sc; 
	PrintWriter pw;
	List<Integer>[] list;
	int n;
	int calc(int node, int prev) {
		int z = (prev < 0) ? 0 : 1;
		int c = list[node].size()-z;
		if (c == 0) return 0;
		if (c == 2) {
			int res = 0;
			for (int i = 0; i < list[node].size(); i++) {
				if (list[node].get(i) != prev) {
					res += calc(list[node].get(i), node);
				}
			}
			return res;
		}
		if (c == 1) {
			int res = 0;
			Queue<Integer> que = new LinkedList<Integer>();
			boolean[] used = new boolean[n];
			used[node] = true;
			que.add(node);
			while (!que.isEmpty()) {
				int index = que.poll();
				for (int i : list[index]) {
					if (prev != i && !used[i]) {
						res++;
						used[i] = true;
						que.add(i);
					}
				}
			}
			return res;
		} 
		int res = 10000000;
		int[] rem = new int[n];
		int sum = 0;
		for (int i : list[node]) {
			if (i != prev) {
				int count = 0;
				Queue<Integer> que = new LinkedList<Integer>();
				boolean[] used = new boolean[n];
				used[node] = true;
				used[i] = true;
				que.add(i);
				count++;
				while (!que.isEmpty()) {
					int index = que.poll();
					for (int j : list[index]) {
						if (!used[j]) {
							count++;
							used[j] = true;
							que.add(j);
						}
					}
				}
				sum += count;
				rem[i] = count;
			}
		}
		int[] mrem = new int[n];
		for (int i : list[node]) {
			if (i != prev) {
				mrem[i] = calc(i, node);
			}
		}
		for (int i1 : list[node]) {
			for (int i2 : list[node]) {
				if (i1 != i2 && i1 != prev && i2 != prev) {
					res = min(res, sum-rem[i1]-rem[i2]+mrem[i1]+mrem[i2]);
				}
			}
		}
		
		
		return res;
	}
	
	void run() {
		try {
			sc = new Scanner(new File("/Users/ryo/Documents/procon/codejam2014r1a/B-large.in"));
			pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("/Users/ryo/Documents/procon/codejam2014r1a/B-large.out"))));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		int t = sc.nextInt();
		for (int x = 1; x <= t; x++) {
			n = sc.nextInt();
			list = new ArrayList[n];
			for (int i = 0; i < n; i++)
				list[i] = new ArrayList<Integer>();
			for (int i = 0; i < n-1; i++) {
				int a = sc.nextInt()-1, b = sc.nextInt()-1;
				list[a].add(b);
				list[b].add(a);
			}
			int res = 100000;
			for (int i = 0; i < n; i++) {
				res = min(res, calc(i, -1));
			}
			pw.printf("Case #%d: %d\n", x, res);
		}
		sc.close();
		pw.close();
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}