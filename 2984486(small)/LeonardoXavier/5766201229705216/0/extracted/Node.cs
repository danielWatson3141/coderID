using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Problem_B
{

    public class Node
    {

        public Node(Int32 pId)
        {
            Id = pId;
        }

        public Int32 PontosRoot { get; set; }

        public Boolean Excluido { get; set; }

        public Int32 Id { get; private set; }

        public HashSet<Node> Ligacoes = new HashSet<Node>();

        public void AdicionarLigacao(Node pNode)
        {
            Ligacoes.Add(pNode);
            pNode.Ligacoes.Add(this);
        }

        public override int GetHashCode()
        {
            return Id.GetHashCode();
        }

        public override bool Equals(object obj)
        {
            var objeto = obj as Node;
            if (objeto == null)
                return false;
            return Id == objeto.Id;
        }
    }
}
