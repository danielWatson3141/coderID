using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ChargingChaos
{
    class Calc
    {
        private int nDev;
        private int txtLen;
        private long[] inputCnf;
        private long[] outputCnf;

        public Calc(int nDev, int txtLen, long[] inputCnf, long[] outputCnf)
        {
            // TODO: Complete member initialization
            this.nDev = nDev;
            this.txtLen = txtLen;
            this.inputCnf = inputCnf;
            this.outputCnf = outputCnf;
        }
        internal int Calculate()
        {
            int res = Consider(txtLen-1);
            return res;
        }

        public int Consider(int bitPos)
        {
            // check if values for bits txtLen-1 to bitPos+1 match
            {
                long mask = 0;
                for (int cBit=bitPos+1;cBit<txtLen;++cBit)
                {
                    mask = mask | 1<<cBit;
                }
                for (int cDev=0;cDev<nDev;++cDev)
                {
                    if (! ((inputCnf[cDev] & mask) == (outputCnf[cDev] & mask)) )
                        return int.MaxValue-1000;
                }
            }
            if (bitPos<0)
                return 0;

            int in_n0;
            int in_n1;
            int out_n0;
            int out_n1;
            Count10(bitPos, out in_n0, out in_n1, inputCnf);
            Count10(bitPos, out out_n0, out out_n1, outputCnf);
            if (in_n0==in_n1 && (in_n0==out_n0))
            {
                int res1 = Consider(bitPos-1);
                FlipBit(ref inputCnf, bitPos);
                int res2 = Consider(bitPos-1)+1;
                FlipBit(ref inputCnf, bitPos);
                return Math.Min(res1, res2);
            }
            else if (in_n0==out_n0)
            {
                return Consider(bitPos - 1);
            }
            else if (in_n0 == out_n1)
            {
                FlipBit(ref inputCnf, bitPos);
                int res = Consider(bitPos-1)+1;
                FlipBit(ref inputCnf, bitPos);
                return res;
            }
            return int.MaxValue-1000;
        }

        private void FlipBit(ref long[] inputCnf, int bitPos)
        {
            long mask = 1 << bitPos;
            for (int cDev = 0; cDev < nDev; ++cDev)
                inputCnf[cDev] ^= mask;
            inputCnf = inputCnf.OrderBy(l => l).ToArray();
        }

        private void Count10(int cBit, out int n0, out int n1, long[] devArr)
        {
            long mask = 1 << cBit;
            n0 = 0;
            n1 = 0;

            for (int cDev = 0; cDev < nDev; ++cDev)
            {
                if ((devArr[cDev] & mask) != 0)
                    ++n1;
                else ++n0;
            }
        }
    }
}
