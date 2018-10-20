package a_2014;

import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.StringTokenizer;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for(int cas = 1; cas<=T; cas++) {
			int N = in.nextInt();
			int L = in.nextInt();
			in.nextLine();
			StringTokenizer str = new StringTokenizer(in.nextLine());
			String[] outlets = new String[N];
			for(int i = 0; i<N; i++) {
				outlets[i] = str.nextToken();
			}
			str = new StringTokenizer(in.nextLine());
			String[] devices = new String[N];
			for(int i = 0; i<N; i++) {
				devices[i] = str.nextToken();
			}
			HashSet<String> switches = new HashSet<String>();
			
			for(int i = 0; i<N; i++) {
				for(int j = 0; j<N; j++) {
					switches.add(diff(outlets[i], devices[j]));
				}
			}
			
			int best = Integer.MAX_VALUE;
			for(String pos : switches) {
				HashSet<String> dev = new HashSet<String>();
				for(int i=0; i<N; i++) {
					dev.add(apply(devices[i], pos));
				}
				boolean works = true;
				for(int i = 0; i<outlets.length; i++) {
					if(!dev.contains(outlets[i])) {
						works = false;
						break;
					}
				}
				if(works) {
					int count = 0;
					for(int i = 0; i<pos.length(); i++) {
						if(pos.charAt(i) == '1')
							count++;
					}
					if(count<best) {
						best = count;
					}
				}
				
			}
			
			if(best == Integer.MAX_VALUE) {
				System.out.println("Case #"+cas+": NOT POSSIBLE");
			} else {
				System.out.println("Case #"+cas+": "+best);
			}
		}
	}
	
	public static String apply(String a1, String switches) {
		String ans = "";
		
		for(int i = 0; i<a1.length(); i++) {
			if(switches.charAt(i) == '0')
				ans += a1.charAt(i);
			else
				if(a1.charAt(i) == '0')
					ans+= "1";
				else
					ans+= "0";
		}
		return ans;
	}
	
	public static String diff(String a1, String a2) {
		String ans = "";
		
		for(int i = 0; i<a1.length(); i++) {
			if(a1.charAt(i) == a2.charAt(i))
				ans += "0";
			else
				ans += "1";
		}
		return ans;
	}
}
class byOnes implements Comparator<String> {

	@Override
	public int compare(String arg0, String arg1) {
		int c1 = 0; int c2 = 0;
		
		for(int i = 0; i<arg0.length(); i++) {
			if(arg0.charAt(i) == '1')
				c1++;
			if(arg1.charAt(i) == '1')
				c2++;
		}
		if(c1>c2)
			return 1;
		if(c2>c1)
			return -1;
		
		return arg0.compareTo(arg1);
	}
	
}
