import java.io.*;
import java.util.Arrays;

public class ChargingChaos {
	static String flip(String original, String bits){
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<original.length(); i++){
			if(bits.charAt(i) == '1'){
				if(original.charAt(i) == '0'){
					sb.append('1');
				}else{
					sb.append('0');
				}
			}else{
				sb.append(original.charAt(i));
			}
		}
		return sb.toString();
	}
	static boolean match(String[] outlets, String[] devices){
		String[] sortedOutlets = new String[outlets.length];
		String[] sortedDevices = new String[devices.length];
		for(int i=0; i<outlets.length; i++){
			sortedOutlets[i] = outlets[i];
		}
		for(int i=0; i<devices.length; i++){
			sortedDevices[i] = devices[i];
		}
		Arrays.sort(sortedOutlets);
		Arrays.sort(sortedDevices);
		if(sortedOutlets.length != sortedDevices.length){
			return false;
		}
		for(int i=0; i<sortedOutlets.length; i++){
			if(!sortedOutlets[i].equals(sortedDevices[i])){
				return false;
			}
		}
		return true;
	}
	static String xor(String device, String outlet){
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<device.length(); i++){
			if(device.charAt(i) == outlet.charAt(i)){
				sb.append("0");
			}else{
				sb.append("1");
			}
		}
		return sb.toString();
	}
	static int countBits(String bits){
		int count = 0;
		for(int i=0; i<bits.length(); i++){
			if(bits.charAt(i) == '1'){
				count++;
			}
		}
		return count;
	}
	static int solve(String[] origins, String[] devices){
		String dev1 = devices[0];
		String[] flipped = new String[origins.length];
		boolean possible = false;
		int best = 100;
		for(String outlet : origins){
			String bits = xor(dev1, outlet);
			for(int i=0; i<origins.length; i++){
				flipped[i] = xor(origins[i], bits);
			}
			if(match(flipped, devices)){
				int temp = countBits(bits);
				if(temp < best){
					best = temp;
				}
				possible = true;
			}
		}
		if(possible){
			return best;
		}else{
			return -1;
		}
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.valueOf(br.readLine());
		for(int ctr=0; ctr<cases; ctr++){
			br.readLine(); // Throw out the count and length
			String[] origins = br.readLine().split("\\s+");
			String[] devices = br.readLine().split("\\s+");
			
			int answer = solve(origins, devices);
			if(answer < 0){
				System.out.printf("Case #%d: NOT POSSIBLE\n", ctr+1);
			}else{
				System.out.printf("Case #%d: %d\n", ctr+1, answer);
			}
		}
	}
}
