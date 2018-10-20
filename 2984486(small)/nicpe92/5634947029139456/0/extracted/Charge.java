import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Charge {

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T =Integer.parseInt(in.readLine());
		for (int c = 0; c < T; c++) {
			String[] s = in.readLine().split(" " );
			int N = Integer.parseInt(s[0]);
			int L = Integer.parseInt(s[1]);
			int[] mat = new int[N];
			s =  in.readLine().split(" " );
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < L; j++) {
					if(s[i].charAt(j)=='1')
					{
						mat[i] |= (1<<j);
					}
				}
			}
			int[] mat2 = new int[N];
			s =  in.readLine().split(" " );
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < L; j++) {
					if(s[i].charAt(j)=='1')
						mat2[i] |= (1<<j);
				}
			}
			int min = 1000;
			a: for (int i = 0; i < (1<<L); i++) {
				int cnt = 0, j=i;
				while(j>0)
				{
					if(j%2==1)
						cnt++;
					j/=2;
				}
				boolean[] match = new boolean[N];
				int[] nuev = new int[N];
				for (int k = 0; k < N; k++) {
					for (int k2 = 0; k2 < L; k2++) {
						if((mat[k]&(1<<k2))!=0 && (i&(1<<k2))==0)
							nuev[k]|=(1<<k2);
						else if((mat[k]&(1<<k2))==0 && (i&(1<<k2))!=0)
							nuev[k]|=(1<<k2);
					}
					for (int k2 = 0; k2 < N; k2++) {
						if(nuev[k] == mat2[k2] && !match[k2])
						{
							match[k2]=true;
						}
					}
				}
				for (int k = 0; k < N; k++) {
					if(!match[k])
						continue a;
				}
				min = Math.min(min, cnt);
			}
			System.out.print("Case #"+(c+1)+": ");
			if(min < 1000)
				System.out.println(min);
			else System.out.println("NOT POSSIBLE");
		}
	}
}
