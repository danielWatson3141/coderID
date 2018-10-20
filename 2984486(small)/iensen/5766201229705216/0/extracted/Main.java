import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    int countReachableNodes(SparseGraph g, int curNode, boolean []visited) {
           visited[curNode] = true;
           int p=g.Head[curNode];
           int count = 0;
           while(p!=-1) {

            if(!visited[g.To[p]]){

               count += countReachableNodes(g,g.To[p],visited);
            }
            p=g.Next[p];
         }
        return count +1;
    }


    int solve(SparseGraph g, int curNode,int solved[],int N,boolean isEdge[][]) {

        if(solved[curNode]!=-1) {
            return solved[curNode];
        }

        ArrayList<Edge> list= (ArrayList<Edge>)g.getIncidentEdges(curNode);
        if(list.size()<2) {
            boolean []visited = new boolean[N];
            Arrays.fill(visited,false);

            int x=  countReachableNodes(g,curNode,visited)-1;
            return x;
        }

        ArrayList<Integer> listCt = new ArrayList<Integer>();
        ArrayList<Integer> listR = new ArrayList<Integer>();
        ArrayList<Integer> nodes = new ArrayList<Integer>();
        int totReach = 0;
        int p=g.Head[curNode];
        int count = 0;

        while(p!=-1) {

            int solvedCt = solve(g, g.To[p], solved, N,isEdge);
            boolean visited[] = new boolean[1001];
            int solveR = countReachableNodes(g,g.To[p],visited);
            totReach +=solveR;
            listR.add(solveR);
            listCt.add(solvedCt);
            nodes.add(g.To[p]);
            p=g.Next[p];
        }

        int best = totReach;
        for(int i=0;i<listR.size();i++) {
            for(int j=i+1;j<listR.size();j++) {


                if(!isEdge[nodes.get(i)][nodes.get(j)]) {
                   if(totReach - listR.get(i)-listR.get(j)+listCt.get(i)+listCt.get(j)<best)   {

                       best = totReach - listR.get(i)-listR.get(j)+listCt.get(i)+listCt.get(j);
                   }

                }

            }
        }

        return solved[curNode] = best;
    }

    int buildGraph(int prevNode,int curNode, boolean visited2[], SparseGraph g2, SparseGraph g) {
        int p=g.Head[curNode];
        visited2[curNode] = true;
        int count = 0;
        while(p!=-1) {

            if(!visited2[g.To[p]]){
                g2.addEdge(curNode,g.To[p]);
                buildGraph(curNode, g.To[p], visited2, g2, g);
            }
            p=g.Next[p];
        }
        return count;
    }
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        boolean isEdge[][] = new boolean[1001][1001];
        SparseGraph g = new SparseGraph(N,N*2+5);
        for(int i=0;i<N-1;i++) {
            int from = in.nextInt()-1;
            int to = in.nextInt() -1;
            g.addEdge(from,to);
            g.addEdge(to,from);
            isEdge[from][to] = true;
            isEdge[to][from] = true;
        }

        int curBest = Integer.MAX_VALUE;
        for(int root = 0;root<N-1;root++) {
            SparseGraph g2 = new SparseGraph(N,N+5);
            boolean []visited2 = new boolean[N];
            Arrays.fill(visited2,false);
            int ct = buildGraph(-1,root, visited2,g2,g);

            Arrays.fill(visited2,false);
            int ct2 = countReachableNodes(g,root,visited2);
            int solved[] = new int[N];
            Arrays.fill(solved,-1);
            int removed = solve(g2,root,solved,N,isEdge);
            if(removed+N-ct2 < curBest) {
                curBest = removed+N-ct2;
            }

        }
        out.println("Case #"+testNumber+": "+curBest);


    }
}

class SparseGraph extends   Graph
{
    public int []From;
    public int []To;
    public int Head[];
    public int Next[];

    int edgeCapacity;



    public SparseGraph(int vertexCount,int edgeCapacity)
    {
        From=new int[edgeCapacity];
        To=new int[edgeCapacity];
        Head=new int[vertexCount];
        Next=new int[edgeCapacity];
        Arrays.fill(Next,-1);
        Arrays.fill(Head,-1);
        this.edgeCapacity=edgeCapacity;

        this.vertexCount=vertexCount;
        edgeCount=0;
    }



    public void addEdge(int from, int to) {
        From[edgeCount]=from;
        To[edgeCount]=to;
        Next[edgeCount]=Head[from];
        Head[from]=edgeCount;
        ++edgeCount;

    }


    public List<Edge> getIncidentEdges(int vertexId)
    {
       ArrayList<Edge> list=new ArrayList<Edge>();
       int p=Head[vertexId];
       while(p!=-1) {
           Edge e=new Edge(To[p]);
           list.add(e);
           p=Next[p];
       }
        return list;
    }


}

class Edge implements Comparable<Edge>
{
   int from;
   public int to;
   public int weight;

    public  Edge(int to)
    {
        //this.from=from;
        this.to=to;
    }
    public Edge(int to,int weight)
    {
       this(to);
       this.weight=weight;
    }
    public Edge(int from,int to,int weight)
    {
        this(to);
        this.from=from;
        this.weight=weight;
    }
    public int compareTo(Edge edge)
    {
        if(this.weight< edge.weight)
        {
            return -1;
        }
        else if(this.weight==edge.weight && this.to==edge.to && this.from==edge.from) {
            return 0;
        }
        else return 1;
    }


}

class InputReader {

    private InputStream stream;
    int curCharIndex = 0;
    int charsInBuf = 0;
     byte buf[] = new byte[16*1024];

    public InputReader(InputStream stream) {
        this.stream = stream;
    }


    public int readChar() {

        if (curCharIndex >= charsInBuf) {
            curCharIndex = 0;
            try {
                charsInBuf = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (charsInBuf <= 0)
                return -1;
        }
        return buf[curCharIndex++];
    }


    public int nextInt() {

        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        int sign = 1;
        if (c == '-') {
            c = readChar();
            sign = -1;

        }
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        return sign * res;
    }


    public String nextToken() {
        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        return res.toString();
    }

    /*
    * For the purpose of compatibilty with Chelper Chrome extension
     */

    public String next() {
        return nextToken();
    }


    private boolean isWhitespace(int c) {
        return  c==' ' || c=='\n'|| c=='\r' || c=='\t';
    }
}

abstract class Graph
{
    public int vertexCount;
    public int edgeCount;


}


