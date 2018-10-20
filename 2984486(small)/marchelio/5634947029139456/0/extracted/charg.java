package charging;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class charg {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(new File("A-small-attempt0.in"));
		int T = scan.nextInt();
		FileWriter fw = new FileWriter( new File("result.txt"));
		//System.out.println(2^2);
		for(int k=0;k<T;k++){
			int rez=50;
			
			int n = scan.nextInt();
			int l = scan.nextInt();
			int[] out = new int[n];
			int[] dev = new int[n];
			for (int i=0;i<n;i++){
				out[i] = scan.nextInt();
			}
			for (int i=0;i<n;i++){
				dev[i] = scan.nextInt();
			}
			for (int i=0;i<n;i++){
				int buf=0;
				for (int j=0;j<l;j++){
					buf+=out[i]%10*Math.pow(2, j);
					out[i]/=10;
				}
				out[i]=buf;
				buf=0;
				for (int j=0;j<l;j++){
					buf+=dev[i]%10*Math.pow(2, j);
					dev[i]/=10;
				}
				dev[i]=buf;
			}
			Arrays.sort(out);
			Arrays.sort(dev);
//			for (int i=0;i<n;i++){
//				System.out.print(out[i]+" ");
//			}
//			System.out.println();
//			for (int i=0;i<n;i++){
//				System.out.print(dev[i]+" ");
//			}
//			System.out.println();
			if(same(out,dev)){
				System.out.println("Case #"+k+": 0");
				fw.write("Case #"+(k+1)+": 0"+"\n");
				fw.flush();
			}
			else{
				for (int i=0;i<n;i++){
					int rez1=0;
					int buf = out[i]^dev[0];
					//System.out.println("bb "+buf);
					//System.out.println("r1 "+rez1);
					int[] aout = new int[n];
					for(int j=0;j<n;j++){
						aout[j]=out[j]^buf;
					}
					Arrays.sort(aout);
//					for (int j=0;j<n;j++){
//						System.out.print(out[j]+" ! ");
//					}
//					System.out.println("bb2 "+buf);
					for(int j=0;j<l;j++){
						rez1+=buf%2;
						buf/=2;
					}
					if(same(aout,dev))
						if(rez>rez1)
							rez=rez1;
				}
				if (rez==50){
					System.out.println("Case #"+k+": NOT POSSIBLE");
					fw.write("Case #"+(k+1)+": NOT POSSIBLE"+"\n");
					fw.flush();
				}
				else{
					System.out.println("Case #"+k+1+": "+rez);
					fw.write("Case #"+(k+1)+": "+rez+"\n");
					fw.flush();
				}
			}
			
		}
	}
	public static boolean same(int[] a, int[] b){
		for(int i=0;i<a.length;i++){
			if(a[i]!=b[i])
				return false;
		}
		return true;
	}
}
