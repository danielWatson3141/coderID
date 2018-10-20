package rounda;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args) {
		try {
			solve();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public static void solve() throws FileNotFoundException {
		String filename = "A-small-attempt0.in";
		Scanner sc = new Scanner(new File(filename));
		
		int numOfTestcase = sc.nextInt();
		for(int i = 1; i <= numOfTestcase; i++) {
			int numOfDevice = sc.nextInt();
			int numOfSwitch = sc.nextInt();
			
			ArrayList<Integer> devices = new ArrayList<Integer>();
			for (int j = 0; j < numOfDevice; j++) {
				String d = sc.next();
				int value = 0;
				for(int a = 0; a < numOfSwitch; a++) {
					value <<= 1;
					if(d.charAt(a) == '1') {
						value |= 1;
					}
				}
				devices.add(value);
				// System.out.println(value);
			}
			ArrayList<Integer> expectations = new ArrayList<Integer>();
			for (int j = 0; j < numOfDevice; j++) {
				String d = sc.next();
				int value = 0;
				for(int a = 0; a < numOfSwitch; a++) {
					value <<= 1;
					if(d.charAt(a) == '1') {
						value |= 1;
					}
				}
				expectations.add(value);
			}
			
			int result = 11;
			for(int n = 0; n < 1024; n++) {
				boolean ok = true;
				for(int d : devices) {
					int dd = d ^ n;
					if(!expectations.contains(dd)) {
						ok = false;
						break;
					}
				}
				if(ok) {
					int b = 0;
					int c = n;
					while(c != 0) {
						b += (c & 1);
						c >>= 1;
					}
					result = Math.min(result, b);
				}
			}
			
			if(result == 11) {
				System.out.printf("Case #%d: NOT POSSIBLE\n", i);				
			}
			else {
				System.out.printf("Case #%d: %d\n", i, result);				
			}
		}
	}
}

/*
3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01
*/