#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

struct edge
{
    int v,next;
}e[1005];
int head[3005];
int dp[1005];
int dp2[1005];
int ecnt;
void add_edge(int u,int v) {
    e[ecnt].v = v;
    e[ecnt].next = head[u];
    head[u] = ecnt;
    ecnt++;
}
int dfs2(int x,int fa) {
    if (dp2[x] != -1) {
        return dp2[x];
    }
    int to = 1;
    for (int i=head[x];i!=-1;i=e[i].next) {
        int v = e[i].v;
        if (fa == v) continue;
        to += dfs2(v, x);
    }
    return dp2[x] = to;
}
int dfs(int x,int fa) {
    if (dp[x] != -1) {
        return dp[x];
    }
    int tot = 0;
    int ma = -1, ma1 = -1;
    for (int i=head[x];i!=-1;i=e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        int k = dfs(v, x);
        int tmp = dp2[v] - k;
        if (tmp>ma) {
            ma1 = ma;
            ma = tmp;
        } else if (tmp > ma1) {
            ma1 = tmp;
        }
    }
    //dp2[x] - 1 - 不要删的点(dp2[x1]+dp2[x2]-dp1[x1]-dp1[x2])
    //for (int i=head[x];i!=-1;i=e[i].next)
    
    dp[x] = dp2[x] - 1;
    if (ma1 != -1) {
        dp[x] = min(dp[x], dp2[x] - 1 - (ma1+ma));
    }
    return dp[x];
}
int main() {
    freopen("B.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++)
    {
        ecnt=0;
        memset(head,-1,sizeof(head));
        int n;
        scanf("%d",&n);
        for (int i=0;i<n-1;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            add_edge(x,y);
            add_edge(y,x);
        }
        int mi = 200000;
        for (int i=1;i<=n;i++) {
            memset(dp, -1, sizeof(dp));
            memset(dp2, -1, sizeof(dp2));
            dfs2(i, -1);
//            if (dfs(i, -1) < mi) {
//                puts("#######");
//                printf("%d\n",i);
//                for (int j=1;j<=n;j++) {
//                    printf("%d\n",dp[j]);
//                }
//            }
            mi = min(mi, dfs(i, -1));
        }
        printf("Case #%d: %d\n", cas, mi);
    }
}