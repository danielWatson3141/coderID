import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.List;

public class Main {

	public static void main(String[] args) {
		String inputFile = args[0];
		String outputFile = args[1];

		File file = new File(inputFile);
		File ouptutFile = new File(outputFile);
	
		if (!file.exists() ) return ;
		Integer testCaseNum = 0;
	
		try (
				FileReader fr = new FileReader(file);
				BufferedReader br = new BufferedReader(fr);
				FileWriter fw = new FileWriter(outputFile);
				BufferedWriter bw = new BufferedWriter(fw);
		) {
			String line = null;
			line = br.readLine();
		
			testCaseNum = Integer.parseInt(line);
		
			for (int i =0; i < testCaseNum; i++) {
				line = br.readLine();
				String [] splitedLine = line.split(" ");
				int numDevice = Integer.parseInt(splitedLine[0]);
				int numBits = Integer.parseInt(splitedLine[1]);
			
				line = br.readLine();
				String [] splitedOutlet = line.split(" ");
			
				line = br.readLine();
				String [] splitedDevice = line.split(" ");
				
				int tryNum = solveJam(numDevice, numBits, splitedOutlet, splitedDevice);
				
				bw.write(String.format("Case #%d: ", i+1));
				if ( tryNum == -1 )  {
					bw.write("NOT POSSIBLE\n");
				} else {
					bw.write(String.format("%d\n", tryNum));	
				}
			}
			
		} catch ( Exception e) {
			e.printStackTrace();
		}
	}
	
	private static int solveJam(int numDevice, int numBits, String[] outlets,
			String[] devices) {
		
		int tryNum = -1;
		
		List<String> outletList = Arrays.asList(outlets);
		List<String> deviceList = Arrays.asList(devices);
		
		if ( outletList.containsAll(deviceList) ) {
			return 0;
		}
		
		for ( String outlet : outletList ) {
			for (int i =0; i < numDevice; i++) {
				String device = deviceList.get(i);
				
				ArrayList<Integer> changeBitList = new ArrayList<>();
				for (int j =0; j < numBits; j++) {
					if ( outlet.charAt(j) != device.charAt(j) ) {
						changeBitList.add(j);
					}
				}
				
				if ( tryNum != -1 && tryNum < changeBitList.size() ) {
					continue;
				}
				
				
				ArrayList<String> changedList = new ArrayList<>();
				for ( String changedOutlet : outlets) {
					String s = new String();
					for ( int j =0; j < numBits; j++) {
						if ( changeBitList.contains(j) ) {
							if ( changedOutlet.charAt(j) == '0' ) {
								s = s.concat("1");
							} else {
								s = s.concat("0");
							}
						} else {
							s = s.concat(String.valueOf(changedOutlet.charAt(j)));
						}
					} 
					changedList.add(s);
				}
				
				if ( changedList.containsAll(deviceList) ) {
					tryNum = changeBitList.size();
				}
			}
		}
		
		return tryNum;
	}


}
