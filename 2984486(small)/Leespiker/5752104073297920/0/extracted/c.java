import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class c {
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			int caseCount = Integer.parseInt(br.readLine());
			for (int caseNum = 0; caseNum < caseCount; caseNum++) {
				String[] nums = br.readLine().split(" ");
				int[] iNums = new int[nums.length];
				for (int i = 0; i < nums.length; i++)
					iNums[i] = Integer.parseInt(nums[i]);
				long start = System.nanoTime();
				insertionSort(iNums);
				long end = System.nanoTime();
				System.out.println("Case #" + (caseNum + 1) + ": "
						+ (end - start < 100000 ? "BAD" : "GOOD"));
			}
		} catch (IOException e) {
		}
	}

	public static void insertionSort(int[] arr) {
		int i, j, newValue;
		for (i = 1; i < arr.length; i++) {
			newValue = arr[i];
			j = i;
			while (j > 0 && arr[j - 1] > newValue) {
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = newValue;
		}
	}
}