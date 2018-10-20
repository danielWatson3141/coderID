import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Iron Maiden - Number of the Beast.
 * 
 * @author Gorokhov Nikita (wackloner@gmail.com)
 */

public class E implements Runnable {
	
	void solve() {
		int T = nextInt();
		for (int testNumber = 1; testNumber <= T; testNumber++) {
			int n = nextInt(), l = nextInt();
			int[] have = new int[n];
			for (int i = 0; i < n; i++)
				have[i] = Integer.parseInt(nextString(), 2);
			int[] need = new int[n];
			for (int i = 0; i < n; i++)
				need[i] = Integer.parseInt(nextString(), 2);
			boolean[] used = new boolean[1 << l];
			int best = 100;
			for (int mask = 0; mask < (1 << l); mask++) {
				for (int i = 0; i < n; i++)
					used[have[i] ^ mask] = true;
				boolean ok = true;
				for (int i = 0; i < n; i++)
					if (!used[need[i]])
						ok = false;
				if (ok)
					best = Math.min(best, Integer.bitCount(mask));
				for (int i = 0; i < n; i++)
					used[have[i] ^ mask] = false;
			}
			print("Case #");
			print(testNumber);
			print(": ");
			println(best == 100 ? "NOT POSSIBLE" : best);
		}
	}
	
	public static void main(String[] args) throws IOException {
		new E("input.txt", "output.txt").run();
	}
	
	E() {
		this.stream = System.in;
		this.writer = new PrintWriter(System.out);
	}
	
	E(String input, String output) throws IOException {
		File inputFile = new File(input);
		inputFile.createNewFile();
		stream = new FileInputStream(inputFile);
		File outputFile = new File(output);
		outputFile.createNewFile();
		writer = new PrintWriter(outputFile);
	}
	
	public void run() {
		solve();
		writer.close();
	}
	
	void halt() {
		writer.close();
		System.exit(0);
	}
	
	PrintWriter writer;;
	
	void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}
	
	void println(Object... objects) {
		print(objects);
		writer.println();
	}
	
	void printArray(int[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0) writer.print(' ');
			writer.print(array[i]);
		}
		writer.println();
	}
	
	void printArray(long[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0) writer.print(' ');
			writer.print(array[i]);
		}
		writer.println();
	}
	
	void printMatrix(int[][] matrix) {
		for (int i = 0; i < matrix.length; i++)
			printArray(matrix[i]);
	}
	
	void printMatrix(long[][] matrix) {
		for (int i = 0; i < matrix.length; i++)
			printArray(matrix[i]);
	}
	
	/**
	 * Pure Egor's code is straight ahead.
	 */
	
	InputStream stream;
	byte[] buf = new byte[1024];
	int curChar, numChars;
	
	int nextInt() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = next();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = next();
		} while (!isWhitespace(c));
		return res * sgn;
	}
	
	long nextLong() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = next();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = next();
		} while (!isWhitespace(c));
		return res * sgn;
	}
	
	double nextDouble() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = next();
		}
		double res = 0;
		while (!isWhitespace(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, nextInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = next();
		}
		if (c == '.') {
			c = next();
			double m = 1;
			while (!isWhitespace(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = next();
			}
		}
		return res * sgn;
	}
	
	BigInteger nextBigInteger() {
		try {
			return new BigInteger(nextString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}
	
	int next() {
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
	
	String nextString() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = next();
		} while (!isWhitespace(c));
		return res.toString();
	}
	
	String nextLine() {
		StringBuilder buf = new StringBuilder();
		int c = next();
		while (c != '\n' && c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = next();
		}
		return buf.toString();
	}
	
	boolean EOF() {
		int value;
		while (isWhitespace(value = peek()) && value != -1)
			next();
		return value == -1;
	}
	
	int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
	}
	
	boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
}