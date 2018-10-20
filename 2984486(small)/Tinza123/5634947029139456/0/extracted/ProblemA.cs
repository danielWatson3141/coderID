using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam2014Round1A
{
    class ProblemA
    {
        public void Solver(StreamReader inFile, StreamWriter outFile)
        {
            var caseCount = Int32.Parse(inFile.ReadLine());
            int caseNum = 1;
            while (!inFile.EndOfStream)
            {
                var nums = inFile.ReadLine().Split(' ');
                int n = Convert.ToInt32(nums[0]);
                int l = Convert.ToInt32(nums[1]);
                var outlets = new HashSet<string>(inFile.ReadLine().Split(' '));
                var devices = new HashSet<string>(inFile.ReadLine().Split(' '));
                var res = new List<int>();

                var firstOutlet = outlets.First().ToString();

                foreach(var device in devices)
                {
                    var success = true;
                    var diff = Diff(firstOutlet, device);
                    foreach (var checkDevice in devices)
                    {
                        if (!outlets.Contains(Flip(diff, checkDevice)))
                        {
                            success = false;
                            break;
                        }
                    }
                    if (success)
                        res.Add(diff.Count());
                }

                if (res.Count() == 0)
                    outFile.WriteLine("Case #{0}: NOT POSSIBLE", caseNum);
                else
                    outFile.WriteLine("Case #{0}: {1}", caseNum, res.Min());
                caseNum++;
            }
        }

        public List<int> Diff(string a, string b)
        {
            List<int> res = new List<int>();
            for (int i = 0; i < a.Length; i++)
            {
                if (a[i] != b[i])
                    res.Add(i);
            }
            return res;
        }

        public string Flip(List<int> switches, string device)
        {
            string res = device;
            foreach (var pos in switches)
            {
                string c = device[pos].ToString();
                if (c == "1")
                    c = "0";
                else
                    c = "1";
                res = res.Remove(pos, 1);
                res = res.Insert(pos, c);
            }
            return res;
        }
    }
}
