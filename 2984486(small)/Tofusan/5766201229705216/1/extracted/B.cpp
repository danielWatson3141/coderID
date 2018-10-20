#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int n;
int t;
int st,ed;
int dp[1001][3];
int col[1001];
int rnd;
int ans;
vector<int> adj[1001];
void dfs(int a)
{
int ch=0;
int alldpz=0;
int maxminus1=0,maxminus2=0;
int del;
maxminus1=maxminus1-999999;
maxminus2=maxminus2-999999;
 col[a]=rnd;
 //printf("in %d\n",a);
 for(int i=0;i<adj[a].size();i++)
 {
  if(col[adj[a][i]]!=rnd)
  {
  dfs(adj[a][i]);
  ch++;
  alldpz=alldpz+dp[adj[a][i]][0];
  del=dp[adj[a][i]][0]-dp[adj[a][i]][1];
  if(del>maxminus1){maxminus2=maxminus1;maxminus1=del;}
  else if(del>maxminus2){maxminus2=del;}
  }
  //dp 1 = kep 0 = del
  //all dp 0
  //all dp 0 - (2 dp 0 - dp 1) = max dp 0 - dp 1
  //all min dp 0 , dp 1
 }
 if(ch==0){dp[a][0]=1;dp[a][1]=0;/*printf(">> %d\n",a);*/}
 else
 {
  dp[a][0]=alldpz+1;
   //printf("%d : alldel = %d,minus = %d, ch = %d\n",a,alldpz,maxminus1+maxminus2,ch);
  dp[a][1]=alldpz;
  if(ch>=2&&maxminus1+maxminus2>0)
  {
   dp[a][1]=dp[a][1]-maxminus1-maxminus2;
  }
 }
}
main()
{
 freopen("B-large.in","r",stdin);
 freopen("B-large.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
   adj[i].clear();
  }
  for(int i=1;i<n;i++)
  {
   scanf("%d%d",&st,&ed);
   adj[st].push_back(ed);
   adj[ed].push_back(st);
  }
  ans=99999;
  for(int i=1;i<=n;i++)
  {
   rnd++;
   for(int j=1;j<=n;j++)
   {
    dp[j][0]=0;
    dp[j][1]=0;
   }
   dfs(i);
   if(dp[i][0]<ans){ans=dp[i][0];}
   if(dp[i][1]<ans){ans=dp[i][1];}
  }
  printf("Case #%d: %d\n",tests,ans);
 }
 
 return 0;
}
