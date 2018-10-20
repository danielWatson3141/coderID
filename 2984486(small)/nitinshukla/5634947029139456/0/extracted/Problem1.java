package com.nitin.ofss.codejam3;

import java.io.*;
import java.util.*;

public class Problem1 {
	static FileReader fr;
	static Scanner scan;
	static PrintWriter out;
	static int N,L;
	public static void main(String[] args) throws IOException {
		initialize();
		int T10 = scan.nextInt();
		
		for (int i10 = 1; i10 <= T10; i10++) {
			String ans="";
			N = scan.nextInt();
			L = scan.nextInt();
			String inp  = "";
			
			String[]  str1 = new String[N];
			
			String[]  str2 = new String[N];
			for(int i=0;i<N;i++)
				str1[i]=scan.next();
			for(int i=0;i<N;i++)
				str2[i]=scan.next();
			
			ans=getAns(str1,str2);
			
			
			
			
			
			
			out.printf("Case #%d: %s\n", i10,ans);
		}
		close();
	}

private static String getAns(String[] str1, String[] str2) {
				int ans= getAns1(str1,str2,0);
				if(ans>L) return "NOT POSSIBLE";
				else return String.valueOf(ans);
				//return null;
	}


private static int getAns1(String[] str1, String[] str2, int i) {
	if(i==L){
		Arrays.sort(str1);
		Arrays.sort(str2);
		for(int i1=0;i1<N;i1++) if(!str1[i1].equalsIgnoreCase(str2[i1])) return 100000;
		return 0;
	}
	int sum=getVal(str1,i);
	int sum1=getVal(str2,i);
	if(sum==sum1 && sum==N/2 && N%2==0){
		String[] str21=gets(str2,i);
		int max1=0;
		max1=Math.min(getAns1(str1, str2,i+1),1+getAns1(str1,str21,i+1));
		if(max1>=100000) return 100000;
		else return max1;
	}
	else if(sum==sum1){
		return getAns1(str1,str2,i+1);
	}
	else if(sum==N-sum1 || sum1==N-sum) {
		String[] str21=gets(str2,i);
		int max1=1+getAns1(str1,str21,i+1);
		if(max1>=100000) return 100000;
		else return max1;
	}
	else return 100000;
}

private static String[] gets(String[] str2, int i1) {
		String[] str1 = new String[str2.length];int cnt=0;
		System.arraycopy(str2, 0, str1, 0, str2.length);
		for(int i=0;i<str1.length;i++){
			if (str1[i].charAt(i1)=='0')
				str1[i]=str1[i].substring(0,i1)+str1[i].substring(i1, str1[i].length()).replaceFirst("0","1");
			else 				str1[i]=str1[i].substring(0,i1)+str1[i].substring(i1, str1[i].length()).replaceFirst("1","0");
		}
	return str1;
}

private static String getAns(String[] str1, String[] str2, int i) {
	int sum=getVal(str1,i);
	int sum1=getVal(str2,i);
	
	return null;
}

private static int getVal(String[] str2,int l) {
	int ret=0;	
	for(int i=0;i<N;i++)
		{
			if (str2[i].charAt(l)=='1') ret++;
		}
	return ret;
}

public static void initialize() throws FileNotFoundException{
	fr = new FileReader("in.txt");
	scan = new Scanner(fr);
	out = new PrintWriter("out.txt");
}
public static void close() throws IOException{
	fr.close();
	out.close();
	
}
}
