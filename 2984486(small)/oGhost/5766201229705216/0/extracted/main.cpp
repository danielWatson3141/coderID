#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define inf 1000000


struct data{
    int u,v,w,n;
};

data e[11111];
int nex[11111],top;
int s[11111],f[11111],d[11111];


void push(int u,int v)
{
    e[++top].u=u; e[top].v=v; e[top].n=nex[u]; nex[u]=top;
}

void dfs(int u,int pre){

    int ma1=-inf, ma2=-inf;

    s[u]=1;

    for(int i=nex[u];i;i=e[i].n)
    if(e[i].v!=pre)
    {
        dfs(e[i].v,u);
        s[u]+=s[e[i].v];
    }

    for(int i=nex[u];i;i=e[i].n)
    if(e[i].v!=pre)
    {
        int v=e[i].v;
        if(f[v]>ma1)
            ma2=ma1,ma1=f[v];
        else if(f[v]>ma2)
            ma2=f[v];
    }

    if(ma1!=-inf && ma2!=-inf)
    {
        f[u]=1+ma1+ma2;
    }
    else
        f[u]=1;
    //printf("%d:%d\n",u,f[u]);
}


int main()
{
    freopen("b1.in","r",stdin);
    freopen("b1.out","w",stdout);


    int cas;
    scanf("%d",&cas);
    int tt=0;
    int n,x,y;

    while(cas--)
    {
        tt++;
        scanf("%d",&n);

        memset(nex,0,sizeof(nex));
        memset(d,0,sizeof(d));

        top=0;

        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            push(x,y);
            push(y,x);
            d[x]++;d[y]++;
        }

        int ans=-inf;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                f[j]=inf,s[j]=0;

            dfs(i,0);
            //printf("%d!!!!!!!\n",f[i]);
            if(f[i]>ans)
                ans=f[i];
            //puts("~~~");
        }

        printf("Case #%d: ",tt);
        printf("%d\n",n-ans);
    }
    return 0;
}
