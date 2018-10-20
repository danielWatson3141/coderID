import java.util.*;
import java.io.*;

public class Tree {

	static Scanner in;
	static PrintWriter out;
	static int needToDelete;
	static int small;

	public static void main(String[] args) throws IOException {

		in = new Scanner(new FileInputStream("B-small-attempt0.in"));
		out = new PrintWriter(new FileOutputStream("B-small-attempt0.out"));

		int iteration = in.nextInt();

		for (int z = 1; z <= iteration; z++) {

			small = Integer.MAX_VALUE;

			int nodeN = in.nextInt();
			List[] connection;
			connection = new List[nodeN + 1];

			for (int i = 0; i < nodeN + 1; i++) {
				connection[i] = new LinkedList<Integer>();
			}

			for (int i = 0; i < nodeN - 1; i++) {
				int a = in.nextInt();
				int b = in.nextInt();

				connection[a].add(b);
				connection[b].add(a);
			}

			for (int i = 1; i <= nodeN; i++) {

				boolean[] touched = new boolean[connection.length];

				for (int j = 0; j < touched.length; j++) {
					touched[j] = false;
				}
				needToDelete = 0;
				traverse(i, connection, touched);
				if (needToDelete < small){
					small = needToDelete;
				}
			}

			System.out.println("Case #" + z + ": " + small);
			out.println("Case #" + z + ": " + small);
		}
		
		out.flush();
		out.close();
	}

	public static void traverse(int i, List[] connection, boolean[] touched) {

		if (touched[i]) {
			return;
		} else {
			touched[i] = true;
			int count = 0;
			for (int j = 0; j < connection[i].size(); j++) {
				if (!touched[(Integer) connection[i].get(j)]) {
					count++;
				}
			}
			if (count != 2) {
				countDelete(i, connection, touched);
				return;
			} else {
				for (int j = 0; j < connection[i].size(); j++) {
					traverse((Integer) connection[i].get(j), connection, touched);
				}
			}
			touched[i] = false;
		}

	}

	public static void countDelete(int i, List[] connection, boolean[] touched) {
		
		boolean[] newTouched = new boolean[touched.length];
		
		for (int j = 0; j < connection.length; j++){
			newTouched[j] = touched[j];
		}
		
		for (int j = 0; j < connection[i].size(); j++) {
			if (!touched[(Integer) connection[i].get(j)]) {
				needToDelete++;
				newTouched[(Integer) connection[i].get(j)] = true;
			}
		}
		
		for (int j = 0; j < connection[i].size(); j++) {
			if (!touched[(Integer) connection[i].get(j)]) {
				countDelete((Integer) connection[i].get(j), connection, newTouched);
			}
		}
		
	}

	public static boolean allTouched(boolean[] touched) {

		for (int i = 1; i < touched.length; i++) {
			if (touched[i] != true) {
				return false;
			}
		}

		return true;

	}

}
