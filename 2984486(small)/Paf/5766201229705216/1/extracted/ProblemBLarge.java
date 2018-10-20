import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.System.*;

public class ProblemBLarge {

	static class Choice {
		int sumIfDeleted;
		int sumIfKept;

		int value() {
			return sumIfDeleted - sumIfKept;
		}
	}

	public class Case {
		int numNodes;
		LinkedHashMap<Integer, LinkedHashSet<Integer>> edges = new LinkedHashMap<Integer, LinkedHashSet<Integer>>();

		int bestRemovals = Integer.MAX_VALUE;

		public void solve(int caseIndex) {

			for (int i = 0; i < numNodes; i++) {
//				System.out.println("Root: "+i);
				int removals = find(i, new LinkedHashSet<Integer>());
				bestRemovals = Math.min(removals, bestRemovals);
			}

			println("Case #" + (caseIndex + 1) + ": " + bestRemovals);
		}

		int find(int node, Set<Integer> visited) {
			visited.add(node);

			LinkedHashSet<Integer> s = new LinkedHashSet<Integer>();
			{
				LinkedHashSet<Integer> temp = edges.get(node);
				if (temp != null) {
					for (Integer n : temp) {
						if (!visited.contains(n)) {
							s.add(n);
						}
					}
				}
			}

			if (s.size() == 0) {
				return 0;
			}
			else if (s.size() == 2) {
				int sum = 0;
				for (Integer n : s) {
					sum += find(n, visited);
				}
				return sum;
			}
			else {
				ArrayList<Choice> choices = new ArrayList<Choice>();
				for (Integer n : s) {
					LinkedHashSet<Integer> temp = new LinkedHashSet<Integer>();
					temp.add(node);
					Choice c = new Choice();
					c.sumIfDeleted = getSize(n, temp);
					c.sumIfKept = find(n, visited);
					choices.add(c);
//					System.out.println("Delete: "+n+": "+size);
				}
				Collections.sort(choices, new Comparator<Choice>() {
					@Override
					public int compare(Choice o1, Choice o2) {
						return Integer.compare(o2.value(), o1.value());
					}
				});
				int sum = 0;
				while (choices.size() != 2 && choices.size() != 0) {
					Choice c = choices.remove(choices.size() - 1);
					sum += c.sumIfDeleted;
				}
				for (Choice c : choices) {
					sum += c.sumIfKept;
				}

//				System.out.println("Returning: "+sum);
				return sum;

//				ArrayList<Integer> sizes = new ArrayList<Integer>();
//				for (Integer n : s) {
//					LinkedHashSet<Integer> temp = new LinkedHashSet<Integer>();
//					temp.add(node);
//					int size = getSize(n, temp);
//					sizes.add(size);
//					System.out.println("Delete: "+n+": "+size);
//				}
//				Collections.sort(sizes, Collections.reverseOrder());
//				int sum = 0;
//				while (sizes.size() != 2 && sizes.size() != 0) {
//					sum += sizes.remove(sizes.size() - 1);
//				}
//				System.out.println("Returning: "+sum);
//				return sum;
			}
		}

		int getSize(int node, Set<Integer> visited) {
			visited.add(node);

			int sum = 1;
			LinkedHashSet<Integer> temp = edges.get(node);
			if (temp != null) {
				for (Integer n : temp) {
					if (!visited.contains(n)) {
						sum += getSize(n, visited);
					}
				}
			}
			return sum;
		}

	}

	public void run() throws Exception {
		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			InputParser p = new InputParser(r.readLine());
			c.numNodes = p.readInt();
			for (int i = 0; i < c.numNodes - 1; i++) {
				p = new InputParser(r.readLine());
				int n1 = p.readInt();
				int n2 = p.readInt();

				addToMultiMapLinkedHashSet(n1 - 1, n2 - 1, c.edges);
				addToMultiMapLinkedHashSet(n2 - 1, n1 - 1, c.edges);
			}

			c.solve(caseIndex);
		}

