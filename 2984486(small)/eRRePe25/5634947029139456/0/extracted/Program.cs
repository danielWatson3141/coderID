using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace googleCodeJam14
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> lineasEnunciado = File.ReadAllLines("C:\\a.txt").ToList();
            lineasEnunciado.RemoveAt(0);

            int nCaso = 1;
            while (lineasEnunciado.Count > 0)
            {
                string resultado;
                string [] salidasOriginales = lineasEnunciado[1].Split(' ');
                string [] dispositivos = lineasEnunciado[2].Split(' ');
                bool colocados = false;

                int minFlips = 123456789;
                colocados = colocar(salidasOriginales, dispositivos);

                if (!colocados)//Si no se pueden colocar sin modificar nada...
                {
                    for (int i = 1; i < (int)Math.Pow(2, (salidasOriginales[0].Length)); i++)//Pruebo todas las posibilidades de flips para encontrar la optima
                    {
                        /*if (i == 493)
                        {
                            int dsadsa = 22;
                        }*/

                        string binario = Convert.ToString(i, 2);
                        //Relleno de ceros por la izquierda
                        while (binario.Length != salidasOriginales[0].Length)
                        {
                            binario = "0" + binario;
                        }

                        string[] salidas = (string[]) salidasOriginales.Clone();
                        int nFlips = 0;

                        flip(salidas, binario);//Modifico las salidas
                        colocados = colocar(salidas, dispositivos);//Pruebo a colocar
                        if (colocados)//Si con esa combinacion se pueden colocar, cuento los cambios que se han hecho, y si son menores que el minimo, guardo el nuevo minimo
                        {
                            for (int j = 0; j < binario.Length; j++)
                            {
                                if (binario[j] == '1')
                                {
                                    nFlips++;
                                }
                            }
                            if (nFlips < minFlips)
                            {
                                minFlips = nFlips;
                            }
                        }
                        Console.WriteLine(binario);
                    }
                }
                else
                {
                    minFlips = 0;
                }

                if (minFlips == 123456789)
                {
                    resultado = "NOT POSSIBLE";
                }
                else
                {
                    resultado = minFlips.ToString();
                }

                File.AppendAllText("C:\\salida.txt", "Case #" + nCaso + ": "  + resultado + Environment.NewLine);


                //borro los datos del caso procesado
                for (int i = 0; i < 3; i++)
                {
                    lineasEnunciado.RemoveAt(0);
                }

                nCaso++;
            }

        }
        public static bool colocar(string[] salidas, string[] dispositivos)
        {
            bool[] enUso = new bool[salidas.Length];
            bool dispositivoSinColocar = false;

            for (int i = 0; i < dispositivos.Length && !dispositivoSinColocar; i++)
            {
                dispositivoSinColocar = true;
                for (int j = 0; j < salidas.Length && dispositivoSinColocar; j++)
                {
                    if (dispositivos[i] == salidas[j])
                    {
                        dispositivoSinColocar = false;
                    }
                }
            }

            return !dispositivoSinColocar;
        }

        public static void flip(string[] salidas, string binario)
        {
            for (int i = 0; i < binario.Length; i++)
            {
                if (binario[i] == '1')
                {
                    for (int j = 0; j < salidas.Length; j++)
                    {
                        StringBuilder sb = new StringBuilder(salidas[j]);
                        if (sb[i] == '1')
                        {
                            sb[i] = '0';
                        }
                        else
                        {
                            sb[i] = '1';
                        }
                        salidas[j] = sb.ToString();
                    }
                }
            }
        }
    }
}
