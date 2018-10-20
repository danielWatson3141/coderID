using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;


namespace Problem_B
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"B-small-attempt1.in";
        public const string OutputFile = @"B-small.out";


        public Int32 N { get; set; }

        public Dictionary<Int32, Node> Nodes = new Dictionary<int, Node>();

        public Int32 Resposta { get; set; }

        public override void LerDados()
        {
            N = ProximoInteiro();
            for (int x = 1; x <= N; x++)
            {
                Nodes.Add(x, new Node(x)); ;
            }

            for (int x = 1; x < N; x++)
            {
                var pares = ProximoInteiros();
                Nodes[pares[0]].AdicionarLigacao(Nodes[pares[1]]);
            }
        }

        public override void Resolver()
        {
            foreach (var node in Nodes.Values)
            {
                node.PontosRoot = Calcular(node, 0);
            }
            var root = Nodes.Values.OrderByDescending(pX => pX.PontosRoot).First();
            Resposta = N - root.PontosRoot;
            //CalcularPerda(root, 0);
            //Resposta = Nodes.Count(pX => pX.Value.Excluido);
        }

        public Int32 CalcularPerda(Node pNode, Int32 pAnterior)
        {
            var somas = new Dictionary<Node,int>();
            foreach (var node in pNode.Ligacoes)
            {
                if (node.Id == pAnterior)
                    continue;
                somas.Add(node, CalcularPerda(node, pNode.Id));
            }
            if (somas.Count >= 2)
            {
                foreach (var node in somas.OrderByDescending(pX => pX.Value).Skip(2).Select(pX => pX.Key).ToArray())
                {
                    node.Excluido = true;
                }
                return somas.OrderByDescending(pX => pX.Value).Take(2).Sum(pX => pX.Value);
            }
            if (somas.Count == 0)
            {
                return 1;
            }
            foreach (var node in somas.Keys)
            {
                node.Excluido = true;
            }
            return 1;
        }

        public Int32 Calcular(Node pNode, Int32 pAnterior)
        {

            if (pNode.Ligacoes.Count >= (pAnterior == 0 ? 2 : 3))
            {
                var somas = new List<int>();
                foreach (var node in pNode.Ligacoes)
                {
                    if (node.Id == pAnterior)
                        continue;
                    somas.Add(Calcular(node, pNode.Id));
                }
                return somas.OrderByDescending(pX => pX).Take(2).Sum() + 1;
            }
            return 1;
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(Resposta);
        }
    }
}
