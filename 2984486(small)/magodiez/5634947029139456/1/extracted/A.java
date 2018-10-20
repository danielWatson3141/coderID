import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Locale;
import java.util.Set;

/**
 * @author Mikeldi Latorre (mikeldi10@gmail.com)
 */
public class A implements Runnable {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
		new Thread(new A()).start();
	}

	public A() {
		try {
			System.setIn(new FileInputStream("a.in"));
			System.setOut(new PrintStream(new FileOutputStream("a.out")));
		} catch (FileNotFoundException e) {
			throw new RuntimeException();
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	public void run() {
		int numTests = in.readInt();
		for (int testNumber = 0; testNumber < numTests; testNumber++) {
			out.println("Case #" + (testNumber + 1) + ": " + algorithm());
		}
		out.close();
	}

	private String algorithm() {
		int n = in.readInt();
		int l = in.readInt();

		String[] plugs = in.readLine().split(" ");
		String[] devices = in.readLine().split(" ");
		
		Set<String> masks = new HashSet<String>();
		for(int i=0;i<n;i++){
			Set<String> newMasks = new HashSet<String>();
			boolean found = false;
			for(int j=0;j<n;j++){
				if(i==0){
					newMasks.add(getMask(plugs[i],devices[j]));
					found = true;
				}else{
					String mask = getMask(plugs[i],devices[j]);
					if(masks.contains(mask)){
						newMasks.add(mask);
						found = true;
					}
				}
			}
			if(!found)
				return "NOT POSSIBLE";
			else
				masks = newMasks;
		}

		return String.valueOf(getMoves(masks));
	}

	private int getMoves(Set<String> x) {
		int minMoves = Integer.MAX_VALUE;
		for (String mask : x) {
			minMoves = Math.min(minMoves, getMoves(mask));
		}
		return minMoves;
	}

	private int getMoves(String x) {
		int moves = 0;
		for (int i = 0; i < x.length(); i++) {
			if (x.charAt(i) == '1')
				moves++;
		}
		return moves;
	}

	private String getMask(String a, String b) {
		StringBuilder str = new StringBuilder();
		for (int i = 0; i < a.length(); i++) {
			if (a.charAt(i) == b.charAt(i)) {
				str.append('0');
			} else {
				str.append('1');
			}
		}
		return str.toString();
	}

	private String format(double x) {
		return String.format(Locale.ENGLISH, "%.7f", x);
	}

	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1000];
		private int curChar, numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		private int read() {
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

		public long readLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
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

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		public String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		public String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		public BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		public double readDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
	}
}
