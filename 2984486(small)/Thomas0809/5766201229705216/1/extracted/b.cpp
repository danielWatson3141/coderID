#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T, n, fa[1111], num, cur[1111], sz[1111], q[1111], l, r, ans;

struct edge { int p, pre; } g[11111];

int calc(int a, int b)
{
    int ans = 1;
    if (a > 0 && b > 0)
        return a + b + 1;
    return 1;
    /*if (a + b == 1) return 1;
    for (int i = 1; ; i *= 2)
    {
        if (a >= i && b >= i)
        {
            a -= i; b -= i; ans += 2 * i; continue;
        }
        if (a < i && b < i)
        {
            if (max(a, b) > 1)
                ans += max(a, b);
            break;
        }
        if (a < i)
        {
            if (a % 2 == 1) a -= 1;
            ans += i + a;
            break;
        }
        if (b < i)
        {
            if (b % 2 == 1) b -= 1;
            ans += i + b;
            break;
        }
    }
    return ans;*/
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++)
    {
        scanf("%d", &n);
        num = 0;
        memset(cur, -1, sizeof cur);
        for (int i = 1, u, v; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            g[num].p = u; g[num].pre = cur[v]; cur[v] = num++;
            g[num].p = v; g[num].pre = cur[u]; cur[u] = num++;
        }
        ans = 0;
        for (int root = 1; root <= n; root++)
        {
            q[l = r = 0] = root; fa[root] = 0;
            while (l <= r)
            {
                for (int i = cur[q[l]]; i != -1; i = g[i].pre)
                    if (g[i].p != fa[q[l]])
                        fa[q[++r] = g[i].p] = q[l];
                l++;
            }
            for (; r >= 0; r--)
            {
                int s1 = 0, s2 = 0;
                for (int i = cur[q[r]]; i != -1; i = g[i].pre)
                    if (g[i].p != fa[q[r]])
                    {
                        if (sz[g[i].p] > s2)
                            s2 = sz[g[i].p];
                        if (sz[g[i].p] > s1)
                            s2 = s1, s1 = sz[g[i].p];
                    }
                sz[q[r]] = calc(s1, s2);
            }
            //printf("%d %d\n", root, sz[root]);
            if (sz[root] > ans)
                ans = sz[root];
        }
        printf("Case #%d: %d\n", tt + 1, n - ans);
    }
    return 0;
}
