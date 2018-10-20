package Round1A;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;


public class ProblemA {

	static int N;
	static int L;
	
	public static void main(String[] args) {
		
		FileReader fr = null ;
    	Scanner sc = null;
    	int n_cases = 0;
    	Locale.setDefault(Locale.US);
    
    
    	try{
    		fr = new FileReader(args[0]);
    		sc = new Scanner(fr);
    		
    		if (sc.hasNextInt()) n_cases = sc.nextInt();
    		
    		for (int i=0;i<n_cases;i++){
    			
    			N = sc.nextInt();
    			L = sc.nextInt();
    			sc.nextLine();
    			boolean possible = true;
    			
    			String[] initial = sc.nextLine().split(" ");
    			String[] goal = sc.nextLine().split(" ");
    			Arrays.sort(goal);
    			
    			String[] test = initial.clone();
    			ArrayList<int[]> switches = new ArrayList<int[]>();
    			switches.add(new int[L]);
    			
    			for (int l=0;l<L;l++){
    				int sum_init = sumSwitch(test,l);
    				int sum_goal = sumSwitch(goal,l);
    				if (sum_init == sum_goal && sum_goal == N-sum_init){
    					ArrayList<int[]> new_switches = new ArrayList<int[]>();
    					for (int[] array : switches){
    						array[l]=0;
    					}
    					for (int[] array : switches){
    						int[] new_array = array.clone();
    						new_array[l]=1;
    						new_switches.add(new_array);
    					}
    					switches.addAll(new_switches);	
    				}
    				else if (sum_init == sum_goal){
    					for (int[] array : switches)
    						array[l]=0;
    				}
    				else if (sum_goal == N-sum_init){
    					for (int[] array : switches)
    						array[l]=1;
    				}
    				else{ 
    					System.out.println("Case #"+(i+1)+": NOT POSSIBLE");	
    					possible = false;
    					break;
    				}
    			}
    			
    			if (possible){
    				int min = -1;
    				for (int[] solution : switches){
    					String[] outlets = initial.clone();
	    				for (int l=0;l<L;l++){
	    					if (solution[l]==1)
	    						switchOne(outlets,l);
	    				}
	    				Arrays.sort(outlets);
	    				if (Arrays.equals(outlets,goal)){
	    					int sum = sumOf(solution);
	    					if (sum < min || min==-1)
	    						min = sum;
	    				}
    				}
    				if (min>-1)
    					System.out.println("Case #"+(i+1)+": " + min);
    				else
    					System.out.println("Case #"+(i+1)+": NOT POSSIBLE");
	    				
    			}
    					
    		}
    		
    	} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
    	finally{
    		if(sc != null) sc.close();
    		if(fr != null)	try {fr.close();} catch (Exception e) {}
    	}
       	

	}
	
	private static int sumOf(int[] switches) {
		int sum = 0;
		for(int i : switches){
			sum += i;
		}
		return sum;
	}

	public static int sumSwitch(String[] arr,int idx){
		int sum = 0;
		for (int i=0;i<N;i++){
			sum += Character.getNumericValue((arr[i]).charAt(idx));
		}
		
		return sum;
	
	}
	
	public static void switchOne(String[] arr,int idx){
		for (int i=0;i<N;i++){
			StringBuilder temp = new StringBuilder(arr[i]);
			temp.setCharAt(idx, (char) ('0' + (new Integer(arr[i].charAt(idx)+1) %2)));
			arr[i] = temp.toString();
		}
	}

}
