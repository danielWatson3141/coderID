package com.g0426.a;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Test {

	// private static final String TASK = "sample";
	// private static final String TASK = "A-small-attempt3";
	// private static final String TASK = "A-small-attempt2";
	private static final String TASK = "A-large";

	int n, l;
	private ArrayList<Integer> a; // = new long[4];
	private ArrayList<Integer> b; // = new long[4];

	public Test(InputReader reader) throws IOException {
		n = reader.nextInt();
		l = reader.nextInt();
		a = new ArrayList<Integer>();
		b = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			String str = reader.nextString();
			int aa = 0;
			for (int j = 0; j < l; j++) {
				if ("1".equals(str.substring(j, j+1))) {
					aa ++;
				}
				aa *= 2;
			}
			aa /= 2;
			// System.out.println("a=" + aa);
			a.add(aa);
		}
		for (int i = 0; i < n; i++) {
			String str = reader.nextString();
			int aa = 0;
			for (int j = 0; j < l; j++) {
				if ("1".equals(str.substring(j, j+1))) {
					aa ++;
				}
				aa *= 2;
			}
			aa /= 2;
			// System.out.println("a=" + aa);
			b.add(aa);
		}
	}

	private String solve() throws Exception {
		int flip = 0;
		int enableFlip = 0;
		int flipSize = 0;
		
		long ll = 1;
		for (int j = 0; j < l; j++) {
			int aa = 0;
			int bb = 0;
			for (int i = 0; i < n; i++) {
				aa += a.get(i) % (ll * 2) / ll;
				bb += b.get(i) % (ll * 2) / ll;
			}
			if (aa != bb && (n - aa) == bb) {
				flip += ll;
				flipSize ++;
			} else if (aa == bb && (n - aa) == bb) {
				enableFlip += ll;
			} else if (aa != bb && (n - aa) != bb){
				return "NOT POSSIBLE";
			}
			ll *= 2;
		}
		
		// flip
		Collections.sort(b);
		ArrayList<Integer> newA = new ArrayList<Integer>();
		for (int lll : a) {
			newA.add(lll ^ flip);
		}
		Collections.sort(newA);
		boolean flag = true;
		for (int i = 0; i < n; i++) {
			if (newA.get(i).intValue() != b.get(i).intValue()) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return flipSize + "";
		}
		
		// enableFlipList
		ArrayList<Long> eList = new ArrayList<Long>();
		ll = 1;
		int enableFlipBackup = enableFlip;
		while (enableFlip > 0){
			if (enableFlip % 2 == 1) {
				eList.add(ll);
			}
			enableFlip /= 2;
			ll *= 2;
		}
		
		ll = 1;
		for (int i = 0; i < eList.size(); i++) {
			ll *= 2;
		}
		int bestFlip = Integer.MAX_VALUE;
		for (int j = 0; j < ll; j++) {
			ArrayList<Integer> tmpA = new ArrayList<Integer>();
			int tmpJ = j;
			int index = 0;
			flip = 0;
			while (tmpJ > 0) {
				if (tmpJ % 2 == 1) {
					flip += eList.get(index);
				}
				tmpJ /= 2;
				index++;
			}
			// System.out.println("enableFlip=" + enableFlipBackup + ", flip=" + flip);
			
			// flip = enableFlipList & j;
			
			for (int lll : newA) {
				tmpA.add(lll ^ flip);
			}
			Collections.sort(tmpA);
			boolean flag2 = true;
			for (int i = 0; i < n; i++) {
				if (tmpA.get(i).intValue() != b.get(i).intValue()) {
					flag2 = false;
					break;
				}
			}
			if (flag2) {
				int f = 0;
				int t = flip;
				while(t > 0) {
					if (t % 2 == 1) {
						f++;
					}
					t /= 2;
				}
				if (bestFlip > (flipSize + f)) {
					bestFlip = flipSize + f;
				}
			}
		}
		if (bestFlip != Integer.MAX_VALUE){
			return bestFlip +"";
		}
		
		return "NOT POSSIBLE";
	}
	

	public static void main(String[] args) throws Exception {
		String directory = new File("src\\"
			+ Test.class.getPackage().getName().replace(".", "/")).getAbsolutePath() +
			"\\";
		String inName = directory + TASK + ".in";
		String outName = directory + TASK + ".out";

		try (InputReader reader = new InputReader(inName);
				OutputWriter writer = new OutputWriter(outName)) {
			ExecutorService executorService = Executors.newFixedThreadPool(1); // TODO

			int testCaseN = reader.nextInt();
			final String[] result = new String[testCaseN];
			for (int i = 0; i < testCaseN; i++) {
				final Test test = new Test(reader);
				final int ii = i;
				executorService.submit(new Runnable() {
					@Override
					public void run() {
						try {
							result[ii] = test.solve();
						} catch (Exception e) {
							e.printStackTrace();
							System.out.println("failure :: " + ii);
							throw new RuntimeException("failure :: " + ii, e);
						}
					}
				});
			}
			executorService.shutdown();
			executorService.awaitTermination(10, TimeUnit.MINUTES);

			for (int i = 0; i < testCaseN; i++) {
				writer.println("Case #" + (i + 1) + ": " + result[i]);
				if (result[i] == null) {
					System.out.println("failure : " + i);
					throw new RuntimeException("failure : " + i);
				}
			}
		} catch (FileNotFoundException e) {
			System.out.println("FileNotFound : " + e.getMessage());
		}
	}
	
	/** Utility **/
	public static class InputReader implements AutoCloseable {
		private final BufferedReader reader;
		private StringTokenizer tokenizer = new StringTokenizer("");
		public InputReader(String filename) throws FileNotFoundException {
			this.reader = new BufferedReader(new FileReader(filename));
		}
		public String nextToken() throws IOException {
			while (!tokenizer.hasMoreTokens()) {
				tokenizer = new StringTokenizer(reader.readLine());
			}
			return tokenizer.nextToken();
		}
		public int nextInt() throws IOException {
			return Integer.parseInt(nextToken());
		}
		public long nextLong() throws IOException {
			return Long.parseLong(nextToken());
		}
		public double nextDouble() throws IOException {
			return Double.parseDouble(nextToken());
		}
		public String nextString() throws IOException {
			return nextToken();
		}
		@Override
		public void close() throws Exception {
			reader.close();
		}
	}
	
	public static class OutputWriter implements AutoCloseable {
		private final PrintWriter writer;
		public OutputWriter(String file) throws FileNotFoundException {
			writer = new PrintWriter(file);
		}
		public void println(String str) {
			System.out.println(str);
			writer.println(str);
		}
		@Override
		public void close() throws Exception {
			writer.close();
		}
	}
	
}
