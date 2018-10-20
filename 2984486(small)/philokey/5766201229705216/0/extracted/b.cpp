#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1005;
vector<int> tree[MAXN];

int cnt[MAXN];
void init(int n) {
    for (int i = 0; i <= n; ++i)
        tree[i].clear();
}
int dfs(int u,int pre) {
    cnt[u] = tree[u].size()-1;
    for (int i = 0; i < tree[u].size(); ++i) {
        if (tree[u][i] == pre) continue;
        cnt[u] += dfs(tree[u][i],u);
    }
    return cnt[u];
}
void solve(int u,int pre,int &sum) {
    bool isroot = (pre==-1);
    if (tree[u].size()+isroot==2) {
        sum+=cnt[u];
        return ;
    }
    int fir,sec,x,y;
    int n = tree[u].size();
    fir = sec = -1;
    if (n+isroot>2) {
        for (int i = 0; i < n; ++i) {
            int v = tree[u][i];
            if (v == pre) continue;
            if (fir<cnt[v]) {
                sec = fir;
                fir = cnt[v];
                y = x;
                x = v;
            } else if (sec < cnt[v]) {
                if (sec>0)
                sum += sec;
                sec = cnt[v];
                y = v;
            }
        }
        solve(x,u,sum);
        solve(y,u,sum);
    }
}
int main()
{
    freopen("/home/qitaishui/practice/retired/in.txt","r",stdin);
    freopen("/home/qitaishui/practice/retired/out.txt","w",stdout);
    int cas;
    int u,v;
    int n;
    scanf("%d",&cas);
    for (int ca = 1; ca<=cas; ++ca) {
        scanf("%d",&n);
        init(n);
        for (int i = 1; i < n; ++i) {
            scanf("%d%d",&u,&v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int ans,tmp;
        ans = n;
        for (int i = 1; i <= n; ++i) {
            memset(cnt,0,sizeof(cnt));
            dfs(i,-1);
            cnt[i]++;
            tmp = 0;
            solve(i,-1,tmp);
            ans = min(ans,tmp);
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
