import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


/**
 * @author Paul LaMotte
 *
 */
public class ProblemA {

	public static void main(String[] args) {
		try {
			System.setOut(new PrintStream(new FileOutputStream("ProblemA.out")));
			Scanner scan = new Scanner(new FileInputStream("ProblemA.in"));
			int cases = new Scanner(scan.nextLine()).nextInt();
			for (int l = 0; l < cases; l++) {
				int n = scan.nextInt();
				int len = scan.nextInt();

				int[][] orig = new int[n][len];

				for (int i = 0; i < n; i++) {
					String val = scan.next();
					for (int j = 0; j < val.length(); j++) {
						orig[i][j] = Integer.parseInt("" + val.charAt(j));
					}
				}

				int[][] arr = new int[n][len];
				for (int i = 0; i < n; i++) {
					String val = scan.next();
					for (int j = 0; j < val.length(); j++) {
						arr[i][j] = Integer.parseInt("" + val.charAt(j));
					}
				}
				
				int flips = -1;
				for (int i = 0; i < (1 << n); i++) {
					int[][] copy = new int[orig.length][orig[0].length];
					for (int j = 0; j < copy.length; j++) {
						copy[j] = Arrays.copyOf(arr[j], arr[0].length);
					}
					int val = solve(orig, copy, i);
					if (val != -1) {
						if (flips == -1) {
							flips = val;
						} else {
							flips = Math.min(flips, val);
						}
					}
				}

				String str = "";
				if (flips == -1) {
					str = "NOT POSSIBLE";
				} else {
					str = flips + "";
				}
				System.out.printf("Case #%d: %s%n", l+1, str);
			}

		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static int solve(int[][] orig, int[][] arr, int perm) {
		int count = 0;
		for (int i = 0; i < arr[0].length; i++) {
			if ( (perm & (1 << i)) > 0) {
			count++;
			}
			for (int j = 0; j < arr.length; j++) {
				if ( (perm & (1 << i)) > 0) {
					arr[j][i] = arr[j][i] == 1 ? 0 : 1;
					
				}
			}
		}
		
		ArrayList<String> origStrings = new ArrayList<String>();
		ArrayList<String> arrStrings = new ArrayList<String>();
		for (int k = 0;  k < arr.length; k++) {
			String origStr = "";
			String arrStr = "";
			for (int m = 0; m < arr[0].length; m++) {
				origStr += orig[k][m];
				arrStr += arr[k][m];
			}
			origStrings.add(origStr);
			arrStrings.add(arrStr);
		}

		for (int i = 0; i < origStrings.size(); i++) {
			if (arrStrings.contains(origStrings.get(i))) {
				arrStrings.remove(origStrings.get(i));
			}
		}
		if (arrStrings.size() == 0) {
			return count;
		} else {
			return -1;
		}
		
	}

}
