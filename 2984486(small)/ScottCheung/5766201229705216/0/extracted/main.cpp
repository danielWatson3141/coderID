#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define NUM 1005

int T, N, ans, dd[NUM];
vector<int> a[NUM];
bool b[NUM], c[NUM];

void dfs2(int x)
{
    c[x] = true;
    for (int i = 0; i < a[x].size(); i++)
        if (!b[a[x][i]])
        {
            dd[x]++;
            if (!c[a[x][i]])
                dfs2(a[x][i]);
        }
}

void dfs(int d, int w)
{
    if (w >= ans)
        return;
    if (d > N)
    {
        bool ok = false;
        for (int r = 1; r <= N; r++)
            if (!b[r])
            {
                memset(c, false, sizeof(c));
                memset(dd, 0, sizeof(dd));
                dfs2(r);
                for (int i = 1; i <= N; i++)
                    dd[i]--;
                dd[r]++;
                bool ok2 = true;
                for (int i = 1; i <= N; i++)
                    if (!b[i] && (!c[i] || dd[i] != 0 && dd[i] != 2))
                    {
                        ok2 = false;
                        break;
                    }
                if (ok2)
                {
                    ok = true;
                    break;
                }
            }
        if (ok)
            ans = w;
        return;
    }
    b[d] = false;
    dfs(d + 1, w);
    b[d] = true;
    dfs(d + 1, w + 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int x = 1; x <= T; x++)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            a[i].clear();
        for (int i = 1; i < N; i++)
        {
            int X, Y;
            scanf("%d%d", &X, &Y);
            a[X].push_back(Y);
            a[Y].push_back(X);
        }
        memset(b, false, sizeof(b));
        ans = N;
        dfs(1, 0);
        printf("Case #%d: %d\n", x, ans);
    }
    return 0;
}
