#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

#define MAXN 2000
vi adj[MAXN];
vi children[MAXN];
bool visited[MAXN];
int sz[MAXN];
int mem[MAXN];

void dfs(int cur)
{
    visited[cur] = true;
    sz[cur] = 1;

    for (int i = 0; i < size(adj[cur]); i++)
    {
        int nxt = adj[cur][i];
        if (!visited[nxt])
        {
            children[cur].push_back(nxt);
            dfs(nxt);
            sz[cur] += sz[nxt];
        }
    }
}

int count(int cur)
{
    if (mem[cur] != -1)
        return mem[cur];

    int all = 0;
    for (int i = 0; i < size(children[cur]); i++)
        all += sz[children[cur][i]];

    int mn = all;
    for (int i = 0; i < size(children[cur]); i++)
    {
        for (int j = i + 1; j < size(children[cur]); j++)
        {
            int a = children[cur][i],
                b = children[cur][j];

            mn = min(mn, all - sz[a] - sz[b] + count(a) + count(b));
        }
    }

    // printf("%d %d\n", cur + 1, mn);

    return mem[cur] = mn;
}

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        printf("Case #%d: ", t+1);

        int n;
        scanf("%d\n", &n);

        for (int i = 0; i < n; i++)
            adj[i].clear();

        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            scanf("%d %d\n", &a, &b);
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int mn = -1;
        for (int root = 0; root < n; root++)
        {
            for (int i = 0; i < n; i++)
                children[i].clear();

            memset(visited, 0, n);
            dfs(root);

            // printf("\n");
            // printf("root is %d\n", root + 1);

            // for (int i = 0; i < n; i++)
            // {
            //     printf("%d:", i + 1);
            //     for (int j = 0; j < size(children[i]); j++)
            //     {
            //         printf(" %d", children[i][j] + 1);
            //     }

            //     printf("\n");
            // }

            memset(mem, -1, n << 2);
            int cnt = count(root);
            if (mn == -1 || cnt < mn)
            {
                mn = cnt;
            }
        }

        printf("%d\n", mn);
    }

    return 0;
}

