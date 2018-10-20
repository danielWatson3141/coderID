import java.util.*;

public class BSmall {
	static int[][] memo;
	static boolean[][] tree;
	static int numNodes;

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int numCases = s.nextInt();
		for (int z = 1; z <= numCases; z++) {
			// if(z == 87){
			// while(s.hasNext()){
			// System.out.println(s.nextLine());
			// }
			// return;
			// }
			numNodes = s.nextInt();
			memo = new int[numNodes + 1][1 << numNodes];
			for (int a = 0; a <= numNodes; a++)
				Arrays.fill(memo[a], -1);
			tree = new boolean[numNodes][numNodes];
			for (int a = 0; a < numNodes - 1; a++) {
				int first = s.nextInt() - 1;
				int second = s.nextInt() - 1;
				tree[first][second] = tree[second][first] = true;
			}
			System.out.println("Case #" + z + ": " + run(0, 0));
		}
	}

	public static int run(int mask, int pos) {
		if (memo[pos][mask] != -1)
			return memo[pos][mask];
		if (works(mask)) {
			return memo[pos][mask] = 0;
		}
		if (pos >= numNodes)
			return memo[pos][mask] = 987654321;
		return memo[pos][mask] = Math.min(run(mask, pos + 1), run(set(mask, pos), pos + 1) + 1);
	}

	private static boolean works(int mask) {
		if (Integer.bitCount(mask) == numNodes - 1)
			return true;
		int activeNodes = numNodes - Integer.bitCount(mask);
		int activeEdges = 0;

		boolean foundRoot = false;
		for (int a = 0; a < numNodes; a++) {
			if (isSet(mask, a))
				continue;
			int numConnected = 0;
			for (int b = 0; b < numNodes; b++) {
				if (isSet(mask, b))
					continue;
				if (tree[a][b]){
					numConnected++;
					if(a > b) activeEdges++;
				}
			}
			if (numConnected == 2) {
				if (foundRoot)
					return false;
				foundRoot = true;
			} else if (numConnected != 3 && numConnected != 1) {
				return false;
			}
		}
		foundRoot &= activeEdges + 1 == activeNodes;
			return foundRoot;
	}

	public static boolean isSet(int mask, int pos) {
		return (mask & (1 << pos)) > 0;
	}

	public static int set(int mask, int pos) {
		return mask | (1 << pos);
	}

	public static int unset(int mask, int pos) {
		return mask & (~(1 << pos));
	}
}
