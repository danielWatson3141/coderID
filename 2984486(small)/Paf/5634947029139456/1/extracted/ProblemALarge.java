import static java.lang.Math.*;

import java.io.*;
import java.util.*;

public class ProblemALarge {


	public class Case {
		int numOutlets;
		int numSwitches;
		Set<Long> initial;
		Set<Long> target;

		int bestNumFlips = Integer.MAX_VALUE;
		Long bestFlips = null;

		public void solve(int caseIndex) {
			iterate(0, 0);

			println("Case #" + (caseIndex + 1) + ": " + (bestFlips == null ? "NOT POSSIBLE" : (""+bestNumFlips)));
		}

		void iterate(int pos, long flips) {
			if (!isValid(flips, pos)) {
				return;
			}

			if (pos >= numSwitches) {
				int numFlips = countFlips(flips);
				if (numFlips < bestNumFlips) {
					bestNumFlips = numFlips;
					bestFlips = flips;
				}

				return;
			}

			int onesInitial = countOnes(pos, initial);
			int onesTarget = countOnes(pos, target);
			if ((numOutlets & 1) == 0 && onesInitial == (numOutlets >> 1)) {
				iterate(pos + 1, flips);
				iterate(pos + 1, flips | (1 << pos));
			}
			else {
				if (onesInitial == onesTarget) {
					iterate(pos + 1, flips);
				}
				else if (onesInitial == numOutlets - onesTarget) {
					iterate(pos + 1, flips | (1 << pos));
				}
			}
		}

		int countOnes(int pos, Set<Long> s) {
			int mask = (1 << pos);
			int c = 0;
			for (Long l : s) {
				if ((l & mask) != 0) c++;
			}
			return c;
		}
		
		int countFlips(long flips) {
			int c = 0;
			while (flips != 0) {
				if ((flips & 1) != 0) c++;
				flips >>>= 1;
			}
			return c;
		}

		boolean isValid(long flips, int pos) {
			int mask = (1 << pos) - 1;
			Set<Long> s = new LinkedHashSet<Long>();
			for (Long f : initial) {
				s.add((f ^ flips) & mask);
			}
			Set<Long> t = new LinkedHashSet<Long>();
			for (Long f : target) {
				t.add(f & mask);
			}
			return s.equals(t);
		}


	}

	long parse(String s) {
		long l = 0;
		for (int i = 0; i < s.length(); i++) {
			l <<= 1;
			if (s.charAt(i) == '1') l |= 1;
		}
		return l;
	}
	
	public void run() throws Exception {
		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			InputParser p = new InputParser(r.readLine());

			c.numOutlets = p.readInt();
			c.numSwitches = p.readInt();

			c.initial = new LinkedHashSet<Long>(c.numOutlets);
			p = new InputParser(r.readLine());
			for (int i = 0; i < c.numOutlets; i++) {
				c.initial.add(parse(p.readToken()));
			}
			c.target = new LinkedHashSet<Long>(c.numOutlets);
			p = new InputParser(r.readLine());
			for (int i = 0; i < c.numOutlets; i++) {
				c.target.add(parse(p.readToken()));
			}
		

			c.solve(caseIndex);
		}

		r.close();
	}

	public static void main(String[] args) throws Exception {
		fileWriter = new PrintWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream("output.txt"))));
		new ProblemALarge().run();
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



