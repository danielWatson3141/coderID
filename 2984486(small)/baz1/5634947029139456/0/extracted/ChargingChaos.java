import java.util.HashMap;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

public class ChargingChaos {
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		in.useLocale(Locale.ENGLISH);
		int T = in.nextInt(), i = 0, j, N, L;
		HashMap<Long, Integer> devices = new HashMap<Long, Integer>(1024), cpy;
		LinkedList<Long> outlets = new LinkedList<Long>();
		while (i++ < T)
		{
			System.out.print("Case #" + i + ": ");
			devices.clear();
			outlets.clear();
			N = in.nextInt();
			L = in.nextInt();
			for (j = 0; j < N; ++j)
				outlets.add(Long.valueOf(in.next(), 2));
			for (j = 0; j < N; ++j)
				devices.put(Long.valueOf(in.next(), 2), 1);
			Set<Long> devSet = devices.keySet();
			int best = Integer.MAX_VALUE;
			mainLoop: for (Long k : devSet)
			{
				cpy = (HashMap<Long, Integer>) devices.clone();
				long change = outlets.getFirst().longValue() ^ k.longValue();
				for (Long current : outlets)
				{
					if (cpy.remove(current.longValue() ^ change) == null)
						continue mainLoop;
				}
				if (Long.bitCount(change) < best)
					best = Long.bitCount(change);
			}
			if (best == Integer.MAX_VALUE)
				System.out.println("NOT POSSIBLE");
			else System.out.println(best);
		}
		in.close();
	}
}
