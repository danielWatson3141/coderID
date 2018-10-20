import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class ChargingChaos {

	public static void main(String[] args) throws IOException {
		boolean flag = false;
		int numCases = 0;
		String[] line = new String[2];
		String[] line2;
		int n;
		int binary = 0;
		int length = 0;
		int min = 0;
		ArrayList<Integer> e1;
		ArrayList<Integer> e1b;
		ArrayList<Integer> e2;
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt2.in"));

		numCases = Integer.parseInt(br.readLine());

		for (int i = 1; i <= numCases; i++) {
			min = 0;
			flag = false;
			binary = 0;
			line = br.readLine().split(" ");
			n = Integer.parseInt(line[0]);
			length = Integer.parseInt(line[1]);

			line2 = new String[n];
			line2 = br.readLine().split(" ");

			e1 = new ArrayList<Integer>(n);
			e2 = new ArrayList<Integer>(n);

			for (int j = 0; j < n; j++) {
				e1.add(Integer.parseInt(line2[j]));
			}
			Collections.sort(e1);
			e1b = new ArrayList<Integer>(e1);

			line2 = br.readLine().split(" ");

			for (int j = 0; j < n; j++) {
				e2.add(Integer.parseInt(line2[j]));
			}
			Collections.sort(e2);

			for (int j = 0; j < Math.pow(2, length) && flag == false; j++) {
				e1 = new ArrayList<Integer>(e1b);
				binary = Integer.parseInt((Integer.toBinaryString(j)));
				//System.out.println(binary+":");
				for (int k = 0; k < n; k++) {
					//System.out.print(e1.get(k));
					e1.set(k, toggle(e1.get(k), binary));
					//System.out.println(" > " + e1.get(k));
				}
				Collections.sort(e1);

				if (e1.equals(e2)) { // something
					flag = true;
					min = countOne(binary, length);
				}

			}

			if (flag == false)
				System.out.println("Case #" + i + ": NOT POSSIBLE");
			else
				System.out.println("Case #" + i + ": " + min);

		}
		br.close();
	}

	public static int toggle(int x, int mask) {
		String x2 = String.valueOf(x);
		String mask2 = String.valueOf(mask);
		String toggled = "";

		while (mask2.length() > x2.length())
			x2 = "0" + x2;

		while (mask2.length() < x2.length())
			mask2 = "0" + mask2;

		for (int j = 0; j < x2.length(); j++) {
			if ((x2.charAt(j) == '1') && (mask2.charAt(j) == '0'))
				toggled += "1";
			else if ((x2.charAt(j) == '0') && (mask2.charAt(j) == '1'))
				toggled += "1";
			else
				toggled += "0";
		}

		return Integer.parseInt(toggled);
	}

	public static int countOne(int x, int length) {
		String num = String.valueOf(x);
		int count = 0;
		for (int j = 0; j < num.length(); j++) {
			if (num.charAt(j) == '1')
				count++;
		}
		return count;
	}
}
