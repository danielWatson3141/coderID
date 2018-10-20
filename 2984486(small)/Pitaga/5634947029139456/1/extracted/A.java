import java.util.*;
import java.io.*;
public class A {
	
	public static void main(String[] args)throws IOException {
		
		//Scanner qwe = new Scanner(System.in);
		Scanner qwe = new Scanner(new File("a.in"));
		PrintWriter out = new PrintWriter("a.out");
		
		int T = qwe.nextInt();
		
		for(int cse = 1; cse <= T; cse++){
			int N = qwe.nextInt();
			int L = qwe.nextInt();
			
			boolean[] isSwap = new boolean[L];
			
			String[] outs = new String[N];
			for(int i =0; i < N; i++){
				outs[i] = qwe.next();
			}
			
			HashSet<String> devs = new HashSet<String>();
			for(int i =0; i < N; i++){
				devs.add(qwe.next());
			}
			
			int best = 987654321;
			
			for(String start : devs){
				
				int cont = 0;
				
				for(int i =0; i < L; i++){
					if(start.charAt(i) != outs[0].charAt(i)){
						cont++;
						isSwap[i] = true;
					}
					else isSwap[i] = false;
				}
				
				boolean good = true;
				
				for(String str : outs){
					
					char[] res = str.toCharArray();
					for(int i =0; i < L; i++)
						if(isSwap[i]){
							if(res[i] == '1')
								res[i] = '0';
							else res[i] = '1';
						}
					
					String result = String.valueOf(res);
					if(!devs.contains(result)){
						good = false;
						break;
					}
				}
				
				if(good) best = Math.min(best, cont);
				
			}
			
			if(best == 987654321)
				out.printf("Case #%d: NOT POSSIBLE\n",cse);
			else
				out.printf("Case #%d: %d\n",cse,best);
		}
		
		qwe.close();
		out.close();
	}

}
