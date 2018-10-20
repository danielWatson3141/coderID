import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class CodeJam1A2 {

	public static void main(String[] args) {
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			int numTestCase = Integer.valueOf(br.readLine());
			for(int testCase=1; testCase<=numTestCase; testCase++)
			{
				System.out.print("Case #" + testCase + ": ");
				
				// Read each test case
				// Int
				int numNode = Integer.valueOf(br.readLine());
				int[] numEdgeArray = new int[numNode];
				boolean[][] edgeList = new boolean[numNode][numNode];
				for(int i=0; i< numNode-1; i++)
				{
					// Array
					String[] qArray = br.readLine().split(" ");
					// Do you need to use long or double?
					int v1 = Integer.valueOf(qArray[0])-1;
					int v2 = Integer.valueOf(qArray[1])-1;
					edgeList[v1][v2] = true;
					edgeList[v2][v1] = true;
					numEdgeArray[v1]++;
					numEdgeArray[v2]++;
					
				}
				
				boolean rootCandidate[] = new boolean[numNode];
				for(int i=0; i<numNode; i++)
				{
					rootCandidate[i] = (numEdgeArray[i] == 2);
				}
				// Logic goes here
				int ans = 0;
				
				int min = Integer.MAX_VALUE;
						
				for(int i=0; i<numNode; i++)
				{
					int remove = minRemove(i, edgeList, numEdgeArray, -1);
					if(remove < min)
					{
						min = remove;
					}
				}
				
		/*		for(int numRemove=0; numRemove<numNode; numRemove++)
				{
					for(int i=0; i<numRemove; i++)
					{
						
					}
				}
	*/			
				// Print output
				System.out.println(min);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static int minRemove(int root, boolean[][] edgeList, int[] numEdgeArray, int parent)
	{
		if(parent == -1)
		{
			if(numEdgeArray[root] == 1)
				return Integer.MAX_VALUE;
			
			if(numEdgeArray[root] == 2)
			{
				int minRequired = 0;
				for(int i=0; i<edgeList.length; i++)
				{
					if(edgeList[root][i])
						minRequired += minRemove(i, edgeList, numEdgeArray, root);
				}
				return minRequired;
			}
			else
			{
				int minRequired = 0;
				for(int i=0; i<edgeList.length; i++)
				{
					if(edgeList[root][i])
					{
						minRequired++;
						minRequired += numDes(i, edgeList, root);
						boolean[][] edgeListTemp = edgeList.clone();
						int[] numEdgeArrayTemp = numEdgeArray.clone();
						edgeListTemp[root][i] = false;
						edgeListTemp[i][root] = false;
						numEdgeArrayTemp[root]--;
						numEdgeArrayTemp[i]--;
						minRequired += minRemove(root, edgeListTemp, numEdgeArrayTemp, parent);
					}
					
				}
				return minRequired;
				
			}
		}
		else
		{
			if(numEdgeArray[root] == 1)
				return 0;
			
			if(numEdgeArray[root] == 2)
			{
				return numDes(root, edgeList, parent);
			}
			else if(numEdgeArray[root] == 3)
			{
				int minRequired = 0;
				for(int i=0; i<edgeList.length; i++)
				{
					if(i != parent && edgeList[root][i])
						minRequired += minRemove(i, edgeList, numEdgeArray, root);
				}
				return minRequired;
				
			}
			else
			{
				int minRequired = 0;
				for(int i=0; i<edgeList.length; i++)
				{
					if(edgeList[root][i])
					{
						minRequired++;
						minRequired += numDes(i, edgeList, root);
						boolean[][] edgeListTemp = edgeList.clone();
						int[] numEdgeArrayTemp = numEdgeArray.clone();
						edgeListTemp[root][i] = false;
						edgeListTemp[i][root] = false;
						numEdgeArrayTemp[root]--;
						numEdgeArrayTemp[i]--;
						minRequired += minRemove(root, edgeListTemp, numEdgeArrayTemp, parent);
					}
					
				}
				return minRequired;
			}
		}
		
		
		//System.out.println("Should not be here111111111111111111111111111111111111111111111111111111");
		//return 0;
		
	}
	
	public static int numDes(int root, boolean[][] edgeList, int parent)
	{
		int sumDes = 0;
		for(int i=0; i< edgeList.length; i++)
		{
			if(i != parent && edgeList[root][i])
			{
				sumDes++;
				sumDes += numDes(i, edgeList, root);
			}
		}
		return sumDes;
		
	}
	
	public static boolean isFull(int root, int[] numEdgeArray)
	{
		for(int i=0; i<numEdgeArray.length; i++)
		{
			if(i == root)
			{
				if(numEdgeArray[i] != 2)
					return false;
			}
			else
			{
				if(numEdgeArray[i] != 1 && numEdgeArray[i] != 3)
					return false;
			}
		}
		return true;
	}

}
