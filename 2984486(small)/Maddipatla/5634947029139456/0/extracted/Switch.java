package com.google;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Switch {

	public Switch() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		BufferedWriter out = null;
		Scanner scanner = null;
		try {
			String inputFileName = "A-small-attempt0.in";
			scanner = new Scanner(new FileInputStream("/Users/MSR/Downloads/"+inputFileName));
			out = new BufferedWriter(new FileWriter("/Users/MSR/Downloads/"+inputFileName+"_out"));
			int numTests = scanner.nextInt();
			for(int i=1;i<=numTests;i++){
				
				int noSwitches = scanner.nextInt();
				int switchLen = scanner.nextInt();
				String flows[] = new String[noSwitches];
				String devices[] = new String[noSwitches];
				for(int p=0;p<noSwitches;p++){
					flows[p] = scanner.next();
				}
				for(int q=0;q<noSwitches;q++){
					devices[q] = scanner.next();
				}
				Arrays.sort(flows);
				Arrays.sort(devices);
				String[] originalFlows = Arrays.copyOf(flows, noSwitches) ;
				int count = 0;
				boolean found = false;
				boolean firstFound = false;
				int max = 1;
				int si=0;
				while(si<switchLen){
					max = max * 2;
					si++;
				}
				int[] minCases = new int[max];
				for(int m=0;m<max;m++){
					minCases[m] = 4000000;
				}
				if(!Arrays.equals(flows, devices)){
				   
					for(int k=0;k<max;k++){
						flows = Arrays.copyOf(originalFlows, noSwitches) ;
						count = 0;
						String binaryM =  Integer.toBinaryString(k);
						while(binaryM.length() < switchLen){
							binaryM = "0"+binaryM;
						}
						char[] binChar = binaryM.toCharArray();
						for(int p=0; p<switchLen;p++){
							char binC = binChar[p];
							if(binC == '1'){
								count++;
								for(int j=0;j<noSwitches;j++){
									char[] s = flows[j].toCharArray();
									if(s[p] == '0')
										s[p] = '1';
									else 
										s[p] = '0';
									flows[j] = new String(s);
									
								}

							}
						}
						Arrays.sort(flows);
						if(Arrays.equals(flows, devices)){
							found = true;
							minCases[k]= count;
						}
						
					}
					
					
				} else {
					firstFound = true;
				}
				
				
				out.write("Case #"+i+": ");
				if(firstFound){
					out.write(0+"");
				}
				else if(found){
					Arrays.sort(minCases);
					out.write(minCases[0]+"");
				} else {
					out.write("NOT POSSIBLE");
				}
				out.write("\n");
				out.flush();
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally{
			try {
				scanner.close();
				out.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	
	}
	
	

}
