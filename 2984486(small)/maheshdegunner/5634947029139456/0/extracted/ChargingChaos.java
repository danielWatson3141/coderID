import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedHashSet;


public class ChargingChaos {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader inputStream = null;
        PrintWriter outputStream = null;

        try {
            inputStream = new BufferedReader(new FileReader("C:\\Users\\Maheshwaran\\Downloads\\CodeJam\\A-small-attempt0.in"));
            outputStream = new PrintWriter(new FileWriter("C:\\Users\\Maheshwaran\\Downloads\\CodeJam\\round1ap1smallout.txt"));

            
            String num = inputStream.readLine();
            //System.out.println("Number of test cases "+num);
           // System.out.println(num);
            for(int i=1;i<Integer.valueOf(num)+1;i++)
            {
            	String[] l1=inputStream.readLine().split(" ");
            	int n=Integer.parseInt(l1[0]);
            	int l=Integer.parseInt(l1[1]);
            	String l2[]=inputStream.readLine().split(" ");
            	ArrayList<String> al2=new ArrayList<String>();
            	for(int m=0;m<l2.length;m++)
            		al2.add(l2[m]);
            	ArrayList<String> al3=new ArrayList<String>();
            	String l3[]=inputStream.readLine().split(" ");
            	for(int m=0;m<l2.length;m++)
            		al3.add(l3[m]);
            	
            	int f=1;
            	for(int c=0;c<al2.size();c++)
            	{
            		if(!al3.contains(al2.get(c)))
            			f=0;
            	}
            	
            	if(f==1)
            	{
            		//System.out.println("Case #"+i+": 0");
            		outputStream.write("Case #"+i+": 0"+"\n");
            		continue;
            	}
            	
            	String set[] = new String[l];
            	for(int fi=0;fi<l;fi++)
            	{
            		Integer fc=new Integer(fi);
            		set[fi]=fc.toString();
            	}
            	 LinkedHashSet myPowerSet = powerset(set);
                 
            	 Iterator ip=myPowerSet.iterator();
            	 int flag=1;
   		      while(ip.hasNext())
   		      {
					LinkedHashSet lhs = (LinkedHashSet) ip.next();
					if (lhs.size() > 0) {
						Iterator lhi = lhs.iterator();
						flag = 1;
						StringBuffer sb = new StringBuffer();
						ArrayList<StringBuffer> al2t = new ArrayList<StringBuffer>();
						for (int y = 0; y < al2.size(); y++) {
							StringBuffer sbuf = new StringBuffer();
							sbuf.append(al2.get(y));
							al2t.add(sbuf);
						}
						while (lhi.hasNext()) {
							if(flag==0)
								flag=1;
							int j = Integer.parseInt(lhi.next().toString());
							for (int k = 0; k < n; k++) {

								if (al2t.get(k).charAt(j) == '0')
									al2t.get(k).setCharAt(j, '1');
								else if (al2t.get(k).charAt(j) == '1')
									al2t.get(k).setCharAt(j, '0');
								if (!al3.contains(al2t.get(k).toString()))
									flag = 0;
							}
						}
						if (flag == 1) {
							//System.out.println("Case #" + i + ": " + lhs.size());
							outputStream.write("Case #" + i + ": " + lhs.size()+"\n");
							break;
						}
					}
   		    	  
   		      }
            	 
                 if(flag==0)
                 {
                	 //System.out.println("Case #" + i + ": NOT POSSIBLE");
                	 outputStream.write("Case #" + i + ": NOT POSSIBLE"+"\n");
                 }
            	/*int flag=1;
            	for(int j=0;j<l;j++)
            	{
            		flag=1;
            		for(int k=0;k<n;k++)
            		{
            	
            			StringBuffer sb=new StringBuffer();
            			sb.append(al2.get(k));
            			if(sb.charAt(j)=='0')
            				sb.setCharAt(j, '1');
            			else if(sb.charAt(j)=='1')
            				sb.setCharAt(j, '0');
            			if(!al3.contains(sb.toString()))
            				flag=0;
            		}
            		if(flag==1)
            			break;
            	}
            	if(flag==1)
            	{
            		System.out.println("Case #"+i+": 1");
            		continue;
            	}*/
            	
            }
            
            
            
            inputStream.close();
            outputStream.close();
        } catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	private static LinkedHashSet powerset(String[] set) {
	     
	       //create the empty power set
	       LinkedHashSet power = new LinkedHashSet();
	     
	       //get the number of elements in the set
	       int elements = set.length;
	     
	       //the number of members of a power set is 2^n
	       int powerElements = (int) Math.pow(2,elements);
	     
	       //run a binary counter for the number of power elements
	       for (int i = 0; i < powerElements; i++) {
	         
	           //convert the binary number to a string containing n digits
	           String binary = intToBinary(i, elements);
	         
	           //create a new set
	           LinkedHashSet innerSet = new LinkedHashSet();
	         
	           //convert each digit in the current binary number to the corresponding element
	            //in the given set
	           for (int j = 0; j < binary.length(); j++) {
	               if (binary.charAt(j) == '1')
	                   innerSet.add(set[j]);
	           }
	         
	           //add the new set to the power set
	           power.add(innerSet);
	         
	       }
	     
	       return power;
	   }
	 
	   /**
	     * Converts the given integer to a String representing a binary number
	     * with the specified number of digits
	     * For example when using 4 digits the binary 1 is 0001
	     * @param binary int
	     * @param digits int
	     * @return String
	     */
	   private static String intToBinary(int binary, int digits) {
	     
	       String temp = Integer.toBinaryString(binary);
	       int foundDigits = temp.length();
	       String returner = temp;
	       for (int i = foundDigits; i < digits; i++) {
	           returner = "0" + returner;
	       }
	     
	       return returner;
	   } 

}
