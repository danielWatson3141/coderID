package codejam;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.LinkedHashSet;
import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class PR_A2 {
	public static void main(String s[]) throws IOException
	{
		System.setIn(new FileInputStream("A-small-attempt0.in"));
		System.setOut(new PrintStream(new FileOutputStream("A-small-attempt0.out")) );
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedOutputStream output = new BufferedOutputStream(System.out);
		StringBuilder strbldr = new StringBuilder(15000);
		int tcases = Integer.parseInt(br.readLine());
		int k=0;
		Pattern p=Pattern.compile("1");
		nextCase:
		while (k++!=tcases) 
		{
			StringTokenizer stringTokenizer=new StringTokenizer(br.readLine());
			int n=Integer.parseInt(stringTokenizer.nextToken());
			int l=Integer.parseInt(stringTokenizer.nextToken());
			String[] s1=new String[n];
			String[] s2=new String[n];
			stringTokenizer=new StringTokenizer(br.readLine());
			int i=-1;
			while(++i!=n)
				s1[i]=stringTokenizer.nextToken();
			i=-1;
			stringTokenizer=new StringTokenizer(br.readLine());
			while(++i!=n)
				s2[i]=stringTokenizer.nextToken();
			n=s1.length;
			Integer d=0;
			nextPerm:
			while(d<=Math.pow(2, l))
			{	
				//System.out.println("y");
				String bd=normalise(Integer.toBinaryString(d),l);
				Matcher m=p.matcher(bd);
				LinkedHashSet<Integer> tempSet=new LinkedHashSet<Integer>();
				while(m.find())
					tempSet.add(m.start());
				//System.out.println("case: "+bd);
				String ss1[]=new String[s1.length];
				for(i=0;i<ss1.length;i++)
					ss1[i]=s1[i];
				String ss2[]=new String[s2.length];
				for(i=0;i<ss2.length;i++)
					ss2[i]=s2[i];
				i=0;
					for(i=0;i<ss1.length;i++)
					{
						String dev=flip(ss1[i], tempSet);
						//System.out.print(dev+": ");
						int j=0;
						for(j=0;j<ss2.length;j++)
						{
							if(dev.equals(ss2[j]))//flip(ss2[j], tempSet)))
							{
							//	System.out.println(ss2[j]);//+" "+flip(ss2[j], tempSet));
								ss2[j]="";
								break;
							}
						}
						if(j==ss2.length)
							{
						//	System.out.println("uhh");
							d++;
							continue nextPerm;
							}
					}
					if(i==ss1.length)
					{
						strbldr.append("Case #").append(k).append(": ").append(tempSet.size()).append("\n");
						continue nextCase;
					}
				
				d++;
			}


			strbldr.append("Case #").append(k).append(": ").append("NOT POSSIBLE").append("\n");
		}
		output.write(strbldr.toString().getBytes());
		
		output.flush();
		output.close();
	}
	
	public static String normalise(String s,int length)
	{
		if(s.length()==length)
			return s;
		StringBuilder stringBuilder=new StringBuilder();
		for(int i=0;i<length-s.length();i++)
			stringBuilder.append("0");
		stringBuilder.append(s);
		return stringBuilder.toString();
	}
	
	public static String flip(String s,LinkedHashSet<Integer> set)
	{
		if(s.equals(""))
			return s;
		StringBuilder stringBuilder=new StringBuilder();
		int j=0;
		for(Integer i:set)
		{
			
			stringBuilder.append(s.substring(j, i));
			if(s.charAt(i)=='0')
				stringBuilder.append('1');
			else
				stringBuilder.append('0');
			j=i+1;
		}
		if(j!=s.length())
		stringBuilder.append(s.substring(j, s.length()));
		return stringBuilder.toString();
	}
	
}
