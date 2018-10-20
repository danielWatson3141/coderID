package round1;

import java.awt.Point;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class B {

	private static File inputF = new File("B-large.in");
	private static File outputF = new File("b_large.out");

	private static ArrayList<ArrayList<Integer>> edges;
	private static HashMap<Point, Integer> cost;
	private static HashMap<Point, Integer> subSize;
	private static int n;

	private static void calcCost(int i, int j) {
		Point pt = new Point(i, j);
		if (cost.containsKey(pt) || subSize.containsKey(pt)) {
			if (!(cost.containsKey(pt) && subSize.containsKey(pt))) {
				throw new RuntimeException();
			}
			return;
		}
		ArrayList<Integer> sonCts = new ArrayList<Integer>();
		int sumSize = 1;
		int ans = 0;
		for (int s : edges.get(j)) {
			if (s != i) {
				calcCost(j, s);
				Point tmpPt = new Point(j, s);
				sumSize += subSize.get(tmpPt);
				ans += cost.get(tmpPt);
				sonCts.add(subSize.get(tmpPt) - cost.get(tmpPt));
			}
		}
		subSize.put(pt, sumSize);
		if (sonCts.size() == 1) {
			ans += sonCts.get(0);
		} else {
			if (sonCts.size() > 2) {
				Collections.sort(sonCts);
				for (int k = 0; k < sonCts.size() - 2; k++) {
					ans += sonCts.get(k);
				}
			}
		}
		if (ans > sumSize - 1) {
			throw new RuntimeException();
		}
		cost.put(pt, ans);
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(inputF);
		BufferedWriter out = new BufferedWriter(new FileWriter(outputF));

		int numCase = sc.nextInt();
		for (int testNum = 0; testNum < numCase; testNum++) {
			out.write("Case #" + (testNum + 1) + ": ");

			n = sc.nextInt();
			edges = new ArrayList<ArrayList<Integer>>();
			cost = new HashMap<Point, Integer>();
			subSize = new HashMap<Point, Integer>();
			for (int i = 0; i < n; i++) {
				edges.add(new ArrayList<Integer>());
			}

			for (int i = 0; i < n - 1; i++) {
				int x = sc.nextInt() - 1;
				int y = sc.nextInt() - 1;
				edges.get(x).add(y);
				edges.get(y).add(x);
			}
			int ans = n + 1;
			for (int i = 0; i < n; i++) {
				int tmpCt = 0;
				ArrayList<Integer> tmpList = new ArrayList<Integer>();
				for (int j : edges.get(i)) {
					calcCost(i, j);
					Point tmpPt = new Point(i, j);
					tmpCt += cost.get(tmpPt);
					tmpList.add(subSize.get(tmpPt) - cost.get(tmpPt));
				}
				if (tmpList.size() == 1) {
					tmpCt += tmpList.get(0);
				} else {
					if (tmpList.size() > 2) {
						Collections.sort(tmpList);
						for (int k = 0; k < tmpList.size() - 2; k++) {
							tmpCt += tmpList.get(k);
						}
					}
				}
				if(tmpCt < ans) {
					ans = tmpCt;
				}
			}
			out.write(Integer.toString(ans));
			out.newLine();
		}
		sc.close();
		out.flush();
		out.close();
	}

}
