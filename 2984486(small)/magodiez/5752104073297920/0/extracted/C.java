import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Locale;

/**
 * @author Mikeldi Latorre (mikeldi10@gmail.com)
 */
public class C implements Runnable {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
		new Thread(new C()).start();
	}

	public C() {
		try {
			System.setIn(new FileInputStream("c.in"));
			System.setOut(new PrintStream(new FileOutputStream("c.out")));
		} catch (FileNotFoundException e) {
			throw new RuntimeException();
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}
	
	int random(int min, int max){
		return min + (int)(Math.random() * ((max - min) + 1));
	}
	
	
	int distance(int[] x){
		int a=0;
		for (int i = 0; i < x.length; i++) {
			a+=Math.abs(i-x[i]);
		}
		return a;
	}
	
	int good(int n){
		int[] a = new int[n];
		for (int k=0; k<n;k++){
		  a[k] = k;
		}
		for (int k=0; k<n;k++){
		  int p = random(k,n-1);
		  int tmp = a[k];
		  a[k]=a[p];
		  a[p]=tmp;
		}
		return distance(a);
	}
	
	int bad(int n){
		int[] a = new int[n];
		for (int k=0; k<n;k++){
		  a[k] = k;
		}
		for (int k=0; k<n;k++){
		  int p = random(0,n-1);
		  int tmp = a[k];
		  a[k]=a[p];
		  a[p]=tmp;
		}
		return distance(a);
	}

	public void run() {
	 int numTests = in.readInt();
        for (int testNumber = 0; testNumber < numTests; testNumber++) {
        	out.println("Case #" + (testNumber + 1) + ": "+algorithm());
		}
		out.close();
	}
	
//	private String algorithm(){
//		long avg1 = 0;
//		long avg2 = 0;
//		for (int i = 0; i < 1000; i++) {
//			avg1+=good(1000);
//			avg2+=bad(1000);
//		}
//		return "\ngood:"+String.valueOf(avg1/1000)+"\nbad:"+String.valueOf(avg2/1000);
//	}
	
	private String algorithm(){
		int n = in.readInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.readInt();
		}
		return distance(a)>325500?"GOOD":"BAD";
//		return String.valueOf(distance(a));
	}
	
	private String format(double x){
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
