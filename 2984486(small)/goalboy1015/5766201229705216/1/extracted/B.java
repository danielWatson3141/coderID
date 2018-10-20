import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "B";
	static final String INPUT = "large";
	static final String ID = "0";
	static final String PATH = "/Users/wangkai/Documents/software installer/codejam-commandline-1.2-beta1/source/";

	public static void main(String[] args) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int N = in.nextInt();
			Node[] nodes = new Node[N];
			for (int i = 0; i < nodes.length; i++) {
				nodes[i] = new Node();
			}
			for (int i = 0; i < N - 1; i++) {
				int x = in.nextInt();
				int y = in.nextInt();
				nodes[x - 1].adjacents.add(y - 1);
				nodes[y - 1].adjacents.add(x - 1);
			}

			int minDeleteNum = Integer.MAX_VALUE;
			for (int i = 0; i < nodes.length; i++) {
				minDeleteNum = Math.min(minDeleteNum,
						searchTree(i, -1, nodes).deleted);
			}

			out.println(minDeleteNum);
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static Result searchTree(int index, int parent, Node[] nodes) {
		int deleted = 0;
		int remain = 1;

		ArrayList<Integer> remains = new ArrayList<Integer>();
		for (int adjacent : nodes[index].adjacents) {
			if (adjacent != parent) {
				Result result = searchTree(adjacent, index, nodes);
				deleted += result.deleted;
				remain += result.remain;
				remains.add(result.remain);
			}
		}

		Collections.sort(remains);

		if (remains.size() == 1) {
			deleted += remains.get(0);
			remain -= remains.get(0);
		} else if (remains.size() > 2) {
			for (int i = 0; i < remains.size() - 2; i++) {
				deleted += remains.get(i);
				remain -= remains.get(i);
			}
		}

		return new Result(deleted, remain);
	}
}

class Node {
	ArrayList<Integer> adjacents = new ArrayList<Integer>();
}

class Result {
	int deleted;
	int remain;

	Result(int deleted, int remain) {
		this.deleted = deleted;
		this.remain = remain;
	}
}