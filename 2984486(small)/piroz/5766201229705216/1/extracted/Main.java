package round1A_B;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	static boolean debug = false;
	private static StringBuilder ansSB = new StringBuilder();
	public static void main(String[] args) {
		solve();
		outstd();
		outfile();
	}
	private static void solve() {
		Scanner sc = new Scanner(System.in);
		int testCaseNum = sc.nextInt();
		for(int testCase=0;testCase<testCaseNum;testCase++) {
			if (debug) {
				System.out.println("Case" + testCase);
			}
			int n = sc.nextInt();
			@SuppressWarnings("unchecked")
			ArrayList<Integer>[] graph = new ArrayList[n];
			for(int i=0;i<n;i++) {
				graph[i] = new ArrayList<>();
			}
			for(int i=0;i<n-1;i++) {
				int x = sc.nextInt()-1;
				int y = sc.nextInt()-1;
				graph[x].add(y);
				graph[y].add(x);
			}
			solveCase(n,graph);
		}
	}
	private static void solveCase(int n,ArrayList<Integer>[] graph) {
		int ans = 10000;
		Pair[][] memo = new Pair[n][n];
		for(int root=0;root<n;root++) {
			ans = Math.min(ans, dfs(n,graph,root,-1,memo).min);
		}
		outCase(ans);
	}
	public static Pair dfs(int n,ArrayList<Integer>[] graph,int v,int parent,Pair[][] memo) {
		if (parent!=-1) {
			if (memo[parent][v] != null) {
				return memo[parent][v];
			}
		}
		Pair ret = null;
		
		int childNum = parent == -1 ? graph[v].size() : graph[v].size()-1;
		if (childNum == 0) {
			ret = new Pair(0,1);
		}else{
			int sum = 0;
			ArrayList<Pair> cost = new ArrayList<>();
			for(int i=0;i<graph[v].size();i++) {
				int u = graph[v].get(i);
				if (u == parent) {
					continue;
				}else{
					Pair p = dfs(n, graph, u, v ,memo);
					cost.add(p);
					sum += p.max;
				}
			}
			Collections.sort(cost);
			if (childNum >= 2) {
				ret = new Pair(sum-cost.get(0).diff()-cost.get(1).diff(),sum+1);
			}else{
				ret = new Pair(sum,sum+1);
			}
		}
		
		if (parent!=-1) {
			memo[parent][v] = ret;
		}
		if (debug) {
			System.out.println(parent + "," + v + "," + ret);
		}
		return ret;
	}
	
	public static int outnum = 0;
	public static BufferedWriter bw;
	public static void outCase(Object o) {
		outnum++;
		ansSB.append("Case #" + outnum + ": " + o + "\n");
	}
	private static void outfile() {
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
			bw.write(ansSB.toString());
			bw.close();
		}catch (IOException e) {
			e.printStackTrace();
		}
	}
	private static void outstd() {
		System.out.println(ansSB);
	}
}
class Pair implements Comparable<Pair>{
	int min;
	int max;
	public Pair(int a,int b) {
		this.min = a;
		this.max = b;
	}
	public int compareTo(Pair o) {
		return -((this.max-this.min)-(o.max-o.min));
	}
	public int diff() {
		return this.max-this.min;
	}
	public String toString() {
		return "(" + min + "," + max + ")";
	}
}