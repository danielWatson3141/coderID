#include <iostream>
#include <fstream>

#define MAX 3000

int num[MAX], nxt[MAX], g[MAX], s[MAX], f[MAX];
int tt = 0;

void insert(int x, int y)
{
    ++tt; num[tt] = y; nxt[tt] = g[x]; g[x] = tt;
    ++tt; num[tt] = x; nxt[tt] = g[y]; g[y] = tt;
}

void dfs(int x, int fa)
{
    f[x] = 0; s[x] = 0;
    int h[3] = {0, -1, -1};
    int p = g[x];
    while (p != 0)
    {
        if (num[p] != fa)
        {
            dfs(num[p], x);
            if (h[2] != -1) h[2] += s[num[p]];
            if (h[1] != -1 && (h[2] == -1 || h[1] + f[num[p]] < h[2]))
                h[2] = h[1] + f[num[p]];
            if (h[1] != -1) h[1] += s[num[p]];
            if (h[1] == -1 || h[0] + f[num[p]] < h[1])
                h[1] = h[0] + f[num[p]];
            h[0] += s[num[p]];
        }
        p = nxt[p];
    }
    s[x] = h[0]+1;
    f[x] = h[0];
    if (h[2] != -1 && h[2] < f[x]) f[x] = h[2];
}

int main()
{
    std::ifstream infile("B-large.in");
    std::ofstream outfile("outputB");

    int t;
    infile >> t;
    for (int ca = 1; ca <= t; ++ca)
    {
        outfile << "Case #" << ca << ": ";
        int ans = -1, n;

        infile >> n;
        tt = 0;
        for (int i = 1; i <= n; ++i) g[i] = 0;
        
        for (int i = 1; i < n; ++i)
        {
            int x, y;
            infile >> x >> y;
            insert(x, y);
        }

        for (int root = 1; root <= n; ++root)
        {
            dfs(root, 0);
            if (ans == -1 || f[root] < ans)
                ans = f[root];
        }
        outfile << ans << std::endl;
    }
    return 0;
}
