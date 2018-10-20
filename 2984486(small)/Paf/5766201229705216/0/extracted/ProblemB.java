import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.System.*;

public class ProblemB {


	public class Case {
		int numNodes;
		LinkedHashMap<Integer, LinkedHashSet<Integer>> initialEdges = new LinkedHashMap<Integer, LinkedHashSet<Integer>>();

		int bestRemovals = Integer.MAX_VALUE;

		public void solve(int caseIndex) {

			int maxRemovals = (1 << numNodes);
			for (int removals = 0; removals < maxRemovals; removals++) {
				if (isValid(removals)) {
					bestRemovals = Math.min(countOnes(removals), bestRemovals);
				}
			}

			println("Case #" + (caseIndex + 1) + ": " + bestRemovals);
		}

		boolean isValid(int removals) {
			Map<Integer, LinkedHashSet<Integer>> edges = new LinkedHashMap<Integer, LinkedHashSet<Integer>>();
			Set<Integer> nodes = new LinkedHashSet<Integer>();

			for (int i = 0; i < numNodes; i++) {
				if (!isRemoved(i, removals)) nodes.add(i);
			}
			for (Map.Entry<Integer, LinkedHashSet<Integer>> entry : initialEdges.entrySet()) {
				int n1 = entry.getKey();
				if (!isRemoved(n1, removals)) {
					for (Integer n2 : entry.getValue()) {
						if (!isRemoved(n2, removals)) {
							addToMultiMapLinkedHashSet(n1, n2, edges);
						}
					}
				}
			}

//			for (Integer node : nodes) {
//				LinkedHashSet<Integer> s = edges.get(node);
//			}

			for (Integer i : nodes) {
				Set<Integer> visited = new LinkedHashSet<Integer>();
				boolean result = find(i, visited, edges);
				if (result) {
					if (visited.equals(nodes)) {
						return true;
					}
					else {
						return false;
					}
				}
			}
			return false;
		}

		boolean find(int node, Set<Integer> visited, Map<Integer, LinkedHashSet<Integer>> edges) {
			visited.add(node);

			LinkedHashSet<Integer> s = new LinkedHashSet<Integer>();
			LinkedHashSet<Integer> temp = edges.get(node);
			if (temp != null) {
				for (Integer n : temp) {
					if (!visited.contains(n)) {
						s.add(n);
					}
				}
			}

			if (s.isEmpty()) {
				return true;
			}
			else if (s.size() == 1) {
				return false;
			}
			else if (s.size() >= 3) {
				return false;
			}
			else {
				for (Integer neigh : s) {
//					if (!visited.contains(neigh)) {
						if (!find(neigh, visited, edges)) {
							return false;
						}
//					}
				}
				return true;
			}
		}
		
		boolean isRemoved(int node, int removals) {
			return (removals & (1 << node)) != 0;
		}

		int countOnes(long removals) {
			int c = 0;
			while (removals != 0) {
				if ((removals & 1) != 0) c++;
				removals >>>= 1;
			}
			return c;
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

				addToMultiMapLinkedHashSet(n1 - 1, n2 - 1, c.initialEdges);
				addToMultiMapLinkedHashSet(n2 - 1, n1 - 1, c.initialEdges);
			}

			c.solve(caseIndex);
		}

		r.close();
	}

	public static void main(String[] args) throws Exception {
		fileWriter = new PrintWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream("output.txt"))));
		new ProblemB().run();
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



