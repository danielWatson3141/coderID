using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using Quadruple;

namespace gcj_rotate
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("A-large-practice.in");
            int T=Convert.ToInt32(sr.ReadLine());
            var sw= new StreamWriter("A-large-practice.out");
            for (int t = 0; t < T; t++)
            {
                var vals=sr.ReadLine().Split(' ');
                int n = Convert.ToInt32(vals[0]);
                int k = Convert.ToInt32(vals[1]);
                string[] str = new string[n];
                for (int i = 0; i < n; i++)
                {
                    str[i]=sr.ReadLine().Replace(".","");
                    int l = str[i].Length;
                    for(int j=0;j<n-l;j++) str[i] = '.'+str[i];
                }
                bool r=false;
                bool b=false;
                for(int i=0;i<n;i++)
                    for (int j = 0; j < n; j++)
                    {
                        if (!r && str[i][j] == 'R')
                        {
                            bool s1 = true;
                            bool s2 = true;
                            bool s3 = true;
                            bool s4 = true;
                            for (int l = 1; l < k; l++)
                            {
                                if (i + k <= n) s1 = s1 && (str[i+l][j] == 'R');
                                if (j + k <= n) s2 = s2 && (str[i][j + l] == 'R');
                                if (i + k <= n && j + k <= n) s3 = s3 && (str[i + l][j + l] == 'R');
                                if (i + k <= n && j - k >= -1) s4 = s4 && (str[i + l][j - l] == 'R');
                            }
                            r=s1 && i + k <= n || s2 && j + k <= n || s3 && i + k <= n && j + k <= n || s4 && i + k <= n && j - k >= -1;
                        }
                        if (!b && str[i][j] == 'B')
                        {
                            bool s1 = true;
                            bool s2 = true;
                            bool s3 = true;
                            bool s4 = true;
                            for (int l = 1; l < k; l++)
                            {
                                if (i + k <= n) s1 = s1 && (str[i+l][j] == 'B');
                                if (j + k <= n) s2 = s2 && (str[i][j + l] == 'B');
                                if (i + k <= n && j + k <= n) s3 = s3 && (str[i + l][j + l] == 'B');
                                if (i + k <= n && j - k >= -1) s4 = s4 && (str[i + l][j - l] == 'B');
                            }
                            b = s1 && i + k <= n || s2 && j + k <= n || s3 && i + k <= n && j + k <= n || s4 && i + k <= n && j - k >= -1;
                        }
                    }
                sw.Write("Case #"+(t+1).ToString()+": ");
                if(r&&b) sw.WriteLine("Both"); else if (r) sw.WriteLine("Red"); else if(b) sw.WriteLine("Blue"); else sw.WriteLine("Neither");

            }
            sw.Close();
            sr.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("C-large-practice.in");
            int n = Convert.ToInt32(sr.ReadLine());
            var sw = new StreamWriter("C-large-practice.out");
            string per1="1573";
            string per2 = "24530093447546990655";
            string per3 = "1796993094044906218573149716344821084545393295927482030069059550937814268502836551789154546067040725";
            for (int t = 0; t < n; t++)
            {

                int i = Convert.ToInt32(sr.ReadLine());
             /* 
                int a = 2;
                int b = 6;
                int c = a;
                if (i == 0) c = a; else if (i == 1) c = b;else 
                    for (int j = 1; j < i; j++)
                    {

                        c = 6 * b - 4 * a;
                        while (c < 0) c += 1000;
                        c = c % 1000;
                        a = b;
                        b = c;

                    }
                sw.WriteLine("Case #" + (t + 1).ToString() + ": " + (c-1).ToString("000"));*/
                string let1 = "";
                string let2 = "";
                string let3 = "";
                if (i < 2) let3 = "0"; else let3 = per3[(i - 3) % per3.Length].ToString();
                if (i < 1) let2 = "0"; else let2 = per2[(i - 2) % per2.Length].ToString();
                let1 = per1[i % per1.Length].ToString();
                sw.WriteLine("Case #" + (t + 1).ToString() + ": " + let3+let2+let1);
               
            }
            sw.Close();
            sr.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("B-small-practice (1).in");
            int c = Convert.ToInt32(sr.ReadLine());
            var sw = new StreamWriter("B-small-practice (1).out");
            List<Point> E0=new List<Point>();
            List<Point> E1=new List<Point>();

            for (int t = 0; t < c; t++)
            {
                int n = Convert.ToInt32(sr.ReadLine());
                int m = Convert.ToInt32(sr.ReadLine());
                for (int i = 0; i < m; i++)
                {
                    var vals = sr.ReadLine().Split(' ');
                    int T = Convert.ToInt32(vals[0]);
                    for (int j = 0; j < T; j++)
                        if (vals[1 + j*2 + 1] == "0") E0.Add(new Point(i, Convert.ToInt32(vals[1 + j*2]))); else E1.Add(new Point(i, Convert.ToInt32(vals[1 + j*2])));
                    // есть граф

                }
                sw.WriteLine("Case #" + (t + 1).ToString() + ": ");       
            }
            sw.Close();
            sr.Close();
  
        }

        private void button4_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("A-small-attempt0.in ");
            var sw = new StreamWriter("A-small-attempt0.out");
            int T = Convert.ToInt32(sr.ReadLine());
            for (int t = 0; t < T; t++)
            {
                int r1 = Convert.ToInt32(sr.ReadLine());
                int i = 1;
                for (; i < r1; i++) sr.ReadLine();
                var row1 = sr.ReadLine().Split(' ');
                for (; i < 4; i++) sr.ReadLine();
                int r2 = Convert.ToInt32(sr.ReadLine());
                i = 1;
                for (; i < r2; i++) sr.ReadLine();
                var row2 = sr.ReadLine().Split(' ');
                for (; i < 4; i++) sr.ReadLine();
                var res = row1.Intersect(row2).ToList();
                sw.Write("Case #" + (t + 1).ToString() + ": ");
                if (res.Count >1) sw.WriteLine("Bad magician!");
                else
                    if (res.Count == 1) sw.WriteLine(res[0]); else
                        sw.WriteLine("Volunteer cheated!");

            }
            sr.Close();
            sw.Close();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("B-large.in ");
            var sw = new StreamWriter("B-large.out");
            int T = Convert.ToInt32(sr.ReadLine());
            decimal gamma= 0.5772156649015328606065120M;
            for (int t = 0; t < T; t++)
            {
                var val = sr.ReadLine().Split(' ');
                decimal C = Convert.ToDecimal(val[0].Replace('.',','));
                decimal F = Convert.ToDecimal(val[1].Replace('.', ','));
                decimal X = Convert.ToDecimal(val[2].Replace('.', ','));
                int i = 0;
                decimal sum = 0;
                decimal lastres = X/2;
                bool stop=false;
                while(true)
                {
                    decimal sum2 = ((decimal)Math.Log(2+i*(double)F))/F+gamma;
                    if (!stop)
                    {
                        sum += 1 / (2 + i * F);
                        if (Math.Abs(sum2 - sum) < 0.0000001M) stop = true;
                    }
                    else sum = sum2;
                    decimal res = C * sum + (X-C) / (2 + i * F);
                    if (res > lastres) break;
                    lastres = res;
                    i++;
                }
                sw.WriteLine("Case #" + (t + 1).ToString() + ": " + lastres.ToString("0.0000000").Replace(',', '.'));
            
            }
            sr.Close();
            sw.Close();
        }
        int ceil(int a, int b)
        {
            if (a % b == 0) return a / b;
            return a / b + 1;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("C-large.in ");
            var sw = new StreamWriter("C-large.out");
            int T = Convert.ToInt32(sr.ReadLine());
            List<string> res=new List<string>();
            for (int t = 0; t < T; t++)
            {
                var val = sr.ReadLine().Split(' ');
                int R = Convert.ToInt32(val[0]);
                int C = Convert.ToInt32(val[1]);
                int M = Convert.ToInt32(val[2]);
                sw.WriteLine("Case #" + (t + 1).ToString() + ":");
                int i = Math.Min(R, C);
                int j = R * C - M;
                if(i>1 && (j==2 || j==3 || j==5 || j==7) || j<1 || i==2 && j%2==1 && j!=1) sw.WriteLine("Impossible"); else
                {
                    if (i == 1)
                    {
                        if (R == 1)
                        {
                            string str = "c";
                            for (int k = 1; k < j; k++) str += '.';
                            for (int k = 0; k < M; k++) str += '*';
                            sw.WriteLine(str);
                        }
                        else
                        {
                            sw.WriteLine("c");
                            for (int k = 1; k < j; k++) sw.WriteLine('.');
                            for (int k = 0; k < M; k++) sw.WriteLine('*');
                        }
                    } else
                        if(j==1)
                        {
                            string str = "c";
                            string str1 = "*";
                            for(int k=1;k<C;k++) {str+='*';str1+='*';}
                            sw.WriteLine(str);
                            for(int k=1;k<R;k++) sw.WriteLine(str1);                            
                        } else
                            if(j==4)
                            {
                                string str = "c.";
                                string str1 = "..";
                                string str2 = "**";
                                for (int k = 2; k < C; k++) { str += '*'; str1 += '*'; str2 += '*'; }
                                sw.WriteLine(str);
                                sw.WriteLine(str1);
                                for (int k = 2; k < R; k++) sw.WriteLine(str2);                            
                            } else
                                if (i == 2)
                                {
                                    if (R == 2)
                                    {
                                        string str = "c";
                                        string str1 = ".";
                                        for (int k = 1; k < j / 2; k++) { str += '.'; str1 += '.'; }
                                        for (int k = 0; k < M / 2; k++) { str += '*'; str1 += '*'; }
                                        sw.WriteLine(str);
                                        sw.WriteLine(str1);

                                    }
                                    else
                                    {
                                        sw.WriteLine("c.");
                                        for (int k = 1; k < j / 2; k++) sw.WriteLine("..");
                                        for (int k = 0; k < M / 2; k++) sw.WriteLine("**");
                                    }
                                }
                                else
                                    if (j % 2 == 0)
                                    {
                                        string str = "c";
                                        string str1 = ".";
                                        int m = 0;
                                        int k = 1;
                                        for (; k < Math.Min(j / 2, C); k++) { str += '.'; str1 += '.'; }
                                        for (; k < C; k++) { str += '*'; str1 += '*'; m += 2; }
                                        sw.WriteLine(str);
                                        sw.WriteLine(str1);
                                        str = ""; for (k = 0; k < C; k++) str += '.';
                                        //       for (k = 0; k < R - 2 - ceil(M - m , C); k++) sw.WriteLine(str);
                                        if ((M - m) % C == C - 1 && R - 2 - ceil(M - m, C) > 0)
                                        {
                                            for (k = 0; k < R - 3 - ceil(M - m, C); k++) sw.WriteLine(str);
                                            str = "*"; for (k = 1; k < C; k++) str += '.';
                                            sw.WriteLine(str);
                                            m++;
                                        }
                                        else
                                            for (k = 0; k < R - 2 - ceil(M - m, C); k++) sw.WriteLine(str);
                                        if ((M - m) % C != 0)
                                        {
                                            str = ""; for (k = 0; k < (M - m) % C; k++) str += '*';
                                            for (; k < C; k++) str += '.';
                                            sw.WriteLine(str);
                                        }
                                        str = ""; for (k = 0; k < C; k++) str += '*';
                                        for (k = 0; k < (M - m) / C; k++) sw.WriteLine(str);
                                    }
                                    else
                                    if (i == 3)
                                    {
                                        if (R == 3)
                                        {
                                            string str = "c";
                                            string str1 = ".";
                                            string str2 = ".";
                                            if (j % 3 == 1) str2 = "*";
                                            int k = 1;
                                            for (; k < Math.Min(j / 3, C); k++) { str += '.'; str1 += '.'; str2 += '.'; }
                                            if (k != C && j % 3 != 0)
                                            {
                                                str += '*'; str1 += '.'; str2 += '.'; k++;
                                            }
                                            for (; k < C; k++) { str += '*'; str1 += '*'; str2 += '*'; }
                                            sw.WriteLine(str);
                                            sw.WriteLine(str1);
                                            sw.WriteLine(str2);
                                        }
                                        else
                                        {
                                            if (j % 3 == 1) sw.WriteLine("c.*"); else sw.WriteLine("c..");
                                            int k = 1;
                                            for (; k < Math.Min(j / 3, R); k++) { sw.WriteLine("..."); }
                                            if (k != R && j % 3 != 0)
                                            {
                                                sw.WriteLine("*.."); k++;
                                            }
                                            for (; k < R; k++) { sw.WriteLine("***"); }
                                        }
                                    }
                                    
                                     
                                        else
                                        {
                                            string str = "c";
                                            string str1 = ".";
                                            string str2 = ".";
                                            int m = 0;
                                            int k = 1;
                                            if (j % 3 == 0)
                                            {
                                                for (; k < Math.Min(j / 3, C); k++) { str += '.'; str1 += '.'; str2 += '.'; }
                                                for (; k < C; k++) { str += '*'; str1 += '*'; str2 += '*'; m += 3; }
                                            }
                                            else
                                            {
                                                if (j <= 3 * C) {str2 = "*"; m = 1;}
                                                for (; k < Math.Min(j/3, C); k++) { str += '.'; str1 += '.'; str2 += '.'; }
                                                if (j <= 3 * C)
                                                {
                                                    if (M - 1 - 3 * (C - k - 1) > (R - 3) * C) { str += "."; str1 += "."; str2 += "*"; k++; m++; }
                                                    else
                                                    { str += "."; str1 += "."; str2 += "."; k++; }
                                                }
                                                for (; k < C; k++) { str += '*'; str1 += '*'; str2 += '*'; m += 3; }
                                            }
                                            sw.WriteLine(str);
                                            sw.WriteLine(str1);
                                            if ((M - m) % C == C - 1 && R - 4 - (M - m) / C<=0)
                                            {
                                                str2 = "*" + str2.Substring(1);
                                                m++;
                                            }
                                            sw.WriteLine(str2);
                                            str = ""; for (k = 0; k < C; k++) str += '.';
                                            if ((M - m) % C == C - 1 && R - 3 - ceil(M - m, C) > 0)
                                            {
                                                for (k = 0; k < R - 4 - ceil(M - m, C); k++) sw.WriteLine(str);
                                                str = "*"; for (k = 1; k < C; k++) str += '.';
                                                sw.WriteLine(str);
                                                m++;
                                            }
                                            else
                                                for (k = 0; k < R - 3 - ceil(M - m, C); k++) sw.WriteLine(str);
                                            if ((M - m) % C != 0)
                                            {
                                                str = ""; for (k = 0; k < (M - m) % C; k++) str += '*';
                                                for (; k < C; k++) str += '.';
                                                sw.WriteLine(str);
                                            }
                                            str = ""; for (k = 0; k < C; k++) str += '*';
                                            for (k = 0; k < (M-m)/C; k++) sw.WriteLine(str);
                                          
                                        }

                   
                }

            }
            sr.Close();
            sw.Close();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("D-large.in ");
            var sw = new StreamWriter("D-large.out");
            int T = Convert.ToInt32(sr.ReadLine());
            for (int t = 0; t < T; t++)
            {
                int N = Convert.ToInt32(sr.ReadLine());
                var Na = sr.ReadLine().Split(' ');
                var Ke = sr.ReadLine().Split(' ');
                List<double> Naomi=new List<double>();
                List<double> Ken=new List<double>();
                for (int i = 0; i < N; i++)
                {
                    Naomi.Add(Convert.ToDouble(Na[i].Replace('.', ',')));
                    Ken.Add(Convert.ToDouble(Ke[i].Replace('.', ',')));
                }
                Naomi.Sort();
                Ken.Sort();
                int j=0;
                for (int i = 0; i < N; i++)
                {
                    for (; j < N && Naomi[j] < Ken[i]; j++) ;
                    if (j == N) { sw.Write("Case #" + (t + 1).ToString() + ": " + i.ToString() + " "); break; } else if (i == N - 1) { sw.Write("Case #" + (t + 1).ToString() + ": "+N.ToString()+" "); /*stop = true;*/ break; }
                    j++;
                }
                    j = 0;
                    for (int i = 0; i < N; i++)
                    {
                        for (; j < N && Ken[j] < Naomi[i]; j++) ;
                        if (j == N) { sw.WriteLine((N - i).ToString()); break; } else if (i == N - 1) { sw.WriteLine("0"); break; }
                        j++;
                    }
         
            }
            sr.Close();;
            sw.Close();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("C-small-attempt0.out");
          //  var sr2 = new StreamReader("C-small-attempt0.in");
            var sw = new StreamWriter("C-small-attempt0.in---");
            int t=0;
            int r = 0;
            int c = 0;
            int m = 0;
            while (!sr.EndOfStream)
            {
                var str=sr.ReadLine();
                if (str == "Impossible")
                {
                } else
                if (str.StartsWith("Case"))
                {
                    t++;
                    sw.WriteLine(r.ToString() + " " + c.ToString() + " " + m.ToString());
                    r = 0;
                    c = 0;
                    m = 0;
                }
                else
                {
                    int cc=str.Length;
                    if (c == 0) c = cc;
                    r++;
                    if (cc != c) sw.WriteLine("ERROR! rowlength");
                    for (int i = 0; i < cc; i++)
                    {
                        if (str[i] == '*') m++;
                    }
                }

            }
            sr.Close();
            sw.Close();
    
        }
        bool antinumbergame(int A, int B)
        {
            if (A == B || A<=0 || B<=0) return true;
            if (A > B)
            {
                int C = A;
                A = B;
                B = C;
            }
            for (int i = 1; i < B / A; i++)
                if (!numbergame(A, B - A * i)) return false;
            return true;
        }
        bool numbergame(int A, int B)
        {
            if (A == B || A<=0 || B<=0 ) return false;
            if (A > B)
            {
                int C = A;
                A = B;
                B = C;
            }
            if (A == 1) return true;
            for (int i = 1; i < B / A; i++)
               if (antinumbergame(A, B - A * i)) return true;
            return false;
        }
        private void button9_Click(object sender, EventArgs e)
        {
            for(int A=2;A<100;A++)
                for (int B = 2; B < 100; B++)
                {
                    Console.WriteLine(A.ToString()+" "+B.ToString()+" "+numbergame(A, B).ToString());
                }
        }

        int check(int i, int N,int L,List<string> vectors1,List<string> vectors2)
        {
            bool stright=true;
                     for (int k = 0; k < N; k++)
                     {
                        if (vectors1[k][i] != vectors2[k][i]) stright=false;
                     }
            var vectors3=new List<string>();
                            for (int k = 0; k < N; k++)
                            {
                                if (vectors1[k][i] == '0') vectors3.Add(vectors1[k].Substring(0, i) + "1" + vectors1[k].Substring(i + 1)); else vectors3.Add(vectors1[k].Substring(0, i) + "0" + vectors1[k].Substring(i + 1));
                            }
            vectors3.Sort();
            bool inv=true;
                     for (int k = 0; k < N; k++)
                     {
                        if (vectors3[k][i] != vectors2[k][i]) inv=false;
                     }
            if(i!=L-1)
            {
                int I1=-1;
                if(stright) I1=check(i+1,N,L,vectors1,vectors2);
                int I2=-1;
                if(inv) I2=check(i+1,N,L,vectors3,vectors2);
                if (I1 == -1 && I2==-1) return -1;
                if (I1 == -1) return I2 + 1;
                if(I2==-1) return I1;
                return Math.Min(I1,I2+1);
            }
            if(stright) return 0;
            if(inv) return 1;
            return -1;    
        
           
        }
        private void button10_Click(object sender, EventArgs e)
        {
      var sr = new StreamReader("A-large.in ");
            var sw = new StreamWriter("A-large.out");
            int T = Convert.ToInt32(sr.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var vals=sr.ReadLine().Split(' ');
                int N = Convert.ToInt32(vals[0]);
                int L = Convert.ToInt32(vals[1]);
                var vectors1 = sr.ReadLine().Split(' ').ToList();
                var vectors2 = sr.ReadLine().Split(' ').ToList();
                vectors1.Sort();
                vectors2.Sort();
                int I=check(0,N,L,vectors1,vectors2);
                    if (I==-1)
                    {
                        sw.WriteLine("Case #" + (t+1).ToString() + ": NOT POSSIBLE");
                    } else sw.WriteLine("Case #" + (t+1).ToString() + ": "+I.ToString());
                
            }
     
            sr.Close();
            sw.Close();
        }
    }
}