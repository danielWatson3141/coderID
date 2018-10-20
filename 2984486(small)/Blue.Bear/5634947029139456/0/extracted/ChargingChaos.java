import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class ChargingChaos {

	
	static int n;
	static int l;
	static int ans;
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner cin = new Scanner(new File("A-small-attempt0.in"));
		PrintStream cout = new PrintStream("A-small-attempt0.out");
//		Scanner cin = new Scanner(System.in);
//		PrintStream cout = System.out;
		
		int _case = 0;

		
		for (int T=cin.nextInt(); T>0; T--) {
			_case++;
			n = cin.nextInt();
			l = cin.nextInt();
			
			ArrayList<String> a = new ArrayList<String>();
			ArrayList<String> b = new ArrayList<String>();
			
			int ans = 1000;
			
			for (int i=0; i<n; i++) a.add(cin.next());
			for (int i=0; i<n; i++) b.add(cin.next());
			
			for (String s : a)
				for (String t : b) {
					int mark = 0;
					int markCnt = 0;
					for (int i=0; i<l; i++) {
						if (s.charAt(i) != t.charAt(i)) {
							mark += 1 << i;
							markCnt++;
						}
					}
					
					String[] aa = new String[n];
					String[] bb = new String[n];
					for (int i=0; i<n; i++) {
						char []cb = a.get(i).toCharArray();
						for (int j=0; j<l; j++)
							if ((mark & (1 << j)) > 0) cb[j] = cb[j] == '0' ? '1' : '0';
						aa[i] = String.valueOf(cb);
						
						cb = b.get(i).toCharArray();
						bb[i] = String.valueOf(cb);
					}
					
					Arrays.sort(aa);
					Arrays.sort(bb);
					
					boolean isok = true;
					for (int i=0; i<aa.length; i++)
						if (!aa[i].equals(bb[i])) {
							isok = false;
							break;
						}
					
					if (isok) ans = Math.min(ans, markCnt);
				}
			
			if (ans == 1000) cout.printf("Case #%d: NOT POSSIBLE%n", _case);
			else cout.printf("Case #%d: %d%n", _case, ans);
		}
			
		
		cin.close();
		cout.close();
	}
	
}
