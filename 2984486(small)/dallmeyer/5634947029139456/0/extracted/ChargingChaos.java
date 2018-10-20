import java.util.ArrayDeque;
import java.util.BitSet;
import java.util.HashSet;
import java.util.Queue;
import java.util.Scanner;


public class ChargingChaos {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int caseNo = 1; caseNo <= T; caseNo++)
		{
			int N = in.nextInt(),
				L = in.nextInt();
			
			BitSet[] outlets = new BitSet[N];
			HashSet<BitSet> devices = new HashSet<BitSet>();
			for (int i = 0; i < N; i++)
			{
				outlets[i] = new BitSet(L);
				String s = in.next();
				for (int j = 0; j < L; j++)
				{
					if (s.charAt(j) == '1')
					{
						outlets[i].set(j, true);
					}
				}
			}
			for (int i = 0; i < N; i++)
			{
				BitSet device = new BitSet(L);
				String s = in.next();
				for (int j = 0; j < L; j++)
				{
					if (s.charAt(j) == '1')
					{
						device.set(j, true);
					}
				}
				devices.add(device);
			}
			
			
			BitSet switches = new BitSet(L);
			HashSet<BitSet> visited = new HashSet<BitSet>();
			visited.add(switches);
			Queue<BitSet> q = new ArrayDeque<BitSet>();
			q.add(switches);
			boolean possible = false;
			
			while (!q.isEmpty())
			{
				BitSet flips = q.poll();
				boolean chargeAll = true;
				for (int i = 0; i < N; i++)
				{
					BitSet flippedOutlet = (BitSet) outlets[i].clone();
					flippedOutlet.xor(flips);
					if (!devices.contains(flippedOutlet))
					{
						chargeAll = false;
						break;
					}
				}
				
				if (chargeAll)
				{
					System.out.println("Case #" + caseNo + ": " + flips.cardinality());
					possible = true;
					break;
				}
				
				for (int i = 0; i < L; i++)
				{
					BitSet newFlip = (BitSet) flips.clone();
					newFlip.set(i, true);
					if (!visited.contains(newFlip))
					{
						visited.add(newFlip);
						q.add(newFlip);
					}
				}
			}
			
			if (!possible)
			{
				System.out.println("Case #" + caseNo + ": NOT POSSIBLE");
			}
		}
	}

}
