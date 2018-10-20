using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace test {
    public class Ctest {
        public void main(String FileName) {
            FileStream fs, fs2;
            StreamReader sr = null;
            StreamWriter sw = null;

            try {
                fs = new FileStream(FileName, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
                sr = new StreamReader(fs, Encoding.Default);
                fs2 = new FileStream("output.txt", FileMode.Create, FileAccess.ReadWrite, FileShare.Read);
                sw = new StreamWriter(fs2, Encoding.Default);

                //header
                string str = sr.ReadLine();

                int iSize = int.Parse(str);

                for (int ip = 0; ip < iSize; ip++) {
                    string[] strs;
                    str = sr.ReadLine();
                    int N = int.Parse(str);
                    List<node> g = new List<node>();
                    for (int i = 0; i < N; i++) {
                        g.Add(new node(i));
                    }

                    for (int i = 0; i < N - 1; i++) {
                        str = sr.ReadLine();
                        strs = str.Split(new char[] { ' ' });
                        int n1 = int.Parse(strs[0]);
                        int n2 = int.Parse(strs[1]);
                        g[n1-1].anode.Add(g[n2-1]);
                        g[n2-1].anode.Add(g[n1-1]);
                    }

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(g);
                    Console.WriteLine(sres);
                    sw.WriteLine(sres);
                }
            } catch (Exception ex) {
                Console.WriteLine(ex.Message);
            } finally {
                if (sr != null)
                    sr.Close();
                if (sw != null)
                    sw.Close();
            }

            return;
        }
    }

    public class node {
        public int id;
        public int ich;
        public List<node> anode;
        public bool completed;
        public bool deleted;
        public node(int iid) {
            id = iid;
            anode = new List<node>();
        }
    }

    public class prob {
        public static string Solve(List<node> g) {
            //string ret = "";
            int imdel = int.MaxValue;
            foreach (node n in g) {
                for (int i = 0; i < g.Count; i++) {
                    g[i].completed = false;
                    g[i].deleted = false;
                    g[i].ich = 0;
                }

                Search(null, n);
                imdel = Math.Min(imdel, g.Count<node>(gn => gn.deleted));
            }

            return imdel.ToString();
        }

        private static void Search(node p, node n) {
            n.completed = true;

            foreach (node an in n.anode) {
                if (!an.completed && !an.Equals(p)) {
                    Search(n, an);
                }
            }

            if (p == null) {
                if (n.anode.Count == 0 || n.anode.Count == 2) {
                } else if(n.anode.Count == 1){
                    SetDeleted(n, n.anode[0]);
                } else {
                    foreach (node an in n.anode) {
                        if (!an.Equals(p)) {
                            an.ich = CountActiveChild(n, an);
                        } else {
                            an.ich = int.MaxValue;
                        }
                    }
                    n.anode.Sort((n1, n2) => n1.ich < n2.ich ? -1 : n1.ich > n2.ich ? 1 : 0);
                    for (int i = 0; i < n.anode.Count - 2; i++) {
                        SetDeleted(n, n.anode[i]);
                    }
                }
            } else {
                if (n.anode.Count == 1 || n.anode.Count == 3) {
                } else if(n.anode.Count == 2){
                    if (n.anode[0].Equals(p)) {
                        SetDeleted(n, n.anode[1]);
                    } else {
                        SetDeleted(n, n.anode[0]);
                    }
                } else {
                    foreach (node an in n.anode) {
                        if (!an.Equals(p)) {
                            an.ich = CountActiveChild(n, an);
                        } else {
                            an.ich = int.MaxValue;
                        }
                    }
                    n.anode.Sort((n1, n2) => n1.ich < n2.ich ? -1 : n1.ich > n2.ich ? 1 : 0);
                    for (int i = 0; i < n.anode.Count - 3; i++) {
                        SetDeleted(n, n.anode[i]);
                    }
                }
            }
        }

        private static void SetDeleted(node p, node n) {
            n.deleted = true;
            foreach (node an in n.anode) {
                if (!an.Equals(p))
                    SetDeleted(n, an);
            }
        }

        private static int CountActiveChild(node p, node n) {
            int icnt = 0;
            foreach (node an in n.anode) {
                if (!an.Equals(p) && !an.deleted)
                    icnt++;
            }
            return icnt;
        }
    }
}
