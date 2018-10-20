import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class A {
	
	public void toDec(int[][] in, int[] out) {
		for (int i = 0; i < in.length; i++) {
			int mult = 1;
			int val = 0;
			for (int j = 0; j < in[0].length; j++) {
				val += mult*in[i][j];
				mult *= 2;
			}
			out[i] = val;
		}
	}
	
	public int[] getMask(int a, int s) {
		int[] array = new int[s];
		for (int i = 0; i < s; i++) {
			array[i] = (a >> i) & 1;
		}
		return array;
	}
	
	public boolean test(int[] a, int[] b, LinkedList<Integer> list, int res, PrintWriter out) {
		int[] c = new int[list.size()];
		for (int i = 0; i < list.size(); i++) {
			c[i] = list.get(i);
		}
		int min = 9999;
		for (int mask = 0; mask < Math.pow(2, list.size()); mask++) {
			int[] array = getMask(mask, list.size());
			for (int i = 0; i < list.size(); i++) {
				for (int j = 0; j < a.length; j++) {
					a[j] ^= (array[i] << c[i]);
				}
			}
			Arrays.sort(a);
			if (Arrays.equals(a, b)) {
				int cur = 0;
				for (int i = 0; i < array.length; i++) {
					if (array[i] == 1) {
						cur++;
					}
				}
				min = Math.min(min, cur);
				//System.out.println(res);
				//out.println(res);
				//return true;
			}
			for (int i = 0; i < list.size(); i++) {
				for (int j = 0; j < a.length; j++) {
					a[j] ^= (array[i] << c[i]);
				}
			}
		}
		if (min < 9999) {
			System.out.println(res+min);
			out.println(res+min);
			return true;
		}
		return false;
	}
	
	public void solve(Scanner scan, PrintWriter out) {
		int result = 0;
		int N = scan.nextInt();
		int L = scan.nextInt();
		String[] strings = new String[N];
		int[][] outlets = new int[N][L];
		int[][] flows = new int[N][L];
		for (int i = 0; i < N; i++) {
			strings[i] = scan.next();
			for (int j = 0; j < L; j++) {
				outlets[i][j] = Character.getNumericValue(strings[i].charAt(j));
			}
		}
		for (int i = 0; i < N; i++) {
			strings[i] = scan.next();
			for (int j = 0; j < L; j++) {
				flows[i][j] = Character.getNumericValue(strings[i].charAt(j));
			}
		}
		LinkedList<Integer> list = new LinkedList<Integer>();
		for (int i = 0; i < L; i++) {
		//	list.add(i);
		}
		for (int i = 0; i < L; i++) {
			int flow = 0;
			int outlet = 0;
			for (int j = 0; j < N; j++) {
				if (flows[j][i] == 1) {
					flow++;
				}
				if (outlets[j][i] == 1) {
					outlet++;
				}
			}
			if (flow == outlet) {
				if (N % 2 == 0 && flow == N/2) {
					list.push(i);
				}
				continue;
			} else if (flow == N-outlet) {
				for (int j = 0; j < N; j++) {
					outlets[j][i] ^= 1;
				}
				result++;
			} else {
				System.out.println("NOT POSSIBLE");
				out.println("NOT POSSIBLE");
				return;
			}
		}
		int[] out_dec = new int[N];
		int[] flow_dec = new int[N];
		toDec(outlets, out_dec);
		toDec(flows, flow_dec);
		Arrays.sort(out_dec);
		Arrays.sort(flow_dec);
		if (Arrays.equals(out_dec, flow_dec)) {
			System.out.println(result);
			out.println(result);
			return;
		}
		
		if (!test(out_dec, flow_dec, list, result, out)) {
			System.out.println("NOT POSSIBLE");
			out.println("NOT POSSIBLE");
		}
	}
	
	public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(new FileReader("inputAs.in"));
        PrintWriter out = new PrintWriter("outputAs.txt");
        int problems = scan.nextInt();
        for (int count = 0; count < problems; count++) {
            System.out.print("Case #" + (count+1) + ": ");
            out.print("Case #" + (count+1) + ": ");
            new A().solve(scan, out);
        }
        out.flush();
        out.close();
        scan.close();
    }
	
}