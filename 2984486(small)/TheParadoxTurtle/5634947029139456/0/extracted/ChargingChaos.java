import java.util.*;
import java.io.*;

public class ChargingChaos {
	public static char[] getDiff(String outlet, String device) {
		char[] out = new char[outlet.length()];
		for(int i = 0; i < out.length; i++) {
			if(outlet.charAt(i) == device.charAt(i))
				out[i] = '0';
			else
				out[i] = '1';
		}
		return out;
	}
	
	public static String[] flipSwitches(String[] outlets, char[] diff) {
		String[] result = new String[outlets.length];
		for(int i = 0; i < outlets.length; i++) {
			char[] temp = new char[outlets[i].length()];
			for(int j = 0; j < outlets[i].length(); j++) {
				if(diff[j] == '1') {
					if(outlets[i].charAt(j) == '1')
						temp[j] = '0';
					else
						temp[j] = '1';
				}
				else
					temp[j] = outlets[i].charAt(j);
			}
			result[i] = new String(temp);
		}
		return result;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(new File("A-small-attempt0.in"));
		//Scanner scan = new Scanner(System.in);
		int T = Integer.parseInt(scan.next());
		for(int t = 1; t <= T; t++) {
			int N = Integer.parseInt(scan.next());
			int L = Integer.parseInt(scan.next());
			String[] outlets = new String[N];
			String[] devices = new String[N];
			for(int i = 0; i < N; i++) 
				outlets[i] = scan.next();
			for(int i = 0; i < N; i++) 
				devices[i] = scan.next();
			Arrays.sort(devices);
			//Try to match each outlet with each device
			boolean possible = false;
			int min = L+1;
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++) {
					char[] diff = getDiff(outlets[i], devices[j]);
					String[] flipped = flipSwitches(outlets, diff);
					Arrays.sort(flipped);
					boolean works = true;
					for(int k = 0; k < N; k++)
						if(!devices[k].equals(flipped[k])) {
							works = false;
							break;
						}
					if(works) {
						int count = 0;
						for(int k = 0; k < L; k++)
							if(diff[k] == '1')
								count++;
						if(min > count)
							min = count;
						possible = true;
					}
				}
			if(possible)
				System.out.println("Case #" + t + ": " + min);
			else
				System.out.println("Case #" + t + ": NOT POSSIBLE");
		}
	}
	
}