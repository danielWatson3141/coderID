import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class ProblemC {
	private static double[][] probs = null;
	public static int middle = 65000;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("C-small-attempt0.in"));
		System.setOut(new PrintStream(new FileOutputStream("C-small-attempt0.out")));

		Scanner in = new Scanner(System.in);

		int T = in.nextInt();

		int[][] allnums = new int[T][];

		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			int[] nums = new int[N];
			for (int j = 0; j < N; j++) {
				nums[j]  = in.nextInt();
			}
			allnums[i] = nums;
		}

		boolean[] res = solve(allnums);

		for (int i = 0; i < T; i++) {
			System.out.printf("Case #%d: %s%n", i+1, (res[i])?"GOOD":"BAD");
		}
	}
	
	public static boolean[] solve(int[][] allnums) {
		int T = allnums.length;
		double[] difs = new double[T];
		int[] indices = new int[T];
		for (int i = 0; i < T; i++) {
			indices[i] = i;
			difs[i] = deviation(allnums[i]);
		}

		for (int i = 0; i < T - 1; i++) {
			for (int j = i + 1; j < T; j++) {
				if (difs[i] > difs[j]) {
					indices[i] ^= indices[j];
					indices[j] ^= indices[i];
					indices[i] ^= indices[j];

					double temp = difs[i];
					difs[i] = difs[j];
					difs[j] = temp;
				}
			}
		}

		boolean[] res = new boolean[T];
		for (int i = 0; i < T; i++) {
			//res[indices[i]] = (i < T / 2);
			res[indices[i]] = difs[i] < middle;
		}
		
		return res;
	}

	public static double deviation(int[] nums) {
		if (probs == null) genprobs();
		int N = nums.length;
		double dev = 0;
		for (int i = 0; i < N; i++) {
			double p = probs[nums[i]][i];
			//dev += Math.signum(p) * p * p;
			dev += probs[nums[i]][i];
		}
		return dev * 10000000;
	}
	
	private static void badShuffle(int[] nums) {
		int N = nums.length;
		for (int i = 0; i < N; i++) {
			int p = (int)(Math.random() * N);
			if (i != p) {
				nums[i] ^= nums[p];
				nums[p] ^= nums[i];
				nums[i] ^= nums[p];
			}
		}
	}
	
	private static void goodShuffle(int[] nums) {
		int N = nums.length;
		for (int i = 0; i < N; i++) {
			int p = (int)(Math.random() * (N-i)) + i;
			if (i != p) {
				nums[i] ^= nums[p];
				nums[p] ^= nums[i];
				nums[i] ^= nums[p];
			}
		}
	}
	
	private static void genprobs() {
		int N = 1000;
		int reps = 1 << 16;
		probs = new double[N][N];
		for (int i = 0; i < reps; i++) {
			int[] nums = new int[N];
			for (int j = 0; j < N; j++) nums[j] = j;
			badShuffle(nums);
			for (int j = 0; j < N; j++) {
				probs[nums[j]][j] += 1.0 / reps;
			}
		}
		for (int i = 0; i < reps; i++) {
			int[] nums = new int[N];
			for (int j = 0; j < N; j++) nums[j] = j;
			goodShuffle(nums);
			for (int j = 0; j < N; j++) {
				probs[nums[j]][j] -= 1.0 / reps;
			}
		}
	}
	
	public static int mergeSort(int[] nums, int[] temp, int left, int right) {
		int count = 0;
		if (right > left) {
			int mid = (right+left)/2;
			count += mergeSort(nums,temp,left,mid);
			count += mergeSort(nums,temp,mid+1,right);
			count += merge(nums,temp,left,mid+1,right);
		}
		return count;
	}
	
	public static int merge(int[] nums, int[] temp, int left, int mid, int right) {
		int i = left;
		int j = mid;
		int k = 0;
		int N = right - left+1;
		
		int count = 0;
		
		while (i < mid && j <= right) {
			if (nums[i] <= nums[j]) {
				temp[k++] = nums[i++];
			} else {
				temp[k++] = nums[j++];
				count += mid - i;
			}
		}
		
		while (i < mid) {
			temp[k++] = nums[i++];
		}
		while (j <= right) {
			temp[k++] = nums[j++];
		}
		for (i = left; i <= right; i++) {
			nums[i] = temp[i-left];
		}
		
		return count;
	}
}
