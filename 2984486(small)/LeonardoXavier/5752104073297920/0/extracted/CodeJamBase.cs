using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Problem_C
{
    public abstract class CodeJamBase
    {

        public abstract void LerDados();
        public abstract void Resolver();
        public abstract void EscreverResposta();

        public static void Run()
        {
            if (Solucao.UseStandardIO)
            {
                _inputStream = Console.In;
                _outputStream = Console.Out;
            }
            else
            {
                _inputStream = File.OpenText(Path.Combine(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile), "Downloads"), Solucao.InputFile));
                _outputStream = File.CreateText(Solucao.OutputFile);
            }

            int qtdTestes = int.Parse(_inputStream.ReadLine());
            var solucoes = new Solucao[qtdTestes];
            for (int i = 0; i < qtdTestes; ++i)
            {
                solucoes[i] = new Solucao();
                solucoes[i].LerDados();
            }

            int completos = 0;
            if (Solucao.UseMultiThreading)
            {
                solucoes.AsParallel().WithDegreeOfParallelism(Math.Max(Environment.ProcessorCount, 2)).ForAll(
                    pX => { pX.Resolver(); Console.Title = (++completos).ToString() + " de " + qtdTestes; });
            }
            else
            {
                for (int i = 0; i < qtdTestes; ++i)
                {
                    solucoes[i].Resolver();
                    Console.Title = (++completos).ToString() + " de " + qtdTestes;
                }
            }
            for (int i = 0; i < qtdTestes; ++i)
            {
                Out.Write(string.Format("Case #{0}: ", i + 1));
                solucoes[i].EscreverResposta();
            }
            Out.Flush();
            if (Solucao.UseStandardIO)
            {
                Console.ReadLine();
            }
            else
            {
                Out.Close();
            }
        }

        public static TextWriter Out { get { return _outputStream; } }

        private static TextReader _inputStream;
        private static TextWriter _outputStream;


        public string ProximaLinha()
        {
            return _inputStream.ReadLine();
        }

        public Int32[] ProximoInteiros()
        {
            return _inputStream.ReadLine().Split().Select(Int32.Parse).ToArray();
        }

        public Int32 ProximoInteiro()
        {
            return int.Parse(_inputStream.ReadLine());
        }

        public Int64[] ProximoLongs()
        {
            return _inputStream.ReadLine().Split().Select(Int64.Parse).ToArray();
        }

        public Int64 ProximoLong()
        {
            return Int64.Parse(_inputStream.ReadLine());
        }

        public Double[] ProximoDoubles()
        {
            return _inputStream.ReadLine().Split().Select(Double.Parse).ToArray();
        }

        public Double ProximoDouble()
        {
            return Double.Parse(_inputStream.ReadLine());
        }

        public BigInteger[] ProximoBigIntegers()
        {
            return _inputStream.ReadLine().Split().Select(BigInteger.Parse).ToArray();
        }

        public BigInteger ProximoBigInteger()
        {
            return BigInteger.Parse(_inputStream.ReadLine());
        }

        static void Main()
        {
            new Thread(Run, 64 * 1024 * 1024).Start();
        }

    }
}
