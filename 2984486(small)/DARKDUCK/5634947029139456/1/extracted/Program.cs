using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam2k14
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream filestream = new FileStream(@"C:\Users\Guillaume\Documents\codeJam2k14\part2\ex1\out.txt", FileMode.Truncate);
            var streamwriter = new StreamWriter(filestream);
            streamwriter.AutoFlush = true;
            Console.SetOut(streamwriter);
            Console.SetError(streamwriter);
            System.IO.StreamReader file = new System.IO.StreamReader(@"C:\Users\Guillaume\Documents\codeJam2k14\part2\ex1\file.txt");
            int nbTestCases = Int32.Parse(file.ReadLine());
            for (int T = 1; T <= nbTestCases; T++)
            {
                String[] splited = file.ReadLine().Split(' ');
                int nbDevices = Int32.Parse(splited[0]);
                int flowLength = Int32.Parse(splited[1]);
                var sFlow = convert(file.ReadLine().Split(' '));
                var dFlow = convert(file.ReadLine().Split(' '));

                Poss root = new Poss(nbDevices, sFlow, dFlow);
                List<Poss> posses = new List<Poss>();
                posses.Add(root);
                for(int i = 0 ; i < flowLength; i++)
                {
                    List<Poss> newPosses = new List<Poss>();
                    foreach(var j in posses)
                    {
                        Poss withTrue = j.GenNextPoss(true);
                        Poss withFalse = j.GenNextPoss(false);
                        if (withFalse != null) newPosses.Add(withFalse);
                        if (withTrue != null) newPosses.Add(withTrue);
                    }
                    posses = newPosses;
                    if (posses.Count == 0) break;
                }

                Console.Write("Case #" + T + ": ");

                if (posses.Count == 0) Console.WriteLine("NOT POSSIBLE");
                else
                {
                    int min = -1;
                    foreach(var i in posses)
                    {
                        if (min == -1 || i.changed < min) min = i.changed;
                    }
                    Console.WriteLine(min);
                }
            }
        }

	    static List<List<bool>> convert(String[] input)
        {
            List<List<bool>> output = new List<List<bool>>();
		    foreach(String s in input)
            {
                List<bool> temp = new List<bool>();
                foreach(char c in s)
                {
                    if (c == '0') temp.Add(false);
                    else temp.Add(true);
                }
                output.Add(temp);
            }
            return output;
        }
	
    }

    class Poss
    {
        int done = 0;
        int length;
        public int changed = 0;
        List<int>[] poss;
        List<List<bool>> sFlow;
        List<List<bool>> dFlow;

        public Poss(int length, List<List<bool>> sFlow, List<List<bool>> dFlow)
        {
            this.length = length;
            this.sFlow = sFlow;
            this.dFlow = dFlow;
            poss = new List<int>[length];
            for(int i = 0 ; i < length ; i++)
            {
                poss[i] = new List<int>();
                for(int j = 0; j < length ; j ++)
                {
                    poss[i].Add(j);
                }
            }
        }

        public Poss(Poss p)
        {
            this.done = p.done;
            this.length = p.length;
            this.changed = p.changed;
            poss = new List<int>[length];
            for(int i = 0 ; i < length; i++)
            {
                poss[i] = new List<int>(p.poss[i]);
            }
            this.dFlow = cloneFlow(p.dFlow);
            this.sFlow = cloneFlow(p.sFlow);
        }

        static public List<List<bool>> cloneFlow(List<List<bool>> f)
        {
            List<List<bool>> newFlow = new List<List<bool>>();
            foreach(var i in f)
            {
                var t = new List<bool>();
                foreach(var j in i)
                {
                    t.Add(j);
                }
                newFlow.Add(t);
            }
            return newFlow;
        }

        void swapAtindex(int index)
        {
            for(int i = 0; i < length ; i++)
            {
                sFlow[i][index] = !sFlow[i][index];
            }
        }

        public Poss GenNextPoss(bool v)
        {
            Poss res = new Poss(this);
            res.done++;
            if (v)
            {
                res.swapAtindex(res.done - 1);
                res.changed++;
            }
            for (var i = 0; i < res.length; i++) // index du device
            {
                List<int> newPoss = new List<int>();
                for (var j = 0; j < res.poss[i].Count; j++) // pour chaque mapping possible
                {
                    int index = res.poss[i][j];
                    if (res.dFlow[i][res.done - 1] == res.sFlow[index][res.done - 1]) newPoss.Add(index);
                }
                res.poss[i] = newPoss;
            }

            if (res.isPossible()) return res;
            else return null; 

        }

        public bool isPossible()
        {

            foreach(var i in poss)
            {
                if (i.Count == 0) return false;
            }
            return true;
        }

    }
}
