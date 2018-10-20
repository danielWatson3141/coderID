// A

import java.util.*; // for the haxing

public class Main {
  
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int iterations = in.nextInt();
    for (int i = 1; i <= iterations; i++) {
      // Parse in case
      int n = in.nextInt();
      int l = in.nextInt();


      // Get outlets
      List<BitSet> outlets = new ArrayList<BitSet>();
      for (int j = 0; j < n; j++) {
        BitSet bs = new BitSet(l);
        String o = in.next();
        for (int k = 0; k < l; k++)
          bs.set(k, o.charAt(k) == '1');
        outlets.add(bs);
      }

      // Get reference device
      Set<BitSet> devices = new HashSet<BitSet>();
      BitSet reference = new BitSet(l);
      String r = in.next();
      for (int k = 0; k < l; k++)
        reference.set(k, r.charAt(k) == '1');
      devices.add((BitSet) reference.clone());

      // Get rest of devices
      for (int j = 1; j < n; j++) {
        BitSet bs = new BitSet(l);
        String o = in.next();
        for (int k = 0; k < l; k++)
          bs.set(k, o.charAt(k) == '1');
        devices.add(bs);
      }

      // Solve case
      String result = solve(n, l, reference, outlets, devices);

      // Print case
      System.out.println("Case #" + i + ": " + result);
    }
  }

  public static String solve(int n, int l, BitSet reference, List<BitSet> outlets, Set<BitSet> devices) {
    if (n == 0) return "0";
    int switches = 42;
    SwitchSeq:
    for (int i = 0; i < n; i++) {
      BitSet xor = (BitSet) outlets.get(i).clone();
      xor.xor(reference);
      for (int j = 0; j < n; j++) {
        BitSet test = (BitSet) xor.clone();
        test.xor(outlets.get(j));
        if (! devices.contains(test)) continue SwitchSeq;
      }
      switches = Math.min(switches, xor.cardinality());   
    }
    return (switches > 40) ? "NOT POSSIBLE" : Integer.toString(switches);
  }

}
