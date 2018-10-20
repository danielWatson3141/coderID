import java.util.*;
import java.io.*;
public class C {
	
	public static void main(String[] args)throws IOException {
		
		//Scanner qwe = new Scanner(System.in);
		Scanner qwe = new Scanner(new File("c.in"));
		PrintWriter out = new PrintWriter("c.out");
		
		int T = qwe.nextInt();
		
		for(int cse = 1; cse <= T; cse++){
			int N = qwe.nextInt();
			int[] nums = new int[N];
			for (int i = 0; i < nums.length; i++) {
				nums[i] = qwe.nextInt();
			}
			
			long sum = 0;
			long dis = 0;
			
			for(int a = 0; a < N; a++){
				dis += Math.abs(a-nums[a]);
				for(int b = a+1; b < N; b++){
					if(nums[a] > nums[b]) sum++;
				}
			}
			
			if(sum > 245000 && dis > 327200)
				out.printf("Case #%d: GOOD\n",cse);
			else if(sum < 245000 && dis < 327200)
				out.printf("Case #%d: BAD\n",cse);
			else{
				if(sum % 2 == 0){
					out.printf("Case #%d: GOOD\n",cse);
				}
				else out.printf("Case #%d: BAD\n",cse);
			}
		}
		
		qwe.close();
		out.close();
	}

}