		r.close();
	}

	public static void main(String[] args) throws Exception {
		fileWriter = new PrintWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream("output.txt"))));
		new ProblemBLarge().run();
		fileWriter.close();
	}

	public static class InputParser {
		String text;
		int pos;

		public InputParser(String text) {
			this.text = text;
		}

		public void skipSpaces() {
			while (pos < text.length()) {
				if (text.charAt(pos) != ' ') break;
				pos++;
			}
		}

		public String readUntil(char expectedChar) {
			StringBuilder b = new StringBuilder();
			while (pos < text.length()) {
				char ch = text.charAt(pos);
				if (ch == expectedChar) break;
				b.append(ch);
				pos++;
			}
			return b.toString();
		}

		public String readToken() {
			skipSpaces();
			return readUntil(' ');
		}

		public int readInt() {
			return Integer.parseInt(readToken());
		}

		public long readLong() {
			return Long.parseLong(readToken());
		}

		public double readDouble() {
			return Double.parseDouble(readToken());
		}

		public char readChar() {
			char ch = text.charAt(pos);
			pos++;
			return ch;
		}

		public void readExpectedString(String s) {
			for (int i = 0; i < s.length(); i++) {
				char ch = s.charAt(i);
				if (readChar() != ch) throw new RuntimeException("Expected: "+ch);
			}
		}
	}

	public static PrintWriter fileWriter;

	public static void print(String text) {
		fileWriter.print(text);
		System.out.print(text);
	}

	public static void println(String text) {
		fileWriter.println(text);
		System.out.println(text);
	}

	public static <Key, Value> void addToMultiMapArrayList(Key key, Value value, Map<Key, ArrayList<Value>> map) {
		ArrayList<Value> list = map.get(key);
		if (list == null) {
			list = new ArrayList<Value>();
			map.put(key, list);
		}
		list.add(value);
	}

	public static <Key, Value> void addToMultiMapLinkedHashSet(Key key, Value value, Map<Key, LinkedHashSet<Value>> map) {
		LinkedHashSet<Value> list = map.get(key);
		if (list == null) {
			list = new LinkedHashSet<Value>();
			map.put(key, list);
		}
		list.add(value);
	}

	public static <Key, Value> ArrayList<Value> getMultiMapValues(Map<Key, Collection<Value>> map) {
		ArrayList<Value> result = new ArrayList<Value>();
		for (Collection<Value> list : map.values()) {
			result.addAll(list);
		}
		return result;
	}

//	binarySearch(, , 0.000000001, new Function<Double, Integer>() {
//		public Integer evaluate(Double key) {
//			return ;
//		}
//	});
	public static double binarySearch(double low, double high, double precision, Function<Double, Integer> f) {
		if (high < low) throw new RuntimeException("High ("+high+") cannot be smaller than low ("+low+")");
		{
			int lowValue = f.evaluate(low);
			if (lowValue == 0) return low;
			if (lowValue > 0) throw new RuntimeException("Unsuitable low: "+low);
		}
		{
			int highValue = f.evaluate(high);
			if (highValue == 0) return high;
			if (highValue < 0) throw new RuntimeException("Unsuitable high: "+high);
		}

		while (true) {
			double mid = (low + high) * 0.5;
			if (abs(high - low) < precision) {
				return mid;
			}

			int c = f.evaluate(mid);
			if (c < 0) low = mid;
			else if (c > 0) high = mid;
			else return mid;
		}
	}

	public static <T> LinkedHashSet<T> intersection(Set<T> s1, Set<T> s2) {
		if (s2.size() < s1.size()) {
			Set<T> temp = s1;
			s1 = s2;
			s2 = temp;
		}
		LinkedHashSet<T> result = new LinkedHashSet<T>();
		for (T o : s1) {
			if (s2.contains(o)) result.add(o);
		}
		return result;
	}

	public static interface Function<Key, Value> {
		public Value evaluate(Key key);
	}

	public static class Int2 {
		int x, y;

		public Int2(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Int2 other = (Int2) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		@Override
		public String toString() {
			return "("+x+","+y+")";
		}
	}
}



