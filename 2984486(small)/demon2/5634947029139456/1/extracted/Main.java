import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class Main {

    
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner=new Scanner(new File("E:\\A-large.in"));
		PrintWriter printWriter=new PrintWriter(new File("E:\\output.txt"));
		int T=scanner.nextInt();
		for (int i = 1; i <= T; i++) {			
			 int N=scanner.nextInt();
			 int L=scanner.nextInt();
			 scanner.nextLine();
			 String[] flow=scanner.nextLine().split(" ");
			 String[] device=scanner.nextLine().split(" ");
			 int ret=L+1;
			 String s=flow[0];
			 for (int j = 0; j < N; j++) {
				 boolean[] flag=new boolean[L];
				 int tmp=0;
				for (int k = 0; k < L; k++) {
					if (s.charAt(k)==device[j].charAt(k)) {
						flag[k]=true;
					}
					else tmp++;
				}
				for (int k = 0; k < N; k++) {
					boolean f1=false;
					for (int k2 = 0; k2 < N; k2++) {
						boolean f=true;
						for (int m = 0; m < L; m++) {
							if ((flow[k].charAt(m)==device[k2].charAt(m)&&flag[m])||(flow[k].charAt(m)!=device[k2].charAt(m)&&!flag[m])) {
								continue;
							}
							else {
								f=false;
								break;
							}
						}
						if (f) {
							f1=true;
							break;
						}
					}
					if (!f1) {
						tmp=-1;
						break;
					}
				}
				if (tmp!=-1) {
					ret=Math.min(ret, tmp);
				}
			}
			 if (ret==L+1) {
				 printWriter.println("Case #"+i+": "+"NOT POSSIBLE");
			}
			 else printWriter.println("Case #"+i+": "+ ret);
						
		}
		scanner.close();
		printWriter.close();
	}	 	 
}

