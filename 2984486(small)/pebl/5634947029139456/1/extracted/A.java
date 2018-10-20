package codejam.f2013a;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;

public class A {

	private static ArrayList os = new ArrayList();
	private static ArrayList ds = new ArrayList();

	private static int test(int oIndex, int curMin) {
		StringBuilder swithes = new StringBuilder();
		
		int ret = 0;
		String outlet = (String) os.get(oIndex);
		String device = (String) ds.get(0); 
		
		for(int i=0;i<outlet.length(); i++) {
			if (outlet.charAt(i) == device.charAt(i))
				swithes.append('0');
			else {
				swithes.append('1');
				ret++;
			}
		}
		
		if (ret > curMin)
			return curMin;
		
		HashSet newOutlets = new HashSet();
		for(int i=0; i<os.size(); i++) {
			String out = (String) os.get(i);
			StringBuilder oNew = new StringBuilder();
			
			for(int j=0; j<swithes.length(); j++) {
				if (swithes.charAt(j) == '0')
					oNew.append(out.charAt(j));
				else if (out.charAt(j) == '1')
					oNew.append('0');
				else
					oNew.append('1');
			}
		
			newOutlets.add(oNew.toString());
		}
		
		for(int i=0; i<ds.size(); i++) {
			if (!newOutlets.contains(ds.get(i)))
				return curMin;
		}
		
		return ret;
	}
	
	private static void handleCase(int nr, Scanner scanner) {
		int N = scanner.nextInt();
		int L = scanner.nextInt();
		
		ds.clear();
		os.clear();
		
		for(int i=0; i<N; i++) {
			String s = scanner.next();
			os.add(s);			
		}

		for(int i=0; i<N; i++) {
			String s = scanner.next();
			ds.add(s);			
		}

		
		int switches = L+1;
		for(int i=0; i<N; i++) {
			int s = test(i,switches);
			switches = Math.min(switches, s);
		}
		
		if (switches == L+1) {
			System.out.println("Case #"+nr+": "+"NOT POSSIBLE");
			return;
		}

		System.out.println("Case #"+nr+": "+switches);
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
		int cases = scanner.nextInt();
		
		for(int i=0;i<cases; i++)
			handleCase(i+1,scanner);
	}
}
