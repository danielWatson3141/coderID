import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Random;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	static int bin1(long n){//求n二进制1的个数
		n=(n&0X55555555)+((n>>1)&0X55555555);
		n=(n&0X33333333)+((n>>2)&0X33333333);
		n=(n&0X0f0f0f0f)+((n>>4)&0X0f0f0f0f);
		n=(n&0X00ff00ff)+((n>>8)&0X00ff00ff);
		n=(n&0X0000ffff)+((n>>16)&0X0000ffff);
		return (int)n;
	}
	public static void main(String arg0[])throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter( new BufferedWriter(new FileWriter("test.out")));
		 int casen;
		 Scanner in=new Scanner(f);
		 long c[]=new long[60];
		 //System.out.println("asd");
		 c[0]=1;
		 for (int i=1;i<60;i++) c[i]=c[i-1]*2;
		 casen=in.nextInt();
		   for (int casei=0;casei<casen;casei++){
			   HashMap<Long, Integer> gg=new HashMap<Long, Integer> ();
		        int n,m;  n=in.nextInt();m=in.nextInt();
		        String[] a=new String[n];	
		        long [] aa=new long[n];
		        String[] b=new String[n];
		        long [] bb=new long[n];
		        for (int i=0;i<n;i++){
		        	a[i]=in.next();
		        	aa[i]=Long.valueOf(a[i], 2);
		        }
		        for (int i=0;i<n;i++){
		        	b[i]=in.next();
		        	bb[i]=Long.valueOf(b[i], 2);
		        }
		        for (int i=0;i<n;i++){
		        	for (int j=0;j<n;j++){
		        		long s=0;
		        		for (int k=0;k<m;k++){
		        			
		        			if (a[i].charAt(k)==b[j].charAt(k)){
		        				s=s+c[k];
		        			}
		        			
		        		}
		        		if (gg.containsKey(s)){
		        			gg.put(s, gg.get(s)+1);
		        		}else{
		        			gg.put(s, 1);
		        		}
		        	}
		        }
		        Iterator<Long> it=gg.keySet().iterator();
		        int ans=1000000;
		      
		        HashMap<Long, Integer> ss=new HashMap<Long, Integer> ();
		        for (int i=0;i<n;i++){
		        	if (ss.containsKey(bb[i])){
	        			ss.put(bb[i], ss.get(bb[i])+1);
	        		}else{
	        			ss.put(bb[i], 1);
	        		}
		        }
		        while (it.hasNext()){
		        	  HashMap<Long, Integer> tt=new HashMap<Long, Integer> ();
		        	long tmp=it.next();
		        	//System.out.println(tmp);
		        	for (int i=0;i<n;i++){
		        		long tm=tmp^aa[i];
		        		if (tt.containsKey(tm)){
		        			tt.put(tm, tt.get(tm)+1);
		        		}else{
		        			tt.put(tm, 1);
		        		}
		        	}
		        	 Iterator<Long> itt=ss.keySet().iterator();
		        	 boolean tell=true;
		        	 while (itt.hasNext()){
		        		 long jjj=itt.next();
		        		// System.out.println(jjj+" is jjj");
		        		 if (tt.containsKey(jjj)&&tt.get(jjj)==ss.get(jjj)){
		        			 
		        		 }else {
		        			 tell=false;break;
		        		 }
		        	 }
		        	 if (tell) ans=Math.min(ans, bin1(tmp));
		        	
		        }
		        out.print("Case #"+(casei+1)+": ");
		        if (ans==1000000){
		        	out.println("NOT POSSIBLE");
		        }else{
		        	out.println(ans);
		        }
		   }
		   out.close();
	}
}
