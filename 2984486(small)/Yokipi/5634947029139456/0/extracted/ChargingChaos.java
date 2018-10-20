package roundonea2014;

import java.io.*;
import java.util.*;
import java.math.*;

/*
class Answer {
	public HashSet<Long> ans;
	
	public Answer(long n) {
		ans = new HashSet<Long>();
		ans.add(n);
	}
	
	public Answer() {
		ans = new HashSet<Long>();
	}
	
	public String toString() {
		String s = "{";
		boolean found = false;
		for (Long l : ans) {
			s += l + ",";
			found = true;
		}
		if (found) s = s.substring(0, s.length()-1);
		s += "}";
		return s;
	}
}
*/

public class ChargingChaos {
	static String[] outlets;
	static String[] devices;
	
	static int getInt(StringTokenizer st) {
		return Integer.parseInt(st.nextToken());
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader in = new BufferedReader(new FileReader(new File("src/roundonea2014/"
				+ fin.readLine())));
		FileWriter out = new FileWriter(new File("src/roundonea2014/ChargingChaos.out"));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			/*
			TreeSet<String> outlets = new TreeSet<String>();
			TreeSet<String> devices = new TreeSet<String>();
			
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = getInt(st);
			int L = getInt(st);
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < N; i++) {
				outlets.add(st.nextToken());
			}
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < N; i++) {
				devices.add(st.nextToken());
			}
			
			int switches = 999;
			HashSet<Long> all = help(devices, outlets);
			for (Long l : all) {
				switches = Math.min(switches, Long.bitCount(l));
			}
			*/
			
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = getInt(st);
			int L = getInt(st);
			
			/*
			outlets = new String[N];
			devices = new String[N];
			
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < N; i++) {
				outlets[i] = st.nextToken();
			}
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < N; i++) {
				devices[i] = st.nextToken();
			}
			
			//Arrays.sort(outlets);
			//Arrays.sort(devices);
			*/
			
			HashSet<Long> outlets = new HashSet<Long>();
			HashSet<Long> devices = new HashSet<Long>();
			
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < N; i++) {
				outlets.add(Long.parseLong(st.nextToken(), 2));
			}
			st = new StringTokenizer(in.readLine());
			Long foo = 0L;
			for (int i = 0; i < N; i++) {
				foo = Long.parseLong(st.nextToken(), 2);
				devices.add(foo);
			}
			
			HashSet<Long> cand = new HashSet<Long>();
			for (Long b : outlets) {
				cand.add(diff(foo, b, L));
			}
			
			HashSet<Long> ans = new HashSet<Long>();
			for (Long l : cand) {
				if (equiv(outlets, devices, l)) ans.add(l);
			}
			
			int switches = 999;
			for (Long l : ans) {
				switches = Math.min(switches, Long.bitCount(l));
			}
			

			out.write(String.format("Case #%d: ", t));
			out.write(switches == 999 ? "NOT POSSIBLE" : switches + "");
			out.write("\n");
		}

		fin.close();
		in.close();
		out.close();
	}
	
	
	/*
	static HashSet<Long> help(TreeSet<String> devices, TreeSet<String> outlets) {
		if (devices.size() != outlets.size()) {
			return new HashSet<Long>();
		}
		if (devices.size() == 1) {
			HashSet<Long> ans = new HashSet<Long>();
			ans.add(count(devices.first(), outlets.first()));
			return ans;
		}
		if (devices.size() == 0 || devices.first().length() == 0) {
			HashSet<Long> ans = new HashSet<Long>();
			ans.add(0L);
			return ans;
		}
		int zeroes = 0;
		int ones = 0;
		for (String s1 : devices) {
			if (s1.charAt(0) == '0') zeroes++;
			else ones++;
		}
		for (String s2 : outlets) {
			if (s2.charAt(0) == '0') {
				zeroes--;
				ones--;
			}
		}
		
		HashSet<Long> all = new HashSet<Long>();
		if (zeroes == 0) {
			TreeSet<String> newdevices = new TreeSet<String>();
			TreeSet<String> newoutlets = new TreeSet<String>();
			TreeSet<String> newdevices2 = new TreeSet<String>();
			TreeSet<String> newoutlets2 = new TreeSet<String>();
			for (String s1 : devices) {
				if (s1.charAt(0) == '0') newdevices.add(s1.substring(1));
				else newdevices2.add(s1.substring(1));
			}
			for (String s1 : outlets) {
				if (s1.charAt(0) == '0') newoutlets.add(s1.substring(1));
				else newdevices2.add(s1.substring(1));
			}
			HashSet<Long> ans = help(newdevices, newoutlets);
			HashSet<Long> ans2 = help(newdevices2, newoutlets2);
			for (Long l : ans) {
				if (ans2.contains(l)) all.add(l << 1);
			}
		}
		if (ones == 0) {
			TreeSet<String> newdevices = new TreeSet<String>();
			TreeSet<String> newoutlets = new TreeSet<String>();
			TreeSet<String> newdevices2 = new TreeSet<String>();
			TreeSet<String> newoutlets2 = new TreeSet<String>();
			for (String s1 : devices) {
				if (s1.charAt(0) == '0') newdevices.add(s1.substring(1));
				else newdevices2.add(s1.substring(1));
			}
			for (String s1 : outlets) {
				if (s1.charAt(0) == '1') newoutlets.add(s1.substring(1));
				else newdevices2.add(s1.substring(1));
			}
			HashSet<Long> ans = help(newdevices, newoutlets);
			HashSet<Long> ans2 = help(newdevices2, newoutlets2);
			for (Long l : ans) {
				if (ans2.contains(l)) all.add((l << 1) + 1);
			}
		}
		return all;
	}
	
	static long count(String s1, String s2) {
		long count = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (s1.charAt(i) != s2.charAt(i)) count += 1 << i;
		}
		return count;
	}
	*/
	
	static long diff(Long a, Long b, int L) {
		long diff = 0;
		String s1 = Long.toBinaryString(a);
		String s2 = Long.toBinaryString(b);
		while (s1.length() < L) {
			s1 = "0" + s1;
		}
		while (s2.length() < L) {
			s2 = "0" + s2;
		}
		for (int i = 0; i < L; i++) {
			if (s1.charAt(i) != s2.charAt(i)) diff += 1L << (L-1-i);
		}
		return diff;
	}
	
	static boolean equiv(HashSet<Long> d, HashSet<Long> o, Long x) {
		for (Long a : d) {
			if (!o.contains(a ^ x)) {
				return false;
			}
		}
		return true;
	}
}
