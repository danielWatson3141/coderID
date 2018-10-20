import java.io.*;
import java.util.*;

public class OR1A2014P1 {

	/**
	 * @param args
	 */
	public static void main(String[] args)throws FileNotFoundException, UnsupportedEncodingException {
		// TODO Auto-generated method stub
		String INPUT = "A-small-attempt1.in";
		String OUTPUT = "A-small-attempt1.out";
		
		//String INPUT = "input.txt";
		//String OUTPUT = "output.txt";
		
		File file = new File(INPUT);
	
		PrintWriter writer = new PrintWriter(OUTPUT, "UTF-8");
			
		Scanner sc = new Scanner(file);
		int test = sc.nextInt();
		
		ArrayList<String> outlets;
		ArrayList<String> devices;
		ArrayList<String> newOutlets;
		int n;
		int l;
		
		for (int testCase=1; testCase <= test; testCase++){
			n = sc.nextInt();
			l = sc.nextInt();
			int res = l+1;	
			outlets = new ArrayList<String>();
			devices = new ArrayList<String>();
			//newOutlets = new ArrayList<String>();
 			for (int i=0; i<n; i++){
 				outlets.add(sc.next());
 			}
 			for (int i=0; i<n; i++){
 				devices.add(sc.next());
 			}
 			Collections.sort(devices);
 			Collections.sort(outlets);
 			boolean[] flick;
 			for (int i=0; i<n; i++){
 				for (int j=0; j<n; j++){
 					flick = new boolean[l];
 					int cnt = 0;
 					newOutlets = new ArrayList<String>();
 					for (int u=0; u<l; u++){
 						flick[u] = false;
 					}
 					String outlet = outlets.get(i);
 					String device = devices.get(j);
 					for (int u = 0; u<l; u++){
 						if (outlet.charAt(u) != device.charAt(u)){
 							flick[u] = true;
 							cnt++;
 						}
 					}
 					newOutlets.addAll(outlets);
 					
 					for (int u=0; u<n; u++){
 						char[] tmpOutlet = newOutlets.get(u).toCharArray();
 						for (int v=0; v<l; v++){
 							if (flick[v]){
 								if (tmpOutlet[v] == '0'){
 									tmpOutlet[v] = '1';
 								} else
 									tmpOutlet[v] = '0';
 								newOutlets.set(u,String.valueOf(tmpOutlet));
 							}
 						}
 					}
 					
 					Collections.sort(newOutlets);
 					boolean check = true;
 					for (int u=0; u<n; u++){
 						if (!newOutlets.get(u).equals(devices.get(u))){
 							check = false;
 							break;
 						}
 					}
 					if (check){
 						if (cnt<res){
 							res = cnt;
 						}
 					}
 				}
 			}
 				
			writer.print("Case #" + testCase + ": ");
			if (res == l+1)
				writer.println("NOT POSSIBLE");
			else writer.println(res);
		}	
		
		writer.close();
	}

}
