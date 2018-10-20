import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;


public class ProblemA {

	File f; 
	Scanner s; 
	File out;
	FileWriter writer;
	
	public int flipN(int i, int n) {
		return i ^ (1 << n);
	}
	
	public void init() throws IOException {
		f = new File("ASmall.txt");
		s = new Scanner(f);
		out = new File("ASmallOut.txt");
		writer = new FileWriter(out);
	}
	
	public void finish() throws IOException {
		writer.close();
	}
	
	public List<Integer> readLine(String s, int n, int l) {
		String[] str = s.split(" ");
		List<Integer> vals = new ArrayList<Integer>();
		for (int i = 0; i < n; i ++) {
			int val = 0; 
			for (int j = l-1; j >= 0; j --) {
				val += Integer.parseInt(Character.toString(str[i].charAt(l - j - 1))) 
						* Math.pow(2, j);
			}
			vals.add(val);
		}
		return vals;
	}
	
	public ArrayList<List<Integer>> adjacent(List<Integer> v, int l, int n) {
		ArrayList<List<Integer>> adj = new ArrayList<List<Integer>>();
		for (int i = 0; i < l; i ++	) {
			List<Integer> copy = new ArrayList<Integer>();
			for (int c = 0; c < v.size(); c ++) {
				copy.add(v.get(c));
			}
			for (int j = 0; j < n; j ++) {
				copy.set(j, flipN(copy.get(j), i));
			}
			Collections.sort(copy);
			adj.add(copy);
		}
		return adj;
	}
	
	public String magic(List<Integer> s, List<Integer> d, int n, int l) {
		Collections.sort(d);
		Queue<List<Integer>> q = new LinkedList<List<Integer>>();
		HashMap<List<Integer>, Integer> dist = new HashMap<List<Integer>, Integer>();
		Collections.sort(s);
		dist.put(s, 0);
		HashSet<List<Integer>> visited = new HashSet<List<Integer>>();
		q.add(s);
		visited.add(s);
		System.out.println("start");
		while (!q.isEmpty()) {
			List<Integer> cur = q.poll();
			System.out.println(cur.toString());
			if (cur.equals(d)) return Integer.toString(dist.get(cur));
			for (List<Integer> next : adjacent(cur, l, n)) {
				if (!visited.contains(next)) {
					visited.add(next);
					dist.put(next, dist.get(cur) + 1);
					q.add(next);
				}
			}
		}
		return "NOT POSSIBLE";
	}
	
	public void go() throws IOException {
		init();
		int numCases = s.nextInt();
		for (int c = 0; c < numCases; c ++) {
			int n = s.nextInt();
			int l = s.nextInt();
			s.nextLine();
			List<Integer> sockets = readLine(s.nextLine(), n, l);
			List<Integer> devices = readLine(s.nextLine(), n, l);
			String ans = magic(sockets, devices, n, l);
			System.out.println("Case #" + (c+1) + ": " + ans);
			writer.write("Case #" + (c+1) + ": " + ans + "\n");
			
		}
		
		finish();
	}
	
	public static void main(String[] args) {
		ProblemA a = new ProblemA();
		try {
			a.go();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
