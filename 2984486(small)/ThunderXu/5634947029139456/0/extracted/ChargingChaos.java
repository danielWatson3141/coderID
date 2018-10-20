import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;


public class ChargingChaos {

	public void solve()
	{
		Scanner sc = new Scanner(System.in);
		int numTest = sc.nextInt();
		for(int i=0;i<numTest;i++)
		{
			int N = sc.nextInt();
			int L = sc.nextInt();
			ArrayList<String> outlets = new ArrayList<String>();
			ArrayList<String> devices = new ArrayList<String>();
			for(int y=0;y<N;y++)
			{
				outlets.add(sc.next());
			}
			for(int z=0;z<N;z++)
			{
				devices.add(sc.next());
			}
			boolean solved = false;
			for(int fn=0;fn<=L;fn++)
			{
				if(subFlip(outlets, devices, 0, fn))
				{
					System.out.printf("Case #%d: %d\n", i+1, fn);
					solved = true;
					break;
				}
			}
			if(!solved)
			{
				System.out.printf("Case #%d: NOT POSSIBLE\n", i+1);
			}
			
			
		}
	}
	
	private boolean subFlip(ArrayList<String> outlets, ArrayList<String> devices, int index, int remain)
	{
		if(remain==0)
		{
			return isSame(outlets, devices);
		}
		
		if(index>=devices.get(0).length())
		{
			return false;
		}
		
		
			ArrayList<String> dev1 = (ArrayList<String>)devices.clone();
			ArrayList<String> dev2 = (ArrayList<String>)devices.clone();
			flipBit(dev2, index);
			return subFlip(outlets, dev1, index+1, remain)||subFlip(outlets, dev2, index+1,remain-1);
		
	}
	
	private void flipBit(ArrayList<String> arr, int index)
	{
		for(int i=0;i<arr.size();i++)
		{
			if(arr.get(i).charAt(index)=='0')
			{
				arr.set(i, arr.get(i).substring(0,index)+"1"+ arr.get(i).substring(index+1));
			}
			else
			{
				arr.set(i, arr.get(i).substring(0,index)+"0"+ arr.get(i).substring(index+1));
			}
		}
	}
	private boolean isSame(ArrayList<String> arr1, ArrayList<String> arr2)
	{
		HashSet<String> set = new HashSet<String>();
		for(String str: arr1)
		{
			set.add(str);
		}
		for(String str: arr2)
		{
			if(!set.contains(str))
			{
				return false;
			}
		}
		return true;
		
	}
}
