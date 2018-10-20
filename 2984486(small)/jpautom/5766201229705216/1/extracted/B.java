import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;


public class B {
	static int N;
	static List<Integer>[] adj;
	
	
	static void solveCase() {
		N = sc.nextInt();
		adj = new List[N];
		for (int i=0; i<N; i++) adj[i] = new ArrayList<Integer>();
		for (int i=0; i<N-1; i++) {
			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			adj[x].add(y);
			adj[y].add(x);
		}

		int minCost = N+1;
		for (int root=0; root<N; root++) {
			boolean[] used = new boolean[N];
			int[] cost = visit(root, used);
			minCost = Math.min(minCost, cost[1]);
			//p("root", root, minCost);
		}
		printf("%d\n", minCost);
	}
	
	static int[] visit(int n, boolean[] used) {
		used[n] = true;
		List<int[]> children = new ArrayList<>();
		for (int m : adj[n]) {
			if (!used[m]) {
				children.add(visit(m, used));
			}
		}
		int[] res = new int[2];
		int total = 0;
		for (int[] child : children) {
			total += child[0] + 1;
		}
		res[0] = total;
		if (children.size() < 2) {
			res[1] = total;
		}
		
		else {
			List<Integer> aux = new ArrayList<Integer>();
			for (int i=0; i<children.size() - 1; i++) {
				for (int j=i+1; j<children.size(); j++) {
					int[] child1 = children.get(i);
					int[] child2 = children.get(j);
					aux.add(total - child1[0] - child2[0] - 2 + child1[1] + child2[1]);
				}
			}
			Collections.sort(aux);
			res[1] = aux.get(0);
		}
		
		//p(n, res);
		return res;
	}
	
	
	static void printf(String f, Object... args) {
		System.out.printf(f, args);
	}
	
	static void p(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	
	static Scanner sc;
	public static void main(String[] args) throws FileNotFoundException {
		sc = new Scanner(args.length > 0 ? new FileInputStream(args[0]) : System.in);
		int numCases = sc.nextInt();
		for (int nCase=1; nCase<=numCases; nCase++) {
			printf("Case #%d: ", nCase);
			solveCase();
		}
		sc.close();
	}

}
