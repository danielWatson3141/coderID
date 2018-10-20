package round1a;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Stack;


public class Graph {
	
	/*
	 * Common Graph Variables..
	 */
	HashMap<Integer, List<Integer>> graph;
	HashMap<Integer, List<Integer>> revGraph;
	HashMap vertexMapping;
	HashMap revVertexMapping;
	List<Integer> V;
	HashMap<Pair<Integer, Integer>, Integer> E;
	
	/*
	 * Variables for coloring
	 */
	HashMap<Integer, HashMap<Integer, Integer>> coloredNbrsMap;
	
	/*
	 * Some public codes for various algorithms and heuristics..
	 */
	public static final int ALGORITHM_COLORING_GREEDY = 0;
	public static final int HEURISTIC_MAXIMUM_ADJACENT_COLORED = 0;
	public static final int HEURISTIC_MAXIMUM_DEGREE = 1;
	
	/*
	 * Debug variables and codes..
	 */
	private int debug = 0;
	public static final int DEBUG_NO = 0;
	public static final int DEBUG_GRAPH_BUILD = 1;
	public static final int DEBUG_COLORING = 2;
	public static final int DEBUG_ALL = 3;
	
	public Graph() {
		
		this(new HashMap<Integer, List<Integer>>(), new HashMap<Integer, List<Integer>>());
		
	}
	
	public Graph(HashMap<Integer, List<Integer>> g, HashMap<Integer, List<Integer>> rg) {
		
		graph = new HashMap<Integer, List<Integer>>();
		graph.putAll(g);
		revGraph = new HashMap<Integer, List<Integer>>();
		revGraph.putAll(rg);
		setGraphParamters();
	}
	
	public Graph(List<Pair<String, String>> edges) {
		
		setGraph(edges);
		
	}
	
	public void setGraph(List<Pair<String, String>> edges) {
		
		graph = new HashMap<Integer, List<Integer>>();
		revGraph = new HashMap<Integer, List<Integer>>();
		V = new ArrayList<Integer>();
		HashMap<String, Boolean> tempMap = new HashMap<String, Boolean>();
		for(Pair<String, String> edge : edges) {
			
			tempMap.put(edge.getLeft(), true);
			tempMap.put(edge.getRight(), true);
			
		}
		List<String> l = new ArrayList<String>(tempMap.keySet());
		createMapping(l);
		//V.addAll(revVertexMapping.keySet());
		for(Pair<String, String> edge : edges) {
			
			addEdge(vertexMapping.get(edge.getLeft()), vertexMapping.get(edge.getRight()));
			
		}
		setGraphParamters();
		
	}
	
	private void setGraphParamters() {
		
		V = new ArrayList<Integer>();
		HashMap<Integer, Boolean> tempMap = new HashMap<Integer, Boolean>();
		//V.addAll(graph.keySet());
		E = new HashMap<Pair<Integer,Integer>, Integer>();
		for(Entry<Integer, List<Integer>> e : graph.entrySet()) {
			
			tempMap.put(e.getKey(), true);
			for(Integer i : e.getValue()) {
				
				E.put(new Pair<Integer, Integer>(e.getKey(), i), 0);
				tempMap.put(i, true);
				
			}
			
		}
		V.addAll(tempMap.keySet());
		
	}
	
	public boolean existsEdge(int a, int b) {
		
		return E.containsKey(new Pair(a,b));
		
	}
	
	public String vertexToString(int v) {
		
		if(revVertexMapping != null) {
			
			assert(revVertexMapping.get(v) != null);
			return revVertexMapping.get(v).toString();
			
		}
		return "" + v;
		
	}
	
	public <E> void createMapping(List<E> l) {
		
		vertexMapping = new HashMap<E, Integer>();
		revVertexMapping = new HashMap<Integer, E>();
		int no = 0;
		for(E e : l) {
			
			vertexMapping.put(e, no);
			revVertexMapping.put(no, e);
			no++;
			
		}
		
	}
	
