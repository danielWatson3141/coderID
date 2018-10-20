import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class R1A {
	
	static long[] ef;
	static long[] ol;
	
	static int verify(int p){
		if (p<0) return 0;
		boolean fg=true;
		for (int i = 0; i < ef.length && fg; i++) {
			if ((ef[i]>>p)%2 != (ol[i]>>p)%2) fg=false; 
		}
		int mnk=-1;
		if (fg){
			mnk=verify(p-1);
		}
		//System.out.println((1<<p)+" "+ p +" : "+Arrays.toString(ef));
		for (int i = 0; i < ef.length; i++) {
			if ((ef[i]>>p)%2 == 1) ef[i]-=1<<p;
			else ef[i]+=1<<p;
		}		
		Arrays.sort(ef);
		fg=true;
		for (int i = 0; i < ef.length && fg; i++) {
			if ((ef[i]>>p)%2 != (ol[i]>>p)%2) fg=false; 
		}
		if (fg){
			int k=verify(p-1);
			if (k>=0){
				if (mnk>=0) mnk=Math.min(mnk,k+1);
				else mnk=k+1;
			}
		}
		for (int i = 0; i < ef.length; i++) {
			if ((ef[i]>>p)%2 == 1) ef[i]-=1<<p;
			else ef[i]+=1<<p;
		}
		Arrays.sort(ef);
		return mnk;
	}
	
	
public static void main(String[] args) {
		String prblm="A"; boolean fl=!true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				s=fr.readLine();
				String[] tok=s.split(" ");
				int N=Integer.parseInt(tok[0]);
				int L=Integer.parseInt(tok[1]);
				s=fr.readLine();
				tok=s.split(" ");
				ef=new long[N];
				ol=new long[N];
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < L; k++) 
						if (tok[j].charAt(k)=='1') ef[j]+=1<<(L-k-1);
				}
				s=fr.readLine();
				tok=s.split(" ");
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < L; k++) 
						if (tok[j].charAt(k)=='1') ol[j]+=1<<(L-k-1);
				}
				Arrays.sort(ef);
				Arrays.sort(ol);
				int v=verify(L-1);
				if (v>=0) s=""+v;
				else s="NOT POSSIBLE";
				System.out.println(s);
				fw.write("Case #"+i+": "+ s  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}