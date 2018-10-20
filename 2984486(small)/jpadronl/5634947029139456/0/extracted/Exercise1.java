package code.jam.round1;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Exercise1 {

	private static int tests;
	private static int devices;
	private static int outlets;
	private static ArrayList<String> outlet;
	private static ArrayList<String> device;

	private static String resolveProblem(ArrayList<String> outlet,
			int changes, int pos) throws IOException {


		if (changes > outlets) {
			return "NOT POSSIBLE";
		} else {
			for (int i = pos; i < outlets; i++) {
				String conf = outlet.get(i);
				StringBuilder sb = new StringBuilder(conf);
				if (conf.charAt(i) == '0')
					sb.setCharAt(i, '1');
				else
					sb.setCharAt(i, '0');
				outlet.set(i, sb.toString());
			}
			if (outlet.containsAll(device))
				return Integer.toString(changes);
			else
				return resolveProblem(outlet, changes + 1, pos);
		}
	}

	private static int times(String substring, String pattern) {
		int cont = 0;
		while (pattern.indexOf(substring) > -1) {
			pattern = pattern.substring(pattern.indexOf(
					substring)+substring.length(),pattern.length());
			cont++;
		}
		return cont;
	}

	private static ArrayList<String> applyPatternTo(ArrayList<String> list, String pattern) {
		ArrayList<String> newList = new ArrayList<String>(list);
		for (int i = 0; i < pattern.length(); i++) {
			if (pattern.charAt(i) == '1') {
				for (int k = 0; k < list.size(); k++) {
					String conf = newList.get(k);
					StringBuilder sb = new StringBuilder(conf);
					if (conf.charAt(i) == '0')
						sb.setCharAt(i, '1');
					else
						sb.setCharAt(i, '0');
					newList.set(k, sb.toString());
				}
			}
		}
		return newList;
	}

	private static String resolveProblemNew() {
		int combinations = (int) (Math.pow(2, outlets) - 1);
		int better = Integer.MAX_VALUE;
		for (int i = 1; i <= combinations; i++) {
			String pattern = String.format("%0" + outlets + "d",Integer.parseInt(Integer.toBinaryString(i)));
			ArrayList<String> candidate = applyPatternTo(outlet, pattern);
			if (candidate.containsAll(device)) {
				int result = times("1", pattern);
				if (better > result) {
					better = result;
				}
			}
		}
		if (better == Integer.MAX_VALUE) {
			return "NOT POSSIBLE";
		} else {
			return Integer.toString(better);
		}
	}

	public static void main(String [] params) throws IOException {

//		FileReaderUtils fileUtils = new FileReaderUtils("1_Round_Example_1.in");
		FileReaderUtils fileUtils = new FileReaderUtils("/Users/jpadron/Downloads/A-small-attempt3.in");
		FileWriterUtils fileWriterUtils = new FileWriterUtils("exercise1_small.out");
//		FileWriterUtils fileWriterUtils = new FileWriterUtils("exercise1_large.out");
		tests = Integer.parseInt(fileUtils.readLine());
		for (int i = 0; i < tests; i++) {
			String[] line = fileUtils.readLine().split(" ");
			devices = Integer.parseInt(line[0]);
			outlets = Integer.parseInt(line[1]);

			line = fileUtils.readLine().split(" ");
			outlet = new ArrayList<String>(line.length);
			for (int k = 0; k < line.length; k++) {
				outlet.add(line[k]);
			}

			line = fileUtils.readLine().split(" ");
			device = new ArrayList<String>(line.length);
			for (int k = 0; k < line.length; k++) {
				device.add(line[k]);
			}
			String result;
			if (device.containsAll(outlet))
				result = "0";
			else
				result = resolveProblemNew();
			fileWriterUtils.writeLine("Case #" + (i+1) + ": " + result + "\n");
		}
		fileWriterUtils.close();
	}

	public static class FileReaderUtils {

		private final File file;
		private final BufferedReader reader;

		public FileReaderUtils(String fileName) throws FileNotFoundException {
			this.file = new File(fileName);
			reader = new BufferedReader(new FileReader(file));
		}

		public String readLine() throws IOException {
			return reader.readLine();
		}
	}

	public static class FileWriterUtils {

		private final File file;
		private final BufferedWriter writer;

		public FileWriterUtils(String fileName) throws IOException {
			this.file = new File(fileName);
			writer = new BufferedWriter(new FileWriter(file));
		}

		public void writeLine(String line) throws IOException {
			writer.write(line);
		}

		public void close() throws IOException {
			writer.close();
		}
	}

}
