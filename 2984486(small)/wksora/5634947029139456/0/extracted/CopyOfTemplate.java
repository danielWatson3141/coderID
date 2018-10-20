import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CopyOfTemplate {
    public final static String INPUT_FILE = "d:\\A-small-attempt0 (1).in";
    public final static String OUTPUT_FILE = "d:\\out.txt";

    public void handle(Scanner scanner, PrintWriter output) {
	int caseNum = scanner.nextInt();
	for (int i = 0; i < caseNum; i++) {
	    output.print("Case #" + (i + 1) + ": ");
	    int N = scanner.nextInt();
	    int L = scanner.nextInt();
	    long[] outlets = new long[N];
	    long[] devices = new long[N];
	    for (int j = 0; j < N; j++) {
		String tmp = scanner.next();
		outlets[j] = Long.valueOf(tmp, 2);
	    }
	    for (int j = 0; j < N; j++) {
		String tmp = scanner.next();
		devices[j] = Long.valueOf(tmp, 2);
	    }
	    Map<Long, Integer> map = new HashMap<Long, Integer>();

	    int min = 99999;
	    for (int j = 0; j < ((1 << L) - 1); j++) {
		map.clear();
		for (int k = 0; k < N; k++) {
		    if (map.containsKey(devices[k])) {
			map.put(devices[k], map.get(devices[k]) + 1);
		    } else {
			map.put(devices[k], 1);
		    }
		}

		int flag = 1;
		for (int k = 0; k < N; k++) {
		    Long val = j ^ outlets[k];
		    if (map.containsKey(val)) {
			if (map.get(val) == 0) {
			    flag = 0;
			    break;
			}
			map.put(val, map.get(val) - 1);
		    } else {
			flag = 0;
			break;
		    }
		}
		if (flag == 0) {
		    continue;
		}

		int x = count0(j);
		if (x < min)
		    min = x;
	    }

	    if (min == 99999) {
		output.print("NOT POSSIBLE\n");
	    } else {
		output.print(min + "\n");
	    }
	    output.flush();

	}
    }

    public int count0(long val) {
	int count = 0;
	while (val != 0) {
	    if (val % 2 == 1)
		count++;
	    val /= 2;
	}
	return count;
    }

    /**
     * @param args
     */
    public static void main(String[] args) {
	// CASE CLASS!!!!!!!!
	CopyOfTemplate runner = new CopyOfTemplate();

	Scanner scanner = null;
	PrintWriter output = null;
	try {
	    scanner = new Scanner(new FileInputStream(INPUT_FILE));
	    // scanner = new Scanner(System.in);
	    output = new PrintWriter(new FileOutputStream(OUTPUT_FILE));
	    // output = new PrintWriter(System.out);
	    runner.handle(scanner, output);
	} catch (FileNotFoundException e) {
	    e.printStackTrace();
	} finally {
	    scanner.close();
	    output.close();
	}

    }

}
