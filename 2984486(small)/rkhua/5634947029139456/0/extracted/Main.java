package TaskA;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Vector;

/**
 * Thank you to Egor Kulikov for Java Template
 * Built using CHelper plug-in
 * @author Richard Hua (rich@rkhua.com)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		out.print("Case #" + testNumber + ": ");
		if (testNumber == 4) {
			assert Boolean.TRUE;
		}
		int totalNumbers = in.readInt();
		int totalBits = in.readInt();
		
		long[] numbers = new long[totalNumbers];

		for (int i = 0; i < numbers.length; i++) {
			numbers[i] = Long.parseLong(in.readString(), 2);
		}
		
		int[] onBits = new int[totalBits];
		for (int i = 0; i < onBits.length; i++) {
			onBits[i] = 0;
			for (int j = 0; j < numbers.length; j++) {
				onBits[i] += numbers[j] >> i & 1;
			}
		}
		
		long[] flows = new long[totalNumbers];
		for (int i = 0; i < numbers.length; i++) {
			flows[i] = Long.parseLong(in.readString(), 2);
		}
		
		int numFlips = 0;
		Vector<Integer> ambiguousBits = new Vector<Integer>();
		for (int i = 0; i < onBits.length; i++) {
			int flowOnBits = 0;
			for (int j = 0; j < numbers.length; j++) {
				flowOnBits += flows[j] >> i & 1;
			}
			if (flowOnBits != onBits[i]) {
				if (totalNumbers - flowOnBits != onBits[i]) {
					out.printLine("NOT POSSIBLE");
					return;
				}
				numFlips++;
				// Flip all bits
				for (int j = 0; j < flows.length; j++) {
					flows[j] = flows[j] ^ (1 << i);
				}
			} else if (totalNumbers - flowOnBits == flowOnBits) {
				ambiguousBits.add(i);
			}
		}
		
		if (ambiguousBits.size() == 0 && isMatching(numbers, flows, new Vector<Integer>())) {
			out.printLine(numFlips);
			return;
		}
		for (int i = 0; i <= ambiguousBits.size(); i++) {
			Vector<Integer> flipped = new Vector<Integer>();
			if (canMatch(i, ambiguousBits, numbers, flows, flipped, 0)) {
				out.printLine(numFlips + i);
				return;
			}
		}
		out.printLine("NOT POSSIBLE");
	}
	
	boolean canMatch(int numFlips, Vector<Integer> bits, long[] numbers, long[] flows, Vector<Integer> flipped, int startingBit) {
		if (numFlips == 0) return isMatching(numbers, flows, flipped);
		if (numFlips > bits.size() - startingBit) return false;
		
		for (int i = startingBit; i < bits.size(); i++) {
			flipped.add(bits.get(i));
			if (canMatch(numFlips - 1, bits, numbers, flows, flipped, i + 1)) {
				return true;
			}
			flipped.remove(flipped.size() - 1);
		}
		
		
		return false;
	}
	
	boolean isMatching(long[] numbers, long[] flows, Vector<Integer> flipped) {
		long flipper = 0;
		for (int i = 0; i < flipped.size(); i++) {
			flipper = flipper | 1 << flipped.get(i);
		}
		
		HashSet<Long> hashSet = new HashSet<Long>();
		for (int i = 0; i < flows.length; i++) {
			long flow = flows[i] ^ flipper;
			if (hashSet.contains(flow)) {
				return false;
			}
			hashSet.add(flow);
		}
		
		for (int i = 0; i < numbers.length; i++) {
			if (!hashSet.contains(numbers[i])) {
				return false;
			}
		}
		
		return true;
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}
	
	public char readChar() {
		int c;
		do {
			c = read();
		} while (isSpaceChar(c));
		
		return (char) c;
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}
	
	public float readFloat() {
		return Float.parseFloat(readString());
	}
	
	public double readDouble() {
		return Double.parseDouble(readString());
	}

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}
	
	public void readArray(char[] array) {
		for (int i = 0; i < array.length; i++) {
				array[i] = readChar();
		}
	}
	
	public void readArray(int[] array) {
		for (int i = 0; i < array.length; i++) {
				array[i] = readInt();
		}
	}

	public void readArray(char[][] array) {
		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array[i].length; j++)
				array[i][j] = readChar();
		}
	}

	public void readArray(int[][] array) {
		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array[i].length; j++)
				array[i][j] = readInt();
		}
	}

	public void readVerticalArrays(int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = readInt();
		}
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public String next() {
		return readString();
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

}

class MiscUtils {

	public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}
}

	
	
	