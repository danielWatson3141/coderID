#include <cstdio>
#include <vector>
using namespace std;

const int N = 1050;

vector<int> E[N];

int D[N];

void DFS(int x, int p = -1)
{
    D[x] = 1;
    int mx1 = -1, mx2 = -1;
    for (int i = 0; i < E[x].size(); i++)
    {
        int y = E[x][i];
        if (y == p)
            continue;
        DFS(y, x);
        if (mx1 < D[y])
            mx2 = mx1, mx1 = D[y];
        else if (D[y] <= mx1 && mx2 < D[y])
            mx2 = D[y];
    }
    if (mx1 != -1 && mx2 != -1)
        D[x] = max(D[x], mx1 + mx2 + 1);
}

void solve(int cs)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        E[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        DFS(i);
        ans = max(ans, D[i]);
    }
    printf("Case #%d: %d\n", cs, n - ans);
    fflush(stdout);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i + 1);
}
