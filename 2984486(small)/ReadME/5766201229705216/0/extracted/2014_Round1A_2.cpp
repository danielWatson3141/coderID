#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define maxn 1005

struct Edge
{
    int y, next;
}g[maxn*2];

int fst[maxn], cnt0;
int n;
int son[maxn];
int dp[maxn][2];

int getint()
{
    int d = 0, flag = 0; char ch = ' ';
    while (!isdigit(ch=getchar()))
        if (ch == '-') break;

    if (ch == -1) flag = 1;
        else d = ch - 48;

    while (isdigit(ch=getchar())) d = d * 10 + ch - 48;
    if (flag) return -d;
        else return d;
}
void edge(int x, int y)
{
    cnt0++;
    g[cnt0].y = y; g[cnt0].next = fst[x]; fst[x] = cnt0;
}
void dfs(int pa, int idx)
{
    int max1, max2, p1, p2, yy;

    max1 = 0; max2 = 0;
    for (int y = fst[idx]; y != -1; y = g[y].next)
    {
        yy = g[y].y;
        if (yy == pa) continue;

        dfs(idx, yy);
        if (son[yy]+1 > max1)
        {
            max2 = max1;
            p2 = p1;
            max1 = son[yy] + 1;
            p1 = yy;
        }else if (son[yy]+1 > max2)
        {
            max2 = son[yy] + 1;
            p2 = yy;
        }
        son[idx] += son[yy] + 1;
    }

    if (max1 == 0)
    {
        dp[idx][1] = 0;
    }else if (max2 == 0)
    {
        dp[idx][1] = dp[p1][0];
    }else
    {
        dp[idx][1] = dp[p1][1] + dp[p2][1] + son[idx]-max1-max2;
    }

    dp[idx][0] = son[idx] + 1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int Test, x, y, ans;
    Test = getint();
    for (int tt = 1; tt <= Test; tt++)
    {
        printf("Case #%d: ", tt);

        n = getint();
        memset(fst, -1, sizeof(fst));
        cnt0 = 0;
        for (int i = 0; i < n-1; i++)
        {
            x = getint()-1; y = getint()-1;
            edge(x, y);
            edge(y, x);
        }

        ans = n;
        for (int i = 0; i < n; i++)
        {
            memset(son, 0, sizeof(son));
            memset(dp, 0, sizeof(dp));
            dfs(-1, i);
            ans = min(ans, min(dp[i][1],dp[i][0]));
        }
        printf("%d\n", ans);
    }

    return 0;
}
