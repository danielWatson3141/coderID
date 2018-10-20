package _2014.Round1A.A;

import Utils.InputFile;
import Utils.OutputFile;

public class A {

private static void solve(InputFile inputFile, OutputFile outputFile){
		
		int nbCases = Integer.parseInt(inputFile.getNextLine());
		
		for(int caseNumber = 0; caseNumber < nbCases; caseNumber++){
			System.out.println("case : " + caseNumber);
			
			String firstLine = inputFile.getNextLine();
			String secondLine = inputFile.getNextLine();
			String thirdLine = inputFile.getNextLine();
			
			int numberDevices = Integer.parseInt(firstLine.split(" ")[0]);
			int sizeDevices = Integer.parseInt(firstLine.split(" ")[1]);
			
			String[] outlets =  secondLine.split(" ");
			String[] devices =  thirdLine.split(" ");
			
			int res = switchOutlet(outlets, devices, 1);
			if(res >=0){
				outputFile.writeResult("" + res);
				System.out.println(res);
			} else{
				outputFile.writeResult("NOT POSSIBLE");
				System.out.println("NOT POSSIBLE");
			}
			
			
			
			
		}
	}

private static int switchOutlet(String[] outlets, String[] devices, int currentSwitch){
	//no switch
	int withoutSwitch = 0;
	int withSwitch = 0;
	if(isOK(devices.clone(), outlets.clone(), currentSwitch)){
		if(currentSwitch == outlets[0].length()){
			withoutSwitch=0;
		} else{
			withoutSwitch =  switchOutlet(outlets.clone(), devices.clone(), currentSwitch + 1);
		}
		
	} else{
		withoutSwitch = -999999999;
	}
	
	//switch

	String[] devicesSwitched =  devices.clone();
	String[] outletsSwitched =  outlets.clone();
	for(int i =0; i < outletsSwitched.length;i++){
		char c = outletsSwitched[i].charAt(currentSwitch-1);
		char newChar = '0';
		if(c == '0'){
			newChar = '1';
		}
		String outletSwitched = "";
		for(int j = 0; j < outletsSwitched[i].length(); j++){
			if(j == currentSwitch-1){
				outletSwitched+=newChar;
			} else{
				outletSwitched+=outletsSwitched[i].charAt(j);
			}
		}
		outletsSwitched[i]= outletSwitched;
	}
	if(isOK(devicesSwitched.clone(), outletsSwitched.clone(), currentSwitch)){
		if(currentSwitch == outletsSwitched[0].length()){
			withSwitch=1;
		} else{
			withSwitch =  1 + switchOutlet(outletsSwitched, devicesSwitched, currentSwitch + 1);
		}
	}else{
		withSwitch = -999999999;
	}
	
	if(withoutSwitch >= 0 && withSwitch < 0){
		return withoutSwitch;
	} else if(withoutSwitch < 0 && withSwitch >= 0){
		return withSwitch;
	} else if(withoutSwitch >= 0 && withSwitch >=0){
		return Math.min(withoutSwitch, withSwitch);
	} else{
		return -999999999;
	}

}


private static boolean isOK(String[] devices, String[] outlets, int currentSwitch){
	boolean isOK = true;
	for(int i =0; i < devices.length;i++){
		boolean isOneOK = false;
		for(int j =0; j < devices.length;j++){
			if(devices[i].substring(0, currentSwitch).equals(outlets[j].substring(0, currentSwitch))){
				isOneOK = true;
				outlets[j] = "                                                                                                   ";
				break;
			}
		}
		if(!isOneOK){
			isOK = false;
			break;
		}
	}
	
	return isOK;
}

	public static void main(String[] args) {
		
		InputFile inputFile = new InputFile("A", "large", "_2014/Round1A");
		OutputFile outputFile = new OutputFile(inputFile);
		solve(inputFile, outputFile);
		outputFile.endFile();
		
	}
	
	
	
}
