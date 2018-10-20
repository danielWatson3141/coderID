using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

class AChargingChaos
{
    static void Main()
    {
        var T = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
        for (int t = 1; t <= T; t++)
        {
            var NL = Console.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            if (NL.Length != 2)
                throw new InvalidOperationException("Expected 2 items in line, actual count " + NL.Length);
            var N = int.Parse(NL[0], CultureInfo.InvariantCulture);
            var L = int.Parse(NL[1], CultureInfo.InvariantCulture);

            var outlets = Console.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(_ => _.ToCharArray()).ToArray();
            if (outlets.Length != N)
                throw new InvalidOperationException("Expected " + N + " items in line, actual count " + outlets.Length);

            var devices = Console.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(_ => _.ToCharArray()).ToArray();
            if (devices.Length != N)
                throw new InvalidOperationException("Expected " + N + " items in line, actual count " + devices.Length);

            int flipCount = 0;
            for (int j = 0; j < L; j++)
            {
                int outlet1Count = 0, device1Count = 0;
                for (int i = 0; i < N; i++)
                {
                    outlet1Count += outlets[i][j] - '0';
                    device1Count += devices[i][j] - '0';
                }
                if (outlet1Count == device1Count)
                    continue;
                else if (N - outlet1Count == device1Count)
                {
                    flipCount++;
                    continue;
                }
                else
                {
                    Console.WriteLine("Case #{0}: NOT POSSIBLE", t);
                    goto next;
                }
            }
            Console.WriteLine("Case #{0}: {1}", t, flipCount);
        next: ;
        }
    }
}
