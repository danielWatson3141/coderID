/*
 *Author:       Zhaofa Fang
 *Created time: 2014-04-26-09.45 Saturday
 */
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
#define DEBUG(x) cout<< #x << ':' << x << endl
#define FOR(i,s,t) for(int i = (s);i <= (t);i++)
#define FORD(i,s,t) for(int i = (s);i >= (t);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=(n-1);i>=0;i--)
#define PII pair<int,int>
#define PB push_back
#define ft first
#define sd second
#define lowbit(x) (x&(-x))
#define INF (1<<30)
#define eps (1e-8)

const int maxn = 1011;
int N;
vector<int> vec[maxn],dag[maxn];
int ans;
int tot;
int dp[maxn],cnt[maxn];
void init(){
    REP(i,maxn)vec[i].clear();
}

void dfs(int u,int fa){
    int sz = vec[u].size();
    REP(i,sz){
        int v = vec[u][i];
        if(v != fa){
            dag[u].PB(v);
            dfs(v,u);
        }
    }
}
void count(int u){
    int sz = dag[u].size();
    cnt[u] = 1;
    if(sz == 0)return;
    REP(i,sz){
        int v = dag[u][i];
        count(v);
        cnt[u] += cnt[v];
    }
    return ;
}
int func(int u){
    if(dp[u]!=-1)return dp[u];
    int sz = dag[u].size();
    if(sz == 0)return dp[u] = 0;
    if(sz == 1){
        return dp[u] = cnt[u] - 1;
    }
    int sum = 0;
    int mi1 = INF, mi2 = INF;
    REP(i,sz){
        int v = dag[u][i];
        sum += func(v);
        if(mi1 > cnt[v] - func(v)){
            mi1 = cnt[v] - func(v);
        }else if(mi2 > cnt[v] - func(v)){
            mi2 = cnt[v] - func(v);
        }
    }
    return dp[u] = sum + mi1 + mi2;

}
void solve(){
    ans = INF;
    FOR(i,1,N){
        FOR(j,1,N)dag[j].clear();
        dfs(i,-1);
        count(i);
        memset(dp,-1,sizeof(dp));
        func(i);
        ans = min(ans,dp[i]);
    }
    printf("%d\n",ans);
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin>>T;
    FOR(cas,1,T){
        printf("Case #%d: ",cas);
        cin>>N;//DEBUG(N);
        init();
        REP(i,N-1){
            int x,y;
            cin>>x>>y;
            vec[x].PB(y);
            vec[y].PB(x);
        }
        solve();
    }
    return 0;
}
