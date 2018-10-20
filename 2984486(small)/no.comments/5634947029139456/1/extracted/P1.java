import java.io.*;
import java.util.*;
public class P1
{
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File("A-large.in"));
		PrintWriter p = new PrintWriter("A-large.out");
		int numCases = in.nextInt();
		for(int caseNo = 1; caseNo <= numCases; caseNo++){
			int n = in.nextInt();
			int l = in.nextInt();
			long[] outlets = new long[n];
			long[] configurations = new long[n];
			ArrayList<Long> possibleShifts = new ArrayList<Long>();
			for(int i = 0; i < n; i++){
				outlets[i] = strToLong(in.next());
			}
			for(int i = 0; i < n; i++){
				configurations[i] = strToLong(in.next());
				possibleShifts.add(outlets[0]^configurations[i]);
			}
			for(int i = 1; i < n; i++){
				ArrayList<Long> newShifts = new ArrayList<Long>();
				for(int j = 0; j < n; j++){
					if(possibleShifts.contains(outlets[i]^configurations[j])){
						newShifts.add(outlets[i]^configurations[j]);
					}
				}
				possibleShifts = newShifts;
			}
			if(possibleShifts.size()==0)p.printf("Case #%d: NOT POSSIBLE%n", caseNo);
			else{
				int minCount = countBits(possibleShifts.get(0));
				for(int j = 1; j < possibleShifts.size(); j++){
					int k = countBits(possibleShifts.get(j));
					if(k < minCount)
						minCount = k;
				}
				p.printf("Case #%d: %d%n", caseNo, minCount);
			}
		}
		in.close();
		p.close();
	}
	static long strToLong(String s){
		long r = 0;
		long b = 1;
		for(int i = s.length()-1; i>=0; i--){
			if(s.charAt(i)=='1')r+=b;
			b*=2;
		}
		return r;
	}
	static int countBits(Long l){
		int count = 0;
		while(l!=0){
			count += l%2;
			l/=2;
		}
		return count;
	}
}
