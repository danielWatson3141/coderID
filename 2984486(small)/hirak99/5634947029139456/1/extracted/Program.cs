using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2013R1A {
    class Program {
        Tuple<string[],int> rehash(string[] arr, string el_from, string el_to) {
            int mismatch=0;
            for (int j = 0; j < el_from.Length; ++j) {
                if (el_from[j] != el_to[j]) {
                    ++mismatch;
                }
            }
            string[] result_arr = new string[arr.Length];
            for (int i = 0; i < arr.Length; ++i) {
                string result = "";
                for (int j = 0; j < el_from.Length; ++j) {
                    if (el_from[j] == el_to[j]) result += (arr[i][j] == '1' ? '1' : '0');
                    else result += (arr[i][j] == '1' ? '0' : '1');
                }
                result_arr[i] = result;
            }
            return new Tuple<string[], int>(result_arr, mismatch);
        }
        string Solve() {
            Console.ReadLine();
            string[] arr1 = Console.ReadLine().Split().ToArray();
            string[] arr2 = Console.ReadLine().Split().ToArray();
            Array.Sort(arr2);
            int nSwitch = int.MaxValue;
            for (int i = -1; i < arr1.Length; ++i) {
                Tuple<string[], int> result = i == -1 ? new Tuple<string[], int>(arr1, 0) : rehash(arr1, arr1[i], arr2[0]);
                Array.Sort(result.Item1);
                bool allEqual = true;
                for (int j = 0; allEqual && j < result.Item1.Length; ++j)
                    if (result.Item1[j] != arr2[j]) allEqual = false;
                if (allEqual && result.Item2 < nSwitch) {
                    nSwitch = result.Item2;
                }
            }
            return nSwitch == int.MaxValue ? "NOT POSSIBLE" : nSwitch.ToString();
        }
        Program() {
            int dummy = int.Parse(Console.ReadLine());
            for (int i = 0; i < dummy; ++i)
                Console.WriteLine("Case #{0}: {1}", i + 1, Solve());
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
