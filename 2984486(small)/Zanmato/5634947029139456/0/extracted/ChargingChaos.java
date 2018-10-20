import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;


public class ChargingChaos {
	public static void main(String[] args) throws Exception{
		FileOutputStream fop = null;
		File file;
		BufferedReader br = new BufferedReader(new FileReader("c:\\A-small-attempt2.in"));
		//BufferedReader br = new BufferedReader(new FileReader("c:\\in.in"));
		try {
			file = new File("c:\\A-small-attempt2.out");
			//file = new File("c:\\out.out");
			fop = new FileOutputStream(file);
		
			int testcase = Integer.parseInt(br.readLine());
			
			for(int i=0;i<testcase;i++){
				String[] params = br.readLine().split(" ");
				int N = Integer.parseInt(params[0]);
				int L = Integer.parseInt(params[1]);
				
				List<String> devices = new ArrayList<String>();
				List<String> outlets = new ArrayList<String>();
				
				String[] nStr = br.readLine().split(" ");
				String[] lStr = br.readLine().split(" ");
				for(int j=0;j<N;j++){
					devices.add(nStr[j]);
					outlets.add(lStr[j]);
				}
				
				int ans = countAns(devices, outlets, 0, L);
				
				String out = "Case #"+(i+1)+": "+(ans<0?"NOT POSSIBLE":ans)+"\n";
				System.out.print(out);
				byte[] contentInBytes = out.getBytes();
				fop.write(contentInBytes);
			}
		} finally {
	        br.close();
	        fop.flush();
			fop.close();
	    }
	}
	
	private static int countAns(List<String> devices, List<String> outlets, int digit, int L){
		if(digit==L) return 0;
		
		List<String> ds = new ArrayList<String>(devices);
		List<String> os = new ArrayList<String>(outlets);
		
		int ans = 0;
		int ans2 = -1;
		if(checkDigit(devices, outlets, digit)){
			flip(os, digit);
			if(checkDigit(ds, os, digit)){
				ans2 = ans + 1 + countAns(ds, os, digit+1, L);
			}
			ans += countAns(devices, outlets, digit+1, L);
		}
		else{
			flip(outlets, digit);
			if(!checkDigit(devices, outlets, digit)){
				ans = -L;
			}
			else{
				ans += 1 + countAns(devices, outlets, digit+1, L);
			}
		}

		if(ans>0 && ans2>0){
			ans = ans<ans2?ans:ans2;
		}
		else if(ans<0 && ans2>0){
			ans = ans2;
		}
		else if(ans<0 && ans2<0){
			ans = ans<ans2?ans:ans2;
		}
		
		return ans;
	}
	
	private static boolean checkDigit(List<String> devices, List<String> outlets, int digit){
		Set<String> ds = new TreeSet<String>();
		Set<String> os = new TreeSet<String>();
		for(int i=0;i<devices.size();i++){
			String d = devices.get(i);
			String o = outlets.get(i);
			
			ds.add(d.substring(0,digit+1));
			os.add(o.substring(0,digit+1));
		}
		
		if(ds.containsAll(os)){
			return true;
		}
		else{
			return false;
		}
	}
	
	private static void flip(List<String> outlets, int digit){
		for(int i=0;i<outlets.size();i++){
			String str = outlets.get(i);
			String result = "";
			
			if(digit>0){
				result = str.substring(0,digit); 
			}
			result += (str.charAt(digit)=='0'?"1":"0");
			if(digit<str.length()){
				result += str.substring(digit+1);
			}
			
			
			outlets.set(i, result);
		}
	}
}
