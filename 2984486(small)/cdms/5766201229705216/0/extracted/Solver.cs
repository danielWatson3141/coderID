using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CodeJam
{

    class Solver
    {
        Dictionary<int, List<int>> tree;


        int getMinDeletes()
        {
            int minDeletes = tree.Keys.Count - 1;
            foreach (int key in tree.Keys)
            {
                int keyMinDeletes = 0;
                List<int[]> nodes2verify = new List<int[]>();
                nodes2verify.Add(new int[] { key, 0, 1 });
                do
                {
                    var node2verify = nodes2verify.Last();
                    nodes2verify.RemoveAt(nodes2verify.Count - 1);
                    int node = node2verify[0];
                    int nodeParent = node2verify[1];
                    int isValidNode = node2verify[2];
                    if (isValidNode == 0)
                        keyMinDeletes++;
                    int[] nodeEdges = tree[node].ToArray();
                    nodeEdges = nodeEdges.Where(e => e != nodeParent).ToArray();
                    isValidNode = (isValidNode == 1 && (nodeEdges.Count() == 0 || nodeEdges.Count() == 2)) ? 1 : 0;
                    for (int i = 0; i < nodeEdges.Count(); i++)
                    {
                        nodes2verify.Add(new int[] { nodeEdges[i], node, isValidNode, isValidNode });
                    }
                } while (nodes2verify.Count > 0);
                if (keyMinDeletes == 0)
                    return 0;
                if (keyMinDeletes < minDeletes)
                    minDeletes = keyMinDeletes;
            }
            return minDeletes;
        }

        string solveCase(int[][] input)
        {
            int N = input[0][0];
            tree = new Dictionary<int, List<int>>();
            for (int i = 1; i <= N; i++)
            {
                tree.Add(i, new List<int>());
            }
            for (int i = 1; i < input.Length; i++)
            {
                int[] edge = input[i];
                tree[edge[0]].Add(edge[1]);
                tree[edge[1]].Add(edge[0]);
            }
            return getMinDeletes() + "";
        }


        public string Solve(string input)
        {
            string[] lines = input.Trim().Split('\n').Select(l => l.TrimEnd('\r')).ToArray();

            StringBuilder sb = new StringBuilder();
            int nbCases = Convert.ToInt32(lines[0]);
            int iLine = 1;
            for (int i = 0; i < nbCases; i++)
            {
                //Console.WriteLine("Case: " + i);

                string[] lineParts = lines[iLine].Split(' ');
                int[] linePartsint = lineParts.Select(p => Convert.ToInt32(p)).ToArray();

                int caseLines = linePartsint[0] - 1;
                int[][] caseInput = new int[caseLines + 1][];
                caseInput[0] = linePartsint;

                for (var caseLine = 0; caseLine < caseLines; caseLine++)
                {
                    iLine++;
                    lineParts = lines[iLine].Split(' ');
                    linePartsint = lineParts.Select(p => Convert.ToInt32(p)).ToArray();
                    caseInput[caseLine + 1] = linePartsint;
                }
                string result = solveCase(caseInput);
                sb.AppendLine("Case #" + (i + 1) + ": " + result);
                iLine++;
            }
            return sb.ToString();
        }
    }

}

