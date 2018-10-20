#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

#define pb push_back
#define SZ 1007
#define INF (1<<20)
using namespace std;

vector<int>edge[SZ+7];
int tot[SZ+7];
int vis[SZ+7] , True , n;
int Par[SZ+7];

void dfs(int u,int p)
{
    vis[u] = True;
    tot[u] = 1;
    Par[u] = p;
    for(int i=0;i<edge[u].size();i++) {
        int v = edge[u][i];
        if(v!=p && vis[v]!=True ) {
            dfs(v,u);
            tot[u] += tot[v];
        }
    }
}


int dp[SZ+7][SZ+7][3];
int Color[SZ+7][SZ+7][3];

int back(int pos,int i,int tk)
{
    if(Color[pos][i][tk] == True) {
        return dp[pos][i][tk];
    }
    Color[pos][i][tk] = True; dp[pos][i][tk] = INF;
    if(i==0) {
        if(edge[pos].size()==0) {
            dp[pos][i][tk] = 0;
            return 0;
        }
        dp[pos][i][tk] = back(pos,i+1,0);
    }
    else {
        if(i==edge[pos].size()) {
            int v = edge[pos][i-1];
            if(tk==1) {
                if(v==Par[pos]) {
                    dp[pos][i][tk] = INF;
                }
                else dp[pos][i][tk] = back(v,0,0);
            }
            else {
                if(v==Par[pos]) {

                    dp[pos][i][tk] = 0;
                }
                else {
                    dp[pos][i][tk] = tot[v];
                }
            }
        }
        else {
            if(tk<=1 ) {
                int v = edge[pos][i-1];
                if(v==Par[pos]) {
                    dp[pos][i][tk] = back(pos,i+1,tk);
                }
                else {
                    dp[pos][i][tk] = back(pos,i+1,tk+1) + back(v,0,0);
                    dp[pos][i][tk] = min( dp[pos][i][tk] , back(pos,i+1,tk) + tot[v]);
                }
            }
            else {
                int v = edge[pos][i-1];
                if(v==Par[pos]) {
                    dp[pos][i][tk] = back(pos,i+1,tk);
                }
                else {
                    dp[pos][i][tk] = back(pos,i+1,tk) + tot[v];
                }
            }

        }
    }

    return dp[pos][i][tk];

}


int main()
{
    freopen("B.in","rt",stdin);
    freopen("B.out","wt",stdout);
    int tst,cas;
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++) {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)   edge[i].clear();
        for(int i=0;i<n-1;i++) {
            int u , v;
            scanf("%d%d",&u,&v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        int mn = INF;
        for(int i=1;i<=n;i++) {
            True++;
            dfs(i,-1);
            True++;
     //       printf("%d %d\n",i,back(i,0,0));
            mn = min(mn, back(i,0,0));
        }
        printf("Case #%d: %d\n",cas,mn);

    }

    return 0;
}
