/*
ID: amr.f.eldfrawy
LANG: C++
*/
#include <fstream>
#include <string>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#define INF 1000000
#define MOD  1000000007
#define MAX 100000
using namespace std;
int dp[1002],dp2[1001];
vector< vector<int> >G,G2;
long long COST;
int cost(int root)
{
    if(G[root].size()==0)
        return 1;
    if(dp2[root]!=-1)return dp2[root];
    int res =0;
    for (int i=0;i<G[root].size();i++)
        res +=cost(G[root][i]);

    return dp2[root]=res+1;
}
int solve(int root)
{
    //int ans = INF ;
    if(G[root].size()==1)
        return cost(G[root][0]);
    if(G[root].size()==0)
        return 0;
    if(dp[root]!=-1)return dp[root];
    int res=INF,COST=0;
    for (int i=0;i<G[root].size();i++)
        COST+=cost(G[root][i]);

     for (int i=0;i<G[root].size();i++)
     for (int j=i+1;j<G[root].size();j++)
       res = min(res , solve(G[root][i])+ solve(G[root][j])+COST-(cost(G[root][i])+cost(G[root][j])) );

    return dp[root]=res;
}
  bool vis[1002];
   int n , a , b ,c  ;
void BFS( int root)
{
    queue<int>q;
    q.push(root);

    memset(vis,false,sizeof vis);
    vis[root]=1;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int i=0; i<G2[top].size(); i++)
        {
            if(!vis[G2[top][i]])
            {
                vis[G2[top][i]]=1;
                G[top].push_back(G2[top][i]);
                q.push(G2[top][i]);
            }
        }

    }
     fill(&dp2[0],&dp2[n+1],-1);
    cost(root);

}
int main()
{
    freopen("S.in","r",stdin);
   freopen("out.txt","w",stdout);

    int g=1;
  //  memset(dp,-1,sizeof dp);
    int t ;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d",&n);
        G2.assign(n+1, vector<int>());
        for (int i=0; i<n-1; i++)
        {
            scanf("%d %d",&a,&b);
            G2[a].push_back(b);
            G2[b].push_back(a);

        }
        int ans = INF ;
        for (int i=1; i<=n; i++)
        {
            G.assign(n+1, vector<int>());
            BFS(i);
            fill(&dp[0],&dp[n+1],-1);

            ans = min ( ans , solve(i));


        }
        printf("Case #%d: %d",g++,ans);
        if(t>0)
            printf("\n");

    }

    return 0;

}
