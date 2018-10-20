import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Solution{
	static int t,n,s,e;
	static int[] a;
	static int[] d;
	static int[][] ed;
	static int answer,nodes,edges,global;
	static String line;
	static String[] row;
	
	public static void main(String [ ] args) throws IOException{
		int i,j,k;
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt3.in"));
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

		        n = Integer.valueOf(line);
		        a = new int[n];
		        d = new int[n];
		        ed = new int[n][n];
		        for (j=0;j<n;j++){
		        	a[j]=0;
		        	d[j]=0;
		        }
		        
		        for (i=0;i<n;i++){
		        	for (j=0;j<n;j++){
		        		ed[i][j]=0;
		        	}
		        }
	        	for (j=0;j<n-1;j++){
	        		line = br.readLine();
	        		row = line.split("\\s");
	        		s = Integer.valueOf(row[0]);
	        		e = Integer.valueOf(row[1]);
	        		a[s-1]++;
	        		a[e-1]++;
	        		ed[s-1][e-1]=1;
	        		ed[e-1][s-1]=1;
	        	}
	        	answer = 0;
	        	global = n+1;
	        	nodes = n;
	        	edges = n-1;
	        	//delete all unconnected nodes
		        for (j=0;j<n;j++){
		        	if(a[j]==0) {
		        		answer++;
			        	d[j]=1;
		        	}
		        }
		        
		        solve();
		        
    			bw.write("Case #"+(k+1)+": "+global+"\n");
    			//bw.flush();
	        }
	        
			bw.close();

	    } finally {
	        br.close();
	    }
	}
	
	private static void print(){
		for (int j=0;j<n;j++){
        	System.out.print(" "+a[j]);
        }
        System.out.println();
        for (int j=0;j<n;j++){
        	System.out.print(" "+d[j]);
        }
        System.out.println();
	}
	
	
	private static void solve(){
		//check Full
		if(checkConn2() && checkFull())
		{
			global=answer;
			return;
		}
		back(0,0);
	}
	
	private static void back(int j,int deletions){
		int i;
		if (j==n){
			if(checkConn() && checkFull())	{
				if (deletions+answer<global){
					global = deletions+answer;
					print();
					System.out.println("global"+global+"nodes"+nodes+"ed"+edges);
				}
			}
			return;
		}
		
		if(d[j]==0){
				//try to delete node j
				d[j]=1;
				nodes--;
				for (i=j+1;i<n;i++){
					if(ed[i][j]==1){
						ed[i][j]=-1;
						a[i]--;
						a[j]--;
						edges--;
					}
				}
				//try with deletion
				back(j+1,deletions+1);
				//undo
				for (i=j+1;i<n;i++){
					if(ed[i][j]==-1){
						ed[i][j]=1;
						a[i]++;
						a[j]++;
						edges++;
					}
				}
				nodes++;
				d[j]=0;
		}
		//try without deletion
		back(j+1,deletions);
	}
	
	private static boolean checkConn(){
		//all are connected
		int currentEdges=0, currentNodes=0;
		for(int i=0;i<n;i++){
			if(d[i]==0) //skip isolated/deleted
			{
				currentNodes ++;
				currentEdges +=a[i];
			}
		}
		return (2*(currentNodes-1)==currentEdges);
	}
	
	private static boolean checkConn2(){

		return (nodes-1==edges);
	}
	
	private static boolean checkFull(){
		//one node has 2 (root) all have 1 or 3
		//total order is 2*(N-1)
		boolean root = false;
		for(int i=0;i<n;i++){
			if(a[i]<=0 && d[i] ==0|| a[i]>3) {
				return false;
			}
			if(a[i]==2){
				if(!root) root=true;
				else return false; //second root
			}
		}
		return root;
	}
	
}
