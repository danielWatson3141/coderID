import java.util.StringTokenizer;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
class C{
public static void main(String[] args){
	try{
		FileReader fr = new FileReader("C-small-attempt3.in");			//
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw =new FileWriter("Cout.txt");
		BufferedWriter bw = new BufferedWriter(fw);
		int T = Integer.parseInt(br.readLine());
		for(int x=0;x<T;x++){
			boolean flag=true;
			int N = Integer.parseInt(br.readLine());
			StringTokenizer st=new StringTokenizer(String.valueOf(br.readLine()));
			int set[]=new int[N];
			int boo[]=new int[N];
			int sum=0;
			int count=0;
			for(int i=0;i<N;i++){
			set[i]=Integer.parseInt(st.nextToken());
			boo[i]=i;
			}
			for(int i=0,j;i<N;i++){
				for(j=i;j<N;j++)
					if(boo[j]==set[i]){
						int temp=boo[i];
						if(j==1) count++;
						sum+=j;
						boo[i]=boo[j];
						boo[j]=temp;
						break;
						}
				if(j==N) {flag=false;break;}	
			}
			String ans;
			if(flag==true)
			ans="GOOD";
			else ans="BAD";
			if(count>N/5||(sum/N<(106*N/143))) ans="BAD";
			String str="Case #"+(x+1)+": ";
			bw.write(str);
			bw.write(String.valueOf(ans));
			bw.newLine();			
		}
		bw.flush();
		bw.close();
		}catch(Exception e){e.printStackTrace();}
	}
}	