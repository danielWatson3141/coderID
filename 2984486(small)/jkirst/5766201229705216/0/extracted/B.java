import java.util.*;

public class B {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int cases = sc.nextInt();
	for (int z = 0; z < cases; z++) {
	    int N = sc.nextInt();
	    boolean[][] adjMat = new boolean[N][N];
	    int[] deg = new int[N];
	    for (int i = 0; i < N-1; i++) {
		int U = sc.nextInt();
		int V = sc.nextInt();
		adjMat[U-1][V-1] = true;
		adjMat[V-1][U-1] = true;
		deg[U-1]++;
		deg[V-1]++;
	    }
	    int minimum = Integer.MAX_VALUE;
	    for (int i = 0; i < N; i++) {
		//make i our root.
		int[] numChild = new int[N];
		int[] inSubtree = new int[N];//not including root.
		dfs(i, adjMat, numChild, inSubtree, new boolean[N]);
		int costTo = fix(i, adjMat, new boolean[N], numChild, inSubtree);
		//System.out.println("ROOTED AT: " + i + " COST: " + costTo);
		//System.out.println(Arrays.toString(inSubtree));
		minimum = Math.min(minimum, costTo);
	    }
	    System.out.printf("Case #%d: %d\n", (z+1), minimum);
	}
    }

   public static int fix(int root, boolean[][] adj, boolean[] used, int[] numChild, int[] sub) {
       used[root] = true;
       if (numChild[root] == 0) return 0;//its a leaf! we're good.
       if (numChild[root] == 1) {//only way to fix this is by killing its only child :'(
	   int cost = sub[root];
	   return cost;
       }
       if (numChild[root] == 2) {//good root...cost of fixing is fixing everything in subtrees!
	   int sum = 0;
	   for (int i = 0; i < adj.length; i++) {
	       if (adj[root][i] && !used[i]) {
		   sum += fix(i, adj, used, numChild, sub);
	       }
	   }
	   return sum;
       }
       //otherwise we have numChild[root] > 2...take best two!
       boolean[] copyUsed = new boolean[adj.length];
       for (int i = 0; i < adj.length; i++) copyUsed[i] = used[i];
       int[] childFix = new int[adj.length];//cost of fixing but leaving i...(cant delete i
	Arrays.fill(childFix, Integer.MAX_VALUE);//havent computed
	int sum = Integer.MAX_VALUE;
	for (int i = 0; i < adj.length; i++) {
	    if (adj[root][i] && !used[i]) {
		//root childFix and try and fix it!
		childFix[i] = fix(i, adj, used, numChild, sub);
		//childFix[i] = Math.min(childFix[i], sub[i]+1);
		/*if (childFix[i] != Integer.MAX_VALUE) {
		    sum += childFix[i];
		}*/
	    }
	}
	/*Arrays.sort(childFix);
	for (int i = 2; i < adj.length; i++) {
	    sum += sub[i]+1;
	    }*/
	//System.out.println(Arrays.toString(childFix));
	for (int i = 0; i < adj.length; i++) {
	    if (adj[root][i] && !copyUsed[i])
	    for (int j = 0; j < adj.length; j++) {
		if (adj[root][j] && !copyUsed[j])
		if (i != j) {
		    int costToFix = childFix[i];
		    int costTo = childFix[j];
		    //if (costToFix == Integer.MAX_VALUE || costTo == Integer.MAX_VALUE) continue;
		    //System.out.println("costToFix: " + costToFix);
		    //System.out.println("costTo: " + costTo);
		    int make = costToFix+costTo;
		    for (int k = 0; k < adj.length; k++) {
			if (k != i && k != j && adj[k][root] && !copyUsed[k]) make += sub[k] + 1;
		    }
		    sum = Math.min(sum, make);
		}
	    }
	}
	if (sum == Integer.MAX_VALUE) System.out.println("ERROR");
        return sum;
    }

    public static void dfs(int cur, boolean[][] adj, int[] numChild, int[] sub, boolean[] used) {
	int cnt = 0;
	int sum = 0;
	used[cur] = true;
	for (int i = 0; i < adj.length; i++) {
	    if (adj[cur][i] && !used[i]) {
		dfs(i, adj, numChild, sub, used);
		cnt++;
		sum += sub[i];
	    }
	}
	numChild[cur] = cnt;
	sub[cur] = sum + numChild[cur];
    }
}
