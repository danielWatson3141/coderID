package question;

import java.awt.Container;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

import utils.FileTools;

public class Qualification2014B1 {
	static int total;
	static int min;
	static ArrayList<Integer> revert = new ArrayList<Integer>();
static int N;
static int L;
	public static Long reverse(Long l, int bit) {
		bit=L-1-bit;
		int i = 1;
		i = i << bit;
		l ^= i;
		return l;
	}

	public static ArrayList<Long> revert(ArrayList<Long> list, int bit) {
		ArrayList<Long> newlist = new ArrayList<Long>();
		for (int i = 0; i < list.size(); i++) {
			Long l = list.get(i);
			newlist.add(reverse(l, bit));
		}
		return newlist;
	}

	public static boolean tryRevert(int index, ArrayList<Long> a1, ArrayList<Long> a2) {
		int bit = revert.get(index);
		boolean res = false;
		{
			if (index == revert.size() - 1) {
				if (compare(a1, a2)) {
					res = true;
					if (min > total) {
						min = total;
					}
				}
			} else {
				res = res || tryRevert(index + 1, a1, a2);
			}
		}
		{
			total++;
			a1 = revert(a1, bit);
			if (index == revert.size() - 1) {
				if (compare(a1, a2)) {
					res = true;
					if (min > total) {
						min = total;
					}
				}
			} else {
				res = res || tryRevert(index + 1, a1, a2);
			}
		}
		total--;
		return res;
	}

	public static boolean compare(ArrayList<Long> a1, ArrayList<Long> a2) {
		Collections.sort(a1);
		Collections.sort(a2);
//		System.out.println(a1);
//		System.out.println(a2);
		for (int i = 0; i < a1.size(); i++) {
			if (!a1.get(i).equals(a2.get(i))) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		try {
			FileTools ft = new FileTools("A-small-attempt4.in");
			int T = Integer.parseInt(ft.in.readLine());
			String line;

			for (int i = 0; i < T; i++) {
				line = (ft.in.readLine());
				String[] l = line.split(" ");
				N = Integer.parseInt(l[0]);
				L = Integer.parseInt(l[1]);
				String line1 = (ft.in.readLine());
				String[] l1 = line1.split(" ");
				String line2 = (ft.in.readLine());
				String[] l2 = line2.split(" ");
				revert = new ArrayList<Integer>();
				ArrayList<Long> a1 = new ArrayList<Long>();
				ArrayList<Long> a2 = new ArrayList<Long>();
				HashMap<Integer, Integer> m1 = new HashMap<Integer, Integer>();
				HashMap<Integer, Integer> m2 = new HashMap<Integer, Integer>();
				min = Integer.MAX_VALUE;
				for (String s : l1) {
					a1.add(Long.parseLong(s, 2));
					for (int j = 0; j < L; j++) {
						int n = Integer.parseInt(Character.toString(s.charAt(j)));
						if (!m1.containsKey(j)) {
							m1.put(j, n);
						} else {
							m1.put(j, m1.get(j) + n);
						}
					}
				}
				for (String s : l2) {
					a2.add(Long.parseLong(s, 2));
					for (int j = 0; j < L; j++) {
						int n = Integer.parseInt(Character.toString(s.charAt(j)));
						if (!m2.containsKey(j)) {
							m2.put(j, n);
						} else {
							m2.put(j, m2.get(j) + n);
						}
					}
				}
				Collections.sort(a1);
				Collections.sort(a2);
				total = 0;
				boolean poss = true;
				for (int j = 0; j < L; j++) {
					int k1 = m1.get(j);
					int k2 = m2.get(j);
					if (k1 == k2) {
						if (k1 + k2 == N) {
							revert.add(j);
						}
					} else if (k1 + k2 == N) {
						total++;
						a1 = revert(a1, j);
					} else {
						poss = false;
					}
				}
				if (poss) {
					if (revert.size() > 0) {
						poss = tryRevert(0, a1, a2);
					} else {
						poss = compare(a1, a2);
						if(poss){
						if (min > total) {
							min = total;
						}
						}
					}
				}
				if (poss) {
					ft.out.write("Case #" + (i + 1) + ": " + min);
					System.out.println("Case #" + (i + 1) + ": " + min);
				} else {
					ft.out.write("Case #" + (i + 1) + ": NOT POSSIBLE");
					System.out.println("Case #" + (i + 1) + ": NOT POSSIBLE");
				}
				ft.out.newLine();
				// ft.in.readLine();
			}

			ft.out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
