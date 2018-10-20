import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;


public class ProblemA {
	
	public static int getMin(String[] outlets, String[] targets){
		int res=0;
		for(int i=0; i<outlets[0].length(); i++){
			int num0o=0, num1o=0, num0t=0, num1t=0;
			for(int j=0; j<outlets.length; j++){
				if(outlets[j].charAt(i)=='0')
					num0o++;
				else
					num1o++;
				if(targets[j].charAt(i)=='0')
					num0t++;
				else
					num1t++;
			}
			if(num0o==num1t&&num0o!=num0t)
				res++;
			else if(num0o!=num0t && num0o!=num1t)
				return -1;
		}
		return res;
	}

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException{
		Scanner sc = new Scanner(new File("E:\\gcj\\data\\A-small-attempt1.in"));
//		Scanner sc = new Scanner(new File("E:\\gcj\\data\\test.txt"));
		PrintWriter writer = new PrintWriter("E:\\gcj\\data\\output.txt", "UTF-8");
		int T;
		T=sc.nextInt();
		for(int i=0; i<T; i++){
			int index = i+1;
			writer.print("Case #"+index+": ");
			int N=sc.nextInt();
			int L=sc.nextInt();
			String[] outlets=new String[N];
			String[] targets=new String[N];
			for(int j=0; j<N; j++){
				outlets[j]=sc.next();
			}
			for(int j=0; j<N; j++){
				targets[j]=sc.next();
			}
			int res=getMin(outlets, targets);
			if(res==-1)
				writer.println("NOT POSSIBLE");
			else
				writer.println(res);
		}
		sc.close();
		writer.close();
	}
}
