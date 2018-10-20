import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class random {
	public static void main (String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("C-small-attempt1.in")));
		Integer n = Integer.parseInt(br.readLine());
		double average = 0;
		ArrayList<Double> results = new ArrayList<Double>();
		for (int i = 0; i < n; i++) {
			int s = Integer.parseInt(br.readLine());
			String[] perm = br.readLine().split(" ");
			double count = 0;
			for (int j = 0; j < (s/2); j++) {
				int test = Integer.parseInt(perm[j]);
				count += Math.min(s-test, test);
			}
			average += count;
			results.add(count);
		}
		average = average/n;
		for (int i = 0; i < n; i++) {
			if (results.get(i) < average) {
				System.out.println("Case #"+(i+1)+": BAD");
			} else {
				System.out.println("Case #"+(i+1)+": GOOD");
			}
		}
	}
}
