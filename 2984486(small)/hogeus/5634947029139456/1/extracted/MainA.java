package gcj;
import static java.lang.Math.*; 
import static java.util.Collections.*; 

import java.math.*; 
import java.util.*; 
import java.io.BufferedReader;
import java.io.FileReader;


public class Main {
	
	public static boolean compare(ArrayList<String> l1, ArrayList<String> l2) {		
		sort(l1);
		sort(l2);		
		for(int j=0; j<min(l1.size(), l2.size()); j++) {
			if(!l1.get(j).equals(l2.get(j))) return false;
		}
		return true;		
	}
	
	static int changes = 0;
	public static String getCode(String outlet, String device) {
		String code = "";
		changes = 0;
 		for(int i=0; i<outlet.length(); i++) {
 			if(outlet.charAt(i) == device.charAt(i)) code += "0";
 			else {
 				changes++;
 				code += "1"; 			
 			}
 		}
		return code;				
	}
	
	public static String convert(String outlet, String code) {
		String res = "";		
 		for(int i=0; i<code.length(); i++) {
 			if(code.charAt(i) == '0') res += outlet.charAt(i); 			
 			else {
 				if(outlet.charAt(i) == '0') res += '1';
 				else res += '0'; 				
 			}		
 		}
		return res;				
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input"));
		
		int cases = Integer.parseInt(in.readLine().trim());
		
		for(int i=1; i<=cases; i++) {
			String[] ctrl = in.readLine().split(" ");
			int N = Integer.parseInt(ctrl[0]);
			int L = Integer.parseInt(ctrl[1]);
			
			String[] outlet = in.readLine().split(" ");
			String[] device = in.readLine().split(" ");
			
			ArrayList<String> outlets = new ArrayList<String>();
			ArrayList<String> devices = new ArrayList<String>();
			
			for(String o : outlet) outlets.add(o);
			for(String d : device) devices.add(d);
			
			sort(outlets);
			sort(devices);
			
			int mnn = Integer.MAX_VALUE;
			
			for(int o=0; o<outlets.size(); o++) {
				
				for(int d=0; d<devices.size(); d++) {
					
					// match o to d
					
					String code = getCode(outlets.get(o), devices.get(d));
					
					
					ArrayList<String> newOutlets = new ArrayList<String>();
					
					for(String out : outlets) {
						newOutlets.add( convert(out, code) ) ;						
					}
			
					if(compare(newOutlets, devices)) {
						mnn = min(mnn, changes);
					}
				}
				
			}
			
			if(mnn == Integer.MAX_VALUE)	
				System.out.println("Case #" + i + ": NOT POSSIBLE");
			else
				System.out.println("Case #" + i + ": " + mnn);
			//if(outlets.equals(devices)) System.out.println(i + "," + 0);
			
			
			//System.out.println("Case #" + i + ": " + deceitScore + " " + warScore);
		}
		
		
		in.close();
	}
}
