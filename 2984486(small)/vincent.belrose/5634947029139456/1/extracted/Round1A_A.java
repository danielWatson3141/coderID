import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Locale;
import java.util.Scanner;


public class Round1A_A {


	String round="Round_1A";
	String exercice="A";

	// global var
	int N,L;
	String[] outlet,device;
	long[] boutlet;
	long[] bdevice;
	
	void log(Object s) {
	//	System.out.println(s);
	}
	
	void info(String s) {
		System.out.println(s);
	}
	
	void error(String s) {
		System.out.println(s);
	}

	int countOnes(String x){
		int res=0;
		for (int i=0;i<L;i++){
			if (x.charAt(i)=='1')
				res++;
		}
		return res;
	}
	
	int countOnes(long x){
		int res=0;
		while (x>0){
			if (x%2==1)
				res++;
			x=x/2;
		}
		return res;
	}
	
	
	String update(String flow,String x){
		//log(L+" "+flow.length()+" "+x.length());

		String res="";
		for (int i=0;i<L;i++){
			if (x.charAt(i)=='1'){
				if (flow.charAt(i)=='0')
					res=res+'1';
				else
					res=res+'0';
			}
			else
				res=res+flow.charAt(i);
		}
		log("Update "+flow+" with "+x+" res:"+res);
		return res;
	}
	
	boolean check(String x){
		log("Trying "+x);
		String[] flow2=new String[N];
		for (int i=0;i<N;i++){
			flow2[i]=update(outlet[i],x);
			log(flow2[i]);
		}
		Arrays.sort(flow2);
		for (int i=0;i<N;i++){
			log("device:"+device[i]);
		}
		for (int i=0;i<N;i++){
			if (!flow2[i].equals(device[i]))
				return false;
		}
		return true;
	}
	
	int evaluate(String A, int index){
		if (index==L-1){
			int res=0;
			boolean ev1=check(A+"0");
			int count1=countOnes(A+"0");
			boolean ev2=check(A+"1");
			int count2=countOnes(A+"1");
			if ((!ev1) && (!ev2))
				return -1;
			if ((ev1)&&(ev2))
				return Math.min(count1,count2);
			if (ev1)
				return count1;
			if (ev2)
				return count2;
			error("zonx");
		}
		int res1=evaluate(A+"0",index+1);
		int res2=evaluate(A+"0",index+1);
		if ((res1==-1)&&(res2==-1))
			return -1;
		if ((res1>-1)&&(res2>-1))
			return Math.min(res1,res2);
		if (res1>-1)
			return res1;
		return res2;
	}

	
	String solveBourrin(){
		int res=evaluate("",0);
		if (res==-1)
			return "NOT POSSIBLE";
		else
			return ""+res;
	}
	
	String solveBin(){
		int res=L+1;
		long[] res1=new long[N];
		long[] res2=new long[N];
		for (int j=0;j<N;j++) 
			for (int k=0;k<N;k++) 
				
		{
			for (int i=0;i<N;i++){
				res1[i]=bdevice[i]^ bdevice[k];
				res2[i]=boutlet[i] ^boutlet[j];

			}
			Arrays.sort(res1);
			log("res1");
			for (int i=0;i<N;i++){
				log(Long.toBinaryString(res1[i]));
			}
			log("res2");
			Arrays.sort(res2);
			for (int i=0;i<N;i++){
				log(Long.toBinaryString(res2[i]));
			}

			boolean possible=true;
			for (int i=0;i<N;i++){
				if (res1[i]!=res2[i]) {
					possible=false;
					break;
				}
			}
			
			if (possible){
				log("Possible for "+j);
				long c=bdevice[k]^boutlet[j];
				
						int x=countOnes(c);
						if (x<res)
							res=x;

			}
		}
			if (res==L+1)
				return "NOT POSSIBLE";
			else
				return ""+res;


	}
	
	String solve(){
		return "";
		}



	void process() throws Exception {

	//	File inputFile=new File(round+"/test_"+exercice+".in");
	//	PrintWriter outputFile= new PrintWriter(round+"/test_"+exercice+".out","UTF-8");
	
	//		File inputFile=new File(round+"/vbTest.in");
	//	PrintWriter outputFile= new PrintWriter(round+"/vbTest","UTF-8");

	//		File inputFile=new File(round+"/"+exercice+"-small-attempt4.in");
	//		PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-small-attempt4.out","UTF-8");

		
		File inputFile=new File(round+"/"+exercice+"-large.in");
		PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large.out","UTF-8");


		Scanner scanner=new Scanner(inputFile);
		scanner.useLocale(Locale.US);
		int T = scanner.nextInt();
		System.out.println("Doing "+T+" cases");

		

		for (int t=1;t<=T;t++) {
	
			// do Something
			N=scanner.nextInt();
			L=scanner.nextInt();
			outlet=new String[N];
			device=new String[N];
			boutlet=new long[N];
			bdevice=new long[N];
			
			for (int i=0;i<N;i++){
				outlet[i]=scanner.next();
				boutlet[i]=Long.parseLong(outlet[i],2);
			}
			
			for (int i=0;i<N;i++){
				device[i]=scanner.next();
				bdevice[i]=Long.parseLong(device[i],2);
			}
			Arrays.sort(device);
			
			
			String ss=""+solveBin();
		
			System.out.println("Case #"+t+": "+ss);
			outputFile.println("Case #"+t+": "+ss);
			
		}
		scanner.close();
		outputFile.close();

	}



	public static void main(String[] args) throws Exception {
		Round1A_A J=new Round1A_A();
		J.process();
	}


}

