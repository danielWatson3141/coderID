import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) throws IOException{
		BufferedReader x = new BufferedReader(new FileReader("C:/Documents and Settings/alvin/My Documents/alvin/Computer Science/Code Jam/alarge.in"));
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("C:/Documents and Settings/alvin/My Documents/alvin/test.out.txt")));
		int numcases=Integer.parseInt(x.readLine());
		for (int a=1; a<=numcases; a++){
			StringTokenizer st=new StringTokenizer(x.readLine());
			int numdevices=Integer.parseInt(st.nextToken());//n
			int numbits=Integer.parseInt(st.nextToken());//l
			StringTokenizer ab=new StringTokenizer(x.readLine());
			String[]switches=new String[numdevices];
			for (int i=0; i<numdevices; i++){
				switches[i]=ab.nextToken();
			}
			StringTokenizer cd=new StringTokenizer(x.readLine());
			String[]devices=new String[numdevices];
			for (int i=0; i<numdevices; i++){
				devices[i]=cd.nextToken();
			}
			String[][]working=new String[numdevices][numdevices];//rows=switches, columns=appliances
			for (int i=0; i<numdevices; i++){
				for (int j=0; j<numdevices; j++){
					String builder="";
					for (int k=0; k<numbits; k++){
						if (switches[i].charAt(k)!=devices[j].charAt(k)){
							builder=builder+k;
						}
					}
					working[i][j]=builder;
				}
			}
			int minlength=10000;
			boolean success=false;
			for (int i=0; i<numdevices; i++){
				String currentconfig=working[i][0];
				boolean works=true;
				for (int j=0; j<numdevices; j++){
					boolean satisfy=false;
					for (int k=0; k<numdevices; k++){
						if (currentconfig.equals(working[j][k])){
							satisfy=true;
							break;
						}
					}
					if (!satisfy){
						works=false;
						break;
					}
				}
				if (works){
					success=true;
					if (minlength>currentconfig.length()){
						minlength=currentconfig.length();
					}
				}
			}
			if (!success){
				out.println("Case #"+a+": NOT POSSIBLE");
			}
			else{
				out.println("Case #"+a+": "+minlength);
			}
		}
		out.close();
		System.exit(0);
	}

}
