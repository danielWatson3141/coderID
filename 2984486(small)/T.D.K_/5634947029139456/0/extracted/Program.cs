using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace prA {
    class Program {
        static char[,] have;
        static string[] need;
        static int L;
        static int N;
        static StreamWriter sw;

        static List<int> anses; 

        static void Perebor(int p, int ans) {
            if(p == L) {
                string[] res = new string[N];
                for(int i = 0; i < N; i++) {
                    StringBuilder sb = new StringBuilder();
                    for(int Li = 0; Li < L; Li++) {
                        sb.Append(have[i, Li]);
                    }
                    res[i] = sb.ToString();
                }
                Array.Sort(res);
                bool good = true;
                for(int i = 0; i < N; i++) {
                    if(res[i] != need[i]) {
                        good = false;
                        break;
                    }
                }
                if(good)
                    anses.Add(ans);
            }
            else {
                Perebor(p + 1, ans);
                for (int i = 0; i < N; i++) {
                    have[i, p] = have[i, p] == '0' ? '1' : '0';
                }
                Perebor(p + 1, ans + 1);
                for (int i = 0; i < N; i++) {
                    have[i, p] = have[i, p] == '0' ? '1' : '0';
                }
            }
        }

        static void Main(string[] args) {
            StreamReader sr = new StreamReader("input");
            sw= new StreamWriter("output");

            int T = int.Parse(sr.ReadLine());
            for(int ti = 0; ti < T; ti++) {
                sw.Write("Case #" + (ti + 1) + ": ");
                string[] ss = sr.ReadLine().Split(' ');
                N = int.Parse(ss[0]);
                L = int.Parse(ss[1]);
                string[] data = sr.ReadLine().Split(' ');
                need = sr.ReadLine().Split(' ');

                have = new char[N, L];
                for (int Ni = 0; Ni < N; Ni++)
                    for (int Li = 0; Li < L; Li++)
                        have[Ni, Li] = data[Ni][Li];

                Array.Sort(need);

                anses = new List<int>();

                Perebor(0, 0);

                anses.Sort();
                if(anses.Count == 0)
                    sw.WriteLine("NOT POSSIBLE");
                else
                    sw.WriteLine(anses[0]);

                //**************************
                //Array.Sort(need);
                //Array.Sort(data);
                //int[] need1 = new int[L];
                //for(int NI = 0; NI < N; NI++) {
                //    for(int Li = 0; Li < L; Li++) {
                //        need1[Li] += need[NI][Li] == '1' ? 1 : 0;
                //    }
                //}
                //int[] have1 = new int[L];
                //for (int NI = 0; NI < N; NI++) {
                //    for (int Li = 0; Li < L; Li++) {
                //        have1[Li] += data[NI][Li] == '1' ? 1 : 0;
                //    }
                //}

                //char[,] have = new char[N, L];
                //for (int Ni = 0;Ni<N;Ni++)
                //    for(int Li = 0; Li < L; Li++)
                //        have[Ni, Li] = data[Ni][Li];

                //int ans = 0;
                //for(int Li = 0; Li < L; Li++) {
                //    if(have1[Li] == need1[Li] && have1[Li] == N - need1[Li]) {
                //        string[] aaa = new string[N];
                //        string[] bbb = new string[N];
                //        for(int i = 0; i < N; i++) {
                //            aaa[i] = need[i].Substring(0, Li + 1);
                //        }
                //        for(int i = 0; i < N; i++) {
                //            StringBuilder sb = new StringBuilder();
                //            for(int lli = 0; lli <= Li; lli++) {
                //                sb.Append(have[i, lli]);
                //            }
                //            bbb[i] = sb.ToString();
                //        }
                //        Array.Sort(aaa);
                //        Array.Sort(bbb);
                //        bool g = true;
                //        for(int i = 0; i < N; i++) {
                //            if(aaa[i] != bbb[i]) {
                //                g = false;
                //                break;
                //            }
                //        }
                //        if(!g) {
                //            aaa = new string[N];
                //            bbb = new string[N];
                //            for(int i = 0; i < N; i++) {
                //                aaa[i] = need[i].Substring(0, Li + 1);
                //            }
                //            for(int i = 0; i < N; i++) {
                //                have[i, Li] = have[i, Li] == '0' ? '1' : '0';
                //            }
                //            for(int i = 0; i < N; i++) {
                //                StringBuilder sb = new StringBuilder();
                //                for(int lli = 0; lli <= Li; lli++) {
                //                    sb.Append(have[i, lli]);
                //                }
                //                bbb[i] = sb.ToString();
                //            }
                //            Array.Sort(aaa);
                //            Array.Sort(bbb);
                //            g = true;
                //            for(int i = 0; i < N; i++) {
                //                if(aaa[i] != bbb[i]) {
                //                    g = false;
                //                    break;
                //                }
                //            }
                //            if(g) {
                //                ans++;
                //            }
                //            else {
                //                for(int i = 0; i < N; i++) {
                //                    have[i, Li] = have[i, Li] == '0' ? '1' : '0';
                //                }
                //            }
                //        }
                //    }
                //    else if(N - have1[Li] == need1[Li]) {
                //        ans++;
                //        for(int i = 0; i < N; i++) {
                //            have[i, Li] = have[i, Li] == '0' ? '1' : '0';
                //        }
                //    }
                //}
                //string[] res = new string[N];
                //for(int i = 0; i < N; i++) {
                //    StringBuilder sb = new StringBuilder();
                //    for(int Li = 0; Li < L; Li++) {
                //        sb.Append(have[i, Li]);
                //    }
                //    res[i] = sb.ToString();
                //}
                //Array.Sort(res);
                //bool good = true;
                //for(int i = 0; i < N; i++) {
                //    if (res[i] != need[i])
                //        good = false;
                //}
                //if(good)
                //    sw.WriteLine(ans);
                //else {
                //    sw.WriteLine("NOT POSSIBLE");
                //}
            }
            sr.Close();
            sw.Close();
        }
    }
}
