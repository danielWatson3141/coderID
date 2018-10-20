import java.util.*;

public class CardShuffle {

	public static void main(String[] args)
	{
//		Random r = new Random();
//		System.out.println(Integer.toString(r.nextInt(5)));
		CardShuffle cs = new CardShuffle();
		cs.run();
	}
	
	public void run()
	{
		Scanner sc = new Scanner(System.in);
		
		int num_cases = sc.nextInt();
		
		for (int c = 1; c <= num_cases; c++)
		{
			int answer = 0;
			int length = sc.nextInt();
			
			int bias_count = 0;
			for (int j = 0; j < length; j++)
			{
				int mynum = sc.nextInt();
				
				// Check for positively biased numbers
				if ((j < mynum) && (mynum <= j+100))
				{
					bias_count += 1;
				}
					
				if ((j - 1000 < mynum) && (mynum < j - 900))
				{
					bias_count += 1;
				}	
			}
//			
//			System.out.println(bias_count);
//			
			if (bias_count > 110)
			{
				System.out.printf("Case #%d: BAD\n", c);
			}
			else
			{
				System.out.printf("Case #%d: GOOD\n", c);
			}
		}
	}

}
