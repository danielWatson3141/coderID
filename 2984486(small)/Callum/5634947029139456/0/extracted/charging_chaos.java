import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class charging_chaos {

	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0(1).in"));
		
		PrintWriter pw = new PrintWriter("A-small.out", "UTF-8");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 1; test <= t; test++) {
			pw.print("Case #" + test + ": ");
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int n = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			
			String[] outlets = new String[n];
			String[] devices = new String[n];
			outlets = br.readLine().split(" ");
			devices = br.readLine().split(" ");
			
			Arrays.sort(outlets);
			Arrays.sort(devices);
			
			int min = 1000;
			
			for (int i = 0; i < Math.pow(2, l); i++) {
				String[] temp = flipAll(outlets.clone(), padZeros(Integer.toBinaryString(i), l));
				Arrays.sort(temp);
				if (compare(temp, devices)) {
					int q = num(Integer.toBinaryString(i));
					if (q < min) {
						min = q;
					}
				}
			}
			
			if (min == 1000) {
				pw.println("NOT POSSIBLE");
			} else {
				pw.println(min);
			}
		}
		
		br.close();
		pw.close();
	}
	
	public static String[] flipAll(String[] d, String b) {
		for (int i = 0; i < b.length(); i++) {
			if (b.charAt(i) == '1') {
				for (int j = 0; j < d.length; j++) {
					d[j] = flipBit(d[j], i);
				}
			}
		}
		return d;
	}
	
	public static int num(String s) {
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '1') {
				ans++;
			}
		}
		return ans;
	}
	
	public static String flipBit(String s, int i) {
		if (s.charAt(i) == '0') {
			return s.substring(0, i) + "1" + s.substring(i + 1);
		}
		if (s.charAt(i) == '1') {
			return s.substring(0, i) + "0" + s.substring(i + 1);
		}
		return "";
	}
	
	public static boolean compare(String[] a, String[] b) {
		for (int i = 0; i < a.length; i++) {
			if (!a[i].equals(b[i])) {
				return false;
			}
		}
		return true;
	}
	
	public static String padZeros(String s, int n) {
		while (s.length() < n) {
			s = "0" + s;
		}
		return s;
	}
}