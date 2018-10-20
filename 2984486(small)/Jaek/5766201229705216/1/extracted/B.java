package a_2014;

import java.util.ArrayList;
import java.util.Scanner;


public class B {

	public static ArrayList<Integer>[] paths;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for(int cas = 1; cas <= T; cas++) {
			int N = in.nextInt();
			
			paths = new ArrayList[N];
			for(int i = 0; i<N; i++) {
				paths[i] = new ArrayList<Integer>();
			}
			for(int i = 0; i<N-1; i++) {
				int X = in.nextInt()-1;
				int Y = in.nextInt()-1;
				paths[X].add(Y);
				paths[Y].add(X);
			}
			int best = Integer.MAX_VALUE;
			for(int i = 0; i<N; i++) {
				int t = minRemove(i, -1);
				if(t<best)
					best = t;
				//System.out.println(i+" "+t);
			}
			System.out.println("Case #"+cas+": "+best);
		}
	}
	
	public static int minRemove(int node, int parent) {
		int count = 0;
		
		int childs = paths[node].size();
		if(parent == -1)
			childs++;
		
		if(childs == 1)
			return 0;
		if(childs == 2) {
			for(int i: paths[node]) {
				if(i != parent)
					return children(i, node);
			}
		}
		if(childs == 3) {
			for(int i: paths[node]) {
				if(i != parent)
					count += minRemove(i, node);
			}
			return count;
		}
		int at1 = -1;
		int at2 = -1;
		int best1 = -1;
		int best2 = -1;
		
		for(int i: paths[node]) {
			if(i != parent) {
				int removed = minRemove(i, node);
				int children = children(i, node);
				if(children-removed>best1) {
					best1 = children-removed;
					at1 = i;
				}
				if(best1>best2) {
					int t = best2;
					best2 = best1;
					best1 = t;
					
					t = at2;
					at2 = at1;
					at1 = t;
				}
			}
		}
		
		for(int i:paths[node]) {
			if(i!= parent) {
				count += children(i, node);
			}
		}
		//System.out.println(at1+" "+best1+" "+at2+" "+best2+" "+count);
		return count-best1-best2;
	}
	
	public static int children(int node, int parent) {
		int count = 1;
		for(int i : paths[node]) {
			if(i != parent) {
				count += children(i, node);
			}
		}
		return count;
	}
}
