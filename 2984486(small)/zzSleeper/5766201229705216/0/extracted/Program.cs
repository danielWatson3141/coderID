using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam2014
{
    class Program
    {
        public const string ProjectName = @"Full Binary Tree";
        public const string PathFormat = @"D:\Projects\CodeJam\2014\CodeJam2014\{0}\{1}";
        public const string InputFile = @"B-small-attempt0.in";

        static void Main(string[] args)
        {
            var reader = new StreamReader(String.Format(PathFormat, ProjectName, InputFile));
            var writer = new StreamWriter(String.Format(PathFormat, ProjectName, InputFile + ".out.txt"));

            var numCases = Int32.Parse(reader.ReadLine());

            for (int caseNo = 0; caseNo < numCases; caseNo++)
            {
                //TODO: Do Stuff
                var n = int.Parse(reader.ReadLine());
                var nodeList = new Node[n];
                for (int i = 0; i < n; i++) nodeList[i] = new Node();

                for (var i = 0; i < n-1; i++)
                {
                    var pair = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                    var a = nodeList[pair[0]-1];
                    var b = nodeList[pair[1]-1];
                    a.AddLink(b);
                    b.AddLink(a);
                }

                var result = GetSolution(nodeList);

                var outputLine = "Case #" + (caseNo + 1) + ": " + result;
                //Console.WriteLine(outputLine);
                writer.WriteLine(outputLine);
            }

            reader.Close();
            writer.Close();
            Console.WriteLine("Press enter to exit...");
            Console.ReadLine();
        }

        static int GetSolution(Node[] nodeList)
        {
            var maxSize = 0;
            foreach(var node in nodeList)
            {
                var h = node.CalcBalancedTreeSize(node);
                if (h > maxSize) maxSize = h;
            }
            return nodeList.Length - maxSize;
        }
    }

    class Node
    {
        private List<Node> links = new List<Node>();

        public Node()
        {

        }

        public void AddLink(Node linkedNode)
        {
            links.Add(linkedNode);
        }

        public int CalcBalancedTreeSize(Node parent)
        {
            var children = links.Count(x => x != parent);

            if (children < 2) return 1;

            var maxChildSize = 0;
            var nextMaxChildSize = 0;
            foreach (var child in links.Where(x => x != parent))
            {
                var s = child.CalcBalancedTreeSize(this);

                if (s > nextMaxChildSize)
                {
                    nextMaxChildSize = s;
                }
                if (nextMaxChildSize > maxChildSize)
                {
                    var tmp = maxChildSize;
                    maxChildSize = nextMaxChildSize;
                    nextMaxChildSize = tmp;
                }
            }
            return 1 + maxChildSize + nextMaxChildSize;
        }
    }
}
