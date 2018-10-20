using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Electric {
    class Program {
        static void Main(string[] args) {
            int testCount = Console.ReadLine().Split().Select(it => Int32.Parse(it)).First();
            for(int i = 1; i <= testCount; i++) {
                Test test = new Test();
                test.Load();
                Console.WriteLine("Case #{0}: {1}", i, test.Solve());
            }
        }
    }

    public class Test {
        int outletcount, bitcount;
        long[] outlets;
        long[] flows;
        public void Load() {
            var pars = Console.ReadLine().Split().Select(it => Int32.Parse(it));
            outletcount = pars.First();
            bitcount = pars.Last();
            outlets = Console.ReadLine().Split().Select(it => Convert.ToInt64(it, 2)).ToArray();
            flows = Console.ReadLine().Split().Select(it => Convert.ToInt64(it, 2)).ToArray();
        }
        bool checkLine(List<long> newPositions) {
            foreach(long outlet in outlets) {
                if(!newPositions.Remove(outlet)) {
                    return false;
                }
            }
            return true;
        }
        int calc() {
            int result = bitcount + 1;
            foreach(long val in outlets) {
                long combination = val ^ flows[0];
                int switches = Convert.ToString(combination, 2).Split('1').Length - 1;
                if(switches < result) {
                    if(checkLine(flows.Select(it => it ^ combination).ToList())) {
                        result = switches;
                    }
                }
            }
            return result;
        }
        public string Solve() {
            int res = calc();
            if(res == bitcount + 1) {
                return "NOT POSSIBLE";
            }
            return res.ToString();
        }
    }
}
