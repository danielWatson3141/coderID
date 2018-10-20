package gustafson.ryan;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class ChargingChaos {
    private final BufferedReader reader;
    private final PrintWriter writer;

    public ChargingChaos(String file) throws IOException {
	reader = new BufferedReader(new FileReader(file));
	writer = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
    }

    public void solve() throws IOException {
	int numCases = readInt();
	int[] pair = new int[2];
	for (int i = 0; i < numCases; i++) {
	    System.out.println("Case " + (i + 1));

	    read(pair);
	    int N = pair[0];
	    int L = pair[1];
	    String[] outlets = read();
	    String[] devices = read();

	    Arrays.sort(outlets);
	    Arrays.sort(devices);

	    System.out.println("N=" + N);
	    System.out.println("L=" + L);
	    dump(outlets, devices);

	    if (outlets.length != N) {
		throw new IllegalStateException("Expected outlets.length = " + N);
	    }
	    if (devices.length != N) {
		throw new IllegalStateException("Expected devices.length = " + N);
	    }

	    int flips = 0;
	    for (int j = 0; j < L; j++) {
		if (!aligned(outlets, devices, j)) {
		    flips++;
		    flip(outlets, j);
		    Arrays.sort(outlets);
//		    System.out.println("Flip at " + j);
//		    dump(outlets, devices);
		    if (!aligned(outlets, devices, j)) {
			flips = -1;
			break;
		    }
		}
	    }

	    writeCase(i + 1);
	    if (flips >= 0) {
		writer.print(flips);
	    } else {
		writer.print("NOT POSSIBLE");
	    }
	    writer.println();
	}
	writer.flush();
	writer.close();
    }

    private void dump(String[] outlets, String[] devices) {
	for (int i = 0; i < outlets.length; i++) {
	    System.out.println(outlets[i] + "  " + devices[i]);
	}
    }

    boolean aligned(String[] outlets, String[] devices, int position) {
	for (int i = 0; i < outlets.length; i++) {
	    if (!outlets[i].startsWith(devices[i].substring(0, position + 1))) {
		return false;
	    }
	}
	return true;
    }

    void flip(String[] values, int position) {
	for (int i = 0; i < values.length; i++) {
	    StringBuilder buf = new StringBuilder(values[i]);
	    buf.setCharAt(position, buf.charAt(position) == '1' ? '0' : '1');
	    values[i] = buf.toString();
	}
    }

    private void writeCase(int n) {
	writer.print("Case #");
	writer.print(n);
	writer.print(": ");
    }

    private int readInt() throws IOException {
	return Integer.parseInt(reader.readLine().trim());
    }

    private void read(int[] array) throws IOException {
	String line = reader.readLine();
	String[] split = line.split(" ");
	for (int i = 0; i < split.length; i++) {
	    array[i] = Integer.parseInt(split[i]);
	}
    }

    private String[] read() throws IOException {
	String line = reader.readLine();
	String[] split = line.split(" ");
	return split;
    }

    public static void main(String[] args) throws Exception {
	String file = "A-test.in";
	file = "A-small-attempt1.in";
	//file = "A-large.in";
	ChargingChaos fullBinaryTree = new ChargingChaos(file);
	fullBinaryTree.solve();
    }
}
