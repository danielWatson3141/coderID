
import java.util.*;
import java.io.*;

class Main {
    private Stdin stdin = new Stdin();
    private java.util.logging.Logger logger = null;
    private static String logger_name = "B";

    /**
     * Init class data here
     */
    private void init() {
	
    }

    /**
     * Handle the input here.
     * This method will call solve() method inside to solve the problem.
     * The return value indicates if there are more input data need to 
     * be handled. If it doesn't return 0, means this function have to be
     * called again to solve next data.
     * @return 0: end. 1: need to call input() again for next data.
     */
    private int input() {
	int ret=0;
	String com1;
	int T;

	com1 = stdin.get1();
	if (com1==null) {
	    return ret;
	}
	T = Integer.parseInt(com1);

	for (int t=0; t<T; t++) {
	    Graph<Integer, Long> graph = new Graph<Integer, Long>();
	    int N;
	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    N = Integer.parseInt(com1);
	    for (int i=0; i<N; i++) {
		graph.addNode(new Integer(i+1));
	    }

	    for (int i=0; i<N-1; i++) {
		int X;
		int Y;
		com1 = stdin.get1();
		if (com1==null) {
		    return ret;
		}
		X = Integer.parseInt(com1);
		com1 = stdin.get1();
		if (com1==null) {
		    return ret;
		}
		Y = Integer.parseInt(com1);
		graph.addEdge(new Integer(X), new Integer(Y), new Long(1));
		graph.addEdge(new Integer(Y), new Integer(X), new Long(1));
	    }

	    solve(graph);
	}

	ret=0;
    	return ret;
    }

    private int countNodes(Graph<Integer,Long> graph, Integer node, Integer parent) {
	int c=1;
	Set<Integer> edges = graph.getEdges(node);
	for (Iterator<Integer> i=edges.iterator(); i.hasNext(); ) {
	    Integer iI = i.next();
	    Integer inode = graph.getNodeByIndex(iI.intValue());
	    if (inode.compareTo(parent)==0) {
		continue;
	    }
	    c += countNodes(graph, inode, node);
	}
	return c;
    }

    private int solveR(Graph<Integer,Long> graph, Integer node, Integer parent) {
	int c=1;
	Set<Integer> edges = graph.getEdges(node);
	int numOfChilds=0;
	for (Iterator<Integer> i=edges.iterator(); i.hasNext(); ) {
	    Integer iI = i.next();
	    Integer inode = graph.getNodeByIndex(iI.intValue());
	    if (parent != null && inode.compareTo(parent)==0) {
		continue;
	    }
	    numOfChilds++;
	}
	if (numOfChilds<=1) {
	    return c;
	}

	if (numOfChilds==2) {
	    for (Iterator<Integer> i=edges.iterator(); i.hasNext(); ) {
		Integer iI = i.next();
		Integer inode = graph.getNodeByIndex(iI.intValue());
		if (parent != null && inode.compareTo(parent)==0) {
		    continue;
		}
		c+=solveR(graph, inode, node);
	    }
	    return c;
	}

	int[] maxNumOfChilds = new int[2];
	Arrays.fill(maxNumOfChilds, -1);

	for (Iterator<Integer> i=edges.iterator(); i.hasNext(); ) {
	    Integer iI = i.next();
	    Integer inode = graph.getNodeByIndex(iI.intValue());
	    if (parent != null && inode.compareTo(parent)==0) {
		continue;
	    }
	    int r = solveR(graph, inode, node);
	    for (int j=0; j<maxNumOfChilds.length; j++) {
		if (r > maxNumOfChilds[j]) {
		    if (j+1 < maxNumOfChilds.length) {
			maxNumOfChilds[j+1] = maxNumOfChilds[j];
		    }
		    maxNumOfChilds[j] = r;
		    break;
		}
	    }
	}
	for (int i=0; i<maxNumOfChilds.length; i++) {
	    c += maxNumOfChilds[i];
	}
	return c;
    }


    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(Graph<Integer,Long> graph) {
	ArrayList<Integer> nodes = graph.getNodesArray();
	int maxR=-1;
	for (int i=0; i<nodes.size(); i++) {
	    Integer node = nodes.get(i);
	    int r = solveR(graph, node, null);
	    if (r > maxR) {
		maxR = r;
	    }
	}
	
	output(graph.size()-maxR);
    }

    int output_N=0;
    /**
     * Output the results
     */
    private void output(int n) {
	output_N++;
	System.out.format("Case #%1$d: %2$d%n",output_N, n);
    }


    /**
     * log information for debugging.
     */
    public void logInfo(String a, Object... args) {
	if (logger != null) {
	    logger.info(String.format(a,args));
	}
    }

    public void begin() {
	this.logger = java.util.logging.Logger.getLogger(Main.logger_name);
	if (this.logger.getLevel() != java.util.logging.Level.INFO) {
	    this.logger = null;
	}
	init();
	while (input()==1) {
	}
    }

    public void unittest() {
	this.logger = java.util.logging.Logger.getLogger(Main.logger_name);
    }

