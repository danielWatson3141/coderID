import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;


public class OR1A2014P2 {

	static int[] x;
	static int[] a;
	static int[] b;
	static int n;
	static int res;
	
	public static void checkResult(){
		int[] children = new int[n];
		for (int i=0; i<n-1; i++){
			if (x[a[i]-1] == 1 && x[b[i]-1]==1){
				children[a[i]-1]++;
				children[b[i]-1]++;
			}
		}
		int twochildren = 0;
		int nochildren = 0;
		
		int cnt=0;
		boolean morechildren=false;
		for (int i=0; i<n; i++){
			if (x[i]==1){
				cnt++;
				if (children[i]==2){
					twochildren++;
				}
				if (children[i]==0){
					nochildren++;
				}
				if (children[i]>3){
					morechildren=true;
				}
			}
		}
		cnt = n - cnt;
		if ((nochildren == 1 && cnt==n-1) || (nochildren==0 && twochildren==1 && morechildren == false))
			if (cnt < res){
				res = cnt;
				/*
				for (int i=0; i<n; i++)
					System.out.print(x[i]);
					System.out.println();
				*/
			}
	}
	
	public static void find(int i){
		for (int j=0; j<=1; j++){
			x[i] = j;
			if (i==n-1){
				checkResult();
			} else
				find(i+1);
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args)throws FileNotFoundException, UnsupportedEncodingException {
		// TODO Auto-generated method stub
		String INPUT = "B-small-attempt0.in";
		String OUTPUT = "B-small-attempt0.out";
		File file = new File(INPUT);
	
		PrintWriter writer = new PrintWriter(OUTPUT, "UTF-8");
			
		Scanner sc = new Scanner(file);
		int test = sc.nextInt();
	
		for (int testCase=1; testCase <= test; testCase++){
			n = sc.nextInt();
			a = new int[n-1];
			b = new int[n-1];
			x = new int[n];
			res = n;
			for (int i=0; i<n-1; i++){
				a[i] = sc.nextInt();
				b[i] = sc.nextInt();
			}
			find(0);
			
			writer.println("Case #" + testCase + ": " + res);
		}	
		
		writer.close();
	}

}
