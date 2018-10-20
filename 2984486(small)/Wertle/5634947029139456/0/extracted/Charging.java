import java.util.Scanner;


public class Charging {

	public static void main(String[] args) {
		
		Charging me = new Charging();
		me.runAll();

	}
	
	Scanner in = new Scanner(System.in);
	
	public void runAll() {
		
		int nCases = in.nextInt();
		for(int i = 1; i <= nCases; i++) {
			runOne(i);
		}
		
	}
	
	int nPlugs, nVals;
	boolean[][] origOutlets,outlets, devices;
	
	
	public void runOne(int caseNum) {
		
		System.out.print("Case #"+caseNum+": ");
		
		nPlugs = in.nextInt();
		nVals = in.nextInt();
		
		origOutlets = new boolean[nPlugs][nVals];
		outlets = new boolean[nPlugs][nVals];
		devices = new boolean[nPlugs][nVals];
		
		for(int i = 0; i < nPlugs; i++) {
			char[] str = in.next().toCharArray();
			for(int j = 0; j < nVals; j++) {
				origOutlets[i][j] = str[j] == '1';
			}
		}
		for(int i = 0; i < nPlugs; i++) {
			char[] str = in.next().toCharArray();
			for(int j = 0; j < nVals; j++) {
				devices[i][j] = str[j] == '1';
			}
		}
		
		int minFlips = Integer.MAX_VALUE;
		
		// Make the ith switch match the first value, find the best such solution
		for(int iFirst = 0; iFirst < nPlugs; iFirst++) {
			
			for(int i = 0; i < nPlugs; i++) {
				for(int j = 0; j < nVals; j++) {
					outlets[i][j] = origOutlets[i][j];
				}
			}
			
			// Make it match
			int nFlips = 0;
			for(int jVal = 0; jVal < nVals; jVal++){
				if(outlets[iFirst][jVal] != devices[0][jVal]) {
					// Flip the row
					nFlips++;
					for(int iFlip = 0; iFlip < nPlugs; iFlip++) {
						outlets[iFlip][jVal] = !outlets[iFlip][jVal];
					}
				}
			}
			
			
			
			// Check if this assignment works
			boolean goodAssignment  = true;
			boolean[] used = new boolean[nPlugs];
			for(int iDevice = 0; iDevice < nPlugs; iDevice++){
				
				boolean anyPasses = false;
				
				for(int iOutlet = 0; iOutlet < nPlugs; iOutlet++) {
					
					if(!used[iOutlet]) {
						
						boolean passes = true;
						// Check if it passes
						for(int iVal = 0; iVal < nVals; iVal++) {
							if(devices[iDevice][iVal] != outlets[iOutlet][iVal]) {
								passes  = false;
								break;
							}
						}
						
						if(passes) {
							anyPasses = true;
							used[iOutlet] = true;
							break;
						}
					}
					
				}
				
				if(!anyPasses) {
					goodAssignment = false;
				}
			}
			
			if(goodAssignment) {
				minFlips = Math.min(minFlips, nFlips);
			}
		}
		
		if(minFlips < Integer.MAX_VALUE) {
		System.out.println(minFlips);
		} else {
			System.out.println("NOT POSSIBLE");
		}
		
	}

}
