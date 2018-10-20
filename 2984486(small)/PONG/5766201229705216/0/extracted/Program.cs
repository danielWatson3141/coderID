using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B
{
    class Program
    {
        private static string INPUT_SMAPLE = @"Inputs\sample.in.txt";
        private static string INPUT_SAMLL = @"Inputs\B-small-attempt1.in";
        private static string INPUT_LARGE = @"Inputs\B-large-practice.in";

        private static Dictionary<int, Node> nodes = new Dictionary<int, Node>();

        static void Main(string[] args)
        {
            StreamReader sReader = new StreamReader(INPUT_SAMLL);
            StreamWriter sWriter = new StreamWriter(@"output.txt");

            int T = 0;

            try
            {
                string line = sReader.ReadLine();
                T = int.Parse(line);
            }
            catch (Exception e)
            {
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
            }

            // solve the problem!!!
            int N, X, Y;            

            int biggestSize;

            Console.WriteLine("Problem B:");
            for (int t = 1; t <= T; t++)
            {
                nodes.Clear();

                string line = sReader.ReadLine();
                N = int.Parse(line);

                for (int n = 1; n < N; n++)
                {
                    line = sReader.ReadLine();
                    string[] splits = line.Split(' ');
                    X = int.Parse(splits[0]);
                    Y = int.Parse(splits[1]);

                    if (nodes.ContainsKey(X))
                    {
                        nodes[X].children.Add(Y);
                    }
                    else
                    {
                        nodes.Add(X, new Node(X, Y));
                    }
                    if (nodes.ContainsKey(Y))
                    {
                        nodes[Y].children.Add(X);
                    }
                    else
                    {
                        nodes.Add(Y, new Node(Y, X));
                    }
                }

                // walk each tree and find the biggest tree
                biggestSize = 0;
                int tempSize;
                int biggestSubTreeSize, secondBiggestSubTreeSize;
                for (int n = 1; n <= N; n++)
                {
                    tempSize = 0;
                    biggestSubTreeSize = 0;
                    secondBiggestSubTreeSize = 0;
                    if (nodes[n].children.Count >= 2)
                    {
                        for (int c = 0; c < nodes[n].children.Count; c++)
                        {
                            int childSize = FindFullBinaryTreeNodes(nodes[nodes[n].children[c]], nodes[n].value);
                            if (childSize > biggestSubTreeSize)
                            {
                                secondBiggestSubTreeSize = biggestSubTreeSize;
                                biggestSubTreeSize = childSize;
                            }
                            else if (childSize > secondBiggestSubTreeSize)
                            {
                                secondBiggestSubTreeSize = childSize;
                            }
                        }

                        //currentSize += FindFullBinaryTreeNodes(nodes[nodes[n].children[0]], nodes[n].value);
                        //currentSize += FindFullBinaryTreeNodes(nodes[nodes[n].children[1]], nodes[n].value);

                        // include root node itself
                        tempSize = biggestSubTreeSize + secondBiggestSubTreeSize + 1;
                    }
                    //Console.WriteLine("cs: " + n + " " + tempSize);

                    if (tempSize > biggestSize)
                    {
                        biggestSize = tempSize;
                    }
                }

                Console.WriteLine(string.Format("Case #{0}: {1}", t, (N - biggestSize)));
                sWriter.WriteLine(string.Format("Case #{0}: {1}", t, (N - biggestSize)));
            }

            sReader.Close();
            sWriter.Close();

            Console.WriteLine("----------------------------------");
            Console.WriteLine("done");
            Console.ReadKey();
        }

        private static int FindFullBinaryTreeNodes(Node node, int parent)
        {
            if (node.children.Count <= 2)
            {
                // all other nodes are not part of full binary tree
                return 1;
            }
            else if (node.children.Count > 3)
            {
                return 0;
            }
            
            // current node itself;
            int count = 1;
            foreach (int nodeValue in node.children)
            {
                if (nodeValue != parent)
                {
                    // this is a valid subtree
                    count += FindFullBinaryTreeNodes(nodes[nodeValue], node.value);
                }
            }

            return count;
        }

        private class Node
        {
            public List<int> children;
            public int value;

            public Node(int value, int child)
            {
                this.value = value;
                children = new List<int>();
                children.Add(child);
            }
        }
    }
}
