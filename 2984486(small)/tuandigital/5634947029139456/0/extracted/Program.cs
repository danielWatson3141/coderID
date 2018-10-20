using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChargingChaos
{
    class Program
    {
        static void Main(string[] args)
        {

            int test = int.Parse(Console.ReadLine());
            for (int t = 1; t <= test; t++)
            {
                string[] line = Console.ReadLine().Split();
                int n = int.Parse(line[0]);
                int l = int.Parse(line[1]);
                line = Console.ReadLine().Split();
                ulong[] outlets = new ulong[n];
                for (int i = 0; i < n; i++)
                {
                    outlets[i] = StrToLong(line[i]);
                }
                line = Console.ReadLine().Split();
                ulong[] devices = new ulong[n];
                for (int i = 0; i < n; i++)
                {
                    devices[i] = StrToLong(line[i]);
                }
                int best = 100;
                for (int i = 0; i < n; i++)
                {
                    ulong curDevice = devices[i];
                    for (int j = 0; j < n; j++)
                    {
                        ulong curOutlet = outlets[j];
                        int numberOfChanges = 0;
                        ulong[] outletsClone = new ulong[n];
                        Array.Copy(outlets, outletsClone, n);
                        for (int k = 0; k < l; k++)
                        {
                            if ((((curOutlet ^ curDevice) >> k) & 1) != 0)
                            {
                                numberOfChanges++;
                                for (int u = 0; u < n; u++)
                                {
                                    outletsClone[u] ^= ((ulong)1 << k);
                                }
                            }
                        }
                        bool ok = true;
                        for (int k = 0; k < n; k++)
                        {
                            bool found = false;
                            for (int u = 0; u < n; u++)
                            {
                                if (outletsClone[u] == devices[k])
                                {
                                    found = true;
                                    break;
                                }
                            }
                            if (!found)
                            {
                                ok = false;
                                break;
                            }
                        }
                        if (ok)
                        {
                            best = Math.Min(best, numberOfChanges);
                        }
                    }
                }
                if (best == 100)
                {
                    Console.WriteLine("Case #{0}: NOT POSSIBLE", t);
                }
                else
                {
                    Console.WriteLine("Case #{0}: {1}", t, best);
                }
            }
        }

        static ulong StrToLong(string str)
        {
            ulong ret = 0;
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == '1')
                    ret |= (((ulong)1) << i);
            }
            return ret;
        }
    }
}
