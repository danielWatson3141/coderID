using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_jam
{
    class Program
    {
        static List<byte[]> solutions = new List<byte[]>();

        static void Main(string[] args)
        {
            int cases = int.Parse(Console.ReadLine());
            for (int cas = 1; cas <= cases; cas++)
            {
                solutions.Clear();
                string text = Console.ReadLine();
                string[] bits = text.Split(' ');
                List<int> t = bits.ToArray<string>().Select(Int32.Parse).ToList();
                int n = t[0];
                int l = t[1];
                text = Console.ReadLine();
                bits = text.Split(' ');
                List<byte[]> flow = new List<byte[]>();
                foreach (string item in bits)
                {
                    flow.Add(System.Text.Encoding.UTF8.GetBytes(item));
                }
                foreach (byte[] item in flow)
                {
                    for (int i = 0; i < item.Length;i++ )
                    {
                        item[i] -= 48;
                    }
                }
                text = Console.ReadLine();
                bits = text.Split(' ');
                List<byte[]> devices = new List<byte[]>();
                foreach (string item in bits)
                {
                    devices.Add(System.Text.Encoding.UTF8.GetBytes(item));
                }
                foreach (byte[] item in devices)
                {
                    for (int i = 0; i < item.Length; i++)
                    {
                        item[i] -= 48;
                    }
                }
                byte[] conf = new byte[l];
                recur(flow, devices, conf);
                if (solutions.Count == 0)
                {
                    Console.Write("Case #"); Console.Write(cas); Console.WriteLine(": NOT POSSIBLE");
                }
                else
                {
                    List<int> num = new List<int>();
                    foreach (byte[] item in solutions)
                    {
                        int j = 0;
                        foreach (byte iitem in item)
                        {
                            if (iitem == 1) j++;
                        }
                        num.Add(j);
                    }
                    Console.Write("Case #"); Console.Write(cas); Console.Write(": "); Console.WriteLine(num.Min());
                }
            }
        }

        private static bool recur(List<byte[]> list, List<byte[]> devices, byte[] conf)
        {
            List<byte[]> orig = new List<byte[]>(list.Count);
            list.ForEach((item) =>
            {
                byte[] nen = new byte[item.Length];
                for (int ii = 0; ii < item.Length; ii++)
                {
                    nen[ii] = item[ii];
                }
                    orig.Add(nen);

            });
            int i = 0;
            foreach (byte[] item in list)
            {
                for (i = 0; i < conf.Length; i++)
                {
                    if (conf[i] == 1) { 
                        if (item[i] == 1) 
                            item[i] = 0;
                        else
                            item [i] = 1;
                    }
                }
            }

            bool end = true;
            byte[] orifConf = new byte[conf.Length];
            for (i = 0; i < conf.Length; i++)
            {
                orifConf[i] = conf[i];
            }
                for (int ii = 0; ii < conf.Length; ii++) { if (conf[ii] == 0) end = false; }
            if (end == true) return false;

            byte tmp = 1; i = 0;
            while (tmp == 1)
            {
                if (conf[i] == 1)
                {
                    tmp = 1;
                    conf[i] = 0;
                }
                else
                {
                    tmp = 0;
                    conf[i] = 1;
                }
                i++;
            }

            foreach (byte[] item in devices)
            {
                try
                {
                    int index = list.FindIndex(comp(item));
                    list.RemoveAt(index);
                }
                catch (Exception e)
                {
                    return recur(orig, devices, conf);
                }
            }
            solutions.Add(orifConf);
            return true;
        }

        static Predicate<byte[]> comp(byte[] ne)
        {
            return delegate(byte[] ar)
            {
                for (int i = 0; i < ar.Length; i++)
                {
                    if (ar[i] != ne[i]) return false;
                }
                return true;
            };
        }
    }
}
