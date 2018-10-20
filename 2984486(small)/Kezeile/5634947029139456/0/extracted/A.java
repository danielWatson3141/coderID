import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for (int kk=1; kk<=tests; kk++) {
			int num = sc.nextInt();
			int length = sc.nextInt();
			int[] outlets = new int[num];
			int[] device = new int[num];
			for (int i=0; i<num; i++)
				outlets[i] = Integer.parseInt(sc.next(), 2);
			for (int i=0; i<num; i++)
				device[i] = Integer.parseInt(sc.next(), 2);
			Arrays.sort(device);
			int least =  100;
			outer: for(int i=0;i<(1<<length);i++) {
				//i - what bit to flip
				int[] flipped = new int[num];
				for (int j=0; j<num; j++) {
					flipped[j] = i ^ outlets[j];
				}
				Arrays.sort(flipped);

				// compare if same
				boolean diff = false;
				for (int j=0;j<num ;j++ ) {
					// System.out.println(device[j] +" "+ flipped[j]);
					if(device[j] != flipped[j])
						diff = true;
				}
				if(least > Integer.bitCount(i) && !diff)
					least = Integer.bitCount(i);
			}
			if (least == 100) {
				System.out.printf("Case #%d: NOT POSSIBLE\n",kk);
			} else {
				System.out.printf("Case #%d: %d\n", kk,least);
			}

		}
	}
}
// 10 00 = 10
// 10 01 = 11
// 10 10 = 00
// 10 11 = 01