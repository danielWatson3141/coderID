using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014R1AA {
    class Program {
        /// <summary>
        /// スレッド数
        /// </summary>
        static int ThreadCount = 4;
        /// <summary>
        /// 進捗を表示する。
        /// </summary>
        static bool Verbose = true;
        static int ProgressInterval = 1;

        class Solver {
            public List<string> SolveAll(int threadId, StreamReader sr) {
                // ------------ 初期化 ------------
                int TestCase = int.Parse(sr.ReadLine());
                // ------------ 初期化 ------------
                List<string> outputs = new List<string>();
                for (int testCase = 0; testCase < TestCase; testCase++) {
                    // ------------ 読み込み ------------
                    int[] cs = (from l in sr.ReadLine().Split(' ') select int.Parse(l)).ToArray();
                    int N = cs[0];
                    int L = cs[1];
                    string otss = sr.ReadLine();
                    string devss = sr.ReadLine();
                    // ------------ 読み込み ------------
                    #region
                    if (testCase % ThreadCount != threadId) {
                        // このスレッドの担当ではないので解かない
                        continue;
                    }
                    if (Verbose) {
                        if (testCase % ProgressInterval == 0) {
                            Console.Error.WriteLine(testCase + " / " + TestCase);
                        }
                    }
                    #endregion
                    // ------------ 呼び出し ------------
                    string output = Solve(testCase, N, L, otss, devss);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            string Solve(int testCase, int N, int L, string otss, string devss) {
                if (testCase == -1) {
                }
                List<long> ots = Decode(otss);
                List<long> devs = Decode(devss);
                int[] f = new int[L];
                bool error = false;
                for (int i = 0; i < L; i++) {
                    int oc = 0;
                    foreach (var ot in ots) {
                        if ((ot & (1 << i)) != 0) {
                            oc++;
                        }
                    }
                    int dc = 0;
                    foreach (var dv in devs) {
                        if ((dv & (1 << i)) != 0) {
                            dc++;
                        }
                    }
                    if (oc == dc) {
                        f[i] |= 1;
                    }
                    if (oc == N - dc) {
                        f[i] |= 2;
                    }
                    if (f[i] == 0) {
                        error = true;
                        break;
                    }
                }
                if (error) {
                    return "NOT POSSIBLE";
                }
                long bc = 0;
                int bcbits = 0;
                List<int> xorix = new List<int>();
                for (int i = 0; i < L; i++) {
                    if (f[i] == 1) {
                    }
                    else if (f[i] == 2) {
                        bc |= 1L << i;
                        bcbits++;
                    }
                    else if (f[i] == 3) {
                        xorix.Add(i);
                    }
                }

                int min = int.MaxValue;
                for (int i = 0; i < 1 << xorix.Count; i++) {
                    long xor = 0;
                    int bits = bcbits;
                    for (int j = 0; j < xorix.Count; j++) {
                        if ((i & (1 << j)) != 0) {
                            xor |= 1L << xorix[j];
                            bits++;
                        }
                    }
                    if (Match(ots, devs, bc, xor)) {
                        if (bits < min) {
                            min = bits;
                        }
                    }
                }
                if (min == int.MaxValue) {
                    return "NOT POSSIBLE";
                }
                else {
                    return min.ToString();
                }
            }
            static bool Match(List<long> ots, List<long> devs, long bc, long xor) {
                ots = ots.ToList();
                devs = devs.ToList();
                foreach (var ot in ots) {
                    long x = ot ^ (bc | xor);
                    int ix = devs.IndexOf(x);
                    if (ix == -1) {
                        return false;
                    }
                    devs.RemoveAt(ix);
                }
                return true;
            }
            static List<long> Decode(string src) {
                List<long> vs = new List<long>();
                List<string> ss = src.Split(' ').ToList();
                foreach (var s in ss) {
                    long v = 0;
                    for (int i = 0; i < s.Length; i++) {
                        v *= 2;
                        if (s[i] == '1') {
                            v++;
                        }
                    }
                    vs.Add(v);
                }
                return vs;
            }
        }


        static void Main(string[] args) {
            // ファイル名が指定されている場合は、指定されたファイルに対して処理を行う。
            // ファイル名が指定されてない場合は、カレントディレクトリの large っぽいファイル、
            // small っぽいファイル、sample.in を順に検索する。
            // large や small が複数ある場合は、名前でソートして一番最後のを使う。
            string inputName = null;
            if (args.Length > 0) {
                if (File.Exists(args[0]) == false) {
                    Console.Error.WriteLine("入力ファイルが見つかりません。");
                    return;
                }
                inputName = args[0];
            }
            if (inputName == null) {
                List<string> larges = new List<string>();
                foreach (var fi in new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles()) {
                    if (fi.Name.Contains("large") && fi.Name.EndsWith(".in")) {
                        larges.Add(fi.FullName);
                    }
                }
                if (larges.Count > 0) {
                    larges.Sort();
                    inputName = larges[larges.Count - 1];
                }
            }
            if (inputName == null) {
                List<string> smalls = new List<string>();
                foreach (var fi in new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles()) {
                    if (fi.Name.Contains("small") && fi.Name.EndsWith(".in")) {
                        smalls.Add(fi.FullName);
                    }
                }
                if (smalls.Count > 0) {
                    smalls.Sort();
                    inputName = smalls[smalls.Count - 1];
                }
            }
            if (inputName == null) {
                foreach (var fi in new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles()) {
                    if (fi.Name.ToLower() == "sample.in") {
                        inputName = fi.FullName;
                        break;
                    }
                }
            }
            if (inputName == null) {
                Console.Error.WriteLine("入力ファイルが見つかりません。");
                return;
            }
            // 出力先のファイル名を決定し、同名のファイルがある場合はリネームする。
            string outputName = inputName;
            if (outputName.EndsWith(".in")) {
                outputName = outputName.Substring(0, outputName.Length - 3);
            }
            outputName += ".out";
            if (File.Exists(outputName)) {
                int rev = 1;
                while (File.Exists(outputName + "." + rev)) {
                    rev++;
                }
                File.Move(outputName, outputName + "." + rev);
            }

            // 実行する。ThreadCount == 1 なら、現在のスレッドで、それ以外なら Parallel で実行する。
            List<string>[] outputs = new List<string>[ThreadCount];
            if (ThreadCount == 1) {
                for (int i = 0; i < ThreadCount; i++) {
                    Solver solver = new Solver();
                    using (StreamReader sr = new StreamReader(inputName)) {
                        outputs[i] = solver.SolveAll(i, sr);
                    }
                }
            }
            else {
                Parallel.For(0, ThreadCount, i => {
                    Solver solver = new Solver();
                    using (StreamReader sr = new StreamReader(inputName)) {
                        outputs[i] = solver.SolveAll(i, sr);
                    }
                });
            }

            // 結果を出力する。Case # はここで付加する。
            using (StreamWriter sw = new StreamWriter(outputName)) {
                for (int i = 0; ; i++) {
                    if (outputs[i % ThreadCount].Count > i / ThreadCount) {
                        sw.WriteLine("Case #" + (i + 1) + ": " + outputs[i % ThreadCount][i / ThreadCount]);
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}
