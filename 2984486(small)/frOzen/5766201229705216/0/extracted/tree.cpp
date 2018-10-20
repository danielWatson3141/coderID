#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <memory>
using namespace std;




int a[1500],b[1500][1500],s[1500],sss;
bool p[1500];
int dfs(int x)
{
    int co=1;

    for (int i=1;i<=a[x];i++)
    if (p[ b[x][i] ]) {
        p[ b[x][i] ]=false;
        //cout<<"deep into"<<b[x][i]<<endl;
        co+=dfs(b[x][i]);
    }
    s[x]=co;
    return co;
}

int dfsans(int x)
{
    int co=0;
   // cout<<"here : "<<x<<endl;
    p[x]=false;
    for (int i=1;i<=a[x];i++)
        if (p[ b[x][i] ]) {co++;}

  //  cout<<"cout into"<<co<<endl;
    if (co==0) return 0;

    if (co==1) {
        for (int i=1;i<=a[x];i++)
        if (p[ b[x][i] ]) return s[ b[x][i] ];
    }

    if (co==2) {
        int re=0;
        for (int i=1;i<=a[x];i++)
        if (p[ b[x][i] ]) re+=dfsans(b[x][i]);
        return re;

    };

    if (co>2)
    {
        int xx=0,sp=0;
        int k1=15000,k2=15000;
        for (int i=1;i<=a[x];i++)
            if (p[ b[x][i] ])
        {
            int y=dfsans(b[x][i]);
            xx+=y;
            sp++;
           // cout<<b[x][i]<<":"<<y<<" ";
            if (y<k1) { k1=y; k2=k1;}
            else if (y<k2) k2=y;
        }
      //  cout<<endl;

        //if (xx-(k1+k2)<0) { cout<<"fuck"<<x<<" "<<k2<<endl;}
        return xx-(k1+k2);
    }
    p[x]=true;
    return 0;
}
int main(int argc, const char * argv[])
{
   ifstream fin;
   ofstream fout;
   int t;
   fin.open("data.in",std::ofstream::in);
   fout.open("data.out",std::ofstream::out);

   fin>>t;
   for (int step=0;step<t;step++)
   {
      int N;
      int ans;
      sss=step;
      memset(a, 0, sizeof(a));
      memset(b, 0, sizeof(b));
      fin>>N;
      ans=N;
      int x,y;
      for (int i=0;i<N-1;i++)
      {
         fin>>x>>y;
         a[x]++;
         b[x][a[x]]=y;
         a[y]++;
         b[y][a[y]]=x;
       }
     /*& for (int i=0;i<N;i++)
       {
       for(int j=1;j<=a[i];j++)
        cout<<b[i][j]<<" ";
      cout<<endl;
       }*/
      for (int i=1;i<=N;i++)
      {
       // cout<<"root:"<<i<<endl;
        memset(s, 0, sizeof(s));
        for (int j=1;j<=N;j++)
            p[j]=true;


        s[i]=dfs(i);

        for (int j=1;j<=N;j++)
            p[j]=true;
        int xx=dfsans(i);

        //cout<<endl<<"ans:"<<xx<<endl;
        if (xx<ans) ans=xx;
      }
        fout<<"Case #"<<step+1<<": "<<ans<<endl;

   }
   fin.close();
   fout.close();
}
