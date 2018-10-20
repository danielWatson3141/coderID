#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
const int N=2010;
int dp[N],all[N];

struct edge
{
    int to;
    int nxt;
}e[N];
int head[N],en;
void addedge(int f,int t)
{
    e[en].to=t;
    e[en].nxt=head[f];
    head[f]=en++;
    e[en].to=f;
    e[en].nxt=head[t];
    head[t]=en++;
}
void dfs(int now,int pre)
{
    dp[now]=0;
    all[now]=1;
    int degree=0;
    int first=-1,second=-1;
    int vf=0,vs=0;
    for(int i=head[now];i;i=e[i].nxt)
    {
        if(e[i].to!=pre)
        {
            degree++;
            int t=e[i].to;
            dfs(t,now);
            all[now]+=all[t];
            if(all[t]-dp[t]>=vf)
            {
                vs=vf;
                second=first;
                vf=all[t]-dp[t];
                first=t;
            }
            else if(all[t]-dp[t]>=vs)
            {
                vs=all[t]-dp[t];
                second=t;
            }
        }
    }
    if(degree==1)
    {
        dp[now]=all[now]-1;
    }
    else
    {
        dp[now]=all[now]-1-vf-vs;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int ti=1;ti<=t;ti++)
    {
        scanf("%d",&n);
        en=1;
        for(int i=0;i<n;i++)head[i]=0;

        for(int i=0;i<n-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--,b--;
            addedge(a,b);
        }
        int ans=10000000;
        for(int i=0;i<n;i++)
        {
            dfs(i,-1);
//            cout<<i<<' '<<dp[i]<<endl;
            ans=min(ans,dp[i]);
        }
        printf("Case #%d: %d\n",ti,ans);
    }
    return 0;
}
