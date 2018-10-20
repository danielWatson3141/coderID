#include <iostream>   //我是沙茶....今天又写搓了。。
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <utility>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define abs(x) ((x)>0?(x):(-(x)))
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define FORD(i,a,b) for(int i = (a);i>=(b);i--)
#define REP(i,n) for(int i = 0;i<(n);i++)
#define rst(x,k) memset(x,k,sizeof(x))
#define lowbit(x) ((x)&(-(x)))
#define h(x) (1<<(x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define eps 1e-10
#define INF 2100000000
#define maxn 1100
#define mod 1000000007LL
#define Pi acos(-1.0)
#define link fjksldfjaslkdfjas
#define y1 fksjdlf
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
struct node{
    int t,nxt;
}edge[maxn << 1];
int headline[maxn] , E;
vector<P> aa[maxn];
int s[maxn];
inline void add(int f,int t){
    edge[E].t = t;
    edge[E].nxt = headline[f];
    headline[f] = E++;
}
int n,iCase;
int dfs(int u,int fa){
    //printf("u is %d\n",u);
    s[u] = 1;
    int ans = 0;
    int son = 0;
    for(int i = headline[u];~i;i = edge[i].nxt){
        int v = edge[i].t;
        if(v != fa){
            son++;
            int tt = dfs(v,u);
            s[u] += s[v];
            aa[u].push_back(P(tt-s[v] , v));
            //ans += tt;
        }
    }
    //printf("aa%d  is  %d\n",u,aa[u].size());
    //if(aa[u].size() <= 1)return s[u] - 1;
    //sort(aa[u].begin(),aa[u].end());
    //int ss = aa[u].size();
    //REP(i,ss-2) ans += aa[u][i];
    if(son < 2)return s[u] - 1;
    int ss = aa[u].size();
    sort(aa[u].begin(),aa[u].end());
    REP(i,2){
        int tt = aa[u][i].first;
        int v = aa[u][i].second;
        ans += tt + s[v];
    }
    FOR(i,2,ss-1){
        int v = aa[u][i].second;
        ans += s[v];
    }
    return ans;
}
void solve(void){
    scanf("%d",&n);
    rst(headline,-1); E = 0;
    FOR(i,1,n-1){
        int a,b; scanf("%d%d",&a,&b);
        add(a,b); add(b,a);
    }
    int ans = n-1;
    FOR(i,1,n){
        FOR(j,1,n)aa[j].clear();
        int tt = dfs(i,-1);
        if(tt < ans)ans = tt;
    }
    printf("Case #%d: %d\n",++iCase,ans);
}
int main(void){
    //freopen("B-small-attempt2.in","r",stdin);
    //freopen("out.out","w",stdout);
    iCase = 0;
    int casenum; scanf("%d",&casenum);
    while(casenum--) solve();
    return 0;
}
