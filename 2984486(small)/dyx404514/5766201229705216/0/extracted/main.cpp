#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define maxn 1010
using namespace std;
struct edge
{
    int to;
    int next;
}e[maxn<<1];
int box[maxn],cnt;
void init()
{
    cnt=0;
    memset(box,-1,sizeof(box));
}
void add(int from,int to)
{
    e[cnt].to=to;
    e[cnt].next=box[from];
    box[from]=cnt++;
}
int dp[maxn],chd[maxn];
void dfs(int now,int fa)
{
    chd[now]=1;
    int num=0;
    for(int t=box[now];t+1;t=e[t].next)
    {
        int v=e[t].to;
        if(v!=fa)
        {
            num++;
            dfs(v,now);
            chd[now]+=chd[v];
        }
    }
    if(num==0)
    dp[now]=0;
    else if(num==1)
    dp[now]=chd[now]-1;
    else
    {
        int ma1=0,ma2=0;
        for(int t=box[now];t+1;t=e[t].next)
        {
            int v=e[t].to;
            if(v!=fa)
            {
                if(chd[v]-dp[v]>ma1)
                {
                    ma2=ma1;
                    ma1=chd[v]-dp[v];
                }
                else if(chd[v]-dp[v]>ma2)
                {
                    ma2=chd[v]-dp[v];
                }
            }
        }
        dp[now]=chd[now]-ma1-ma2-1;
    }
}
int main()
{
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        int n,x,y;
        printf("Case #%d: ",++T);
        scanf("%d",&n);
        init();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        int ans=100000;
        for(int i=1;i<=n;i++)
        {
             memset(dp,0,sizeof(dp));
             dfs(i,0);
             if(ans>dp[i])
             ans=dp[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
