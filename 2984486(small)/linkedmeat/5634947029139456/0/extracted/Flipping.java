import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/* Name of the class has to be "Main" only if the class is public. */
class Flipping {
	public static void main(String[] args) throws java.lang.Exception {
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		File file = new File("output.txt");
		BufferedWriter bw = new BufferedWriter(new FileWriter(file));
		String lineSeperator = System.getProperty("line.separator");
		try {
			int numOfCases = Integer.parseInt(br.readLine());
			int curCase = 1;
			while (curCase <= numOfCases) {
				String[] params = br.readLine().split(" ");
				int numOfDevices = Integer.parseInt(params[0]);
				int length = Integer.parseInt(params[1]);

				int[] inputFlow = toIntArray(br.readLine().split(" "));
				int[] targetFlow = toIntArray(br.readLine().split(" "));
				int y = minFlipping(inputFlow, targetFlow, numOfDevices, length);

				String result = "" + y;
				if (y == -1)
					result = "NOT POSSIBLE";
				String line = "Case #" + curCase + ": " + result;

				System.out.println(line);
				bw.append(line + lineSeperator);
				curCase++;
			}
		} finally {
			br.close();
			bw.close();
		}
	}

	public static int[] toIntArray(String[] inputFlow) {
		int[] array = new int[inputFlow.length];
		for (int i = 0; i < array.length; i++) {
			array[i] = Integer.parseInt(inputFlow[i], 2);
		}
		return array;
	}

	public static int minFlipping(int[] inputFlow, int[] targetFlow,
			int numOfOutlets, int outletLength) {
		int min = -1;
		int length = (int) Math.pow(2, outletLength);
		for (int i = 0; i <= length; i++) {
			int[] initFlow = Arrays.copyOf(inputFlow, inputFlow.length);
			for (int index = 0; index < numOfOutlets; index++) {
				initFlow[index] = initFlow[index] ^ i;
			}
			Arrays.sort(initFlow);
			Arrays.sort(targetFlow);
			if (Arrays.equals(initFlow, targetFlow)) {
				int count = 0;
				String indicator = Integer.toBinaryString(i);
				for (int k = 0; k < indicator.length(); k++) {
					if (indicator.charAt(k) == '1') {
						count++;
					}
				}
				if (min == -1)
					min = count;
				min = min > count ? count : min;
			}
		}
		return min;
	}
}