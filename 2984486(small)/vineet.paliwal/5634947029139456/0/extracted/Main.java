import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;


public class Main {

	static Main main;

	static int n;

	static int l;

	static BitSet[] b;

	static BitSet[] c;

	public static void main(String[] args) {
		main = new Main();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedOutputStream bos = new BufferedOutputStream(System.out);
		String eol = System.getProperty("line.separator");
		byte[] eolb = eol.getBytes();
		byte[] spaceb = " ".getBytes();
		byte[] caseb = "Case #".getBytes();
		byte[] colonb = ":".getBytes();
		try {
			String str = br.readLine();
			int t = Integer.parseInt(str);
			for(int i = 0 ; i < t ; i++) {

				str = br.readLine();
				int blank = str.indexOf(" ");
				n = Integer.parseInt(str.substring(0,blank));
				l = Integer.parseInt(str.substring(blank+1));

				b = new BitSet[n];
				ArrayList<BitSet> source = new ArrayList<BitSet>();
				ArrayList<BitSet> target = new ArrayList<BitSet>();
				str = br.readLine();
				int j=0;
				int s=0;
				int k =0;
				int length = str.length();
				while(j<length) {
					while(j<length) {
						if(str.charAt(j) == ' ') {
							break;
						}else {
							j++;
						}
					}
					String x = str.substring(s,j) ;	
					b[k] = new BitSet(l);
					b[k].clear();
					for(int a = 0 ; a < l ; a++) {
						if(x.charAt(a)=='1') {
							b[k].set(a);
						}
					}
					source.add(b[k]);
					k++;
					j++;
					s=j;			
				}
				c = new BitSet[n];

				str = br.readLine();
				j=0;
				s=0;
				k =0;
				length = str.length();
				while(j<length) {
					while(j<length) {
						if(str.charAt(j) == ' ') {
							break;
						}else {
							j++;
						}
					}
					c[k] = new BitSet(l);
					c[k].clear();

					String x = str.substring(s,j) ;	
					for(int a = 0 ; a < l ; a++) {
						if(x.charAt(a)=='1') {
							c[k].set(a);
						}
					}
					target.add(c[k]);
					k++;
					j++;
					s=j;			
				}
				int ans = solve(source,target,0,0);
				bos.write(caseb);
				bos.write(new Integer(i+1).toString().getBytes());
				bos.write(colonb);
				bos.write(spaceb);
				if(ans == Integer.MAX_VALUE) {
					bos.write("NOT POSSIBLE".getBytes());
				} else {
					bos.write(new Integer(ans).toString().getBytes());
				}
				bos.write(eolb);
			}
			bos.flush();
		} catch(IOException ioe) {
			ioe.printStackTrace();
		}
	}

	public static int solve(ArrayList<BitSet> source , ArrayList<BitSet> target , int st , int carry) {
		if(source.size()==0) {
			return carry;
		}
		int s = 0;
		int t = 0 ;
		int tot = source.size();
		for(int i = 0 ; i < source.size() ; i++) {
			boolean a = source.get(i).get(st);
			boolean b = target.get(i).get(st);
			if(a) {
				s++;
			}
			if(b) {
				t++;
			}
		}
		//System.out.println("s = " + s + " t = " + t + " tot = " + tot);
		if((s!=t)&&(s+t!=tot)) {
			return Integer.MAX_VALUE;		
		}
		if(st==l-1) {
			if(s==t) {
				return carry;
			}
			return carry + 1;
		}
		int ans = 0;
		ArrayList<BitSet> source1 = new ArrayList<BitSet>();
		ArrayList<BitSet> target1 = new ArrayList<BitSet>();
		ArrayList<BitSet> source2 = new ArrayList<BitSet>();
		ArrayList<BitSet> target2 = new ArrayList<BitSet>();
		boolean direct = false;
		boolean flip = false;
		if(s==t) {
			direct = true;
		}
		if(s+t==tot) {
			flip = true;
		}
		for(int i = 0 ; i < source.size() ; i++) {
			boolean a = source.get(i).get(st);
			boolean b = target.get(i).get(st);
			if(a) {
				source1.add(source.get(i));
			} else {
				source2.add(source.get(i));
			}
			if(b) {
				target1.add(target.get(i));
			} else {	
				target2.add(target.get(i));
			}
		}
		//ans = Math.min(solve(source1,target1,st+1,carry),solve(source2,target2,st+1,carry+1));
		
		int s1 = Integer.MAX_VALUE;
		if(direct) {
			s1 = Math.min(s1,Math.max(solve(source1,target1,st+1,carry),solve(source2,target2,st+1,carry)));
		}
		if(flip) {
			s1 = Math.min(s1, Math.max(solve(source1,target2,st+1,carry+1),solve(source2,target1,st+1,carry+1)));
		}
		ans = s1;
		return ans;
	}

}
