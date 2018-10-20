package codejam2014.round1A;
import java.util.*;
import java.io.*;
/*
 * Auther : dibakar.nandi@gmail.com
 */

public class DibakarNandiRound1AQA {
    final static String PROBLEM_NAME = "A-small-attempt0";
    final static String WORK_DIR = "E:\\CodeJam\\"+PROBLEM_NAME;

    void solve(Scanner sc, PrintWriter pw) {
       int noOfDevice = sc.nextInt();
       int noOfSwitch = sc.nextInt();
       int change[]=new int[noOfSwitch]; 
       String flow[]=new String[noOfDevice];
       String tempFlow[]=new String[noOfDevice];
       int changeSwch=999;
       
       String flowRequired[]=new String[noOfDevice];
       
        for(int i=0;i<noOfDevice;i++)
        {
        	flow[i]=sc.next();
        	//System.out.println(flow[i]);
        }
        for(int i=0;i<noOfDevice;i++)
        {
        	flowRequired[i]=sc.next();
        //	System.out.println(flowRequired[i]);
        }
        
        boolean matching=true;
        for(int m=0;m<noOfDevice;m++)
        {
	   		 matching=false;
	   		 for(int t=0;t<noOfDevice;t++){
	       		 if(flow[t].equals(flowRequired[m])){
	       			 matching=true;
	       			 break;
	       		 }
	   		 }
	   		 if(!matching)
	   			 break;
	   	
        }
   	 
	   	if(matching )
	   		changeSwch=0;
	   	
   	
        
        
        for(int i=0;i<noOfDevice;i++)
        {
        	int tempChangeSwch=0;
        	System.out.println(flowRequired[i]+"  "+flow[0]);
        	
        	for(int j=0;j<noOfSwitch;j++)
        		change[j]=0;
        
        	for(int j=0;j<noOfDevice;j++)
        		tempFlow[j]=flow[j];
        	
        	for(int k=0;k<noOfSwitch;k++)
        	{
        		if(flowRequired[i].charAt(k)!=flow[0].charAt(k)){
        			change[k]=1;
        			System.out.println("Change in "+k);
        			tempChangeSwch++;
        		}
        		
        	}
        	
        	for(int j=0;j<noOfDevice;j++)
        	{	
        		char tempChr[]=tempFlow[j].toCharArray();
        		for(int k=0;k<noOfSwitch;k++)
        		{
        			if(change[k]==1){
        				if(tempChr[k]=='1')
        					tempChr[k]='0';
        				else
        					tempChr[k]='1';
        			}
        			
        		}
        		String tmp="";
        		for(int k=0;k<noOfSwitch;k++)
        		{
        			tmp+=tempChr[k];
        		}
        		tempFlow[j]=tmp;
        		System.out.println("## "+tempFlow[j]);
        	}
        	
        	matching=true;
        	 for(int m=0;m<noOfDevice;m++)
             {
        		 matching=false;
        		 for(int t=0;t<noOfDevice;t++){
        			 System.out.println("@@@ "+t+"  "+tempFlow[t]+" "+flowRequired[m]);
	        		 if(tempFlow[t].equals(flowRequired[m])){
	        			 System.out.println("@@@ Matched");
	        			 matching=true;
	        			 break;
	        		 }
        		 }
        		 if(!matching)
        			 break;
        	
             }
        	 
        	if(matching && changeSwch>tempChangeSwch)
        		changeSwch=tempChangeSwch;
        	
        	
        }
      
        
        
        if(changeSwch==999){
	        System.out.println("NOT POSSIBLE");
	        pw.print("NOT POSSIBLE");
        }
        else
        {
        	System.out.println(changeSwch);
	        pw.print(changeSwch);
        }
        
    }
    
    public void shorting(int max,float speed[],float pos[])
    {
	    	for(int j=0;j<max;j++)
	    	{
	    		int tpos=j;
	    		for(int k=j;k<max;k++)
	    		{
    		  if(pos[k]<pos[tpos])
    			  tpos=k;
    		}
    		float tmp=0;
    		
    		tmp=pos[j];
    		pos[j]=pos[tpos];
    		pos[tpos]=tmp;
    		
    		tmp=speed[j];
    		speed[j]=speed[tpos];
    		speed[tpos]=tmp;
    			
    	}

    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + ".in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + ".out"));
        int caseCnt = sc.nextInt();

        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new DibakarNandiRound1AQA().solve(sc, pw);
            if(caseNum+1<caseCnt)
            	pw.print("\n");
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
