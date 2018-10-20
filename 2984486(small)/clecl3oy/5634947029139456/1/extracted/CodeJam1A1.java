import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class CodeJam1A1 {

	public static void main(String[] args) {
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			int numTestCase = Integer.valueOf(br.readLine());
			for(int testCase=1; testCase<=numTestCase; testCase++)
			{
				System.out.print("Case #" + testCase + ": ");
				
				// Read each test case
				// Array
				String[] qArray = br.readLine().split(" ");
				// Do you need to use long or double?
				int n = Integer.valueOf(qArray[0]);
				int l = Integer.valueOf(qArray[1]);
				
				String[] lArray = br.readLine().split(" ");
				ArrayList<String> lList = new ArrayList<String>();
				for(int i=0; i<n; i++)
				{
					lList.add(lArray[i]);
				}
				Collections.sort(lList);
				String[] dArray = br.readLine().split(" ");
				ArrayList<String> dList = new ArrayList<String>();
				for(int i=0; i<n; i++)
				{
					dList.add(dArray[i]);
				}
				Collections.sort(dList);
				// Logic goes here
				int ans = 0;
				boolean possible = false;
				for(int numBit=0; numBit<=l; numBit++)
				{
					
					//for(int i=0; i<n; i++)
					//{
						String device = dList.get(0);
						for(int j=0; j<n; j++)
						{
							ArrayList<String> lListClone = (ArrayList<String>)lList.clone();
							ArrayList<String> dListClone = (ArrayList<String>)dList.clone();
							
							String outlet = lListClone.get(j);
							ArrayList<Integer> diffBitList = diffBit(device, outlet);
							if(diffBitList.size() == numBit)
							{
								dListClone.remove(0);
								lListClone.remove(j);
								possible = findMatch(diffBitList, dListClone, lListClone);
								if(possible)
								{
									ans = numBit;
									break; // for j
								}
							}
						}
					//}
						if(possible)
						{
							break; //numBit
						}
				}
				
				if(possible)
				{
				
				// Print output
					System.out.println(ans);
				}
				else
				{
					System.out.println("NOT POSSIBLE");
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static ArrayList<Integer> diffBit(String device, String outlet)
	{
		ArrayList<Integer> diffBitList = new ArrayList<Integer>();
		for(int i=0; i<device.length(); i++)
		{
			if(device.charAt(i) != outlet.charAt(i))
			{
				diffBitList.add(i);
			}
		}
		return diffBitList;
	}
	
	public static boolean findMatch(ArrayList<Integer> diffBitList, ArrayList<String> dListClone, ArrayList<String> lListClone)
	{
		if(dListClone.isEmpty())
			return true;
		
		//for(int i=0; i<dListClone.size(); i++)
		//{
			String device = dListClone.get(0);
			for(int j=0; j<lListClone.size(); j++)
			{
				String outlet = lListClone.get(j);
				ArrayList<Integer> diffBitListTemp = diffBit(device, outlet);
				if(diffBitList.equals(diffBitListTemp))
				{ 
					dListClone.remove(0);
					lListClone.remove(j);
					return findMatch(diffBitList, dListClone , lListClone);
				}
			}
		//}
		return false;
	}

}
