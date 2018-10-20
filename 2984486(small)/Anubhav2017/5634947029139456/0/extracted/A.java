package round_1A_2014;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int n,l;
		for (int i = 1; i <=T ; i++) {
			n = sc.nextInt();
			l = sc.nextInt();
			ArrayList<String> incomingFlow = new ArrayList<String>();
			ArrayList<String> neededFlow = new ArrayList<String>();
			for (int j = 0; j < n; j++) {
				incomingFlow.add(sc.next());
			}
			for (int j = 0; j < n; j++) {
				neededFlow.add(sc.next());
			}
			
			char[][] incomingA = new char[n][l];
			char[][] neededA = new char[n][l];
			for (int j = 0; j < n; j++) {
				incomingA[j] = incomingFlow.get(j).toCharArray();
			}
			
			for (int j = 0; j < n; j++) {
				neededA[j] = neededFlow.get(j).toCharArray();
			}
			boolean present = isPresent(incomingA, neededA, n, l);
			
			ArrayList<HashSet<Integer>> allSubSets = new ArrayList<HashSet<Integer>>();
			allSubSets.addAll(getallSubsets(l));
			int count = 999999;
			if(!present){
				char[][] temp = new char[n][l];
				for (int j = 0; j < allSubSets.size(); j++) {
					temp = new char[n][l];
					HashSet<Integer> temp1 = allSubSets.get(j);
					ArrayList<Integer> temp2 = new ArrayList<Integer>();
					temp2.addAll(temp1);
					for (int k = 0; k < n; k++) {
						for (int m = 0; m < l; m++) {
							temp[k][m]=incomingA[k][m];
						}
					}
					for (int k = 0; k < temp2.size(); k++) {
						temp = flip(temp,n,temp2.get(k));
						
					}
					if(isPresent(temp, neededA, n, l)){
						present = true;
						count = Math.min(count, temp2.size());
					}
				}
			}
			
			
			System.out.print("Case #"+i+": ");
			if(!present)
				System.out.print("NOT POSSIBLE");
			else
				System.out.print(count==999999?"0":count);
				
			/*ArrayList<String> nSwitches = new ArrayList<String>();
			for (int j = 0; j < l; j++) {
				String flow = new String();
				for (int k = 0; k < n; k++) {
					flow += incomingFlow.get(k).charAt(j);
				}
				nSwitches.add(flow);
			}
			
			ArrayList<String> neededSwitch = new ArrayList<String>();
			for (int j = 0; j < l; j++) {
				String flow = new String();
				for (int k = 0; k < n; k++) {
					flow += neededFlow.get(k).charAt(j);
				}
				neededSwitch.add(flow);
			}
			
			for (int j = 0; j <nSwitches.size() ; j++) {
				if(neededSwitch.contains(nSwitches.get(j)))
					{
					neededSwitch.remove(nSwitches.get(j));
					nSwitches.remove(j);
					j--;
					}
			}
			int count = 0;
			if(neededSwitch.size()>0)
			{
				for (int j = 0; j < nSwitches.size(); j++) {
					if(neededSwitch.contains(flipSwitch(nSwitches.get(j)))){
						count++;
						neededSwitch.remove(nSwitches.get(j));
						nSwitches.remove(j);
						j--;
						
					}
				}
			}
			System.out.print("Case #"+i+": ");
			if(neededSwitch.size()>0)
				System.out.print("NOT POSSIBLE");
			else
				System.out.print(count);
				*/
			System.out.println();
			
		}

	}
	
	
	public static String flipSwitch(String s){
		for (int i = 0; i < s.length(); i++) {
			if(s.charAt(i)=='0')
				{
				s=s.substring(0, i)+"1"+s.substring(i+1,s.length());
				continue;}
			if(s.charAt(i)=='1')
				{
				s=s.substring(0, i)+"0"+s.substring(i+1,s.length());
				continue;}
			
			
		}
		return s;
	}

	
	public static boolean isPresent(char[][] incomingA,char[][] neededA,int n,int r){
		boolean present = false;
		for (int j = 0; j < n; j++) {
			present = false;
			for (int k = 0; k < n; k++) {
				if(equal(incomingA[k],neededA[j],r)){
					present = true;
					
					
					break;
				}
			}
			if(!present)
				break;
		}
		return present;
		
		
		
	}
	
	public static boolean equal(char[] a,char[] b,int n){
		for (int i = 0; i < n; i++) {
			if(a[i]!=b[i])
				return false;
		}
		return true;
	}
	
	public static HashSet<HashSet<Integer>> getallSubsets(int n)
	{
		HashSet<HashSet<Integer>> allsubsets = new HashSet<HashSet<Integer>>();
		BigInteger end = new BigInteger(String.valueOf((int)Math.pow(2, n)));
		HashSet<Integer> temp;
		for (BigInteger i = BigInteger.ZERO;i.compareTo(end)!=1;i=i.add(BigInteger.ONE)) {
			String binary = "00000000000000000000000000000000000000000000"+i.toString(2);
			binary = binary.substring(binary.length()-n,binary.length());
			temp = new HashSet<Integer>();
			while(binary.indexOf('1')>-1){
			temp.add(binary.indexOf('1'));
			binary = binary.replaceFirst("1", "0");
			}
			if(temp.size()>0)
				allsubsets.add(temp);
		}
		return allsubsets;
		
	}
		
	public static char[][] flip(char[][] arr,int n,int j){
		for (int i = 0; i < n; i++) {
			if(arr[i][j]=='0'){
				arr[i][j]='1';
				continue;
			}
			if(arr[i][j]=='1'){
				arr[i][j]='0';
				continue;
			}
		}
		return arr;
	}
	
}
