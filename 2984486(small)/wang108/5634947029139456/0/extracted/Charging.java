import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


public class Charging {

	long[] map;
	int[] sum1;
	int[] sum2;
	int n,l;
	Set<Long> set;
	int ans;
	
	boolean check2(){
		for ( int i = 0 ; i < n ; i++ )
			if ( !set.contains(map[i])  ){
				return false;
			}
		return true;
	}
	
	void search( int index, int flip ){
		if ( ans >= 0 )
			return;
		if ( index == l ){
			if ( check2() ){
				ans = flip;
			}
			return;
		}
		if ( sum1[index] == sum2[index] ){
			search(index+1, flip);
			if ( sum1[index] == n-sum2[index] ){
				for ( int i = 0 ; i < n ; i++ )
					map[i] ^= 1<<index;
				search( index+1, flip+1 );
				for ( int i = 0 ; i < n ; i++ )
					map[i] ^= 1<<index;
			}
		}
		else {
			if ( sum1[index] != n-sum2[index] )
				return;
			for ( int i = 0 ; i < n ; i++ )
				map[i] ^= 1<<index;
			search( index+1, flip+1 );
			for ( int i = 0 ; i < n ; i++ )
				map[i] ^= 1<<index;
		}
	}
	
	void search2( int index, int flip ){
		if ( index == l ){
			if ( check2() ){
				if ( ans == -1 || flip < ans )
					ans = flip;
			}
			return;
		}
		search2(index+1, flip);
		
		for ( int i = 0 ; i < n ; i++ )
			map[i] ^= 1<<index;
		
		search2( index+1, flip+1 );
		
		for ( int i = 0 ; i < n ; i++ )
			map[i] ^= 1<<index;

	}
	
	public void charge() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			n = sc.nextInt();
			l = sc.nextInt();
			int i, j;
			String str;
			set = new HashSet<Long>();
			map = new long[n];			
			sum1 = new int[l];
			sum2 = new int[l];
			for ( i = 0 ; i < n ; i++ ){
				str = sc.next();
				for ( j = 0 ; j < l ; j++ ){
					char c = str.charAt(j);
					if ( c == '1' ){
						map[i] ^= 1<<j;
						sum1[j]++;
					}
				}
			}
			
			for ( i = 0 ; i < n ; i++ ){
				str = sc.next();
				long x = 0;
				for ( j = 0 ; j < l ; j++ ){
					char c = str.charAt(j);
					if ( c == '1' ){
						x ^= 1 << j;
						sum2[j]++;
					}
				}
				set.add(x);
			}

			
			bw.write("Case #" + z + ": ");
			ans = -1;
			search2(0, 0);
			if ( ans == -1 )
				bw.write("NOT POSSIBLE");
			else bw.write(""+ans);
			bw.write("\n");
		}
		bw.close();
		sc.close();
	}
	
	public static void main( String[] args ) throws IOException{
		(new Charging()).charge();
	}
}
