package GCodeJam;

import java.util.*;

public class ChargingChaos {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		String[] input = in.nextLine().split(" ");
		int T = Integer.parseInt(input[0]);
		for(int t=1; t<=T; t++) {
			
			input = in.nextLine().split(" ");
			int n = Integer.parseInt(input[0]);
			
			long outlets[] = new long[n];
			long devices[] = new long[n];
			
			TreeSet<Long> outletSet = new TreeSet<Long>();
			TreeSet<Long> deviceSet = new TreeSet<Long>();
			TreeSet<Long> xorSet = new TreeSet<Long>();
			
			input = in.nextLine().split(" ");
			for (int i = 0; i < n; i++) {
				String a = input[i];
				long decimalValue = Long.parseLong(a, 2);
				outlets[i] = decimalValue;
				outletSet.add((long) decimalValue);
			}
			
			input = in.nextLine().split(" ");
			for (int i = 0; i < n; i++) {
				String a = input[i];
				long decimalValue = Long.parseLong(a, 2);
				devices[i] = decimalValue;
				deviceSet.add((long) decimalValue);
			}
			
			int[] flipArray = new int[n];
			
			boolean thisWorks = true;
			int flips = 0;
			
			long d1 = outletSet.first();
			for (long d2 : deviceSet) {
				xorSet.add(d1 ^ d2);
			}
			
			int i = 0;
			for (long x : xorSet) {
				
				thisWorks = true;
				
				for (long d2 : deviceSet) {
					thisWorks &= (outletSet.contains(d2 ^ x));
				}
				if (thisWorks) {
					flipArray[i] = countSetBits(x);
					break;
				}
				i++;
			}
			Arrays.sort(flipArray);
			for (int j = 0; j < n; j++) {
				flips = flipArray[j];
				if (flips != 0) {
					break;
				}
			}
			
			System.out.println("Case #" + t + ": " + (thisWorks ? String.valueOf(flips) : "NOT POSSIBLE"));
			
		}
	}
	
	static int countSetBits(long n)
	{
		int count = 0;
		while(n != 0) {
		   if(n % 2 != 0)
		     ++count;
		   n /= 2;
		}
		return count;
	}

}
