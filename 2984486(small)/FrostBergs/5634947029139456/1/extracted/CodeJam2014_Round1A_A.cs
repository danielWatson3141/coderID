using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Linq;
using System.Windows.Forms;
using CodeJam.ExtentionMethods;

namespace CodeJam.Problems
{
    public class CodeJam2014_Round1A_A : BaseProblem
    {
        protected override object SolveCase()
        {
            int[] inputs = GetNextInputLine().ConvertInputToIntArray();
            
            int N = inputs[0];
            int L = inputs[1];

            List<string> outlets = new List<string>(GetNextInputLine().Split(' '));
            List<string> devices = new List<string>(GetNextInputLine().Split(' '));

            outlets.Sort();
            devices.Sort();

            int minSwitches = Int32.MaxValue;
            List<int> switchesPressed = new List<int>();

            for (int n = 0; n < N; n++)
            {
                switchesPressed.Clear();
                
                for (int l = 0; l < L; l++)
                {
                    if (outlets[n][l] != devices[0][l])
                    {
                        switchesPressed.Add(l);
                    }
                }

                List<string> newOutlets = new List<string>(outlets);
                for (int i = 0; i < newOutlets.Count; i++)
                    foreach (int pressedSwitch in switchesPressed)
                    {
                        newOutlets[i] = newOutlets[i].Insert(pressedSwitch, (newOutlets[i][pressedSwitch] == '1') ? ("0") : ("1"));
                        newOutlets[i] = newOutlets[i].Remove(pressedSwitch + 1, 1);
                    }
                newOutlets.Sort();

                if (String.Join(String.Empty, devices.ToArray()) == String.Join(String.Empty, newOutlets.ToArray()) && switchesPressed.Count < minSwitches)
                    minSwitches = switchesPressed.Count;

                if (minSwitches == 0)
                    break;
            }

            if (minSwitches == Int32.MaxValue)
                return "NOT POSSIBLE";
            else
                return minSwitches.ToString();
        }
    }
}
