import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;


public class ChargingChaos {

	static PrintWriter pw=null;
	static int totalCases=0;
	public static void main(String[] args) throws IOException{
		
			
			BufferedWriter bw = null;
			BufferedReader br = null;
			try {
				File outputFile=new File("output.txt");
				if(outputFile.exists())
				{
					outputFile.delete();
				}
				if(!outputFile.createNewFile())
				{
					System.out.println("Output file not created.");
					return;
				}
				File f=new File("A-large-practice.in");
				if(!f.exists())
				{
					System.out.println("A-large-practice.in doesn't exist.");
					return;
				}
				bw = null;
				pw= new PrintWriter(bw=new BufferedWriter(new FileWriter(outputFile, true)));
				
				br = null;
				try {
					br=new BufferedReader(new FileReader(f));
				} catch (FileNotFoundException e) {
					
					e.printStackTrace();
				}
				String line;
				int caseNumber=1;
				totalCases=Integer.parseInt(br.readLine());
				nextCase:
				while((line=br.readLine())!=null)
				{
					ArrayList<String> out=new ArrayList<String>();
					ArrayList<String> dev=new ArrayList<String>();
					StringTokenizer st=new StringTokenizer(line," ");
					int n=Integer.parseInt(st.nextToken().trim());
					int l=Integer.parseInt(st.nextToken().trim());
					line=br.readLine();
					StringTokenizer st2=new StringTokenizer(line," ");
					while(st2.hasMoreTokens())
					{
						out.add(st2.nextToken().trim());
					}
					line=br.readLine();
					StringTokenizer st3=new StringTokenizer(line," ");
					while(st3.hasMoreTokens())
					{
						dev.add(st3.nextToken().trim());
					}
					solveCC(caseNumber,n,l,out,dev);
					
					caseNumber++;
				}
			}finally{
			bw.close();
			pw.close();
			br.close();
			}
	}
	private static void solveCC(int caseNumber,int n,int l,ArrayList<String> out,ArrayList<String> dev)
	{
		HashMap<String,Integer> diffList=new HashMap<String,Integer>();
		out:
		for(int i=0;i<out.size();i++)
		{
			HashMap<String,Integer>	tempList=new HashMap<String,Integer>();
			for(int j=0;j<dev.size();j++)
			{
				
				if(i==0)
				{
					getCharacterDifference(out.get(i), dev.get(j),true,diffList,tempList);
					continue;
				}
				if(diffList.isEmpty())
				{
					break out;
				}
				getCharacterDifference(out.get(i), dev.get(j),false,diffList,tempList);
				
			}
			if(i!=0)
			{
			diffList.clear();
			diffList.putAll(tempList);
			}
		}
		pw.printf("Case #"+caseNumber+": ");
		System.out.printf("Case #"+caseNumber+": ");
		if(diffList.isEmpty())
		{
			pw.printf("NOT POSSIBLE");
			System.out.printf("NOT POSSIBLE");
		}
		else
		{
			pw.printf(getLeastNumber(diffList).toString());
			System.out.printf(getLeastNumber(diffList).toString());
		}
		if(totalCases!=caseNumber)
		{
			pw.printf("\n");
			System.out.printf("\n");
		}
	}
	private static boolean getCharacterDifference(String s1,String s2,boolean isLoad,HashMap<String,Integer> diffList,HashMap<String,Integer> tempList)
	{
		int count=0;
		String diffString=new String("");
		if(s1.equals(s2))
		{
			if(diffList.containsKey(""))
			{
				tempList.put("",0);
				return true;
			}
			if(isLoad)
			{
				diffList.put("",0);
				return true;
			}
		}
		char[] c1  = s1.toCharArray();
		char[] c2 = s2.toCharArray();
		for(int i = 0; i < c1.length; i++)
		{
		        if (c1[i] != c2[i])
		        {
		            count++;
		            diffString+=i;
		        }
		}
		if(isLoad)
		{
			diffList.put(diffString,count);
			return true;
		}
		if(diffList.containsKey(diffString)&&diffList.get(diffString).equals(count))
		{
			tempList.put(diffString,count);
			return true;
		}
		return false;		
	}
	private static Integer getLeastNumber(HashMap<String,Integer> list)
	{
		ArrayList<Integer> listInt=new ArrayList<Integer>(list.values());
		if(list.isEmpty())
			return -1;
		
		Integer leastNumber=listInt.get(0);
		for(int i=0;i<listInt.size();i++)
		{
			
			if(leastNumber>listInt.get(i))
			{
				leastNumber=listInt.get(i);
			}
		}
		return leastNumber;
	}

}
