import java.util.*;
import java.io.*;

public class Solution {
	public static String flip(String bin, int n) {
		char[] str = bin.toCharArray();
		if (str[n] == '1')
			str[n] = '0';
		else
			str[n] = '1';
		
		return new String(str);
	}
	
	public static String[] permutations(int len) {
		if (len == 1) return new String[]{"0", "1"};
		
		String[] perms = new String[(int)(Math.pow(2, len))];
		String[] p = permutations(len - 1);
		
		for (int i = 0; i < perms.length; i+=p.length)
			for (int e = 0; e < p.length; e++)
				perms[i+e] = ((i + e) < (perms.length / 2) ? "0" : "1") + p[e];
		
		return perms;
	}
	
	public static ArrayList<String> makeList(String[] toclone, String flip_mask) {
		ArrayList<String> c = new ArrayList<String>();
		char[] mask = flip_mask.toCharArray();
		
		for (int i = 0; i < toclone.length; i++) {
			String o = new String(toclone[i]);
			
			for (int n = 0; n < mask.length; n++)
				if (mask[n] == '1')
					o = flip(o, n);
			
			c.add(o);
		}
		
		return c;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("input.in"));
		FileWriter out = new FileWriter("output.out");
		int test_cases = Integer.parseInt(in.nextLine());
		
		for (int test_case = 1; test_case <= test_cases; test_case++) {
			String[] lengths = in.nextLine().split(" ");
			int count = Integer.parseInt(lengths[0]);
			int length = Integer.parseInt(lengths[1]);
			String[] devices = in.nextLine().split(" ");
			String[] outlets = in.nextLine().split(" ");
			
			int min_changed = -1;
			for (String perm : permutations(length)) {
				int changed = perm.replaceAll("0", "").length();
				ArrayList<String> mod_outlets = makeList(outlets, perm);
				
				for (int i = 0; i < devices.length; i++) {
					mod_outlets.remove(devices[i]);
				}
				
				if (mod_outlets.size() == 0 && (min_changed > changed || min_changed < 0)) {
					min_changed = changed;
				}
			}
			
			if (min_changed < 0) {
				out.write("Case #" + test_case + ": NOT POSSIBLE\n");
			} else {
				out.write("Case #" + test_case + ": " + min_changed + "\n");
			}
			
		}
		
		out.close();
		in.close();
	}
}
