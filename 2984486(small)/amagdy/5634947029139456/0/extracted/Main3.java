import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;


public class Main3 {

	static int countSetBits(int n)
	{
	  int count = 0;
	  while(n > 0)
	  {
	    count += n & 1;
	    n >>= 1;
	  }
	  return count;
	}
	 
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int numT = sc.nextInt();
		
		
		for(int xx = 1 ; xx<=numT;xx++){
			int N = sc.nextInt();
			int L = sc.nextInt();
			
			int [] start = new int[N];
			int [] end = new int[N];
			
			for(int i = 0 ; i < N ; i ++){
				start[i] = sc.nextInt(2);
			}
			
			for(int i = 0 ; i < N ; i ++){
				end[i] = sc.nextInt(2);
			}			

			int matrix [][] = new int[N][N];
			
			for(int i = 0 ; i < N ; i ++){
				for(int j = 0 ; j < N ; j++){
					matrix[i][j] = (start[i] ^ end[j]);
				}
			}
			
			
			boolean visited[] = new boolean[N];
			int cur = 0;

			LinkedList<Integer> list = new LinkedList<Integer>();
			for(int k = 0 ; k < N ; k ++){
				Arrays.fill(visited, false);
				cur = matrix[0][k];
				visited[k] = true;
				int i ;
				for(i = 1 ; i < N ; i ++){
					boolean found = false;
					for(int j = 0 ; j < N ; j++){
						if(cur == matrix[i][j] && !visited[j]){
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
