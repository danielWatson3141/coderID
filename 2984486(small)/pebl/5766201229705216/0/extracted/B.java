package codejam.f2013a;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;
import java.util.TreeMap;

public class B {
	static ArrayList al;
	
	static class Node {
		int nr;
		ArrayList edges = new ArrayList(3);
		int mark;
	}
	
	private static int size(Node n, int mark) {
		int size = 1;
		n.mark = mark;
		for(int i=0; i<n.edges.size(); i++) {
			Node c = (Node)n.edges.get(i);
			if (c.mark == mark)
				continue;			
			size += size(c,mark);			
		}
		return size;
	}
	
	private static boolean allNone2(Node n,int mark) {
		if (n.mark == mark)
			return true;
		n.mark = mark;
		if (al.size() == 2)
			return false;
		if (al.size() == 1)
			return true;
		for(int i=0; i<n.edges.size(); i++) {
			Node c = (Node) n.edges.get(i);
			if (c.mark == mark)
				continue;
			boolean ok = allNone2(c,mark);
			if (!ok)
				return false;
		}
		return true;
	}

	private static int getSize(Node n, int mark) {
		n.mark = mark;
		if (n.edges.size() < 2)
			return 1;
		
		int found = 0;
		int[] sizes = new int[n.edges.size()];
		for(int i=0; i<n.edges.size(); i++) {
			Node c = (Node)n.edges.get(i);
			if (c.mark == mark)
				continue;
			found++;
			int size = getSize(c, mark);
			sizes[i] = size;
		}
		
		if (found < 2)
			return 1;

		Arrays.sort(sizes);
		return 1+sizes[sizes.length-2]+sizes[sizes.length-1];
	}
	
	
	private static void handleCase(int nr, Scanner scanner) {
		int N = scanner.nextInt();
		
		al = new ArrayList();
		for(int i=0; i<N; i++) {
			Node n = new Node();
			n.nr = i;
			al.add(n);		
		}
		
		for(int i=0; i<N-1; i++) {
			int Xi = scanner.nextInt();
			int Yi = scanner.nextInt();
			
			Node nx = (Node) al.get(Xi-1);
			Node ny = (Node) al.get(Yi-1);

			if (!nx.edges.contains(ny)) {
				nx.edges.add(ny);
				ny.edges.add(nx);
			}
		}

		int maxSize=0;
		for(int i=0; i<N; i++) {
			Node n = (Node)al.get(i);
			int size = getSize(n,i+1);
			//System.out.println("dept "+(i+1)+" "+size);
			if (size > maxSize) {
				maxSize = size;
				//System.out.println("max dept "+(i+1)+" "+size);
			}
		}
		
		System.out.println("Case #"+nr+": "+(N-maxSize));
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
		int cases = scanner.nextInt();
		
		for(int i=0;i<cases; i++)
			handleCase(i+1,scanner);
	}
}
