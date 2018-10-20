#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#define     M 300
using namespace std;

const int inf = 1000000;
int T, n, l, cnt[2][M];
int visit[M];
vector <string> v[2];

inline void fff(int x)
{
    for (int i = 0; i < n; i++)
        if (v[0][i][x] == '1')
            v[0][i][x] = '0';
        else
            v[0][i][x] = '1';
}

int dfs(int ans, int k)
{
    if (k >= l)
    {
        for (int i = 0; i < n; i++)
            if (v[0][i] != v[1][i])
                return inf;
        return ans;
    }

    int kk;
    for (kk = k + 1; kk < l && visit[kk] == 0; kk++);
    for (int i = 0; i < n; i++)
    {
        for (int p = 0; p < k; p++)
            if (v[0][i][p] != v[1][i][p])
                return inf;
        if (v[0][i][k] != v[1][i][k])
        {
            fff(k);
            sort(v[0].begin(), v[0].end());
            int tmp = dfs(ans + 1, kk);
            fff(k);
            sort(v[0].begin(), v[0].end());
            return tmp;
        }
    }
    int tmp = dfs(ans, kk);
    fff(k);
    sort(v[0].begin(), v[0].end());
    tmp = min(tmp, dfs(ans + 1, kk));
    fff(k);
    sort(v[0].begin(), v[0].end());
    return tmp;
}

void solve()
{
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cnt[i][j] = 0;
            for (int k = 0; k < n; k++)
                if (v[i][k][j] == '1')
                    cnt[i][j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        if (cnt[0][i] == cnt[1][i])
        {
            if (cnt[0][i] == n - cnt[0][i])
                visit[i] = 1;
        }
        else if (cnt[0][i] == n - cnt[1][i])
            ans++, fff(i);
        else
        {
            puts("NOT POSSIBLE");
            return;
        }
    }
    sort(v[1].begin(), v[1].end());
    for (;;)
    {
        sort(v[0].begin(), v[0].end());
        int i;
        for (i = 0; i < n; i++)
            if (v[0][i] != v[1][i])
                break;
        if (i >= n)
            break;
        int k;
        for (k = 0; k < l && visit[k] == 0; k++)
            ;
        if (visit[k] == 0)
        {
            puts("NOT POSSIBLE");
            return;
        }
        ans = dfs(ans, k);
        if (ans >= inf)
        {
            puts("NOT POSSIBLE");
            return;
        }
        break;
    }
    printf("%d\n", ans);
}

int main(int argc, char *argv[])
{
    freopen("A-large.in", "r", stdin);
    freopen("answer.txt", "w", stdout);
    string tmp;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &n, &l);
        v[0].clear(), v[1].clear();
        for (int i = 0 ; i < 2; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> tmp;
                v[i].push_back(tmp);
            }
        printf("Case #%d: ", cas);
        solve();
    }

    return 0;
}
