#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int k[50][50];
int kk[50][50];
int p[50];

bool yes(int pos,int tam)
{
    kk[pos][pos]=0;
    int hijos=0;
    for(int i=1;i<=n;i++)
    {
        if(pos==i)
            continue;
        if(kk[pos][i]==1)
        {
            kk[i][pos]=0;
            kk[pos][i]=0;
            hijos++;
            if(yes(i,tam+1)==false)
                return false;
        }
    }
    if(hijos==0 || hijos==2)
        return true;
    return false;
}

int checa()
{
    bool si=false;
    int res=0;
    for(int i=1;i<=n;i++)
        if(p[i]==1)
            res++;
    for(int i=1;i<=n;i++)
    {
        if(p[i]==1)
            continue;
        for(int x=1;x<=n;x++)
            for(int y=1;y<=n;y++)
            {
                if(x==y)
                {
                    kk[x][y]=1;
                    continue;
                }
                if(p[x]==0 && p[y]==0)
                    kk[x][y]=k[x][y];
                else
                    kk[x][y]=0;
            }
        for(int x=1;x<=n;x++)
            if(p[x]==1)
                kk[x][x]=0;
        if(yes(i,0))
        {
            int cosa=0;
            for(int x=1;x<=n;x++)
                for(int y=1;y<=n;y++)
                    cosa+=kk[x][y];
            if(cosa==0)
                si=true;
        }
    }
    if(si)
        return res;
    return 1<<30;
}

int fun(int pos)
{
    if(pos==n+1)
    {
        return checa();
    }
    int a=fun(pos+1);
    p[pos]=1;
    int b=fun(pos+1);
    p[pos]=0;
    return min(a,b);
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int I=1;I<=T;I++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                k[i][j]=0;
        for(int i=1;i<=n;i++)
            p[i]=0;
        int a,b;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            k[a][b]=1;
            k[b][a]=1;
        }
        int res=fun(1);
        cout<<"Case #"<<I<<": "<<res<<endl;
    }
    return 0;
}
