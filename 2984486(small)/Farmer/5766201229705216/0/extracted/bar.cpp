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

const int maxn = 17;
int N;
vector<int> vec[maxn],dag[maxn];
int ans;
bool vist[maxn];
int tot;
void init(){
    REP(i,maxn)vec[i].clear();
}
void dfs2(int u,int fa){
    tot++;//DEBUG(u);
    int sz = vec[u].size();
    REP(i,sz){
        int v = vec[u][i];
        if(v != fa){
            dfs2(v,u);
        }
    }
}
void dfs(int u,int fa){
    if(vist[u]){
        dfs2(u,fa);
        return;
    }
    int sz = vec[u].size();
    REP(i,sz){
        int v = vec[u][i];
        if(v != fa){
            if(!vist[v])dag[u].PB(v);
            dfs(v,u);
        }
    }
}
bool check(){
    FOR(i,1,N){
        if(dag[i].size()!=0&&dag[i].size()!=2)return false;
    }
    return true;
}

void solve(){
    ans = INF;
    FOR(i,1,N){//DEBUG(i);
        REP(j,(1<<N)){
            tot = 0;

            REP(k,maxn)dag[k].clear();
            memset(vist,0,sizeof(vist));
            REP(k,N){
                if(j&(1<<k)){
                    vist[k+1] = 1;//DEBUG(k+1);
                }
            }
            dfs(i,-1);//puts("***");
            if(check()){//DEBUG(tot);
                ans = min(ans,tot);
            }
//            puts("*********************");
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("B-small-attempt1.in","r",stdin);
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
