package rounda;

import java.awt.Point;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class ProblemB{
	public static void main(String[] args) {
		try {
			solve();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public static void solve() throws FileNotFoundException {
		String filename = "B-small-attempt1.in";
		Scanner sc = new Scanner(new File(filename));
		
		int numOfTestcase = sc.nextInt();
		for(int t = 1; t <= numOfTestcase; t++) {
			int numOfEdge = sc.nextInt();
			
			HashMap<Integer, ArrayList<Integer>> nodes = new HashMap<Integer, ArrayList<Integer>>();
			for(int i = 1; i < numOfEdge; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				
				if(nodes.containsKey(x)) {
					nodes.get(x).add(y);
				}
				else {
					nodes.put(x, new ArrayList<Integer>());
					nodes.get(x).add(y);
				}

				if(nodes.containsKey(y)) {
					nodes.get(y).add(x);
				}
				else {
					nodes.put(y, new ArrayList<Integer>());
					nodes.get(y).add(x);
				}				
			}
			
			int numOfNodes = nodes.size();
			int result = numOfNodes;
			ArrayList<Point> fff = new ArrayList<Point>();
			
			for(int n = 1; n <= numOfNodes; n++) {
				// System.out.println(" node num:" + n);
				int count = 0;
				
				ArrayList<Integer> root = nodes.get(n);
				if(root.size() == 1) {
					count = numOfNodes - 1;
				}
				else if(root.size() == 3) {
					count = numOfNodes - 1;					
				}
				else {
					for(int b : root) {
						fff.add(new Point(b, n));
					}
					
					while(fff.size() > 0) {
						Point target = fff.remove(0);
						ArrayList<Integer> tmp = nodes.get(target.x);
						
						if(tmp.size() == 3) {
							for(int b : tmp) {
								if(b != target.y) {
									fff.add(new Point(b, target.x));
								}
							}
						}
						else  {
							for(int b : tmp) {
								if(b != target.y) {
									count += deleteNodes(b, target.x, nodes);
								}
							}							
						}
					}
					result = Math.min(result, count);
					// System.out.printf("  %d: %d\n", n, count);					
				}
			}
			
			System.out.printf("Case #%d: %d\n", t, result);
			
		}
	}
	
	private static int deleteNodes(int b, int parent,
			HashMap<Integer, ArrayList<Integer>> nodes) {
		
		ArrayList<Point> aaa = new ArrayList<Point>();
		aaa.add(new Point(b, parent));
		
		int nodesCount = 0;
		while(aaa.size() > 0) {
			nodesCount++;
			Point target = aaa.remove(0);
			
			ArrayList<Integer> tmp = nodes.get(target.x);

			for(int c : tmp) {
				if(c != target.y) {
					aaa.add(new Point(c, target.x));
				}
			}										
		}
		// System.out.println("fin");
		return nodesCount;
	}
	
}

/*
3
3
2 1
1 3
7
4 5
4 2
1 2
3 1
6 4
3 7
4
1 2
2 3
3 4
*/