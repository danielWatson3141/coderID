package first.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class ChargingChaos {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-small-attempt1.in"));
		//Scanner in = new Scanner(new File("charging-chaos.in"));
		
		int tests = in.nextInt();
		for ( int test = 1; test <= tests; ++test ) {
			int number = in.nextInt();
			int length = in.nextInt();
			
			long[] outlets = new long[number];
			long[] devices = new long[number];
			
			for ( int i = 0; i < number; ++i ) {
				outlets[i] = in.nextLong(2);
			}
			
			for ( int i = 0; i < number; ++i ) {
				devices[i] = in.nextLong(2);
			}
			
			Arrays.sort(devices);

			/*
			System.out.printf("Outlets: %s\n", Arrays.toString(outlets));
			System.out.printf("Devices: %s\n", Arrays.toString(devices));
			*/
			
			int minimumFlips = Integer.MAX_VALUE;
			long max = 1 << length;
			for ( long flips = 0; flips <= max; ++flips ) {
				long[] flippedOutlets = flip ( outlets, flips );
				Arrays.sort(flippedOutlets);
				
				if ( Arrays.equals(flippedOutlets, devices) ) {
					minimumFlips = Math.min(minimumFlips, Long.bitCount(flips));
				}
			}
			
			if ( minimumFlips > length ) {
				System.out.printf("Case #%d: NOT POSSIBLE\n", test);
			} else {
				System.out.printf("Case #%d: %d\n", test, minimumFlips);
			}
		}
		
		in.close();
	}
	
	private static long[] flip ( long[] in, long flip ) {
		long[] result = new long[in.length];
		for ( int i = 0; i < in.length; ++i ) {
			result[i] = (in[i] ^ flip);
		}
		return result;
	}
}
