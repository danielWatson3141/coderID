
public class LongMergeSort {
	
	public static long[] sort(long[] y, int n, boolean isBigToSmall) {
		if (n <= 1) return y;
		int middle = n/2;
		long[] left = new long[middle];
		for (int i=0; i<middle; i++)
			left[i] = y[i];
		left = sort(left, middle, isBigToSmall);
		long[] right;
		if (middle*2 == n) {
			right = new long[middle];
			for (int i=0; i<middle; i++)
				right[i] = y[middle+i];
			right = sort(right, middle, isBigToSmall);
		} else {
			right = new long[middle+1];
			for (int i=0; i<=middle; i++)
				right[i] = y[middle+i];
			right = sort(right, middle+1, isBigToSmall);
		}
		return merge(left, right, isBigToSmall);
	}

	private static long[] merge(long[] left, long[] right, boolean isBigToSmall) {
		int leftLen = left.length;
		int rightLen = right.length;
		int resultLen = leftLen + rightLen;
		int i=0;
		int j=0;
		long[] result = new long[resultLen];
		for (int m=0; m<resultLen; m++) {
			if (isBigToSmall) {
				if (i < leftLen && j<rightLen) {
					if (left[i] > right[j]) {
						result[m] = left[i];
						i++;
					}
					else {
						result[m] = right[j];
						j++;
					}
				}
				else if (i < leftLen) {
					result[m] = left[i];
					i++;
				}
				else if (j < rightLen) {
					result[m] = right[j];
					j++;
				}
			}
			else {
				if (i < leftLen && j<rightLen) {
					if (left[i] < right[j]) {
						result[m] = left[i];
						i++;
					}
					else {
						result[m] = right[j];
						j++;
					}
				}
				else if (i < leftLen) {
					result[m] = left[i];
					i++;
				}
				else if (j < rightLen) {
					result[m] = right[j];
					j++;
				}
			}
		}
		return result;
	}

}