	private void addEdge(Object ov, Object ow) {
		
		assert(ov.getClass().equals(Integer.class) && ow.getClass().equals(Integer.class));
		Integer v = (Integer) ov;
		Integer w = (Integer) ow;
		if(isDebuggable(DEBUG_GRAPH_BUILD)) {
			
			System.out.println("Adding edge : " + vertexToString(v) + ", " + vertexToString(w));
			
		}
		List<Integer> l;
		if(graph.containsKey(v)) {
			
			l = graph.get(v);
			if(isDebuggable(DEBUG_GRAPH_BUILD)) {
				
				System.out.println("Graph already contains " + l.size() + " edges for this vertex");
				
			}
			
		}
		else {
			
			l = new ArrayList<Integer>();
			
		}
		l.add(w);
		graph.put(v, l);
		
		if(revGraph.containsKey(w)) {
			
			l = revGraph.get(w);
			
		}
		else {
			
			l = new ArrayList<Integer>();
			
		}
		l.add(v);
		revGraph.put(w, l);
		
	}
	
	public boolean isDebuggable(int level) {
		
		return (debug & level) > 0;
		
	}
	
	public void setDebugLevel(int debug) {
		
		this.debug = debug;
		
	}
	
	public void addDebugLevel(int debug) {
		
		this.debug |= debug;
		
	}
	
	public void setDebuggableAll() {
		
		this.debug = DEBUG_ALL;
		
	}
	
	private int getDegree(int v) {
		
		if(graph.containsKey(v)) {
			
			return graph.get(v).size();
			
		}
		else
			return 0;
		
	}
	
	public int dfs(int root) {
		
		PriorityQueue<Integer> st = new PriorityQueue<Integer>();
		List<Integer> l = graph.get(root);
		if(l.size() != 0 && l.size() != 2) {
			
			return 1;
			
		}
		int count = 1;
		st.addAll(l);
		HashMap<Integer, Boolean> visited = new HashMap<Integer, Boolean>();
		visited.put(root, true);
		while(!st.isEmpty()) {
			
			int v = st.poll();
			if(visited.containsKey(v) && visited.get(v))
				continue;
			visited.put(v, true);
			l = graph.get(v);
			if(l.size() == 3) {
				
				count++;
				for(int w : l) {
					
					if(!visited.containsKey(w) || !visited.get(w)) {
						
						st.add(w);
						
					}
					
				}
				
			}
			else if(l.size() == 2) {
				
				int w = l.get(0);
				int x = l.get(1);
				count++;
				/*
				if(visited.containsKey(w) && visited.get(w)) {
					
					//count++;
					//visited.put(arg0, arg1)
					
					boolean novisits = false;
					for(int z : graph.get(w)) {
						
						if(!visited.containsKey(z) || !visited.get(z)) {
						
							visited.put(z, true);
							novisits = true;
							
						}
						
					}
					if(!novisits)
						count--;
					
				}
				else {
					
					boolean novisits = false;
					for(int z : graph.get(x)) {
						
						if(!visited.containsKey(z) || !visited.get(z)) {
						
							visited.put(z, true);
							novisits = true;
							
						}
						
					}
					if(!novisits)
						count--;
					
				}*/
				
			}
			else if(l.size() == 1) {
				
				int w = l.get(0);
				if(visited.containsKey(w) && visited.get(w)) {
					
					count++;
					
				}
				
				
			}
			
		}
		return count;
		
	}
	
	public HashMap<String, Integer> runColoring() {
		
		return runColoring(ALGORITHM_COLORING_GREEDY, HEURISTIC_MAXIMUM_DEGREE);
		
	}
	
	private int getLowestColor(int v, HashMap<String, Integer> map) {
		
		List<Integer> colors = new ArrayList<Integer>();
		for(Integer w : graph.get(v)) {
			
			if(map.containsKey(vertexToString(w))) {
				
				if(isDebuggable(DEBUG_COLORING)) {
					
					//System.out.println("Neighbour " + vertexToString(w) + " of " + vertexToString(v) + " has color " + map.get(w));
					
				}
				colors.add(map.get(vertexToString(w)));
				
			}
			
		}
		Collections.sort(colors);
		int last = -1;
		for(Integer i : colors) {
			
			if(i - last > 1)
				break;
			last = i;
			
		}
		return last+1;	
		
	}
	 
