import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class ProblemA {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		ProblemA p = new ProblemA();
		
		p.Solve();
		//p.Test();
	}
	
	public void Solve()
	{
		Scanner sc = new Scanner(System.in);
		
		String line = sc.nextLine();
		
		int T = Integer.parseInt(line);
		
		for(int caseNum = 1; caseNum <= T; caseNum++)
		{
			line = sc.nextLine();
			
			Scanner scanner = new Scanner(line);
			
			int N = scanner.nextInt();
			int L = scanner.nextInt();
			
			line = sc.nextLine();
			ArrayList<String> init = getList(line, N, L);
			
			line = sc.nextLine();
			ArrayList<String> goal = getList(line, N, L);
			
			Collections.sort(goal);
			int result = Solve(init, goal, N, L, 0);
			if(result < 0)
			{
				System.out.println("Case #" + caseNum + ": NOT POSSIBLE");
			}
			else
			{
				System.out.println("Case #" + caseNum + ": " + result);
			}
		}
	}
	
	public int Solve(ArrayList<String> input_curr, ArrayList<String> goal, int N, int L, int round)
	{		
		Collections.sort(input_curr);
		
		ArrayList<String> curr = new ArrayList<String>();
		
		for(int i = 0; i < N; i++)
		{
			curr.add(input_curr.get(i));
		}
		
		if(round == L)
		{
			for(int i = 0; i < N; i++)
			{
				if( !curr.get(i).equalsIgnoreCase(goal.get(i)) )
				{
					return -1;
				}
			}
			
			return 0;
		}
		
		int numZeroCurr = countIndexZeroes(round, curr, N, L);
		int numZeroGoal = countIndexZeroes(round, goal, N, L);
		
		if(numZeroCurr == numZeroGoal || N - numZeroCurr == numZeroGoal)
		{
			ArrayList<String> currCopy = new ArrayList<String>();
			
			for(int i = 0; i < N; i++)
			{
				currCopy.add(curr.get(i));
			}
			
			int numFlipsA = Solve(curr, goal, N, L, round+1);
			
			currCopy = getFlippedRound(currCopy, round);
			int numFlipsB = Solve(currCopy, goal, N, L, round+1);
			
			if(numFlipsB + 1 < numFlipsA && numFlipsB > -1)
			{
				return numFlipsB + 1;
			}
			else if(numFlipsA < 0 && numFlipsB >= 0)
			{
				return numFlipsB + 1;
			}
			else
			{
				return numFlipsA;
			}
		}
		else
		{
			return -1;
		}
	}
	
	public void Test()
	{
		String test1 = "0";
		String test2 = "00";
		String test3 = "000";
		
		ArrayList<String> list = new ArrayList<String>();
		
		list.add(test1);
		ArrayList<String> list1 = getFlippedRound(list, 0);
		System.out.println(list1.get(0));
		
		list.remove(0);
		list.add(test2);
		ArrayList<String> list2 = getFlippedRound(list, 1);
		System.out.println(list2.get(0));
		
		list.remove(0);
		list.add(test3);
		ArrayList<String> list3 = getFlippedRound(list, 2);
		System.out.println(list3.get(0));
	}
	
	public ArrayList<String> getFlippedRound(ArrayList<String> list, int round)
	{
		for(int i = 0; i < list.size(); i++)
		{
			String elem = list.get(i);
			String newElem = new String();
			
			char ch = elem.charAt(round);
			
			String prefix = new String();
			String suffix = new String();
			
			if(round > 0)
				prefix = elem.substring(0, round);
			
			if(round < elem.length())
				suffix = elem.substring(round+1, elem.length());
			
			if(ch == '0')
			{
				newElem = prefix + "1" + suffix; 
			}
			else
			{
				newElem = prefix + "0" + suffix;
			}
			
			if(newElem.length() < elem.length())
			{
				System.out.println("ERROR");
			}
			
			list.set(i, newElem);
		}
		
		return list;
	}
	
	public int countIndexZeroes(int round, ArrayList<String> list, int N, int L)
	{
		int numLastZero = 0;
		for(int i = 0; i < N; i++)
		{
			if(list.get(i).charAt(round) == '0')
				numLastZero++;
		}
		
		return numLastZero;
	}
	
	public int SolveAux(ArrayList<String> init, ArrayList<String> goal, int N, int L)
	{
		int result = -1;
		
		return result;
	}
	
	public ArrayList<String> getList(String line, int N, int L)
	{
		ArrayList<String> list = new ArrayList<String>();
		Scanner scanner = new Scanner(line);
		
		for(int i = 0; i < N; i++)
		{
			list.add(scanner.next());
		}
		
		scanner.close();
		
		return list;
	}

}
