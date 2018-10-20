using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;
using System.Numerics;

namespace B
{
    class Node
    {
        public override string ToString()
        {
            if (!children.Any())
                return id.ToString();

            bool first = true;
            StringBuilder sb = new StringBuilder();
            foreach (var child in children)
            {
                if (first)
                    sb.Append('(');
                else
                    sb.Append(',');
                first = false;
                sb.Append(child.ToString());
            }
            sb.Append(')');

            return string.Format("id: {0} ch: {1}", id, sb.ToString());
        }

        static int numBits(int x)
        {
            int count = 0;
            while (x != 0)
            {
                x = x & (x - 1);
                count++;
            }
            return count;
        }

        public int id;
        public List<Node> children = new List<Node>();

        public void Grow(List<int>[] graph, int except)
        {
            foreach (var i in graph[id].Where(x => x != except))
            {
                Node child = new Node { id = i };
                children.Add(child);
                child.Grow(graph, id);
            }
        }

        public int ncs = int.MaxValue;
        public void CalcNumChildrenAndSelf()
        {
            if (ncs != int.MaxValue)
                return;

            int count = 1;
            foreach (var child in children)
            {
                child.CalcNumChildrenAndSelf();
                count += child.ncs;
            }
            ncs = count;
        }

        public int cg = int.MaxValue;
        public void MakeGood()
        {
            if (cg != int.MaxValue)
                return;

            int C = 1 << children.Count;
            int best = int.MaxValue;

            for (int i = 0; i < C; i++)
            {
                int nb = numBits(i);
                if (nb != 0 && nb != 2)
                    continue;

                int count = 0;
                for (int j = 0; j < children.Count; j++)
                {
                    if (((1 << j) & i) == 0)
                        count += children[j].ncs;
                    else
                    {
                        children[j].MakeGood();
                        count += children[j].cg;
                    }
                }

                best = Math.Min(best, count);
            }
            cg = best;
        }
    }

    class Program
    {
        static int Solve(List<int>[] graph)
        {
            int N = graph.Length;
            int best = int.MaxValue;
            for (int i = 0; i < N; i++)
            {
                Node root = new Node { id = i };
                root.Grow(graph, -1);
                root.CalcNumChildrenAndSelf();
                root.MakeGood();

                best = Math.Min(best, root.cg);
            }

            return best;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int N = int.Parse(Console.ReadLine());
                List<int>[] graph = new List<int>[N];
                for (int i = 0; i < N; i++)
                    graph[i] = new List<int>();

                for (int i = 0; i < N - 1; i++)
                {
                    string[] line = Console.ReadLine().Split();
                    int a = int.Parse(line[0]) - 1;
                    int b = int.Parse(line[1]) - 1;

                    graph[a].Add(b);
                    graph[b].Add(a);
                }

                Console.WriteLine("Case #{0}: {1}", t, Solve(graph));
            }
        }
    }
}
