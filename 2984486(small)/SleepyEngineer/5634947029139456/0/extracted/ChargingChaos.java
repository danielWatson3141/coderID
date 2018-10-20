package chargingChaos;

import java.util.*;
import java.io.*;
import java.math.*;

public class ChargingChaos {
	final static String PROBLEM_NAME = "ChargingChaos";
	final static String FILE = "A-small-attempt0";
	final static String PACKAGE_NAME = "2014_Round_1A";
	final static String WORK_DIR = PACKAGE_NAME + "/" + PROBLEM_NAME + "/";
	final static String FILE_IN = WORK_DIR + FILE + ".in";
	final static String FILE_OUT = WORK_DIR + FILE + ".out";
	


	String solve(int[] current, int[] required){
		int res = -1;
		Arrays.sort(required);
		for(int i=0;i<required.length;i++){
			int diff = current[0] ^ required[i];
			System.out.println("current:" + current[0] + "\nreq:" + required[i] + "\ndiff:" + diff);
			for(int j=0;j<required.length;j++){
				//System.out.println("diff ^ cur:" + (diff ^ current[i]) + "\ncurrent[i]:" + current[i]);
				int[] changed = new int[current.length];
				for(int k=0;k<changed.length;k++){
					changed[k] = diff ^ current[k];
				}
				Arrays.sort(changed);
				System.out.println(Arrays.toString(changed));
				System.out.println(Arrays.toString(required));
				if (Arrays.equals(changed,required)){
					int res1 = Integer.bitCount(diff);//how many toggled
					if(res1 < res || res < 0){
						res = res1;
					}
				}
			}
		}
		if (res >= 0){
			return Integer.toString(res);
		}
		else {
			return "NOT POSSIBLE";
		}
	}

	public void doMain() throws Exception {
		Scanner fr = new Scanner(new FileReader(FILE_IN));
		PrintWriter fw = new PrintWriter(new FileWriter(FILE_OUT));
		
		int caseCnt = fr.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			// ENTER CODE HERE
			
			int N = fr.nextInt();
			int L = fr.nextInt();
			
			int[] current = new int[N];
			for(int i=0;i<current.length;i++){
				current[i] = Integer.parseInt(fr.next(),2);
			}
			int[] required = new int[N];
			for(int i=0;i<required.length;i++){
				required[i] = Integer.parseInt(fr.next(),2);
			}
			String res1 = "";
			res1 = solve(current, required);

			// END OF CODE SECTION 
			
			fw.println("Case #" + caseNum + ": " + res1);
			
			System.out.println("Finished " + caseNum + " in " + (System.currentTimeMillis() - time) + "ms.");
		}
		
		fw.flush();
		fw.close();
		fr.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ChargingChaos()).doMain();
	}
}