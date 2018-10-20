import java.util.*;

public class A {
    static final String BAD = "NOT POSSIBLE";
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int cases = Integer.parseInt(sc.nextLine());
	for (int z = 0; z < cases; z++) {
	    String[] spl = sc.nextLine().split(" ");
	    int N = Integer.parseInt(spl[0]);
	    int L = Integer.parseInt(spl[1]);
	    String[] outlets = sc.nextLine().split(" ");
	    String[] devices = sc.nextLine().split(" ");
	    HashSet<String> tried = new LinkedHashSet<String>();
	    int min = Integer.MAX_VALUE;
	    for (int i = 0; i < devices.length; i++) {
		String d = devices[i];
		for (int j = 0; j < outlets.length; j++) {
		    String o = outlets[j];
		    String x = xor(d, o);
		    if (!tried.contains(x)) {
			boolean[] used = new boolean[outlets.length];
			boolean[] usedD = new boolean[devices.length];
			used[j] = true;
			usedD[i] = true;
			int run = canMath(devices, outlets, used, x, usedD);
			//System.out.println("XOR: " + x + " OUTPUT: " + run);
			
			if (run != -1) {
			    min = Math.min(min, run);
			}
		    }
		}
	    }
	    if (min == Integer.MAX_VALUE) {
		System.out.printf("Case #%d: %s\n", (z+1), BAD);
	    } else {
		System.out.printf("Case #%d: %d\n", (z+1), min);
	    }
	}
    }
    
    public static int canMath(String[] devices, String[] outlets, boolean[] used, String xorString, boolean[] usedD) {
	int using = -1;
	for (int i = 0; i < usedD.length; i++) {
	    if (!usedD[i]) {
		using = i;
		break;
	    }
	}
	if (using == -1) {
	    int cnt = 0;
	    for (int i = 0; i < xorString.length(); i++) {
		if (xorString.charAt(i) == '1') cnt++;
	    }
	    return cnt;
	} else {
	    //math using.
	    int val = Integer.MAX_VALUE;
	    for (int i = 0; i < used.length; i++) {
		if (!used[i]) {
		    String x = xor(devices[using], outlets[i]);
		    if (x.equals(xorString)) {
			used[i] = true;
			usedD[using] = true;
			int ret = canMath(devices, outlets, used, xorString, usedD);
			if (ret != -1) val = Math.min(val, ret);
			used[i] = false;
			usedD[using] = false;
			break;//trick?
		    }
		}
	    }
	    return val == Integer.MAX_VALUE ? -1 : val;
	}
    }

    public static String xor(String one, String two) {
	StringBuilder res = new StringBuilder("");
	for (int i = 0; i < one.length(); i++) {
	    if (one.charAt(i) == two.charAt(i)) res.append("0");
	    else res.append("1");
	}
	return res.toString();
    }
}
