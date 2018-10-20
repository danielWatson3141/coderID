#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long

using namespace std;

const int nm=1002;

int n;vector<int> adj[nm];
int ncon[nm],xoa[nm],nchau[nm];
bool fr[nm];

void dfs(int i)
{
    int j,k;
    fr[i]=0;ncon[i]=xoa[i]=0;vector<int> con;
    nchau[i]=1;
    for(k=0;k<int(adj[i].size());++k)
    {
        j=adj[i][k];
        if (fr[j])
        {
            ncon[i]++;con.pb(j);
            dfs(j);
            nchau[i]+=nchau[j];
        }
    }
    if (ncon[i]==0) xoa[i]=0;
    else
    {
        if (ncon[i]==1) xoa[i]=nchau[con[0]];
        else
        {
            if (ncon[i]==2) xoa[i]=xoa[con[0]]+xoa[con[1]];
            else
            {
                int min1=1000000,min2=1000000;
                for(k=0;k<int(con.size());++k)
                {
                    j=con[k];
                    if (xoa[j]-nchau[j]<min1)
                    {
                        min2=min1;min1=xoa[j]-nchau[j];
                    }
                    else
                    {
                        if (xoa[j]-nchau[j]<min2)
                        {
                            min2=xoa[j]-nchau[j];
                        }
                    }
                }
                xoa[i]=nchau[i]-1+min1+min2;
            }
        }
    }
}

int main()
{
    freopen("b-small-attempt1.in","r",stdin);
    freopen("vd.out","w",stdout);
    int t,i,u,v,kq;
    scanf("%d",&t);
    for(int ti=1;ti<=t;++ti)
    {
        scanf("%d",&n);
        for(i=1;i<=n;++i) adj[i].clear();
        for(i=1;i<n;++i)
        {
            scanf("%d%d",&u,&v);adj[u].pb(v);adj[v].pb(u);
        }
        kq=n-1;
        for(i=1;i<=n;++i)
        {
            memset(xoa,0,sizeof(xoa));
            memset(ncon,0,sizeof(ncon));
            memset(fr,1,sizeof(fr));
            dfs(i);
            if (xoa[i]<kq) kq=xoa[i];
        }
        printf("Case #%d: %d\n",ti,kq);
    }
}
