import java.io.File;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.TreeSet;


public class Chaos {
	public static void main(String[] args) throws Exception{
		
		Scanner s = new Scanner(new File("A-small-attempt0.in"));
		int numCases = Integer.parseInt(s.nextLine());
		for(int c = 1;c<=numCases;c++) {
			String counts = s.nextLine();
			String outlets = s.nextLine();
			String[] outletsArr = outlets.split(" ");
			String devices = s.nextLine();
			String[] devicesArr = devices.split(" ");
			int result = solve(outletsArr,devicesArr);
			if(result==-1) {
				System.out.println("Case #" + c + ": NOT POSSIBLE");
			} else {
				System.out.println("Case #" + c + ": " + result);
			}
		}
		
		
		
	}
	public static int solve(String[] settings, String[] devices) {
		int size = settings[0].length();
		LinkedList<Flip> q = new LinkedList<Flip>();
		q.push(new Flip(settings,new TreeSet<Integer>(),0));
		while(!q.isEmpty()) {
			Flip test = q.pop();
			//System.out.println("TESTING: " + test.flipped);
			if(check(test.current,devices)) {
				return test.flipped.size();
			} else {
				for(int i = test.min;i<size;i++) {
						//System.out.println("GENERATING WITH FLIP " + i);
						Flip next = new Flip(generate(test.current,i),test.flipped,i+1);
						next.flipped.add(i);
						q.push(next);
				}
			}
		}
		return -1;
	}
	public static String[] generate(String[] current, int flip) {
		String[] answer = new String[current.length];
		for(int i = 0;i<current.length;i++) {
			String result = current[i];
			if(result.charAt(flip) == '0') {
				result = result.substring(0,flip) + '1' + result.substring(flip+1);
			} else {
				result = result.substring(0,flip) + '0' + result.substring(flip+1);
			}
			answer[i] = result;
		}
		return answer;
	}
	public static boolean check(String[] settings, String[] devices) {
		for(String d : devices) {
			boolean found = false;
			for(String s : settings) {
				if(s.equals(d)){
					found = true;
				}
			}
			if(!found) {
				return false;
			}
		}
		return true;
	}
}
class Flip {
	String[] current;
	TreeSet<Integer> flipped = new TreeSet<Integer>();
	int min;
	public Flip(String[] current,TreeSet<Integer> flipped, int min) {
		this.current = current;
		this.flipped = new TreeSet<Integer>();
		this.flipped.addAll(flipped);
		this.min = min;
	}
}
