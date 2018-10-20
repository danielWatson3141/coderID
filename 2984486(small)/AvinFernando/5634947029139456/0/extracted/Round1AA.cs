using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace GoogleCodeJam.Fourteen.Round1A
{
    /// <summary>
    /// CodeJamProblem contains a collection of TestCases which are created by parsing the input file.
    /// The Solve method is called for each Test Case, then The output file is generated.
    /// </summary>
    public class Round1AA : CodeJamProblem<Round1AATestCase>
    {
        protected override void ParseCase(Round1AATestCase currentCase, int currentCaseNum, ref int currentLine, string[] lines)
        {
            var field = lines[currentLine].Split(_delimiterChars);
            currentCase.Switches = int.Parse(field[0]);
            currentCase.Bits = int.Parse(field[1]);
            currentLine++;
            field = lines[currentLine].Split(_delimiterChars);
            foreach (var num in field)
                currentCase.Outlets.Add(GetLong(num));
            currentLine++;
            field = lines[currentLine].Split(_delimiterChars);
            foreach (var num in field)
                currentCase.Devices.Add(GetLong(num));
            currentLine++;
        }

        private long GetLong(string s)
        {
            long n = 0;
            for (int i = 0; i < s.Length;i++)
            {
                n += s[i] == '1' ? 1 : 0;
                if (i != s.Length - 1)
                    n <<= 1;
            }
            return n;
        }
        protected override StringBuilder OutputForEachCase(Round1AATestCase testCase, StringBuilder currentString)
        {
            if (testCase.NumFlips == null)
                currentString.Append("NOT POSSIBLE");
            else
                currentString.Append(testCase.NumFlips.Value);
            return currentString;
        }
    }

    public class Round1AATestCase : ITestCase
    {
        public int Switches { get; set; }
        public int Bits { get; set; }
        public HashSet<long> Outlets { get; set; }
        public HashSet<long> Devices { get; set; }
        public int? NumFlips { get; set; }

        public Round1AATestCase()
        {
            Outlets = new HashSet<long>();
            Devices = new HashSet<long>();
        }

        static Round1AATestCase()
        {
        }

        public void Solve()
        {
            long mask = 0;
            int minflips = Bits + 1;
            long maxvalue = 1;
            maxvalue <<= Bits;
            var flippedOutlets = new HashSet<long>(Outlets);
            int numBits = 0;
            while (mask < maxvalue)
            {
                flippedOutlets = new HashSet<long>(Outlets.Select(x => x ^ mask));
                if (flippedOutlets.IsSubsetOf(Devices) && flippedOutlets.IsSupersetOf(Devices))
                    minflips = Math.Min(minflips, numBits);
                for (long j = 1; (j & mask) != 0; j <<= 1)
                    numBits--;
                numBits++;
                mask++;
            }
            if (minflips <= Bits)
                NumFlips = minflips;
        }
    }
}
