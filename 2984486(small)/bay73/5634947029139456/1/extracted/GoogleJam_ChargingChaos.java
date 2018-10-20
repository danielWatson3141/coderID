/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlejam;

import java.io.*;
import java.util.Arrays;

/**
 *
 * @author a.bogdanov
 */
public class GoogleJam_ChargingChaos {
    public static final String problemLetter = "A";
    
    private static String [] given;
    private static String [] required;
	private static int N;
	private static int L;

	static int check(int position){
    	Arrays.sort(given);
    	String groupPrefix = given[0].substring(0, position);
    	int groupGivenZeros = 0;
    	int groupGivenOnes = 0;
    	int groupRequireZeros = 0;
    	int groupRequireOnes = 0;
    	int needSwitch = -1;
    	for(int i=0;i<N;i++){
    		if(given[i].startsWith(groupPrefix)){
    			if(given[i].charAt(position)=='0'){
    				groupGivenZeros++;
    			}else{
    				groupGivenOnes++;
    			}
    			if(required[i].charAt(position)=='0'){
    				groupRequireZeros++;
    			}else{
    				groupRequireOnes++;
    			}
    		}else{
    			if(groupGivenZeros==groupRequireZeros && groupGivenZeros!=groupRequireOnes){
    				if(needSwitch==1){
    					return -2;
    				}else{
    					needSwitch=0;
    				}
    			}else if(groupGivenZeros!=groupRequireZeros && groupGivenZeros==groupRequireOnes){
    				if(needSwitch==0){
    					return -2;
    				}else{
    					needSwitch=1;
    				}
    			}else if(groupGivenZeros==groupRequireZeros && groupGivenZeros==groupRequireOnes){
    				
    			}else{
					return -2;
    			}
    			groupPrefix = given[i].substring(0, position); 
    	    	groupGivenZeros = 0;
    	    	groupGivenOnes = 0;
    	    	groupRequireZeros = 0;
    	    	groupRequireOnes = 0;
    			if(given[i].charAt(position)=='0'){
    				groupGivenZeros++;
    			}else{
    				groupGivenOnes++;
    			}
    			if(required[i].charAt(position)=='0'){
    				groupRequireZeros++;
    			}else{
    				groupRequireOnes++;
    			}
    		}
    	}
		if(groupGivenZeros==groupRequireZeros && groupGivenZeros!=groupRequireOnes){
			if(needSwitch==1){
				return -2;
			}else{
				needSwitch=0;
			}
		}else if(groupGivenZeros!=groupRequireZeros && groupGivenZeros==groupRequireOnes){
			if(needSwitch==0){
				return -2;
			}else{
				needSwitch=1;
			}
		}else if(groupGivenZeros==groupRequireZeros && groupGivenZeros==groupRequireOnes){
			
		}else{
			return -2;
		}
    	return needSwitch;
    }
	
	static void switchOne(int position){
    	for(int i=0;i<N;i++){
    		if(given[i].charAt(position)=='1'){
    			given[i] = given[i].substring(0, position) + "0" + given[i].substring(position + 1);  
    		}else{
    			given[i] = given[i].substring(0, position) + "1" + given[i].substring(position + 1);  
    		}
    	}
	}
	
	static int trySwitch(int position){
		if(position >= L){
			return 0;
		}
		int toSwitch = check(position);
		if(toSwitch==-2){
			return -1;
		} else if(toSwitch==0){
			return trySwitch(position + 1);
		}else if(toSwitch==1){
			switchOne(position);
			int next = trySwitch(position + 1);
			switchOne(position);
			if(next == -1)
				return -1;
			else
				return next + 1;
		}else{
			int next1 = trySwitch(position + 1);
			switchOne(position);
			int next2 = trySwitch(position + 1);
			switchOne(position);
			if(next1 == -1){
				if(next2 == -1) return -1;
				else return next2 + 1;
			}else{
				if(next2 == -1) return next1;
				else {
					if(next1 < next2 + 1) return next1;
					else return next2 + 1;
				}
			}
		}
	}
    
    public static void solve(BufferedReader reader, PrintWriter writer) throws IOException{
        int caseCount = Integer.parseInt(reader.readLine());
        for(int caseNum=1; caseNum<=caseCount; caseNum++){
            String[] str = reader.readLine().split(" ");
            N = Integer.parseInt(str[0]);
            L = Integer.parseInt(str[1]);
            given = reader.readLine().split(" ");
            required = reader.readLine().split(" ");
        	Arrays.sort(required);
        	int result = trySwitch(0);
        	if(result == -1){
        		System.out.println("Case #" + caseNum + ": NOT POSSIBLE");
        		writer.println("Case #" + caseNum + ": NOT POSSIBLE");
        	}else{
        		System.out.println("Case #" + caseNum + ": " + result);
        		writer.println("Case #" + caseNum + ": " + result);
        	}
            writer.flush();
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File folder = new File(".");
        for(final File entry:folder.listFiles()){
            if(entry.getName().endsWith(".in") && entry.getName().startsWith(problemLetter)){
                BufferedReader reader = new BufferedReader(new FileReader(entry));
                String fileOut = entry.getName().substring(0, entry.getName().length()-3) + ".out";
                System.out.println(entry.getName() + " -> " + fileOut);
                PrintWriter writer = new PrintWriter(fileOut);
                solve(reader, writer);
                reader.close();
                writer.close();
            }
        }
    }
    
}
