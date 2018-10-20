using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;


namespace Round1AProb2
{
    public struct edge
    {
        public edge(int pX, int pY)
        {
            mX = pX;
            mY = pY;
        }
        public int mX;
        public int mY;
    }

    

    public class node
    {
        public node()
        {
            mLeft = null;
            mRight = null;
        }

        public int mValue;

        public node mLeft;
        public node mRight;
    }
       

    class Program
    {
        public const string cInputFile = "C:\\Dev\\2014\\Round1A\\Prob2\\B-small-attempt0.in";
        public const string cOutputFile = "C:\\Dev\\2014\\Round1A\\Prob2\\out.txt";
        public const string cExampleAnswerFile = "C:\\Dev\\2014\\Round1A\\Prob2\\ea.txt";

        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter(cOutputFile))
            {
                using (StreamReader reader = new StreamReader(cInputFile))
                {
                    int numberOfTestCases = int.Parse(reader.ReadLine());

                    for (int testCaseNum = 0; testCaseNum < numberOfTestCases; testCaseNum++)
                    {
                        int numNodes = int.Parse(reader.ReadLine());

                        edge[] listOfEdges = new edge[numNodes];
                        for (int i = 0; i < numNodes - 1; i++)
                        {
                            int[] val = reader.ReadLine().Split(' ').Select(o => int.Parse(o)).ToArray();
                            listOfEdges[i] = new edge(val[0], val[1]);
                        }

                        int numDelete = GetNumberOfDeletes(listOfEdges, numNodes);
                        if (numDelete < 0)
                        {
                            numDelete = 0;
                        }


                        //Output testcase 
                        string outputLine = "Case #" + (testCaseNum + 1).ToString() + ": " + numDelete.ToString();

                        Console.WriteLine(outputLine);
                        writer.WriteLine(outputLine);
                    }
                }
            }
            ///CompareResultWithExample();
        }

        public static int GetNumberOfDeletes(edge[] pEdges, int numNodes)
        {
            int minNumDeletes = 0;

            int num0 = 0;
            int num2 = 0;

            for (int i = 1; i < numNodes + 1; i++)
            {
                int numChild = 0;

                foreach (edge a in pEdges)
                {
                    if (a.mX == i || a.mY == i)
                    {
                        numChild++;
                    }
                }

                if (numChild == 0)
                {
                    num0++;
                }

                if (numChild == 2)
                {
                    num2++;
                }
            }

            return num2-1;
        }


    }
}
