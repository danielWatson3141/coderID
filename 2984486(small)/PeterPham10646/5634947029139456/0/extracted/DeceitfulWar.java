package Round1Task1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
 
public class DeceitfulWar {
	
	
	public static boolean isMatch(boolean[][] devices, boolean[][] outlets){
		
		int countDevices[] = new int[(int)Math.pow(2,devices[0].length)];
		int countOutlets[] = new int[(int)Math.pow(2,devices[0].length)];
		
		for(int j = 0; j < devices.length; j++){
			int tmp = 0;
			for(int k = 0; k < devices[0].length; k++){
				if(devices[j][k]){
					//tmp += (int)Math.pow(2,devices[0].length - k - 1);
					int one = 1;
					one = one << (devices[0].length - k - 1);
					tmp = tmp | one; 
				}
			}
			countDevices[tmp]++;
		}
		
		for(int j = 0; j < devices.length; j++){
			int tmp = 0;
			for(int k = 0; k < devices[0].length; k++){
				if(outlets[j][k]){
					int one = 1;
					one = one << (devices[0].length - k - 1);
					tmp = tmp | one; 
				}
			}
			countOutlets[tmp]++;
		}
		
		
		for(int j = 0; j < countDevices.length; j++){
			//System.out.println(countOutlets[j] + " and " + countDevices[j]);
			if(countOutlets[j] != countDevices[j]){
				
				return false;
			}
		}
		
		return true;
	}
	
	public static int minimumSwitch(boolean[][] devices, boolean[][] outlets, int nSwitches, int index){
		
		
		
		if(index >= devices[0].length ){
			
			if(isMatch(devices,outlets)){
				return nSwitches;
			}else{
				return -1;
			}
			
			
		}else{
			
			
			// Count boolean
			int nDevices = 0, nOutlets = 0;
			int withflip = -1, withoutflip = -1;
			for(int i = 0; i < devices.length; i++){
				if(devices[i][index]){
					nDevices++;
				}
				
				if(outlets[i][index]){
					nOutlets++;
				}
			}
			
			// Without flip check if condition met
			if(nDevices == nOutlets){
				withoutflip = minimumSwitch(devices,outlets, nSwitches, index + 1);
			}
			
			if(nDevices == devices.length - nOutlets){
				//flip
				for(int i = 0; i < devices.length; i++){
					outlets[i][index] = !outlets[i][index]; 					
				}
				
				
				withflip = minimumSwitch(devices,outlets, nSwitches + 1, index + 1);
				
				//flip back
				for(int i = 0; i < devices.length; i++){
					outlets[i][index] = !outlets[i][index]; 					
				}
			}
			
			if(!(nDevices == nOutlets) && !(nDevices == devices.length - nOutlets)){
				return -1;
			}
			
			if(withflip != -1 && withoutflip != -1){
				return Math.min(withflip, withoutflip);
			}else if(withflip != -1){
				return withflip;
			}else if(withoutflip != -1){
				return withoutflip;
			}else{
				return -1;
			}
			
		}
		
	}
 
	public static void main(String[] args) {
		
		String dir = "/Users/tnpha6/Documents/workspace/CodeJam Preparation/files/Outlets/";
		
		int numTestCase;
		int N;
		int L;
		
		boolean outlets[][], devices[][];
		
		String result = "";
		String[] splited = null;
		BufferedReader br = null;
		PrintWriter writer = null;
		try {
 
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader(dir + "A-small-attempt1.in"));
			writer = new PrintWriter(dir + "output", "UTF-8");
			
			// Getting the number of test case
			numTestCase = Integer.parseInt(br.readLine());
			
			
			// Loop through every test cases
			for(int i = 0; i < numTestCase; i++){
				
				splited = br.readLine().split(" ");
				N = Integer.parseInt(splited[0]);
				L = Integer.parseInt(splited[1]);
				
				// fill outlets and devices
				outlets = new boolean[N][L];
				devices = new boolean[N][L];
				char[] tmp;
				
				//read outlets
				splited = br.readLine().split(" ");
				for(int j = 0; j < N; j++){
					tmp = splited[j].toCharArray();
					
					for(int k = 0; k < L; k++){
						if(tmp[k] == '0'){
							outlets[j][k] = false;
						}else{
							outlets[j][k] = true;
						}
						
					}
				}
				
				//read devices
				splited = br.readLine().split(" ");
				for(int j = 0; j < N; j++){
					tmp = splited[j].toCharArray();
					
					for(int k = 0; k < L; k++){
						if(tmp[k] == '0'){
							devices[j][k] = false;
						}else{
							devices[j][k] = true;
						}
					}
				}
				
				int result1  = minimumSwitch(devices,outlets, 0, 0);
				// Print out test case number
				if(result1 < 0){
					writer.println("Case #" + (i+1) + ": NOT POSSIBLE" );
					System.out.println("Case #" + (i+1) + ": NOT POSSIBLE");
				}else{
					writer.println("Case #" + (i+1) + ": "+ result1 );
					System.out.println("Case #" + (i+1) + ": " + result1);
				}
			}
			
			writer.close();
 
		
		
		
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
 
	}
}


