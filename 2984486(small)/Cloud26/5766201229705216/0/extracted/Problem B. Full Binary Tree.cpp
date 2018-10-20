#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;


typedef long long LL;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define lson (pos << 1)
#define rson (pos << 1 | 1)

template<class T> void checkMax(T &a, T b){a = max(a, b);}
template<class T> void checkMin(T &a, T b){a = min(a, b);}
const int N = 1005;
int n, addCost[N], delCost[N], diff[N], vis[N];
vector<int> tree[N];
void dfs(int root, int fa)
{
    int i, sum = 0;
    for(i = 0; i < tree[root].size(); i++)
    {
        if(tree[root][i] != fa)
        {
            dfs(tree[root][i], root);
            sum += delCost[tree[root][i]];
        }
    }
    addCost[root] = sum;
    delCost[root] = sum + 1;
    pair<int, int> mintwo = make_pair(INF, INF);
    for(i = 0; i < tree[root].size(); i++)
    {
        if(tree[root][i] != fa)
        {
            if(diff[tree[root][i]] <= mintwo.first)
            {
                mintwo.second = mintwo.first;
                mintwo.first = diff[tree[root][i]];
            }
            else if(diff[tree[root][i]] <= mintwo.second)
            {
                mintwo.second = diff[tree[root][i]];
            }
        }
    }
    if(mintwo.first + mintwo.second < 0)
        addCost[root] = sum + mintwo.first + mintwo.second;
    diff[root] = addCost[root] - delCost[root];
}
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, cas = 1, i, j, a, b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            tree[i].clear();
        for(i = 1; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        int ans = INF;
        for(i = 1; i <= n; i++)
        {
            dfs(i, -1);
            checkMin(ans, addCost[i]);
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
