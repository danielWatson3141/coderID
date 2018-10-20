import java.io.FileReader;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;
import java.util.Scanner;


public class Problem1 {
	
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new FileReader("problem1.txt"));
		
		int tests = scanner.nextInt();		
		for(int i = 1; i <= tests; i++) {
			int N = scanner.nextInt();
			int L = scanner.nextInt();
			
			BitSet[] initial = new BitSet[N];
			BitSet[] devices = new BitSet[N];
			
			for(int j = 0; j < N; j++) {
				initial[j] = new BitSet(L);
				String bits = scanner.next();
				int k = bits.length() - 1;
				for(char c : bits.toCharArray()) {
					initial[j].set(k--, c == '1' ? true : false);
				}
			}
			
			for(int j = 0; j < N; j++) {
				devices[j] = new BitSet(L);
				String bits = scanner.next();
				int k = bits.length() - 1;
				for(char c : bits.toCharArray()) {
					devices[j].set(k--, c == '1' ? true : false);
				}
			}
			
			
			int result = getNumFlips(N, L, initial, devices);
			
			if(result == -1) {
				System.out.printf("Case #%d: NOT POSSIBLE\n", i);
			} else {
				System.out.printf("Case #%d: %d\n", i, result);
			}
		}
		
		scanner.close();
		
		System.exit(0);
	}
	
	
	private static int getNumFlips(int N, int L, BitSet[] initial, BitSet[] devices) {
		BitSet b = new BitSet(L);
		b.set(0, L, false);
		if(works(b, initial, devices, N)) return 0;
		
		for(int i = 1; i < L; i++) {
			b = new BitSet(L);
			//System.out.println("***" + b);
			int nb = numSetBits(b, L);
			while(nb < L) {
				//System.out.println("***" + b + "  " + nb);
				if(nb == i) {
					if(works(b, initial, devices, N)) return i;
				}
				
				b = increment(b, L);
				nb = numSetBits(b, L);
			}
		}
		b = new BitSet(L);
		b.set(0, L, true);
		if(works(b, initial, devices, N)) return L;
		
		return -1;
	}
	
	private static int numSetBits(BitSet b, int N) {
		int num = 0;
		for(int i = 0; i < N; i++) {
			if(b.get(i)) num++;
		}
		return num;
	}
	
	  /**
	   * Increment the numeric value represented by this bit set
	   * 
	   * @param set
	   *          to increment
	   * @param totalBits
	   *          number of bits in the bit set
	   * @return bit set with incremented value
	   */
	  public static BitSet increment(BitSet set, int totalBits) {
	    boolean carry = true;
	    int place = totalBits - 1;
	    while (carry && place >= 0) {
	      carry = set.get(place);
	      set.set(place, !set.get(place));
	      place--;
	    }
	    return set;
	  }
	  
	  private static boolean works(BitSet b, BitSet[] initial, BitSet[] devices, int N) {
		  List<BitSet> end = new ArrayList<BitSet>();
		  for(int i = 0; i < N; i++) {
			  BitSet a = (BitSet)initial[i].clone();
			  a.xor(b);
			  end.add(a);
		  }
		  
		  for(int i = 0; i < N; i++) {
			  if(end.contains(devices[i])) {
				  end.remove(end.indexOf(devices[i]));
			  } else {
				  return false;
			  }
		  }
		  return true;
	  }
	

}
