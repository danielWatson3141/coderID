import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class ChargingChaos {

	private static void processInput(int i, Scanner in) {

		int N = in.nextInt();
		int L = in.nextInt();

		String origStr[] = new String[N];
		Long origLong[] = new Long[N];
		String reqStr[] = new String[N];
		Long reqLong[] = new Long[N];

		for (int n = 0; n < N; n++) {
			origStr[n] = in.next();
			origLong[n] = Long.parseLong(origStr[n], 2);
//			System.out.print(origLong[n] + " ");
		}
//		System.out.println();

		for (int n = 0; n < N; n++) {
			reqStr[n] = in.next();
			reqLong[n] = Long.parseLong(reqStr[n], 2);
//			System.out.print(reqLong[n] + " ");
		}
//		System.out.println();

		Long diff[][] = new Long[N][N];

		List<Set<Long>> diffListOfSet = new ArrayList<Set<Long>>();
		List<Long> firstSet = new ArrayList<Long>();

		for (int p = 0; p < N; p++) {
			Set<Long> currSet = new HashSet<Long>();
			for (int q = 0; q < N; q++) {
				diff[p][q] = origLong[p] ^ reqLong[q];
//				System.out.print(diff[p][q] + " ");
				currSet.add(diff[p][q]);
				if (p == 0) {
					firstSet.add(diff[p][q]);
				}
			}
//			System.out.println();
			diffListOfSet.add(currSet);
		}

		boolean flag = true;
		int min = 99;
		for (Long difff : firstSet) {
			int countOfOnesInDifff = getCountOfOnes(difff);
//			System.out.println(countOfOnesInDifff + " ");
			flag = true;
			for (Set<Long> currSet : diffListOfSet) {
				if (!currSet.contains(difff)) {
//					System.out.println("false" + currSet);
					flag = false;
					break;
				}
			}
			if (flag && countOfOnesInDifff == 0) {
				min = 0;
				break;
			}
			if (flag) {
				if (min > countOfOnesInDifff) {
					min = countOfOnesInDifff;
				}
			}
//			System.out.println();
		}

		
		String output = "";
		if (min == 99) {
			output = "NOT POSSIBLE";
		} else {
			output = new Integer(min).toString();
		}
		System.out.println("Case #" + (i + 1) + ": " + output);
	}

	private static int getCountOfOnes(Long num) {
		int count;
		for (count = 0; num > 0; ++count) {
			num &= num - 1;
		}
		return count;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			processInput(i, in);
		}
		in.close();

	}

}