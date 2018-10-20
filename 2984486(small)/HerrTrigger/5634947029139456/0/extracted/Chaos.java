import java.util.*;
import java.lang.*;

public class Chaos{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int num_problems = Integer.parseInt(scan.nextLine());
		for(int case_no = 1; case_no <= num_problems; case_no++) {
			String l = scan.nextLine();
			String[] ls = l.split(" ");
			int num 	= Integer.parseInt(ls[0]);
			int length 	= Integer.parseInt(ls[1]);
			l = scan.nextLine();
			String[] outlets = l.split(" ");
			l = scan.nextLine();
			String[] devices = l.split(" ");
			
			String out = "NOT POSSIBLE";
			for(int d = 0; d <= length; d++) {				
				if(search(outlets, devices, length, d , -1)){
					out = String.valueOf(d);
					break;
				}
			}
		
			System.out.println("Case #" + case_no + ": " + out);			
		}
		scan.close();		
	}
	
	public static boolean search(String[] outlets, String[] devices, int length, int depth, int from){
		if(depth > 0){
			for(int i = 0; i < length; i++) {
				if(i == from) return false;
				String[] outlets_c = copyStrings(outlets);
				flip(outlets_c, i);
				if(search(outlets_c, devices, length, depth - 1, i))
					return true;
			}
			return false;
		}else return match(outlets, devices);
		
	}
	
	public static void flip(String[] ss, int pos) {
		for(int i = 0; i < ss.length; i++) {
			char[] cs = ss[i].toCharArray();
			cs[pos] = (cs[pos] == '0' ? '1' : '0');
			ss[i] = String.valueOf(cs);
		}
	}
	
	public static boolean match(String[] ss0, String[] ss1){
		LinkedList<String> ll = new LinkedList<String>(Arrays.asList(ss1));
		for(int i = 0; i < ss0.length; i++) {
			int size = ll.size();
			for(int j = 0; j < ll.size(); j++) {
				if(ll.get(j).compareTo(ss0[i]) == 0) {
					ll.remove(j);
					break;
				}
			}
			if (ll.size() == size)
				return false;
		}
		if(ll.size() == 0)
			return true;
		return false;
	}
	
	public static String[] copyStrings(String[] ss){
		String[] ss0 = new String[ss.length];
		for(int i = 0; i < ss.length; i++) {
			ss0[i] = String.valueOf(ss[i].toCharArray());
		}
		return ss0;
	}
}