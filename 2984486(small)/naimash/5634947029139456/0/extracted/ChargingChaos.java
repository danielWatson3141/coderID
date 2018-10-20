import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;


public class ChargingChaos {

	public static void main(String[] args) throws IOException {
		new ChargingChaos().go();
	}
	
//	String IN = "A.in";
//	String OUT = "A.out";
	String IN = "A-small-attempt0.in";
	String OUT = "A-small-attempt0.out";
	
	void go() throws IOException{
		Scanner scan = new Scanner(new File(IN));
		scan.useLocale(Locale.US);
		FileWriter wr = new FileWriter(OUT);
		int T = scan.nextInt();		
		System.out.println("T = " + T);		
		for(int t=1;t<=T;t++){
			int N = scan.nextInt();
			int L = scan.nextInt();
			List<String> out = new ArrayList<String>();
			List<String> dev = new ArrayList<String>();
			for (int i = 0; i < N; i++) {
				out.add(scan.next());
			}
			for (int i = 0; i < N; i++) {
				dev.add(scan.next());
			}
			int ans = calc(out,dev,0,0,L);
			debug("ans = " + ans);
			String res = ans != Integer.MAX_VALUE ? "" + ans : "NOT POSSIBLE";
			wr.append("Case #" + t + ": " + res + "\n");
			
//			debug(out);
//			debug(dev);
			
		}
		scan.close();
		wr.close();
		
	}
	
	int calc(List<String> out,List<String> dev,int step,int count,int L){
		String arr1[] = new String[out.size()];
		String arr2[] = new String[dev.size()];
		
		out.toArray(arr1);
		dev.toArray(arr2);
		Arrays.sort(arr1);
		Arrays.sort(arr2);
		boolean b = Arrays.deepEquals(arr1,arr2);
//		debug(out,"===",dev,b);
		if(b){
			return count;
		}
		if(step == L){
			return Integer.MAX_VALUE;
		}
		int min = Integer.MAX_VALUE;
		min = Math.min(min, calc(out,dev,step+1,count,L));
		
		List<String> tmp = new ArrayList<String>();
		for(String s : out){
			tmp.add(trans(s,step));
		}
		min = Math.min(min, calc(tmp,dev,step+1,count+1,L));
		
		return min;
	}
	
	String trans(String str,int index){
		char[] arr = str.toCharArray();
		arr[index] = arr[index] == '0' ? '1' : '0'; 	
		return new String(arr);
	}
	
	
	static void debug(Object... objs) {
		System.err.println(Arrays.deepToString(objs));
	}

}
