using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB.FullBinaryTree
{
    class Program
    {
        class Node
        {
            public Node()
            {
                Connections = new LinkedList<Node>();
            }

            public int Index { get; set; }
            public LinkedList<Node> Connections { get; set; }
            public Node Parent { get; set; }
        }

        class Case
        {
            public int CaseNumber { get; set; }
            public int N { get; set; }
            public IEnumerable<Node> Nodes { get; set; }
        }

        static void Main(string[] args)
        {
            const string fileName = "B-small-attempt3";

            var input = File.ReadAllLines("../../" + fileName + ".in");
            var cases = new List<Case>();

            // read input
            int testCasesCount = int.Parse(input[0]);

            int lineIndex = 0;
            for (int i = 0; i < testCasesCount; ++i)
            {
                var c = new Case();
                c.CaseNumber = i + 1;

                c.N = int.Parse(input[++lineIndex]);

                var nodes = new LinkedList<Node>();
                for (int j = 0; j < c.N; ++j)
                {
                    var n = new Node();
                    n.Index = j + 1;
                    nodes.AddLast(n);
                }
                c.Nodes = nodes.Where(x => x.Index >0);

                for (int j = 0; j < c.N-1; ++j)
                {
                    int[] edge = input[++lineIndex].Split().Select(x => int.Parse(x)).ToArray();
                    var first = c.Nodes.First(x => x.Index == edge[0]);
                    var second = c.Nodes.First(x => x.Index == edge[1]);
                    first.Connections.AddLast(second);
                    second.Connections.AddLast(first);
                }

                cases.Add(c);
            }

            // process cases

            var output = new List<string>();

            foreach (var c in cases)
            {
                //possible root has 2 children (connections)
                var roots = c.Nodes.Where(x => x.Connections.Count == 2);

                int maxNodes = 1;
                foreach (var r in roots)
                {
                    var nodes = c.Nodes.ToList();
                    foreach (var n in nodes)
                    {
                        n.Parent = null;
                    }

                    int nodesCount = 1;

                    var root = nodes.First(x => x.Index == r.Index);

                    VisitChildren(root, ref nodesCount);

                    maxNodes = nodesCount > maxNodes ? nodesCount : maxNodes;
                    if (maxNodes == c.N)
                    {
                        break;
                    }
                }

                output.Add("Case #" + c.CaseNumber + ": " + (c.N - maxNodes));
            }

            File.WriteAllLines("../../" + fileName + ".out", output);
        }

        private static void VisitChildren(Node root, ref int nodesCount)
        {
            foreach (var child in root.Connections)
            {
                if(child != root.Parent)
                {
                    ++nodesCount;
                    child.Parent = root;
                    if (child.Connections.Count == 3)
                    {
                        VisitChildren(child, ref nodesCount);
                    }
                    else if (child.Connections.Count > 3)
                    {
                        child.Connections = new LinkedList<Node>(child.Connections.OrderByDescending(x => x.Connections.Count).Take(2).ToList());
                        VisitChildren(child, ref nodesCount);
                    }
                }
            }
        }
    }

}