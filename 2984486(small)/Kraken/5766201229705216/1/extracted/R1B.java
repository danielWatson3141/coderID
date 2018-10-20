import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class R1B {
	
	static class TrN{
		public int n;
		public int nch;
		public ArrayList<TrN> ar;
		
		TrN(int i){
			n=i;
			ar=new ArrayList<TrN>();
		}
		
		void cntN(TrN from){
			nch=1;
			for (TrN nd:this.ar) {
				if (nd==from) continue;
				nd.cntN(this);
				nch+=nd.nch;
			}
		}
		
		int minEr(TrN from){
			int nn=0;
			int nchd=0;
			int mx=-1; int mx2=-1;
			for (TrN nd:this.ar) {
				if (nd==from) continue;
				nn+=nd.nch;
				int tm=nd.nch-nd.minEr(this);
				if (tm>=mx) { mx2=mx; mx=tm;}
				else if (tm>=mx2) { mx2=tm;}
				nchd++;
			}
			if (nchd>=2) nn-=mx+mx2;
			return nn;
		}
	}
	
public static void main(String[] args) {
		String prblm="B"; boolean fl=true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				s=fr.readLine();
				int N=Integer.parseInt(s);
				TrN[] tree=new TrN[N];
				for (int j = 0; j < N; j++) tree[j]=new TrN(j);
				for (int j = 0; j < N-1; j++) {
					s=fr.readLine();
					String[] tok=s.split(" ");
					int f=Integer.parseInt(tok[0]);
					int e=Integer.parseInt(tok[1]);
					tree[f-1].ar.add(tree[e-1]);
					tree[e-1].ar.add(tree[f-1]);
				}
				int mn=Integer.MAX_VALUE;
				for (int j = 0; j < N; j++) {
					tree[j].cntN(null);
					int tm=tree[j].minEr(null);
					mn=Math.min(tm,mn);
				}
				System.out.println(mn);
				fw.write("Case #"+i+": "+ mn  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}