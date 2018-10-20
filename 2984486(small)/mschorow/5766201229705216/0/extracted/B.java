import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();

		for (int testCase = 1; testCase <= t; testCase++) {
			int n = s.nextInt();
			boolean[][] adjacency = new boolean[n][n];
			for (int i = 0; i < n - 1; i++) {
				int x = s.nextInt() - 1;
				int y = s.nextInt() - 1;
				adjacency[x][y] = true;
				adjacency[y][x] = true;
			}
			int bestSet = 0;
			set: for (int set = 0; set < Math.pow(2, n); set++) {
				root: for (int root = 0; root < n; root++) {
					if (!isInSet(set, root))
						continue;
					if (! (traverse(root, set, -1, n, adjacency) == countOnes(set))) {
						continue root;
					}
					int size = countOnes(set);
					if (size > bestSet) {
//						 System.out.println(set + " " + root);
						bestSet = size;
					}
				}

			}
			System.out.println("Case #" + testCase + ": " + (n - bestSet));
		}

	}

	private static int traverse(int index, int set, int origin, int n,
			boolean[][] adjacent) {
		int numAdjacent = 0;
		int nodes = 0;
		for (int x = 0; x < n; x++) {
			if (!isInSet(set, x) || !adjacent[x][index])
				continue;
			if (x == origin) {
				continue;
			}
			numAdjacent++;
			if (numAdjacent > 2) {
				return -1;
			}
			int rest = traverse(x, set, index, n, adjacent);
			nodes += rest;
			if (rest < 0) {
				return -1;
			}
		}
		if(numAdjacent == 0 || numAdjacent == 2){
			return 1+nodes;
		}
		return -1;
	}

	private static int countOnes(int set) {
		int answer = 0;
		while (set > 0) {
			answer += set % 2;
			set /= 2;
		}
		return answer;
	}

	private static boolean isInSet(int set, int flag) {
		set = set >> flag;
		return set % 2 == 1;
	}
}
