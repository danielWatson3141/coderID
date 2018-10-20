#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int t,n,hd[1000],el,ans;

struct E
{
    int v,p;
}e[2000];

void adde(int u,int v)
{
    e[el].v=v; e[el].p=hd[u]; hd[u]=el++;
    e[el].v=u; e[el].p=hd[v]; hd[v]=el++;
}

void init()
{
    int i,j,k,l;
    memset(hd,-1,sizeof hd);
    el=0;
    ans=n;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        adde(j-1,k-1);
    }
}

void calc(int u,int f,int &d,int &s)
{
    int i,j,k,l,mx1=-1,mx2=-1;
    int v,vd,vs;
    for(l=hd[u],k=0,s=1;l!=-1;l=e[l].p)
    {
        v=e[l].v;
        if(v==f)
            continue;
        k++;
        calc(v,u,vd,vs);
        j=vs-vd;
        if(j>mx1)
        {
            mx2=mx1;
            mx1=j;
        }
        else if(j>mx2)
            mx2=j;
        s+=vs;
    }
    if(k==0)
        d=0;
    else if(k==1)
        d=s-1;
    else
        d=s-1-mx1-mx2;
}

void solve()
{
    int i,j,k,l;
    for(i=0;i<n;i++)
    {
        calc(i,-1,j,k);
        ans=min(ans,j);
    }
    printf("Case #%d: %d\n",++t,ans);
}

int main()
{
    scanf("%*d");
    while(~scanf("%d",&n))
    {
        init();
        solve();
    }
    return 0;
}
