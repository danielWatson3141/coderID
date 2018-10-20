import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;

public class R1AASmall {

	public static void main(String[] args) {
		if (args.length < 1) {
			System.exit(1);
		}
		new R1AASmall().solve(args[0]);
	}

	public void solve(String inputFileName) {
		try {
			BufferedReader in = new BufferedReader(
					new FileReader(inputFileName));
			int number_of_cases = Integer.parseInt(in.readLine());
			for (int i = 1; i <= number_of_cases; i++) {
				String [] numbers = in.readLine().split(" ");
				SmartOutlets smo = new SmartOutlets(
						Integer.parseInt(numbers[0]),
						Integer.parseInt(numbers[1]),
						in.readLine(), 
						in.readLine());
				System.out.printf("Case #%d: %s\n", i, smo.answer());				
			}
			in.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	class SmartOutlets{
		private int N;
		private int L;
		private String [] fromConfig;
		private String [] toConfig;
		public SmartOutlets(int num, int len, String fromConfigStr, String toConfigStr){
			N = num;
			L =len;
			fromConfig = fromConfigStr.split(" ");
			toConfig = toConfigStr.split(" ");
			Arrays.sort(toConfig);
		}
		
		private boolean testConfig(String [] config){
			Arrays.sort(config);
			for(int i=0; i<N;i++){
				if( !config[i].equals(toConfig[i]) )
					return false;
			}
			return true;
		}
		
		private String [] applyMask(String mask){
			String [] ret = new String [N];
			for (int i=0; i<N; i++){
				StringBuffer buf = new StringBuffer(fromConfig[i]);
				for (int j=0;j<L;j++){
					if(mask.charAt(j) == '1'){
						if (buf.charAt(j) =='1'){
							buf.setCharAt(j, '0');
						}else{
							buf.setCharAt(j, '1');
						}
					}
				}
				ret[i] = buf.toString();
			}
			return ret;
		}
		private int countFlip(String mask){
			int cnt =0;
			for(int i=0; i < L; i++){
				if (mask.charAt(i) =='1'){
					cnt++;
				}
			}
			return cnt;
		}
				
		public String answer(){
			if(testConfig(fromConfig)){
				return "0";
			}
			List<String> masks = new ArrayList<String>();
			for(int i=1, sz = 1<<L; i< sz; i++){
				StringBuilder str = new StringBuilder();
				String bin = Integer.toBinaryString(i);
				for (int j=0;j<L-bin.length(); j++)
					str.append('0');
				str.append(bin);
				masks.add(str.toString());
			}
			Collections.sort(masks,new Comparator<String>() {
				@Override
				public int compare(String o1, String o2) {
					// TODO Auto-generated method stub
					return countFlip(o1) - countFlip(o2);
				}
			});
			for(String m:masks){
				if (testConfig(applyMask(m))){
					return Integer.toString(countFlip(m));
				}
			}
			return "NOT POSSIBLE";
		}	
	}

}
