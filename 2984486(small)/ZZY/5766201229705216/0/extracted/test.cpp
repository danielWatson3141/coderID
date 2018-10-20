#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map> 
#define MAXN 1005
using namespace std;
struct Edge
{
      int u,v,next;
}edge[MAXN<<1]; 
int _next[MAXN],num;
int dp[MAXN][3]; //0度为0,两者最小值，2度为2 
void addedge(int u,int v)
{
      edge[++num].next=_next[u],_next[u]=num;
      edge[num].u=u,edge[num].v=v;
}
void dfs(int u,int father)
{
      int v,k,d,i,j,num=0,sum,son[MAXN];
      dp[u][0]=0;  
      for (k=_next[u];k;k=edge[k].next)
      {
             v=edge[k].v;
             if (v==father) continue;
             dfs(v,u); 
             son[++num]=v;  
             dp[u][0]+=dp[v][0]+1;
      } 
      for (i=1;i<num;i++)
         for (j=i+1;j<=num;j++)
         {
              sum=0;
              for (k=1;k<=num;k++)
                 if (k!=i && k!=j) sum+=dp[son[k]][0]+1;
              sum+=dp[son[i]][1]+dp[son[j]][1];
              dp[u][2]=min(dp[u][2],sum);
         }
      dp[u][1]=min(dp[u][0],dp[u][2]);
}
int count(int n)
{
      int i,ans=n+1; 
      for (i=1;i<=n;i++)
      { 
             memset(dp,0x3f,sizeof(dp));
             dfs(i,0); 
             ans=min(ans,dp[i][1]);
      }
      return ans;
}
int main()
{
      int T,cases,N,i,u,v;
      freopen("B-small-attempt2.in","r",stdin);
      freopen("output.txt","w",stdout);
      scanf("%d",&T);
      for (cases=1;cases<=T;cases++)
      {
             scanf("%d",&N);
             memset(_next,0,sizeof(_next));
             num=0;
             for (i=1;i<N;i++)
             {
                    scanf("%d%d",&u,&v);
                    addedge(u,v),addedge(v,u);
             }
             printf("Case #%d: %d\n",cases,count(N)); 
      }
      return 0;
}
