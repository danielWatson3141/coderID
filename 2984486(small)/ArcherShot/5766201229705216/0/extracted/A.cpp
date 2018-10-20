#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;
template<typename X> inline bool minimize(X&p,X q){if(p<=q)return 0;p=q;return 1;}
template<typename X> inline bool maximize(X&p,X q){if(p>=q)return 0;p=q;return 1;}
const int MAXN = 1005 , MAXE = 2005;
struct Arclist{
    struct Edge{int v,next;}E[MAXE];
    int head[MAXN],cur;
    void init(int n=MAXN){fill_n(head,n,-1);cur=0;}
    void add(int u,int v){
        E[cur].v=v;E[cur].next=head[u];head[u]=cur++;
    }
    int dfs(int u,int pre=-1){
        int m1 = 0 , m2 = 0;
        for(int p=head[u];~p;p=E[p].next){
            int v = E[p].v;
            if(v==pre)continue;
            int w = dfs(v,u);
            if(w>m1)swap(w,m1);
            if(w>m2)swap(w,m2);
        }
        if(m1==0||m2==0)return 1;
        return m1+m2+1;
    }
}G;
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T,N;
    scanf("%d",&T);
    for(int t=1;t<=T;++t){
        scanf("%d",&N);
        G.init();
        for(int i=1,u,v;i<N;++i){
            scanf("%d%d",&u,&v);
            G.add(u,v);G.add(v,u);
        }
        int ans = 0;
        for(int r=1;r<=N;++r)
            maximize(ans,G.dfs(r));
        printf("Case #%d: %d\n",t,N-ans);
    }
    return 0;
}
