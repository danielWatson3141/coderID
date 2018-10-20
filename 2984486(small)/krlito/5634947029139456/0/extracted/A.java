import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Scanner;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		HashSet<Integer> dev = new HashSet<Integer>();
		Queue<Integer> q = new ArrayDeque<Integer>();
		
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(), out[] = new int[150];
		
		outer:
		for(int t=1; t<=T; t++)
		{
			int N = in.nextInt(), L = in.nextInt();
			
			dev.clear();
			for(int i=0; i<N; i++)
				dev.add(Integer.parseInt(in.next(), 2));
			
			for(int i=0; i<N; i++)
				out[i] = Integer.parseInt(in.next(), 2);
			
			q.clear();
			q.add(0);
			
			while(!q.isEmpty())
			{
				int i = 0, x = q.poll();
				
				for(i=0; i<N; i++)
					if(!dev.contains(out[i] ^ x))
						break;
				
				if(i==N)
				{
					int nbits = 0;
					while(x > 0)
					{
						if((x & 1) == 1) nbits++;
						x >>= 1;
					}
						
					System.out.println("Case #" + t + ": " + nbits);
					continue outer;
				}
				
				int y = 1;
				for(i=0; i<L; i++)
				{
					if((x & y) == 0)
						q.add(x | y);
					
					y <<= 1;
				}
			}
			
			System.out.println("Case #" + t + ": NOT POSSIBLE");
			
		}
		

	}

}
