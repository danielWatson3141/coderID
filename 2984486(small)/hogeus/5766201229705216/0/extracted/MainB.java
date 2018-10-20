package gcj;
import static java.lang.Math.*; 
import static java.util.Collections.*; 

import java.math.*; 
import java.util.*; 
import java.io.BufferedReader;
import java.io.FileReader;



public class Main {

	public  static class Nod implements Comparable<Nod> {
		int srt;
		int siz;
		int need;

		public Nod(int a, int b, int c) {
			srt = a;
			siz = b;
			need = c;
		}

		public boolean equals(Object obj0) {
			if (obj0 == this)
				return true;
			Nod c = (Nod) obj0;
			if (c.srt == srt && c.siz == siz && c.need == need)
				return true;
			return false;
		}

		public int hashCode() {
			return (int) srt ;
		}

		public int compareTo(Nod arg0) {
			if (srt == arg0.srt) {
				if (siz == arg0.siz)
					return need - arg0.need;
				return (siz > arg0.siz) ? 1 : -1;
			}
			return (srt > arg0.srt) ? 1 : -1;
		}

		public String toString() {
			return "(" + srt + "," + siz + ")";
		}
	}
	
	static int[] deg;
	static int[] degM;
	static int count = 0;

	static boolean[][] mat;
	static boolean[] visited;

	public static int visit(int v) {
		visited[v] = true;
		count += 1;

		if(degM[v] == 0) {
			return 0;
		}
		else if(degM[v] == 1) {
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(v);

			int res = 0;
			while(q.size() > 0) {
				int nn = q.pop();
				res++;		
				for(int j=0; j<degM.length; j++) {
					if(mat[nn][j] && !visited[j]) {
						//degM[j] -= 1;
						visited[j] = true;
						count += 1;
						q.add(j);
					}
				}
			}			
			return res - 1;
		}
		else if(degM[v] >= 2) {			
			ArrayList<Nod> visits = new ArrayList<Nod>();
			
			for(int j=0; j<degM.length; j++) {
				if(mat[v][j] && !visited[j]) {
					degM[j] -= 1;
					int nB = count;
					int inc = visit(j);									
					int tSize = count - nB;
					
					visits.add(new Nod (tSize - inc, tSize, inc) );
					//System.out.println(tSize + "," + inc);
					//System.out.println("TS:" + j + "," +  tSize + "," + inc);
				}
			}
			Collections.sort(visits, reverseOrder());
			
			int ret = 0;
			for(int j=0; j<min(2, visits.size()); j++) {
				ret += visits.get(j).need;
			}
			for(int j=2; j<visits.size(); j++)
				ret += visits.get(j).siz;

			//System.out.println(visits);
			
			return ret;
		}
		
		System.out.println("ERROR");
		return 0;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input"));

		int cases = Integer.parseInt(in.readLine().trim());

		for(int i=1; i<=cases; i++) {
			int N = Integer.parseInt(in.readLine().trim()); 

			mat = new boolean[N][N];
			deg = new int[N];
			degM = new int[N];
			Arrays.fill(deg, 0);
			Arrays.fill(degM, 0);
			
			for(int j=0; j<N-1; j++) {

				String[] edge = in.readLine().split(" ");
				int src = Integer.parseInt(edge[0]) - 1;
				int dst = Integer.parseInt(edge[1]) - 1;

				mat[src][dst] = true;
				mat[dst][src] = true;

				deg[src] += 1;
				deg[dst] += 1;
			}

			// consider roots
			int mn = Integer.MAX_VALUE;
			
			for(int j=0; j<N; j++) {
				for(int k=0; k<deg.length; k++) degM[k] = deg[k];
				
				visited = new boolean[N];				
				Arrays.fill(visited, false);
				
				mn = min(mn, visit(j));
			}
			//System.out.println(mn);

			System.out.println("Case #" + i + ": " + mn);
		}


		in.close();
	}
}
