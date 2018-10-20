import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class elec {
	public static void main (String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("A-large.in")));
		Integer n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			String dim = br.readLine();
			String[] out = br.readLine().split(" ");
			String[] dev = br.readLine().split(" ");
			
			ArrayList<ArrayList<Integer>> p = new ArrayList<ArrayList<Integer>>();
			
			for (int j = 0; j < dev.length; j++) {
				ArrayList<Integer> temp = new ArrayList<Integer>();
				for (int m = 0; m < out.length; m++) {
					int on = 0;
					for (int k = 0; k < dev[j].length(); k++) {
						if (dev[j].charAt(k) != out[m].charAt(k)) {
							on = (int) (on | (Math.round(Math.pow(2, k))));
						}
					}
					temp.add(on);
					//System.out.print(on + " ");
				}
				p.add(temp);
				//System.out.println();
			}
			//System.out.println();
			ArrayList<Integer> can = new ArrayList<Integer>();
			
		       for (Integer t : p.get(0)) {
		    	   boolean has = true;
		    	   for (int j = 1; j < p.size(); j++) {
		    		   has = has && p.get(j).contains(t);
		    	   }
		    	   if (has) {
		    		   can.add(t);
		    	   }
		        }
		       
		   if (can.size() == 0) {
			   System.out.println("Case #"+(i+1)+": NOT POSSIBLE");
		   } else {
			   int min = -1;
			   for (Integer t : can) {
				   int count = Integer.bitCount(t);
				   if (min == -1 || count < min) {
					   min = count;
				   }
				   
			   }
			   System.out.println("Case #"+(i+1)+": "+min);
		   }

			
		}
	}
}
