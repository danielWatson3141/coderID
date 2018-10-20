import java.util.*;
public class A {
	public static void main(String[]args) {
		Scanner in = new Scanner(System.in);
		int inputs = in.nextInt();
		for(int caseNum = 1; caseNum <= inputs; caseNum++){ 
			int numDevices = in.nextInt();
			int length = in.nextInt();
			String[] devices = new String[numDevices];
			String[] outlets = new String[numDevices];
			for(int i = 0 ; i< numDevices; i++) {
				outlets[i] = in.next();
			}
			for(int i = 0 ; i < numDevices; i++) {
				devices[i] = in.next();
			}
			
			Arrays.sort(outlets);
			int best = length + 1;
			for(int i = 0 ; i < numDevices;i++){
				String bitmask = "";
				int count = 0;
				for(int j = 0 ; j < length; j++) {
					if(devices[0].charAt(j) == outlets[i].charAt(j)) {
						bitmask += '0';
					} else {
						bitmask += '1';
						count++;
					}
				}
				//System.out.println(bitmask);
				boolean[] used = new boolean[numDevices];
				used[i] = true;
				boolean works = true;
				J: for(int j = 1; j < numDevices; j++) {
					works = false;
					K: for(int k = 0; k < numDevices; k++) {
						if(!used[k]) {
							boolean match = true;
							L: for(int l = 0; l < length; l++) {
								int test = 1;
								if(devices[j].charAt(l) == outlets[k].charAt(l)) {
									test = 0;
								}
								if(test != bitmask.charAt(l) - '0') {
									match = false;
									break L;
								}
							}
							if(match) {
								//System.out.println(devices[j] + " " + outlets[k] + " " + bitmask);
								used[k] = true;
								works = true;
								break K;
							}
						}
					}
					if(!works) break;
				}
				if(works) {
					best = Math.min(count, best);
				}
			}
			
			if(best > length) {
				System.out.printf("Case #%d: NOT POSSIBLE\n",caseNum);
			} else {
				System.out.printf("Case #%d: %d\n",caseNum, best);
			}
		}
	}
}
