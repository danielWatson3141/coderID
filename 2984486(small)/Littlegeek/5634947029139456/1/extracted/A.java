package round1A;
import java.util.*;
import java.io.*;
import java.lang.*;
import java.awt.geom.*;
public class A {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File(args[0]));
		FileWriter w = new FileWriter(args[0].substring(0, args[0].length() - 3) + ".out");
		int T = in.nextInt();
		
		for (int c = 1; c <= T; c++) {
			int N = in.nextInt();
			int L = in.nextInt();
			long[] outs = new long[N], devs = new long[N];
			for (int i = 0; i < N; i++) outs[i] = Long.parseLong(in.next(),2);
			for (int i = 0; i < N; i++) devs[i] = Long.parseLong(in.next(),2);
			long[] swit = new long[L];
			for (int i = 0; i < L; i++) swit[i] = (long) Math.pow(2,i);
			long masks[] = new long[N];
			for (int i = 0; i < N; i++) {
				masks[i] = devs[i] ^ outs[0];
			}
			int lens[] = new int[N];
			for (int i = 0; i < N; i++) {
				for (int p = 0; p < L; p++) {
					long power = (long) Math.pow(2,p);
					if ((masks[i] & power) > 0) lens[i]++;
					if (power * 2 > masks[i]) p = L;
				}
			}
			Arrays.sort(devs);
			int theMask = -1;
			for (int m = 0; m < N; m++) {
					if (theMask < 0 || lens[m] < theMask) {
					long[] masked = new long[N];
					for (int i = 0; i < N; i++) {
						masked[i] = outs[i] ^ masks[m];
					}
					Arrays.sort(masked);
					boolean yes = true;
					for (int i = 0; i < N; i++) {
						if (masked[i] != devs[i]) {
							yes = false;
							break;
						}
					}
					if (yes) theMask = lens[m];
				}
			}
			if (theMask < 0) w.write("Case #" + c + ": NOT POSSIBLE\n");
			else w.write("Case #" + c + ": " + theMask + "\n");
			
		}
		
		in.close();
		w.close();
	}

}
