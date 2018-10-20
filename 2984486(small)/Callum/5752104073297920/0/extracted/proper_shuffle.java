import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;

public class proper_shuffle {

	public static void main(String[] args) throws Exception {
		
		HashMap<Integer[], Integer> goods = new HashMap<Integer[], Integer>();
		HashMap<Integer[], Integer> bads = new HashMap<Integer[], Integer>();
		
		Random rand = new Random();
		
		for (int i = 0; i < 10000; i++) {
			Integer[] good = new Integer[1000];
			for (int j = 0; j < 1000; j++) {
				good[j] = j;
			}
			for (int j = 0; j < 1000; j++) {
				int p = rand.nextInt(1000 - j) + j;
				Integer temp = good[j];
				good[j] = good[p];
				good[p] = temp;
			}
			if (goods.containsKey(good)) {
				goods.put(good, goods.get(good) + 1);
			} else {
				goods.put(good, 1);
			}
		}
		for (int i = 0; i < 10000; i++) {
			Integer[] bad = new Integer[1000];
			for (int j = 0; j < 1000; j++) {
				bad[j] = j;
			}
			for (int j = 0; j < 1000; j++) {
				int p = rand.nextInt(1000 - j) + j;
				Integer temp = bad[j];
				bad[j] = bad[p];
				bad[p] = temp;
			}
			if (bads.containsKey(bad)) {
				bads.put(bad, bads.get(bad) + 1);
			} else {
				bads.put(bad, 1);
			}
		}
		
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0(1).in"));
		PrintWriter pw = new PrintWriter("C-small.out", "UTF-8");
		br.readLine();
		
		for (int i = 0; i < 120; i++) {
			pw.print("Case #" + (i + 1) + ": ");
			br.readLine();
			StringTokenizer st = new StringTokenizer(br.readLine());
			Integer[] temp = new Integer[1000];
			for (int j = 0; j < 1000; j++) {
				temp[j] = Integer.parseInt(st.nextToken());
			}
			if (goods.containsKey(temp)) {
				if (bads.containsKey(temp)) {
					if (goods.get(temp) > bads.get(temp)) {
						pw.println("GOOD");
					} else {
						pw.println("BAD");
					}
				} else {
					pw.println("GOOD");
				}
			} else if (bads.containsKey(temp)) {
				pw.println("BAD");
			} else {
				pw.println("GOOD");
			}
		}
		
		br.close();
		pw.close();
	}
}