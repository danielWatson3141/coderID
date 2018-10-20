import java.util.Scanner;

public class ChargingChaos {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan  = new Scanner(System.in);
		int T = scan.nextInt();
		for(int tt = 1; tt <= T;tt++) {
			int N = scan.nextInt();
			int L = scan.nextInt();
			String [] inp = new String[N];
			String [] out = new String[N];
			for(int i=0;i<N;i++) {
				inp[i] = scan.next();
			}
			for(int i=0;i<N;i++) {
				out[i] = scan.next();
			}
			int min = Integer.MAX_VALUE;
			String trial = inp[0];
			for(int i=0;i<N;i++) {
				int cost =0;
				boolean [] flipped = new boolean[L];
				for(int j=0;j<L;j++) {
					if(trial.charAt(j) ==  out[i].charAt(j)) continue;
					flipped[j] = true;
					cost++;
				}
				// let's flip o/p
				String [] flip = new String[N];
				for(int j=0;j<N;j++) {
					flip[j]="";
					for(int k=0;k<L;k++) {
						int sw = (out[j].charAt(k) -'0');
						if(flipped[k]) sw = 1-sw;
						flip[j] += (char)(sw+'0');
					}
				}
				/*
				for(int j=0;j<N;j++)
					System.out.println("i/p="+inp[j]+" flip="+flip[j]);
				System.out.println();*/
				// let's match;
				boolean [] matched = new boolean[N];
				int  found = 0;
				for(int j=0;j<N;j++) {
					for(int k=0;k<N;k++) {
						if(inp[j].equals(flip[k]) && !matched[k]) {
							matched[k] = true;
							found++;
							break;
						}
					}
				}
				if(found == N) {
					min = Math.min(min, cost);
				}
			}
			if(min == Integer.MAX_VALUE) {
				System.out.println("Case #"+tt+": NOT POSSIBLE");
			}else {
				System.out.println("Case #"+tt+": "+min);
			}
		}
		scan.close();

	}

}
