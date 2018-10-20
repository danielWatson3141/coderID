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
			a: for (int i = 0; i < N; i++) {
				int cambio = 0;
				for (int j = 0; j < L; j++) {
					if((mat[0] & (1<<j)) != (mat2[i] & (1<<j)))
						cambio |= (1<<j);
				}
				//System.out.println(i+" "+cambio);
				boolean[] matched = new boolean[N];
				for (int j = 0; j < N; j++) {
					int act = 0;
					for (int k = 0; k < L; k++) {
						if( (mat[j]&(1<<k)) != (cambio &(1<<k)) )
							act |= (1<<k);
					}
					//System.out.println(i+" "+j+" "+act);
					for (int j2 = 0; j2 < N; j2++) {
						if(act == mat2[j2])
							matched[j2]=true;
					}
				}
				for (int j = 0; j < N; j++) {
					if(!matched[j])
						continue a;
				}
				int cnt = 0;
				while(cambio>0)
				{
					if(cambio%2==1)
						cnt++;
					cambio/=2;
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
