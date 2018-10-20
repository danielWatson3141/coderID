
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;
import java.util.TreeMap;


public class Main {
	class pair{
		double x;
		int j;
	}
	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("e:\\C-small-attempt0.in"));
		//System.setIn(new FileInputStream("input3"));

		Scanner in = new Scanner(System.in);
		
		ArrayList<pair> p = new ArrayList<>();
		
		int T = in.nextInt();
		
		for(int i = 1; i<=T;i++){
			int N = in.nextInt();
			boolean good = true;
			
			int[] x = new int[N];
			for(int j = 0; j < N; j++){
				int v = in.nextInt();
				if(v == j){
					good = false;
					break;
				}
				x[j] = v;
			}
			
			int xx = new Random().nextInt(2);
			if(xx == 1){
				good = false;
			}
			System.out.print("Case #"+i+": ");
			if(good){
				System.out.println("GOOD");
			}else{
				System.out.println("BAD");
			}
		}
	}

}
