import java.util.*;
public class ASmall {
	static int numCircuits;
	static int circuitLength;
	static int[] circuits;
	static int[] devices;
	static int[][] memo;
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int numCases = s.nextInt();
		for(int z = 1; z <= numCases; z++){
			numCircuits = s.nextInt();
			circuitLength = s.nextInt();
			circuits = new int[numCircuits];
			devices = new int[numCircuits];
			memo = new int[circuitLength + 1][1 << circuitLength];
			for(int a = 0; a < numCircuits; a++){
				circuits[a] = s.nextInt(2);
			}
			for(int a = 0; a < numCircuits; a++){
				devices[a] = s.nextInt(2);
			}
			
			for(int[] arr : memo) Arrays.fill(arr, -1);
			int res = run(0, 0);
			if(res >= 987654321){
				System.out.println("Case #" + z + ": NOT POSSIBLE");
			} else {
				System.out.println("Case #" + z + ": " + res);
			}
		}
	}
	
	public static int run(int mask, int pos){
		if (memo[pos][mask] != -1)
			return memo[pos][mask];
		if (works(mask)) {
			return memo[pos][mask] = 0;
		}
		if (pos >= circuitLength)
			return memo[pos][mask] = 987654321;
		return memo[pos][mask] = Math.min(run(mask, pos + 1), run(set(mask, pos), pos + 1) + 1);
	}
	
	private static boolean works(int mask) {
		boolean[] validCircuits = new boolean[1 << circuitLength];
		for(int a = 0; a < numCircuits; a++){
			int circuit = circuits[a];
			for(int b = 0; b < circuitLength; b++){
				if(isSet(mask, b))
					circuit = toggle(circuit, b);
			}
			validCircuits[circuit] = true;
		}
		for(int a = 0; a < numCircuits; a++){
			if(!validCircuits[devices[a]]){
				return false;
			}
		}
		return true;
	}

	public static boolean isSet(int mask, int pos) {
		return (mask & (1 << pos)) > 0;
	}

	public static int set(int mask, int pos) {
		return mask | (1 << pos);
	}

	public static int unset(int mask, int pos) {
		return mask & (~(1 << pos));
	}
	public static int toggle(int mask, int pos){
		return mask ^ (1 << pos);
	}
}
