import java.io.*;
import java.util.*;


public class ChargingChaos {

	public static void main(String[] args) throws Exception{
		String inputFile = "A-small-attempt0";
		BufferedReader br = new BufferedReader(new FileReader(inputFile+".in"));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintStream ps = new PrintStream(new File(inputFile+".out"));
//		PrintStream ps = new PrintStream(System.out);

		int testcase = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < testcase; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()); //number of switches
			int l = Integer.parseInt(st.nextToken()); //number of bits
			
			String[] initialflow = br.readLine().split(" ");
			String[] devices = br.readLine().split(" ");
			
			Set<Set<Integer>> configs = powerSet(generateOrder(l)); //all configs, sets of sets
			
			int shortest = Integer.MAX_VALUE;
			for(Set<Integer> switches : configs){
				String[] modified = initialflow;
				for(int currentswitch : switches){
					modified = flipIndex(modified, currentswitch);
				}
				if(checkContains(modified,devices)){
					if(switches.size() < shortest){
						shortest = switches.size();
					}
				}
			}
			if(shortest == Integer.MAX_VALUE){
				printCase("NOT POSSIBLE", ps, i+1);
			}
			else{
				printCase(shortest + "", ps, i+1);
			}
		}
	}
	public static boolean checkContains(String[] modified, String[] devices){
		for(String i : devices){
			if(!Arrays.asList(modified).contains(i)){
				return false;
			}
		}
		return true;
	}
	public static String[] flipIndex(String[] initialflow, int index){
		String[] temp = new String[initialflow.length];
		for(int i = 0; i < initialflow.length; i++){
			String currentBit = initialflow[i];
			String bit = "";
			for(int j = 0; j < currentBit.length(); j++){
				if(j != index){
					bit += currentBit.charAt(j);
				}
				else{
					bit += flip(Integer.parseInt(currentBit.charAt(j) + ""));
				}
			}
			temp[i] = bit;
		}
		return temp;
	}
	public static int flip(int n){
		if(n==0){
			return 1;
		}
		else if(n==1){
			return 0;
		}
		else{
			return -1;
		}
	}
	public static Set<Integer> generateOrder(int l){
		Set<Integer> temp = new HashSet<Integer>();
		for(int i = 0; i < l; i++){
			temp.add(i);
		}
		return temp;
	}
	public static void printCase(String s, PrintStream ps, int ncase){
		ps.println("Case #" + ncase + ": " + s);
	}
	public static <T> Set<Set<T>> powerSet(Set<T> originalSet) {
	    Set<Set<T>> sets = new HashSet<Set<T>>();
	    if (originalSet.isEmpty()) {
	    	sets.add(new HashSet<T>());
	    	return sets;
	    }
	    List<T> list = new ArrayList<T>(originalSet);
	    T head = list.get(0);
	    Set<T> rest = new HashSet<T>(list.subList(1, list.size())); 
	    for (Set<T> set : powerSet(rest)) {
	    	Set<T> newSet = new HashSet<T>();
	    	newSet.add(head);
	    	newSet.addAll(set);
	    	sets.add(newSet);
	    	sets.add(set);
	    }		
	    return sets;
	}
}
