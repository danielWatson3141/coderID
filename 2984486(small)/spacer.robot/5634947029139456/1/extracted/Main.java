import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	private static ArrayList<Input> inputs = new ArrayList<Input>();
	private static ArrayList<String> output = new ArrayList<String>();
	
	public static void main(String[] args) {
		try {
			readInput();
			process();
			printOutput();
			//test();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private static void process() {
		for (int i = 0; i < inputs.size(); i++) {
			Input input = inputs.get(i);			
			Long[] s = input.s;
			Long[] t = input.t;
			
			int minValue = Integer.MAX_VALUE;
			for (int j = 0; j < t.length; j++) {
				for (int k = 0; k < s.length; k++) {
					Long diff = t[j]^s[k];
					Integer len = diffLength(diff);
					if (len >= minValue) {
						continue;
					}
						
					if (isPossible(s, t, diff)) {
						minValue = len;
					}					
				}
				if ((j== 0 && minValue == Integer.MAX_VALUE) || minValue == 0) {
					break;
				}
			}
			
			if (minValue == Integer.MAX_VALUE) {
				output.add("Case #" + (i+1) + ": NOT POSSIBLE");
			}
			else {
				output.add("Case #" + (i+1) + ": " + minValue);
			}
		}
	}
	
	private static boolean isPossible(Long[] s , Long[] t, Long diff) {
		Set<Long> sSet = new HashSet<Long>();
		
		for (int i = 0; i < s.length; i++) {
			sSet.add(s[i]^diff);
		}
		for (int i = 0; i < t.length; i++) {
			if (!sSet.contains(t[i])) {
				return false;
			}
		}		
		
		return true;
	}
	
	private static Integer diffLength(Long diff) {
		int n = 0;
		while (diff > 0) {
			if ((diff & 1) == 1) {
				n++;
			}
			diff >>= 1;
		}
		return n;
	}
	
	private static void test() {
		
	}
	
	private static void printOutput() throws FileNotFoundException {
		PrintWriter writer = new PrintWriter("Output.out");
		for (String s : output) {
			writer.println(s);
		}
		
		writer.close();
	}
	
	private static void readInput() throws FileNotFoundException {
		Scanner scanner = new Scanner(new File("Input.in"));
		int testCount = Integer.parseInt(scanner.nextLine());
		for (int i = 0; i < testCount; i++) {
			scanner.nextLine();
			String s = scanner.nextLine();
			String[] a = s.split(" ");
			Long[] source = new Long[a.length];
			for (int j = 0; j < a.length; j++) {
				source[j] = binaryToLong(a[j]);
			}
			
			s = scanner.nextLine();
			a = s.split(" ");
			Long[] target = new Long[a.length];
			for (int j = 0; j < a.length; j++) {
				target[j] = binaryToLong(a[j]);
			}
			
			Input input = new Input(source, target);			
			inputs.add(input);
		}		
		
		scanner.close();
	}
	
	private static Long binaryToLong(String s) {
		Long result = 0L;
		int k = 0;
		for (int i = s.length() - 1 ; i >= 0; i--) {
			if (s.charAt(i) == '1') {
				result += (1 << k);
			}
			k++;
		}
		return result;
	}
	
	private static class Input {
		public Long[] s;
		public Long[] t;
			
		public Input(Long[] s, Long[] t) {
			this.s = s;
			this.t = t;			
		}
	}
}


