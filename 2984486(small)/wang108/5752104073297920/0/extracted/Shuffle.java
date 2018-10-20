import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Shuffle {

	public void shuffle() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int n = sc.nextInt();
			int[] map = new int[n];
			int i;
			int k = 0;
			int q;
			double ans = 0;
			int lo = 2;
			for ( i = 0 ; i < n ; i++ )
				map[i] = sc.nextInt();
			for ( q = n/2 ; q > 1 ; q/=2 ){
				k = 0;
				for ( i = 0 ; i < q ; i++ ){
					if ( map[i] < q  )
						k++;
				}
				if ( k*1.0/n > q*0.5/n  )
					ans += 1.0/lo;
				else ans -= 1.0/lo;
				lo *= 2;
			}
			bw.write("Case #" + z + ": ");
			if ( ans > 0 )
				bw.write("BAD");
			else bw.write("GOOD");
			bw.write("\n");
		}
		bw.close();
		sc.close();
	}

	
	public static void main( String[] args ) throws IOException{
		(new Shuffle()).shuffle();
	}
}
