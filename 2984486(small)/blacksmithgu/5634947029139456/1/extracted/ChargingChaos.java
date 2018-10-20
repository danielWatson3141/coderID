import java.io.*;
import java.util.*;
import java.lang.*;

public class ChargingChaos {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new File("ChargingChaos.in"));
		System.setOut(new PrintStream(new File("ChargingChaos.out")));
		
		int sets = input.nextInt();
		for(int s = 0; s < sets; s++) {
			int num = input.nextInt(), len = input.nextInt(); input.nextLine();
			String[] current = new String[num];
			String[] needed = new String[num];
			
			for(int a = 0; a < num; a++)
				current[a] = input.next();
			input.nextLine();
			for(int a = 0; a < num; a++)
				needed[a] = input.next();
			
			Arrays.sort(needed);
			
			int res = trySolve(current, needed);
			
			System.out.print("Case #" + (s + 1) + ": ");
			System.out.println(res == -1 ? "NOT POSSIBLE" : res);
		}

		input.close();
		System.out.close();
	}
	
	public static int trySolve(String[] curr, String[] needed) {
		int best = -1;
		for(String shift : curr) {
			boolean[] diff = diff(shift, needed[0]);
			int count = 0;
			for(boolean b : diff) if(b) count++;
			
			String[] res = change(curr, diff(shift, needed[0]));
			if(Arrays.equals(res, needed))
				best = (best == -1 ? count : Math.min(best, count));
		}
		
		return best;
	}
	
	public static boolean[] diff(String base, String other) {
		boolean[] res = new boolean[base.length()];
		for(int x = 0; x < base.length(); x++)
			if(base.charAt(x) != other.charAt(x)) res[x] = true;
		return res;
	}
	
	public static String[] change(String[] curr, boolean[] diff) {
		String[] res = new String[curr.length];
		int index = 0;
		for(String s : curr) {
			StringBuilder newStr = new StringBuilder();
			for(int x = 0; x < s.length(); x++) {
				newStr.append(diff[x] ? flop(s.charAt(x)) : s.charAt(x));
			}
			res[index++] = newStr.toString();
		}
		
		Arrays.sort(res);
		return res;
	}
	
	public static char flop(char current) {
		return current == '0' ? '1' : '0';
	}
}