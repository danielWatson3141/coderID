import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class ChargingChaos {

	private static final String NOT_POSSIBLE = "NOT POSSIBLE";
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			int L = in.nextInt();
			in.nextLine();
			String[] outletFlows = in.nextLine().split(" ");
			String[] deviceFlows = in.nextLine().split(" ");
			List<Long> outlets = new LinkedList<Long>();
			List<Long> devices = new LinkedList<Long>();			
			for (int j = 0; j < N; j++) {
				outlets.add(Long.parseLong(outletFlows[j], 2));
				devices.add(Long.parseLong(deviceFlows[j], 2));
			}
			System.out.println("Case #" + (i + 1) + ": " + solve(outlets, devices));
		}
		in.close();
	}

	private static String solve(List<Long> outlets, List<Long> devices) {
		long outlet = outlets.get(0);
		int bestMaskBits = Integer.MAX_VALUE;

		for (Long device : devices) {			
			long mask = outlet ^ device;
			
			int maskBits = getMaskBits(mask);
			
			if (maskBits < bestMaskBits) {
				if (maskSolves(mask, outlets, devices)) {
					bestMaskBits = maskBits;
				}
			}
		}
		
		if (bestMaskBits < Integer.MAX_VALUE) {
			return "" + bestMaskBits;
		}
			
		return NOT_POSSIBLE;
	}

	private static boolean maskSolves(Long mask, List<Long> outlets, List<Long> devices) {
		List<Long> outletsPos = new LinkedList<Long>();
		List<Long> devicesPos = new LinkedList<Long>();
		
		for (int i = 0; i < outlets.size(); i++) {
			outletsPos.add(outlets.get(i) ^ mask);
			devicesPos.add(devices.get(i));
		}
		
		Collections.sort(outletsPos);
		Collections.sort(devicesPos);		
		
		for (int i = 0; i < outletsPos.size(); i++) {
			if (!outletsPos.get(i).equals(devicesPos.get(i))) {
				return false;
			}
		}
		return true;
	}

	private static int getMaskBits(long mask) {
		int result = 0;
		while (mask != 0) {
			result += mask % 2;
			mask /= 2;
		}
		return result;
	}

}
