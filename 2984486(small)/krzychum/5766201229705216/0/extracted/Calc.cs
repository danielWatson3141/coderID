using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FullBinaryTree
{
    class Calc
    {
        public class Node
        {
            public List<int> Neighbours = new List<int>();
            public int ThisValue = int.MaxValue;
            public int NAllDescendants = int.MaxValue;
        }

        Node[] nodes;

        private int nNodes;

        public Calc(int nNodes)
        {
            // TODO: Complete member initialization
            this.nNodes = nNodes;
            nodes = new Node[nNodes];
            for (int cNode = 0; cNode < nNodes; ++cNode)
                nodes[cNode] = new Node();
        }
        internal void Connect(int p1, int p2)
        {
            nodes[p1].Neighbours.Add(p2);
            nodes[p2].Neighbours.Add(p1);
        }

        internal int GetResu(int rootIdx)
        {
            // make a direct tree
            int cDesc = MakeDirectTree(rootIdx);
            if (cDesc != nNodes)
                throw new Exception("Error in MakeDirectTree");
            return ConsiderNode(rootIdx);
        }

        private int ConsiderNode(int nodeIdx)
        {
            var myNode = nodes[nodeIdx];
            if (myNode.ThisValue!=int.MaxValue)
                return myNode.ThisValue;
            if (myNode.Neighbours.Count() == 0)
            {
                myNode.ThisValue = 0;
            }
            else if (myNode.Neighbours.Count() == 1)
            {
                myNode.ThisValue = myNode.NAllDescendants;
            }
            else if (myNode.Neighbours.Count() == 2)
            {
                int res = ConsiderNode(myNode.Neighbours[0]);
                res += ConsiderNode(myNode.Neighbours[1]);
                myNode.ThisValue = res;
            }
            else
            {
                int best = int.MaxValue;
                // find all possible solutions...
                for (int notRemove1=0;notRemove1<myNode.Neighbours.Count();++notRemove1)
                {
                    for (int notRemove2=notRemove1+1;notRemove2<myNode.Neighbours.Count();++notRemove2)
                    {
                        // count all the rest
                        int res = 0;
                        for (int cNeigh=0;cNeigh<myNode.Neighbours.Count();++cNeigh)
                        {
                            if (cNeigh==notRemove1 || cNeigh==notRemove2)
                            {
                                res += ConsiderNode(myNode.Neighbours[cNeigh]);
                            }
                            else
                            {
                                res += nodes[myNode.Neighbours[cNeigh]].NAllDescendants+1;
                            }
                        }
                        best = Math.Min(best, res);
                    }
                }
                myNode.ThisValue = best;
            }
            return myNode.ThisValue;
        }

        private int MakeDirectTree(int nodeIdx)
        {
            var myNode = nodes[nodeIdx];
            int cDesc = 0;
            for (int cNeigh=0;cNeigh<myNode.Neighbours.Count();++cNeigh)
            {
                var aNeigh = nodes[myNode.Neighbours[cNeigh]];
                aNeigh.Neighbours.Remove(nodeIdx);
                cDesc += MakeDirectTree(myNode.Neighbours[cNeigh]);
            }
            myNode.NAllDescendants = cDesc;
            cDesc += 1;
            return cDesc;
        }
    }
}
