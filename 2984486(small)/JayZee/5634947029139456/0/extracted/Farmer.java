
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.*;

public class Farmer {


		public static void main(String args[]) throws Exception {
			
			try {
				BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
				int intCases=Integer.parseInt(br.readLine());
	            
				for(int intCase=1; intCase<=intCases; intCase++) {
					String[] strParams = br.readLine().split(" ");
					String strOutlets = br.readLine();
					String[] strDevices = br.readLine().split(" ");

					//int N = Integer.parseInt(strParams[0]);
					int L = Integer.parseInt(strParams[1]);
					int intFlips=0;
					
					while(intFlips<=L) {
						boolean boolResult = flipSwitches(intFlips, L, strOutlets, strDevices);
						if(boolResult==true) break;
						intFlips++;
					}
					
					System.out.print("Case #" + intCase + ": ");
					if(intFlips<=L) System.out.println(intFlips);
					else System.out.println("NOT POSSIBLE");
					
				}
				br.close();
			} catch(Exception e) {
				System.out.println(e.toString());
			}
		}
		
		private static boolean flipSwitches(int F, int L, String strOutlets, String[] strDevices) {
			//System.out.print("Flipping " + F + " switches: ");
			String flips="";
			
			double limit = Math.pow(2,  L);
			//System.out.println("Limit: " + limit);
			for(int count=0; count<limit; count++) {
				//if((int)(count/1000000)==count/1000000) System.out.println(count);
				flips = Integer.toBinaryString(count);
				// count the number of ones in the string
				int numOnes=0;
				for(int pos=0; pos<flips.length();pos++)
					if(flips.charAt(pos)=='1') numOnes++;				
				while(flips.length() < L) flips = "0".concat(flips);
				//System.out.print(" - flips: " + flips);
				if(numOnes==F) { // this is a candidate for flippage
					String[] strOutletTry = strOutlets.split(" ");
					for(int subCount=0; subCount<strOutletTry.length; subCount++) {
						strOutletTry[subCount] = flipBits(strOutletTry[subCount], flips);
					}
					if(compareFlow(strOutletTry, strDevices)==true) return true;
				}
				//System.out.println();
			}
			
			return false; // no valid combination found
		
		}

		private static String flipBits(String strBits, String strFlip) {
			String strResult="";
			for(int count=0; count<strFlip.length(); count++) {
				if(strFlip.charAt(count)=='1')
					if(strBits.charAt(count)=='0') strResult=strResult.concat("1");
					else strResult=strResult.concat("0");
				else
					strResult=strResult.concat(strBits.substring(count,count+1));
				
			}
			return strResult;
			
		}
		
		private static boolean compareFlow(String[] a, String[] b) {
			int outer;
			for(outer=0; outer<a.length; outer++) {
				boolean boolMatch=false;
				for(int inner=0; inner<b.length; inner++)
					if(a[outer].compareTo(b[inner])==0) { boolMatch=true; break; }
				if(boolMatch==false) break;
			}
			
			if(outer<a.length) return false;
			else return true;
		}
	
}
