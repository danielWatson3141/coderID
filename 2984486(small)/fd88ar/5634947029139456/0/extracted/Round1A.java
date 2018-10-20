import java.util.*;


public class Round1A {
	
	static Scanner scan;
	static int N, L;
	static ArrayList<String> goal;
	
	public static void main(String[] args) {
		scan = new Scanner(System.in);
		int cases = scan.nextInt();
		for(int i = 1; i <= cases; ++i) {
			System.out.print("Case #" + i + ": ");
			doCase();
		}
	}
	
	static void doCase() {
		N = scan.nextInt();
		L = scan.nextInt();
		ArrayList<String> initial = new ArrayList<String>();
		goal = new ArrayList<String>();
		for(int i = 0; i < N; ++i) {
			initial.add(scan.next());
		}
		for(int i = 0; i < N; ++i) {
			goal.add(scan.next());
		}
		int r = findClosest(0, 0, initial);
		if(r == -1) {
			System.out.println("NOT POSSIBLE");
		} else {
			System.out.println(r);
		}
	}
	
	static int findClosest(int index, int changed, ArrayList<String> start) {
		if(index == L) {
			if(correct(start, goal)) {
				return changed;
			}
			return -1;
		}
		int result = findClosest(index+1, changed, start);
		ArrayList<String> switched = new ArrayList<String>();
		for(String s : start) {
			switched.add(useSwitch(s,index));
		}
		int result2 = findClosest(index+1, changed+1, switched);
		if(result == -1) return result2;
		if(result2 == -1) return result;
		return Math.min(result, result2);
	}
	
	static String useSwitch(String s, int i) {
		char c = s.charAt(i);
		char[] r = s.toCharArray();
		if(c=='0') {
			r[i] = '1';
		} else {
			r[i] = '0';
		}
		return String.valueOf(r);
	}
	
	static boolean correct(ArrayList<String> candidate, ArrayList<String> goal) {
		return candidate.containsAll(goal);
	}

}
