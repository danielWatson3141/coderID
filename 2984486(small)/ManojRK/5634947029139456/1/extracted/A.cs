using System;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    internal class A : CodeJamBase
    {
        private static readonly int Const1 = Convert.ToInt32("033333333333", 8);
        private static readonly int Const2 = Convert.ToInt32("011111111111", 8);
        private static readonly int Const3 = Convert.ToInt32("030707070707", 8);
        private long[] CL;
        private long[] CN;
        private int L;
        private int N;

        public override bool ExecuteAsynchronus
        {
            get { return false; }
        }

        public override void LoadInput(StreamReader input)
        {
            var list = input.ReadNumberList();
            N = list[0];
            L = list[0];
            CN = input.ReadList().Select(s => Convert.ToInt64(s, 2)).ToArray();
            CL = input.ReadList().Select(s => Convert.ToInt64(s, 2)).ToArray();
        }

        public override string Process()
        {
            var c = CN[0];
            foreach (var chg in CL.Select(cl => c ^ cl).OrderBy(i => i))
            {
                if ((from cn in CN
                     join cl in CL on (cn ^ chg) equals cl
                     select 1).Count() == N)
                {
                    return BitCount((uint) chg).ToString();
                }
            }
            return "NOT POSSIBLE";
        }

        private int BitCount(uint u)
        {
            var uCount = u - ((u >> 1) & Const1) - ((u >> 2) & Const2);
            return (int) (((uCount + (uCount >> 3)) & Const3) % 63);
        }
    }
}