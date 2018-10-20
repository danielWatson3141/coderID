import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class problemA {
	
	private static int test(int switches, int []outlets, int[] devices, int max) {	
		if (switches >= max) {
			return -1;
		}
		int[] copyOutlet = Arrays.copyOf(outlets, outlets.length);
		int[] copyDevices = Arrays.copyOf(devices, devices.length);
		
		
		int mask = 1 << switches;
		for (int x=0; x<outlets.length; x++) {
			outlets[x] ^= mask;
		}
		
		Arrays.sort(outlets);
		Arrays.sort(devices);
		if (Arrays.equals(outlets, devices)) {
			return 1;
		} else {
			int value = test(switches+1, copyOutlet, copyDevices, max);
			int value1 = test(switches+1, Arrays.copyOf(outlets, outlets.length), Arrays.copyOf(devices, devices.length), max);
			if (value1 == -1) {
				return value;
			} else {
				if (value == -1) {
				return value1 + 1;
				} else {
					return Math.min(value, value1 + 1);
				}
			}
		}
		
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(new File("A-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new FileWriter("outputA.txt")); 
		int testCases = input.nextInt();
		for (int i=1; i<=testCases; i++) {
			int size = input.nextInt();
			int length = input.nextInt();
			
			int[] sockets = new int[size];
			int[] devices = new int[size];
			
			for (int x=0; x<size; x++) {
				sockets[x] = Integer.parseInt(input.next(), 2);
			}
			for (int x=0; x<size; x++) {
				devices[x] = Integer.parseInt(input.next(), 2);
			}
			
			Arrays.sort(sockets);
			Arrays.sort(devices);
			if (Arrays.equals(sockets, devices)) {
				out.print("Case #" + i + ": 0");
			} else {
				int value = test(0, sockets, devices, length);
				if (value!=-1) {
					out.print("Case #" + i + ": "+value);
				} else {
					out.print("Case #" + i + ": NOT POSSIBLE");
				}
			}
			
			
			out.println();
		}
		out.close();
	}

}
