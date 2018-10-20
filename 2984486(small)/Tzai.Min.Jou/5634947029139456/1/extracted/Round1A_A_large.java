import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Round1A_A_large {

	public static void main(String[] args) throws IOException {

		BufferedReader inputReader = new BufferedReader(
				new FileReader("fileRound1A_A\\A-large.in"));
		BufferedWriter outputWriter = new BufferedWriter(
				new FileWriter("fileRound1A_A\\A-large.out"));
		int testCaseNumber = Integer.valueOf(inputReader.readLine());
		for (int i = 1 ; i <= testCaseNumber ; i++) {
			String N_L = inputReader.readLine();
			String[] N_L_Array = N_L.split(" ");
			int N = Integer.parseInt(N_L_Array[0]);
			int L = Integer.parseInt(N_L_Array[1]);
			String outlet = inputReader.readLine();
			String[] outlet_array = outlet.split(" ");
			String device = inputReader.readLine();
			String[] device_array = device.split(" ");
			int switch_count[] = new int[N];
			boolean[] diff_digit = new boolean[L];
			boolean isEqual;
			
			for (int j = 0 ; j < N ; j++) {
				switch_count[j] = 100;
			}
			
			for (int j = 0 ; j < N ; j++) {
				isEqual = true;
				for (int k = 0 ; k < L ; k++) {
					diff_digit[k] = false;
				}
				
				for (int k = 0 ; k < L ; k++) {
					if (outlet_array[0].charAt(k) != device_array[j].charAt(k)) {
						diff_digit[k] = true;
					}
				}
				String[] ret = switch_outlet(outlet_array, N, diff_digit, L);
				
				for (int k = 0 ; k < N ; k++) {
					int m = 0;
					for (; m < N ; m++) {
						if (ret[k].equals(device_array[m])) {
							break;
						}
					}
					if (m == N) {
						isEqual = false;
					}
				}
				if (isEqual) {
					int count = 0;
					for (int k = 0 ; k < L ; k++) {
						if (diff_digit[k]) {
							count++;
						}
					}
					switch_count[j] = count;
				}
				
			}
			
			int isPossible = 100;
			for (int j = 0 ; j < N ; j++) {
				if (switch_count[j] < isPossible) {
					isPossible = switch_count[j];
				}
			}
			if (isPossible == 100) {
				outputWriter.write("Case #" + Integer.toString(i) + ": NOT POSSIBLE");
			} else {
				outputWriter.write("Case #" + Integer.toString(i) + ": " + isPossible);
			}
			outputWriter.newLine();
		}
		inputReader.close();
		outputWriter.close();
	}
	
	public static String[] switch_outlet(String[] outlet_array, int N, boolean[] diff_digit, int L) {
		String[] ret = new String[N];
		
		for (int i = 0 ; i < N ; i++) {
			char[] string_char = new char[L]; 
			for (int j = 0 ; j < L ; j++) {
				if (diff_digit[j]) {
					if (outlet_array[i].charAt(j) == '0') {
						string_char[j] = '1';
					} else {
						string_char[j] = '0';
					}
				} else {
					string_char[j] = outlet_array[i].charAt(j);
				}
			}
			ret[i] = new String(string_char);
		}
		return ret;
	}

}