	public HashMap<String, Integer> runColoring(int code, int heuristic) {
		
		HashMap<String, Integer> ret = new HashMap<String, Integer>();
		if(code == ALGORITHM_COLORING_GREEDY) {
			
			/*
			if(heuristic == HEURISTIC_MAXIMUM_ADJACENT_COLORED) {
				
				coloredNbrsMap = new HashMap<Integer, HashMap<Integer,Integer>>();
				for(Integer v : V) {
					
					coloredNbrsMap.put(v, new HashMap<Integer, Integer>());
					
				}
				PriorityQueue<Integer> pq = new PriorityQueue<Integer>(V.size(), new Comparator<Integer>() {

					@Override
					public int compare(Integer v, Integer w) {
					
						return coloredNbrsMap.get(v).size() - coloredNbrsMap.get(w).size();
						
					}
					
				});
				pq.addAll(V);				
				while(!pq.isEmpty()) {
					
					Integer v = pq.poll();
					Set<Integer> nbrs = coloredNbrsMap.get(v).keySet();
					if(debug == DEBUG_COLORING) { 
					
						System.out.println("Picked new vertex " + v + " with " + nbrs.size() + " colored neighbours");
					
					}
					if(nbrs.size() == 0) {
						
						addColor(v,0);
						ret.put(v, 0);
						continue;
						
					}
					for(int w : nbrs) {
						
						assert(ret.containsKey(w));
						lowest = Math.min(lowest, ret.get(w));
						
					}
					
					
				}
				
			} */
			if(heuristic == HEURISTIC_MAXIMUM_DEGREE) {
				
				List<Integer> orderedV = new ArrayList<Integer>();
				orderedV.addAll(V);
				Collections.sort(orderedV, new Comparator<Integer>() {

					@Override
					public int compare(Integer v, Integer w) {
					
						return getDegree(w) - getDegree(v);
						
					}
					
				});
				if(isDebuggable(DEBUG_COLORING)) {
					
					System.out.println("Total number of vertices : " + orderedV.size());
					
				}
				for(Integer v : orderedV) {
					
					if(isDebuggable(DEBUG_COLORING)) { 
						
						System.out.println("Picked new vertex " + vertexToString(v) + " with degree = " + graph.get(v).size());
					
					}
					int color = getLowestColor(v, ret);
					if(isDebuggable(DEBUG_COLORING)) {
						
						System.out.println("Assigned color " + color + " to vertex " + vertexToString(v));
						
					}
					ret.put(vertexToString(v), color);
					
				}
				
			}
			
		}
		return ret;
		
	}
	
	/*
	 * Sub classes for graph..
	 * 
	 */
	class ColorVertex implements Comparable<ColorVertex>{
		
		int v;
		int color;
		List<Integer> coloredNeighbours;
		
		public ColorVertex(int v) {
			
			this(v, -1, null);
			
		}
		
		public ColorVertex(int v, int color) {
			
			this(v,color,null);
			
		}
		
		public ColorVertex(int v, int color, HashMap<Integer, Integer> colorMap) {
			
			this.v = v;
			this.color = color;
			coloredNeighbours = new ArrayList<Integer>();
			if(colorMap == null)
				return;
			for(Integer w : graph.get(v)) {
				
				if(colorMap.containsKey(w)) {
					
					coloredNeighbours.add(w);
					
				}
				
			}
			
		}
		
		public int getV() {
			return v;
		}

		public void setV(int v) {
			this.v = v;
		}
		
		public int getColor() {
			return color;
		}

		public void setColor(int c) {
			this.color = c;
		}

		public List<Integer> getColoredNeighbours() {
			return coloredNeighbours;
		}

		public void setColoredNeighbours(List<Integer> coloredNeighbours) {
			this.coloredNeighbours = coloredNeighbours;
		}

		public void addColoredNeighbour(int w) {
			
			assert(E.containsKey(new Pair<Integer, Integer>(v,w)));
			coloredNeighbours.add(w);
			
		}

		@Override
		public int compareTo(ColorVertex w) {
		
			return coloredNeighbours.size() - w.getColoredNeighbours().size();
			
		}		
		
	}

}
