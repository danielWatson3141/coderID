using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Random
{

	class Random
	{
	
	static int LCS(List<int> permutation)
	{
		int n = permutation.Count;
		List<List<int>> C = new  List<List<int>> ();
		for (int  i = 0; i < n; ++i)
		{
			C.Add(new List<int>());
			for (int j = 0; j < n; ++j)
				C[i].Add(0);
		}
		for (int  i = 1; i < n; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (permutation[i] == j)
				{
					C[i][j] = C[i-1][j-1] + 1;
				}
				else
				{
					C[i][j] = C[i-1][j] > C[i][j-1]? C[i-1][j] : C[i][j-1];
				}
			}
			
		}
		return C[n-1][n-1];	
			
	}
	
	static int score(List<int> permutation)
	{
		return LCS(permutation);
	
	}

	
	static List<string> solveProblem(StreamReader reader)
	{
		
		string line;
		//List<string> input = new List<string>(line.Split().Select(token => token).ToArray());
		int n = 120;
		List<int> scores = new List<int>();
		Console.WriteLine(1);
		for (int i = 0; i < n; ++i)
		{
			line = reader.ReadLine();
			line = reader.ReadLine();
			List<int> input = new List<int>(line.Split().Select(token => int.Parse(token)).ToArray());
			scores.Add(score(input));
			
		}
		Console.WriteLine(2);
		List<int> sortedScores = new List<int>(scores);
		sortedScores.Sort();
		int median = sortedScores[n/2];
		int totalGood = n/2;
		List<string> answers = new List<string>();
		Console.WriteLine(3);
		for(int i = 0; i < n; ++i)
		{
			answers.Add("");
		}
		for(int i = 0; i < n; ++i)
		{
			if (scores[i] > median)
			{
				answers[i] = "BAD";
			}
			else if (scores[i] < median)
			{
				answers[i] = "GOOD";
				totalGood--;
			}
			else 
			{
				if (scores[i] == median && totalGood > 0)
				{
					answers[i] = "GOOD";
					totalGood--;
				}
				else
				{
					answers[i] = "BAD";
				}
			}

		}
		Console.WriteLine(4);
	
		return answers;
	}

        static void Main(string[] args)
        {
//			StreamReader reader = new StreamReader("C-small-practice-2.in");
			StreamReader reader = new StreamReader("C-small-attempt0.in");
//			StreamReader reader = new StreamReader("B-small-practice2.txt");
//            StreamReader reader = new StreamReader("C-large-practice-2b.in");
//            StreamReader reader = new StreamReader("C-small-practice.in");
//	    StreamReader reader = new StreamReader("B-large-practice.in");
//            StreamWriter writer = new StreamWriter("output3b.txt");
            StreamWriter writer = new StreamWriter("output.txt");
			string line = reader.ReadLine();
			int total = int.Parse(line);
			List<string> answers = solveProblem(reader);

			StringBuilder results = new StringBuilder();

//            while ((line = reader.ReadLine()) != null)
  //          {
			for (int i = 1; i <= total; ++i)
			{
				string tempResult = "Case #" + i.ToString() + ": " + answers[i-1];
				Console.WriteLine(tempResult);
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
