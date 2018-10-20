import java.io.FileReader;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.util.ArrayList;

public class InputParser {
	public static void main(String[] args) throws FileNotFoundException{
		Scanner inStream = new Scanner(new FileReader(args[0]));
		
		int cases = inStream.nextInt();
		int count = 0;
		
		while((inStream.hasNextLine()) && (count < cases)){
			if(count != 0){
				System.out.print("\n");
			}
			count++;
			System.out.print("Case #" + count + ": ");
			

			//Put in inStream reads here for each line
			int N = inStream.nextInt();
			int L = inStream.nextInt();
			
			ArrayList<String> initialFlow = new ArrayList<String>();
			ArrayList<String> reqFlow = new ArrayList<String>();
			
			for(int i = 0; i < N; i++){
				String s = inStream.next();
				initialFlow.add(s);
			}
			for(int i = 0; i < N; i++){
				String s = inStream.next();
				reqFlow.add(s);
			}
			
			
			// need to add the arguments for Problem here
			// Also change between ProblemA, ProblemB, ProblemC
			ProblemA ans = new ProblemA(N, L, initialFlow, reqFlow);
			int answer = ans.solve();
			if(answer == -1){
				System.out.print("NOT POSSIBLE");
			}else{
				System.out.print(answer);
			}
		}
		assert (count == cases);
		inStream.close();
		
		
		
	}
	

}