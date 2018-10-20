package Round1A;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

import Round1A.Q1.SortedPair;
/**
 * @author Amit Jacob
 *
 */
public class Q1 {

	/**
	 * @param args - Input File Path
	 * @throws IOException 
	 */
	private static String NOT_POSSIBLE = "NOT POSSIBLE";
	public static class SortedPair
	{
		public String mask;
		public int id;
		public SortedPair(int id,String mask)
		{
			this.mask=mask;
			this.id=id;
		}
	}
	public static class SortedComp implements Comparator<SortedPair>
	{

		@Override
		public int compare(SortedPair arg0, SortedPair arg1) {
			int i1;
			i1=arg0.mask.compareTo(arg1.mask);
			if(i1!=0)
				return i1;
			return arg0.id-arg1.id;
		}
	}
	public static void main(String[] args) throws IOException {
		//Reading the input file:
		String path=args[0];
		File file = new File(path);
		BufferedReader br = new BufferedReader(new FileReader(file));
		String line;
		//Writing the output file:
		File fileout = new File("output.txt");
		fileout.createNewFile();
	    FileWriter writer = new FileWriter(fileout);
	    //var declarations:
	    int N,L;
	    String[] nums;
	    String[] initFlow;
	    String[] finalFlow;
	    SortedPair[] arr;
	    Comparator<SortedPair> pairComp = new SortedComp();
	    String curStr;
	    int checkedId;
	    int[] PermArr;
	    boolean isValid = false;
	    Stack<String> sols = new Stack<String>();
	    int b;
	    //Begin reading:
  		line=br.readLine();
  		int nTests = Integer.parseInt(line);
  		for(int j=0;j<nTests;++j)
  		{
  			line=br.readLine();
  			nums=line.split(" ");
  			N=Integer.parseInt(nums[0]);
  			L=Integer.parseInt(nums[1]);
  			line=br.readLine();
  			initFlow=line.split(" ");
  			line=br.readLine();
  			finalFlow=line.split(" ");
  			arr=new SortedPair[N*N];
  			for(int i=0;i<N;++i)
  			{
  				for(int k=0;k<N;++k)
  	  			{
  	  				arr[i*N+k]=new SortedPair(k, getMask(initFlow[i],finalFlow[k],L));
  	  			}
  			}
			Arrays.sort(arr, pairComp);
			checkedId=0;
			
			while(checkedId<N*N)
			{
				curStr=arr[checkedId].mask;
				b=0;
				PermArr=new int[N];
				while(b<N&&checkedId+b<N*N&&arr[checkedId+b].mask.equals(curStr))
				{
					PermArr[arr[checkedId+b].id]+=1;
					b=b+1;
				}
				if(b>0)
					checkedId=checkedId+b;
				isValid=true;
				for(int i=0;i<N;++i)
				{
					if(PermArr[i]!=1)
					{
						isValid=false;
						break;
					}
				}
				if(isValid)
				{
					if(b>0)
						sols.push(arr[checkedId-1].mask);
					else
						sols.push(arr[checkedId].mask);
				}
			}
			if(sols.isEmpty())
			{
				writer.write("Case #"+(j+1)+": " + NOT_POSSIBLE + "\n");
			}
			else
			{
				int minSol=L+1;
				while(!sols.isEmpty())
				{
					minSol=Math.min(minSol,getNOnes(sols.pop()));
				}
				writer.write("Case #"+(j+1)+": " + minSol + "\n");
			}
			writer.flush();
  		}
  		writer.close();
	}
	private static int getNOnes(String str) {
		int m=0;
		char[] arr= str.toCharArray();
		for(int i=0;i<str.length();++i)
		{
			if(arr[i]=='1')
				++m;
		}
		return m;
	}
	private static String getMask(String string1, String string2,int L) {
		String mask = "";
		for(int i=0;i<L;++i)
		{
			if(string1.charAt(i)!=string2.charAt(i))
				mask=mask+"1";
			else
				mask=mask+"0";
		}
		return mask;
	}

}
