package com.test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class CJ1A1 {
	private static int change2int(String str){
		int result = 0;
		for(int i = 0; i < str.length(); i++){
			result = result * 2 + (str.charAt(i) - '0');
		}
		return result;
	}
	
	private static boolean match(int[] arrayOrg, int[] arrayNew, int k){
		for(int i = 0; i < arrayOrg.length; i++){
			arrayOrg[i] = arrayOrg[i] ^ k;
		}
		Arrays.sort(arrayOrg);
		Arrays.sort(arrayNew);
		for(int i = 0; i < arrayOrg.length; i++){
			if(arrayOrg[i] != arrayNew[i]) return false;
		}
		return true;
	}
	
	private static int numBit(int num){
		int result = 0;
		while(num != 0){
			result += num % 2;
			num /= 2;
		}
		return result;
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("ans.txt"));
		int T = Integer.parseInt(br.readLine()); 
		for(int i = 0; i < T; i++){
			String[] tmp = br.readLine().split(" ");
			int N = Integer.parseInt(tmp[0]);
			int L = Integer.parseInt(tmp[1]);
			tmp = br.readLine().trim().split(" ");
			
			int[] arrayOrg = new int[tmp.length];
			int[] arrayNew = new int[tmp.length];
			for(int j = 0; j < tmp.length; j++){
				arrayOrg[j] = change2int(tmp[j]);
			}
			tmp = br.readLine().trim().split(" ");
			for(int j = 0; j < tmp.length; j++){
				arrayNew[j] = change2int(tmp[j]);
			}
			int ans = L+1;
			for(int k = 0; k < Math.pow(2, L); k++){
				if(match(Arrays.copyOf(arrayOrg, arrayOrg.length), Arrays.copyOf(arrayNew, arrayNew.length), k)){
					if( numBit(k) < ans){
						ans = numBit(k);
					}
				}
			}
			System.out.println(ans);
		
			if(ans == L+1){
				bw.write("Case #" + (i+1) + ": " + "NOT POSSIBLE\n");
			}
			else{
				bw.write("Case #" + (i+1) + ": " + ans +"\n");
			}

		}

		br.close();
		bw.close();
		
	}
}
