import java.util.ArrayList;
import java.util.Scanner;


public class FullBinaryTree {
	
	private static class Vertex {
		public int id;
		public ArrayList<Vertex> adjList;
		
		public Vertex(int i) {
			id = i;
			adjList = new ArrayList<Vertex>(2);
		}
	}
	
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		int cases = kb.nextInt();
		
		for(int c = 1; c <= cases; c++) {
			int nodes = kb.nextInt();
			
			ArrayList<Vertex> vertexList = new ArrayList<Vertex>(nodes);
			
			for(int i = 0; i <= nodes; i++) {
				vertexList.add(new Vertex(i));
			}
			
			for(int i = 1; i < nodes; i++) {
				int a = kb.nextInt();
				int b = kb.nextInt();;
				vertexList.get(a).adjList.add(vertexList.get(b));
				vertexList.get(b).adjList.add(vertexList.get(a));
			}
			
			int n = solve(vertexList);
			
			System.out.println("Case #" + c + ": " + n);
		}
	}

	private static int solve(ArrayList<Vertex> vertexList) {
		int min = Integer.MAX_VALUE;
		Vertex parent = new Vertex(-1);
		for(int i = 1; i < vertexList.size(); i++) {
			Vertex current = vertexList.get(i);
			if(getChildN(current, parent) == 3) {
				ArrayList<Vertex> adjList = current.adjList;
				
				for(int j = 0; j < adjList.size(); j++) {
					Vertex newParent = adjList.get(j);
					int deleted = getDeleted(current, newParent) + getNodes(newParent, current);
					min = Math.min(min, deleted);
				}
			} else {
				int deleted = getDeleted(current, parent);
				min = Math.min(min, deleted);
			}
		}
		
		return min;
	}
	
	private static int getDeleted(Vertex current, Vertex parent) {
		ArrayList<Vertex> adjList = current.adjList;
		
		int children = getChildN(current, parent);
		if(children == 0) return 0;
		
		if(children == 2) {
			int sum = 0;
			for(int i = 0; i < adjList.size(); i++) {
				Vertex vertex = adjList.get(i);
				
				if(vertex.id != parent.id) {
					sum += getDeleted(vertex, current);
				}
			}
			return sum;
		}
		
		
		int sum = 0;
		for(int i = 0; i < adjList.size(); i++) {
			Vertex vertex = adjList.get(i);
			
			if(vertex.id != parent.id) {
				sum += getNodes(vertex, current);
			}
		}
		
		return sum;
	}
	

	
	private static int getNodes(Vertex current, Vertex parent) {
		ArrayList<Vertex> adjList = current.adjList;
		int c = getChildN(current, parent);
		if(c == 0) return 1;
		
		int sum = 1;
		for(int i = 0; i < adjList.size(); i++) {
			Vertex vertex = adjList.get(i);
			
			if(vertex.id != parent.id) {
				sum += getNodes(vertex, current);
			}
		}
		
		return sum;
	}
	
	private static int getChildN(Vertex current, Vertex parent) {
		int sum = 0;
		ArrayList<Vertex> adjList = current.adjList;
		
		for(int i = 0 ; i < adjList.size(); i++) {
			Vertex v = adjList.get(i);
			
			if(v.id != parent.id) sum++;
		}
		return sum;
	}
}
