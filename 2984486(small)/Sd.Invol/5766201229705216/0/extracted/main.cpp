#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;

#define N 1005
int n , pre[N] , mcnt , ca;
struct edge {
    int x , next;
}e[N << 1];
int deg[N] , sum[N] , ret;
int f[N];
void dfs(int x , int fa) {
    deg[x] = 0 , sum[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            ++ deg[x];
            dfs(y , x);
            sum[x] += sum[y];
        }
    }
}
void DFS(int x , int fa) {
    if (deg[x] == 0) {
        f[x] = 0;
        return;
    }
    if (deg[x] == 1) {
        f[x] = sum[x] - 1;
        return;
    }
    int tot = 0;
    vector<int> c;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            DFS(y , x);
            c.push_back(f[y] - sum[y]);
            tot += sum[y];
        }
    }
    sort(c.begin() , c.end());
    tot += c[0] , tot += c[1];
    f[x] = tot;
}

void work()
{
    printf("Case #%d: " , ++ ca);

    int i , j , k , x , y;
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
    }
    int ans = n - 1;
    for (k = 1 ; k <= n ; ++ k) {
        memset(f , 0 , sizeof(f));
        dfs(k , 0);
        DFS(k , 0);
        ans = min(ans , f[k]);
    }
    printf("%d\n" , ans);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    freopen("2.txt" , "w" , stdout);

    int _ ; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
