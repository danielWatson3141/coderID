import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;


public class ProblemA {
    public static void main(String[] args) {
        BufferedReader r = null;
        BufferedWriter bw = null;
        FileWriter fw = null;
        
        try {
            InputStreamReader myInputStreamReader = new InputStreamReader(
                    new FileInputStream("A-small-attempt0.in"));
            r = new BufferedReader(myInputStreamReader);
            
            File file = new File("A-small-attempt0.out");
            
            if (!file.exists()) {
                file.createNewFile();
            }
            
            fw = new FileWriter(file.getAbsoluteFile());
            bw = new BufferedWriter(fw);

            String line = r.readLine().toString();
            int T = Integer.parseInt(line);
            
            for (int t = 0; t < T; t++) {
                line = r.readLine().toString();
                String[] inputStrings = line.split(" ");
                int N = Integer.parseInt(inputStrings[0]);
                int L = Integer.parseInt(inputStrings[1]);
                
                long[] outlets = new long[N];
                long[] devices = new long[N];
                
                line = r.readLine().toString();
                inputStrings = line.split(" ");
                
                for (int i = 0; i < inputStrings.length; i++) {
//                	Byte b = Byte.parseByte(inputStrings[i], 2);
                	outlets[i] = Long.parseLong(inputStrings[i], 2);
//                	System.out.print(outlets[i] + " ");
				}
//                System.out.println(" ");
                
                line = r.readLine().toString();
                inputStrings = line.split(" ");
                
                for (int i = 0; i < inputStrings.length; i++) {
//                	Byte b = Byte.parseByte(inputStrings[i], 2);
                	devices[i] = Long.parseLong(inputStrings[i], 2);
//                	System.out.print(devices[i] + " ");
				}
//                System.out.println(" ");
                
                
                Arrays.sort(devices);
                
                int smallestResult = 100;
                for (int i = 0; i < Math.pow(2, L); i++) {
					if (compare(outlets, devices, i)) {
						String binaryFormat = Long.toBinaryString(i);
						int result = 0;
						for (int j = 0; j < binaryFormat.length(); j++) {
							if (binaryFormat.charAt(j) == '1') {
								result++;
							}
						}
						
						if (result < smallestResult) {
							smallestResult = result;
						}
					}
				}
                
                String strAnswer = "";
                
                if (smallestResult == 100) {
                	strAnswer = "NOT POSSIBLE";
				} else {
					strAnswer += smallestResult;
				}
                
                String strCase = "Case #" + (t + 1) + ": ";
                System.out.println(strCase + strAnswer);
                bw.write(strCase + strAnswer);
                if (t < T - 1) {
                    bw.write("\n");
                }
                
                
            }

        } catch (NumberFormatException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                r.close();
                bw.close();
                fw.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    
    private static boolean compare(long[] outlets, long[] devices, long switches) {
    	long[] tempOutlets = new long[outlets.length];
    	for (int i = 0; i < tempOutlets.length; i++) {
			tempOutlets[i] = outlets[i] ^ switches;
		}
    	Arrays.sort(tempOutlets);
    	for (int i = 0; i < devices.length; i++) {
			if (devices[i] != tempOutlets[i]) {
				return false;
			}
		}
    	return true;
    }
}
