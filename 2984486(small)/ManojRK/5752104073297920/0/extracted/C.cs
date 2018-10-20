using System;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    internal class C : CodeJamBase
    {
        private int[] nums;

        public override bool ExecuteAsynchronus
        {
            get { return false; }
        }

        public override void LoadInput(StreamReader input)
        {
            input.ReadLine();
            nums = input.ReadNumberList();
        }

        public override string Process()
        {
            //return Enumerable.Repeat(1, 120).Select(i => IsGood(BadAlg())).Average().ToString();
            //return Enumerable.Repeat(1,100).Select(j => Enumerable.Repeat(1, 120).Where(i => IsGood(BadAlg()) <= 254).Count()).Average().ToString();
            return IsGood(nums) <= 254 ? "GOOD" : "BAD";
        }

        private static int IsGood(int[] nums)
        {
            return nums.Take(500).Where(i => i < 500).Count();
        }

        private static int[] GoodAlg()
        {
            var rand = new Random();
            var n = new int[1000];
            for (int i = 0; i < 1000; i++)
            {
                n[i] = i;
            }
            for (int i = 0; i < 1000; i++)
            {
                Swap(n, i, rand.Next(i, 1000));
            }
            return n;
        }

        private static int[] BadAlg()
        {
            var rand = new Random();
            var n = new int[1000];
            for (int i = 0; i < 1000; i++)
            {
                n[i] = i;
            }
            for (int i = 0; i < 1000; i++)
            {
                Swap(n, i, rand.Next(0, 1000));
            }
            return n;
        }

        private static void Swap(int[] nums, int i, int j)
        {
            var c = nums[i];
            nums[i] = nums[j];
            nums[j] = c;
        }
    }
}