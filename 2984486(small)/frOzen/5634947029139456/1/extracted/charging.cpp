#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;



int MaxN=150+5;
int MaxL=40+5;

char opp(char x)
{
    if (x=='1') return  '0';
            else return '1';
};
int main(int argc, const char * argv[])
{
   ifstream fin;
   ofstream fout;
   int t;
   fin.open("data.in",std::ofstream::in);
   fout.open("data.out",std::ofstream::out);

   fin>>t;
   char f[MaxN][MaxL];
   char p[MaxN][MaxL];
   for (int step=0;step<t;step++)
   {
        int N, L , ans;
        fin>> N >> L;
        ans=L+1;
        char x;


        for (int i=0;i<N;i++)
        {

           for (int j=0;j<L;j++)
           {
           fin>>x;
           f[i][j]=x;
           }
        }
        for (int i=0;i<N;i++)
        {

           for (int j=0;j<L;j++)
           {
           fin>>x;
           p[i][j]=x;
           }
        }
        for (int i=0;i<N;i++)
        {
            bool swi[MaxL];
            int sans=0;
            for (int j=0;j<L;j++)
                if (f[i][j]!=p[0][j])   {
                                            sans++;
                                            swi[j]=true;
                                        }
                            else      swi[j]=false;
            char t[MaxN][MaxL];

            for (int j=0;j<N;j++)
                for (int k=0;k<L;k++)
                    if (swi[k])  t[j][k]=opp(f[j][k]);
                            else t[j][k]=f[j][k];
            bool test[MaxN];
            for (int j=0;j<N;j++)
                test[j]=true;
          /*  for (int j=0;j<N;j++)
                {
                    for (int k=0;k<L;k++)
                        cout<<t[j][k];
                    cout<<" ";
                }

            cout<<sans<<endl;*/
            int co=0;
            for (int j=0;j<N;j++)
                for (int k=0;k<N;k++)
                  if (test[k])
            {
                bool go=true;
                for (int l=0;l<L;l++)
                    if (t[j][l]!=p[k][l]) {go=false; break;}
                if (!go) continue;
                test[k]=false;
                co++;
            }
            if (co==N)
                if (sans<ans) ans=sans;



        }





        if (ans!=L+1) fout<<"Case #"<<step+1<<": "<<ans<<endl;
        else
                      fout<<"Case #"<<step+1<<": NOT POSSIBLE"<<endl;
   }
   fin.close();
   fout.close();
}
