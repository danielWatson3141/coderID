import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;

public class a {
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			int caseCount = Integer.parseInt(br.readLine());
			for (int caseNum = 0; caseNum < caseCount; caseNum++) {
				String[] nums = br.readLine().split(" ");
				int n = Integer.parseInt(nums[0]);
				int l = Integer.parseInt(nums[1]);
				String ini[] = br.readLine().split(" ");
				String req[] = br.readLine().split(" ");
				List<Integer> list = new ArrayList<Integer>();
				if (compareArrays(ini, req))
					list.add(0);
				else {
					for (int i = 1; i < Math.pow(2, l); i++) {
						String tmp[] = ini.clone();
						for (int j = 0; j < n; j++) {
							StringBuilder temp = new StringBuilder(tmp[j]);
							for (int k : getBitIndices(i)) {
								temp.setCharAt(k, temp.charAt(k) == '1' ? '0'
										: '1');
							}
							tmp[j] = temp.toString();
						}
						if (compareArrays(tmp, req))
							list.add(i);
					}
				}
				System.out.println("Case #"
						+ (caseNum + 1)
						+ ": "
						+ (list.size() > 0 ? getLeastSwitches(list)
								: "NOT POSSIBLE"));
			}
		} catch (IOException e) {
		}
	}

	public static int getLeastSwitches(List<Integer> list) {
		int lowestCount = Integer.MAX_VALUE;
		for (Integer i : list) {
			if (getBitCount(i) < lowestCount)
				lowestCount = getBitCount(i);
		}
		return lowestCount;
	}

	public static boolean compareArrays(String[] arr1, String[] arr2) {
		HashSet<String> set1 = new HashSet<String>(Arrays.asList(arr1));
		HashSet<String> set2 = new HashSet<String>(Arrays.asList(arr2));
		return set1.equals(set2);
	}

	public static int getBitCount(int n) {
		int count = 0;
		while (n != 0) {
			if (n % 2 != 0)
				count++;
			n /= 2;
		}
		return count;
	}

	public static int[] getBitIndices(int n) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		int i = 0;
		while (n != 0) {
			if (n % 2 != 0)
				list.add(i);
			n /= 2;
			i++;
		}
		return convertIntegers(list);
	}

	public static int[] convertIntegers(ArrayList<Integer> integers) {
		int[] ret = new int[integers.size()];
		Iterator<Integer> iterator = integers.iterator();
		for (int i = 0; i < ret.length; i++) {
			ret[i] = iterator.next().intValue();
		}
		return ret;
	}
}