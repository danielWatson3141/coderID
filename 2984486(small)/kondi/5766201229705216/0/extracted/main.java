

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

public class main {

	public static void main(String[] args) throws Exception {


		Scanner sc = new Scanner(new File("in.txt"));
		FileWriter out = new FileWriter(new File("out.txt"));
		int T = new Integer(sc.nextLine());
		for(int i = 1 ; i < T+1 ; i++)
		{
			int res = 0;
			int N = sc.nextInt();
			ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
			for(int j = 0 ; j < N ; j++ )
			{
				adj.add(new ArrayList<Integer>());
			}
			for(int j = 0 ; j < N-1 ; j++ )
			{
				int first = sc.nextInt();
				int second = sc.nextInt();
				adj.get(first-1).add(second-1);
				adj.get(second-1).add(first-1);
			}
			
			for(int j = 0 ; j< adj.size() ; j++)
			{
				System.out.println(adj.toString() );
			}
			int req = 999999999;
			for(int j = 0 ; j < N; j++)
			{
				System.out.println("for index "+ j);
				//assume that this node is root
				int required = getRequired(adj , j , new ArrayList<Integer>());
				System.out.println("returns " + required);
				if(required < req)
					req = required;
			}
			System.out.println("Case #"+i+": "+req);
			out.write("Case #"+i+": "+req+"\n");
			try{ sc.nextLine();}
			catch(Exception e){}

		}
		out.flush();
		sc.close();
		out.close();
	}

	private static   int   getRequired(ArrayList<ArrayList<Integer>> adj, int j , ArrayList<Integer> above) {
		ArrayList <Integer> mychilds = new ArrayList<Integer>();
		ArrayList <Integer > myneighbours =  adj.get(j);
		ArrayList <Integer> newabove = new ArrayList<Integer>();
		for(int i = 0; i < myneighbours.size() ; i++)
			mychilds.add(myneighbours.get(i));
		for(int i = 0 ; i < above.size() ; i++){
			mychilds.remove(above.get(i));
			newabove.add(above.get(i));
		}
		if(mychilds.size() == 0)
			return 0;		
		newabove.add(j);
		if(mychilds.size() == 1)
		{
			return(getnumber(adj , mychilds.get(0) , newabove) );
		}
		//System.out.println("          "+j+"  " + mychilds.toString() +  "   "  + newabove.toString() + "    " );
		int [] number = new int [mychilds.size()];
		int [] cost = new int[mychilds.size()];
		for(int i = 0 ;i < mychilds.size() ; i++)
		{
			 number[i] = getnumber(adj, mychilds.get(i), newabove);
			cost[i] = getRequired (adj, mychilds.get(i), newabove);
		}
		int numbersum = 0;
		int costsum = 0;
		int best = 999999999;		
		for(int i = 0 ; i < number.length ; i++)
		{
			numbersum+=number[i];
			costsum+=cost[i];
		}
		System.out.println("            " + j+"  " + costsum +  "   "  + numbersum);
		System.out.println("            " + j+"  " + Arrays.toString(number));
		System.out.println("            " + j+"  " +Arrays.toString(cost));
		for(int i = 0; i < number.length ; i++)
		{
			for(int h = 0 ; h < number.length ; h++)
			{
				 if(i!=h){
				int cc = numbersum - number[i] -number[h] + cost[i] + cost[h];
				if(cc< best)
				{
					best = cc;
				}
				 }
			}
		}
		System.out.println("          "+j+"  " + mychilds.toString() +  "   "  + newabove.toString() + "    " +best);
		return best;
	}
	
	
	private static int getnumber(ArrayList<ArrayList<Integer>> adj,
			Integer j, ArrayList<Integer> above) {
		int ret = 1;
		ArrayList <Integer> newabove = new ArrayList<Integer>();
		ArrayList <Integer> mychilds = new ArrayList<Integer>();
		ArrayList <Integer > myneighbours =  adj.get(j);
		for(int i = 0; i < myneighbours.size() ; i++)
			mychilds.add(myneighbours.get(i));
		for(int i = 0 ; i < above.size() ; i++){
			mychilds.remove(above.get(i));
			newabove.add(above.get(i));
		}
		newabove.add(j);
		for(int i = 0; i < mychilds.size() ; i++)
			ret+=getnumber(adj, mychilds.get(i) , newabove);
		return ret;
	}


	 
	 
}

class TreeNode implements Iterable<TreeNode> {

	  private Set<TreeNode> children;

	  public TreeNode() {
	    children = new HashSet<TreeNode>();
	  }

	  public boolean addChild(TreeNode n) {
	    return children.add(n);
	  }

	  public boolean removeChild(TreeNode n) {
	    return children.remove(n);
	  }

	  public Iterator<TreeNode> iterator() {
	    return children.iterator();
	  }
	}
