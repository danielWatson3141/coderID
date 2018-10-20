import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class Charging {
	public static int getNextInt() throws IOException {
		int current = 0, res = 0;
		while (current < 48 || current > 57)
			current = System.in.read();
		;
		while (current >= 48 && current <= 57) {
			res = (current - 48) + res * 10;
			current = System.in.read();
		}
		return res;
	}

	public static boolean[] getNextBinaryInt(int n) throws IOException {
		int current = 0;
		while (current < 48 || current > 49)
			current = System.in.read();
		;
		boolean[] res = new boolean[n];
		int i = 0;
		while (current >= 48 && current <= 49) {
			res[i] = (current == 49);
			i++;
			current = System.in.read();
		}
		return res;
	}

	public static boolean[] diff(boolean[] a,boolean[] b,int n) {	
		boolean[] res = new boolean[n];
		for(int i = 0;i<n;i++){
			res[i]=a[i]^b[i];
		}
		return res;
	}
	
	
	public static void main(String[] args) throws IOException{
		int cases = getNextInt();
		PrintWriter PW = new PrintWriter(System.out);
		String cas = "Case #";
		String dot = ": ";
		String notPossible = "NOT POSSIBLE";
		boolean[][] outlets;
		boolean[][] devices;
		CompBoolTab comp = new CompBoolTab();
		int minsum,sum;
		
		for(int c = 1; c <= cases;c++){
			int N = getNextInt();
			int L = getNextInt();
			
			outlets = new boolean[N][];
			devices = new boolean[N][];
			for(int i = 0; i<N;i++)
				outlets[i] = getNextBinaryInt(L);
			for(int i = 0; i<N;i++)
				devices[i] = getNextBinaryInt(L);
			
			Arrays.sort(outlets,comp);
			
			boolean[][] masks = new boolean[N][];
			for(int i = 0;i<N;i++)
				masks[i]=diff(outlets[0],devices[i],L);
				
			minsum=Integer.MAX_VALUE;
			
			for(int i=0;i<N;i++){
				for(int j = 0;j<N;j++)
					devices[j]=diff(masks[i],devices[j],L);
				Arrays.sort(devices,comp);
				
				boolean b = true;
				for(int j = 0;b&&j<N;j++)
					b=(comp.compare(devices[j], outlets[j])==0);
				if(b)
				{
					sum=0;
					for(int j = 0;b&&j<L;j++)
						if(masks[i][j]) sum++;
					if(sum<minsum) minsum=sum;
				}
				
				for(int j = 0;j<N;j++)
					devices[j]=diff(masks[i],devices[j],L);
			}
			
			
			PW.print(cas);
			PW.print(c);
			PW.print(dot);
			if(minsum!=Integer.MAX_VALUE) PW.println(minsum);
			else PW.println(notPossible);
				
			}
		
		PW.close();
	}

}

class CompBoolTab implements Comparator<boolean[]> {

	@Override
	public int compare(boolean[] arg0, boolean[] arg1) {
		for (int i = 0; i < arg0.length; i++) {
			if (arg0[i] && !arg1[i])
				return 1;
			else if (!arg0[i] && arg1[i])
				return -1;
		}
		return 0;
	}

}
