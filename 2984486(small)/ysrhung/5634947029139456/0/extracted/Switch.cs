using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Switch
{

	class Switch
	{
	
	static int countOne(List<string> flow, int k)
	{
		int count = 0;
		for (int i = 0; i < flow.Count; ++i)
		{
			if (flow[i][k] == '1')
				count++;
		}
		return count;
	}
	
	static bool determineIdentical(List<string> initialFlow, List<string> finalFlow)
	{
		initialFlow.Sort();
		finalFlow.Sort();
		for (int i = 0; i < initialFlow.Count; ++i)
		{
			if (initialFlow[i] != finalFlow[i])
				return false;
		}
		return true;
	}
	
	static int totalFlips(List<bool> flips)
	{
		int count = 0;
		foreach (bool b in flips)
			if (b) count++;
		return count;
	}
	
	static List<string> flip(List<string> initialFlow, List<bool> flips, int L)
	{
		List<string> newFlow = new List<string>();
		
		foreach (string f in initialFlow)
		{
			string nf = "";
			for (int i = 0; i < L; ++i)
			{
				if (flips[i])
					nf = nf + (f[i] == '1'? '0' : '1');				
				else
					nf = nf + f[i];
			
			}
			newFlow.Add(nf);
		}
		return newFlow;
	}
	
	static bool allTrue(List<bool> combination)
	{
		foreach (bool b in combination)
			if (!b) return false;
		return true;
	}
	
	static void advance(List<bool> combination)
	{
		for (int i = 0; i < combination.Count; ++i)
		{
			if (!combination[i])
			{
				combination[i] = true;
				return;
			}
			else
			{
				combination[i] = false;
			}
		}
	
	}
	
	static bool bruteForce(int n, List<string> initialFlow, List<string> finalFlow, List<bool> flips, out List<bool> additionalFlips)
	{
		// application dependent begin
		additionalFlips = new List<bool>(flips);
		// end
		List<bool> combination = new List<bool>();
		for(int i = 0 ; i < n; ++i)
			combination.Add(false);
		while (!allTrue(combination))
		{
			advance(combination);
			if (trial(combination, initialFlow, finalFlow, flips, out additionalFlips))
				return true;
		}
		return false;
	}
	
	static void print(List<bool> flips)
	{
		foreach ( bool b in flips)
			Console.Write(b + " " );
		Console.WriteLine();
	}
	
	static bool trial(List<bool> combination, List<string> initialFlow, List<string> finalFlow, List<bool> flips, out List<bool> additionalFlips)
	{
		additionalFlips = new List<bool>(flips);
//		print(flips);
		for(int i = 0, index = 0; i < additionalFlips.Count; ++i)
		{
//			Console.WriteLine(index + " " + combination.Count);
			if (!additionalFlips[i])
			{
				if (combination[index])
				{
					additionalFlips[i] = true;
				}
				index++;
			}
		}
//		print(additionalFlips);
		List<string> newFlow = flip(initialFlow, additionalFlips, additionalFlips.Count);
		if (determineIdentical(newFlow, finalFlow))
			return true;
		return false;
	}
	
	static int transform(List<string> initialFlow, List<string> finalFlow, int length, int n)
	{
		List<int> initialDigits = new List<int>();
		List<int> finalDigits = new List<int>();
		for (int i = 0; i < length; ++i)
		{
			initialDigits.Add( countOne(initialFlow, i) );
			finalDigits.Add( countOne(finalFlow, i));
		}
		List<bool> flips = new List<bool>();
		for (int i = 0; i < length; ++i)
		{
			if (initialDigits[i] == finalDigits[i])
				flips.Add(false);
			else if (initialDigits[i] + finalDigits[i] == n)
			{
				flips.Add(true);
			}
			else return -1;
		}
		
		List<string> newFlow = totalFlips(flips) > 0? flip(initialFlow, flips, length) : new List<string>(initialFlow);
		if (determineIdentical(newFlow, finalFlow))
			return totalFlips(flips);
			
		// additional flips needed
		List<bool> additionalFlips = new List<bool>(flips);

		int possibilities = length - totalFlips(flips);
		
		
		if (bruteForce(possibilities, initialFlow, finalFlow, flips, out additionalFlips)) 
			return totalFlips(additionalFlips);
		else return -1;
	}

	
	static string solveProblem(StreamReader reader)
	{
		
		string line = reader.ReadLine();
		List<int> input = new List<int>(line.Split().Select(token => int.Parse(token)).ToArray());
		int n = input[0];
		int L = input[1];
		line = reader.ReadLine();
		List<string> initialFlow = new List<string>(line.Split().Select(token => token).ToArray());

		line = reader.ReadLine();
		List<string> finalFlow = new List<string>(line.Split().Select(token => token).ToArray());
		
		
		int count = transform(initialFlow, finalFlow, L, n);
		if (count < 0) return "NOT POSSIBLE";
		
		
		
		
		
		
		
		
		
		return count.ToString();
	}

        static void Main(string[] args)
        {
//			StreamReader reader = new StreamReader("C-small-practice-2.in");
			StreamReader reader = new StreamReader("A-small-attempt1.in");
//			StreamReader reader = new StreamReader("B-small-practice2.txt");
//            StreamReader reader = new StreamReader("C-large-practice-2b.in");
//            StreamReader reader = new StreamReader("C-small-practice.in");
//	    StreamReader reader = new StreamReader("B-large-practice.in");
//            StreamWriter writer = new StreamWriter("output3b.txt");
            StreamWriter writer = new StreamWriter("output.txt");
			string line = reader.ReadLine();
			int total = int.Parse(line);
			StringBuilder results = new StringBuilder();

//            while ((line = reader.ReadLine()) != null)
  //          {
			for (int i = 1; i <= total; ++i)
			{
				string tempResult = "Case #" + i.ToString() + ": " + solveProblem(reader);
//				Console.WriteLine(tempResult);
				results.AppendLine(tempResult);
				
			}
		//writer.WriteLine(total);
//	    }
			writer.WriteLine(results.ToString());
            reader.Close();
            writer.Close();
        }
    }
}
