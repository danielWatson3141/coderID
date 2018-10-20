import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;


public class Chaos {

	/**
	 * @param args
	 * @throws Exception 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader bufferRead = new BufferedReader(new FileReader("A-small-attempt0.in"));
    	//BufferedReader bufferRead = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new FileWriter("A-small.out"));

		int caseCnt = Integer.parseInt(bufferRead.readLine());

		for(int l=0; l<caseCnt; l++) {
			String[] caseData = bufferRead.readLine().split(" ");
			int N = Integer.parseInt(caseData[0]);
			int L = Integer.parseInt(caseData[1]);
			
			caseData = bufferRead.readLine().split(" ");
			Set<String> source = new HashSet<String>();
			for(int i=0; i<N; i++) {
				source.add(caseData[i]);
			}

			caseData = bufferRead.readLine().split(" ");
			Set<String> target = new HashSet<String>();
			for(int i=0; i<N; i++) {
				target.add(caseData[i]);
			}

			out.println("Case #"+(l+1)+": "+checkChaos(N, L, source, target));
		}

		out.close();
        bufferRead.close();
	}

	public static String checkChaos(int N, int L, Set<String> source, Set<String> target) {
		if(sourceHasTarget(target, source))
			return "0";

		for(long i=1; i<(2<<L); i++) {
			String mask = Long.toBinaryString(i);
			Set<String> newTarget = new HashSet<String>();
			int flipCount = flipSource(source, mask, newTarget);
			if(sourceHasTarget(target, newTarget)) {
				return String.valueOf(flipCount);
			}
		}

		return "NOT POSSIBLE";
	}

	public static int flipSource(Set<String> source, String mask, Set<String> target) {
		int flipped = 0;
		int toProcess = 0;

		for(String flow : source) {
			flipped = 0;
			toProcess = flow.length();
			StringBuilder newFlow = new StringBuilder(flow);
			for(int i=mask.length()-1; i>=0; i--) {
				if(toProcess <= 0)
					break;

				if(mask.charAt(i) == '1') {
					if(newFlow.charAt(toProcess-1) == '1')
						newFlow.setCharAt(toProcess-1, '0');
					else
						newFlow.setCharAt(toProcess-1, '1');
					flipped++;
				}
				toProcess--;
			}
			target.add(newFlow.toString());
		}
		
		return flipped;
	}
	
	public static boolean sourceHasTarget(Set<String> source, Set<String> target) {
		if(source.containsAll(target))
			return true;
		return false;
	}
}
