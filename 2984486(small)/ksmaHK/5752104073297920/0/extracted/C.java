import java.util.*;

public class C {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	outer:
	for (int nc = 1; nc <= nCase; nc++) {
		int N = scanner.nextInt();
		int[] permu = new int[N];
		for (int i = 0; i < N; i++)
			permu[i] = scanner.nextInt();
		
		
		int first = 0;
		int second = 0;
		for (int i = 0; i < N/2; i++)
			first += permu[i];
		
		for (int i = N/2; i < N; i++)
			second += permu[i];
			
		if (first < second)
			System.out.println("Case #" + nc + ": GOOD");
		else
			System.out.println("Case #" + nc + ": BAD");
			
			/*
		double ans = 0;
		double p = 1.0/N;
		for (int i = 0; i < N; i++) {
			if (permu[i] == i) {
				ans -= p;
			}			
		}
		
		for (int i = 0; i < N; i++) {
			if (permu[i] == i) {
				System.out.println("Case #" + nc + ": GOOD");
				continue outer;
			}
		}
		
		for (int i = 0; i < N/2; i++)
			if (permu[i] > i) ans += p;
		
		for (int i = N/2; i < N; i++)
			if (permu[i] < i) ans += p;
		
		if (ans >= 0.5)
			System.out.println("Case #" + nc + ": GOOD");
		else
			System.out.println("Case #" + nc + ": BAD");
			*/
	}
}
}