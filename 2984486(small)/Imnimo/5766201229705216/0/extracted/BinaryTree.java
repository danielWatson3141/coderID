import java.io.File;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class BinaryTree {
	public static void main(String[] args) throws Exception {

		Scanner s = new Scanner(new File("B-small-attempt4.in"));
		int numCases = Integer.parseInt(s.nextLine());
		for(int c = 1;c<=numCases;c++) {
			int size = Integer.parseInt(s.nextLine());
			String[] edges = new String[size-1];
			for(int i = 0;i<size-1;i++) {
				edges[i] = s.nextLine();
			}
		
			int result = solve(edges,size);
			System.out.println("Case #" + c + ": " + result);
			//if(size==3)
			//System.exit(1);
		}
		
		//int result = solve(new String[]{"1 2"},2);
		
		//System.out.println(result);
	}
	public static boolean isConnected(String[] edges,int size,Set<Integer> deleted, int root) {
		LinkedList<Integer> reachable = new LinkedList<Integer>();
		reachable.add(root);
		boolean[] marked = new boolean[size+1];
		
		while(!reachable.isEmpty()) {
			Integer node = reachable.poll();
			marked[node] = true;
			for(String s : edges) {
				String[] sa = s.split(" ");
				int first = Integer.parseInt(sa[0]);
				int second = Integer.parseInt(sa[1]);
				if(first==node) {
					if(!marked[second] && !deleted.contains(second)) {
						reachable.add(second);
					}
				}
				if(second==node) {
					if(!marked[first] && !deleted.contains(first)) {
						reachable.add(first);
					}
				}
			}
		}
		int count = 0;
		for(int i = 1;i<=size;i++) {
			if(marked[i]) {
				count++;
			}
		}
		return count + deleted.size() == size;
	}
	public static int solve(String[] edges, int size) {
		PriorityQueue<DeletionSet> q = new PriorityQueue<DeletionSet>(100,new Comp());
		int[] initcounts = getCounts(edges,size,new TreeSet<Integer>());
		
		ArrayList<Integer> initEmpty = getEmptySet(initcounts,size,new TreeSet<Integer>());
		//System.out.println(initEmpty);
		DeletionSet start = new DeletionSet();
		start.deleted.addAll(initEmpty);
		q.add(start);
		while(!q.isEmpty()) {
			DeletionSet test = q.poll();
			//System.out.println("Checking " + test.deleted);
			int[] counts = getCounts(edges,size,test.deleted);
			//for(int i = 0;i<counts.length;i++) {
			//	System.out.println((i+1) + " " + counts[i]);
			//}
			ArrayList<Integer> badSet = getBadSet(counts,size,test.deleted);
			ArrayList<Integer> emptySet = getEmptySet(counts,size,test.deleted);
			//System.out.println("BAD: " + badSet);
			if(badSet.size()==1 && counts[badSet.get(0)-1]==2 && emptySet.size()==0) {
			//	System.out.println(test.deleted);
			//	for(int i = 0;i<counts.length;i++) {
			//		if(test.deleted.contains(i+1)) {
			//			continue;
			//		}
			//		System.out.println((i+1) + " " + counts[i]);
			//	}
				if(isConnected(edges,size,test.deleted,badSet.get(0)))
				return test.deleted.size();
			}
			if(test.deleted.size()==size && emptySet.size()==0) {
				/*	System.out.println(test.deleted);
					for(int i = 0;i<counts.length;i++) {
						if(test.deleted.contains(i+1)) {
							continue;
						}
						System.out.println((i+1) + " " + counts[i]);
					}*/
				return test.deleted.size()-1;
			}
			for(int a = test.minDel;a<=size;a++) {
				if(test.deleted.contains(a)) {
					continue;
				}
				
				DeletionSet temp = new DeletionSet(test.deleted);
				temp.deleted.add(a);
				temp.minDel = a;
				//int[] countsTemp = getCounts(edges,size,temp.deleted);
				
			//	System.out.println(temp.deleted + " ADDS " + emptySet);
				//temp.deleted.addAll(emptySet);
				q.add(temp);
			}
		}
		return -1;
	}
	public static int[] getCounts(String[] edges, int size, Set<Integer> deleted) {
		int[] counts = new int[size];
		for(String s : edges) {
			String[] sa = s.split(" ");
			int first = Integer.parseInt(sa[0]);
			int second = Integer.parseInt(sa[1]);
			if(!deleted.contains(first) && !deleted.contains(second)) {
				counts[first-1]++;
				counts[second-1]++;
			}
		}
		return counts;
	}
	public static ArrayList<Integer> getBadSet( int[] counts, int size, Set<Integer> deleted) {
		ArrayList<Integer> badNodes = new ArrayList<Integer>();
		for(int i = 0;i<size;i++) {
			if(deleted.contains(i+1)) {
				continue;
			}
			
			if(counts[i]==2 || counts[i]>3) {
				badNodes.add(i+1);
			} 
		}
		return badNodes;
	}
	public static ArrayList<Integer> getEmptySet(int[] counts, int size, Set<Integer> deleted) {
		ArrayList<Integer> badNodes = new ArrayList<Integer>();
		for(int i = 0;i<size;i++) {
			if(deleted.contains(i+1)) {
				continue;
			}
			
			if(counts[i]==0) {
				badNodes.add(i+1);
			} 
		}
		return badNodes;
	}
	public static void check(String[] edges, int size,Set<Integer> deleted) {
		int[] counts = new int[size];
		for(String s : edges) {
			String[] sa = s.split(" ");
			int first = Integer.parseInt(sa[0]);
			int second = Integer.parseInt(sa[1]);
			if(!deleted.contains(first) && !deleted.contains(second)) {
				counts[first-1]++;
				counts[second-1]++;
			}
		}
		ArrayList<Integer> badNodes = new ArrayList<Integer>();
		ArrayList<Integer> emptyNodes = new ArrayList<Integer>();
		for(int i = 0;i<size;i++) {
			if(deleted.contains(i+1)) {
				continue;
			}
			System.out.println((i+1) + " " + counts[i]);
			if(counts[i]==2 || counts[i]>3) {
				System.out.println("BAD: " + (i+1));
				badNodes.add(i+1);
			} else if(counts[i]==0) {
				emptyNodes.add(i+1);
			}
		}
		
	}
}
class Comp implements Comparator<DeletionSet> {

	@Override
	public int compare(DeletionSet arg0, DeletionSet arg1) {
		Integer a = arg0.deleted.size();
		Integer b = arg1.deleted.size();
		return a.compareTo(b);
	}
	
}
class DeletionSet {
	TreeSet<Integer> deleted;
	int minDel = 1;
	public DeletionSet() {
		deleted = new TreeSet<Integer>();
	}
	public DeletionSet(TreeSet<Integer> parent) {
		deleted = new TreeSet<Integer>();
		deleted.addAll(parent);
	}
}
