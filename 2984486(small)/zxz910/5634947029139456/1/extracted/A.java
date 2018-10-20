import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;
public class A {
	public static void main(String[] args) {
		
		//read in input
		Scanner scanner = new Scanner(new BufferedInputStream(System.in));
		int n = scanner.nextInt();
		
		for (int i = 0; i < n; i++) {
			System.out.print("Case #" + (i+1) + ": ");
			int N = scanner.nextInt();
			int L = scanner.nextInt();
			
			String [] correct = new String[N];
			String [] o = new String[N];
			String [] d = new String[N];
			
			int[] outlets = new int[L];
			int[] devices = new int[L];
			
			for (int j = 0; j < N; j++) {
				//for (int j = 0; j < L; j++) {
				o[j] = scanner.next();	
				//}
			}
			for (int j = 0; j < N; j++) {
				//for (int j = 0; j < L; j++) {
				d[j] = scanner.next();
				//}
			}
			
			for ( int j = 0; j < N; j++) {
				correct[j] = o[j];
				for (int k = 0; k < L; k++)  {
					if (o[j].charAt(k) == '0') {
						outlets[k]++;
					}
					if (d[j].charAt(k) == '0') {
						devices[k]++;
					}
				}
			}
			//System.out.println(Arrays.toString(outlets));
			//System.out.println(Arrays.toString(devices));
			
			int count = 0;
			boolean possible = true;
			int[] unknown = new int[L];
			for (int j = 0; j < L; j++) {
				
				if (outlets[j] == devices[j] && outlets[j] == N/2 && N%2 == 0) {
					unknown[j] = 1;
				}
				else if (outlets[j] != devices[j]) {
					if (outlets[j] == N - devices[j]) {
						count++;
						o = flip(o, j);
					}
					else {
						possible = false;
					}
				}
			}
			if (possible) {
				Arrays.sort(o);
				for (int j = 0; j < N; j++) {
					correct[j] = o[j];
				}
				Arrays.sort(d);
				if (Arrays.equals(o, d)) {
					System.out.println(count);
				}
				else {
					int min = N+1;
					for (int j = 0; j < N; j++) {
						boolean skip = false;
						int tmpCount = 0;
						for (int k = 0; k < L; k++) {
							if (unknown[k] == 0) {
								if (o[j].charAt(k) != d[0].charAt(k)) {
									skip = true;
								}
								
							}
							else {
								if (o[j].charAt(k) != d[0].charAt(k)) {
									flip(o, k);
									tmpCount++;
								}
							}
						}
						Arrays.sort(o);
						if (!skip && Arrays.equals(o, d) && tmpCount < min) {
							min = tmpCount;
						}
						for (int k = 0; k < N; k++) {
							o[k] = correct[k];
						}
					}
					if (min == N+1) {
						System.out.println("NOT POSSIBLE");
					}
					else {
						System.out.println((count + min));
					}
					
				}
			}
			else {
				System.out.println("NOT POSSIBLE");
			}
			
			
		}
	}
	
	public static String[] flip(String[] outlets, int bit) {
		for(int i = 0; i < outlets.length; i++) {
			if (outlets[i].charAt(bit) == '1') {
				outlets[i] = outlets[i].substring(0, bit) + '0' + outlets[i].substring(bit+1, outlets[i].length());
			}
			else {
				outlets[i] = outlets[i].substring(0, bit) + '1' + outlets[i].substring(bit+1, outlets[i].length());
			}
		}

		return outlets;
	} 
	
	public static boolean check(String[] outlets, String[] devices) {
		for (int i = 0; i < outlets.length; i++) {
			if (!outlets[i].equals(devices[i])) {
				return false;
			}
		}
		return true;
	}
}

