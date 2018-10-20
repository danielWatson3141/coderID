import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Iterator;
import java.util.TreeSet;

public class Solution{
	static int t,n,l;
	static int[][] a,b;
	static boolean success;
	static int global;
	static TreeSet<String> f,s;
	static int[] flip;
	static String line;
	static String[] row;
	
	public static void main(String [ ] args) throws IOException{
		int i,j,k;
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));
	    try {
	    	File file = new File("aaa.out");
    		
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		
	        line = br.readLine();
	        t = Integer.valueOf(line);
	        
	        for(k = 0; k < t; k++){
	        	line = br.readLine();
	        	row = line.split("\\s");
	        	n = Integer.valueOf(row[0]);
	        	l = Integer.valueOf(row[1]);

	        	a = new int[n][l];
	        	b = new int[n][l];
	        	flip = new int [l];
	        	
	        	line = br.readLine();
	        	row = line.split("\\s");
	        	for (j=0;j<n;j++){
	    			for (i=0;i<l;i++){
	    				a[j][i] = Integer.valueOf(row[j].charAt(i)-'0');
	    			}
	        	}
	        	
	        	line = br.readLine();
	        	row = line.split("\\s");
	        	for (j=0;j<n;j++){
	    			for (i=0;i<l;i++){
	    				b[j][i] = Integer.valueOf(row[j].charAt(i)-'0');
	    			}
	        	}
	        		        		        	
    			bw.write("Case #"+(k+1)+": "+solve()+"\n");
	        }
	        
	        
			bw.close();

	    } finally {
	        br.close();
	    }
	}
	
	private static String solve(){
		int i,j,k;
		int suma,sumb;
		int flips = 0;
		success = false;
		//bit check
		for (j=0;j<l;j++){
			suma=0;sumb=0;
			flip[j]=0;
			for (i=0;i<n;i++){
				suma+=a[i][j];
				sumb+=b[i][j];
			}
			
			if(suma==sumb){
				flip[j]=1;
			}
			if (suma==n-sumb){
				flip[j]+=2;
			}
			System.out.println("n"+n+"l"+l+"i"+i+"j"+j+":"+suma+"-"+ sumb);
			if (flip[j]==0) return "NOT POSSIBLE";
		}
		
		//flip all MUST flips without alternative (==2)
		for (j=0;j<l;j++){
			if(flip[j]==2) {
				for (i=0;i<n;i++){
					a[i][j]=1-a[i][j];
				}
				flips++;
				flip[j]-=2;
			}
		}
		
		//sort and check
		
		//backtrack all possibilities
		global = l+1;
		back(0,0);
		
		if(success) return ""+(flips+global);
		else return "NOT POSSIBLE";
	}
	
	private static void back(int step,int current){
		int i;
		if(step==l){
			if(convert()) {
				success =true;
				if (current < global){
					global = current;
				}
			}
			return;
		}
		
		if(flip[step]==3){
			//do flip
			for (i=0;i<n;i++){
				a[i][step]=1-a[i][step];
			}
			back(step+1,current+1);
			//redo flip
			for (i=0;i<n;i++){
				a[i][step]=1-a[i][step];
			}
		}
		//try w/0 flip
		back(step+1,current);
	}
	
	private static boolean convert(){
		int i,j;
		f = new TreeSet();
		s = new TreeSet();
		String aa,bb;
		for (i=0;i<n;i++){
			aa="";bb="";
			for (j=0;j<l;j++){
				aa+=""+a[i][j];
				bb+=""+b[i][j];
			}
			f.add(aa);
			s.add(bb);
		}
		
		Iterator<String> itf = f.iterator();
		Iterator<String> its = s.iterator();
		while(itf.hasNext()&&its.hasNext()) {
			if(!itf.next().equals(its.next())){
				return false;
			}
		}
		return true;
	}
	
	
}
