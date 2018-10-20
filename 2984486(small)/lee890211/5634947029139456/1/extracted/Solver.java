import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Solver {

//	private static String mInputFName = "A-small-attempt2.in";
//	private static String mOutputFName = "A-small-attempt2.out";

	 private static String mInputFName = "A-large.in";
	 private static String mOutputFName = "A-large.out";

	private static Scanner sc;
	private static PrintWriter pw;

	private static String printStr = "";

	public static void main(String[] args) throws IOException {
		sc = new Scanner(new FileReader(mInputFName));
		pw = new PrintWriter(mOutputFName);

		int cNum = sc.nextInt();

		for (int i = 0; i < cNum; i++) {
			int inputNum = sc.nextInt();
			int inputLen = sc.nextInt();

			String[] outLets = new String[inputNum];
			String[] devices = new String[inputNum];
			for (int j=0; j<inputNum; j++)
				outLets[j] = sc.next();
			for (int j=0; j<inputNum; j++)
				devices[j] = sc.next();
			int res = calc(outLets, devices, inputNum, inputLen);
			
			if (res == -1)
				pw.println(String.format("Case #%d: %s", i+1, "NOT POSSIBLE"));
			else 
				pw.println(String.format("Case #%d: %d", i+1, res));

		}
		pw.flush();
		sc.close();
		pw.close();

	}

	private static int calc(String[] out, String[] devices, int arrSize,
			int strLen) {

		HashMap<Integer, Boolean> shouldFlipSwitch = new HashMap<Integer, Boolean>();
		HashMap<Integer, Boolean> nonOccupiedSwitch = new HashMap<Integer, Boolean>();
		int flip_num = -1;
		// 첫번재 스위치가 선택할 스위치
		for (int i = 0; i < arrSize; i++) {
			nonOccupiedSwitch.clear();
			shouldFlipSwitch.clear();
			for (int j = 0; j < arrSize; j++)
				nonOccupiedSwitch.put(j, true);

			nonOccupiedSwitch.remove(i);

			for (int j = 0; j < strLen; j++) {
				if (devices[0].charAt(j) != out[i].charAt(j)){
					shouldFlipSwitch.put(j, true);
				}
			}
			// 두번째 스위치부터 마지막까지
			for (int j = 1; j < arrSize; j++) {
				boolean matchSwitch = false;
				// 선택할 스위치
				for (int sw : nonOccupiedSwitch.keySet()) {
					boolean check = true;
					for (int k = 0; k < strLen; k++) {
						if (devices[j].charAt(k) != out[sw].charAt(k)) {
							if (shouldFlipSwitch.get(k) == null) {
								check = false;
								break;
							}

						} else {
							if (shouldFlipSwitch.get(k) != null) {
								check = false;
								break;
							}
						}
					}
					
					if (check){
						nonOccupiedSwitch.remove(sw);
						matchSwitch = true;
						break;
					}
						
				}
				if (!matchSwitch) {
//					flip_num = -1;
					break;
				}
				
				if (j == arrSize-1 && (flip_num > shouldFlipSwitch.size() || flip_num == -1)){
					flip_num = shouldFlipSwitch.size();
				}
			}
		}
		if (arrSize == 1)
			flip_num = shouldFlipSwitch.size();
		return flip_num;
	}
	
}
