import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Random;

public class Two {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(
					System.in));
			int ntest = Integer.parseInt(br.readLine());
			int[] res = new int[ntest];


			ArrayList<ArrayList<Integer>> inpl = new ArrayList<ArrayList<Integer>>();
			for (int p = 0; p < ntest; p++) {

				int n = Integer.parseInt(br.readLine());
				String[] in = br.readLine().split(" ");
				ArrayList<Integer> input = new ArrayList<Integer>();

				for (int i = 0; i < n; i++) {
					input.add(Integer.parseInt(in[i]));
				}

				inpl.add(input);			

			}			
			
			for (int h = 0; h < inpl.size(); h++) {
				
				if( inpl.get(h).equals(badAlgo())){
					//System.out.println("BAD");
					res[h] = 1;
				}
			}
			print(120,res);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static ArrayList<Integer> badAlgo(){
		ArrayList<Integer> gen = new ArrayList<Integer>();
		
		for(int k=0; k<1000; k++){
			gen.add(k);
		}
		for(int k=0; k<1000; k++){
			
			Random r = new Random();
			for (int i = 0; i < 1000; i++) {
				int el = gen.get(k);
				int j = r.nextInt(1000);
				int ex = gen.get(j);
				gen.set(j, el);
				gen.set(k, ex);
			}			
		}
		
		return gen;
	}
	
	public static  void print(int ntest, int res[]) {
		for (int p = 0; p < ntest; p++) {
			int c = p + 1;
			if(res[p] == 0) {
				System.out.println("Case #" + c + ": GOOD");
			}else{
				System.out.println("Case #" + c + ": BAD");
			}
			
		}
	}
}
