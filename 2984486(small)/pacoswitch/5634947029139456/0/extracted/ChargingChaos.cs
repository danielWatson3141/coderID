using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class ChargingChaos
    {
        private cIO console;
        public ChargingChaos(cIO c) 
        {
            console = c;
        }
        public bool compara(int[] a, int[] b, int N)
        {
            for (int i = 0; i < N; i++)
            {
                if (a[i] != b[i])
                {
                    return false;
                }
            }
            return true;
        }
        public void solve()
        {
            int veces;
            veces = console.ReadInt();
            for (int i = 0; i < veces; i++)
            {
                int N, L;
                N = console.ReadInt();
                L = console.ReadInt();
                int limite = (int)Math.Pow(2, L);
                string [] dispositivos = new string[N];
                string [] conectores = new string[N];
                int [] idisp = new int[N];
                int [] icone = new int[N];
                for (int j = 0; j < N; j++)
                {
                    dispositivos[j] = console.ReadString();
                    idisp[j] = Convert.ToInt32(dispositivos[j], 2);
                }
                for (int j = 0; j < N; j++)
                {
                    conectores[j] = console.ReadString();
                    icone[j] = Convert.ToInt32(conectores[j], 2);
                }
                Array.Sort(idisp);
                Array.Sort(icone);
                if (compara(idisp, icone, N))
                    console.WriteLineCodeJamFormat(i + 1, "0");
                else
                {
                    int max = 2048;
                    for (int k = 1; k < limite; k++)
                    {
                        //k es el numero de switches que se van a mover
                        int[] temporal = new int[N];
                        Array.Copy(icone, temporal, N);
                        int contador = 0;
                        for (int y = 0; y < L; y++)
                        {
                            int Z = (int)Math.Pow(2, y);
                            if ((k & Z) > 0)
                            {
                                contador++;
                                for (int x = 0; x < N; x++)
                                {
                                    temporal[x] = ((temporal[x] & Z) > 0) ? temporal[x] - Z : temporal[x] + Z;
                                }
                            }
                        }
                        Array.Sort(temporal);
                        if (compara(idisp, temporal, N))
                        {
                            if (max > contador) max = contador;
                        }
                    }
                    if (max == 2048)
                        console.WriteLineCodeJamFormat(i + 1, "NOT POSSIBLE");
                    else
                        console.WriteLineCodeJamFormat(i + 1, max.ToString());
                }
                
            }
        }
    }
}
