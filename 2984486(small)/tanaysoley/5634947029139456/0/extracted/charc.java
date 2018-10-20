import java.io.*;
import java.util.StringTokenizer;

public class charc{
	public static void main(String args[]) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s;
		StringTokenizer st;
		
		int T,N,answer;
		int arr[][];
		int res[];
		
		s=br.readLine();
		T=Integer.parseInt(s);
		for(int I=1;I<=T;I++){
			s=br.readLine();
			st=new StringTokenizer(s," ");
			N=Integer.parseInt(st.nextToken());
			
			arr=new int[2][N];
			res=new int[N];
			
			s=br.readLine();
			st=new StringTokenizer(s," ");
			for(int i=0;i<N;i++){
				arr[0][i]=Integer.parseInt(st.nextToken(),2);
			}
			
			s=br.readLine();
			st=new StringTokenizer(s," ");
			for(int i=0;i<N;i++){
				arr[1][i]=Integer.parseInt(st.nextToken(),2);
			}
			
			int a[]=new int[N];
			for(int i=0;i<N;i++){
				a[i]=-1;
			}
			
			if(N>1){
				answer=check(a,N,arr,0,100);
			}else{
				answer=count(arr[0][0]^arr[1][0]);
			}
			if(answer==100){
				System.out.println("Case #"+I+": NOT POSSIBLE");
			}else{
				System.out.println("Case #"+I+": "+answer);
			}
		}
		
	}
	
	public static int check(int a[],int N,int[][] arr,int in,int answer){
		
		for(int I=0;I<N;I++){
			if(a[I]==-1){
				a[I]=in;
			}
			else{
				continue;
			}
		
			
			
			if(in==N-1){
			
			
			/*********
				for(int i=0;i<N;i++){
					System.out.print(a[i]);
				}
				System.out.println("");
			**********/
			
				int[] temp=new int[N];
				int[] res=new int[N];
				
			/***********
				System.out.print("xoring");
				for(int i=0;i<N;i++){
					System.out.print(arr[1][a[i]]^arr[0][i]);
				}
				System.out.println("");
			***********/
				
				
				for(int i=0;i<N;i++){
					res[i]=arr[1][a[i]]^arr[0][i];
					if(i>=1){
						if(res[i]!=res[i-1]){
							//System.out.println(res[i]+"!="+res[i-1]);
							break;
						}else{
							//System.out.println("answer"+count(res[i]));
							if(i==N-1&&answer>count(res[i])){
								answer=count(res[i]);
							}
						}
					}
				}
			}else{
				answer=check(a,N,arr,in+1,answer);
			}
			a[I]=-1;
		}
		
		return answer;
	}
	
	public static int count(int a){
		int count=0;
		while(a!=0){
			if(a%2==1){
				count++;
			}
			a=a/2;
		}
		return count;
	}
}