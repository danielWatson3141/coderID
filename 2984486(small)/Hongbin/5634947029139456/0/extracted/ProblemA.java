import java.util.*;
import java.io.PrintStream;
import java.awt.Point;

public class ProblemA
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintStream out = System.out;

		//input
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = in.nextInt();
			int L = in.nextInt();
			
			boolean[][] outlets = new boolean[N][L];
			boolean[][] devices = new boolean[N][L];
			
			for (int i = 0; i < N; i++) {
			    String str = in.next();
				for (int j = 0; j < L; j++) {
					outlets[i][j] = str.charAt(j) == '1';
				}
			}
			for (int i = 0; i < N; i++) {
			    String str = in.next();
				for (int j = 0; j < L; j++) {
					devices[i][j] = str.charAt(j) == '1';
				}
			}
			
			Flows source = new Flows(outlets);
			Flows target = new Flows(devices);
			
			List<Flows> Q = new LinkedList<Flows>();
			List<Flows> V = new LinkedList<Flows>();
			Q.add(source);
			V.add(source);
			int nSteps = 0;
			boolean found = false;

			while (!Q.isEmpty()) {
				List<Flows> Q2 = new LinkedList<Flows>();
				for (Flows flows : Q) {
					if (flows.equals(target)) {
						found = true;
						break;
					}

					for (Flows f : flows.flip()) {
						if (isVisited(V, f)) continue;

						Q2.add(f);
						V.add(f);
					}
				}
				
				if (found) break;
				Q = Q2;
				nSteps++;
			}
			
			out.print("Case #" + t + ": ");
			if (found) {
				out.println(nSteps++);
			}
			else {
				out.println("NOT POSSIBLE");
			}
		}
	}
	
	static boolean isVisited(List<Flows> V, Flows f) {
		for (Flows item : V) {
			if (item.equals(f)) {
				return true;
			}
		}
		return false;
	}
		
}

class Flows
{
	boolean[][] flows;

	public Flows(boolean[][] f) {
		this.flows = f;
		sort();
	}
	
	public void sort() {
		for (int i = 0; i < flows.length; i++) {
			for (int j = i + 1; j < flows.length; j++) {
				if (larger(i, j)) {
					swap(i, j);
				}
			}
		}
	}
	
	void swap(int r1, int r2) {
		boolean[] tmp = flows[r1];
		flows[r1] = flows[r2];
		flows[r2] = tmp;
	}
	
	boolean larger(int r1, int r2) {
		for (int i = 0; i < flows[0].length; i++) {
			if (flows[r1][i] && !flows[r2][i]) return true;
			if (!flows[r1][i] && flows[r2][i]) return false;
		}
		return false;
	}
	
	public boolean equals(Flows f) {
		boolean[][] other = f.data();
		if (flows.length != other.length || flows[0].length != other[0].length) {
			return false;
		}
		
		for (int i = 0; i < flows.length; i++) {
			for (int j = 0; j < flows[0].length; j++) {
				if (flows[i][j] != other[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	
	public List<Flows> flip() {
		List<Flows> res = new ArrayList<Flows>(flows[0].length);
		for (int j = 0; j < flows[0].length; j++) {
			boolean[][] cpy = copy();
			for (int i = 0; i < flows.length; i++) {
				cpy[i][j] = !cpy[i][j];
			}
			res.add(new Flows(cpy));
		}
		return res;
	}
	
	public boolean[][] data() {
		return flows;
	}
	
	public boolean[][] copy() {
		boolean[][] cpy = new boolean[flows.length][flows[0].length];
		for (int i = 0; i < flows.length; i++) {
			for (int j = 0; j < flows[0].length; j++) {
				cpy[i][j] = flows[i][j];
			}
		}
		return cpy;
	}
	
	public String toString() {
		String str = "";
		for (int i = 0; i < flows.length; i++) {
			for (int j = 0; j < flows[0].length; j++) {
				if (flows[i][j]) {
					str += "1";
				}
				else {
					str += "0";
				}
			}
			str += " ";
		}
		return str;
	}
}



