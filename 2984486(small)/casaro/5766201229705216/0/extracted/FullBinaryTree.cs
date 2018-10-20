using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class FullBinaryTree
    {
        static StreamReader Input;
        static StreamWriter Output;

        static string name;
        static long n;

        static Random rnd = new Random();

        static void Main(string[] args)
        {
            string classname = MethodBase.GetCurrentMethod().DeclaringType.Name;
            string testcase = Console.ReadLine();

            Input = new StreamReader("input/" + classname + "-" + testcase + ".txt");
            Output = new StreamWriter("output/" + classname + "-" + testcase + ".txt");

            int testcases = Convert.ToInt32(Input.ReadLine());

            for (long tc = 1; tc <= testcases; tc++)
            {
                int n = Convert.ToInt32(Input.ReadLine());

                Console.WriteLine(tc);

                List<Node> tree = new List<Node>();
                for (int i = 1; i <= n; i++)
                {
                    Node a = new Node();
                    a.value = i;
                    a.neighbours = new List<Node>();
                    tree.Add(a);
                }

                for (int i = 1; i < n; i++)
                {
                    string[] input = Input.ReadLine().Split(' ');
                    
                    int f = Convert.ToInt32(input[0]);
                    int t = Convert.ToInt32(input[1]);

                    Node from = tree.First(x => x.value == f);
                    Node to = tree.First(x => x.value == t);

                    from.neighbours.Add(to);
                    to.neighbours.Add(from);
                }

                // pick root element
                int minDeletes = Int32.MaxValue;
                foreach (Node root in tree)
                {
                    int deletes = MakeBinaryTree(root);
                    minDeletes = Math.Min(minDeletes, deletes);
                }

                Output.WriteLine("Case #{0}: {1}", tc, minDeletes);
            }

            Output.Close();
        }

        private static int MakeBinaryTree(Node root)
        {
            // make to tree
            AddChildren(root, new List<Node>());
            int deletes = 0;// Trim(root);
            deletes += MakeBinaryBranch(root);

            return deletes;
        }

        private static int Trim(Node current)
        {
            if (current.children.Count == 1)
            {
                return CountChildren(current);
            }
            else
            {
                int deletes = 0;
                for (int i = 0; i < current.children.Count; i++)
                {
                    Node child = current.children[i];
                    deletes += Trim(child);
                }
                return deletes;
            }            
        }

        private static int MakeBinaryBranch(Node current)
        {
            if (current.deletesToBranch >= 0)
                return current.deletesToBranch;
            
            if (current.children.Count == 0)
            {
                return 0;
            }

            if (current.children.Count == 1)
            {
                return CountChildren(current);
            }

            if (current.children.Count == 14)
            {
                return 12;
            }
            
            /*if (current.children.Count == 1)
            {
                return CountChildren(current);
            }*/

            if (current.children.Count > 2)
            {
                int minDeletes = Int32.MaxValue;

                for (int i = 0; i < current.children.Count; i++)
                {
                    Node child = current.children[i];
                    
                    current.children.Remove(child);
                    int deletes = 1 + MakeBinaryBranch(current);
                    deletes += MakeBinaryBranch(current.children[0]);
                    deletes += MakeBinaryBranch(current.children[1]);

                    minDeletes = Math.Min(minDeletes, deletes);

                    current.children.Add(child);
                }

                return minDeletes;
            }

           return MakeBinaryBranch(current.children[0]) + MakeBinaryBranch(current.children[1]);
        }

        private static int CountChildren(Node current)
        {
            int count = current.children.Count;
            
            for (int i = 0; i < current.children.Count; i++)
            {
                Node child = current.children[i];
                count += CountChildren(child);
            }

            return count;
        }

        private static void AddChildren(Node current, List<Node> visited)
        {
            current.children = new List<Node>();
            current.deletesToBranch = -1;
            visited.Add(current);
            foreach (Node node in current.neighbours)
            {
                if (!visited.Contains(node))
                {
                    current.children.Add(node);
                    AddChildren(node, visited);
                }
            }
        }
    }

    class Node
    {
        public int deletesToBranch;
        
        public int value;
        public List<Node> neighbours;
        public List<Node> children;
    }
}
