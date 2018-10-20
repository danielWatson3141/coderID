package round_1A_2014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Shuffle {
		public static void main(String[] args) throws IOException {
			BufferedReader f = new BufferedReader(new FileReader("Shuffle.in"));
			PrintWriter out = new PrintWriter(new FileWriter("C:/Users/David/Desktop/Shuffle"));
			StringTokenizer t = new StringTokenizer(f.readLine());
			int testCases = Integer.parseInt(t.nextToken());
			int good = 0;
			for (int i = 0; i < testCases; i++)
			{
				t = new StringTokenizer(f.readLine());
				int N = Integer.parseInt(t.nextToken());
				int[] deck = new int[N];
				t = new StringTokenizer(f.readLine());
				for (int j = 0; j < N; j++)
					deck[j] = Integer.parseInt(t.nextToken());
				
				double positiveBias = 0;
				double negativeBias = 0;
				
				
				
				for (int j = 0; j < N; j++)
				{
					int element = deck[j];
					if (j > element)
					{
						double d = 1 - 0.5 * Math.abs((j - element));
						if (d > 0)
							negativeBias += d;
					}
					else if (element >= N/2 && N/2 - j >= 0)
					{
						double d = 1 - 0.5 * (Math.abs(N-element-j));
						if (d > 0)
							negativeBias += d;
					}
					else
					{
						double d = 1 - 0.5 * (Math.abs((element-j)));
						if (d > 0)
							positiveBias += d;
					}
				}
				
				System.out.println(positiveBias);
				System.out.println(negativeBias);
				
				if (positiveBias - negativeBias  < 0) //bad
				{
					String ans = "Case #" + (i+1) + ": BAD";
					out.println(ans);
					System.out.println(ans);
				}
				else //good shuffling
				{
					String ans = "Case #" + (i+1) + ": GOOD";
					out.println(ans);
					System.out.println(ans);
					good++;
				}
			}
			System.out.println(good);
			out.close(); f.close(); System.exit(0);
		}
}
