using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Problem_C
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = true;
        public const bool UseStandardIO = false;
        public const string InputFile = @"C-small-attempt1.in";
        public const string OutputFile = @"C-small.out";

        public Int32 N { get; set; }
        public Int32[] Numeros { get; set; }

        public String Resultado { get; set; }

        public override void LerDados()
        {
            N = ProximoInteiro();
            Numeros = ProximoInteiros();
        }

        public override void Resolver()
        {
            var metade = (Int32)Math.Floor((double)N / 2);
            var p1 = Numeros.Take(metade).Sum();
            var p2 = Numeros.Skip(Numeros.Length - metade).Sum();
            Resultado = p1 < p2 ? "BAD" : "GOOD";
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(Resultado);
        }
    }
}
