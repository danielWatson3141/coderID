#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<iostream>
#include<sstream>
#include<queue>
using namespace std;
#define ll long long
int T,cas=0,N,st[2005],e;
struct EG
{
    int v,nx;
}eg[2005];
void add(int u,int v)
{
    eg[e].v=v;eg[e].nx=st[u];st[u]=e++;
}
int dfs(int u,int fa)
{
    int ma=0,mama=0;
    int ct=0;
    for(int i=st[u];~i;i=eg[i].nx)
    {
        int v=eg[i].v;
        if(v!=fa)
        {
            ct++;
            int sh=dfs(v,u);
            if(sh>=ma)
            {
                mama=ma;
                ma=sh;
            }
            else if(sh>=mama)
            {
                mama=sh;
            }
        }
    }
    //printf("u %d %d %d %d\n",u,ct,ma,mama);
    if(ct<2)return 1;
    return ma+mama+1;
}
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        e=0;
        memset(st,-1,sizeof(st));
        int u,v;
        for(int i=1;i<N;i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        int ret=0;
        for(int i=1;i<=N;i++)
        {
            //if(i!=2)continue;
            int ans=dfs(i,-1);
            ret=max(ret,ans);
            //printf("%d:%d\n",i,ans);
        }
        printf("Case #%d: %d\n",++cas,N-ret);
    }
}
/*
3
3
2 1
1 3
7
4 5
4 2
1 2
3 1
6 4
3 7
4
1 2
2 3
3 4
*/