    public static void main (String args[]) {
	Main myMain = new Main();
	if (args.length >= 1 && args[0].compareTo("unittest")==0) {
	    myMain.unittest();
	    return;
	}
	java.util.logging.Logger.getLogger(Main.logger_name).setLevel(java.util.logging.Level.SEVERE);
	for (int i=0; args!=null && i<args.length; i++) {
	    if (args[i].compareTo("debug")==0) {
		java.util.logging.Logger.getLogger(Main.logger_name).setLevel(java.util.logging.Level.INFO);
	    }
	}
	myMain.begin();
    }
}

class Stdin
{
    private java.io.InputStream cin;
    private java.io.BufferedReader cin_br;
    private java.io.StreamTokenizer cin_st;

    public static java.lang.String endl = System.getProperty("line.separator");

    public Stdin() {
	this(java.lang.System.in);
    }

    public Stdin(java.io.InputStream cin) {
	this.cin = cin;
 	cin_br = new java.io.BufferedReader(new java.io.InputStreamReader(this.cin));
	cin_st = new java.io.StreamTokenizer(cin_br);
	cin_st.resetSyntax();
	cin_st.wordChars('\u0021','\u007E');
	cin_st.wordChars('\u00A0','\u00FF');
	cin_st.whitespaceChars('\u0000', '\u0020');
    }

    public java.io.InputStream getInputStream() {
	return cin;
    }

    public java.io.BufferedReader getBufferedReader() {
	return cin_br;
    }

    public java.io.StreamTokenizer getStreamTokenizer() {
	return cin_st;
    }

    public java.lang.String gets() {
	java.lang.String str=null;
	try {
	    str = this.cin_br.readLine();
	} catch (java.lang.Exception e) {
	    str = null;
	}
	return str;
    }

    public java.lang.String get1() {
	java.lang.String str=null;
	try {
	    if (cin_st.nextToken() != java.io.StreamTokenizer.TT_EOF) {
		str = cin_st.sval;
	    }
	} catch (java.lang.Exception e) {
	    str = null;
	}
	return str;
    }
}

class Graph <NodeType, WeightType extends java.lang.Number> {
    private LinkedHashMap<NodeType, Integer> nodes;
    private ArrayList<NodeType> nodesArray;

    private ArrayList < LinkedHashMap < Integer, WeightType > > edges;

    public Graph() {
	nodes = new LinkedHashMap<NodeType, Integer>();
	nodesArray = new ArrayList<NodeType>();
	edges = new ArrayList < LinkedHashMap < Integer, WeightType > > ();
    }

    public int size() {
	return nodesArray.size();
    }

    public void addNode(NodeType node) {
	int s = nodes.size();
	if (!nodes.containsKey(node)) {
	    nodes.put(node,new Integer(s));
	    nodesArray.add(node);
	    LinkedHashMap < Integer, WeightType > tmp1 = new LinkedHashMap<Integer, WeightType>();
	    edges.add(tmp1);
	}
    }

    public int getNodeIndex(NodeType node) {
	int ret=-1;
	Integer index = nodes.get(node);
	if (index == null) {
	    return ret;
	}
	ret = index.intValue();
	return ret;
    }

    public ArrayList<NodeType> getNodesArray() {
	return nodesArray;
    }

    public NodeType getNodeByIndex(int index) {
	if (index < 0 || index >= nodesArray.size()) {
	    return null;
	}
	return nodesArray.get(index);
    }

    public void addEdge(NodeType from, NodeType to, WeightType weight) {
	int iFrom = getNodeIndex(from);
	Integer iTo = nodes.get(to);
	edges.get(iFrom).put(iTo, weight);
    }

    public WeightType getEdge(NodeType from, NodeType to) {
	int iFrom = getNodeIndex(from);
	Integer iTo = nodes.get(to);
	return edges.get(iFrom).get(iTo);
    }

    public WeightType removeEdge(NodeType from, NodeType to) {
	int iFrom = getNodeIndex(from);
	Integer iTo = nodes.get(to);
	return edges.get(iFrom).remove(iTo);
    }

    public Set<Integer> getEdges(NodeType v) {
	int iv = getNodeIndex(v);
	return edges.get(iv).keySet();
    }

    class BFSAnswer {
	public int[] father;
	public int[] depth;
	public boolean[] visited;
    }
    public BFSAnswer bfs(NodeType startNodeN) {
	return bfs(startNodeN, -1);
    }
    public BFSAnswer bfs(NodeType startNodeN, int maxDepth) {
	int N = nodes.size();
	BFSAnswer ret = new BFSAnswer();
	ret.father = new int[N];
	ret.depth = new int[N];
        ret.visited = new boolean[N];
	Arrays.fill(ret.father, -1);
	Arrays.fill(ret.depth, -1);
	Arrays.fill(ret.visited, false);

	int startNode = getNodeIndex(startNodeN);
	ret.father[startNode] = -1;
	ret.depth[startNode] = 0;
	ret.visited[startNode] = true;

	Queue<Integer> queue = new LinkedList<Integer>();
	queue.add(new Integer(startNode));
	while (!queue.isEmpty()) {
	    Integer fromI = queue.poll();
	    if (fromI == null) {
		break;
	    }
	    int from = fromI.intValue();
	    if (maxDepth != -1 && ret.depth[from]>=maxDepth) {
		continue;
	    }
	    for (Iterator<Integer> i = edges.get(from).keySet().iterator(); i.hasNext(); ) {
		Integer toI = i.next();
		if (toI == null) {
		    continue;
		}
		int to = toI.intValue();
		if (ret.visited[to]) {
		    continue;
		}
		ret.visited[to] = true;
		ret.depth[to] = ret.depth[from]+1;
		ret.father[to] = from;
		queue.add(toI);
	    }
	}
	return ret;
    }

