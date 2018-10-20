import java.io.*;
import java.util.*;

class Main
{
  public static void main(String args[]) throws Exception
  {
    int T, N, L, t=0;
    BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
    T = Integer.parseInt(x.readLine());
    String token[];
    while(t++ < T){
      token = x.readLine().split(" ");
      N = Integer.parseInt(token[0]);
      L = Integer.parseInt(token[1]);
      String[] req = x.readLine().split(" "), itl = x.readLine().split(" ");
      System.out.println("Case #"+t+": "+flip(N,L,req,itl));
    }
  }
  
  public static String flip(int N, int L, String a[], String b[]){
    int i,j,k;
    boolean f[] = new boolean[L];
    int min = Integer.MAX_VALUE;
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
	int c = 0;	
	for(k=0;k<L;k++){
	  if(a[i].charAt(k) != b[j].charAt(k)) {f[k]=true; c++;}
	  else f[k]=false;
	}
	if(check(a,b,f,N,L)){
	  if(c<min) min=c;
	}
      }
    }
    if(min>L) return "NOT POSSIBLE";
    return ""+min;
  }
  
  public static boolean check(String a[], String b[], boolean f[], int N, int L){
    int m=0, i, j;
    int e[]=new int[N];
    for(i=0;i<N;i++)e[i]=0;
    for(i=0;i<N;i++){
      char[] s = b[i].toCharArray();
      for(j=0;j<L;j++) if(f[j]) s[j]=(s[j]=='0')?'1':'0';
      String st = new String(s);
      for(j=0;j<N;j++){
	if(e[j]>0)continue;
	if(st.equals(a[j])){e[j]=1; m++; break;}
      }
    }
    return (m==N);
  }
}