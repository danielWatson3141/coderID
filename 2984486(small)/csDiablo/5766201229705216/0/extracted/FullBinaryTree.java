import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class FullBinaryTree
{
	static final int inf = 0x7fffffff;

	LinkedList<LinkedList<Integer>> neighbours;
	int n;
	boolean[] used;
	boolean[] canBeUsed;

	public static void main(String[] args) throws Exception
	{
		FullBinaryTree solver = new FullBinaryTree();
		int numberOfTests = Console.nextInt();

		for (int i = 1; i <= numberOfTests; i++)
		{
			solver.readData();
			solver.solve(i);
		}
	}

	private void readData() throws Exception
	{
		n = Console.nextInt();
		canBeUsed = new boolean[n + 1];
		used = new boolean[n + 1];
		neighbours = new LinkedList<LinkedList<Integer>>();
		for (int i = 0; i <= n; i++)
		{
			neighbours.add(new LinkedList<Integer>());
		}

		int from, to;

		for (int i = 0; i < (n - 1); i++)
		{
			from = Console.nextInt();
			to = Console.nextInt();

			addEdge(from, to);
		}

		for (int i = 1; i <= n; i++)
			Collections.sort(neighbours.get(i));
	}

	private void addEdge(int from, int to)
	{
		neighbours.get(from).add(to);
		neighbours.get(to).add(from);
	}

	private void solve(int testIndex) throws Exception
	{
		int ans = inf;

		for (int bitmask = 0; bitmask < (1 << n); bitmask++)
		{
			int currentAns = calculate(bitmask);
			ans = Math.min(ans, currentAns);
		}

		Console.println(String.format("Case #%d: %d", testIndex, ans));
	}

	private int calculate(int bitmask)
	{
		if (bitmask == 68)
		{
			int h = 12;
			h *= h;
		}
		prepareGraph(bitmask);
		for (int root = 1; root <= n; root++)
		{
			if (canBeUsed[root])
			{
				prepareGraph(bitmask);
				boolean isOk = ok(root);
				if (isOk)
				{
					for (int node = 1; node <= n; node++)
					{
						if (!used[node] && canBeUsed[node])
							return inf;
					}
					return Integer.bitCount(bitmask);
				}
			}
		}

		return inf;
	}

	private void prepareGraph(int bitmask)
	{
		for (int i = 0; i < n; i++)
			if (((bitmask >> i) & 1) == 1)
			{
				canBeUsed[i + 1] = false;
				used[i + 1] = true;
			}
			else
			{
				canBeUsed[i + 1] = true;
				used[i + 1] = false;
			}
	}

	private boolean ok(int currentNode)
	{
		used[currentNode] = true;

		int numberOfNeighbours = 0;
		LinkedList<Integer> nextNodes = neighbours.get(currentNode);
		for (int i = 0; i < nextNodes.size(); i++)
		{
			int nextNode = nextNodes.get(i);
			if (canBeUsed[nextNode] && !used[nextNode])
			{
				numberOfNeighbours++;
			}
		}

		if ((numberOfNeighbours % 2) == 1)
			return false;

		for (int i = 0; i < nextNodes.size(); i++)
		{
			int nextNode = nextNodes.get(i);
			if (!used[nextNode] && canBeUsed[nextNode])
			{
				boolean isOk = ok(nextNode);
				if (!isOk)
				{
					return false;
				}
			}
		}

		return true;
	}

	public FullBinaryTree() throws Exception
	{
		// String inputFile = "input.txt";
		// String outputFile = "output.txt";
		String inputFile = "B-small-attempt0.in";
		String outputFile = "B-small-attempt0.out";
		Console c = new Console(inputFile, outputFile);
	}

	static class Console
	{
		static BufferedReader in;

		static StringTokenizer tokenizer;

		static PrintWriter out;

		public Console() throws Exception
		{
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		}

		public Console(String inputFileName, String outputFileName) throws Exception
		{
			in = new BufferedReader(new InputStreamReader(new FileInputStream(inputFileName)));
			out = new PrintWriter(outputFileName);
		}

		public static void println(String string)
		{
			out.write(string + "\n");
			out.flush();
		}

		public static String next() throws Exception
		{
			while ((tokenizer == null) || !tokenizer.hasMoreTokens())
			{
				tokenizer = new StringTokenizer(in.readLine());
			}

			return tokenizer.nextToken();
		}

		public static Integer nextInt() throws Exception
		{
			return Integer.parseInt(next());
		}
	}

}
