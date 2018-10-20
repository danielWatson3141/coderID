// Google Code Jam Round 1A 2014
// Problem B. Full Binary Tree

import java.util.*;
import java.io.*;

class FullBinaryTree{
    static String inname = "B-large.in";    // input file name here
    static String outname = "B-large.out";  // output file name here
    static int n;
    static Vector<Vector<Integer>> g;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	String ans = "";
            	n = in.nextInt();
            	g = new Vector<Vector<Integer>>();
            	for (int i =0; i < n; i++) g.add(new Vector<Integer>());
            	for (int i =0; i < n-1; i++){
            		int a = in.nextInt()-1;
            		int b = in.nextInt()-1;
            		g.get(a).add(b);
            		g.get(b).add(a);
            	}
            	//System.out.println(g);
            	ans = solve();
                //System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
	private static String solve() {
		int ans = n-1;
		for (int i = 0; i < n; i++){
			int currMin = minDelRoot(i);
			//System.out.println(i + " " + currMin);
			if (currMin < ans) ans = currMin;
		}
		return "" + ans;
	}
	private static int minDelRoot(int r) {
		int neigh = neighs(r);
		if (neigh < 2) return n-1;
		else {
			int[] stays = new int[neigh];
			for (int i = 0; i < neigh; i++){
				stays[i] = maxStays(g.get(r).get(i), r);
			}
			Arrays.sort(stays);
			int totStays = stays[stays.length-1] + stays[stays.length-2];
			return n - 1 - totStays;
		}
	}
	private static int maxStays(int r, int parent) {
		int children = neighs(r)-1;
		if (children < 2) return 1;
		else {
			int[] stays = new int[children];
			int j = 0;
			for (int i = 0; i < children+1; i++){
				if (g.get(r).get(i) == parent) continue;
				stays[j] = maxStays(g.get(r).get(i), r);
				j++;
			}
			Arrays.sort(stays);
			int totStays = stays[stays.length-1] + stays[stays.length-2];
			return 1 + totStays;
		}
	}
	private static int neighs(int r) {
		return g.get(r).size();
	}
	private static int descendants(int r, int parent) {
		int ret = g.get(r).size()-1;
		if (ret < 1) return 0;
		for (int j = 0; j < g.get(r).size(); j++){
			if (g.get(r).get(j)!=parent) ret += descendants(g.get(r).get(j), r);
		}
		return ret;
	}
}