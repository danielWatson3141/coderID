package r1;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;


public class MainA {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("input.in"));
		String line = br.readLine();
		int noTestCases = Integer.valueOf(line);
		StringBuilder log = new StringBuilder();
		
		for (int i = 0; i < noTestCases; i++) {
			int numSwitches = 0;
			
			line = br.readLine();
			String[] split = line.split(" ");
			int numDevices = Integer.valueOf(split[0]);
			int portLength = Integer.valueOf(split[1]);
			
			String[] ports = br.readLine().split(" ");
			char[][] initPorts =  new char[numDevices][];
			for (int j = 0; j < ports.length; j++) {
				initPorts[j] = new char[ports[j].length()];
				for (int k = 0; k < ports[j].length(); k++)
					initPorts[j][k] = ports[j].charAt(k);
			}
			
			String[] targetPorts = br.readLine().split(" ");
			String bits1;
			boolean found = false;
			for (int j = 0; !found && j <= Math.pow(2, portLength); j++) {
				bits1 = initBitSet(j, portLength);
//				System.out.println(bits1.toString());
				Set<String> currentPorts = generate(initPorts, bits1, portLength); 
//				System.out.println(Arrays.toString(currentPorts.toArray(new String[0])));
				if(checkFinished(targetPorts, currentPorts)){
					for (int k = 0; k < bits1.length(); k++) {
						if(bits1.charAt(k) == '1')
							numSwitches++;
					}
					log.append("Case #").append(i+1).append(": ").append(numSwitches).append("\n");
					found = true;
				}
			}
			
			if(!found)
				log.append("Case #").append(i+1).append(": ").append("NOT POSSIBLE").append("\n");
				
		}
		br.close();
		
		System.out.println(log.toString());
	}

	private static String initBitSet(int num, int portLength){
		String result = "";
	    for (int i = portLength-1; i >= 0; i--)
	        if((num & (1 << i)) != 0)
	        	result += '1';
	        else
	        	result += '0';
	    return result;
	}
	
	private static Set<String> generate(char[][] initPorts, String bits1, int bits) {
		Set<String> currentPorts = new HashSet<String>();
		for (char[] port : initPorts) {
			String currentPort = "";
			for (int i = 0; i < bits; i++) {
				if(bits1.charAt(i) == '1'){
					if(port[i] == '0')
						currentPort += '1';
					else
						currentPort += '0';
				}else
					currentPort += port[i]; 
			}
			currentPorts.add(currentPort);
		}
		return currentPorts;
	}

	private static boolean checkFinished(String[] targetPorts,
			Set<String> currentPorts) {
		for (String targetPort : targetPorts) {
			if(!currentPorts.contains(targetPort))
				return false;
		}
		return true;
	}
	
}