    class FloydWarshallAnswer {
	public long[][] distance;
	public int[][] middle; 

	public int[] getPath(int startIndex,int endIndex) {
	    if (middle[startIndex][endIndex]==-1) {
		return (new int[0]);
	    }
	    LinkedList<Integer> r = new LinkedList<Integer>();
	    getPath_r(startIndex, endIndex, r);
	    r.addFirst(new Integer(startIndex));
	    r.add(new Integer(endIndex));
	    int[] ret = new int[r.size()];
	    int i=0;
	    for (Iterator<Integer> i1 = r.iterator(); i1.hasNext(); ) {
		Integer ii = i1.next();
		ret[i]=ii.intValue();
		i++;
	    }
	    return ret;
	}
	private void getPath_r(int startIndex, int endIndex, LinkedList<Integer> ans) {
	    int mid = middle[startIndex][endIndex];
	    if (mid < 0) {
		return;
	    }
	    getPath_r(startIndex, mid, ans);
	    ans.add(new Integer(mid));
	    getPath_r(mid, endIndex, ans);
	}
    }
    public FloydWarshallAnswer floydwarshall() {
	int N = nodes.size();
	FloydWarshallAnswer ret = new FloydWarshallAnswer();

	ret.distance = new long[N][N];
	ret.middle = new int[N][N];
	for (int i=0; i<N; i++) {
	    for (int j=0; j<N; j++) {
		ret.distance[i][j]=Long.MAX_VALUE;
		ret.middle[i][j]=-1;
		Integer ji = new Integer(j);
		WeightType w = edges.get(i).get(ji);
		if (w != null) {
		    ret.distance[i][j] = w.longValue();
		    ret.middle[i][j]=-2;
		}
	    }
	}
	for (int i=0; i<N; i++) {
	    ret.distance[i][i]=0;
	}

	for (int k=0; k<N; k++) {
	    for (int i=0; i<N; i++) {
		if (ret.distance[i][k] == Long.MAX_VALUE) {
		    continue;
		}
		for (int j=0; j<N; j++) {
		    if (ret.distance[k][j] == Long.MAX_VALUE) {
			continue;
		    }
		    if (ret.distance[i][k] + ret.distance[k][j] < ret.distance[i][j]) {
			ret.distance[i][j] = ret.distance[i][k] + ret.distance[k][j];
			ret.middle[i][j]=k;
		    }
		}
	    }
	}
	return ret;
    }

    class DijkstraAnswer {
	public double[] dist=null;
	public int[] from=null;
    }
    public DijkstraAnswer dijkstra(NodeType startNode) {
	int v = getNodeIndex(startNode);
	DijkstraAnswer ret = new DijkstraAnswer();
	int N = nodes.size();
	boolean[] s = new boolean[N];
	Arrays.fill(s,false);
	int[] from = new int[N];
	Arrays.fill(from, -1);
	double[] dist = new double[N];
	Arrays.fill(dist, Double.MAX_VALUE);
	for (Iterator<Integer> i = edges.get(v).keySet().iterator(); i.hasNext(); ) {
	    Integer iTo = i.next();
	    WeightType weight = edges.get(v).get(iTo);
	    dist[iTo.intValue()] = weight.doubleValue();
	    from[iTo.intValue()] = v;
	}
	
	s[v]=true;
	dist[v]=0;

	for(int i=0; i<N-2; i++) {
	    /* pick an u */
	    int u=-1;
	    double min1 = Double.MAX_VALUE;
	    for (int j=0; j<N; j++) {
		if (s[j]) {
		    continue;
		}
		if (dist[j] < min1) {
		    min1 = dist[j];
		    u=j;
		}
	    }
	    if (min1==Double.MAX_VALUE) {
		u=-1;
	    }
	    if (u==-1) {
		break;
	    }

	    s[u]=true;

	    for (Iterator<Integer> it = edges.get(u).keySet().iterator(); it.hasNext(); ) {
		Integer iTo = it.next();
		WeightType weight = edges.get(u).get(iTo);
		int w = iTo.intValue();
		if (s[w]) continue;
		if(dist[u] + weight.doubleValue() < dist[w]) {
		    dist[w] = dist[u] + weight.doubleValue();
		    from[w] = u;
		}
	    }
	}
	ret.dist = dist;
	ret.from = from;
	return ret;
    }

}
