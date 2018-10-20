import java.math.BigInteger;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;


public class Main3 {

	static int countSetBits(BigInteger n)
	{
	  int count = 0;
	  while(n.compareTo(new BigInteger("0")) > 0)
	  {
	    count += n.and(new BigInteger("1")).intValue();
	    n = n.shiftRight(1);
	  }
	  return count;
	}
	 
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int numT = sc.nextInt();
		
		
		for(int xx = 1 ; xx<=numT;xx++){
			int N = sc.nextInt();
			int L = sc.nextInt();
			
			BigInteger [] start = new BigInteger[N];
			BigInteger [] end = new BigInteger[N];
			
			for(int i = 0 ; i < N ; i ++){
				start[i] = new BigInteger(sc.next() , 2);
			}
			
			for(int i = 0 ; i < N ; i ++){
				end[i] = new BigInteger(sc.next() , 2);
			}			

			BigInteger matrix [][] = new BigInteger[N][N];
			
			for(int i = 0 ; i < N ; i ++){
				for(int j = 0 ; j < N ; j++){
					matrix[i][j] = (start[i].xor(end[j]));
				}
			}
			
			
			boolean visited[] = new boolean[N];
			BigInteger cur = null;

			LinkedList<BigInteger> list = new LinkedList<BigInteger>();
			for(int k = 0 ; k < N ; k ++){
				Arrays.fill(visited, false);
				cur = matrix[0][k];
				visited[k] = true;
				int i ;
				for(i = 1 ; i < N ; i ++){
					boolean found = false;
					for(int j = 0 ; j < N ; j++){
						if(cur .equals( matrix[i][j]) && !visited[j]){
							found = true;
							visited[j] = true;
							break;
						}
					}
					if(!found)
						break;
				}
				if(i == N){
					list.add(cur);
				}
			}
			
			System.out.print("Case #" + xx + ": ");
			
			
			if(list.size() > 0){
				int []x = new int[list.size()];
				for(int i = 0 ; i < x.length ; i ++){
					x[i] = countSetBits(list.get(i));
				}
				Arrays.sort(x);
				System.out.println(x[0]);
			}
				
			else
				System.out.println("NOT POSSIBLE");
			
		}
		
		
	}
}
