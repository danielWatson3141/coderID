import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Scanner;
import java.util.TreeMap;

public class FullBinaryTree {
	public static HashMap<Integer, LinkedList<Integer>> tree;
	public static ArrayList<TreeMap<Integer, Integer>> nbPoints;

	public static int howMany(int pt, int from)
	{
		Integer result = nbPoints.get(pt).get(from);
		if (result != null) return result;
		int b1 = 0, b2 = 0, current;
		for (int i : tree.get(pt))
		{
			if (i == from) continue;
			current = howMany(i, pt);
			if (current > b1)
			{
				b2 = b1;
				b1 = current;
			} else if (current > b2)
			{
				b2 = current;
			}
		}
		if (b2 == 0)
			result = 1;
		else result = b1 + b2 + 1;
		nbPoints.get(pt).put(from, result);
		return result;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		in.useLocale(Locale.ENGLISH);
		int T = in.nextInt(), i = 0, N, j, p1, p2;
		tree = new HashMap<Integer, LinkedList<Integer>>(4096);
		nbPoints = new ArrayList<TreeMap<Integer, Integer>>(1001);
		for (j = 0; j < 1001; ++j)
			nbPoints.add(null);
		while (i++ < T)
		{
			System.out.print("Case #" + i + ": ");
			N = in.nextInt();
			if (N == 2)
			{
				in.nextInt();
				in.nextInt();
				System.out.println(1);
				continue;
			}
			tree.clear();
			for (j = 1; j <= N; ++j)
			{
				tree.put(j, new LinkedList<Integer>());
				nbPoints.set(j, new TreeMap<Integer, Integer>());
			}
			for (j = 1; j < N; ++j)
			{
				p1 = in.nextInt();
				p2 = in.nextInt();
				tree.get(p1).add(p2);
				tree.get(p2).add(p1);
			}
			int max = 0, current;
			for (j = 1; j <= N; ++j)
			{
				if (tree.get(j).size() < 2)
					continue;
				current = howMany(j, 0);
				if (current > max)
					max = current;
			}
			System.out.println(N - max);
		}
		in.close();
	}
}
