import java.util.Scanner;


public class a {
	static Scanner in=new Scanner(System.in);
	public static void main(String[] args) {
		int T=in.nextInt();
		for(int c=1;c<=T;++c){
			System.out.printf("Case #%d: ", c);
			int ans=solve();
			if(ans==-1)System.out.println("NOT POSSIBLE");
			else System.out.println(ans);
		}
	}
	static int solve(){
		int n=in.nextInt(),l=in.nextInt(),ans=-1;
		String[] a=new String[n],b=new String[n];
		for(int i=0;i<n;++i) a[i]=in.next();
		for(int i=0;i<n;++i) b[i]=in.next();
		boolean[] c=new boolean[l];
		for(int u=0;u<n;++u){
			int cnt=0;
			for(int j=0;j<l;++j)
				if(c[j]=(a[0].charAt(j)!=b[u].charAt(j)))++cnt;
			if(ans!=-1 && cnt > ans)continue;
			boolean[] match=new boolean[n];
			int i=0;
			for(i=0;i<n;++i) {
				boolean matched=false;
				for(int v=0;v<n;++v)if(!match[v]){
					boolean ok = true;
					for(int j=0;j<l && ok;++j)
						ok &= !((a[i].charAt(j) != b[v].charAt(j))^c[j]);
					if(ok){
						matched=match[v]=true;break;
					}
				}
				if(!matched)break;
			}
			if(i==n)ans=cnt;
		}
		return ans;
	}
}
