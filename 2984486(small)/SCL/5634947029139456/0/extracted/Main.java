import java.util.*;
import java.io.*;

public class Main {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2014R1A/io/A-small-attempt0.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2014R1A/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int k = 0 ; k < T ; k++){
			String[] s = input.readLine().split(" ");
			int N = Integer.parseInt(s[0]);
			int L = Integer.parseInt(s[1]);
			String[] out = new String[N];
			String[] dev = new String[N];
			s = input.readLine().split(" ");
			for(int i = 0 ; i < N ; i++){
	        	out[i] = s[i];
			}
			s = input.readLine().split(" ");
			for(int i = 0 ; i < N ; i++){
	        	dev[i] = s[i];
			}
			int index = 0;
			int min = Integer.MAX_VALUE;
			while(true){
				String st = Integer.toBinaryString(index);
				if(st.length() > L)break;
				
				boolean[] devices = new boolean[N];
				
				int zeroinsert = L-st.length();
				String newst = "";
				for(int i = 0 ; i < zeroinsert ; i++){
					newst += "0";
				}
				newst += st;
				
				StringBuilder[] sb = new StringBuilder[N];
				for(int i = 0 ; i < N ; i++){
					sb[i] = new StringBuilder();
					sb[i].append(out[i]);
				}
				int onecount = 0;
				for(int i = 0 ; i < L ; i++){
					if(newst.charAt(i) == '1'){
						onecount++;
						for(int j = 0 ; j < N ; j++){
							if(sb[j].charAt(i) == '0'){
								sb[j].setCharAt(i, '1');
							}else{
								sb[j].setCharAt(i, '0');
							}
						}
					}
				}
				int count = 0;
				for(int i = 0 ; i < N ; i++){
					for(int j = 0 ; j < N ; j++){
						if(sb[i].toString().equals(dev[j])){
							count++;
							break;
						}
					}
				}
				if(count == N)min = Math.min(min,onecount);
				index++;
			}
			if(min == Integer.MAX_VALUE){
				pw.println("Case #"+(k+1)+": NOT POSSIBLE");
			}else{
				pw.println("Case #"+(k+1)+": "+min);
			}
			pw.flush();
		}
		input.close();
		pw.close();
	}
}